#include "user.h"

#include <QString>

//User

User::User(quint32 id, QString login) :
    _id(id), _login(login)
{

}

quint32 User::getId()
{
    return _id;
}

QString User::getLogin()
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
