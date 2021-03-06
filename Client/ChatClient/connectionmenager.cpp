#include "connectionmenager.h"
#include "user.h"
#include "group.h"
#include "message.h"
#include "C:\Chat\protocol.h"

#include <QDateTime>
#include <QDataStream>

User *ConnectionMenager::_currentUser = nullptr;

QString lastUsedLogin;

ConnectionMenager::ConnectionMenager(QObject *parent) :
    QObject(parent)
{
    _socket = new QTcpSocket(this);

    connect(_socket, SIGNAL(readyRead()), this, SLOT(onSokReadyRead()));
    connect(_socket, SIGNAL(connected()), this, SLOT(onSokConnected()));
    connect(_socket, SIGNAL(disconnected()), this, SLOT(onSokDisconnected()));
    connect(_socket, SIGNAL(error(QAbstractSocket::SocketError)), this, SLOT(onSokDisplayError(QAbstractSocket::SocketError)));
}

ConnectionMenager::~ConnectionMenager()
{

}

void ConnectionMenager::onSokConnected()
{

}

void ConnectionMenager::onSokDisconnected()
{

}

void ConnectionMenager::onSokReadyRead()
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

        switch(command)
        {
            case REGISTERED:
            {
                emit registered();
            }
            break;

            case NOT_REGISTERED:
            {
                emit notRegistered();
            }
            break;

            case LOGED:
            {
                quint32 userId;

                in >> userId;

                _currentUser = UserCreator::getInstance().createUser(userId, lastUsedLogin);

                emit logged();
            }
            break;

            case NOT_LOGED:
            {
                notLogged();
            }
            break;

            case NEW_MESSAGE:
            {
                quint32 senderId;
                quint32 groupId;
                quint64 time;
                QString text;

                in >> senderId;
                in >> groupId;
                in >> time;
                in >> text;

                emit addMessageToGroup(senderId, groupId, time, text);
            }
            break;

            case NEW_USER:
            {
                quint32 userId;
                QString login;

                in >> userId;
                in >> login;

                emit addUser(userId, login);
            }
            break;

            case NEW_CONTACT:
            {
                quint32 groupId;
                quint32 interlocutorId;
                QString interlocutorName;

                in >> groupId;
                in >> interlocutorId;
                in >> interlocutorName;

                emit addChat(groupId, interlocutorId, interlocutorName);
            }
            break;

            case NEW_GROUP:
            {
                quint32 groupId;
                quint32 count;
                QString name;
                QList<quint32> members;

                in >> groupId;
                in >> name;
                in >> count;

                quint32 memberId;

                for (quint32 i = 0; i < count; i++)
                {
                    in >> memberId;
                    members.append(memberId);
                }

                emit addGroupChat(groupId, name, members);
            }
            break;

            case POSSIBLE_CONTACTS_LIST:
            {
                quint32 id;
                quint32 count;
                QString login;
                QList<User *> *possibleContactsList = new QList<User *>();

                in >> count;

                for (quint32 i = 0; i < count; i++)
                {
                    in >> id;
                    in >> login;

                    possibleContactsList->append(UserCreator::getInstance().createUser(id, login));
                }

                emit possibleContacts(possibleContactsList);
            }
            break;
        }
    }

    if (_socket->bytesAvailable() >= (int)sizeof(quint16))
    {
        onSokReadyRead();
    }
}

void ConnectionMenager::onSokDisplayError(QAbstractSocket::SocketError socketError)
{
    switch (socketError)
    {
        case QAbstractSocket::RemoteHostClosedError:
        case QAbstractSocket::HostNotFoundError:
        case QAbstractSocket::ConnectionRefusedError:
            connectionFail(_socket->errorString());
            break;

        default:
            qDebug() << "The following error occurred: " << _socket->errorString();
            break;
    }
}

void ConnectionMenager::connectToHost(QString hostName)
{
    _socket->connectToHost(hostName, 8000);
}

User *ConnectionMenager::currentUser()
{
    return _currentUser;
}

void ConnectionMenager::signUp(QString login, QString password)
{
    QByteArray block;
    QDataStream out(&block, QIODevice::WriteOnly);
    out << (quint16)0;

    out << (quint8)SIGN_UP;
    out << login;
    out << password;

    out.device()->seek(0);

    out << (quint16)(block.size() - sizeof(quint16));

    _socket->write(block);
}

void ConnectionMenager::signIn(QString login, QString password)
{
    lastUsedLogin = login;

    QByteArray block;
    QDataStream out(&block, QIODevice::WriteOnly);
    out << (quint16)0;

    out << (quint8)SIGN_IN;
    out << login;
    out << password;

    out.device()->seek(0);

    out << (quint16)(block.size() - sizeof(quint16));

    _socket->write(block);
}

void ConnectionMenager::addContact(User *user)
{
    QByteArray block;
    QDataStream out(&block, QIODevice::WriteOnly);
    out << (quint16)0;

    out << (quint8)ADD_CONTACT;
    out << user->getId();

    out.device()->seek(0);

    out << (quint16)(block.size() - sizeof(quint16));

    _socket->write(block);
}

void ConnectionMenager::createGroupChat(const QList<User *> &users, QString name)
{
    QByteArray block;
    QDataStream out(&block, QIODevice::WriteOnly);
    out << (quint16)0;

    out << (quint8)CREATE_GROUP;
    out << name;
    out << users.count();

    for (User *user: users)
    {
        out << user->getId();
    }

    out.device()->seek(0);

    out << (quint16)(block.size() - sizeof(quint16));

    _socket->write(block);
}

void ConnectionMenager::liveGroup(Group *chat)
{
    QByteArray block;
    QDataStream out(&block, QIODevice::WriteOnly);
    out << (quint16)0;

    out << (quint8)LIVE_GROUP;
    out << chat->getId();

    out.device()->seek(0);

    out << (quint16)(block.size() - sizeof(quint16));

    _socket->write(block);
}

void ConnectionMenager::sendMessage(Message *message)
{
    QByteArray block;
    QDataStream out(&block, QIODevice::WriteOnly);
    out << (quint16)0;

    out << (quint8)SEND_MESSAGE;
    out << message->getGroup()->getId();
    out << message->getText();

    out.device()->seek(0);

    out << (quint16)(block.size() - sizeof(quint16));

    _socket->write(block);
}

void ConnectionMenager::getUserById(quint32 id)
{
    QByteArray block;
    QDataStream out(&block, QIODevice::WriteOnly);
    out << (quint16)0;

    out << (quint8)GET_USER;
    out << id;

    out.device()->seek(0);

    out << (quint16)(block.size() - sizeof(quint16));

    _socket->write(block);
}

void ConnectionMenager::getMessages(quint32 groupId)
{
    QByteArray block;
    QDataStream out(&block, QIODevice::WriteOnly);
    out << (quint16)0;

    out << (quint8)GET_MESSAGES;
    out << groupId;

    out.device()->seek(0);

    out << (quint16)(block.size() - sizeof(quint16));

    _socket->write(block);

}

void ConnectionMenager::getPossibleContacts(QString loginPart)
{
    QByteArray block;
    QDataStream out(&block, QIODevice::WriteOnly);
    out << (quint16)0;

    out << (quint8)GET_POSSIBLE_CONTACTS;
    out << loginPart;

    out.device()->seek(0);

    out << (quint16)(block.size() - sizeof(quint16));

    _socket->write(block);
}
