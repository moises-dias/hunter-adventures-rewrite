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

    private:
        int x;
        int y;
        int width;
        int height;
};

#endif