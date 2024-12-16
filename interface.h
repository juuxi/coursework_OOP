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
    unsigned short piles;
    unsigned short volumes;
    unsigned short length;
    unsigned short height;
    unsigned short width_min;
    unsigned short width_max;
    unsigned short shelves;
    Parameters(unsigned short _pi, unsigned short _vo, unsigned short _le,
               unsigned short _he, unsigned short _wmin, unsigned short _wmax, unsigned short _sh) :
        piles(_pi), volumes(_vo), length(_le), height(_he),
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

    QPushButton* send_btn;

public:
    TParametersWindow(QWidget *parent = nullptr);
    ~TParametersWindow();
public slots:
    void get_params();
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
    QLabel* deal_pile_text_start;
    QLineEdit* deal_pile_val;
    QLabel* deal_pile_text_finish;
    QPushButton* deal;

public:
    TTableControl(QWidget *parent = nullptr);
    ~TTableControl();
public slots:
    void process();
signals:
    void push_volume(int);
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

    QLabel* shelf_number_name;
    QLineEdit* shelf_number_value;
    QLabel* volume_number_name;
    QLineEdit* volume_number_value;
    QPushButton* take_volume_btn;

public:
    QLabel* output;
    TRackControl(QWidget *parent = nullptr);
    ~TRackControl();
public slots:
    void imp_take_volume();
signals:
    void hide_volume(int, int);
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
    void make_piles_shelves();
    ~TInterface();
public slots:
    void receive_params(Parameters);
    void transit_vol(int);
    void imp_hide_volume(int, int);
};
#endif // TINTERFACE_H
