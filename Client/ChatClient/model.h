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

    const QList<Group *> *chats() const;
    const QList<Group *> *groupChats() const;

    void setConnectionMenager(ConnectionMenager *connectionMenager);

    void createChat(User *user);
    void createGroupChat(QString name, QList<User *> *members);

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

    void addMessageToGroup(quint32 senderId, quint32 groupId, quint64 time, QString text);

private:
    QList<Group *> *_chats = nullptr;
    QList<Group *> *_groupChats = nullptr;

    ConnectionMenager *_connectionMenager;
};

#endif // MODEL_H
