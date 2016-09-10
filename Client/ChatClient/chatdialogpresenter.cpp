#include "chatdialogpresenter.h"
#include "chatdialog.h"
#include "group.h"
#include "user.h"
#include "message.h"
#include "connectionmenager.h"

ChatDialogPresenter::ChatDialogPresenter(QObject *parent) :
    QObject(parent)
{
    _chat = new ChatDialog();

    connect(_chat, SIGNAL(messageAdded(QString)), this, SLOT(messageAdded(QString)));
}

ChatDialogPresenter::~ChatDialogPresenter()
{
    delete _chat;
}

void ChatDialogPresenter::setGroup(Group *group)
{
    if (_group)
    {
        _chat->clearOutput();
        disconnect(_group, SIGNAL(messageAdded(Message*)), this, SLOT(messageAdded(Message*)));
    }

    _group = group;

    connect(_group, SIGNAL(messageAdded(Message*)), this, SLOT(messageAdded(Message*)));

    _chat->setInterlocutor(_group->getName());

    for (Message *message : *_group->getMessages())
    {
        _chat->printMessage(message->toString());
    }
}

Group *ChatDialogPresenter::group()
{
    return _group;
}

void ChatDialogPresenter::showWindow()
{
    _chat->show();
}

void ChatDialogPresenter::hideWindow()
{
    disconnect(_group, SIGNAL(messageAdded(Message*)), this, SLOT(messageAdded(Message*)));

    _group = nullptr;

    _chat->close();
}

void ChatDialogPresenter::messageAdded(Message *message)
{
    _chat->printMessage(message->toString());
}

void ChatDialogPresenter::messageAdded(QString message)
{
    _group->addMessage(new Message(QDateTime::currentDateTime(), message, ConnectionMenager::currentUser(), _group));
}
