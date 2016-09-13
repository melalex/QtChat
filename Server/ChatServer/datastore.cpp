#include "datastore.h"

DataStore::DataStore(QObject *parent) : QObject(parent)
{
    _dataBase = QSqlDatabase::addDatabase("QSQLITE");
    _dataBase.setDatabaseName("C:\\Chat\\Server\\ChatServer\\chat.sqlite");

    if (!_dataBase.open())
    {
        qDebug() << "Error: " << _dataBase.lastError().text();
    }

    _isUserExistQuery = "SELECT COUNT(login) FROM users WHERE login = :login";
    _membersCountQuery = "SELECT COUNT(group_id) FROM group_transfer WHERE group_id = :group_id";

    _selectFromUsersWithLoginQuery = "SELECT _id, password FROM users WHERE login = :login";
    _selectFromUsersWithLoginPartQuery = "SELECT _id, login FROM users WHERE login LIKE '%:loginPart%'";
    _selectFromUsersWithIdQuery = "SELECT login FROM users WHERE _id = :id;";
    _selectMessagesWithGroupIdQuery = "SELECT sender_id, date_time, text FROM messages WHERE group_id = :groupId";
    _selectUsersInGroupQuery = "SELECT user_id FROM group_transfer WHERE group_id = :groupId";

    _insertToUsersQuery = "INSERT INTO users(login, password) VALUES (:login, :password)";
    _insertToGroupsQuery = "INSERT INTO groups(name) VALUES (:name);";
    _insertToMessagesQuery = "INSERT INTO messages(sender_id, group_id, date_time, text) VALUES (:senderId, :groupId, :time, :text) ORDER BY date_time";
    _insertToGroupTransferQuery = "INSERT INTO group_transfer(group_id, user_id) VALUES (:group_id, :user_id)";

    _deleteFromGroupsQuery = "DELETE FROM groups WHERE group_id = :groupId";
    _deleteFromMessagesQuery = "DELETE FROM messages WHERE group_id = :groupId";
    _deleteFromGroupTransferQuery = "DELETE FROM group_transfer WHERE group_id = :groupId AND user_id = :userId";
}

bool DataStore::isUserExist(QString login)
{
    QSqlQuery query = QSqlQuery(_dataBase);
    query.prepare(_isUserExistQuery);

    bool result = true;

    query.bindValue(":login", login);
    query.exec();
    query.next();

    if (query.value(0).toInt() == 0)
    {
        result = false;
    }

    return result;
}

quint32 DataStore::getMembersCount(quint32 groupId)
{
    QSqlQuery query = QSqlQuery(_dataBase);
    query.prepare(_membersCountQuery);

    query.bindValue(":group_id", groupId);
    query.exec();
    query.next();

    return query.value(0).toInt();
}

bool DataStore::trySignUp(QString login, QString password)
{
    bool result;

    if (isUserExist(login))
    {
        result = false;
    }
    else
    {
        QSqlQuery query = QSqlQuery(_dataBase);
        query.prepare(_insertToUsersQuery);

        query.bindValue(":login", login);
        query.bindValue(":password", password);
        query.exec();

        result = true;
    }

    return result;
}

bool DataStore::trySignIn(QString login, QString password, quint32 &id)
{
    bool result = false;

    QSqlQuery query = QSqlQuery(_dataBase);
    query.prepare(_selectFromUsersWithLoginQuery);

    query.bindValue(":login", login);
    query.exec();

    if (query.next())
    {
        QString passwordFromBd = query.value(1).toString();

        if (QString::compare(password, passwordFromBd, Qt::CaseSensitive) == 0)
        {
            id = query.value(0).toInt();
            result = true;
        }
    }

    return result;
}

void DataStore::addMessage(quint32 senderId, quint32 groupId, quint64 time, QString text)
{
    QSqlQuery query = QSqlQuery(_dataBase);
    query.prepare(_insertToMessagesQuery);

    query.bindValue(":senderId", senderId);
    query.bindValue(":groupId", groupId);
    query.bindValue(":time", time);
    query.bindValue(":text", text);
    query.exec();
}

quint32 DataStore::createGroup(QString name, const QList<quint32> &members)
{
    quint32 result;
    QSqlQuery query = QSqlQuery(_dataBase);
    query.prepare(_insertToGroupsQuery);

    query.bindValue(":name", name);
    query.exec();

    result = query.lastInsertId().toInt();

    for (quint32 userId: members)
    {
        query.prepare(_insertToGroupTransferQuery);
        query.bindValue(":group_id", result);
        query.bindValue(":user_id", userId);
        query.exec();
    }

    return result;
}

QList<Dialog *> *DataStore::getDialogs(quint32 userId)
{
    return nullptr;
}

QList<Group *> *DataStore::getGroups(quint32 userId)
{
    return nullptr;
}

QString DataStore::getUserById(quint32 id)
{
    QString result;

    QSqlQuery query = QSqlQuery(_dataBase);
    query.prepare(_selectFromUsersWithIdQuery);

    query.bindValue(":id", id);
    query.exec();

    if (query.next())
    {
        result = query.value(0).toString();
    }

    return result;
}

QList<Message *> *DataStore::getMessagesFromGroupWithId(quint32 groupId)
{
    QList<Message *> *result = new QList<Message *>();

    QSqlQuery query = QSqlQuery(_dataBase);
    query.prepare(_selectMessagesWithGroupIdQuery);

    query.bindValue(":groupId", groupId);
    query.exec();

    Message *message = nullptr;
    while (query.next())
    {
        message = new Message();

        message->groupId = groupId;
        message->senderId = query.value(0).toInt();
        message->time = query.value(1).toInt();
        message->text = query.value(2).toString();

        result->append(message);
    }

    return result;
}

QList<User *> *DataStore::getPossibleContacts(QString loginPart)
{
    QList<User *> *result = new QList<User *>();

    QSqlQuery query = QSqlQuery(_dataBase);
    query.prepare(_selectFromUsersWithLoginPartQuery);

    query.bindValue(":loginPart", loginPart);
    query.exec();

    User *user = nullptr;
    while (query.next())
    {
        user = new User();

        user->id = query.value(0).toInt();
        user->login = query.value(1).toString();

        result->append(user);
    }

    return result;
}

QList<quint32> *DataStore::getUsersIdFromGroupWthId(quint32 groupId)
{
    QList<quint32> *result = new QList<quint32>();

    QSqlQuery query = QSqlQuery(_dataBase);
    query.prepare(_selectUsersInGroupQuery);

    query.bindValue(":groupId", groupId);
    query.exec();

    quint32 userId;
    while (query.next())
    {
        userId = query.value(0).toInt();

        result->append(userId);
    }

    return result;
}

void DataStore::liveGroup(quint32 userId, quint32 groupId)
{
    QSqlQuery query = QSqlQuery(_dataBase);
    query.prepare(_deleteFromGroupTransferQuery);

    query.bindValue(":groupId", groupId);
    query.bindValue(":userId", userId);
    query.exec();

    if (getMembersCount(groupId) == 0)
    {
        query.prepare(_deleteFromMessagesQuery);
        query.bindValue(":groupId", groupId);
        query.exec();

        query.prepare(_deleteFromGroupsQuery);
        query.bindValue(":groupId", groupId);
        query.exec();
    }
}
