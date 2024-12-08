#include "pile.h"

Pile::Pile(int _size, unsigned short _min_width, unsigned short _max_width)
{
    size = _size;
    min_width = _min_width;
    max_width = _max_width;
    table_pos = 10;
    for (int i = 0; i < size; i++)
    {
        int curr_width = (i % (max_width - min_width)) + min_width; //ширина всегда будет в нужном диапазоне
        Volume* curr = new Volume(curr_width);
        push(curr);
    }
}

int& Pile::get_size()
{
    return size;
}

int Pile::get_table_pos()
{
    return table_pos;
}
