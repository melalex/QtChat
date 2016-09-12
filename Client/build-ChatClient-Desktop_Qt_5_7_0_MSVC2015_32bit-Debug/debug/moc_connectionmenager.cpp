/****************************************************************************
** Meta object code from reading C++ file 'connectionmenager.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.7.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../ChatClient/connectionmenager.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#include <QtCore/QList>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'connectionmenager.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.7.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_ConnectionMenager_t {
    QByteArrayData data[28];
    char stringdata0[327];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_ConnectionMenager_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_ConnectionMenager_t qt_meta_stringdata_ConnectionMenager = {
    {
QT_MOC_LITERAL(0, 0, 17), // "ConnectionMenager"
QT_MOC_LITERAL(1, 18, 14), // "connectionFail"
QT_MOC_LITERAL(2, 33, 0), // ""
QT_MOC_LITERAL(3, 34, 11), // "socketError"
QT_MOC_LITERAL(4, 46, 6), // "logged"
QT_MOC_LITERAL(5, 53, 9), // "notLogged"
QT_MOC_LITERAL(6, 63, 10), // "registered"
QT_MOC_LITERAL(7, 74, 13), // "notRegistered"
QT_MOC_LITERAL(8, 88, 16), // "possibleContacts"
QT_MOC_LITERAL(9, 105, 13), // "QList<User*>*"
QT_MOC_LITERAL(10, 119, 5), // "users"
QT_MOC_LITERAL(11, 125, 7), // "addChat"
QT_MOC_LITERAL(12, 133, 6), // "Group*"
QT_MOC_LITERAL(13, 140, 4), // "chat"
QT_MOC_LITERAL(14, 145, 12), // "addGroupChat"
QT_MOC_LITERAL(15, 158, 17), // "addMessageToGroup"
QT_MOC_LITERAL(16, 176, 8), // "senderId"
QT_MOC_LITERAL(17, 185, 7), // "groupId"
QT_MOC_LITERAL(18, 193, 4), // "time"
QT_MOC_LITERAL(19, 198, 4), // "text"
QT_MOC_LITERAL(20, 203, 11), // "sendMessage"
QT_MOC_LITERAL(21, 215, 8), // "Message*"
QT_MOC_LITERAL(22, 224, 7), // "message"
QT_MOC_LITERAL(23, 232, 14), // "onSokConnected"
QT_MOC_LITERAL(24, 247, 17), // "onSokDisconnected"
QT_MOC_LITERAL(25, 265, 14), // "onSokReadyRead"
QT_MOC_LITERAL(26, 280, 17), // "onSokDisplayError"
QT_MOC_LITERAL(27, 298, 28) // "QAbstractSocket::SocketError"

    },
    "ConnectionMenager\0connectionFail\0\0"
    "socketError\0logged\0notLogged\0registered\0"
    "notRegistered\0possibleContacts\0"
    "QList<User*>*\0users\0addChat\0Group*\0"
    "chat\0addGroupChat\0addMessageToGroup\0"
    "senderId\0groupId\0time\0text\0sendMessage\0"
    "Message*\0message\0onSokConnected\0"
    "onSokDisconnected\0onSokReadyRead\0"
    "onSokDisplayError\0QAbstractSocket::SocketError"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ConnectionMenager[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      14,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       9,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   84,    2, 0x06 /* Public */,
       4,    0,   87,    2, 0x06 /* Public */,
       5,    0,   88,    2, 0x06 /* Public */,
       6,    0,   89,    2, 0x06 /* Public */,
       7,    0,   90,    2, 0x06 /* Public */,
       8,    1,   91,    2, 0x06 /* Public */,
      11,    1,   94,    2, 0x06 /* Public */,
      14,    1,   97,    2, 0x06 /* Public */,
      15,    4,  100,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      20,    1,  109,    2, 0x0a /* Public */,
      23,    0,  112,    2, 0x08 /* Private */,
      24,    0,  113,    2, 0x08 /* Private */,
      25,    0,  114,    2, 0x08 /* Private */,
      26,    1,  115,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 9,   10,
    QMetaType::Void, 0x80000000 | 12,   13,
    QMetaType::Void, 0x80000000 | 12,   13,
    QMetaType::Void, QMetaType::UInt, QMetaType::UInt, QMetaType::ULongLong, QMetaType::QString,   16,   17,   18,   19,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 21,   22,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 27,    3,

       0        // eod
};

