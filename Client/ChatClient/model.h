#ifndef MODEL_H
#define MODEL_H

#include <QObject>
#include <QList>
#include <QMultiHash>

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

    bool isContact(User *user);

    const QList<Group *> *chats() const;
    const QList<Group *> *groupChats() const;

    void setConnectionMenager(ConnectionMenager *connectionMenager);

    void createChat(User *user);
    void createGroupChat(QString name, const QList<User *> &members);

    void removeChat(quint16 index);
    void removeGroupChat(quint16 index);

signals:
    void chatAdded(Group *chat);
    void groupChatAdded(Group *chat);

    void chatRemoved(quint16 index);
    void groupChatRemoved(quint16 index);

public slots:
    void addUser(quint32 id, QString login);
    void addChat(quint32 groupId, quint32 interlocutorId, QString interlocutorName);
    void addGroupChat(quint32 groupId, QString name, const QList<quint32> &members);

    void addMessageToGroup(quint32 senderId, quint32 groupId, quint64 time, QString text);

private:
    QList<Group *> *_chats = nullptr;
    QList<Group *> *_groupChats = nullptr;

    QMultiHash<quint32, Group *> _mapUsersToGroups;

    ConnectionMenager *_connectionMenager;
};

#endif // MODEL_H
