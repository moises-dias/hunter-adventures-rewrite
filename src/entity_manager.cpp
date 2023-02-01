#include "entity_manager.h"

#include <iostream>

EntityManager::EntityManager() {
    std::cout << "initing EntityManager" << "\n";
    entity_factory = std::make_unique<EntityFactory>();
}
EntityManager::~EntityManager() {
    std::cout << "finishing EntityManager" << "\n";

}

void EntityManager::create_entity(int entity_type){
    entity_list.push_back(
        entity_factory->create_entity(entity_type)
    );
}

void EntityManager::update_entities(){
    for(auto&& iterator_entity : entity_list) {
        iterator_entity->draw_sprite();
    }
}