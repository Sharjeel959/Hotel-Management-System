/****************************************************************************
** Meta object code from reading C++ file 'webinterface.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.5.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../webinterface.h"
#include <QtCore/qmetatype.h>

#if __has_include(<QtCore/qtmochelpers.h>)
#include <QtCore/qtmochelpers.h>
#else
QT_BEGIN_MOC_NAMESPACE
#endif


#include <memory>

#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'webinterface.h' doesn't include <QObject>."
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
struct qt_meta_stringdata_CLASSWebInterfaceENDCLASS_t {};
static constexpr auto qt_meta_stringdata_CLASSWebInterfaceENDCLASS = QtMocHelpers::stringData(
    "WebInterface",
    "attemptLogin",
    "",
    "role",
    "username",
    "password",
    "attemptRegister",
    "name",
    "phone",
    "email",
    "position",
    "shift",
    "salary",
    "logout",
    "getCurrentUser",
    "getCurrentRole",
    "getAdminDashboardStats",
    "getAllRooms",
    "getAllBookings",
    "getAllStaff",
    "addRoom",
    "number",
    "type",
    "price",
    "addStaff",
    "toggleRoomStatus",
    "roomNumber",
    "updateCustomer",
    "updateStaff",
    "getReport",
    "getAvailableRooms",
    "bookRoom",
    "checkout",
    "getMyPaymentInfo",
    "makePayment",
    "submitFeedback",
    "comment",
    "rating",
    "getAllFeedback",
    "requestHousekeeping",
    "joinLoyalty",
    "getRefundInfo",
    "requestRefund"
);
#else  // !QT_MOC_HAS_STRING_DATA
struct qt_meta_stringdata_CLASSWebInterfaceENDCLASS_t {
    uint offsetsAndSizes[86];
    char stringdata0[13];
    char stringdata1[13];
    char stringdata2[1];
    char stringdata3[5];
    char stringdata4[9];
    char stringdata5[9];
    char stringdata6[16];
    char stringdata7[5];
    char stringdata8[6];
    char stringdata9[6];
    char stringdata10[9];
    char stringdata11[6];
    char stringdata12[7];
    char stringdata13[7];
    char stringdata14[15];
    char stringdata15[15];
    char stringdata16[23];
    char stringdata17[12];
    char stringdata18[15];
    char stringdata19[12];
    char stringdata20[8];
    char stringdata21[7];
    char stringdata22[5];
    char stringdata23[6];
    char stringdata24[9];
    char stringdata25[17];
    char stringdata26[11];
    char stringdata27[15];
    char stringdata28[12];
    char stringdata29[10];
    char stringdata30[18];
    char stringdata31[9];
    char stringdata32[9];
    char stringdata33[17];
    char stringdata34[12];
    char stringdata35[15];
    char stringdata36[8];
    char stringdata37[7];
    char stringdata38[15];
    char stringdata39[20];
    char stringdata40[12];
    char stringdata41[14];
    char stringdata42[14];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_CLASSWebInterfaceENDCLASS_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_CLASSWebInterfaceENDCLASS_t qt_meta_stringdata_CLASSWebInterfaceENDCLASS = {
    {
        QT_MOC_LITERAL(0, 12),  // "WebInterface"
        QT_MOC_LITERAL(13, 12),  // "attemptLogin"
        QT_MOC_LITERAL(26, 0),  // ""
        QT_MOC_LITERAL(27, 4),  // "role"
        QT_MOC_LITERAL(32, 8),  // "username"
        QT_MOC_LITERAL(41, 8),  // "password"
        QT_MOC_LITERAL(50, 15),  // "attemptRegister"
        QT_MOC_LITERAL(66, 4),  // "name"
        QT_MOC_LITERAL(71, 5),  // "phone"
        QT_MOC_LITERAL(77, 5),  // "email"
        QT_MOC_LITERAL(83, 8),  // "position"
        QT_MOC_LITERAL(92, 5),  // "shift"
        QT_MOC_LITERAL(98, 6),  // "salary"
        QT_MOC_LITERAL(105, 6),  // "logout"
        QT_MOC_LITERAL(112, 14),  // "getCurrentUser"
        QT_MOC_LITERAL(127, 14),  // "getCurrentRole"
        QT_MOC_LITERAL(142, 22),  // "getAdminDashboardStats"
        QT_MOC_LITERAL(165, 11),  // "getAllRooms"
        QT_MOC_LITERAL(177, 14),  // "getAllBookings"
        QT_MOC_LITERAL(192, 11),  // "getAllStaff"
        QT_MOC_LITERAL(204, 7),  // "addRoom"
        QT_MOC_LITERAL(212, 6),  // "number"
        QT_MOC_LITERAL(219, 4),  // "type"
        QT_MOC_LITERAL(224, 5),  // "price"
        QT_MOC_LITERAL(230, 8),  // "addStaff"
        QT_MOC_LITERAL(239, 16),  // "toggleRoomStatus"
        QT_MOC_LITERAL(256, 10),  // "roomNumber"
        QT_MOC_LITERAL(267, 14),  // "updateCustomer"
        QT_MOC_LITERAL(282, 11),  // "updateStaff"
        QT_MOC_LITERAL(294, 9),  // "getReport"
        QT_MOC_LITERAL(304, 17),  // "getAvailableRooms"
        QT_MOC_LITERAL(322, 8),  // "bookRoom"
        QT_MOC_LITERAL(331, 8),  // "checkout"
        QT_MOC_LITERAL(340, 16),  // "getMyPaymentInfo"
        QT_MOC_LITERAL(357, 11),  // "makePayment"
        QT_MOC_LITERAL(369, 14),  // "submitFeedback"
        QT_MOC_LITERAL(384, 7),  // "comment"
        QT_MOC_LITERAL(392, 6),  // "rating"
        QT_MOC_LITERAL(399, 14),  // "getAllFeedback"
        QT_MOC_LITERAL(414, 19),  // "requestHousekeeping"
        QT_MOC_LITERAL(434, 11),  // "joinLoyalty"
        QT_MOC_LITERAL(446, 13),  // "getRefundInfo"
        QT_MOC_LITERAL(460, 13)   // "requestRefund"
    },
    "WebInterface",
    "attemptLogin",
    "",
    "role",
    "username",
    "password",
    "attemptRegister",
    "name",
    "phone",
    "email",
    "position",
    "shift",
    "salary",
    "logout",
    "getCurrentUser",
    "getCurrentRole",
    "getAdminDashboardStats",
    "getAllRooms",
    "getAllBookings",
    "getAllStaff",
    "addRoom",
    "number",
    "type",
    "price",
    "addStaff",
    "toggleRoomStatus",
    "roomNumber",
    "updateCustomer",
    "updateStaff",
    "getReport",
    "getAvailableRooms",
    "bookRoom",
    "checkout",
    "getMyPaymentInfo",
    "makePayment",
    "submitFeedback",
    "comment",
    "rating",
    "getAllFeedback",
    "requestHousekeeping",
    "joinLoyalty",
    "getRefundInfo",
    "requestRefund"
};
#undef QT_MOC_LITERAL
#endif // !QT_MOC_HAS_STRING_DATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSWebInterfaceENDCLASS[] = {

 // content:
      11,       // revision
       0,       // classname
       0,    0, // classinfo
      26,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // methods: name, argc, parameters, tag, flags, initial metatype offsets
       1,    3,  170,    2, 0x02,    1 /* Public */,
       6,    9,  177,    2, 0x02,    5 /* Public */,
      13,    0,  196,    2, 0x02,   15 /* Public */,
      14,    0,  197,    2, 0x02,   16 /* Public */,
      15,    0,  198,    2, 0x02,   17 /* Public */,
      16,    0,  199,    2, 0x02,   18 /* Public */,
      17,    0,  200,    2, 0x02,   19 /* Public */,
      18,    0,  201,    2, 0x02,   20 /* Public */,
      19,    0,  202,    2, 0x02,   21 /* Public */,
      20,    3,  203,    2, 0x02,   22 /* Public */,
      24,    5,  210,    2, 0x02,   26 /* Public */,
      25,    1,  221,    2, 0x02,   32 /* Public */,
      27,    3,  224,    2, 0x02,   34 /* Public */,
      28,    4,  231,    2, 0x02,   38 /* Public */,
      29,    0,  240,    2, 0x02,   43 /* Public */,
      30,    0,  241,    2, 0x02,   44 /* Public */,
      31,    1,  242,    2, 0x02,   45 /* Public */,
      32,    0,  245,    2, 0x02,   47 /* Public */,
      33,    0,  246,    2, 0x02,   48 /* Public */,
      34,    0,  247,    2, 0x02,   49 /* Public */,
      35,    2,  248,    2, 0x02,   50 /* Public */,
      38,    0,  253,    2, 0x02,   53 /* Public */,
      39,    0,  254,    2, 0x02,   54 /* Public */,
      40,    0,  255,    2, 0x02,   55 /* Public */,
      41,    0,  256,    2, 0x02,   56 /* Public */,
      42,    0,  257,    2, 0x02,   57 /* Public */,

 // methods: parameters
    QMetaType::Bool, QMetaType::QString, QMetaType::QString, QMetaType::QString,    3,    4,    5,
    QMetaType::Bool, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::Double,    3,    7,    8,    4,    5,    9,   10,   11,   12,
    QMetaType::Void,
    QMetaType::QString,
    QMetaType::QString,
    QMetaType::QString,
    QMetaType::QString,
    QMetaType::QString,
    QMetaType::QString,
    QMetaType::Bool, QMetaType::Int, QMetaType::QString, QMetaType::Double,   21,   22,   23,
    QMetaType::Bool, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::Double,    7,    8,   10,   11,   12,
    QMetaType::Bool, QMetaType::Int,   26,
    QMetaType::Bool, QMetaType::QString, QMetaType::QString, QMetaType::QString,    4,    9,    8,
    QMetaType::Bool, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::Double,    4,   10,   11,   12,
    QMetaType::QString,
    QMetaType::QString,
    QMetaType::Bool, QMetaType::Int,   26,
    QMetaType::Bool,
    QMetaType::QString,
    QMetaType::Bool,
    QMetaType::Bool, QMetaType::QString, QMetaType::Int,   36,   37,
    QMetaType::QString,
    QMetaType::Bool,
    QMetaType::Bool,
    QMetaType::QString,
    QMetaType::Bool,

       0        // eod
};

