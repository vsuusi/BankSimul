/****************************************************************************
** Meta object code from reading C++ file 'apidll.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../apidll.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'apidll.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_ApiDLL_t {
    QByteArrayData data[13];
    char stringdata0[150];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_ApiDLL_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_ApiDLL_t qt_meta_stringdata_ApiDLL = {
    {
QT_MOC_LITERAL(0, 0, 6), // "ApiDLL"
QT_MOC_LITERAL(1, 7, 9), // "sendToExe"
QT_MOC_LITERAL(2, 17, 0), // ""
QT_MOC_LITERAL(3, 18, 14), // "sendTokenToExe"
QT_MOC_LITERAL(4, 33, 13), // "QuitEventLoop"
QT_MOC_LITERAL(5, 47, 8), // "recvTili"
QT_MOC_LITERAL(6, 56, 16), // "recvTili_Asiakas"
QT_MOC_LITERAL(7, 73, 11), // "recvAsiakas"
QT_MOC_LITERAL(8, 85, 10), // "recvKortti"
QT_MOC_LITERAL(9, 96, 18), // "recvTilitapahtumat"
QT_MOC_LITERAL(10, 115, 13), // "recvLoginSlot"
QT_MOC_LITERAL(11, 129, 14), // "QNetworkReply*"
QT_MOC_LITERAL(12, 144, 5) // "reply"

    },
    "ApiDLL\0sendToExe\0\0sendTokenToExe\0"
    "QuitEventLoop\0recvTili\0recvTili_Asiakas\0"
    "recvAsiakas\0recvKortti\0recvTilitapahtumat\0"
    "recvLoginSlot\0QNetworkReply*\0reply"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ApiDLL[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   59,    2, 0x06 /* Public */,
       3,    1,   62,    2, 0x06 /* Public */,
       4,    0,   65,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       5,    1,   66,    2, 0x0a /* Public */,
       6,    1,   69,    2, 0x0a /* Public */,
       7,    1,   72,    2, 0x0a /* Public */,
       8,    1,   75,    2, 0x0a /* Public */,
       9,    1,   78,    2, 0x0a /* Public */,
      10,    1,   81,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void, QMetaType::QByteArray,    2,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void, 0x80000000 | 11,   12,

       0        // eod
};

void ApiDLL::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<ApiDLL *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->sendToExe((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 1: _t->sendTokenToExe((*reinterpret_cast< QByteArray(*)>(_a[1]))); break;
        case 2: _t->QuitEventLoop(); break;
        case 3: _t->recvTili((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 4: _t->recvTili_Asiakas((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 5: _t->recvAsiakas((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 6: _t->recvKortti((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 7: _t->recvTilitapahtumat((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 8: _t->recvLoginSlot((*reinterpret_cast< QNetworkReply*(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 8:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QNetworkReply* >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (ApiDLL::*)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ApiDLL::sendToExe)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (ApiDLL::*)(QByteArray );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ApiDLL::sendTokenToExe)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (ApiDLL::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ApiDLL::QuitEventLoop)) {
                *result = 2;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject ApiDLL::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_ApiDLL.data,
    qt_meta_data_ApiDLL,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *ApiDLL::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ApiDLL::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_ApiDLL.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int ApiDLL::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 9)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 9;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 9)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 9;
    }
    return _id;
}

// SIGNAL 0
void ApiDLL::sendToExe(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void ApiDLL::sendTokenToExe(QByteArray _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void ApiDLL::QuitEventLoop()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE