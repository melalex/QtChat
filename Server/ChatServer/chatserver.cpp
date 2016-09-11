#include "chatserver.h"
#include "client.h"

#include <QDebug>
#include <QDateTime>

ChatServer::ChatServer(QObject *parent) :
    QTcpServer(parent)
{

}

void ChatServer::startServer(QHostAddress addr, qint16 port)
{
    if (listen(addr, port))
    {
        qDebug() << "Server started at" << QDateTime::currentDateTime().toString("dd.MM.yyyy hh:mm");
        qDebug() << "Listening on" << addr << ": " << port;
        qDebug() << "Press Ctrl-C to quit.";
    }
    else
    {
        qDebug() << "Server not started at" << addr << ":" << port;
    }
}

void ChatServer::incomingConnection(int handle)
{
    Client *client = new Client(handle, this);

    connect(client, SIGNAL(signUp(QString,QString)), this, SLOT(signUp(QString,QString)));
    connect(client, SIGNAL(signIn(QString,QString)), this, SLOT(signIn(QString,QString)));
    connect(client, SIGNAL(getContacts(Client*)), this, SLOT(getContacts(Client*)));
    connect(client, SIGNAL(getGroups(Client*)), this, SLOT(getGroups(Client*)));
    connect(client, SIGNAL(getUser(Client*,quint32)), this, SLOT(getUser(Client*,quint32)));
    connect(client, SIGNAL(getMessages(Client*,quint32)), this, SLOT(getMessages(Client*,quint32)));
    connect(client, SIGNAL(getPossibleContacts(Client*,QString)), this, SLOT(getPossibleContacts(Client*,QString)));
    connect(client, SIGNAL(sendMessage(quint32,quint32,QString)), this, SLOT(sendMessage(quint32,quint32,QString)));
    connect(client, SIGNAL(addContact(Client*,quint32)), this, SLOT(addContact(Client*,quint32)));
    connect(client, SIGNAL(createGroup(Client*,QString,QList<quint32>)), this, SLOT(createGroup(Client*,QString,QList<quint32>)));
    connect(client, SIGNAL(liveGroup(quint32,quint32)), this, SLOT(liveGroup(quint32,quint32)));
    connect(client, SIGNAL(clientDisconected(quint32)), this, SLOT(clientDisconected(quint32)));
}

void ChatServer::signUp(QString login, QString password)
{

}

void ChatServer::signIn(QString login, QString password)
{

}

void ChatServer::getContacts(Client *client)
{

}

void ChatServer::getGroups(Client *client)
{

}

void ChatServer::getUser(Client *client, quint32 userId)
{

}

void ChatServer::getMessages(Client *client, quint32 groupId)
{

}

void ChatServer::getPossibleContacts(Client *client, QString loginPart)
{

}

void ChatServer::sendMessage(quint32 senderId, quint32 groupId, QString text)
{

}

void ChatServer::addContact(Client *client, quint32 interlocutorId)
{

}

void ChatServer::createGroup(Client *client, QString name, const QList<quint32> &members)
{

}

void ChatServer::liveGroup(quint32 clientId, quint32 groupId)
{

}

void ChatServer::clientDisconected(quint32 id)
{
    Client *client = _clients.take(id);

    _clients.remove(id);

    delete client;
}
