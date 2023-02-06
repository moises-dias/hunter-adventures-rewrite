#ifndef ENTITYFACTORY_H
#define ENTITYFACTORY_H

#include <memory>
#include <list>

#include "entity_flyweight.h"
#include "enemy.h"
#include "player.h"
#include "slime.h"

class EntityFactory {
    public:
        EntityFactory();
        ~EntityFactory();
        // std::shared_ptr<Entity> create_entity(int entity_type);
        void populate_player(std::list<std::shared_ptr<Player>>& player_list);
        void populate_enemy(std::list<std::shared_ptr<Enemy>>& enemy_list, int entity_type);
    private:
        std::shared_ptr<EntityFlyweight> entity_flyweight;
        
};

#endif