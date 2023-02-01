#ifndef ENTITYMANAGER_H
#define ENTITYMANAGER_H

#include <memory>
#include <list>

#include "entity.h"
#include "entity_factory.h"

class EntityManager {
    public:
        EntityManager();
        ~EntityManager();
        void create_entity(int entity_type);
        void update_entities();
    private:
        std::list<std::unique_ptr<Entity>> entity_list;
        std::unique_ptr<EntityFactory> entity_factory; 
        
};

#endif