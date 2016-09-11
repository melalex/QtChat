#include "connectionmenager.h"
#include "user.h"
#include "group.h"
#include "message.h"
#include "C:\Chat\protocol.h"

#include <QDateTime>
#include <QDataStream>

User *ConnectionMenager::_currentUser = nullptr;

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
    _socket->disconnectFromHost();
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

                UserCreator::getInstance().createUser(userId, login);
            }
            break;

            case NEW_CONTACT:
            {
                quint32 userId;
                quint32 interlocutorId;

                in >> userId;
                in >> interlocutorId;
            }
            break;

            case NEW_GROUP:
            {

            }
            break;

            case POSSIBLE_CONTACTS_LIST:
            {

            }
            break;
        }
    }
}

void ConnectionMenager::onSokDisplayError(QAbstractSocket::SocketError socketError)
{
    switch (socketError)
    {
        case QAbstractSocket::HostNotFoundError:
            connectionFail();
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
    _currentUser = UserCreator::getInstance().createUser(0, "Me");

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

void ConnectionMenager::createGroupChat(QList<User *> users, QString name)
{
    QByteArray block;
    QDataStream out(&block, QIODevice::WriteOnly);
    out << (quint16)0;


    out.device()->seek(0);

    out << (quint16)(block.size() - sizeof(quint16));

    _socket->write(block);
}

void ConnectionMenager::removeContact(Group *chat)
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

void ConnectionMenager::removeGroupChat(Group *chat)
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

QList<Group *> *ConnectionMenager::getChats()
{
    QByteArray block;
    QDataStream out(&block, QIODevice::WriteOnly);
    out << (quint16)0;

    out << (quint8)GET_CONTACTS;

    out.device()->seek(0);

    out << (quint16)(block.size() - sizeof(quint16));

    _socket->write(block);

    QList<Group *> *result = new QList<Group *>();

    User *user1 = UserCreator::getInstance().createUser(1, "User1");
    User *user2 = UserCreator::getInstance().createUser(2, "User2");
    User *user3 = UserCreator::getInstance().createUser(3, "User3");
    User *user4 = UserCreator::getInstance().createUser(4, "User4");

    QList<User *> *list1 = new QList<User *>();
    list1->append(user1);

    QList<User *> *list2 = new QList<User *>();
    list2->append(user2);

    QList<User *> *list3 = new QList<User *>();
    list3->append(user3);

    QList<User *> *list4 = new QList<User *>();
    list4->append(user4);

    Group *group1 = new Group(0, user1->getLogin(), list1);
    Group *group2 = new Group(1, user2->getLogin(), list2);
    Group *group3 = new Group(2, user3->getLogin(), list3);
    Group *group4 = new Group(3, user4->getLogin(), list4);

    result->append(group1);
    result->append(group2);
    result->append(group3);
    result->append(group4);

    return result;
}

QList<Group *> *ConnectionMenager::getGroupChats()
{
    QByteArray block;
    QDataStream out(&block, QIODevice::WriteOnly);
    out << (quint16)0;

    out << (quint8)GET_GROUPS;

    out.device()->seek(0);

    out << (quint16)(block.size() - sizeof(quint16));

    _socket->write(block);

    QList<Group *> *result = new QList<Group *>();

    User *user5 = UserCreator::getInstance().createUser(5, "User5");
    User *user6 = UserCreator::getInstance().createUser(6, "User6");
    User *user7 = UserCreator::getInstance().createUser(7, "User7");

    QList<User *> *list5 = new QList<User *>();
    list5->append(user5);
    list5->append(user6);
    list5->append(user7);

    Group *group5 = new Group(4, "Group 5", list5);

    result->append(group5);

    return result;
}

void ConnectionMenager::getPossibleContacts(QString loginPart)
{
    QByteArray block;
    QDataStream out(&block, QIODevice::WriteOnly);
    out << (quint16)0;

    out << (quint8)GET_POSSIBLE_CONTACTS;

    out.device()->seek(0);

    out << (quint16)(block.size() - sizeof(quint16));

    _socket->write(block);

    QList<User *> *result = new QList<User *>();

    User *user8 = UserCreator::getInstance().createUser(8, "User8");
    User *user9 = UserCreator::getInstance().createUser(9, "User9");
    User *user10 = UserCreator::getInstance().createUser(10, "User10");

    result->append(user8);
    result->append(user9);
    result->append(user10);

    emit possibleContacts(result);
}
