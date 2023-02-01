#include "entitymanager.h"

EntityManager::EntityManager() {
    entityFactory = std::make_unique<EntityFactory>();
}
EntityManager::~EntityManager() {

}

void EntityManager::createEntity(int entity_type){
    entityList.push_back(
        entityFactory->createEntity(entity_type)
    );
}

void EntityManager::updateEntities(){
    for(auto&& iteratorEntity : entityList) {
        iteratorEntity->draw_sprite();
    }
}