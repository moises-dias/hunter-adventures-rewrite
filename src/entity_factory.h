#ifndef ENTITYFACTORY_H
#define ENTITYFACTORY_H

#include <memory>
#include <list>
#include <functional>

#include "entity_flyweight.h"
#include "enemy.h"
#include "player.h"
#include "slime.h"
#include "dragon.h"
#include "fire_ball.h"

class EntityFactory {
    public:
        EntityFactory();
        ~EntityFactory();
        void populate_entity(std::list<std::shared_ptr<Entity>>& entity_list, int entity_race);
    private:
        std::shared_ptr<EntityFlyweight> entity_flyweight;
        std::map<int, std::function<void (std::list<std::shared_ptr<Entity>>&, std::shared_ptr<EntityFlyweight>&)>> add_entity_to_list;
        
};

#endif