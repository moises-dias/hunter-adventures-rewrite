#ifndef PLAYER_H
#define PLAYER_H

#include <string>
#include <vector>

#include <allegro5/allegro.h>

class Player {
    public:
        Player();
        ~Player();
        void draw_sprite();
        void update_x_position(int value);
        void update_y_position(int value);
        void update_position(std::vector<int>);
    private:
        int x_position;
        int y_position;

        std::string sprite_path;

        ALLEGRO_BITMAP* sprite;
};

#endif