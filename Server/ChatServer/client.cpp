#include "client.h"

Client::Client(qint32 descriptor, QObject *parent) :
    QObject(parent)
{
    _socket = new QTcpSocket(this);

    _socket->setSocketDescriptor(descriptor);

    connect(_socket, SIGNAL(connected()), this, SLOT(onConnect()));
    connect(_socket, SIGNAL(disconnected()), this, SLOT(onDisconnect()));
    connect(_socket, SIGNAL(readyRead()), this, SLOT(onReadyRead()));
    connect(_socket, SIGNAL(error(QAbstractSocket::SocketError)), this, SLOT(onError(QAbstractSocket::SocketError)));

    qDebug() << "Client connected" << descriptor;

}

Client::~Client()
{

}

void Client::onConnect()
{

}

void Client::onDisconnect()
{

}

void Client::onReadyRead()
{

}

void Client::onError(QAbstractSocket::SocketError socketError) const
{

}

void Client::loged(quint32 userId)
{

}

void Client::notLoged()
{

}

void Client::registered()
{

}

void Client::notRegistered()
{

}

void Client::newMessage(quint32 senderId, quint64 time, QString text)
{

}

void Client::newUser(quint32 userId, QString login)
{

}

void Client::newContact(quint32 groupId, quint32 interlocutorId)
{

}

void Client::newGroup(quint32 groupId, QString name, const QList<quint32> &members)
{

}

void Client::possibleContactList()
{

}
