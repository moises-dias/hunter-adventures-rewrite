#ifndef ENTITYMANAGER_H
#define ENTITYMANAGER_H

#include <memory>
#include <list>

#include "entity.h"
#include "entityfactory.h"

class EntityManager {
    public:
        EntityManager();
        ~EntityManager();
        void createEntity(int entity_type);
        void updateEntities();
    private:
        std::list<std::unique_ptr<Entity>> entityList;
        std::unique_ptr<EntityFactory> entityFactory; 
        
};

#endif