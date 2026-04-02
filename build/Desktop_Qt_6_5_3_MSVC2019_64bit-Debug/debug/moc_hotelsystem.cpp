/****************************************************************************
** Meta object code from reading C++ file 'hotelsystem.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.5.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../hotelsystem.h"
#include <QtCore/qmetatype.h>

#if __has_include(<QtCore/qtmochelpers.h>)
#include <QtCore/qtmochelpers.h>
#else
QT_BEGIN_MOC_NAMESPACE
#endif


#include <memory>

#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'hotelsystem.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.5.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

#ifndef Q_CONSTINIT
#define Q_CONSTINIT
#endif

QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
QT_WARNING_DISABLE_GCC("-Wuseless-cast")
namespace {

#ifdef QT_MOC_HAS_STRINGDATA
struct qt_meta_stringdata_CLASSHotelSystemENDCLASS_t {};
static constexpr auto qt_meta_stringdata_CLASSHotelSystemENDCLASS = QtMocHelpers::stringData(
    "HotelSystem",
    "loginSuccess",
    "",
    "User*",
    "user",
    "loginFailed",
    "registrationSuccess",
    "registrationFailed"
);
#else  // !QT_MOC_HAS_STRING_DATA
struct qt_meta_stringdata_CLASSHotelSystemENDCLASS_t {
    uint offsetsAndSizes[16];
    char stringdata0[12];
    char stringdata1[13];
    char stringdata2[1];
    char stringdata3[6];
    char stringdata4[5];
    char stringdata5[12];
    char stringdata6[20];
    char stringdata7[19];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_CLASSHotelSystemENDCLASS_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_CLASSHotelSystemENDCLASS_t qt_meta_stringdata_CLASSHotelSystemENDCLASS = {
    {
        QT_MOC_LITERAL(0, 11),  // "HotelSystem"
        QT_MOC_LITERAL(12, 12),  // "loginSuccess"
        QT_MOC_LITERAL(25, 0),  // ""
        QT_MOC_LITERAL(26, 5),  // "User*"
        QT_MOC_LITERAL(32, 4),  // "user"
        QT_MOC_LITERAL(37, 11),  // "loginFailed"
        QT_MOC_LITERAL(49, 19),  // "registrationSuccess"
        QT_MOC_LITERAL(69, 18)   // "registrationFailed"
    },
    "HotelSystem",
    "loginSuccess",
    "",
    "User*",
    "user",
    "loginFailed",
    "registrationSuccess",
    "registrationFailed"
};
#undef QT_MOC_LITERAL
#endif // !QT_MOC_HAS_STRING_DATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSHotelSystemENDCLASS[] = {

 // content:
      11,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       4,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    1,   38,    2, 0x06,    1 /* Public */,
       5,    0,   41,    2, 0x06,    3 /* Public */,
       6,    0,   42,    2, 0x06,    4 /* Public */,
       7,    0,   43,    2, 0x06,    5 /* Public */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

Q_CONSTINIT const QMetaObject HotelSystem::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_CLASSHotelSystemENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASSHotelSystemENDCLASS,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_CLASSHotelSystemENDCLASS_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<HotelSystem, std::true_type>,
        // method 'loginSuccess'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<User *, std::false_type>,
        // method 'loginFailed'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'registrationSuccess'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'registrationFailed'
        QtPrivate::TypeAndForceComplete<void, std::false_type>
    >,
    nullptr
} };

void HotelSystem::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<HotelSystem *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->loginSuccess((*reinterpret_cast< std::add_pointer_t<User*>>(_a[1]))); break;
        case 1: _t->loginFailed(); break;
        case 2: _t->registrationSuccess(); break;
        case 3: _t->registrationFailed(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (HotelSystem::*)(User * );
            if (_t _q_method = &HotelSystem::loginSuccess; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (HotelSystem::*)();
            if (_t _q_method = &HotelSystem::loginFailed; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (HotelSystem::*)();
            if (_t _q_method = &HotelSystem::registrationSuccess; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (HotelSystem::*)();
            if (_t _q_method = &HotelSystem::registrationFailed; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 3;
                return;
            }
        }
    }
}

const QMetaObject *HotelSystem::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *HotelSystem::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CLASSHotelSystemENDCLASS.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int HotelSystem::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 4)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 4;
    }
    return _id;
}

// SIGNAL 0
void HotelSystem::loginSuccess(User * _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void HotelSystem::loginFailed()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void HotelSystem::registrationSuccess()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}

// SIGNAL 3
void HotelSystem::registrationFailed()
{
    QMetaObject::activate(this, &staticMetaObject, 3, nullptr);
}
QT_WARNING_POP
