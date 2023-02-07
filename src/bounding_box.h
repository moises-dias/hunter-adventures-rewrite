#ifndef BOUNDINGBOX_H
#define BOUNDINGBOX_H

#include <allegro5/allegro.h>

class BoundingBox {
    public:
        BoundingBox();
        BoundingBox(int x, int y, int width, int height);
        ~BoundingBox();
        void draw();

    private:
        int x;
        int y;
        int width;
        int height;
};

#endif