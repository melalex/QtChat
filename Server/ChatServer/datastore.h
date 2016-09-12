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

    QString _isUserExistQuery;

    QString _selectFromUsersWithLoginQuery;
    QString _selectFromUsersWithIdQuery;

    QString _insertToUsersQuery;
    QString _insertToGroupsQuery;
    QString _insertToMessagesQuery;
    QString _insertToGroupTransferQuery;

    QString _deleteFromUsersQuery;
    QString _deleteFromGroupsQuery;
    QString _deleteFromMessagesQuery;
    QString _deleteFromGroupTransferQuery;


};

#endif // DATASTORE_H
