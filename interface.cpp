#include "interface.h"
#include <QTimer>

TParameters::TParameters(QWidget *parent)
    : QWidget(parent)
{
}

TParameters::~TParameters()
{
}

void TParameters::show_parameters()
{
    this->show();
}

TTableVisual::TTableVisual(QWidget *parent)
    : QWidget(parent)
{
    tag = new QLabel("Table", this);
    tag->setGeometry(0, 0, 100, 30);
}

TTableVisual::~TTableVisual()
{
    delete tag;
}

TTableControl::TTableControl(QWidget *parent)
    : QWidget(parent)
{
    tag = new QLabel("Table Control", this);
    tag->setGeometry(0, 0, 100, 30);
}

TTableControl::~TTableControl()
{
    delete tag;
}

TRackVisual::TRackVisual(QWidget *parent)
    : QWidget(parent)
{
    tag = new QLabel("Rack", this);
    tag->setGeometry(0, 0, 100, 30);
}

TRackVisual::~TRackVisual()
{
    delete tag;
}

TRackControl::TRackControl(QWidget *parent)
    : QWidget(parent)
{
    tag = new QLabel("Rack Control", this);
    tag->setGeometry(0, 0, 100, 30);
}

TRackControl::~TRackControl()
{
    delete tag;
}

TInterface::TInterface(QWidget *parent)
    : QWidget(parent)
{
    setWindowTitle("Главное окно");
    setFixedSize(1500, 800);
    layout = new QGridLayout(this);
    param = new TParameters();
    table_visual = new TTableVisual();
    table_control = new TTableControl();
    rack_visual = new TRackVisual();
    rack_control = new TRackControl();
    layout->addWidget(param,0,0);
    layout->addWidget(table_visual,0,1);
    layout->addWidget(table_control,1,1);
    layout->addWidget(rack_visual,0,2);
    layout->addWidget(rack_control,1,2);
    this->setLayout(layout);
}

TInterface::~TInterface()
{
    delete param;
}
