#include <QString>

#include "group.h"
#include "user.h"
#include "message.h"

Group::Group(quint32 id, QString name, QList<User *> *members, QObject *parent,  QList<Message *> *messages) :
    QObject(parent), _id(id), _name(name), _members(members), _messages(messages)
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

QString Group::getName()
{
    return _name;
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

    emit memberRemoved();

    delete user;
}

void Group::addMessage(Message *message)
{
    _messages->append(message);

    emit messageAdded(message);
}