Q_CONSTINIT const QMetaObject WebInterface::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_CLASSWebInterfaceENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASSWebInterfaceENDCLASS,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_CLASSWebInterfaceENDCLASS_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<WebInterface, std::true_type>,
        // method 'attemptLogin'
        QtPrivate::TypeAndForceComplete<bool, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        // method 'attemptRegister'
        QtPrivate::TypeAndForceComplete<bool, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        QtPrivate::TypeAndForceComplete<double, std::false_type>,
        // method 'logout'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'getCurrentUser'
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        // method 'getCurrentRole'
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        // method 'getAdminDashboardStats'
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        // method 'getAllRooms'
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        // method 'getAllBookings'
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        // method 'getAllStaff'
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        // method 'addRoom'
        QtPrivate::TypeAndForceComplete<bool, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        QtPrivate::TypeAndForceComplete<double, std::false_type>,
        // method 'addStaff'
        QtPrivate::TypeAndForceComplete<bool, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        QtPrivate::TypeAndForceComplete<double, std::false_type>,
        // method 'toggleRoomStatus'
        QtPrivate::TypeAndForceComplete<bool, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'updateCustomer'
        QtPrivate::TypeAndForceComplete<bool, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        // method 'updateStaff'
        QtPrivate::TypeAndForceComplete<bool, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        QtPrivate::TypeAndForceComplete<double, std::false_type>,
        // method 'getReport'
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        // method 'getAvailableRooms'
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        // method 'bookRoom'
        QtPrivate::TypeAndForceComplete<bool, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'checkout'
        QtPrivate::TypeAndForceComplete<bool, std::false_type>,
        // method 'getMyPaymentInfo'
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        // method 'makePayment'
        QtPrivate::TypeAndForceComplete<bool, std::false_type>,
        // method 'submitFeedback'
        QtPrivate::TypeAndForceComplete<bool, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'getAllFeedback'
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        // method 'requestHousekeeping'
        QtPrivate::TypeAndForceComplete<bool, std::false_type>,
        // method 'joinLoyalty'
        QtPrivate::TypeAndForceComplete<bool, std::false_type>,
        // method 'getRefundInfo'
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        // method 'requestRefund'
        QtPrivate::TypeAndForceComplete<bool, std::false_type>
    >,
    nullptr
} };

