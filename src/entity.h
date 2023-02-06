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

// TODO: make sure that type and class are not being mixed up
enum ENTITY_CLASS {PLAYER, ENEMY, PLAYER_PROJECTILE, ENEMY_PROJECTILE, PLATFORM};
enum ENTITY_RACE {SLIME};

// TODO: turn entity into a interface
class Entity {
    public:
        // TODO reference to flyweight would be better than a shared_ptr?
        Entity();
        // Entity(int entity_type, std::shared_ptr<EntityFlyweight> entity_flyweight);
        ~Entity();
        void draw_sprite();
        void update_movement();
        void update();
        // TODO create player class, this method is related only to the player
        void handle_command(int command);

    // TODO: check if all variables should be protected or some should be private
    protected:
        std::unique_ptr<Coordinates> position;
        std::unique_ptr<Coordinates> velocity;
        std::unique_ptr<Coordinates> acceleration;

        ALLEGRO_BITMAP* sprite;
};

#endif