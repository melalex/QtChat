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

    QList<Group *> *chats();
    QList<Group *> *groupChats();

    void setConnectionMenager(ConnectionMenager *connectionMenager);

    void removeChat(quint16 index);
    void removeGroupChat(quint16 index);

signals:
    void chatAdded(Group *chat);
    void groupChatAdded(Group *chat);

    void chatRemoved(quint16 index);
    void groupChatRemoved(quint16 index);

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
