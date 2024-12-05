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
    Pile(int, unsigned short, unsigned short);
    int& get_size();
    int get_table_pos();
signals:
    void throw_volume();
};

#endif // PILE_H
