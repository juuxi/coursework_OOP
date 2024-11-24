#ifndef TINTERFACE_H
#define TINTERFACE_H

#include <QWidget>
#include <QLabel>
#include <QLineEdit>
#include <QGridLayout>
#include <QPushButton>

class TParameters : public QWidget
{
    Q_OBJECT

public:
    TParameters(QWidget *parent = nullptr);
    ~TParameters();
public slots:
    void show_parameters();
};

class TTableVisual : public QWidget
{
    Q_OBJECT
    QLabel* tag;

public:
    TTableVisual(QWidget *parent = nullptr);
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

class TRackVisual : public QWidget
{
    Q_OBJECT
    QLabel* tag;

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
    QGridLayout   *layout;

public:
    TInterface(QWidget *parent = nullptr);
    ~TInterface();
};
#endif // TINTERFACE_H
