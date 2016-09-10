#ifndef CONNECTIONMENAGER_H
#define CONNECTIONMENAGER_H

#include <QObject>
#include <QList>

class Group;
class User;
class Message;

class ConnectionMenager : public QObject
{
    Q_OBJECT

public:
    explicit ConnectionMenager(QObject *parent = 0);
    ~ConnectionMenager();

    User *currentUser();

    void signUp(QString login, QString password);
    void signIn(QString login, QString password);

    void addContact(User *user);
    void createGroupChat(QList<User *> users, QString name);

    void sendMessage(Message *message);

    QList<Group *> *getChats();
    QList<Group *> *getGroupChats();

    void getPossibleContacts(QString loginPart);

signals:
    void logged();
    void notLogged();

    void registered();
    void notRegistered();

    void possibleContacts(QList<User *> *users);

    void addChat(Group *chat);
    void addGroupChat(Group *chat);

    void addMessageToGroup(Message *message, quint32 groupId);

private:
    User *_currentUser;
};

#endif // CONNECTIONMENAGER_H
