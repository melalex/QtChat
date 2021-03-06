#ifndef CLIENT_H
#define CLIENT_H

#include <QObject>
#include <QTcpSocket>

#include "models.h"

class Client : public QObject
{
    Q_OBJECT
public:
    explicit Client(qint32 descriptor, QObject *parent = 0);
    ~Client();

    quint32 id() const;

    void loged(quint32 userId);
    void notLoged();

    void registered();
    void notRegistered();

    void newMessage(quint32 senderId, quint32 groupId, quint64 time, QString text);
    void newUser(quint32 userId, QString login);
    void newContact(quint32 groupId, quint32 interlocutorId, QString interlocutorName);
    void newGroup(quint32 groupId, QString name, const QList<quint32> &members);

    void possibleContactList(QList<User *> *users);

signals:
    void signUp(Client *client, QString login, QString password);
    void signIn(Client *client, QString login, QString password);

    void getUser(Client *client, quint32 userId);
    void getMessages(Client *client, quint32 groupId);
    void getPossibleContacts(Client *client, QString loginPart);

    void sendMessage(quint32 senderId, quint32 groupId, QString text);

    void addContact(Client *client, quint32 interlocutorId);
    void createGroup(Client *client, QString name, const QList<quint32> &members);

    void liveGroup(quint32 clientId, quint32 groupId);

    void clientDisconected(quint32 id);

public slots:
    void onConnect();
    void onDisconnect();
    void onReadyRead();
    void onError(QAbstractSocket::SocketError socketError) const;

private:
    QTcpSocket *_socket;
    quint16 _blockSize = 0;
    quint32 _id;
    bool _isAutched = false;
};

#endif // CLIENT_H
