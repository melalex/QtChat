#ifndef GROUP_H
#define GROUP_H

#include <QObject>
#include <QtGlobal>
#include <QList>

class User;
class Message;

class Group : public QObject
{
    Q_OBJECT

public:
    explicit Group(quint32 id, QList<User *> *members, QObject *parent = 0, QList<Message *> *messages = new QList<Message *>());
    ~Group();

    quint32 getId();
    QList<User *> *getMembers();
    QList<Message *> *getMessages();

    void addMember(User *user);
    void removeMember(User *user);

    void addMessage(Message *message);

signals:
    void messageAdded(Message *message);
    void memberRemoved();

private:
    quint32 _id;
    QList<User *> *_members;
    QList<Message *> *_messages;
};

#endif // GROUP_H
