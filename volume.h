#ifndef VOLUME_H
#define VOLUME_H

#include <QGraphicsItem>
#include <QPainter>

class Volume : public QGraphicsItem
{
    int width;
    int height;
    int length;
    bool is_lying;
public:
    Volume();
    Volume(int);
    Volume(int, int, int);
    QRectF boundingRect() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option,
                  QWidget *widget) override;

    int get_width();
    int get_height();
    int get_length();
    bool get_is_lying();

    void set_width(int);
    void set_height(int);
    void set_length(int);
    void set_is_lying(bool);
};

#endif // VOLUME_H
