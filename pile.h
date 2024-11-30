#ifndef PILE_H
#define PILE_H

#include <QStack>
#include <volume.h>

class Pile : public QStack<Volume*>
{
    int size;
    int table_pos;
public:
    Pile(int);
    int get_size();
    int get_table_pos();
};

#endif // PILE_H
