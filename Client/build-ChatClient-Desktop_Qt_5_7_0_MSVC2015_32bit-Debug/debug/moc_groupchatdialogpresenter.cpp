/****************************************************************************
** Meta object code from reading C++ file 'groupchatdialogpresenter.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.7.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../ChatClient/groupchatdialogpresenter.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#include <QtCore/QList>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'groupchatdialogpresenter.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.7.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_GroupChatDialogPresenter_t {
    QByteArrayData data[8];
    char stringdata0[95];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_GroupChatDialogPresenter_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_GroupChatDialogPresenter_t qt_meta_stringdata_GroupChatDialogPresenter = {
    {
QT_MOC_LITERAL(0, 0, 24), // "GroupChatDialogPresenter"
QT_MOC_LITERAL(1, 25, 10), // "setMembers"
QT_MOC_LITERAL(2, 36, 0), // ""
QT_MOC_LITERAL(3, 37, 19), // "const QList<User*>*"
QT_MOC_LITERAL(4, 57, 7), // "members"
QT_MOC_LITERAL(5, 65, 12), // "messageAdded"
QT_MOC_LITERAL(6, 78, 8), // "Message*"
QT_MOC_LITERAL(7, 87, 7) // "message"

    },
    "GroupChatDialogPresenter\0setMembers\0"
    "\0const QList<User*>*\0members\0messageAdded\0"
    "Message*\0message"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_GroupChatDialogPresenter[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   29,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       5,    1,   32,    2, 0x0a /* Public */,
       5,    1,   35,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    4,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 6,    7,
    QMetaType::Void, QMetaType::QString,    7,

       0        // eod
};

void GroupChatDialogPresenter::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        GroupChatDialogPresenter *_t = static_cast<GroupChatDialogPresenter *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->setMembers((*reinterpret_cast< const QList<User*>*(*)>(_a[1]))); break;
        case 1: _t->messageAdded((*reinterpret_cast< Message*(*)>(_a[1]))); break;
        case 2: _t->messageAdded((*reinterpret_cast< QString(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (GroupChatDialogPresenter::*_t)(const QList<User*> * );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&GroupChatDialogPresenter::setMembers)) {
                *result = 0;
                return;
            }
        }
    }
}

const QMetaObject GroupChatDialogPresenter::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_GroupChatDialogPresenter.data,
      qt_meta_data_GroupChatDialogPresenter,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *GroupChatDialogPresenter::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *GroupChatDialogPresenter::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_GroupChatDialogPresenter.stringdata0))
        return static_cast<void*>(const_cast< GroupChatDialogPresenter*>(this));
    return QObject::qt_metacast(_clname);
}

int GroupChatDialogPresenter::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 3)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 3;
    }
    return _id;
}

// SIGNAL 0
void GroupChatDialogPresenter::setMembers(const QList<User*> * _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_END_MOC_NAMESPACE
