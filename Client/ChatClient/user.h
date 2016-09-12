#ifndef USER_H
#define USER_H

#include <QtGlobal>
#include <QHash>

class QString;
class User;

class UserCreator
{
public:
    static UserCreator& getInstance();

    User* createUser(quint32 id, QString login);
    User* userById(quint32 id);

private:
    QHash<quint32, User *> _usersPool;

    UserCreator() = default;
    UserCreator(const UserCreator&) = default;

    ~UserCreator();

    UserCreator& operator=(UserCreator&) = default;
};

class User
{
    friend class UserCreator;

public:
    void setId(quint32 id);

    quint32 getId() const;
    QString getLogin() const;

private:
    quint32 _id;
    QString _login;

    User(quint32 id, QString login);
};

#endif // USER_H
