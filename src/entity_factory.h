#ifndef ENTITYFACTORY_H
#define ENTITYFACTORY_H

#include <memory>
#include <list>

#include "entity_flyweight.h"
#include "entity.h"

class EntityFactory {
    public:
        EntityFactory();
        ~EntityFactory();
        std::unique_ptr<Entity> create_entity(int entity_type);
    private:
        std::shared_ptr<EntityFlyweight> entity_flyweight;
        
};

#endif