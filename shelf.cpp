#include "shelf.h"

Shelf::Shelf() : width(0), pos(0), size(0) {};

Shelf::Shelf(int _width, int _pos) : width(_width), pos(_pos), size(0) {};

int& Shelf::get_size()
{
    return size;
}
