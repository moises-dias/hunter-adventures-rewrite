#ifndef ENTITYMANAGER_H
#define ENTITYMANAGER_H

#include <memory>
#include <list>

#include "entity.h"

class EntityManager {
    public:
        EntityManager();
        ~EntityManager();
        void addEntity(int entity_type);
        void updateEntities();
    private:
        std::list<std::unique_ptr<Entity>> entityList;
        
};

#endif