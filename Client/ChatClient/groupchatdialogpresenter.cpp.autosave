#include "groupchatdialogpresenter.h"
#include "groupchatdialog.h"
#include "group.h"
#include "user.h"
#include "message.h"
#include "connectionmenager.h"
#include "possiblecontactsmodel.h"

GroupChatDialogPresenter::GroupChatDialogPresenter(QObject *parent) : QObject(parent)
{
    _chat = new GroupChatDialog();

    PossibleContactsModel *tableModel = new PossibleContactsModel(this);

    connect(this, SIGNAL(setMembers(const QList<User*>*)), tableModel, SLOT(setPossibleContacts(const QList<User*>*)));

    _chat->setTableModel(tableModel);

    connect(_chat, SIGNAL(messageAdded(QString)), this, SLOT(messageAdded(QString)));
}

GroupChatDialogPresenter::~GroupChatDialogPresenter()
{
    delete _chat;
}

void GroupChatDialogPresenter::setGroup(Group *group)
{
    if (_group)
    {
        _chat->clearOutput();
        disconnect(_group, SIGNAL(messageAdded(Message*)), this, SLOT(messageAdded(Message*)));
    }

    _group = group;

    emit setMembers(_group->getMembers());

    connect(_group, SIGNAL(messageAdded(Message*)), this, SLOT(messageAdded(Message*)));

    _chat->setInterlocutor(_group->getName());

    if (!_group->isNoMessages())
    {
        for (Message *message : *_group->getMessages())
        {
            _chat->printMessage(message->toString());
        }
    }
}

Group *GroupChatDialogPresenter::group()
{
    return _group;
}

void GroupChatDialogPresenter::showWindow()
{
    _chat->show();
}

void GroupChatDialogPresenter::hideWindow()
{
    disconnect(_group, SIGNAL(messageAdded(Message*)), this, SLOT(messageAdded(Message*)));

    _group = nullptr;

    _chat->close();
}

void GroupChatDialogPresenter::messageAdded(Message *message)
{
    _chat->printMessage(message->toString());
}

void GroupChatDialogPresenter::messageAdded(QString message)
{
    _group->addMessage(new Message(QDateTime::currentDateTime(), message, ConnectionMenager::currentUser()));
}
