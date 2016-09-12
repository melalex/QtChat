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

    _selectFromUsersWithLoginQuery = "SELECT _id, password FROM users WHERE login = :login";

    _insertToUsersQuery = "INSERT INTO users(login, password) VALUES (:login, :password);";
    _insertToGroupsQuery;
    _insertToMessagesQuery;
    _insertToGroupTransferQuery;

    _deleteFromUsersQuery;
    _deleteFromGroupsQuery;
    _deleteFromMessagesQuery;
    _deleteFromGroupTransferQuery;

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

    if (_selectFromUsersWithLoginQuery.size() != 0)
    {
        query.next();

        QString passwordFromBd = query.value(1).toString();

        if (QString::compare(password, passwordFromBd, Qt::CaseSensitive) == 0)
        {
            id = query.value(0).toInt();
            result = true;
        }
    }

    return result;
}
