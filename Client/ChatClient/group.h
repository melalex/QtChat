#ifndef GROUP_H
#define GROUP_H

#include <QtGlobal>
#include <QList>

class User;
class Message;

class Group
{
public:
    Group(quint32 id, QList<User *> *members, QList<Message *> *messages = new QList<Message *>());
    ~Group();

    quint32 getId();
    QList<User *> *getMembers();
    QList<Message *> *getMessages();

    void addMember(User *user);
    void removeMember(User *user);

private:
    quint32 _id;
    QList<User *> *_members;
    QList<Message *> *_messages;
};

#endif // GROUP_H
