#ifndef MODEL_H
#define MODEL_H

#include <QObject>
#include <QList>

class Group;
class User;
class Message;
class ConnectionMenager;

class Model : public QObject
{
    Q_OBJECT
public:
    explicit Model(QObject *parent = 0);
    ~Model();

    QList<User *> *getUsersExceptMe(Group *chat);

    QList<Group *> *chats();
    QList<Group *> *groupChats();

    void setConnectionMenager(ConnectionMenager *connectionMenager);

    void removeChat(Group *chat);
    void removeGroupChat(Group *chat);

signals:
    void chatAdded(Group *chat);
    void groupChatAdded(Group *chat);

    void chatRemoved();
    void groupChatRemoved();

public slots:
    void addChat(Group *chat);
    void addGroupChat(Group *chat);

    void addMessageToGroup(Message *message, quint32 groupId);

private:
    QList<Group *> *_chats;
    QList<Group *> *_groupChats;

    ConnectionMenager *_connectionMenager;
};

#endif // MODEL_H