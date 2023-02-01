#include "entity.h"

#include <memory>
#include <iostream>

Entity::Entity(int entity_type, std::shared_ptr<EntityFlyweight> entityFlyweight) {
    std::cout << "initing entity" << "\n";
    this->entity_type = entity_type;
    x_position = 500 - 200 * entity_type;
    y_position = 500 - 200 * entity_type;

    // sprite_path = "./data/images/dragon/dragon.png";
    // sprite = al_load_bitmap(sprite_path.c_str());
    sprite = *entityFlyweight->getImage(PLAYER_IMAGE);
}

Entity::~Entity() {
    std::cout << "finishing entity" << "\n";
    al_destroy_bitmap(sprite);
}

void Entity::draw_sprite() {
    // TODO: who should be responsible for drawing? the player? game? or another class?
    // al_draw_bitmap_region(sprite, 0, 0, 191, 161, x_position, y_position, 0);
    int r = 0;
    int g = 0;
    int b = 0;
    if (entity_type == PLAYER) {
        r = 255;
    }
    else if (entity_type == ENEMY) {
        b = 255;
    }
    auto color = al_map_rgba(r,g,b,255);
    al_draw_tinted_bitmap_region(sprite, color, 0,0,191,161, x_position, y_position, 0);
}

void Entity::update_position(std::vector<int> coordinates) {
    x_position += coordinates[0];
    y_position += coordinates[1];
}