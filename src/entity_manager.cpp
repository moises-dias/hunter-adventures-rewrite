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
        create_projectile(i_player->get_projectile_to_create());
            i_player->set_projectile_to_create(-1);
        }
    }

    for(auto&& i_enemy : enemy_list) {
        i_enemy->update();
        if (i_enemy->get_projectile_to_create() != -1) {
        create_projectile(i_enemy->get_projectile_to_create());
            i_enemy->set_projectile_to_create(-1);
        }
    }

    for(auto&& i_projectile : projectile_list) {
        i_projectile->update();
        if (i_projectile->get_projectile_to_create() != -1) {
        create_projectile(i_projectile->get_projectile_to_create());
            i_projectile->set_projectile_to_create(-1);
        }
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

void EntityManager::create_enemy(int entity_race) {
    entity_factory->populate_enemy(enemy_list, entity_race);
}

void EntityManager::create_projectile(int entity_race) {
    std::cout << "creating a projectile" << "\n";
    entity_factory->populate_projectile(projectile_list, entity_race);
}