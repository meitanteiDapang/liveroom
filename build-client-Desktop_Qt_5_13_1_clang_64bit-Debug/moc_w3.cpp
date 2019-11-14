/****************************************************************************
** Meta object code from reading C++ file 'w3.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.13.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../client/w3.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'w3.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.13.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_W3_t {
    QByteArrayData data[11];
    char stringdata0[156];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_W3_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_W3_t qt_meta_stringdata_W3 = {
    {
QT_MOC_LITERAL(0, 0, 2), // "W3"
QT_MOC_LITERAL(1, 3, 19), // "please_stop_capture"
QT_MOC_LITERAL(2, 23, 0), // ""
QT_MOC_LITERAL(3, 24, 20), // "go_on_process_picpic"
QT_MOC_LITERAL(4, 45, 13), // "when_captured"
QT_MOC_LITERAL(5, 59, 2), // "id"
QT_MOC_LITERAL(6, 62, 5), // "image"
QT_MOC_LITERAL(7, 68, 18), // "on_quit_pb_clicked"
QT_MOC_LITERAL(8, 87, 18), // "on_send_pb_clicked"
QT_MOC_LITERAL(9, 106, 20), // "on_rocket_pb_clicked"
QT_MOC_LITERAL(10, 127, 28) // "on_refresh_people_pb_clicked"

    },
    "W3\0please_stop_capture\0\0go_on_process_picpic\0"
    "when_captured\0id\0image\0on_quit_pb_clicked\0"
    "on_send_pb_clicked\0on_rocket_pb_clicked\0"
    "on_refresh_people_pb_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_W3[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   49,    2, 0x06 /* Public */,
       3,    0,   50,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       4,    2,   51,    2, 0x0a /* Public */,
       7,    0,   56,    2, 0x08 /* Private */,
       8,    0,   57,    2, 0x08 /* Private */,
       9,    0,   58,    2, 0x08 /* Private */,
      10,    0,   59,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void, QMetaType::Int, QMetaType::QImage,    5,    6,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void W3::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<W3 *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->please_stop_capture(); break;
        case 1: _t->go_on_process_picpic(); break;
        case 2: _t->when_captured((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< QImage(*)>(_a[2]))); break;
        case 3: _t->on_quit_pb_clicked(); break;
        case 4: _t->on_send_pb_clicked(); break;
        case 5: _t->on_rocket_pb_clicked(); break;
        case 6: _t->on_refresh_people_pb_clicked(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (W3::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&W3::please_stop_capture)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (W3::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&W3::go_on_process_picpic)) {
                *result = 1;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject W3::staticMetaObject = { {
    &QWidget::staticMetaObject,
    qt_meta_stringdata_W3.data,
    qt_meta_data_W3,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *W3::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *W3::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_W3.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int W3::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
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
void W3::please_stop_capture()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void W3::go_on_process_picpic()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
