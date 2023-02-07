#ifndef BOUNDINGBOX_H
#define BOUNDINGBOX_H

#include <allegro5/allegro.h>

class BoundingBox {
    public:
        BoundingBox();
        BoundingBox(int x, int y, int width, int height);
        ~BoundingBox();
        void draw();
        void set_x(int x);
        void set_y(int y);
        int get_x();
        int get_y();
        int get_width();
        int get_height();

    private:
        int x;
        int y;
        int width;
        int height;
};

#endif