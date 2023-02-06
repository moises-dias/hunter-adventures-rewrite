#include "entity_manager.h"

#include <iostream>

EntityManager::EntityManager() {
    std::cout << "EntityManager()" << "\n";
    entity_factory = std::make_unique<EntityFactory>();

}
EntityManager::~EntityManager() {
    std::cout << "~EntityManager()" << "\n";

}

void EntityManager::update_entities(){
    for(auto&& i_player : player_list) {
        i_player->update();
    }

    for(auto&& i_enemy : enemy_list) {
        i_enemy->update();
    }
}

void EntityManager::handle_command(int command){
    for(auto&& i_player : player_list) {
        i_player->handle_command(command);
    }
}

void EntityManager::create_player() {
    entity_factory->populate_player(player_list);
}

void EntityManager::create_enemy(int entity_type) {
    entity_factory->populate_enemy(enemy_list, entity_type);
}