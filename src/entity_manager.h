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
        void create_entity(int entity_race, int x_position, int y_position);
        bool bounding_box_collide(std::shared_ptr<BoundingBox> first_box, std::shared_ptr<BoundingBox> second_box);
        bool bounding_box_collide_horizontal(std::shared_ptr<BoundingBox> first_box, std::shared_ptr<BoundingBox> second_box);
        bool bounding_box_collide_vertical(std::shared_ptr<BoundingBox> first_box, std::shared_ptr<BoundingBox> second_box);
        void update_entity(std::shared_ptr<Entity> entity);
        bool allow_collision(int first_entity_class, int second_entity_class);
    private:
        std::list<std::shared_ptr<Entity>> entity_list;
        std::unique_ptr<EntityFactory> entity_factory; 
};

#endif