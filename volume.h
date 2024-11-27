#ifndef VOLUME_H
#define VOLUME_H

#include <QGraphicsItem>
#include <QPainter>

class Volume : public QGraphicsItem
{
    int width;
    int height;
    int length;
public:
    Volume();
    QRectF boundingRect() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option,
                  QWidget *widget) override;

    int get_width();
    int get_height();
    int get_length();

    void set_width(int);
    void set_height(int);
    void set_length(int);
};

#endif // VOLUME_H
