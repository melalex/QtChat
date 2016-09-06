#include <QString>

#include "user.h"

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

