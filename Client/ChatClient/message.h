#ifndef MESSAGE_H
#define MESSAGE_H

#include <QString>
#include <QDateTime>

class User;
class Group;

class Message
{
public:
    Message(const QDateTime &time, const QString &text, User *sender);

    void setGroup(Group *group);

    Group *getGroup() const;
    QDateTime getTime() const;
    QString getText() const;
    User *getSender() const;

    QString toString() const;

private:
    QDateTime  _time;
    QString _text;
    User *_sender;
    Group *_group;
};

#endif // MESSAGE_H
