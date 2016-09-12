#ifndef MODELS_H
#define MODELS_H

#include <QtGlobal>
#include <QString>

struct User
{
    quint32 id;
    QString login;
};

struct Group
{
    quint32 id;
    QString name;
    QList<quint32> members;
};

struct Message
{
    quint32 senderId;
    quint32 groupId;
    quint64 time;
    QString text;
};

#endif // MODELS_H
