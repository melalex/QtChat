#include "datastore.h"

DataStore::DataStore(QObject *parent) : QObject(parent)
{
    _dataBase = QSqlDatabase::addDatabase("QSQLITE");
    _dataBase.setDatabaseName("C:\\Chat\\Server\\ChatServer\\chat.sqlite");

    if (!_dataBase.open())
    {
        qDebug() << "Error: " << _dataBase.lastError().text();
    }

    _isUserExistQuery = QSqlQuery(_dataBase);
    _selectFromUsersWithLoginQuery = QSqlQuery(_dataBase);
    _insertToUsersQuery = QSqlQuery(_dataBase);

    _isUserExistQuery.prepare("SELECT COUNT(login) FROM users WHERE login = :login");

    _selectFromUsersWithLoginQuery.prepare("SELECT id, password FROM users WHERE login = :login");

    _insertToUsersQuery.prepare("INSERT INTO users(login, password) VALUES (:login, :password);");
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
    bool result = true;

    _isUserExistQuery.bindValue(":login", login);
    _isUserExistQuery.exec();
    _isUserExistQuery.next();

    if (_isUserExistQuery.value(0).toInt() == 0)
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
        _insertToUsersQuery.bindValue(":login", login);
        _insertToUsersQuery.bindValue(":password", password);
        _insertToUsersQuery.exec();

        result = true;
    }

    return result;
}

bool DataStore::trySignIn(QString login, QString password, quint32 &id)
{
    bool result = false;

    _selectFromUsersWithLoginQuery.bindValue(":login", login);
    _selectFromUsersWithLoginQuery.exec();

    if (_selectFromUsersWithLoginQuery.size() != 0)
    {
        _selectFromUsersWithLoginQuery.next();

        QString passwordFromBd = _selectFromUsersWithLoginQuery.value(1).toString();

        if (QString::compare(password, passwordFromBd, Qt::CaseSensitive) == 0)
        {
            id = _selectFromUsersWithLoginQuery.value(0).toInt();
            result = true;
        }
    }

    return result;
}
