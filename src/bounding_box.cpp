#include "bounding_box.h"

#include <iostream>

#include <allegro5/allegro_primitives.h>


BoundingBox::BoundingBox() {
    std::cout << "BoundingBox()" << "\n";
}

BoundingBox::BoundingBox(int x, int y, int width, int height) {
    std::cout << "BoundingBox(x, y, width, height)" << "\n";
    this->x = x;
    this->y = y;
    this->width = width;
    this->height = height;
}

BoundingBox::~BoundingBox() {
    std::cout << "~BoundingBox()" << "\n";

}

void BoundingBox::draw() {
    ALLEGRO_COLOR color = al_map_rgba(255,255,255,255);
    al_draw_rectangle(x, y, x + width, y + height, color, 3.0);
}

void BoundingBox::set_x(int x) {
    this->x = x;
}
void BoundingBox::set_y(int y) {
    this->y = y;
}

int BoundingBox::get_x(){
    return x;
}
int BoundingBox::get_y(){
    return y;
}
int BoundingBox::get_width(){
    return width;
}
int BoundingBox::get_height(){
    return height;
}