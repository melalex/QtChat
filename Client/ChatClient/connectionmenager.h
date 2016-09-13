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

    void liveGroup(Group *chat);

    void getUserById(quint32 id);
    void getMessages(quint32 groupId);
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

    void addUser(quint32 id, QString login);
    void addChat(quint32 groupId, quint32 interlocutorId, QString interlocutorName);
    void addGroupChat(quint32 groupId, QString name, const QList<quint32> &members);

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
