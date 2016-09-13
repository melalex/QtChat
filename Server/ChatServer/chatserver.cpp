#include "chatserver.h"
#include "client.h"
#include "datastore.h"

#include <QDebug>
#include <QDateTime>
#include <QDir>

ChatServer::ChatServer(QObject *parent) :
    QTcpServer(parent)
{
    _dataStore = new DataStore(this);
}

ChatServer::~ChatServer()
{
    qDeleteAll(_clients);

    delete _dataStore;
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

    connect(client, SIGNAL(signUp(Client*,QString,QString)), this, SLOT(signUp(Client*,QString,QString)));
    connect(client, SIGNAL(signIn(Client*,QString,QString)), this, SLOT(signIn(Client*,QString,QString)));
    connect(client, SIGNAL(getUser(Client*,quint32)), this, SLOT(getUser(Client*,quint32)));
    connect(client, SIGNAL(getMessages(Client*,quint32)), this, SLOT(getMessages(Client*,quint32)));
    connect(client, SIGNAL(getPossibleContacts(Client*,QString)), this, SLOT(getPossibleContacts(Client*,QString)));
    connect(client, SIGNAL(sendMessage(quint32,quint32,QString)), this, SLOT(sendMessage(quint32,quint32,QString)));
    connect(client, SIGNAL(addContact(Client*,quint32)), this, SLOT(addContact(Client*,quint32)));
    connect(client, SIGNAL(createGroup(Client*,QString,QList<quint32>)), this, SLOT(createGroup(Client*,QString,QList<quint32>)));
    connect(client, SIGNAL(liveGroup(quint32,quint32)), this, SLOT(liveGroup(quint32,quint32)));
    connect(client, SIGNAL(clientDisconected(quint32)), this, SLOT(clientDisconected(quint32)));
}

void ChatServer::signUp(Client *client, QString login, QString password)
{
    qDebug() << "["  << QDateTime::currentDateTime().toString("dd.MM.yyyy hh:mm") << "]"
             << "Client try to sign up with login " << login << " and password " << password;

    if (_dataStore->trySignUp(login, password))
    {
        client->registered();
    }
    else
    {
        client->notRegistered();
    }
}

void ChatServer::signIn(Client *client, QString login, QString password)
{
    qDebug() << "["  << QDateTime::currentDateTime().toString("dd.MM.yyyy hh:mm") << "]"
             << "Client try to sign in with login " << login << " and password " << password;

    quint32 id;
    if (_dataStore->trySignIn(login, password, id))
    {
        _clients.insert(id, client);
        client->loged(id);

        QList<Dialog *> *dialogs = _dataStore->getDialogs(id);
        QList<Group *> *groups = _dataStore->getGroups(id);

        for (Dialog *dialog: *dialogs)
        {
            client->newContact(dialog->id, dialog->interlocutorId, dialog->interlocutorName);
        }

        for (Group *group: *groups)
        {
            client->newGroup(group->id, group->name, group->members);
        }

        qDeleteAll(*dialogs);
        qDeleteAll(*groups);

        delete dialogs;
        delete groups;
    }
    else
    {
        client->notLoged();
    }
}

void ChatServer::getUser(Client *client, quint32 userId)
{
    qDebug() << "["  << QDateTime::currentDateTime().toString("dd.MM.yyyy hh:mm") << "]"
             << "Client with id " << client->id() << " request user with id " << userId;

    QString login = _dataStore->getUserById(userId);

    client->newUser(userId, login);
}

void ChatServer::getMessages(Client *client, quint32 groupId)
{
    qDebug() << "["  << QDateTime::currentDateTime().toString("dd.MM.yyyy hh:mm") << "]"
             << "Client with id " << client->id() << " request messages from group with id " << groupId;

    QList<Message *> *messages = _dataStore->getMessagesFromGroupWithId(groupId);

    for (Message *message: *messages)
    {
        client->newMessage(message->senderId, groupId, message->time, message->text);
    }

    qDeleteAll(*messages);
    delete messages;
}

void ChatServer::getPossibleContacts(Client *client, QString loginPart)
{
    qDebug() << "["  << QDateTime::currentDateTime().toString("dd.MM.yyyy hh:mm") << "]"
             << "Client with id " << client->id() << " request possible contacts with logit part " << loginPart;

    QList<User *> *users = _dataStore->getPossibleContacts(loginPart);

    client->possibleContactList(users);

    qDeleteAll(*users);
    delete users;
}

void ChatServer::sendMessage(quint32 senderId, quint32 groupId, QString text)
{
    qDebug() << "["  << QDateTime::currentDateTime().toString("dd.MM.yyyy hh:mm") << "]"
             << "Client with id " << senderId << " send message to group with id " << groupId;

    quint64 time = QDateTime::currentMSecsSinceEpoch();

    _dataStore->addMessage(senderId, groupId, time, text);

    QList<quint32> *userIds = _dataStore->getUsersIdFromGroupWthId(groupId);

    for (quint32 id: *userIds)
    {
        if (_clients.contains(id))
        {
            _clients.value(id)->newMessage(senderId, groupId, time, text);
        }
    }
}

void ChatServer::addContact(Client *client, quint32 interlocutorId)
{
    qDebug() << "["  << QDateTime::currentDateTime().toString("dd.MM.yyyy hh:mm") << "]"
             << "Client with id " << client->id() << " added to friends user with id " << interlocutorId;

    QString interlocutorName = _dataStore->getUserById(interlocutorId);
    QString clientName = _dataStore->getUserById(client->id());

    QList<quint32> members;
    members.append(client->id());
    members.append(interlocutorId);

    quint32 groupId = _dataStore->createGroup("__Dialog__", members); // (ಠ_ಠ)

    client->newContact(groupId, interlocutorId, interlocutorName);

    if (_clients.contains(interlocutorId))
    {
        _clients.value(interlocutorId)->newContact(groupId, client->id(), clientName);
    }
}

void ChatServer::createGroup(Client *client, QString name, const QList<quint32> &members)
{
    qDebug() << "["  << QDateTime::currentDateTime().toString("dd.MM.yyyy hh:mm") << "]"
             << "Client with id " << client->id() << " create group with name " << name;

    quint32 groupId = _dataStore->createGroup(name, members);

    for (quint32 id: members)
    {
        if (_clients.contains(id))
        {
            _clients.value(id)->newGroup(groupId, name, members);
        }
    }
}

void ChatServer::liveGroup(quint32 clientId, quint32 groupId)
{
    qDebug() << "["  << QDateTime::currentDateTime().toString("dd.MM.yyyy hh:mm") << "]"
             << "Client with id " << clientId << " left group with id " << groupId;

    sendMessage(clientId, groupId, "Left chat");

    _dataStore->liveGroup(clientId, groupId);
}

void ChatServer::clientDisconected(quint32 id)
{
    _clients.remove(id);
}
