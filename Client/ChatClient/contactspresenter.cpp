#include "contactspresenter.h"
#include "addcontactdialogpresenter.h"
#include "contacts.h"
#include "model.h"
#include "chatsmodel.h"
#include "connectionmenager.h"
#include "user.h"
#include "groupchatsmodel.h"
#include "group.h"
#include "chatdialogpresenter.h"
#include "groupchatdialogpresenter.h"

#include <QHeaderView>
#include <QInputDialog>
#include <QString>
#include <QMessageBox>
#include <QApplication>

ContactsPresenter::ContactsPresenter(QObject *parent) : QObject(parent)
{
    _contacts = new Contacts();
    _model = new Model();

    connect(_contacts, SIGNAL(addContact()), this, SLOT(addContact()));
    connect(_contacts, SIGNAL(removeContact(quint16)), this, SLOT(removeContact(quint16)));

    connect(_contacts, SIGNAL(createGroup(QList<quint16>*)), this, SLOT(createGroup(QList<quint16>*)));
    connect(_contacts, SIGNAL(leaveGroup(quint16)), this, SLOT(leaveGroup(quint16)));

    connect(_contacts, SIGNAL(openChat(quint16)), this, SLOT(openChat(quint16)));
    connect(_contacts, SIGNAL(openGroupChat(quint16)), this, SLOT(openGroupChat(quint16)));
}

ContactsPresenter::~ContactsPresenter()
{
    delete _contacts;
    delete _model;
}

void ContactsPresenter::showWindow()
{
    _contacts->show();

    _contacts->setTableModel(new ChatsModel(_model, this),  new GroupChatsModel(_model, this));
    _contacts->setMyLogin(_connectionMenager->currentUser()->getLogin());
}

void ContactsPresenter::setConnectionMenager(ConnectionMenager *connectionMenager)
{
    _connectionMenager = connectionMenager;

    _model->setConnectionMenager(_connectionMenager);

    connect(_connectionMenager, SIGNAL(connectionFail(QString)), this, SLOT(connectionFail(QString)));
}

AddContactDialogPresenter *ContactsPresenter::getAddContactDialog()
{
    if (!_addContactDialog)
    {
        _addContactDialog = new AddContactDialogPresenter(_model, _connectionMenager, this);
    }
    return _addContactDialog;
}

GroupChatDialogPresenter *ContactsPresenter::getGroupChatDialogPresenter()
{
    if (!_groupChatDialogPresenter)
    {
        _groupChatDialogPresenter = new GroupChatDialogPresenter(this);
    }
    return _groupChatDialogPresenter;
}

ChatDialogPresenter *ContactsPresenter::getChatDialogPresenter()
{
    if (!_chatDialogPresenter)
    {
        _chatDialogPresenter = new ChatDialogPresenter(this);
    }
    return _chatDialogPresenter;
}

void ContactsPresenter::connectionFail(QString socketError)
{
    QMessageBox msgBox;
    msgBox.setText(socketError);
    msgBox.setIcon(QMessageBox::Critical);
    msgBox.exec();

    _contacts->close();
    qApp->quit();
    qApp->exit();
}

void ContactsPresenter::addContact()
{
    getAddContactDialog()->showWindow();
}

void ContactsPresenter::removeContact(quint16 index)
{
    if (getChatDialogPresenter()->group() == _model->chats()->at(index))
    {
        getChatDialogPresenter()->hideWindow();
    }

    _model->removeChat(index);
}

void ContactsPresenter::createGroup(QList<quint16> *indexes)
{
    User *user = nullptr;
    QList<User *> users;

    for (quint16 index : *indexes)
    {
        user = _model->chats()->at(index)->getMembers()->at(0);
        users.append(user);
    }

    bool ok;
    QString name = QInputDialog::getText(_contacts, QString("Set group name"),
                                                    QString("Group name:"),
                                                    QLineEdit::Normal,
                                                    QString("New group"),
                                                    &ok);
    if (ok && !name.isEmpty())
    {
        _model->createGroupChat(name, users);
    }
}

void ContactsPresenter::leaveGroup(quint16 index)
{
    if (getGroupChatDialogPresenter()->group() == _model->groupChats()->at(index))
    {
        getGroupChatDialogPresenter()->hideWindow();
    }

    _model->removeGroupChat(index);
}

void ContactsPresenter::openChat(quint16 index)
{
    Group *group = _model->chats()->at(index);

    if (group->isNoMessages())
    {
        _connectionMenager->getMessages(group->getId());
    }

    getChatDialogPresenter()->setGroup(group);
    getChatDialogPresenter()->showWindow();
}

void ContactsPresenter::openGroupChat(quint16 index)
{
    Group *group = _model->groupChats()->at(index);

    if (group->isNoMessages())
    {
        _connectionMenager->getMessages(group->getId());
    }

    getGroupChatDialogPresenter()->setGroup(group);
    getGroupChatDialogPresenter()->showWindow();
}
