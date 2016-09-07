#include "model.h"
#include "group.h"
#include "user.h"

Model::Model(QObject *parent) : QObject(parent)
{

}

Model::~Model()
{
    qDeleteAll(_chats);
    qDeleteAll(_groupChats);
}

void Model::addChat(Group *chat)
{
    _chats.append(chat);

    chatAdded(chat);
}

void Model::addGroupChat(Group *chat)
{
    _groupChats.append(chat);

    groupChatAdded(chat);
}

void Model::removeChat(Group *chat)
{
    _chats.removeOne(chat);

    chatRemoved();

    delete chat;
}

void Model::removeGroupChat(Group *chat)
{
    _groupChats.removeOne(chat);

    groupChatRemoved();

    delete chat;
}

User *Model::currentUser()
{
    return _currentUser;
}

void Model::setCurrentUser(User *user)
{
    _currentUser = user;
}
