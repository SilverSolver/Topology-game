/****************************************************************************
** Meta object code from reading C++ file 'gamecore.h'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.6)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../sources/gamecore.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'gamecore.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.6. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_GameCore[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: signature, parameters, type, tag, flags
      10,    9,    9,    9, 0x05,
      26,    9,    9,    9, 0x05,

 // slots: signature, parameters, type, tag, flags
      51,   41,    9,    9, 0x0a,
      70,    9,    9,    9, 0x0a,
      88,    9,    9,    9, 0x0a,
     110,  101,    9,    9, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_GameCore[] = {
    "GameCore\0\0levelComplete()\0fieldChanged()\0"
    "direction\0getPlayerMove(int)\0"
    "getPlayerAction()\0getTrigger()\0levelNum\0"
    "setUpLevel(int)\0"
};

void GameCore::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        GameCore *_t = static_cast<GameCore *>(_o);
        switch (_id) {
        case 0: _t->levelComplete(); break;
        case 1: _t->fieldChanged(); break;
        case 2: _t->getPlayerMove((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: _t->getPlayerAction(); break;
        case 4: _t->getTrigger(); break;
        case 5: _t->setUpLevel((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData GameCore::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject GameCore::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_GameCore,
      qt_meta_data_GameCore, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &GameCore::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *GameCore::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *GameCore::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_GameCore))
        return static_cast<void*>(const_cast< GameCore*>(this));
    return QObject::qt_metacast(_clname);
}

int GameCore::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    }
    return _id;
}

// SIGNAL 0
void GameCore::levelComplete()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}

// SIGNAL 1
void GameCore::fieldChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 1, 0);
}
QT_END_MOC_NAMESPACE
