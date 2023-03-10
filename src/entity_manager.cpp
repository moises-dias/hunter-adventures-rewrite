#include "entity_manager.h"

#include <iostream>

EntityManager::EntityManager() {
    std::cout << "EntityManager()" << "\n";
    entity_factory = std::make_unique<EntityFactory>();

}
EntityManager::~EntityManager() {
    std::cout << "~EntityManager()" << "\n";

}

void EntityManager::update_entity(std::shared_ptr<Entity> entity) {
    entity->update();
    if (entity->get_projectile_to_create() != -1) {
    create_entity(entity->get_projectile_to_create(), entity->get_x(), entity->get_y());
        entity->set_projectile_to_create(-1);
    }
}

void EntityManager::update_entities(){
    for(auto&& i_entity : entity_list) {
        update_entity(i_entity);
    }
}

bool EntityManager::allow_collision(int first_entity_class, int second_entity_class) {
    if (
        (first_entity_class == second_entity_class) ||
        (first_entity_class == PLAYER && second_entity_class == PLAYER_PROJECTILE) ||
        (first_entity_class == PLAYER_PROJECTILE && second_entity_class == PLAYER) ||
        (first_entity_class == ENEMY && second_entity_class == ENEMY_PROJECTILE) ||
        (first_entity_class == ENEMY_PROJECTILE && second_entity_class == ENEMY)
    ) {
        return false;
    }
    else {
        return true;
    }
}

void EntityManager::collide_entities(){
    // TODO consider if one list of entities would be enough, as i cant cast list<X> to list<Y>

    for (auto i_first_entity = entity_list.begin(); i_first_entity != entity_list.end(); ++i_first_entity) {
        for (auto i_second_entity = std::next(i_first_entity, 1); i_second_entity != entity_list.end(); ++i_second_entity) {
            if (!allow_collision((*i_first_entity)->get_entity_class(), (*i_second_entity)->get_entity_class())) {
                continue;
            }
            if (bounding_box_collide((*i_first_entity)->get_bounding_box(), (*i_second_entity)->get_bounding_box())) {
                std::cout << "collide" << "\n";
            }
        }
    }
}

bool EntityManager::bounding_box_collide(std::shared_ptr<BoundingBox> first_box, std::shared_ptr<BoundingBox> second_box) {

    bool collide_vertical = bounding_box_collide_vertical(first_box, second_box);;
    bool collide_horizontal = bounding_box_collide_horizontal(first_box, second_box);

    return collide_vertical && collide_horizontal;
}

bool EntityManager::bounding_box_collide_horizontal(std::shared_ptr<BoundingBox> first_box, std::shared_ptr<BoundingBox> second_box) {
    std::shared_ptr<BoundingBox> upper_box;
    std::shared_ptr<BoundingBox> lower_box;

    if (first_box->get_y() < second_box->get_y()) {
        upper_box = first_box;
        lower_box = second_box;
    }
    else {
        upper_box = second_box;
        lower_box = first_box;
    }

    return (lower_box->get_y() + lower_box->get_height() - upper_box->get_y() < lower_box->get_height() + upper_box->get_height());
}

bool EntityManager::bounding_box_collide_vertical(std::shared_ptr<BoundingBox> first_box, std::shared_ptr<BoundingBox> second_box) {
    std::shared_ptr<BoundingBox> left_box;
    std::shared_ptr<BoundingBox> right_box;

    if (first_box->get_x() < second_box->get_x()) {
        left_box = first_box;
        right_box = second_box;
    }
    else {
        left_box = second_box;
        right_box = first_box;
    }

    return (right_box->get_x() + right_box->get_width() - left_box->get_x() < right_box->get_width() + left_box->get_width());
}

void EntityManager::handle_command(int command){
    for(auto&& i_entity : entity_list) {
        if (i_entity->get_entity_class() == PLAYER) {
            auto i_player = std::static_pointer_cast<Player> (i_entity);
            i_player->handle_command(command);
        }
    }
}

void EntityManager::create_entity(int entity_race, int x_position, int y_position) {
    entity_factory->populate_entity(entity_list, entity_race);
    entity_list.back()->init_position(x_position, y_position);
}
