#ifndef PROTOCOL_H
#define PROTOCOL_H

#include <QtGlobal>

enum Request : quint8
{
    SIGN_UP,
    SIGN_IN,

    GET_GROUPS,
    GET_USER,
    GET_MESSAGES,
    GET_POSSIBLE_CONTACTS,

    SEND_MESSAGE,

    ADD_CONTACT,
    CREATE_GROUP,

    LIVE_GROUP
};

enum Response : quint8
{
    LOGED,
    NOT_LOGED,

    REGISTERED,
    NOT_REGISTERED,

    NEW_MESSAGE,
    NEW_USER,
    NEW_CONTACT,
    NEW_GROUP,

    POSSIBLE_CONTACTS_LIST,
};

#endif // PROTOCOL_H