void ConnectionMenager::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        ConnectionMenager *_t = static_cast<ConnectionMenager *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->connectionFail((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 1: _t->logged(); break;
        case 2: _t->notLogged(); break;
        case 3: _t->registered(); break;
        case 4: _t->notRegistered(); break;
        case 5: _t->possibleContacts((*reinterpret_cast< QList<User*>*(*)>(_a[1]))); break;
        case 6: _t->addChat((*reinterpret_cast< Group*(*)>(_a[1]))); break;
        case 7: _t->addGroupChat((*reinterpret_cast< Group*(*)>(_a[1]))); break;
        case 8: _t->addMessageToGroup((*reinterpret_cast< quint32(*)>(_a[1])),(*reinterpret_cast< quint32(*)>(_a[2])),(*reinterpret_cast< quint64(*)>(_a[3])),(*reinterpret_cast< QString(*)>(_a[4]))); break;
        case 9: _t->sendMessage((*reinterpret_cast< Message*(*)>(_a[1]))); break;
        case 10: _t->onSokConnected(); break;
        case 11: _t->onSokDisconnected(); break;
        case 12: _t->onSokReadyRead(); break;
        case 13: _t->onSokDisplayError((*reinterpret_cast< QAbstractSocket::SocketError(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 13:
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
            typedef void (ConnectionMenager::*_t)(QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&ConnectionMenager::connectionFail)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (ConnectionMenager::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&ConnectionMenager::logged)) {
                *result = 1;
                return;
            }
        }
        {
            typedef void (ConnectionMenager::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&ConnectionMenager::notLogged)) {
                *result = 2;
                return;
            }
        }
        {
            typedef void (ConnectionMenager::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&ConnectionMenager::registered)) {
                *result = 3;
                return;
            }
        }
        {
            typedef void (ConnectionMenager::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&ConnectionMenager::notRegistered)) {
                *result = 4;
                return;
            }
        }
        {
            typedef void (ConnectionMenager::*_t)(QList<User*> * );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&ConnectionMenager::possibleContacts)) {
                *result = 5;
                return;
            }
        }
        {
            typedef void (ConnectionMenager::*_t)(Group * );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&ConnectionMenager::addChat)) {
                *result = 6;
                return;
            }
        }
        {
            typedef void (ConnectionMenager::*_t)(Group * );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&ConnectionMenager::addGroupChat)) {
                *result = 7;
                return;
            }
        }
        {
            typedef void (ConnectionMenager::*_t)(quint32 , quint32 , quint64 , QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&ConnectionMenager::addMessageToGroup)) {
                *result = 8;
                return;
            }
        }
    }
}

const QMetaObject ConnectionMenager::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_ConnectionMenager.data,
      qt_meta_data_ConnectionMenager,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *ConnectionMenager::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ConnectionMenager::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_ConnectionMenager.stringdata0))
        return static_cast<void*>(const_cast< ConnectionMenager*>(this));
    return QObject::qt_metacast(_clname);
}

int ConnectionMenager::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 14)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 14;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 14)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 14;
    }
    return _id;
}

// SIGNAL 0
void ConnectionMenager::connectionFail(QString _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void ConnectionMenager::logged()
{
    QMetaObject::activate(this, &staticMetaObject, 1, Q_NULLPTR);
}

// SIGNAL 2
void ConnectionMenager::notLogged()
{
    QMetaObject::activate(this, &staticMetaObject, 2, Q_NULLPTR);
}

// SIGNAL 3
void ConnectionMenager::registered()
{
    QMetaObject::activate(this, &staticMetaObject, 3, Q_NULLPTR);
}

// SIGNAL 4
void ConnectionMenager::notRegistered()
{
    QMetaObject::activate(this, &staticMetaObject, 4, Q_NULLPTR);
}

// SIGNAL 5
void ConnectionMenager::possibleContacts(QList<User*> * _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}

// SIGNAL 6
void ConnectionMenager::addChat(Group * _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 6, _a);
}

// SIGNAL 7
void ConnectionMenager::addGroupChat(Group * _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 7, _a);
}

// SIGNAL 8
void ConnectionMenager::addMessageToGroup(quint32 _t1, quint32 _t2, quint64 _t3, QString _t4)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)), const_cast<void*>(reinterpret_cast<const void*>(&_t4)) };
    QMetaObject::activate(this, &staticMetaObject, 8, _a);
}
QT_END_MOC_NAMESPACE
