/****************************************************************************
** Meta object code from reading C++ file 'client.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.7.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../ChatServer/client.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#include <QtCore/QList>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'client.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.7.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_Client_t {
    QByteArrayData data[34];
    char stringdata0[343];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Client_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Client_t qt_meta_stringdata_Client = {
    {
QT_MOC_LITERAL(0, 0, 6), // "Client"
QT_MOC_LITERAL(1, 7, 6), // "signUp"
QT_MOC_LITERAL(2, 14, 0), // ""
QT_MOC_LITERAL(3, 15, 7), // "Client*"
QT_MOC_LITERAL(4, 23, 6), // "client"
QT_MOC_LITERAL(5, 30, 5), // "login"
QT_MOC_LITERAL(6, 36, 8), // "password"
QT_MOC_LITERAL(7, 45, 6), // "signIn"
QT_MOC_LITERAL(8, 52, 9), // "getGroups"
QT_MOC_LITERAL(9, 62, 7), // "getUser"
QT_MOC_LITERAL(10, 70, 6), // "userId"
QT_MOC_LITERAL(11, 77, 11), // "getMessages"
QT_MOC_LITERAL(12, 89, 7), // "groupId"
QT_MOC_LITERAL(13, 97, 19), // "getPossibleContacts"
QT_MOC_LITERAL(14, 117, 9), // "loginPart"
QT_MOC_LITERAL(15, 127, 11), // "sendMessage"
QT_MOC_LITERAL(16, 139, 8), // "senderId"
QT_MOC_LITERAL(17, 148, 4), // "text"
QT_MOC_LITERAL(18, 153, 10), // "addContact"
QT_MOC_LITERAL(19, 164, 14), // "interlocutorId"
QT_MOC_LITERAL(20, 179, 11), // "createGroup"
QT_MOC_LITERAL(21, 191, 4), // "name"
QT_MOC_LITERAL(22, 196, 14), // "QList<quint32>"
QT_MOC_LITERAL(23, 211, 7), // "members"
QT_MOC_LITERAL(24, 219, 9), // "liveGroup"
QT_MOC_LITERAL(25, 229, 8), // "clientId"
QT_MOC_LITERAL(26, 238, 17), // "clientDisconected"
QT_MOC_LITERAL(27, 256, 2), // "id"
QT_MOC_LITERAL(28, 259, 9), // "onConnect"
QT_MOC_LITERAL(29, 269, 12), // "onDisconnect"
QT_MOC_LITERAL(30, 282, 11), // "onReadyRead"
QT_MOC_LITERAL(31, 294, 7), // "onError"
QT_MOC_LITERAL(32, 302, 28), // "QAbstractSocket::SocketError"
QT_MOC_LITERAL(33, 331, 11) // "socketError"

    },
    "Client\0signUp\0\0Client*\0client\0login\0"
    "password\0signIn\0getGroups\0getUser\0"
    "userId\0getMessages\0groupId\0"
    "getPossibleContacts\0loginPart\0sendMessage\0"
    "senderId\0text\0addContact\0interlocutorId\0"
    "createGroup\0name\0QList<quint32>\0members\0"
    "liveGroup\0clientId\0clientDisconected\0"
    "id\0onConnect\0onDisconnect\0onReadyRead\0"
    "onError\0QAbstractSocket::SocketError\0"
    "socketError"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Client[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      15,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
      11,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    3,   89,    2, 0x06 /* Public */,
       7,    3,   96,    2, 0x06 /* Public */,
       8,    1,  103,    2, 0x06 /* Public */,
       9,    2,  106,    2, 0x06 /* Public */,
      11,    2,  111,    2, 0x06 /* Public */,
      13,    2,  116,    2, 0x06 /* Public */,
      15,    3,  121,    2, 0x06 /* Public */,
      18,    2,  128,    2, 0x06 /* Public */,
      20,    3,  133,    2, 0x06 /* Public */,
      24,    2,  140,    2, 0x06 /* Public */,
      26,    1,  145,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      28,    0,  148,    2, 0x0a /* Public */,
      29,    0,  149,    2, 0x0a /* Public */,
      30,    0,  150,    2, 0x0a /* Public */,
      31,    1,  151,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3, QMetaType::QString, QMetaType::QString,    4,    5,    6,
    QMetaType::Void, 0x80000000 | 3, QMetaType::QString, QMetaType::QString,    4,    5,    6,
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, 0x80000000 | 3, QMetaType::UInt,    4,   10,
    QMetaType::Void, 0x80000000 | 3, QMetaType::UInt,    4,   12,
    QMetaType::Void, 0x80000000 | 3, QMetaType::QString,    4,   14,
    QMetaType::Void, QMetaType::UInt, QMetaType::UInt, QMetaType::QString,   16,   12,   17,
    QMetaType::Void, 0x80000000 | 3, QMetaType::UInt,    4,   19,
    QMetaType::Void, 0x80000000 | 3, QMetaType::QString, 0x80000000 | 22,    4,   21,   23,
    QMetaType::Void, QMetaType::UInt, QMetaType::UInt,   25,   12,
    QMetaType::Void, QMetaType::UInt,   27,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 32,   33,

       0        // eod
};

