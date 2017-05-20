/****************************************************************************
** Meta object code from reading C++ file 'levelbuilder.h'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.6)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../levelbuilder.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'levelbuilder.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.6. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_LevelBuilder[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      24,   14,   13,   13, 0x0a,
      70,   55,   49,   13, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_LevelBuilder[] = {
    "LevelBuilder\0\0gameBoard\0"
    "setGameBoard(GameBoard*)\0void*\0"
    "gameBoard,file\0buildGameBoard(GameBoard*,QFile*)\0"
};

void LevelBuilder::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        LevelBuilder *_t = static_cast<LevelBuilder *>(_o);
        switch (_id) {
        case 0: _t->setGameBoard((*reinterpret_cast< GameBoard*(*)>(_a[1]))); break;
        case 1: { void* _r = _t->buildGameBoard((*reinterpret_cast< GameBoard*(*)>(_a[1])),(*reinterpret_cast< QFile*(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< void**>(_a[0]) = _r; }  break;
        default: ;
        }
    }
}

const QMetaObjectExtraData LevelBuilder::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject LevelBuilder::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_LevelBuilder,
      qt_meta_data_LevelBuilder, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &LevelBuilder::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *LevelBuilder::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *LevelBuilder::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_LevelBuilder))
        return static_cast<void*>(const_cast< LevelBuilder*>(this));
    return QObject::qt_metacast(_clname);
}

int LevelBuilder::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 2)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 2;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
