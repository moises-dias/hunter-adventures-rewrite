#ifndef ENTITY_H
#define ENTITY_H

#include <string>
#include <vector>

#include <allegro5/allegro.h>

enum ENTITY_TYPE {PLAYER, ENEMY, PLAYER_PROJECTILE, ENEMY_PROJECTILE, PLATFORM};

class Entity {
    public:
        Entity(int entity_type);
        ~Entity();
        void draw_sprite();
        void update_position(std::vector<int>);
    private:
        int x_position;
        int y_position;
        int entity_type;

        std::string sprite_path;

        ALLEGRO_BITMAP* sprite;
};

#endif