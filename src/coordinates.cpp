#include "coordinates.h"

#include <iostream>

Coordinates::Coordinates() {
    std::cout << "Coordinates()" << "\n"; 
}

Coordinates::Coordinates(float x, float y) {
    std::cout << "Coordinates(x, y)" << "\n"; 
    this->x = x;
    this->y = y;
}


Coordinates::~Coordinates() {
    std::cout << "~Coordinates()" << "\n"; 

}

void Coordinates::print_coordinates() {
    std::cout << "(" << x << ", " << y << ")" << "\n"; 
}

float Coordinates::get_x() {
     return x;
}

float Coordinates::get_y() {
     return y;
}

void Coordinates::operator+=(Coordinates& coordinates) {
    this->x += coordinates.get_x();
    this->y += coordinates.get_y();
}

void Coordinates::set_x(float new_x){
    x = new_x;
}
void Coordinates::set_y(float new_y){
    y = new_y;
}
void Coordinates::update_x(float x){
    this->x += x;
}
void Coordinates::update_y(float y){
    this->y += y;
}