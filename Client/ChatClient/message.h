#ifndef MESSAGE_H
#define MESSAGE_H

#include <QString>
#include <QDateTime>

class User;
class Group;

class Message
{
public:
    Message(const QDateTime &time, const QString &text, User *sender, Group *group);

    QDateTime getTime();
    QString getText();
    User *getSender();
    Group *getGroup();

    QString toString();

private:
    QDateTime  _time;
    QString _text;
    User *_sender;
    Group *_group;
};

#endif // MESSAGE_H
