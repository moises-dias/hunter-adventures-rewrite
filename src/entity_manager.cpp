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
        if (i_player->get_projectile_to_create() != -1) {
        create_projectile(i_player->get_projectile_to_create(), i_player->get_x(), i_player->get_y());
            i_player->set_projectile_to_create(-1);
        }
    }

    for(auto&& i_enemy : enemy_list) {
        i_enemy->update();
        if (i_enemy->get_projectile_to_create() != -1) {
        create_projectile(i_enemy->get_projectile_to_create(), i_enemy->get_x(), i_enemy->get_y());
            i_enemy->set_projectile_to_create(-1);
        }
    }

    for(auto&& i_projectile : projectile_list) {
        i_projectile->update();
        if (i_projectile->get_projectile_to_create() != -1) {
        create_projectile(i_projectile->get_projectile_to_create(), i_projectile->get_x(), i_projectile->get_y());
            i_projectile->set_projectile_to_create(-1);
        }
    }
}

void EntityManager::handle_command(int command){
    for(auto&& i_player : player_list) {
        i_player->handle_command(command);
    }
}

void EntityManager::create_player(int x_position, int y_position) {
    // TODO instead of sendind x and y for a lot of funcitons
    //      create without sending x and y and update the last element
    //      used on the push_back
    entity_factory->populate_player(player_list);
    player_list.back()->init_position(x_position, y_position);
}

void EntityManager::create_enemy(int entity_race, int x_position, int y_position) {
    entity_factory->populate_enemy(enemy_list, entity_race);
    enemy_list.back()->init_position(x_position, y_position);
}

void EntityManager::create_projectile(int entity_race, int x_position, int y_position) {
    std::cout << "creating a projectile" << "\n";
    entity_factory->populate_projectile(projectile_list, entity_race);
    projectile_list.back()->init_position(x_position, y_position);
}