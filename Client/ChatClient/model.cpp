#include "model.h"
#include "group.h"
#include "user.h"
#include "connectionmenager.h"
#include "message.h"

Model::Model(QObject *parent) : QObject(parent)
{
    _chats = new QList<Group *>();
    _groupChats = new QList<Group *>();
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

bool Model::isContact(User *user)
{
    for (Group *contact: *_chats)
    {
        if (user == contact->getMembers()->at(0))
        {
            return true;
        }
    }
    return false;
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

   connect(_connectionMenager,
           SIGNAL(addUser(quint32,QString)),
           this,
           SLOT(addUser(quint32,QString)));

   connect(_connectionMenager,
           SIGNAL(addChat(quint32,quint32,QString)),
           this,
           SLOT(addChat(quint32,quint32,QString)));

   connect(_connectionMenager,
           SIGNAL(addGroupChat(quint32,QString,QList<quint32>)),
           this,
           SLOT(addGroupChat(quint32,QString,QList<quint32>)));

   connect(_connectionMenager,
           SIGNAL(addMessageToGroup(quint32,quint32,quint64,QString)),
           this,
           SLOT(addMessageToGroup(quint32,quint32,quint64,QString)));
}

void Model::createChat(User *user)
{
    _connectionMenager->addContact(user);
}

void Model::createGroupChat(QString name, const QList<User *> &members)
{
    _connectionMenager->createGroupChat(members, name);
}

void Model::addUser(quint32 id, QString login)
{
    User *user = UserCreator::getInstance().createUser(id, login);

    for (Group *group: _mapUsersToGroups.values(id))
    {
        group->addMember(user);
    }
}

void Model::addChat(quint32 groupId, quint32 interlocutorId, QString interlocutorName)
{
    Group *group = new Group(groupId, interlocutorName);
    User *interlocutor = UserCreator::getInstance().createUser(interlocutorId, interlocutorName);

    group->addMember(interlocutor);

    _chats->append(group);

    connect(group, SIGNAL(messageAdded(Message*)), _connectionMenager, SLOT(sendMessage(Message*)));

    emit chatAdded(group);
}

void Model::addGroupChat(quint32 groupId, QString name, const QList<quint32> &members)
{
    Group *group = new Group(groupId, name);
    UserCreator &userCreator = UserCreator::getInstance();

    for (quint32 id: members)
    {
        if (userCreator.isContains(id))
        {
            group->addMember(userCreator.userById(id));
        }
        else
        {
            _connectionMenager->getUserById(id);
            _mapUsersToGroups.insert(id, group);
        }
    }

    _groupChats->append(group);

    connect(group, SIGNAL(messageAdded(Message*)), _connectionMenager, SLOT(sendMessage(Message*)));

    emit groupChatAdded(group);
}

void Model::removeChat(quint16 index)
{
    Group *chat = _chats->at(index);

    _chats->removeAt(index);

    emit chatRemoved(index);

    _connectionMenager->liveGroup(chat);

    delete chat;
}

void Model::removeGroupChat(quint16 index)
{    
    Group *chat = _groupChats->at(index);

    _groupChats->removeAt(index);

    emit groupChatRemoved(index);

    _connectionMenager->liveGroup(chat);

    delete chat;
}

void Model::addMessageToGroup(quint32 senderId, quint32 groupId, quint64 time, QString text)
{
    User *user = UserCreator::getInstance().userById(senderId);
    Message *message = new Message(QDateTime::fromMSecsSinceEpoch(time), text, user);

    for (Group *group: *_chats)
    {
        if (group->getId() == groupId)
        {
            group->addMessage(message);
            return;
        }
    }

    for (Group *group: *_groupChats)
    {
        if (group->getId() == groupId)
        {
            group->addMessage(message);
            return;
        }
    }
}
