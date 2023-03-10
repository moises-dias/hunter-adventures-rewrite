#ifndef ENTITY_H
#define ENTITY_H

#include <string>
#include <vector>

#include <allegro5/allegro.h>

#include "entity_flyweight.h"
#include "coordinates.h"
#include "bounding_box.h"

// TODO: where to store this vector? not in entity, enemies does not need to know it
const std::vector<int> COMMAND_KEYS = {
    ALLEGRO_KEY_RIGHT, 
    ALLEGRO_KEY_LEFT, 
    ALLEGRO_KEY_UP, 
    ALLEGRO_KEY_DOWN,
    ALLEGRO_KEY_P
};

enum ENTITY_CLASS {PLAYER, ENEMY, PLAYER_PROJECTILE, ENEMY_PROJECTILE, PLATFORM};
enum ENTITY_RACE {WARRIOR, SLIME, DRAGON, FIRE_BALL};

// TODO: turn entity into a interface
class Entity {
    public:
        Entity();
        ~Entity();
        void draw_sprite();
        void update_movement();
        void update();
        void init_position();
        void init_position(float x_position, float y_position);
        int get_projectile_to_create();
        void set_projectile_to_create(int projectile_to_create);
        float get_x();
        float get_y();
        int get_entity_class();
        std::shared_ptr<BoundingBox> get_bounding_box();

    protected:
        std::unique_ptr<Coordinates> position;
        std::unique_ptr<Coordinates> velocity;
        std::unique_ptr<Coordinates> acceleration;

        int projectile_to_create;
        int entity_class;
        int entity_race;

        ALLEGRO_BITMAP* sprite;
        std::shared_ptr<BoundingBox> bounding_box;
};

#endif