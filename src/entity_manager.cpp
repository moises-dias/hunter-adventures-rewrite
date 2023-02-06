#include "entity_manager.h"

#include <iostream>

EntityManager::EntityManager() {
    std::cout << "initing EntityManager" << "\n";
    entity_factory = std::make_unique<EntityFactory>();

}
EntityManager::~EntityManager() {
    std::cout << "finishing EntityManager" << "\n";

}

// void EntityManager::create_entity(int entity_type){
//     auto new_entity = entity_factory->create_entity(entity_type);
    
//     entity_list.push_back(new_entity);

//     if (entity_type == PLAYER) {
//         p_player = new_entity;
//     }
// }

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
    // p_player->handle_command(command);
    // std::cout << "command" << "\n";
    // how to pass the command to the player?
    //      new pointer of class player?
    //      set velocity, position and acceleration on entity?
}

void EntityManager::create_player() {
    // auto new_player = entity_factory->create_player();
    // player_list.push_back(new_player);

    entity_factory->populate_player(player_list);
}

void EntityManager::create_enemy(int entity_type) {

    // TODO EM PORTUGUES MSM
    // NO LUGAR DA FACTORY RETORNAR, MANDA A LISTA PRA ELA E ELA POPULA
    // DAI TODAS AS FUNCTIONS RETORNA VOID


    // auto new_enemy = entity_factory->create_enemy(entity_type);
    // enemy_list.push_back(new_enemy);

    entity_factory->populate_enemy(enemy_list, entity_type);
}