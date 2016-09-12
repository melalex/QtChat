#ifndef DATASTORE_H
#define DATASTORE_H

#include <QObject>
#include <QtSql>

class DataStore : public QObject
{
    Q_OBJECT
public:
    explicit DataStore(QObject *parent = 0);

    bool isUserExist(QString login);

    bool trySignUp(QString login, QString password);
    bool trySignIn(QString login, QString password, quint32 &id);

signals:

public slots:

private:
    QSqlDatabase _dataBase;

    QSqlQuery _isUserExistQuery;

    QSqlQuery _selectFromUsersWithLoginQuery;
    QSqlQuery _selectFromUsersWithIdQuery;

    QSqlQuery _insertToUsersQuery;
    QSqlQuery _insertToGroupsQuery;
    QSqlQuery _insertToMessagesQuery;
    QSqlQuery _insertToGroupTransferQuery;

    QSqlQuery _deleteFromUsersQuery;
    QSqlQuery _deleteFromGroupsQuery;
    QSqlQuery _deleteFromMessagesQuery;
    QSqlQuery _deleteFromGroupTransferQuery;


};

#endif // DATASTORE_H
