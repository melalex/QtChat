#include "message.h"
#include "user.h"

Message::Message(const QDateTime &time, const QString &text, User *sender, Group *group) :
    _time(time), _text(text), _sender(sender), _group(group)
{

}

QDateTime Message::getTime()
{
    return _time;
}

QString Message::getText()
{
    return _text;
}

User *Message::getSender()
{
    return _sender;
}

Group *Message::getGroup()
{
    return _group;
}

QString Message::toString()
{
    QString time = _time.toString("dd.MM.yyyy hh:mm");
    QString result = QString("%1 (%3): %2").arg(_sender->getLogin(), time, _text);
    return result;
}
