#ifndef USER_H
#define USER_H

#include <QtGlobal>

#include <string>

class QString;

class User
{
public:
    User(quint32 id, QString login);

    quint32 getId();
    QString getLogin();

private:
    quint32 _id;
    QString _login;
};

#endif // USER_H
