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

void EntityManager::collide_entities(){
    for(auto&& i_player : player_list) {
        for(auto&& i_enemy : enemy_list) {
            if (bounding_box_collide(i_player->get_bounding_box(), i_enemy->get_bounding_box())) {
                std::cout << "collide" << "\n";
            }
        }
    }   
}

bool EntityManager::bounding_box_collide(std::shared_ptr<BoundingBox> first_box, std::shared_ptr<BoundingBox> second_box) {
    // TODO break into two functinos vertical and horizontal
    std::shared_ptr<BoundingBox> left_box;
    std::shared_ptr<BoundingBox> right_box;
    std::shared_ptr<BoundingBox> upper_box;
    std::shared_ptr<BoundingBox> lower_box;

    if (first_box->get_x() < second_box->get_x()) {
        left_box = first_box;
        right_box = second_box;
    }
    else {
        left_box = second_box;
        right_box = first_box;
    }

    if (first_box->get_y() < second_box->get_y()) {
        upper_box = first_box;
        lower_box = second_box;
    }
    else {
        upper_box = second_box;
        lower_box = first_box;
    }

    bool collide_vertical = (right_box->get_x() + right_box->get_width() - left_box->get_x() < right_box->get_width() + left_box->get_width());

    bool collide_horizontal = (lower_box->get_y() + lower_box->get_height() - upper_box->get_y() < lower_box->get_height() + upper_box->get_height());

    return collide_vertical && collide_horizontal;
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