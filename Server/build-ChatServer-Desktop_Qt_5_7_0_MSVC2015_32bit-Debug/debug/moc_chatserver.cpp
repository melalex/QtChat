/****************************************************************************
** Meta object code from reading C++ file 'chatserver.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.7.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../ChatServer/chatserver.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#include <QtCore/QList>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'chatserver.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.7.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_ChatServer_t {
    QByteArrayData data[27];
    char stringdata0[253];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_ChatServer_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_ChatServer_t qt_meta_stringdata_ChatServer = {
    {
QT_MOC_LITERAL(0, 0, 10), // "ChatServer"
QT_MOC_LITERAL(1, 11, 6), // "signUp"
QT_MOC_LITERAL(2, 18, 0), // ""
QT_MOC_LITERAL(3, 19, 7), // "Client*"
QT_MOC_LITERAL(4, 27, 6), // "client"
QT_MOC_LITERAL(5, 34, 5), // "login"
QT_MOC_LITERAL(6, 40, 8), // "password"
QT_MOC_LITERAL(7, 49, 6), // "signIn"
QT_MOC_LITERAL(8, 56, 7), // "getUser"
QT_MOC_LITERAL(9, 64, 6), // "userId"
QT_MOC_LITERAL(10, 71, 11), // "getMessages"
QT_MOC_LITERAL(11, 83, 7), // "groupId"
QT_MOC_LITERAL(12, 91, 19), // "getPossibleContacts"
QT_MOC_LITERAL(13, 111, 9), // "loginPart"
QT_MOC_LITERAL(14, 121, 11), // "sendMessage"
QT_MOC_LITERAL(15, 133, 8), // "senderId"
QT_MOC_LITERAL(16, 142, 4), // "text"
QT_MOC_LITERAL(17, 147, 10), // "addContact"
QT_MOC_LITERAL(18, 158, 14), // "interlocutorId"
QT_MOC_LITERAL(19, 173, 11), // "createGroup"
QT_MOC_LITERAL(20, 185, 4), // "name"
QT_MOC_LITERAL(21, 190, 14), // "QList<quint32>"
QT_MOC_LITERAL(22, 205, 7), // "members"
QT_MOC_LITERAL(23, 213, 9), // "liveGroup"
QT_MOC_LITERAL(24, 223, 8), // "clientId"
QT_MOC_LITERAL(25, 232, 17), // "clientDisconected"
QT_MOC_LITERAL(26, 250, 2) // "id"

    },
    "ChatServer\0signUp\0\0Client*\0client\0"
    "login\0password\0signIn\0getUser\0userId\0"
    "getMessages\0groupId\0getPossibleContacts\0"
    "loginPart\0sendMessage\0senderId\0text\0"
    "addContact\0interlocutorId\0createGroup\0"
    "name\0QList<quint32>\0members\0liveGroup\0"
    "clientId\0clientDisconected\0id"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ChatServer[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      10,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    3,   64,    2, 0x08 /* Private */,
       7,    3,   71,    2, 0x08 /* Private */,
       8,    2,   78,    2, 0x08 /* Private */,
      10,    2,   83,    2, 0x08 /* Private */,
      12,    2,   88,    2, 0x08 /* Private */,
      14,    3,   93,    2, 0x08 /* Private */,
      17,    2,  100,    2, 0x08 /* Private */,
      19,    3,  105,    2, 0x08 /* Private */,
      23,    2,  112,    2, 0x08 /* Private */,
      25,    1,  117,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 3, QMetaType::QString, QMetaType::QString,    4,    5,    6,
    QMetaType::Void, 0x80000000 | 3, QMetaType::QString, QMetaType::QString,    4,    5,    6,
    QMetaType::Void, 0x80000000 | 3, QMetaType::UInt,    4,    9,
    QMetaType::Void, 0x80000000 | 3, QMetaType::UInt,    4,   11,
    QMetaType::Void, 0x80000000 | 3, QMetaType::QString,    4,   13,
    QMetaType::Void, QMetaType::UInt, QMetaType::UInt, QMetaType::QString,   15,   11,   16,
    QMetaType::Void, 0x80000000 | 3, QMetaType::UInt,    4,   18,
    QMetaType::Void, 0x80000000 | 3, QMetaType::QString, 0x80000000 | 21,    4,   20,   22,
    QMetaType::Void, QMetaType::UInt, QMetaType::UInt,   24,   11,
    QMetaType::Void, QMetaType::UInt,   26,

       0        // eod
};

void ChatServer::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        ChatServer *_t = static_cast<ChatServer *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->signUp((*reinterpret_cast< Client*(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< QString(*)>(_a[3]))); break;
        case 1: _t->signIn((*reinterpret_cast< Client*(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< QString(*)>(_a[3]))); break;
        case 2: _t->getUser((*reinterpret_cast< Client*(*)>(_a[1])),(*reinterpret_cast< quint32(*)>(_a[2]))); break;
        case 3: _t->getMessages((*reinterpret_cast< Client*(*)>(_a[1])),(*reinterpret_cast< quint32(*)>(_a[2]))); break;
        case 4: _t->getPossibleContacts((*reinterpret_cast< Client*(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 5: _t->sendMessage((*reinterpret_cast< quint32(*)>(_a[1])),(*reinterpret_cast< quint32(*)>(_a[2])),(*reinterpret_cast< QString(*)>(_a[3]))); break;
        case 6: _t->addContact((*reinterpret_cast< Client*(*)>(_a[1])),(*reinterpret_cast< quint32(*)>(_a[2]))); break;
        case 7: _t->createGroup((*reinterpret_cast< Client*(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< const QList<quint32>(*)>(_a[3]))); break;
        case 8: _t->liveGroup((*reinterpret_cast< quint32(*)>(_a[1])),(*reinterpret_cast< quint32(*)>(_a[2]))); break;
        case 9: _t->clientDisconected((*reinterpret_cast< quint32(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 7:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 2:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QList<quint32> >(); break;
            }
            break;
        }
    }
}

const QMetaObject ChatServer::staticMetaObject = {
    { &QTcpServer::staticMetaObject, qt_meta_stringdata_ChatServer.data,
      qt_meta_data_ChatServer,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *ChatServer::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ChatServer::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_ChatServer.stringdata0))
        return static_cast<void*>(const_cast< ChatServer*>(this));
    return QTcpServer::qt_metacast(_clname);
}

int ChatServer::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QTcpServer::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 10)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 10;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 10)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 10;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
