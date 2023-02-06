#ifndef ENTITYMANAGER_H
#define ENTITYMANAGER_H

#include <memory>
#include <list>

#include "entity.h"
#include "player.h"
#include "enemy.h"
#include "entity_factory.h"

class EntityManager {
    public:
        EntityManager();
        ~EntityManager();
        // void create_entity(int entity_type);
        void update_entities();
        void handle_command(int command);
        void create_player();
        void create_enemy(int entity_type);
    private:
        // std::list<std::shared_ptr<Entity>> entity_list;
        std::list<std::shared_ptr<Player>> player_list;
        std::list<std::shared_ptr<Enemy>> enemy_list;
        // std::shared_ptr<Player> p_player;
        std::unique_ptr<EntityFactory> entity_factory; 
};

#endif