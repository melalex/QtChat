#include "contactspresenter.h"
#include "addcontactdialogpresenter.h"
#include "contacts.h"
#include "model.h"
#include "chatsmodel.h"
#include "connectionmenager.h"
#include "user.h"
#include "groupchatsmodel.h"
#include "group.h"

#include <QHeaderView>
#include <QInputDialog>
#include <QString>

ContactsPresenter::ContactsPresenter(QObject *parent) : QObject(parent)
{
    _contacts = new Contacts();
    _model = new Model();

    connect(_contacts, SIGNAL(addContact()), this, SLOT(addContact()));
    connect(_contacts, SIGNAL(removeContact(quint16)), this, SLOT(removeContact(quint16)));

    connect(_contacts, SIGNAL(createGroup(QList<quint16>*)), this, SLOT(createGroup(QList<quint16>*)));
    connect(_contacts, SIGNAL(leaveGroup(quint16)), this, SLOT(leaveGroup(quint16)));
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
}

AddContactDialogPresenter *ContactsPresenter::getAddContactDialog()
{
    if (!_addContactDialog)
    {
        _addContactDialog = new AddContactDialogPresenter(_model, _connectionMenager, this);
    }
    return _addContactDialog;
}

void ContactsPresenter::addContact()
{
    getAddContactDialog()->showWindow();
}

void ContactsPresenter::removeContact(quint16 index)
{
    _model->removeChat(index);
}

void ContactsPresenter::createGroup(QList<quint16> *indexes)
{
    User *user = nullptr;
    QList<User *> *users = new QList<User *>();

    for (quint16 index : *indexes)
    {
        user = _model->chats()->at(index)->getMembers()->at(0);
        users->append(user);
    }

    bool ok;
    QString name = QInputDialog::getText(_contacts, QString("Set group name"),
                                                    QString("Group name:"),
                                                    QLineEdit::Normal,
                                                    QString("New group"),
                                                    &ok);
    if (ok && !name.isEmpty())
    {
        _model->addGroupChat(new Group(0, name, users));
    }
}

void ContactsPresenter::leaveGroup(quint16 index)
{
    _model->removeGroupChat(index);
}
