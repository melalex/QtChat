#ifndef CONNECTIONMENAGER_H
#define CONNECTIONMENAGER_H

#include <QObject>
#include <QList>
#include <QTcpSocket>

class Group;
class User;
class Message;

class ConnectionMenager : public QObject
{
    Q_OBJECT

public:
    explicit ConnectionMenager(QObject *parent = 0);
    ~ConnectionMenager();

    void connectToHost(QString hostName);

    static User *currentUser();

    void signUp(QString login, QString password);
    void signIn(QString login, QString password);

    void addContact(User *user);
    void createGroupChat(QList<User *> users, QString name);

    void removeContact(Group *chat);
    void removeGroupChat(Group *chat);

    QList<Group *> *getChats();
    QList<Group *> *getGroupChats();

    void getPossibleContacts(QString loginPart);

public slots:
    void sendMessage(Message *message);

signals:
    void connectionFail(QString socketError);

    void logged();
    void notLogged();

    void registered();
    void notRegistered();

    void possibleContacts(QList<User *> *users);

    void addChat(Group *chat);
    void addGroupChat(Group *chat);

    void addMessageToGroup(quint32 senderId, quint32 groupId, quint64 time, QString text);

private slots:
    void onSokConnected();
    void onSokDisconnected();
    void onSokReadyRead();
    void onSokDisplayError(QAbstractSocket::SocketError socketError);

private:
    static User *_currentUser;

    QTcpSocket *_socket;
    quint16 _blockSize = 0;
};

#endif // CONNECTIONMENAGER_H
