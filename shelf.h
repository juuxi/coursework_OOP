#ifndef SHELF_H
#define SHELF_H

#include <QList>
#include <volume.h>

class Shelf : public QList<Volume*>
{
    int max_width;
    int width;
    int pos;
    int size;
public:
    Shelf();
    Shelf(int, int);
    int get_width();
    int get_size();
    int get_pos();
    int get_max_width();
    void add(Volume* vol);
};

#endif // SHELF_H
