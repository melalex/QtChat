/****************************************************************************
** Meta object code from reading C++ file 'contactspresenter.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.7.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../ChatClient/contactspresenter.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#include <QtCore/QList>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'contactspresenter.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.7.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_ContactsPresenter_t {
    QByteArrayData data[13];
    char stringdata0[147];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_ContactsPresenter_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_ContactsPresenter_t qt_meta_stringdata_ContactsPresenter = {
    {
QT_MOC_LITERAL(0, 0, 17), // "ContactsPresenter"
QT_MOC_LITERAL(1, 18, 14), // "connectionFail"
QT_MOC_LITERAL(2, 33, 0), // ""
QT_MOC_LITERAL(3, 34, 11), // "socketError"
QT_MOC_LITERAL(4, 46, 10), // "addContact"
QT_MOC_LITERAL(5, 57, 13), // "removeContact"
QT_MOC_LITERAL(6, 71, 5), // "index"
QT_MOC_LITERAL(7, 77, 11), // "createGroup"
QT_MOC_LITERAL(8, 89, 15), // "QList<quint16>*"
QT_MOC_LITERAL(9, 105, 7), // "indexes"
QT_MOC_LITERAL(10, 113, 10), // "leaveGroup"
QT_MOC_LITERAL(11, 124, 8), // "openChat"
QT_MOC_LITERAL(12, 133, 13) // "openGroupChat"

    },
    "ContactsPresenter\0connectionFail\0\0"
    "socketError\0addContact\0removeContact\0"
    "index\0createGroup\0QList<quint16>*\0"
    "indexes\0leaveGroup\0openChat\0openGroupChat"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ContactsPresenter[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   49,    2, 0x0a /* Public */,
       4,    0,   52,    2, 0x0a /* Public */,
       5,    1,   53,    2, 0x0a /* Public */,
       7,    1,   56,    2, 0x0a /* Public */,
      10,    1,   59,    2, 0x0a /* Public */,
      11,    1,   62,    2, 0x0a /* Public */,
      12,    1,   65,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void,
    QMetaType::Void, QMetaType::UShort,    6,
    QMetaType::Void, 0x80000000 | 8,    9,
    QMetaType::Void, QMetaType::UShort,    6,
    QMetaType::Void, QMetaType::UShort,    6,
    QMetaType::Void, QMetaType::UShort,    6,

       0        // eod
};

void ContactsPresenter::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        ContactsPresenter *_t = static_cast<ContactsPresenter *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->connectionFail((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 1: _t->addContact(); break;
        case 2: _t->removeContact((*reinterpret_cast< quint16(*)>(_a[1]))); break;
        case 3: _t->createGroup((*reinterpret_cast< QList<quint16>*(*)>(_a[1]))); break;
        case 4: _t->leaveGroup((*reinterpret_cast< quint16(*)>(_a[1]))); break;
        case 5: _t->openChat((*reinterpret_cast< quint16(*)>(_a[1]))); break;
        case 6: _t->openGroupChat((*reinterpret_cast< quint16(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObject ContactsPresenter::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_ContactsPresenter.data,
      qt_meta_data_ContactsPresenter,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *ContactsPresenter::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ContactsPresenter::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_ContactsPresenter.stringdata0))
        return static_cast<void*>(const_cast< ContactsPresenter*>(this));
    return QObject::qt_metacast(_clname);
}

int ContactsPresenter::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 7)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 7;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
