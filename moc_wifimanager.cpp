/****************************************************************************
** Meta object code from reading C++ file 'wifimanager.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "wifimanager.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'wifimanager.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_wifiManager_t {
    QByteArrayData data[18];
    char stringdata0[177];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_wifiManager_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_wifiManager_t qt_meta_stringdata_wifiManager = {
    {
QT_MOC_LITERAL(0, 0, 11), // "wifiManager"
QT_MOC_LITERAL(1, 12, 7), // "putWifi"
QT_MOC_LITERAL(2, 20, 0), // ""
QT_MOC_LITERAL(3, 21, 4), // "ssid"
QT_MOC_LITERAL(4, 26, 7), // "wsignal"
QT_MOC_LITERAL(5, 34, 4), // "wsec"
QT_MOC_LITERAL(6, 39, 6), // "lindex"
QT_MOC_LITERAL(7, 46, 7), // "lstatus"
QT_MOC_LITERAL(8, 54, 13), // "clearWifiList"
QT_MOC_LITERAL(9, 68, 13), // "connectedWifi"
QT_MOC_LITERAL(10, 82, 6), // "status"
QT_MOC_LITERAL(11, 89, 19), // "updateConnectedWifi"
QT_MOC_LITERAL(12, 109, 7), // "lsignal"
QT_MOC_LITERAL(13, 117, 11), // "getWifiList"
QT_MOC_LITERAL(14, 129, 3), // "chk"
QT_MOC_LITERAL(15, 133, 11), // "connectWifi"
QT_MOC_LITERAL(16, 145, 8), // "password"
QT_MOC_LITERAL(17, 154, 22) // "startConnectedWifiInfo"

    },
    "wifiManager\0putWifi\0\0ssid\0wsignal\0"
    "wsec\0lindex\0lstatus\0clearWifiList\0"
    "connectedWifi\0status\0updateConnectedWifi\0"
    "lsignal\0getWifiList\0chk\0connectWifi\0"
    "password\0startConnectedWifiInfo"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_wifiManager[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       4,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    5,   54,    2, 0x06 /* Public */,
       8,    0,   65,    2, 0x06 /* Public */,
       9,    1,   66,    2, 0x06 /* Public */,
      11,    2,   69,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      13,    0,   74,    2, 0x0a /* Public */,
      14,    0,   75,    2, 0x0a /* Public */,
      15,    2,   76,    2, 0x0a /* Public */,
      17,    0,   81,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::Int, QMetaType::QString,    3,    4,    5,    6,    7,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,   10,
    QMetaType::Void, QMetaType::Int, QMetaType::QString,   12,    7,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString, QMetaType::QString,    3,   16,
    QMetaType::Void,

       0        // eod
};

void wifiManager::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<wifiManager *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->putWifi((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< QString(*)>(_a[3])),(*reinterpret_cast< int(*)>(_a[4])),(*reinterpret_cast< QString(*)>(_a[5]))); break;
        case 1: _t->clearWifiList(); break;
        case 2: _t->connectedWifi((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 3: _t->updateConnectedWifi((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 4: _t->getWifiList(); break;
        case 5: _t->chk(); break;
        case 6: _t->connectWifi((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 7: _t->startConnectedWifiInfo(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (wifiManager::*)(QString , QString , QString , int , QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&wifiManager::putWifi)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (wifiManager::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&wifiManager::clearWifiList)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (wifiManager::*)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&wifiManager::connectedWifi)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (wifiManager::*)(int , QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&wifiManager::updateConnectedWifi)) {
                *result = 3;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject wifiManager::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_wifiManager.data,
    qt_meta_data_wifiManager,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *wifiManager::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *wifiManager::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_wifiManager.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int wifiManager::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
void wifiManager::putWifi(QString _t1, QString _t2, QString _t3, int _t4, QString _t5)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t3))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t4))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t5))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void wifiManager::clearWifiList()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void wifiManager::connectedWifi(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void wifiManager::updateConnectedWifi(int _t1, QString _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
