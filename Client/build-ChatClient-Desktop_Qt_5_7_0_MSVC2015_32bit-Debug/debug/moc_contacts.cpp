/****************************************************************************
** Meta object code from reading C++ file 'contacts.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.7.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../ChatClient/contacts.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#include <QtCore/QList>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'contacts.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.7.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_Contacts_t {
    QByteArrayData data[18];
    char stringdata0[285];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Contacts_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Contacts_t qt_meta_stringdata_Contacts = {
    {
QT_MOC_LITERAL(0, 0, 8), // "Contacts"
QT_MOC_LITERAL(1, 9, 10), // "addContact"
QT_MOC_LITERAL(2, 20, 0), // ""
QT_MOC_LITERAL(3, 21, 13), // "removeContact"
QT_MOC_LITERAL(4, 35, 5), // "index"
QT_MOC_LITERAL(5, 41, 11), // "createGroup"
QT_MOC_LITERAL(6, 53, 15), // "QList<quint16>*"
QT_MOC_LITERAL(7, 69, 7), // "indexes"
QT_MOC_LITERAL(8, 77, 10), // "leaveGroup"
QT_MOC_LITERAL(9, 88, 20), // "chatSelectionChanged"
QT_MOC_LITERAL(10, 109, 25), // "groupChatSelectionChanged"
QT_MOC_LITERAL(11, 135, 14), // "QItemSelection"
QT_MOC_LITERAL(12, 150, 9), // "selection"
QT_MOC_LITERAL(13, 160, 24), // "on_pushButton_17_clicked"
QT_MOC_LITERAL(14, 185, 24), // "on_pushButton_18_clicked"
QT_MOC_LITERAL(15, 210, 24), // "on_pushButton_19_clicked"
QT_MOC_LITERAL(16, 235, 24), // "on_pushButton_20_clicked"
QT_MOC_LITERAL(17, 260, 24) // "on_pushButton_23_clicked"

    },
    "Contacts\0addContact\0\0removeContact\0"
    "index\0createGroup\0QList<quint16>*\0"
    "indexes\0leaveGroup\0chatSelectionChanged\0"
    "groupChatSelectionChanged\0QItemSelection\0"
    "selection\0on_pushButton_17_clicked\0"
    "on_pushButton_18_clicked\0"
    "on_pushButton_19_clicked\0"
    "on_pushButton_20_clicked\0"
    "on_pushButton_23_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Contacts[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      11,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       4,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   69,    2, 0x06 /* Public */,
       3,    1,   70,    2, 0x06 /* Public */,
       5,    1,   73,    2, 0x06 /* Public */,
       8,    1,   76,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       9,    0,   79,    2, 0x08 /* Private */,
      10,    1,   80,    2, 0x08 /* Private */,
      13,    0,   83,    2, 0x08 /* Private */,
      14,    0,   84,    2, 0x08 /* Private */,
      15,    0,   85,    2, 0x08 /* Private */,
      16,    0,   86,    2, 0x08 /* Private */,
      17,    0,   87,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::UShort,    4,
    QMetaType::Void, 0x80000000 | 6,    7,
    QMetaType::Void, QMetaType::UShort,    4,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 11,   12,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void Contacts::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Contacts *_t = static_cast<Contacts *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->addContact(); break;
        case 1: _t->removeContact((*reinterpret_cast< quint16(*)>(_a[1]))); break;
        case 2: _t->createGroup((*reinterpret_cast< QList<quint16>*(*)>(_a[1]))); break;
        case 3: _t->leaveGroup((*reinterpret_cast< quint16(*)>(_a[1]))); break;
        case 4: _t->chatSelectionChanged(); break;
        case 5: _t->groupChatSelectionChanged((*reinterpret_cast< const QItemSelection(*)>(_a[1]))); break;
        case 6: _t->on_pushButton_17_clicked(); break;
        case 7: _t->on_pushButton_18_clicked(); break;
        case 8: _t->on_pushButton_19_clicked(); break;
        case 9: _t->on_pushButton_20_clicked(); break;
        case 10: _t->on_pushButton_23_clicked(); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 5:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QItemSelection >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (Contacts::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Contacts::addContact)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (Contacts::*_t)(quint16 );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Contacts::removeContact)) {
                *result = 1;
                return;
            }
        }
        {
            typedef void (Contacts::*_t)(QList<quint16> * );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Contacts::createGroup)) {
                *result = 2;
                return;
            }
        }
        {
            typedef void (Contacts::*_t)(quint16 );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Contacts::leaveGroup)) {
                *result = 3;
                return;
            }
        }
    }
}

const QMetaObject Contacts::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_Contacts.data,
      qt_meta_data_Contacts,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *Contacts::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Contacts::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_Contacts.stringdata0))
        return static_cast<void*>(const_cast< Contacts*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int Contacts::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
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

// SIGNAL 0
void Contacts::addContact()
{
    QMetaObject::activate(this, &staticMetaObject, 0, Q_NULLPTR);
}

// SIGNAL 1
void Contacts::removeContact(quint16 _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void Contacts::createGroup(QList<quint16> * _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void Contacts::leaveGroup(quint16 _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}
QT_END_MOC_NAMESPACE
