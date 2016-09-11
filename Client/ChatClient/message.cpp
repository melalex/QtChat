#include "message.h"
#include "user.h"

Message::Message(const QDateTime &time, const QString &text, User *sender) :
    _time(time), _text(text), _sender(sender)
{

}

void Message::setGroup(Group *group)
{
    _group = group;
}

QDateTime Message::getTime() const
{
    return _time;
}

QString Message::getText() const
{
    return _text;
}

User *Message::getSender() const
{
    return _sender;
}

Group *Message::getGroup() const
{
    return _group;
}

QString Message::toString() const
{
    QString time = _time.toString("dd.MM.yyyy hh:mm");
    QString result = QString("%1 [%2]: %3\n").arg(_sender->getLogin(), time, _text);
    return result;
}
