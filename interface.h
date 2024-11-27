#ifndef TINTERFACE_H
#define TINTERFACE_H

#include <QWidget>
#include <QLabel>
#include <QLineEdit>
#include <QGridLayout>
#include <QPushButton>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QPainter>
#include <QPaintEvent>
#include "volume.h"

class TParameters : public QWidget
{
    Q_OBJECT
    QLabel* stacks;
    QLineEdit* stacks_input;
    QLabel* volumes;
    QLineEdit* volumes_input;
    QLabel* width;
    QLineEdit* width_input;
    QLabel* height;
    QLineEdit* height_input;
    QLabel* width_low;
    QLineEdit* width_low_input;
    QLabel* width_high;
    QLineEdit* width_high_input;
    QLabel* shelves;
    QLineEdit* shelves_input;

public:
    TParameters(QWidget *parent = nullptr);
    ~TParameters();
public slots:
    void show_parameters();
};

class TTableVisual : public QGraphicsScene
{
    Q_OBJECT

public:
    TTableVisual(QWidget *parent = nullptr);
    void draw(Volume*);
    ~TTableVisual();
};

class TTableControl : public QWidget
{
    Q_OBJECT
    QLabel* tag;

public:
    TTableControl(QWidget *parent = nullptr);
    ~TTableControl();
};

class TRackVisual : public QGraphicsScene
{
    Q_OBJECT

public:
    TRackVisual(QWidget *parent = nullptr);
    ~TRackVisual();
};

class TRackControl : public QWidget
{
    Q_OBJECT
    QLabel* tag;

public:
    TRackControl(QWidget *parent = nullptr);
    ~TRackControl();
};

class TInterface : public QWidget
{
    Q_OBJECT
    TParameters* param;
    TTableVisual* table_visual;
    TTableControl* table_control;
    TRackVisual* rack_visual;
    TRackControl* rack_control;
    QGraphicsView* table;
    QGraphicsView* rack;
    QGridLayout   *layout;

public:
    TInterface(QWidget *parent = nullptr);
    ~TInterface();
};
#endif // TINTERFACE_H
