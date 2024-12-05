#ifndef SHELF_H
#define SHELF_H

#include <QList>
#include <volume.h>

class Shelf : public QList<Volume*>
{
    int width;
    int pos;
    int size;
public:
    Shelf();
    Shelf(int, int);
    int& get_size();
public slots:
    void catch_volume(Volume*);
};

#endif // SHELF_H
