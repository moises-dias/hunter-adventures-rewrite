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

enum ENTITY_TYPE {PLAYER, ENEMY, PLAYER_PROJECTILE, ENEMY_PROJECTILE, PLATFORM};

class Entity {
    public:
        Entity(int entity_type, std::shared_ptr<EntityFlyweight> entity_flyweight);
        ~Entity();
        void draw_sprite();
        void update_movement();
        void update();
        // TODO create player class, this method is related only to the player
        void handle_command(int command);

    private:
        int entity_type;

        std::unique_ptr<Coordinates> position;
        std::unique_ptr<Coordinates> velocity;
        std::unique_ptr<Coordinates> acceleration;

        std::string sprite_path;

        ALLEGRO_BITMAP* sprite;
};

#endif