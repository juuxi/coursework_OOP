#ifndef TINTERFACE_H
#define TINTERFACE_H

#include <QWidget>
#include <QLabel>
#include <QList>
#include <QLineEdit>
#include <QGridLayout>
#include <QPushButton>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QPainter>
#include <QPaintEvent>
#include "pile.h"
#include "shelf.h"

struct Parameters
{
    unsigned short stacks;
    unsigned short volumes;
    unsigned short length;
    unsigned short height;
    unsigned short width_min;
    unsigned short width_max;
    unsigned short shelves;
    Parameters(unsigned short _st, unsigned short _vo, unsigned short _le,
               unsigned short _he, unsigned short _wmin, unsigned short _wmax, unsigned short _sh) :
        stacks(_st), volumes(_vo), length(_le), height(_he),
        width_min(_wmin), width_max(_wmax), shelves(_sh){};
};

class TParametersWindow : public QWidget
{
    Q_OBJECT
    QLabel* stacks;
    QLineEdit* stacks_input;
    QLabel* volumes;
    QLineEdit* volumes_input;
    QLabel* length;
    QLineEdit* length_input;
    QLabel* height;
    QLineEdit* height_input;
    QLabel* width_min;
    QLineEdit* width_min_input;
    QLabel* width_max;
    QLineEdit* width_max_input;
    QLabel* shelves;
    QLineEdit* shelves_input;

    void get_param();

public:
    TParametersWindow(QWidget *parent = nullptr);
    ~TParametersWindow();
signals:
    void send_params(Parameters);
};

class TTableVisual : public QGraphicsScene
{
    Q_OBJECT

public:
    TTableVisual(QWidget *parent = nullptr);
    int draw(Volume*, int, int);
    void draw_pile(Pile);
    ~TTableVisual();
};

class TTableControl : public QWidget
{
    Q_OBJECT
    QLabel* tag;
    QPushButton* deal;

public:
    TTableControl(QWidget *parent = nullptr);
    ~TTableControl();
};

class TRackVisual : public QGraphicsScene
{
    Q_OBJECT

public:
    TRackVisual(QWidget *parent = nullptr);
    int draw(Volume*, int, int);
    void draw_shelf(Shelf);
    ~TRackVisual();
};

class TRackControl : public QWidget
{
    Q_OBJECT
    QLabel* tag;

public:
    QLabel* output;
    TRackControl(QWidget *parent = nullptr);
    ~TRackControl();
};

class TInterface : public QWidget
{
    Q_OBJECT
    TParametersWindow* param_window;
    TTableVisual* table_visual;
    TTableControl* table_control;
    TRackVisual* rack_visual;
    TRackControl* rack_control;
    QGraphicsView* table;
    QGraphicsView* rack;
    QGridLayout   *layout;
    Parameters params;

public:
    QList<Pile> piles;
    QList<Shelf> shelves;
    TInterface(QWidget *parent = nullptr);
    void update_pic();
    ~TInterface();
public slots:
    void receive_params(Parameters);
    void transit_vol();
};
#endif // TINTERFACE_H
