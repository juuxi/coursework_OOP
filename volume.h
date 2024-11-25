#ifndef VOLUME_H
#define VOLUME_H


class Volume
{
    int width;
    int height;
    int length;
public:
    Volume();

    int get_width();
    int get_height();
    int get_length();

    void set_width(int);
    void set_height(int);
    void set_length(int);
};

#endif // VOLUME_H
