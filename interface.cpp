#include "interface.h"
#include <QTimer>

TParameters::TParameters(QWidget *parent)
    : QWidget(parent)
{
    setWindowTitle("Не главное окно");
    setFixedSize(500, 300);
    btn_1 = new QPushButton(this);
    btn_1->setGeometry(0, 0, 120, 50);
}

TParameters::~TParameters()
{
    delete btn_1;
}

void TParameters::show_parameters()
{
    this->show();
}

TInterface::TInterface(QWidget *parent)
    : QWidget(parent)
{
    setWindowTitle("Главное окно");
    setFixedSize(1500, 800);
    l = new QGridLayout(this);
    param = new TParameters();
    param2 = new TParameters();
    param3 = new TParameters();
    param4 = new TParameters();
    l->addWidget(param,0,0);
    l->addWidget(param2,1,0);
    l->addWidget(param3,0,1);
    l->addWidget(param4,1,1);
    this->setLayout(l);
}

TInterface::~TInterface()
{
    delete param;
}
