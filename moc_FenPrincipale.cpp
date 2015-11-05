/****************************************************************************
** Meta object code from reading C++ file 'FenPrincipale.h'
**
** Created: Tue Jun 21 15:50:05 2011
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "FenPrincipale.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'FenPrincipale.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_FenPrincipale[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
      16,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      15,   14,   14,   14, 0x08,
      28,   14,   14,   14, 0x08,
      39,   14,   14,   14, 0x08,
      46,   14,   14,   14, 0x08,
      53,   14,   14,   14, 0x08,
      66,   14,   14,   14, 0x08,
      74,   14,   14,   14, 0x08,
      89,   14,   14,   14, 0x08,
     104,   14,   14,   14, 0x08,
     119,   14,   14,   14, 0x08,
     139,  133,   14,   14, 0x08,
     174,  161,   14,   14, 0x08,
     203,  199,   14,   14, 0x08,
     223,   14,   14,   14, 0x08,
     253,  241,   14,   14, 0x08,
     279,  276,   14,   14, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_FenPrincipale[] = {
    "FenPrincipale\0\0precedente()\0suivante()\0"
    "home()\0stop()\0actualiser()\0about()\0"
    "aboutPhNavig()\0nouvelOnglet()\0"
    "fermerOnglet()\0chargerPage()\0index\0"
    "changementOnglet(int)\0titreComplet\0"
    "changementTitre(QString)\0url\0"
    "changementUrl(QUrl)\0chargementDebut()\0"
    "pourcentage\0chargementEnCours(int)\0"
    "ok\0chargementTermine(bool)\0"
};

const QMetaObject FenPrincipale::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_FenPrincipale,
      qt_meta_data_FenPrincipale, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &FenPrincipale::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *FenPrincipale::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *FenPrincipale::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_FenPrincipale))
        return static_cast<void*>(const_cast< FenPrincipale*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int FenPrincipale::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: precedente(); break;
        case 1: suivante(); break;
        case 2: home(); break;
        case 3: stop(); break;
        case 4: actualiser(); break;
        case 5: about(); break;
        case 6: aboutPhNavig(); break;
        case 7: nouvelOnglet(); break;
        case 8: fermerOnglet(); break;
        case 9: chargerPage(); break;
        case 10: changementOnglet((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 11: changementTitre((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 12: changementUrl((*reinterpret_cast< const QUrl(*)>(_a[1]))); break;
        case 13: chargementDebut(); break;
        case 14: chargementEnCours((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 15: chargementTermine((*reinterpret_cast< bool(*)>(_a[1]))); break;
        default: ;
        }
        _id -= 16;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
