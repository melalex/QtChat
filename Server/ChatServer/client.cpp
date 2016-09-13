#include "client.h"
#include "C:\Chat\protocol.h"

#include <QDateTime>
#include <QDataStream>
#include <QDebug>
#include <QThreadPool>
#include <QRegExp>

Client::Client(qint32 descriptor, QObject *parent) :
    QObject(parent)
{
    _socket = new QTcpSocket(this);

    _socket->setSocketDescriptor(descriptor);

    connect(_socket, SIGNAL(connected()), this, SLOT(onConnect()));
    connect(_socket, SIGNAL(disconnected()), this, SLOT(onDisconnect()));
    connect(_socket, SIGNAL(readyRead()), this, SLOT(onReadyRead()));
    connect(_socket, SIGNAL(error(QAbstractSocket::SocketError)), this, SLOT(onError(QAbstractSocket::SocketError)));

    qDebug() << "["  << QDateTime::currentDateTime().toString("dd.MM.yyyy hh:mm") << "]"
             << "Client connected" << descriptor;

}

Client::~Client()
{

}

quint32 Client::id() const
{
    return _id;
}

void Client::onConnect()
{

}

void Client::onDisconnect()
{
    if (_isAutched)
    {
        qDebug() << "["  << QDateTime::currentDateTime().toString("dd.MM.yyyy hh:mm") << "]"
                 << "Client with id " << _id << " disconnected";
        emit clientDisconected(_id);
    }
    else
    {
        qDebug() << "["  << QDateTime::currentDateTime().toString("dd.MM.yyyy hh:mm") << "]"
                 << "Client disconnected";
    }

    deleteLater();
}

void Client::onReadyRead()
{
    QDataStream in(_socket);

    if (_blockSize == 0 && _socket->bytesAvailable() >= (int)sizeof(quint16))
    {
        in >> _blockSize;
    }

    if (_socket->bytesAvailable() >= _blockSize)
    {
        _blockSize = 0;

        quint8 command;

        in >> command;

        if (_isAutched)
        {
            switch(command)
            {
                case GET_USER:
                {
                   quint32 userId;

                   in >> userId;

                   emit getUser(this, userId);
                }
                break;

                case GET_MESSAGES:
                {
                   quint32 groupId;

                   in >> groupId;

                   emit getMessages(this, groupId);
                }
                break;

                case GET_POSSIBLE_CONTACTS:
                {
                    QString loginPart;

                    in >> loginPart;

                    emit getPossibleContacts(this, loginPart);
                }
                break;

                case SEND_MESSAGE:
                {
                    quint32 groupId;
                    QString text;

                    in >> groupId;
                    in >> text;

                    emit sendMessage(_id, groupId, text);
                }
                break;

                case ADD_CONTACT:
                {
                    quint32 userId;

                    in >> userId;

                    emit addContact(this, userId);
                }
                break;

                case CREATE_GROUP:
                {
                    quint32 count;
                    QString name;
                    QList<quint32> members;
                    quint32 userId;

                    in >> name;
                    in >> count;

                    members.append(_id);

                    for (quint32 i = 0; i < count; i++)
                    {
                        in >> userId;
                        members.append(userId);
                    }

                    emit createGroup(this, name, members);
                }
                break;

                case LIVE_GROUP:
                {
                    quint32 groupId;
                    in >> groupId;
                    emit liveGroup(_id, groupId);
                }
                break;
            }
        }
        else if (command == SIGN_UP || command == SIGN_IN)
        {
            QString login;
            QString password;

            in >> login;
            in >> password;

            if (command == SIGN_UP)
            {
                signUp(this, login, password);
            }
            else if (command == SIGN_IN)
            {
                signIn(this, login, password);
            }
        }
    }

    if (_socket->bytesAvailable() >= (int)sizeof(quint16))
    {
        onReadyRead();
    }
}

void Client::onError(QAbstractSocket::SocketError socketError) const
{
    switch (socketError)
    {
        case QAbstractSocket::RemoteHostClosedError:
            break;

        default:
            qDebug() << "["  << QDateTime::currentDateTime().toString("dd.MM.yyyy hh:mm") << "]"
                 << "The following error occurred: " << _socket->errorString();
            break;
    }
}

void Client::loged(quint32 userId)
{
    qDebug() << "["  << QDateTime::currentDateTime().toString("dd.MM.yyyy hh:mm") << "]"
             << "Client with id " << userId << " loged";

    _isAutched = true;
    _id = userId;

    QByteArray block;
    QDataStream out(&block, QIODevice::WriteOnly);
    out << (quint16)0;

    out << (quint8)LOGED;
    out << userId;

    out.device()->seek(0);

    out << (quint16)(block.size() - sizeof(quint16));

    _socket->write(block);
}

