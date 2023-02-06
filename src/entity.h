#ifndef ENTITY_H
#define ENTITY_H

#include <string>
#include <vector>

#include <allegro5/allegro.h>

#include "entity_flyweight.h"
#include "coordinates.h"

// TODO: where to store this vector? not in entity, enemies does not need to know it
const std::vector<int> COMMAND_KEYS = {
    ALLEGRO_KEY_RIGHT, 
    ALLEGRO_KEY_LEFT, 
    ALLEGRO_KEY_UP, 
    ALLEGRO_KEY_DOWN
};

enum ENTITY_CLASS {PLAYER, ENEMY, PLAYER_PROJECTILE, ENEMY_PROJECTILE, PLATFORM};
enum ENTITY_RACE {SLIME};

// TODO: turn entity into a interface
class Entity {
    public:
        Entity();
        ~Entity();
        void draw_sprite();
        void update_movement();
        void update();
        void init_position();

    protected:
        std::unique_ptr<Coordinates> position;
        std::unique_ptr<Coordinates> velocity;
        std::unique_ptr<Coordinates> acceleration;

        ALLEGRO_BITMAP* sprite;
};

#endif