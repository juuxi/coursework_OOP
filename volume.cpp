#include "volume.h"

Volume::Volume()
{
    width = 0;
    height = 0; //param
    length = 0; //param
    is_lying = true;
}

Volume::Volume(int _width)
{
    width = _width;
    height = 50; //param
    length = 80; //param
    is_lying = true;
}

QRectF Volume::boundingRect() const
{
    qreal penWidth = 1;
    return QRectF(-10 - penWidth / 2, -10 - penWidth / 2,
                  20 + penWidth, 20 + penWidth);
}

void Volume::paint(QPainter *painter, const QStyleOptionGraphicsItem *option,
              QWidget *widget)
{
    if (is_lying)
        painter->drawRect(10, 10, height, width);
    else
        painter->drawRect(10, 10, width, height);
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

bool Volume::get_is_lying()
{
    return is_lying;
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

void Volume::set_is_lying(bool _is_lying)
{
    is_lying = _is_lying;
}
