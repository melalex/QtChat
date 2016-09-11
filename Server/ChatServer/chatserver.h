#ifndef CHATSERVER_H
#define CHATSERVER_H

#include <QTcpServer>
#include <QHash>

class Client;

class ChatServer : public QTcpServer
{
    Q_OBJECT

public:
    explicit ChatServer(QObject *parent = 0);

    void startServer(QHostAddress addr, qint16 port);

protected:
    void incomingConnection(int handle);

private slots:
    void signUp(Client *client, QString login, QString password);
    void signIn(Client *client, QString login, QString password);

    void getContacts(Client *client);
    void getGroups(Client *client);
    void getUser(Client *client, quint32 userId);
    void getMessages(Client *client, quint32 groupId);
    void getPossibleContacts(Client *client, QString loginPart);

    void sendMessage(quint32 senderId, quint32 groupId, QString text);

    void addContact(Client *client, quint32 interlocutorId);
    void createGroup(Client *client, QString name, const QList<quint32> &members);

    void liveGroup(quint32 clientId, quint32 groupId);

    void clientDisconected(quint32 id);

private:
    QHash<quint32, Client *> _clients;

};

#endif // CHATSERVER_H