void WebInterface::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<WebInterface *>(_o);
        (void)_t;
        switch (_id) {
        case 0: { bool _r = _t->attemptLogin((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[3])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 1: { bool _r = _t->attemptRegister((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[3])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[4])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[5])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[6])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[7])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[8])),(*reinterpret_cast< std::add_pointer_t<double>>(_a[9])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 2: _t->logout(); break;
        case 3: { QString _r = _t->getCurrentUser();
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        case 4: { QString _r = _t->getCurrentRole();
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        case 5: { QString _r = _t->getAdminDashboardStats();
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        case 6: { QString _r = _t->getAllRooms();
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        case 7: { QString _r = _t->getAllBookings();
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        case 8: { QString _r = _t->getAllStaff();
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        case 9: { bool _r = _t->addRoom((*reinterpret_cast< std::add_pointer_t<int>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<double>>(_a[3])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 10: { bool _r = _t->addStaff((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[3])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[4])),(*reinterpret_cast< std::add_pointer_t<double>>(_a[5])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 11: { bool _r = _t->toggleRoomStatus((*reinterpret_cast< std::add_pointer_t<int>>(_a[1])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 12: { bool _r = _t->updateCustomer((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[3])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 13: { bool _r = _t->updateStaff((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[3])),(*reinterpret_cast< std::add_pointer_t<double>>(_a[4])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 14: { QString _r = _t->getReport();
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        case 15: { QString _r = _t->getAvailableRooms();
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        case 16: { bool _r = _t->bookRoom((*reinterpret_cast< std::add_pointer_t<int>>(_a[1])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 17: { bool _r = _t->checkout();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 18: { QString _r = _t->getMyPaymentInfo();
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        case 19: { bool _r = _t->makePayment();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 20: { bool _r = _t->submitFeedback((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[2])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 21: { QString _r = _t->getAllFeedback();
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        case 22: { bool _r = _t->requestHousekeeping();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 23: { bool _r = _t->joinLoyalty();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 24: { QString _r = _t->getRefundInfo();
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        case 25: { bool _r = _t->requestRefund();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        default: ;
        }
    }
}

const QMetaObject *WebInterface::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *WebInterface::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CLASSWebInterfaceENDCLASS.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int WebInterface::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 26)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 26;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 26)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 26;
    }
    return _id;
}
QT_WARNING_POP
