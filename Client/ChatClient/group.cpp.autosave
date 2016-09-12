#include <QString>

#include "group.h"
#include "user.h"
#include "message.h"

Group::Group(quint32 id, QString name, QObject *parent) :
    QObject(parent), _id(id), _name(name)
{
    _members = new QList<User *>();
    _messages = nullptr;
}

Group::~Group()
{
   qDeleteAll(*_messages);

   delete _members;
   delete _messages;
}

bool Group::isNoMessages()
{
    return _messages == nullptr;
}

quint32 Group::getId() const
{
    return _id;
}

QString Group::getName() const
{
    return _name;
}

const QList<User *> *Group::getMembers() const
{
    return _members;
}

const QList<Message *> *Group::getMessages() const
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
    message->setGroup(this);
    _messages->append(message);

    emit messageAdded(message);
}
