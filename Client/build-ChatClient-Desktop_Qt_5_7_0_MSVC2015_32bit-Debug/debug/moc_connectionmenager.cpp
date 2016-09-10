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
    QByteArrayData data[17];
    char stringdata0[174];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_ConnectionMenager_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_ConnectionMenager_t qt_meta_stringdata_ConnectionMenager = {
    {
QT_MOC_LITERAL(0, 0, 17), // "ConnectionMenager"
QT_MOC_LITERAL(1, 18, 6), // "logged"
QT_MOC_LITERAL(2, 25, 0), // ""
QT_MOC_LITERAL(3, 26, 9), // "notLogged"
QT_MOC_LITERAL(4, 36, 10), // "registered"
QT_MOC_LITERAL(5, 47, 13), // "notRegistered"
QT_MOC_LITERAL(6, 61, 16), // "possibleContacts"
QT_MOC_LITERAL(7, 78, 13), // "QList<User*>*"
QT_MOC_LITERAL(8, 92, 5), // "users"
QT_MOC_LITERAL(9, 98, 7), // "addChat"
QT_MOC_LITERAL(10, 106, 6), // "Group*"
QT_MOC_LITERAL(11, 113, 4), // "chat"
QT_MOC_LITERAL(12, 118, 12), // "addGroupChat"
QT_MOC_LITERAL(13, 131, 17), // "addMessageToGroup"
QT_MOC_LITERAL(14, 149, 8), // "Message*"
QT_MOC_LITERAL(15, 158, 7), // "message"
QT_MOC_LITERAL(16, 166, 7) // "groupId"

    },
    "ConnectionMenager\0logged\0\0notLogged\0"
    "registered\0notRegistered\0possibleContacts\0"
    "QList<User*>*\0users\0addChat\0Group*\0"
    "chat\0addGroupChat\0addMessageToGroup\0"
    "Message*\0message\0groupId"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ConnectionMenager[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       8,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   54,    2, 0x06 /* Public */,
       3,    0,   55,    2, 0x06 /* Public */,
       4,    0,   56,    2, 0x06 /* Public */,
       5,    0,   57,    2, 0x06 /* Public */,
       6,    1,   58,    2, 0x06 /* Public */,
       9,    1,   61,    2, 0x06 /* Public */,
      12,    1,   64,    2, 0x06 /* Public */,
      13,    2,   67,    2, 0x06 /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 7,    8,
    QMetaType::Void, 0x80000000 | 10,   11,
    QMetaType::Void, 0x80000000 | 10,   11,
    QMetaType::Void, 0x80000000 | 14, QMetaType::UInt,   15,   16,

       0        // eod
};

void ConnectionMenager::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        ConnectionMenager *_t = static_cast<ConnectionMenager *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->logged(); break;
        case 1: _t->notLogged(); break;
        case 2: _t->registered(); break;
        case 3: _t->notRegistered(); break;
        case 4: _t->possibleContacts((*reinterpret_cast< QList<User*>*(*)>(_a[1]))); break;
        case 5: _t->addChat((*reinterpret_cast< Group*(*)>(_a[1]))); break;
        case 6: _t->addGroupChat((*reinterpret_cast< Group*(*)>(_a[1]))); break;
        case 7: _t->addMessageToGroup((*reinterpret_cast< Message*(*)>(_a[1])),(*reinterpret_cast< quint32(*)>(_a[2]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (ConnectionMenager::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&ConnectionMenager::logged)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (ConnectionMenager::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&ConnectionMenager::notLogged)) {
                *result = 1;
                return;
            }
        }
        {
            typedef void (ConnectionMenager::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&ConnectionMenager::registered)) {
                *result = 2;
                return;
            }
        }
        {
            typedef void (ConnectionMenager::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&ConnectionMenager::notRegistered)) {
                *result = 3;
                return;
            }
        }
        {
            typedef void (ConnectionMenager::*_t)(QList<User*> * );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&ConnectionMenager::possibleContacts)) {
                *result = 4;
                return;
            }
        }
        {
            typedef void (ConnectionMenager::*_t)(Group * );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&ConnectionMenager::addChat)) {
                *result = 5;
                return;
            }
        }
        {
            typedef void (ConnectionMenager::*_t)(Group * );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&ConnectionMenager::addGroupChat)) {
                *result = 6;
                return;
            }
        }
        {
            typedef void (ConnectionMenager::*_t)(Message * , quint32 );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&ConnectionMenager::addMessageToGroup)) {
                *result = 7;
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
        if (_id < 8)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 8;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 8)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 8;
    }
    return _id;
}

// SIGNAL 0
void ConnectionMenager::logged()
{
    QMetaObject::activate(this, &staticMetaObject, 0, Q_NULLPTR);
}

// SIGNAL 1
void ConnectionMenager::notLogged()
{
    QMetaObject::activate(this, &staticMetaObject, 1, Q_NULLPTR);
}

// SIGNAL 2
void ConnectionMenager::registered()
{
    QMetaObject::activate(this, &staticMetaObject, 2, Q_NULLPTR);
}

// SIGNAL 3
void ConnectionMenager::notRegistered()
{
    QMetaObject::activate(this, &staticMetaObject, 3, Q_NULLPTR);
}

// SIGNAL 4
void ConnectionMenager::possibleContacts(QList<User*> * _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void ConnectionMenager::addChat(Group * _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}

// SIGNAL 6
void ConnectionMenager::addGroupChat(Group * _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 6, _a);
}

// SIGNAL 7
void ConnectionMenager::addMessageToGroup(Message * _t1, quint32 _t2)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 7, _a);
}
QT_END_MOC_NAMESPACE
