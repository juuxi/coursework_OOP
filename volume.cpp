#include "volume.h"

Volume::Volume()
{
    width = 0;
    height = 0;
    length = 0;
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
    painter->drawRect(10, 10, 30, 30);
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
