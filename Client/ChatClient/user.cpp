#include "user.h"

#include <QString>

//User

User::User(quint32 id, QString login) :
    _id(id), _login(login)
{

}

quint32 User::getId() const
{
    return _id;
}

QString User::getLogin() const
{
    return _login;
}

//UserCreator

UserCreator::~UserCreator()
{
    qDeleteAll(_usersPool);
}

UserCreator& UserCreator::getInstance()
{
    static UserCreator instance;
    return instance;
}


User* UserCreator::createUser(quint32 id, QString login)
{
    User *result = nullptr;

    if (_usersPool.contains(id))
    {
        result = _usersPool.take(id);
    }
    else
    {
        result = new User(id, login);
        _usersPool.insert(id, result);
    }

    return result;
}

User* UserCreator::userById(quint32 id)
{
    return _usersPool.take(id);
}
