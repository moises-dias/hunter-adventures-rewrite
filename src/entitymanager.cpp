#include "entitymanager.h"

EntityManager::EntityManager() {

}
EntityManager::~EntityManager() {

}
void EntityManager::addEntity(int entity_type){
    entityList.push_back(std::make_unique<Entity>(entity_type));
}
void EntityManager::updateEntities(){
    for(auto&& iteratorEntity : entityList) {
        iteratorEntity->draw_sprite();
    }
}