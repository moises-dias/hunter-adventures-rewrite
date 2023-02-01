#include "entitymanager.h"

#include <iostream>

EntityManager::EntityManager() {
    std::cout << "initing EntityManager" << "\n";
    entityFactory = std::make_unique<EntityFactory>();
}
EntityManager::~EntityManager() {
    std::cout << "finishing EntityManager" << "\n";

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