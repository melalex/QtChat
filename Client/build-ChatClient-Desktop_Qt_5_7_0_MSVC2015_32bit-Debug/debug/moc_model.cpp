/****************************************************************************
** Meta object code from reading C++ file 'model.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.7.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../ChatClient/model.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#include <QtCore/QList>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'model.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.7.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_Model_t {
    QByteArrayData data[24];
    char stringdata0[222];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Model_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Model_t qt_meta_stringdata_Model = {
    {
QT_MOC_LITERAL(0, 0, 5), // "Model"
QT_MOC_LITERAL(1, 6, 9), // "chatAdded"
QT_MOC_LITERAL(2, 16, 0), // ""
QT_MOC_LITERAL(3, 17, 6), // "Group*"
QT_MOC_LITERAL(4, 24, 4), // "chat"
QT_MOC_LITERAL(5, 29, 14), // "groupChatAdded"
QT_MOC_LITERAL(6, 44, 11), // "chatRemoved"
QT_MOC_LITERAL(7, 56, 5), // "index"
QT_MOC_LITERAL(8, 62, 16), // "groupChatRemoved"
QT_MOC_LITERAL(9, 79, 7), // "addUser"
QT_MOC_LITERAL(10, 87, 2), // "id"
QT_MOC_LITERAL(11, 90, 5), // "login"
QT_MOC_LITERAL(12, 96, 7), // "addChat"
QT_MOC_LITERAL(13, 104, 7), // "groupId"
QT_MOC_LITERAL(14, 112, 14), // "interlocutorId"
QT_MOC_LITERAL(15, 127, 16), // "interlocutorName"
QT_MOC_LITERAL(16, 144, 12), // "addGroupChat"
QT_MOC_LITERAL(17, 157, 4), // "name"
QT_MOC_LITERAL(18, 162, 14), // "QList<quint32>"
QT_MOC_LITERAL(19, 177, 7), // "members"
QT_MOC_LITERAL(20, 185, 17), // "addMessageToGroup"
QT_MOC_LITERAL(21, 203, 8), // "senderId"
QT_MOC_LITERAL(22, 212, 4), // "time"
QT_MOC_LITERAL(23, 217, 4) // "text"

    },
    "Model\0chatAdded\0\0Group*\0chat\0"
    "groupChatAdded\0chatRemoved\0index\0"
    "groupChatRemoved\0addUser\0id\0login\0"
    "addChat\0groupId\0interlocutorId\0"
    "interlocutorName\0addGroupChat\0name\0"
    "QList<quint32>\0members\0addMessageToGroup\0"
    "senderId\0time\0text"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Model[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       4,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   54,    2, 0x06 /* Public */,
       5,    1,   57,    2, 0x06 /* Public */,
       6,    1,   60,    2, 0x06 /* Public */,
       8,    1,   63,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       9,    2,   66,    2, 0x0a /* Public */,
      12,    3,   71,    2, 0x0a /* Public */,
      16,    3,   78,    2, 0x0a /* Public */,
      20,    4,   85,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, QMetaType::UShort,    7,
    QMetaType::Void, QMetaType::UShort,    7,

 // slots: parameters
    QMetaType::Void, QMetaType::UInt, QMetaType::QString,   10,   11,
    QMetaType::Void, QMetaType::UInt, QMetaType::UInt, QMetaType::QString,   13,   14,   15,
    QMetaType::Void, QMetaType::UInt, QMetaType::QString, 0x80000000 | 18,   13,   17,   19,
    QMetaType::Void, QMetaType::UInt, QMetaType::UInt, QMetaType::ULongLong, QMetaType::QString,   21,   13,   22,   23,

       0        // eod
};

void Model::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Model *_t = static_cast<Model *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->chatAdded((*reinterpret_cast< Group*(*)>(_a[1]))); break;
        case 1: _t->groupChatAdded((*reinterpret_cast< Group*(*)>(_a[1]))); break;
        case 2: _t->chatRemoved((*reinterpret_cast< quint16(*)>(_a[1]))); break;
        case 3: _t->groupChatRemoved((*reinterpret_cast< quint16(*)>(_a[1]))); break;
        case 4: _t->addUser((*reinterpret_cast< quint32(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 5: _t->addChat((*reinterpret_cast< quint32(*)>(_a[1])),(*reinterpret_cast< quint32(*)>(_a[2])),(*reinterpret_cast< QString(*)>(_a[3]))); break;
        case 6: _t->addGroupChat((*reinterpret_cast< quint32(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< const QList<quint32>(*)>(_a[3]))); break;
        case 7: _t->addMessageToGroup((*reinterpret_cast< quint32(*)>(_a[1])),(*reinterpret_cast< quint32(*)>(_a[2])),(*reinterpret_cast< quint64(*)>(_a[3])),(*reinterpret_cast< QString(*)>(_a[4]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 6:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 2:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QList<quint32> >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (Model::*_t)(Group * );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Model::chatAdded)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (Model::*_t)(Group * );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Model::groupChatAdded)) {
                *result = 1;
                return;
            }
        }
        {
            typedef void (Model::*_t)(quint16 );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Model::chatRemoved)) {
                *result = 2;
                return;
            }
        }
        {
            typedef void (Model::*_t)(quint16 );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Model::groupChatRemoved)) {
                *result = 3;
                return;
            }
        }
    }
}

const QMetaObject Model::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_Model.data,
      qt_meta_data_Model,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *Model::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Model::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_Model.stringdata0))
        return static_cast<void*>(const_cast< Model*>(this));
    return QObject::qt_metacast(_clname);
}

int Model::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
            qt_static_metacall(this, _c, _id, _a);
        _id -= 8;
    }
    return _id;
}

// SIGNAL 0
void Model::chatAdded(Group * _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void Model::groupChatAdded(Group * _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void Model::chatRemoved(quint16 _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void Model::groupChatRemoved(quint16 _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}
QT_END_MOC_NAMESPACE
