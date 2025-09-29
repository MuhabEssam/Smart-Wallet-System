/****************************************************************************
** Meta object code from reading C++ file 'client.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.2.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "client.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'client.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.2.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_client_t {
    const uint offsetsAndSize[28];
    char stringdata0[196];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(offsetof(qt_meta_stringdata_client_t, stringdata0) + ofs), len 
static const qt_meta_stringdata_client_t qt_meta_stringdata_client = {
    {
QT_MOC_LITERAL(0, 6), // "client"
QT_MOC_LITERAL(7, 8), // "sendData"
QT_MOC_LITERAL(16, 0), // ""
QT_MOC_LITERAL(17, 4), // "data"
QT_MOC_LITERAL(22, 14), // "readFromServer"
QT_MOC_LITERAL(37, 22), // "on_get_balance_clicked"
QT_MOC_LITERAL(60, 18), // "on_Deposit_clicked"
QT_MOC_LITERAL(79, 19), // "on_Withdraw_clicked"
QT_MOC_LITERAL(99, 27), // "on_get_transactions_clicked"
QT_MOC_LITERAL(127, 21), // "on_Undo_trans_clicked"
QT_MOC_LITERAL(149, 13), // "getClientInfo"
QT_MOC_LITERAL(163, 14), // "vector<string>"
QT_MOC_LITERAL(178, 4), // "info"
QT_MOC_LITERAL(183, 12) // "CloseSockcet"

    },
    "client\0sendData\0\0data\0readFromServer\0"
    "on_get_balance_clicked\0on_Deposit_clicked\0"
    "on_Withdraw_clicked\0on_get_transactions_clicked\0"
    "on_Undo_trans_clicked\0getClientInfo\0"
    "vector<string>\0info\0CloseSockcet"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_client[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       1,    1,   68,    2, 0x08,    1 /* Private */,
       4,    0,   71,    2, 0x08,    3 /* Private */,
       5,    0,   72,    2, 0x08,    4 /* Private */,
       6,    0,   73,    2, 0x08,    5 /* Private */,
       7,    0,   74,    2, 0x08,    6 /* Private */,
       8,    0,   75,    2, 0x08,    7 /* Private */,
       9,    0,   76,    2, 0x08,    8 /* Private */,
      10,    1,   77,    2, 0x08,    9 /* Private */,
      13,    0,   80,    2, 0x08,   11 /* Private */,

 // slots: parameters
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    0x80000000 | 11, QMetaType::QString,   12,
    QMetaType::Void,

       0        // eod
};

void client::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<client *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->sendData((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 1: _t->readFromServer(); break;
        case 2: _t->on_get_balance_clicked(); break;
        case 3: _t->on_Deposit_clicked(); break;
        case 4: _t->on_Withdraw_clicked(); break;
        case 5: _t->on_get_transactions_clicked(); break;
        case 6: _t->on_Undo_trans_clicked(); break;
        case 7: { vector<string> _r = _t->getClientInfo((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])));
            if (_a[0]) *reinterpret_cast< vector<string>*>(_a[0]) = std::move(_r); }  break;
        case 8: _t->CloseSockcet(); break;
        default: ;
        }
    }
}

const QMetaObject client::staticMetaObject = { {
    QMetaObject::SuperData::link<QDialog::staticMetaObject>(),
    qt_meta_stringdata_client.offsetsAndSize,
    qt_meta_data_client,
    qt_static_metacall,
    nullptr,
qt_incomplete_metaTypeArray<qt_meta_stringdata_client_t
, QtPrivate::TypeAndForceComplete<client, std::true_type>
, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QString, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<vector<string>, std::false_type>, QtPrivate::TypeAndForceComplete<QString, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>


>,
    nullptr
} };


const QMetaObject *client::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *client::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_client.stringdata0))
        return static_cast<void*>(this);
    return QDialog::qt_metacast(_clname);
}

int client::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 9)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 9;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 9)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 9;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
