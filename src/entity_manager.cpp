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
    auto new_entity = entity_factory->create_entity(entity_type);
    
    entity_list.push_back(new_entity);

    if (entity_type == PLAYER) {
        p_player = new_entity;
    }
}

void EntityManager::update_entities(){
    for(auto&& iterator_entity : entity_list) {
        iterator_entity->draw_sprite();
    }
}

void EntityManager::handle_command(int command){
    p_player->handle_command(command);
    // how to pass the command to the player?
    //      new pointer of class player?
    //      set velocity, position and acceleration on entity?
}