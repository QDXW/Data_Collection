/****************************************************************************
** Meta object code from reading C++ file 'lanuage.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.6)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../lanuage.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'lanuage.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.6. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Lanuage_t {
    QByteArrayData data[9];
    char stringdata0[134];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Lanuage_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Lanuage_t qt_meta_stringdata_Lanuage = {
    {
QT_MOC_LITERAL(0, 0, 7), // "Lanuage"
QT_MOC_LITERAL(1, 8, 19), // "ChangeLanuageSingal"
QT_MOC_LITERAL(2, 28, 0), // ""
QT_MOC_LITERAL(3, 29, 21), // "ChangeInterfaceSingal"
QT_MOC_LITERAL(4, 51, 18), // "on_English_clicked"
QT_MOC_LITERAL(5, 70, 18), // "on_Chinese_clicked"
QT_MOC_LITERAL(6, 89, 17), // "on_German_clicked"
QT_MOC_LITERAL(7, 107, 19), // "on_Protugal_clicked"
QT_MOC_LITERAL(8, 127, 6) // "myslot"

    },
    "Lanuage\0ChangeLanuageSingal\0\0"
    "ChangeInterfaceSingal\0on_English_clicked\0"
    "on_Chinese_clicked\0on_German_clicked\0"
    "on_Protugal_clicked\0myslot"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Lanuage[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   49,    2, 0x06 /* Public */,
       3,    1,   52,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       4,    0,   55,    2, 0x08 /* Private */,
       5,    0,   56,    2, 0x08 /* Private */,
       6,    0,   57,    2, 0x08 /* Private */,
       7,    0,   58,    2, 0x08 /* Private */,
       8,    1,   59,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::UChar,    2,
    QMetaType::Void, QMetaType::UChar,    2,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::UChar,    2,

       0        // eod
};

void Lanuage::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Lanuage *_t = static_cast<Lanuage *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->ChangeLanuageSingal((*reinterpret_cast< quint8(*)>(_a[1]))); break;
        case 1: _t->ChangeInterfaceSingal((*reinterpret_cast< quint8(*)>(_a[1]))); break;
        case 2: _t->on_English_clicked(); break;
        case 3: _t->on_Chinese_clicked(); break;
        case 4: _t->on_German_clicked(); break;
        case 5: _t->on_Protugal_clicked(); break;
        case 6: _t->myslot((*reinterpret_cast< quint8(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            typedef void (Lanuage::*_t)(quint8 );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Lanuage::ChangeLanuageSingal)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (Lanuage::*_t)(quint8 );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Lanuage::ChangeInterfaceSingal)) {
                *result = 1;
                return;
            }
        }
    }
}

const QMetaObject Lanuage::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_Lanuage.data,
      qt_meta_data_Lanuage,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *Lanuage::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Lanuage::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Lanuage.stringdata0))
        return static_cast<void*>(this);
    return QDialog::qt_metacast(_clname);
}

int Lanuage::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
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

// SIGNAL 0
void Lanuage::ChangeLanuageSingal(quint8 _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void Lanuage::ChangeInterfaceSingal(quint8 _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
