/****************************************************************************
** Meta object code from reading C++ file 'uqqclient.h'
**
** Created: Fri Mar 22 19:54:05 2013
**      by: The Qt Meta Object Compiler version 67 (Qt 5.0.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../uqqclient.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'uqqclient.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.0.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_UQQClient_t {
    QByteArrayData data[29];
    char stringdata[299];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    offsetof(qt_meta_stringdata_UQQClient_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData) \
    )
static const qt_meta_stringdata_UQQClient_t qt_meta_stringdata_UQQClient = {
    {
QT_MOC_LITERAL(0, 0, 9),
QT_MOC_LITERAL(1, 10, 12),
QT_MOC_LITERAL(2, 23, 0),
QT_MOC_LITERAL(3, 24, 7),
QT_MOC_LITERAL(4, 32, 14),
QT_MOC_LITERAL(5, 47, 6),
QT_MOC_LITERAL(6, 54, 12),
QT_MOC_LITERAL(7, 67, 15),
QT_MOC_LITERAL(8, 83, 4),
QT_MOC_LITERAL(9, 88, 15),
QT_MOC_LITERAL(10, 104, 4),
QT_MOC_LITERAL(11, 109, 16),
QT_MOC_LITERAL(12, 126, 17),
QT_MOC_LITERAL(13, 144, 13),
QT_MOC_LITERAL(14, 158, 10),
QT_MOC_LITERAL(15, 169, 14),
QT_MOC_LITERAL(16, 184, 5),
QT_MOC_LITERAL(17, 190, 12),
QT_MOC_LITERAL(18, 203, 3),
QT_MOC_LITERAL(19, 207, 11),
QT_MOC_LITERAL(20, 219, 9),
QT_MOC_LITERAL(21, 229, 3),
QT_MOC_LITERAL(22, 233, 5),
QT_MOC_LITERAL(23, 239, 3),
QT_MOC_LITERAL(24, 243, 2),
QT_MOC_LITERAL(25, 246, 12),
QT_MOC_LITERAL(26, 259, 11),
QT_MOC_LITERAL(27, 271, 20),
QT_MOC_LITERAL(28, 292, 5)
    },
    "UQQClient\0errorChanged\0\0errCode\0"
    "captchaChanged\0needed\0loginSuccess\0"
    "userFaceChanged\0face\0longNickChanged\0"
    "json\0userLevelChanged\0userDetailChanged\0"
    "categoryReady\0onFinished\0QNetworkReply*\0"
    "reply\0getLoginInfo\0key\0getUserInfo\0"
    "checkCode\0uin\0login\0pwd\0vc\0loadUserInfo\0"
    "loadContact\0getFriendsInCategory\0index\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_UQQClient[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      16,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       8,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   94,    2, 0x05,
       4,    1,   97,    2, 0x05,
       6,    0,  100,    2, 0x05,
       7,    1,  101,    2, 0x05,
       9,    1,  104,    2, 0x05,
      11,    1,  107,    2, 0x05,
      12,    1,  110,    2, 0x05,
      13,    1,  113,    2, 0x05,

 // slots: name, argc, parameters, tag, flags
      14,    1,  116,    2, 0x0a,

 // methods: name, argc, parameters, tag, flags
      17,    1,  119,    2, 0x02,
      19,    1,  122,    2, 0x02,
      20,    1,  125,    2, 0x02,
      22,    3,  128,    2, 0x02,
      25,    0,  135,    2, 0x02,
      26,    0,  136,    2, 0x02,
      27,    1,  137,    2, 0x02,

 // signals: parameters
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, QMetaType::Bool,    5,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    8,
    QMetaType::Void, QMetaType::QString,   10,
    QMetaType::Void, QMetaType::QString,   10,
    QMetaType::Void, QMetaType::QString,   10,
    QMetaType::Void, QMetaType::QString,   10,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 15,   16,

 // methods: parameters
    QMetaType::QVariant, QMetaType::QString,   18,
    QMetaType::QVariant, QMetaType::QString,   18,
    QMetaType::Void, QMetaType::QString,   21,
    QMetaType::Void, QMetaType::QString, QMetaType::QString, QMetaType::QString,   21,   23,   24,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::QString, QMetaType::Int,   28,

       0        // eod
};

void UQQClient::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        UQQClient *_t = static_cast<UQQClient *>(_o);
        switch (_id) {
        case 0: _t->errorChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->captchaChanged((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 2: _t->loginSuccess(); break;
        case 3: _t->userFaceChanged((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 4: _t->longNickChanged((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 5: _t->userLevelChanged((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 6: _t->userDetailChanged((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 7: _t->categoryReady((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 8: _t->onFinished((*reinterpret_cast< QNetworkReply*(*)>(_a[1]))); break;
        case 9: { QVariant _r = _t->getLoginInfo((*reinterpret_cast< const QString(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QVariant*>(_a[0]) = _r; }  break;
        case 10: { QVariant _r = _t->getUserInfo((*reinterpret_cast< const QString(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QVariant*>(_a[0]) = _r; }  break;
        case 11: _t->checkCode((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 12: _t->login((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< QString(*)>(_a[3]))); break;
        case 13: _t->loadUserInfo(); break;
        case 14: _t->loadContact(); break;
        case 15: { QString _r = _t->getFriendsInCategory((*reinterpret_cast< int(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = _r; }  break;
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
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (UQQClient::*_t)(int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&UQQClient::errorChanged)) {
                *result = 0;
            }
        }
        {
            typedef void (UQQClient::*_t)(bool );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&UQQClient::captchaChanged)) {
                *result = 1;
            }
        }
        {
            typedef void (UQQClient::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&UQQClient::loginSuccess)) {
                *result = 2;
            }
        }
        {
            typedef void (UQQClient::*_t)(QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&UQQClient::userFaceChanged)) {
                *result = 3;
            }
        }
        {
            typedef void (UQQClient::*_t)(QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&UQQClient::longNickChanged)) {
                *result = 4;
            }
        }
        {
            typedef void (UQQClient::*_t)(QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&UQQClient::userLevelChanged)) {
                *result = 5;
            }
        }
        {
            typedef void (UQQClient::*_t)(QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&UQQClient::userDetailChanged)) {
                *result = 6;
            }
        }
        {
            typedef void (UQQClient::*_t)(QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&UQQClient::categoryReady)) {
                *result = 7;
            }
        }
    }
}

const QMetaObject UQQClient::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_UQQClient.data,
      qt_meta_data_UQQClient,  qt_static_metacall, 0, 0}
};


const QMetaObject *UQQClient::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *UQQClient::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_UQQClient.stringdata))
        return static_cast<void*>(const_cast< UQQClient*>(this));
    return QObject::qt_metacast(_clname);
}

int UQQClient::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 16)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 16;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 16)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 16;
    }
    return _id;
}

// SIGNAL 0
void UQQClient::errorChanged(int _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void UQQClient::captchaChanged(bool _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void UQQClient::loginSuccess()
{
    QMetaObject::activate(this, &staticMetaObject, 2, 0);
}

// SIGNAL 3
void UQQClient::userFaceChanged(QString _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void UQQClient::longNickChanged(QString _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void UQQClient::userLevelChanged(QString _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}

// SIGNAL 6
void UQQClient::userDetailChanged(QString _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 6, _a);
}

// SIGNAL 7
void UQQClient::categoryReady(QString _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 7, _a);
}
QT_END_MOC_NAMESPACE