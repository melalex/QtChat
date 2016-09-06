#include <QString>

#include "group.h"
#include "user.h"
#include "message.h"

Group::Group(quint32 id, QList<User *> *members, QList<Message *> *messages) :
    _id(id), _members(members), _messages(messages)
{

}

Group::~Group()
{
   qDeleteAll(*_members);
   qDeleteAll(*_messages);

   delete _members;
   delete _messages;
}

quint32 Group::getId()
{
    return _id;
}

QList<User *> *Group::getMembers()
{
    return _members;
}

QList<Message *> *Group::getMessages()
{
    return _messages;
}

void Group::addMember(User *user)
{
    _members->append(user);
}

void Group::removeMember(User *user)
{
    _members->removeOne(user);

    delete user;
}
