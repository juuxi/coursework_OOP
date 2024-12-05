#include "shelf.h"

Shelf::Shelf() : width(0), pos(0), size(0) {};

Shelf::Shelf(int _width, int _pos) : width(_width), pos(_pos), size(0) {};

void Shelf::catch_volume(Volume* _new_vol)
{
    push_back(_new_vol);
    size++;
}

int& Shelf::get_size()
{
    return size;
}
