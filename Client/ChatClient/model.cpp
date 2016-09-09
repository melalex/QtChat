#include "model.h"
#include "group.h"
#include "user.h"
#include "connectionmenager.h"

Model::Model(QObject *parent) : QObject(parent)
{

}

Model::~Model()
{
    qDeleteAll(*_chats);
    qDeleteAll(*_groupChats);

    delete _chats;
    delete _groupChats;
}

QList<User *> *Model::getUsersExceptMe(Group *chat)
{
    QList<User *> *result = new QList<User *>();

    for (User *user : *chat->getMembers())
    {
        if (user != _connectionMenager->currentUser())
        {
            result->append(user);
        }
    }

    return result;
}

QList<Group *> *Model::chats()
{
    return _chats;
}

QList<Group *> *Model::groupChats()
{
    return _groupChats;
}

void Model::setConnectionMenager(ConnectionMenager *connectionMenager)
{
   _connectionMenager = connectionMenager;

   _chats = _connectionMenager->getChats();
   _groupChats = _connectionMenager->getGroupChats();

   connect(_connectionMenager, SIGNAL(addChat(Group*)), this, SLOT(addChat(Group*)));
   connect(_connectionMenager, SIGNAL(addGroupChat(Group*)), this, SLOT(addGroupChat(Group*)));
   connect(_connectionMenager, SIGNAL(addMessageToGroup(Message*,quint32)), this, SLOT(addMessageToGroup(Message*,quint32)));
}

void Model::addChat(Group *chat)
{
    _chats->append(chat);

    chatAdded(chat);
}

void Model::addGroupChat(Group *chat)
{
    _groupChats->append(chat);

    groupChatAdded(chat);
}

void Model::removeChat(Group *chat)
{
    _chats->removeOne(chat);

    chatRemoved();

    delete chat;
}

void Model::removeGroupChat(Group *chat)
{
    _groupChats->removeOne(chat);

    groupChatRemoved();

    delete chat;
}

void Model::addMessageToGroup(Message *message, quint32 groupId)
{
    for (Group *group: *_chats)
    {
        if (group->getId() == groupId)
        {
            group->addMessage(message);
            return;
        }
    }

    for (Group *group: *_chats)
    {
        if (group->getId() == groupId)
        {
            group->addMessage(message);
            return;
        }
    }
}