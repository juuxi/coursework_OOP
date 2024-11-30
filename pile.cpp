#include "pile.h"

Pile::Pile(int _size)
{
    size = _size;
    int min_width = 10;
    int max_width = 20;
    table_pos = 10;
    for (int i = 0; i < size; i++)
    {
        int curr_width = (i % (max_width - min_width)) + min_width; //ширина всегда будет в нужном диапазоне
        Volume* curr = new Volume(curr_width);
        push(curr);
    }
}

int Pile::get_size()
{
    return size;
}

int Pile::get_table_pos()
{
    return table_pos;
}
