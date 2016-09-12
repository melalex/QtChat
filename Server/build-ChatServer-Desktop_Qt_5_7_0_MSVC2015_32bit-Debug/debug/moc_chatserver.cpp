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
    QByteArrayData data[28];
    char stringdata0[263];
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
QT_MOC_LITERAL(8, 56, 9), // "getGroups"
QT_MOC_LITERAL(9, 66, 7), // "getUser"
QT_MOC_LITERAL(10, 74, 6), // "userId"
QT_MOC_LITERAL(11, 81, 11), // "getMessages"
QT_MOC_LITERAL(12, 93, 7), // "groupId"
QT_MOC_LITERAL(13, 101, 19), // "getPossibleContacts"
QT_MOC_LITERAL(14, 121, 9), // "loginPart"
QT_MOC_LITERAL(15, 131, 11), // "sendMessage"
QT_MOC_LITERAL(16, 143, 8), // "senderId"
QT_MOC_LITERAL(17, 152, 4), // "text"
QT_MOC_LITERAL(18, 157, 10), // "addContact"
QT_MOC_LITERAL(19, 168, 14), // "interlocutorId"
QT_MOC_LITERAL(20, 183, 11), // "createGroup"
QT_MOC_LITERAL(21, 195, 4), // "name"
QT_MOC_LITERAL(22, 200, 14), // "QList<quint32>"
QT_MOC_LITERAL(23, 215, 7), // "members"
QT_MOC_LITERAL(24, 223, 9), // "liveGroup"
QT_MOC_LITERAL(25, 233, 8), // "clientId"
QT_MOC_LITERAL(26, 242, 17), // "clientDisconected"
QT_MOC_LITERAL(27, 260, 2) // "id"

    },
    "ChatServer\0signUp\0\0Client*\0client\0"
    "login\0password\0signIn\0getGroups\0getUser\0"
    "userId\0getMessages\0groupId\0"
    "getPossibleContacts\0loginPart\0sendMessage\0"
    "senderId\0text\0addContact\0interlocutorId\0"
    "createGroup\0name\0QList<quint32>\0members\0"
    "liveGroup\0clientId\0clientDisconected\0"
    "id"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ChatServer[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      11,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    3,   69,    2, 0x08 /* Private */,
       7,    3,   76,    2, 0x08 /* Private */,
       8,    1,   83,    2, 0x08 /* Private */,
       9,    2,   86,    2, 0x08 /* Private */,
      11,    2,   91,    2, 0x08 /* Private */,
      13,    2,   96,    2, 0x08 /* Private */,
      15,    3,  101,    2, 0x08 /* Private */,
      18,    2,  108,    2, 0x08 /* Private */,
      20,    3,  113,    2, 0x08 /* Private */,
      24,    2,  120,    2, 0x08 /* Private */,
      26,    1,  125,    2, 0x08 /* Private */,

 // slots: parameters
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
        case 2: _t->getGroups((*reinterpret_cast< Client*(*)>(_a[1]))); break;
        case 3: _t->getUser((*reinterpret_cast< Client*(*)>(_a[1])),(*reinterpret_cast< quint32(*)>(_a[2]))); break;
        case 4: _t->getMessages((*reinterpret_cast< Client*(*)>(_a[1])),(*reinterpret_cast< quint32(*)>(_a[2]))); break;
        case 5: _t->getPossibleContacts((*reinterpret_cast< Client*(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 6: _t->sendMessage((*reinterpret_cast< quint32(*)>(_a[1])),(*reinterpret_cast< quint32(*)>(_a[2])),(*reinterpret_cast< QString(*)>(_a[3]))); break;
        case 7: _t->addContact((*reinterpret_cast< Client*(*)>(_a[1])),(*reinterpret_cast< quint32(*)>(_a[2]))); break;
        case 8: _t->createGroup((*reinterpret_cast< Client*(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< const QList<quint32>(*)>(_a[3]))); break;
        case 9: _t->liveGroup((*reinterpret_cast< quint32(*)>(_a[1])),(*reinterpret_cast< quint32(*)>(_a[2]))); break;
        case 10: _t->clientDisconected((*reinterpret_cast< quint32(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 8:
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
        if (_id < 11)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 11;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 11)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 11;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
