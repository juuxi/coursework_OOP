#include "interface.h"
#include <QTimer>

TParameters::TParameters(QWidget *parent)
    : QWidget(parent)
{
    stacks = new QLabel("Стопки", this);
    stacks->setGeometry(0, 0, 180, 30);
    stacks_input = new QLineEdit(this);
    stacks_input->setGeometry(180, 0, 150, 30);

    volumes = new QLabel("Тома", this);
    volumes->setGeometry(0, 50, 180, 30);
    volumes_input = new QLineEdit(this);
    volumes_input->setGeometry(180, 50, 150, 30);

    width = new QLabel("Ширина тома", this);
    width->setGeometry(0, 100, 180, 30);
    width_input = new QLineEdit(this);
    width_input->setGeometry(180, 100, 150, 30);

    height = new QLabel("Высота тома", this);
    height->setGeometry(0, 150, 180, 30);
    height_input = new QLineEdit(this);
    height_input->setGeometry(180, 150, 150, 30);

    width_low = new QLabel("Нижняя ширина тома", this);
    width_low->setGeometry(0, 200, 180, 30);
    width_low_input = new QLineEdit(this);
    width_low_input->setGeometry(180, 200, 150, 30);

    width_high = new QLabel("Верхняя ширина тома", this);
    width_high->setGeometry(0, 250, 180, 30);
    width_high_input = new QLineEdit(this);
    width_high_input->setGeometry(180, 250, 150, 30);

    shelves = new QLabel("Полки", this);
    shelves->setGeometry(0, 300, 180, 30);
    shelves_input = new QLineEdit(this);
    shelves_input->setGeometry(180, 300, 150, 30);
}

TParameters::~TParameters()
{
    delete stacks;
    delete stacks_input;
    delete volumes;
    delete volumes_input;
    delete width;
    delete width_input;
    delete height;
    delete height_input;
    delete width_low;
    delete width_low_input;
    delete width_high;
    delete width_high_input;
    delete shelves;
    delete shelves_input;
}

void TParameters::show_parameters()
{
    this->show();
}

TTableVisual::TTableVisual(QWidget *parent)
    : QGraphicsScene(parent)
{    
    ;
}

int TTableVisual::draw(Volume* vol, int table_pos, int prev_end)
{
    if (vol->get_is_lying())
        vol->setPos(table_pos, prev_end);
    addItem(vol);
    return prev_end + vol->get_width();
}

void TTableVisual::draw_pile(Pile pile)
{
    int prev_end = 10;
    for (int i = 0; i < pile.get_size(); i++)
        prev_end = draw(pile[i], pile.get_table_pos(), prev_end);
}

TTableVisual::~TTableVisual()
{

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
    : QGraphicsScene(parent)
{

}

TRackVisual::~TRackVisual()
{

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
    : QWidget(parent),
      param(new TParameters()),
      table_visual(new TTableVisual()),
      table_control(new TTableControl()),
      rack_visual(new TRackVisual()),
      rack_control(new TRackControl()),
      table(new QGraphicsView(table_visual, this)),
      rack(new QGraphicsView(rack_visual, this)),
      layout(new QGridLayout(this))
{
    setWindowTitle("Главное окно");
    setFixedSize(1500, 800);
    table->setFixedSize(500, 500);
    rack->setFixedSize(500, 500);

    piles.push_back(Pile(5, 10, 20));
    for (Pile &pile : piles)
    {
        table_visual->draw_pile(pile);
    }

    layout->addWidget(param,0,0);
    layout->addWidget(table,0,1);
    layout->addWidget(table_control,1,1);
    layout->addWidget(rack,0,2);
    layout->addWidget(rack_control,1,2);
    this->setLayout(layout);
}

TInterface::~TInterface()
{
    delete param;
}
