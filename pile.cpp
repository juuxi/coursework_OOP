#include "pile.h"

Pile::Pile(unsigned short _min_width, unsigned short _max_width, unsigned short _pos)
{
    size = 0;
    min_width = _min_width;
    max_width = _max_width;
    table_pos = 10 + 100 * _pos;
}

int& Pile::get_size()
{
    return size;
}

int Pile::get_table_pos()
{
    return table_pos;
}

int Pile::count_total_width()
{
    int sum = 0;
    QStack<Volume*> temp;
    for (int i = 0; i < size; i++)
    {
        temp.push(this->pop());
        sum += temp.top()->get_width();
    }
    for (int i = 0; i < size; i++)
        this->push(temp.pop());
    return sum;
}

void Pile::add_new(int _height, int _length)
{
    int curr_width = (rand() % (max_width - min_width + 1)) + min_width; //ширина всегда будет в нужном диапазоне
    Volume* curr = new Volume(curr_width, _height, _length);
    push(curr);
    size++;
}
