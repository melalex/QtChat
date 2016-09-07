/****************************************************************************
** Meta object code from reading C++ file 'registrationpresenter.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.7.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../ChatClient/registrationpresenter.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'registrationpresenter.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.7.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_RegistrationPresenter_t {
    QByteArrayData data[6];
    char stringdata0[71];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_RegistrationPresenter_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_RegistrationPresenter_t qt_meta_stringdata_RegistrationPresenter = {
    {
QT_MOC_LITERAL(0, 0, 21), // "RegistrationPresenter"
QT_MOC_LITERAL(1, 22, 16), // "registerANewUser"
QT_MOC_LITERAL(2, 39, 0), // ""
QT_MOC_LITERAL(3, 40, 5), // "login"
QT_MOC_LITERAL(4, 46, 8), // "password"
QT_MOC_LITERAL(5, 55, 15) // "confirmPassword"

    },
    "RegistrationPresenter\0registerANewUser\0"
    "\0login\0password\0confirmPassword"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_RegistrationPresenter[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       1,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    3,   19,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void, QMetaType::QString, QMetaType::QString, QMetaType::QString,    3,    4,    5,

       0        // eod
};

void RegistrationPresenter::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        RegistrationPresenter *_t = static_cast<RegistrationPresenter *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->registerANewUser((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< QString(*)>(_a[3]))); break;
        default: ;
        }
    }
}

const QMetaObject RegistrationPresenter::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_RegistrationPresenter.data,
      qt_meta_data_RegistrationPresenter,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *RegistrationPresenter::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *RegistrationPresenter::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_RegistrationPresenter.stringdata0))
        return static_cast<void*>(const_cast< RegistrationPresenter*>(this));
    return QObject::qt_metacast(_clname);
}

int RegistrationPresenter::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 1)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 1;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 1)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 1;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