void Client::notLoged()
{
    qDebug() << "["  << QDateTime::currentDateTime().toString("dd.MM.yyyy hh:mm") << "]"
             << "Client not loged";

    QByteArray block;
    QDataStream out(&block, QIODevice::WriteOnly);
    out << (quint16)0;

    out << (quint8)NOT_LOGED;

    out.device()->seek(0);

    out << (quint16)(block.size() - sizeof(quint16));

    _socket->write(block);
}

void Client::registered()
{
    qDebug() << "["  << QDateTime::currentDateTime().toString("dd.MM.yyyy hh:mm") << "]"
             << "Client registered";

    QByteArray block;
    QDataStream out(&block, QIODevice::WriteOnly);
    out << (quint16)0;

    out << (quint8)REGISTERED;

    out.device()->seek(0);

    out << (quint16)(block.size() - sizeof(quint16));

    _socket->write(block);
}

void Client::notRegistered()
{
    qDebug() << "["  << QDateTime::currentDateTime().toString("dd.MM.yyyy hh:mm") << "]"
             << "Client not registered";

    QByteArray block;
    QDataStream out(&block, QIODevice::WriteOnly);
    out << (quint16)0;

    out << (quint8)NOT_REGISTERED;

    out.device()->seek(0);

    out << (quint16)(block.size() - sizeof(quint16));

    _socket->write(block);
}

void Client::newMessage(quint32 senderId, quint32 groupId, quint64 time, QString text)
{
    qDebug() << "["  << QDateTime::currentDateTime().toString("dd.MM.yyyy hh:mm") << "]"
             << "Client with id " << _id << " get message from user with id " << senderId
             << "to group with id " << groupId;

    QByteArray block;
    QDataStream out(&block, QIODevice::WriteOnly);
    out << (quint16)0;

    out << (quint8)NEW_MESSAGE;
    out << senderId;
    out << groupId;
    out << time;
    out << text;

    out.device()->seek(0);

    out << (quint16)(block.size() - sizeof(quint16));

    _socket->write(block);

}

void Client::newUser(quint32 userId, QString login)
{
    qDebug() << "["  << QDateTime::currentDateTime().toString("dd.MM.yyyy hh:mm") << "]"
             << "Client with id " << _id << " get user with id " << userId << " and login " << login;

    QByteArray block;
    QDataStream out(&block, QIODevice::WriteOnly);
    out << (quint16)0;

    out << (quint8)NEW_USER;
    out << userId;
    out << login;

    out.device()->seek(0);

    out << (quint16)(block.size() - sizeof(quint16));

    _socket->write(block);
}

void Client::newContact(quint32 groupId, quint32 interlocutorId, QString interlocutorName)
{
    qDebug() << "["  << QDateTime::currentDateTime().toString("dd.MM.yyyy hh:mm") << "]"
             << "Client with id " << _id << " get new conntact with user with id " << interlocutorId;

    QByteArray block;
    QDataStream out(&block, QIODevice::WriteOnly);
    out << (quint16)0;

    out << (quint8)NEW_CONTACT;
    out << groupId;
    out << interlocutorId;
    out << interlocutorName;

    out.device()->seek(0);

    out << (quint16)(block.size() - sizeof(quint16));

    _socket->write(block);
}

void Client::newGroup(quint32 groupId, QString name, const QList<quint32> &members)
{
    qDebug() << "["  << QDateTime::currentDateTime().toString("dd.MM.yyyy hh:mm") << "]"
             << "Client with id " << _id << " get new group with id " << groupId << " and name " << name;

    QByteArray block;
    QDataStream out(&block, QIODevice::WriteOnly);
    out << (quint16)0;

    out << (quint8)NEW_GROUP;
    out << groupId;
    out << name;
    out << members.count();

    for (quint32 id: members)
    {
        out << id;
    }

    out.device()->seek(0);

    out << (quint16)(block.size() - sizeof(quint16));

    _socket->write(block);
}

void Client::possibleContactList(QList<User *> *users)
{
    qDebug() << "["  << QDateTime::currentDateTime().toString("dd.MM.yyyy hh:mm") << "]"
             << "Client with id " << _id << " get possible contactslist";

    QByteArray block;
    QDataStream out(&block, QIODevice::WriteOnly);
    out << (quint16)0;

    out << (quint8)POSSIBLE_CONTACTS_LIST;
    out << users->count();

    for (User *user: *users)
    {
        out << user->id;
        out << user->login;
    }

    out.device()->seek(0);

    out << (quint16)(block.size() - sizeof(quint16));

    _socket->write(block);

}
