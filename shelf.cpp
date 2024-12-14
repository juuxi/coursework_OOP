#include "shelf.h"

Shelf::Shelf() : width(0), pos(0), size(0) {};

Shelf::Shelf(int _max_width, int _pos) : max_width(_max_width), width(0), pos(_pos), size(0) {};

void Shelf::add(Volume* vol)
{
    push_back(vol);
    width += vol->get_width();
    size++;
}

int Shelf::get_size()
{
    return size;
}

int Shelf::get_width()
{
    return width;
}

int Shelf::get_max_width()
{
    return max_width;
}

int Shelf::get_pos()
{
    return pos;
}
