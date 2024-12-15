#include "interface.h"
#include <QTimer>

TParametersWindow::TParametersWindow(QWidget *parent)
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

    length = new QLabel("Ширина тома", this);
    length->setGeometry(0, 100, 180, 30);
    length_input = new QLineEdit(this);
    length_input->setGeometry(180, 100, 150, 30);

    height = new QLabel("Высота тома", this);
    height->setGeometry(0, 150, 180, 30);
    height_input = new QLineEdit(this);
    height_input->setGeometry(180, 150, 150, 30);

    width_min = new QLabel("Нижняя ширина тома", this);
    width_min->setGeometry(0, 200, 180, 30);
    width_min_input = new QLineEdit(this);
    width_min_input->setGeometry(180, 200, 150, 30);

    width_max = new QLabel("Верхняя ширина тома", this);
    width_max->setGeometry(0, 250, 180, 30);
    width_max_input = new QLineEdit(this);
    width_max_input->setGeometry(180, 250, 150, 30);

    shelves = new QLabel("Полки", this);
    shelves->setGeometry(0, 300, 180, 30);
    shelves_input = new QLineEdit(this);
    shelves_input->setGeometry(180, 300, 150, 30);
}

void TParametersWindow::get_param()
{
    Parameters param = Parameters(
                stacks_input->text().toInt(),
                volumes_input->text().toInt(),
                length_input->text().toInt(),
                height_input->text().toInt(),
                width_min_input->text().toInt(),
                width_max_input->text().toInt(),
                shelves_input->text().toInt()
                );
    emit send_params(param);
}

TParametersWindow::~TParametersWindow()
{
    delete stacks;
    delete stacks_input;
    delete volumes;
    delete volumes_input;
    delete length;
    delete length_input;
    delete height;
    delete height_input;
    delete width_min;
    delete width_min_input;
    delete width_max;
    delete width_max_input;
    delete shelves;
    delete shelves_input;
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

    deal_pile_text_start = new QLabel("Переложить из", this);
    deal_pile_text_start->setGeometry(0, 50, 120, 40);

    deal_pile_val = new QLineEdit(this);
    deal_pile_val->setGeometry(125, 60, 30, 20);

    deal_pile_text_finish = new QLabel("стопки", this);
    deal_pile_text_finish->setGeometry(160, 50, 100, 40);

    deal = new QPushButton("Deal", this);
    deal->setGeometry(150, 100, 100, 30);

    connect(deal, SIGNAL(pressed()), this, SLOT(process()));
    connect(this, SIGNAL(push_volume(int)), parent, SLOT(transit_vol(int)));
}

void TTableControl::process()
{
    int a = deal_pile_val->text().toInt();
    emit push_volume(a);
}

TTableControl::~TTableControl()
{
    delete tag;
    delete deal;
}

TRackVisual::TRackVisual(QWidget *parent)
    : QGraphicsScene(parent)
{

}

int TRackVisual::draw(Volume* vol, int shelf_pos, int prev_end)
{
    if (!vol->get_is_lying())
        vol->setPos(shelf_pos, prev_end);
    addItem(vol);
    return prev_end + vol->get_width();
}

void TRackVisual::draw_shelf(Shelf shelf)
{
    int prev_end = 10;
    for (int i = 0; i < shelf.get_size(); i++)
    {
        shelf[i]->set_is_lying(false);
        prev_end = draw(shelf[i], 10 + 100 * (shelf.get_pos() - 1), /*prev_end*/10);
    }
}

TRackVisual::~TRackVisual()
{

}

TRackControl::TRackControl(QWidget *parent)
    : QWidget(parent)
{
    tag = new QLabel("Rack Control", this);
    tag->setGeometry(0, 0, 100, 30);

    output = new QLabel(this);
    output->setGeometry(0, 100, 400, 60);
}

TRackControl::~TRackControl()
{
    delete tag;
}

TInterface::TInterface(QWidget *parent)
    : QWidget(parent),
      param_window(new TParametersWindow()),
      table_visual(new TTableVisual()),
      table_control(new TTableControl(this)),
      rack_visual(new TRackVisual()),
      rack_control(new TRackControl()),
      table(new QGraphicsView(table_visual, this)),
      rack(new QGraphicsView(rack_visual, this)),
      layout(new QGridLayout(this)),
      params(3, 15, 50, 80, 15, 25, 4)
{
    setWindowTitle("Главное окно");
    setFixedSize(1500, 800);
    table->setFixedSize(500, 500);
    rack->setFixedSize(500, 500);

    for (int i = 0; i < params.piles; i++)
        piles.push_back(Pile(params.width_min, params.width_max, i));
    srand(time(NULL));
    for (int i = 0; i < params.volumes; i++)
        piles[rand() % 3].add_new();
    int piles_width = 0;
    for (Pile &pile : piles)
    {
        table_visual->draw_pile(pile);
        piles_width += pile.count_total_width();
    }

    for (int i = 1; i <= params.shelves; i++)
        shelves.push_back(Shelf(piles_width * 1.2 / params.shelves, i));
    for (Shelf &shelf : shelves)
        rack_visual->draw_shelf(shelf);

    layout->addWidget(param_window,0,0);
    layout->addWidget(table,0,1);
    layout->addWidget(table_control,1,1);
    layout->addWidget(rack,0,2);
    layout->addWidget(rack_control,1,2);
    this->setLayout(layout);
}

void TInterface::receive_params(Parameters _params)
{
    params = _params; //update params in all windows
}

void TInterface::transit_vol(int pile_num)
{
    bool all_dealt_flag = true;
    rack_control->output->setText("");
    Volume* popped = piles[pile_num].pop();
    piles[pile_num].get_size()--;
    Volume* temp = new Volume(popped->get_width());
    for (Pile pile: piles)
    {
        if (pile.get_size() != 0)
            all_dealt_flag = false;
    }
    for (Shelf &shelf : shelves)
    {
        if (shelf.get_width() + temp->get_width() <= shelf.get_max_width())
        {
            temp->set_is_lying(false);
            shelf.add(temp);
            if (all_dealt_flag)
                rack_control->output->setText("Все тома разложены");
            delete popped;
            break;
        }
        else
        {
            QString s = rack_control->output->text();
            s += "Полка ";
            s += QString().setNum(shelf.get_pos());
            s += " заполнена    ";
            if (shelf.get_pos() == 2)
                s += "\n";
            rack_control->output->setText(s);
            if (shelf.get_pos() == shelves.size() + 1)
            {
                piles[pile_num].push(temp);
                piles[pile_num].get_size()++;
                delete temp;
            }
        }
    }
    update_pic();
}

void TInterface::update_pic()
{
    table->update();
    table->QGraphicsView::viewport()->update();
    rack->update();

    for (Pile &pile : piles)
        table_visual->draw_pile(pile);

    for (Shelf &shelf : shelves)
        rack_visual->draw_shelf(shelf);
}

TInterface::~TInterface()
{
    delete param_window;
}
