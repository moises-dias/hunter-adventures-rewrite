#ifndef COORDINATES_H
#define COORDINATES_H

class Coordinates {
    public:
        Coordinates();
        Coordinates(float x, float y);
        ~Coordinates();
        void print_coordinates();
        float get_x();
        float get_y();
        void set_x(float new_x);
        void set_y(float new_y);
        void update_x(float x);
        void update_y(float y);
        void operator+=(Coordinates& coordinates);
    private:
        float x;
        float y;
};

#endif