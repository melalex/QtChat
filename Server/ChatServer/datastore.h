#ifndef DATASTORE_H
#define DATASTORE_H

#include <QObject>
#include <QtSql>

#include "models.h"

class DataStore : public QObject
{
    Q_OBJECT
public:
    explicit DataStore(QObject *parent = 0);

    bool isUserExist(QString login);
    quint32 getMembersCount(quint32 groupId);

    bool trySignUp(QString login, QString password);
    bool trySignIn(QString login, QString password, quint32 &id);

    void addMessage(quint32 senderId, quint32 groupId, quint64 time, QString text);
    quint32 createGroup(QString name, const QList<quint32> &members);

    QList<Dialog *> *getDialogs(quint32 userId);
    QList<Group *> *getGroups(quint32 userId);

    QString getUserById(quint32 id);
    QList<Message *> *getMessagesFromGroupWithId(quint32 groupId);
    QList<User *> *getPossibleContacts(QString loginPart);
    QList<quint32> *getUsersIdFromGroupWthId(quint32 groupId);

    void liveGroup(quint32 userId, quint32 groupId);

signals:

public slots:

private:
    QSqlDatabase _dataBase;

    QString _isUserExistQuery;
    QString _membersCountQuery;

    QString _selectFromUsersWithLoginQuery;
    QString _selectFromUsersWithLoginPartQuery;
    QString _selectFromUsersWithIdQuery;
    QString _selectMessagesWithGroupIdQuery;
    QString _selectUsersInGroupQuery;

    QString _insertToUsersQuery;
    QString _insertToGroupsQuery;
    QString _insertToMessagesQuery;
    QString _insertToGroupTransferQuery;

    QString _deleteFromGroupsQuery;
    QString _deleteFromMessagesQuery;
    QString _deleteFromGroupTransferQuery;


};

#endif // DATASTORE_H
