#ifndef PILE_H
#define PILE_H

#include <QStack>
#include <volume.h>

class Pile : public QStack<Volume*>
{
    int size;
    unsigned short table_pos;
    unsigned short min_width;
    unsigned short max_width;
public:
    Pile(unsigned short, unsigned short, unsigned short);
    int& get_size();
    int get_table_pos();
    int count_total_width();
    void add_new();
};

#endif // PILE_H
