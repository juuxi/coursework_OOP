#include "volume.h"

Volume::Volume()
{
    width = 0;
    height = 0;
    length = 0;
}

int Volume::get_width()
{
    return width;
}

int Volume::get_height()
{
    return height;
}

int Volume::get_length()
{
    return length;
}

void Volume::set_width(int _width)
{
    width = _width;
}

void Volume::set_height(int _height)
{
    height = _height;
}

void Volume::set_length(int _length)
{
    length = _length;
}
