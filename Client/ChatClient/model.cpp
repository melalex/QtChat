#include "model.h"
#include "group.h"
#include "user.h"
#include "connectionmenager.h"

Model::Model(QObject *parent) : QObject(parent)
{

}

Model::~Model()
{
    if (_chats != nullptr)
    {
        qDeleteAll(*_chats);

        delete _chats;
    }

    if (_groupChats != nullptr)
    {
        qDeleteAll(*_groupChats);

        delete _groupChats;
    }
}

const QList<Group *> *Model::chats() const
{
    return _chats;
}

const QList<Group *> *Model::groupChats() const
{
    return _groupChats;
}

void Model::setConnectionMenager(ConnectionMenager *connectionMenager)
{
   _connectionMenager = connectionMenager;

   _chats = _connectionMenager->getChats();
   _groupChats = _connectionMenager->getGroupChats();

   for (Group *group : *_chats)
   {
        connect(group, SIGNAL(messageAdded(Message*)), _connectionMenager, SLOT(sendMessage(Message*)));
   }

   for (Group *group : *_groupChats)
   {
        connect(group, SIGNAL(messageAdded(Message*)), _connectionMenager, SLOT(sendMessage(Message*)));
   }

   connect(_connectionMenager,
           SIGNAL(addChat(Group*)),
           this,
           SLOT(addChat(Group*)));

   connect(_connectionMenager,
           SIGNAL(addGroupChat(Group*)),
           this,
           SLOT(addGroupChat(Group*)));

   connect(_connectionMenager,
           SIGNAL(addMessageToGroup(Message*,quint32)),
           this,
           SLOT(addMessageToGroup(Message*,quint32)));
}

void Model::createChat(User *user)
{
    QList<User *> *list = new QList<User *>();

    list->append(user);

    Group *group = new Group(0, user->getLogin(), list);

    addChat(group);
}

void Model::createGroupChat(QString name, QList<User *> *members)
{
    addGroupChat(new Group(0, name, members));
}

void Model::addChat(Group *chat)
{
    _chats->append(chat);

    connect(chat, SIGNAL(messageAdded(Message*)), _connectionMenager, SLOT(sendMessage(Message*)));

    emit chatAdded(chat);
}

void Model::addGroupChat(Group *chat)
{
    _groupChats->append(chat);

    connect(chat, SIGNAL(messageAdded(Message*)), _connectionMenager, SLOT(sendMessage(Message*)));

    emit groupChatAdded(chat);
}

void Model::removeChat(quint16 index)
{
    Group *chat = _chats->at(index);

    _chats->removeAt(index);

    emit chatRemoved(index);

    _connectionMenager->removeContact(chat);

    delete chat;
}

void Model::removeGroupChat(quint16 index)
{    
    Group *chat = _groupChats->at(index);

    _groupChats->removeAt(index);

    emit groupChatRemoved(index);

    _connectionMenager->removeGroupChat(chat);

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
