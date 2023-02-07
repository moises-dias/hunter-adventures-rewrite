#ifndef ENTITYMANAGER_H
#define ENTITYMANAGER_H

#include <memory>
#include <list>

#include "entity.h"
#include "player.h"
#include "enemy.h"
#include "projectile.h"
#include "entity_factory.h"

class EntityManager {
    public:
        EntityManager();
        ~EntityManager();
        void update_entities();
        void collide_entities();
        void handle_command(int command);
        void create_player(int x_position, int y_position);
        void create_enemy(int entity_race, int x_position, int y_position);
        void create_projectile(int entity_race, int x_position, int y_position);
        bool bounding_box_collide(std::shared_ptr<BoundingBox> first_box, std::shared_ptr<BoundingBox> second_box);
    private:
        std::list<std::shared_ptr<Player>> player_list;
        std::list<std::shared_ptr<Projectile>> projectile_list;
        std::list<std::shared_ptr<Enemy>> enemy_list;
        std::unique_ptr<EntityFactory> entity_factory; 
};

#endif