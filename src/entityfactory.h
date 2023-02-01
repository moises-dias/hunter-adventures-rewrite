#ifndef ENTITYFACTORY_H
#define ENTITYFACTORY_H

#include <memory>
#include <list>

#include "entityflyweight.h"
#include "entity.h"

class EntityFactory {
    public:
        EntityFactory();
        ~EntityFactory();
        std::unique_ptr<Entity> createEntity(int entity_type);
    private:
        std::shared_ptr<EntityFlyweight> entityFlyweight;
        
};

#endif