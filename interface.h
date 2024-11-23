#ifndef TINTERFACE_H
#define TINTERFACE_H

#include <QWidget>
#include <QGridLayout>
#include <QPushButton>

class TParameters : public QWidget
{
    Q_OBJECT
    QPushButton* btn_1;

public:
    TParameters(QWidget *parent = nullptr);
    ~TParameters();
public slots:
    void show_parameters();
};

class TInterface : public QWidget
{
    Q_OBJECT
    TParameters* param;
    TParameters* param2;
    TParameters* param3;
    TParameters* param4;
    QGridLayout   *l;

public:
    TInterface(QWidget *parent = nullptr);
    ~TInterface();
};
#endif // TINTERFACE_H
