/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.2.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../ShapeGenerator/mainwindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.2.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_MainWindow_t {
    const uint offsetsAndSize[104];
    char stringdata0[1164];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(offsetof(qt_meta_stringdata_MainWindow_t, stringdata0) + ofs), len 
static const qt_meta_stringdata_MainWindow_t qt_meta_stringdata_MainWindow = {
    {
QT_MOC_LITERAL(0, 10), // "MainWindow"
QT_MOC_LITERAL(11, 11), // "sentMessage"
QT_MOC_LITERAL(23, 0), // ""
QT_MOC_LITERAL(24, 6), // "string"
QT_MOC_LITERAL(31, 7), // "onTimer"
QT_MOC_LITERAL(39, 11), // "showMessage"
QT_MOC_LITERAL(51, 25), // "on_splitter_splitterMoved"
QT_MOC_LITERAL(77, 3), // "pos"
QT_MOC_LITERAL(81, 5), // "index"
QT_MOC_LITERAL(87, 29), // "on_polygonButtonShape_clicked"
QT_MOC_LITERAL(117, 29), // "on_ellipseButtonShape_clicked"
QT_MOC_LITERAL(147, 27), // "on_clearEllipseData_clicked"
QT_MOC_LITERAL(175, 21), // "on_addEllipse_clicked"
QT_MOC_LITERAL(197, 22), // "on_clearButton_clicked"
QT_MOC_LITERAL(220, 24), // "on_zoomInButtton_clicked"
QT_MOC_LITERAL(245, 24), // "on_zoomOutButton_clicked"
QT_MOC_LITERAL(270, 26), // "on_zoomToFitButton_clicked"
QT_MOC_LITERAL(297, 27), // "on_clearPolygonData_clicked"
QT_MOC_LITERAL(325, 21), // "on_addPolygon_clicked"
QT_MOC_LITERAL(347, 27), // "on_addRandomPolygon_clicked"
QT_MOC_LITERAL(375, 36), // "on_addRandomIrregularPolygon_..."
QT_MOC_LITERAL(412, 29), // "on_addRandomPolygon_2_clicked"
QT_MOC_LITERAL(442, 23), // "on_shapeDrawing_clicked"
QT_MOC_LITERAL(466, 16), // "on_close_clicked"
QT_MOC_LITERAL(483, 21), // "on_randomStar_clicked"
QT_MOC_LITERAL(505, 19), // "on_triangle_clicked"
QT_MOC_LITERAL(525, 20), // "on_rectangle_clicked"
QT_MOC_LITERAL(546, 16), // "on_other_clicked"
QT_MOC_LITERAL(563, 31), // "on_depthStarSlider_valueChanged"
QT_MOC_LITERAL(595, 5), // "value"
QT_MOC_LITERAL(601, 34), // "on_verticesStarSlider_valueCh..."
QT_MOC_LITERAL(636, 24), // "on_appedTriangle_clicked"
QT_MOC_LITERAL(661, 15), // "on_home_clicked"
QT_MOC_LITERAL(677, 15), // "on_help_clicked"
QT_MOC_LITERAL(693, 18), // "on_aboutQt_clicked"
QT_MOC_LITERAL(712, 17), // "on_home_2_clicked"
QT_MOC_LITERAL(730, 19), // "on_settings_clicked"
QT_MOC_LITERAL(750, 24), // "on_radioButton_4_clicked"
QT_MOC_LITERAL(775, 24), // "on_radioButton_3_clicked"
QT_MOC_LITERAL(800, 24), // "on_radioButton_2_clicked"
QT_MOC_LITERAL(825, 22), // "on_radioButton_clicked"
QT_MOC_LITERAL(848, 23), // "on_addRectangle_clicked"
QT_MOC_LITERAL(872, 35), // "on_rotationAngleSlider_valueC..."
QT_MOC_LITERAL(908, 24), // "on_checkBox_stateChanged"
QT_MOC_LITERAL(933, 4), // "arg1"
QT_MOC_LITERAL(938, 31), // "on_checkBoxRandDim_stateChanged"
QT_MOC_LITERAL(970, 36), // "on_checkBoxCustomOrigin_state..."
QT_MOC_LITERAL(1007, 28), // "on_cogsNrSlider_valueChanged"
QT_MOC_LITERAL(1036, 36), // "on_cogsBaseRadiusSilder_value..."
QT_MOC_LITERAL(1073, 32), // "on_cogsHeightSlider_valueChanged"
QT_MOC_LITERAL(1106, 22), // "on_addCogwheel_clicked"
QT_MOC_LITERAL(1129, 34) // "on_transparencySlider_valueCh..."

    },
    "MainWindow\0sentMessage\0\0string\0onTimer\0"
    "showMessage\0on_splitter_splitterMoved\0"
    "pos\0index\0on_polygonButtonShape_clicked\0"
    "on_ellipseButtonShape_clicked\0"
    "on_clearEllipseData_clicked\0"
    "on_addEllipse_clicked\0on_clearButton_clicked\0"
    "on_zoomInButtton_clicked\0"
    "on_zoomOutButton_clicked\0"
    "on_zoomToFitButton_clicked\0"
    "on_clearPolygonData_clicked\0"
    "on_addPolygon_clicked\0on_addRandomPolygon_clicked\0"
    "on_addRandomIrregularPolygon_clicked\0"
    "on_addRandomPolygon_2_clicked\0"
    "on_shapeDrawing_clicked\0on_close_clicked\0"
    "on_randomStar_clicked\0on_triangle_clicked\0"
    "on_rectangle_clicked\0on_other_clicked\0"
    "on_depthStarSlider_valueChanged\0value\0"
    "on_verticesStarSlider_valueChanged\0"
    "on_appedTriangle_clicked\0on_home_clicked\0"
    "on_help_clicked\0on_aboutQt_clicked\0"
    "on_home_2_clicked\0on_settings_clicked\0"
    "on_radioButton_4_clicked\0"
    "on_radioButton_3_clicked\0"
    "on_radioButton_2_clicked\0"
    "on_radioButton_clicked\0on_addRectangle_clicked\0"
    "on_rotationAngleSlider_valueChanged\0"
    "on_checkBox_stateChanged\0arg1\0"
    "on_checkBoxRandDim_stateChanged\0"
    "on_checkBoxCustomOrigin_stateChanged\0"
    "on_cogsNrSlider_valueChanged\0"
    "on_cogsBaseRadiusSilder_valueChanged\0"
    "on_cogsHeightSlider_valueChanged\0"
    "on_addCogwheel_clicked\0"
    "on_transparencySlider_valueChanged"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MainWindow[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
      45,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    1,  284,    2, 0x06,    1 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       4,    0,  287,    2, 0x0a,    3 /* Public */,
       5,    1,  288,    2, 0x0a,    4 /* Public */,
       6,    2,  291,    2, 0x08,    6 /* Private */,
       9,    0,  296,    2, 0x08,    9 /* Private */,
      10,    0,  297,    2, 0x08,   10 /* Private */,
      11,    0,  298,    2, 0x08,   11 /* Private */,
      12,    0,  299,    2, 0x08,   12 /* Private */,
      13,    0,  300,    2, 0x08,   13 /* Private */,
      14,    0,  301,    2, 0x08,   14 /* Private */,
      15,    0,  302,    2, 0x08,   15 /* Private */,
      16,    0,  303,    2, 0x08,   16 /* Private */,
      17,    0,  304,    2, 0x08,   17 /* Private */,
      18,    0,  305,    2, 0x08,   18 /* Private */,
      19,    0,  306,    2, 0x08,   19 /* Private */,
      20,    0,  307,    2, 0x08,   20 /* Private */,
      21,    0,  308,    2, 0x08,   21 /* Private */,
      22,    0,  309,    2, 0x08,   22 /* Private */,
      23,    0,  310,    2, 0x08,   23 /* Private */,
      24,    0,  311,    2, 0x08,   24 /* Private */,
      25,    0,  312,    2, 0x08,   25 /* Private */,
      26,    0,  313,    2, 0x08,   26 /* Private */,
      27,    0,  314,    2, 0x08,   27 /* Private */,
      28,    1,  315,    2, 0x08,   28 /* Private */,
      30,    1,  318,    2, 0x08,   30 /* Private */,
      31,    0,  321,    2, 0x08,   32 /* Private */,
      32,    0,  322,    2, 0x08,   33 /* Private */,
      33,    0,  323,    2, 0x08,   34 /* Private */,
      34,    0,  324,    2, 0x08,   35 /* Private */,
      35,    0,  325,    2, 0x08,   36 /* Private */,
      36,    0,  326,    2, 0x08,   37 /* Private */,
      37,    0,  327,    2, 0x08,   38 /* Private */,
      38,    0,  328,    2, 0x08,   39 /* Private */,
      39,    0,  329,    2, 0x08,   40 /* Private */,
      40,    0,  330,    2, 0x08,   41 /* Private */,
      41,    0,  331,    2, 0x08,   42 /* Private */,
      42,    1,  332,    2, 0x08,   43 /* Private */,
      43,    1,  335,    2, 0x08,   45 /* Private */,
      45,    1,  338,    2, 0x08,   47 /* Private */,
      46,    1,  341,    2, 0x08,   49 /* Private */,
      47,    1,  344,    2, 0x08,   51 /* Private */,
      48,    1,  347,    2, 0x08,   53 /* Private */,
      49,    1,  350,    2, 0x08,   55 /* Private */,
      50,    0,  353,    2, 0x08,   57 /* Private */,
      51,    1,  354,    2, 0x08,   58 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString,    3,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,    7,    8,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   29,
    QMetaType::Void, QMetaType::Int,   29,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   29,
    QMetaType::Void, QMetaType::Int,   44,
    QMetaType::Void, QMetaType::Int,   44,
    QMetaType::Void, QMetaType::Int,   44,
    QMetaType::Void, QMetaType::Int,   29,
    QMetaType::Void, QMetaType::Int,   29,
    QMetaType::Void, QMetaType::Int,   29,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   29,

       0        // eod
};

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<MainWindow *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->sentMessage((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 1: _t->onTimer(); break;
        case 2: _t->showMessage((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 3: _t->on_splitter_splitterMoved((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 4: _t->on_polygonButtonShape_clicked(); break;
        case 5: _t->on_ellipseButtonShape_clicked(); break;
        case 6: _t->on_clearEllipseData_clicked(); break;
        case 7: _t->on_addEllipse_clicked(); break;
        case 8: _t->on_clearButton_clicked(); break;
        case 9: _t->on_zoomInButtton_clicked(); break;
        case 10: _t->on_zoomOutButton_clicked(); break;
        case 11: _t->on_zoomToFitButton_clicked(); break;
        case 12: _t->on_clearPolygonData_clicked(); break;
        case 13: _t->on_addPolygon_clicked(); break;
        case 14: _t->on_addRandomPolygon_clicked(); break;
        case 15: _t->on_addRandomIrregularPolygon_clicked(); break;
        case 16: _t->on_addRandomPolygon_2_clicked(); break;
        case 17: _t->on_shapeDrawing_clicked(); break;
        case 18: _t->on_close_clicked(); break;
        case 19: _t->on_randomStar_clicked(); break;
        case 20: _t->on_triangle_clicked(); break;
        case 21: _t->on_rectangle_clicked(); break;
        case 22: _t->on_other_clicked(); break;
        case 23: _t->on_depthStarSlider_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 24: _t->on_verticesStarSlider_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 25: _t->on_appedTriangle_clicked(); break;
        case 26: _t->on_home_clicked(); break;
        case 27: _t->on_help_clicked(); break;
        case 28: _t->on_aboutQt_clicked(); break;
        case 29: _t->on_home_2_clicked(); break;
        case 30: _t->on_settings_clicked(); break;
        case 31: _t->on_radioButton_4_clicked(); break;
        case 32: _t->on_radioButton_3_clicked(); break;
        case 33: _t->on_radioButton_2_clicked(); break;
        case 34: _t->on_radioButton_clicked(); break;
        case 35: _t->on_addRectangle_clicked(); break;
        case 36: _t->on_rotationAngleSlider_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 37: _t->on_checkBox_stateChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 38: _t->on_checkBoxRandDim_stateChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 39: _t->on_checkBoxCustomOrigin_stateChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 40: _t->on_cogsNrSlider_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 41: _t->on_cogsBaseRadiusSilder_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 42: _t->on_cogsHeightSlider_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 43: _t->on_addCogwheel_clicked(); break;
        case 44: _t->on_transparencySlider_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (MainWindow::*)(const QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MainWindow::sentMessage)) {
                *result = 0;
                return;
            }
        }
    }
}

const QMetaObject MainWindow::staticMetaObject = { {
    QMetaObject::SuperData::link<QMainWindow::staticMetaObject>(),
    qt_meta_stringdata_MainWindow.offsetsAndSize,
    qt_meta_data_MainWindow,
    qt_static_metacall,
    nullptr,
qt_incomplete_metaTypeArray<qt_meta_stringdata_MainWindow_t
, QtPrivate::TypeAndForceComplete<MainWindow, std::true_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<const QString, std::false_type>
, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QString, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>


>,
    nullptr
} };


const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_MainWindow.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 45)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 45;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 45)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 45;
    }
    return _id;
}

// SIGNAL 0
void MainWindow::sentMessage(const QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
