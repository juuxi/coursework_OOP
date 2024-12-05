#ifndef SHELF_H
#define SHELF_H

#include <QList>
#include <volume.h>

class Shelf : public QList<Volume*>
{
    int width;
    int pos;
public:
    Shelf();
    Shelf(int, int);
};

#endif // SHELF_H