void Client::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Client *_t = static_cast<Client *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->signUp((*reinterpret_cast< Client*(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< QString(*)>(_a[3]))); break;
        case 1: _t->signIn((*reinterpret_cast< Client*(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< QString(*)>(_a[3]))); break;
        case 2: _t->getGroups((*reinterpret_cast< Client*(*)>(_a[1]))); break;
        case 3: _t->getUser((*reinterpret_cast< Client*(*)>(_a[1])),(*reinterpret_cast< quint32(*)>(_a[2]))); break;
        case 4: _t->getMessages((*reinterpret_cast< Client*(*)>(_a[1])),(*reinterpret_cast< quint32(*)>(_a[2]))); break;
        case 5: _t->getPossibleContacts((*reinterpret_cast< Client*(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 6: _t->sendMessage((*reinterpret_cast< quint32(*)>(_a[1])),(*reinterpret_cast< quint32(*)>(_a[2])),(*reinterpret_cast< QString(*)>(_a[3]))); break;
        case 7: _t->addContact((*reinterpret_cast< Client*(*)>(_a[1])),(*reinterpret_cast< quint32(*)>(_a[2]))); break;
        case 8: _t->createGroup((*reinterpret_cast< Client*(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< const QList<quint32>(*)>(_a[3]))); break;
        case 9: _t->liveGroup((*reinterpret_cast< quint32(*)>(_a[1])),(*reinterpret_cast< quint32(*)>(_a[2]))); break;
        case 10: _t->clientDisconected((*reinterpret_cast< quint32(*)>(_a[1]))); break;
        case 11: _t->onConnect(); break;
        case 12: _t->onDisconnect(); break;
        case 13: _t->onReadyRead(); break;
        case 14: _t->onError((*reinterpret_cast< QAbstractSocket::SocketError(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 0:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< Client* >(); break;
            }
            break;
        case 1:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< Client* >(); break;
            }
            break;
        case 2:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< Client* >(); break;
            }
            break;
        case 3:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< Client* >(); break;
            }
            break;
        case 4:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< Client* >(); break;
            }
            break;
        case 5:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< Client* >(); break;
            }
            break;
        case 7:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< Client* >(); break;
            }
            break;
        case 8:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< Client* >(); break;
            case 2:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QList<quint32> >(); break;
            }
            break;
        case 14:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QAbstractSocket::SocketError >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (Client::*_t)(Client * , QString , QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Client::signUp)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (Client::*_t)(Client * , QString , QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Client::signIn)) {
                *result = 1;
                return;
            }
        }
        {
            typedef void (Client::*_t)(Client * );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Client::getGroups)) {
                *result = 2;
                return;
            }
        }
        {
            typedef void (Client::*_t)(Client * , quint32 );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Client::getUser)) {
                *result = 3;
                return;
            }
        }
        {
            typedef void (Client::*_t)(Client * , quint32 );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Client::getMessages)) {
                *result = 4;
                return;
            }
        }
        {
            typedef void (Client::*_t)(Client * , QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Client::getPossibleContacts)) {
                *result = 5;
                return;
            }
        }
        {
            typedef void (Client::*_t)(quint32 , quint32 , QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Client::sendMessage)) {
                *result = 6;
                return;
            }
        }
        {
            typedef void (Client::*_t)(Client * , quint32 );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Client::addContact)) {
                *result = 7;
                return;
            }
        }
        {
            typedef void (Client::*_t)(Client * , QString , const QList<quint32> & );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Client::createGroup)) {
                *result = 8;
                return;
            }
        }
        {
            typedef void (Client::*_t)(quint32 , quint32 );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Client::liveGroup)) {
                *result = 9;
                return;
            }
        }
        {
            typedef void (Client::*_t)(quint32 );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Client::clientDisconected)) {
                *result = 10;
                return;
            }
        }
    }
}

const QMetaObject Client::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_Client.data,
      qt_meta_data_Client,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *Client::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Client::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_Client.stringdata0))
        return static_cast<void*>(const_cast< Client*>(this));
    return QObject::qt_metacast(_clname);
}

int Client::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 15)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 15;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 15)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 15;
    }
    return _id;
}

// SIGNAL 0
void Client::signUp(Client * _t1, QString _t2, QString _t3)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void Client::signIn(Client * _t1, QString _t2, QString _t3)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void Client::getGroups(Client * _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void Client::getUser(Client * _t1, quint32 _t2)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void Client::getMessages(Client * _t1, quint32 _t2)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void Client::getPossibleContacts(Client * _t1, QString _t2)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}

// SIGNAL 6
void Client::sendMessage(quint32 _t1, quint32 _t2, QString _t3)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)) };
    QMetaObject::activate(this, &staticMetaObject, 6, _a);
}

// SIGNAL 7
void Client::addContact(Client * _t1, quint32 _t2)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 7, _a);
}

// SIGNAL 8
void Client::createGroup(Client * _t1, QString _t2, const QList<quint32> & _t3)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)) };
    QMetaObject::activate(this, &staticMetaObject, 8, _a);
}

// SIGNAL 9
void Client::liveGroup(quint32 _t1, quint32 _t2)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 9, _a);
}

// SIGNAL 10
void Client::clientDisconected(quint32 _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 10, _a);
}
QT_END_MOC_NAMESPACE