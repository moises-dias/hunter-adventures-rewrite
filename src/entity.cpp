#include "entity.h"

#include <memory>
#include <iostream>

Entity::Entity() {
    std::cout << "Entity()" << "\n";
}

// Entity::Entity(int entity_type, std::shared_ptr<EntityFlyweight> entity_flyweight) {
//     std::cout << "initing entity" << "\n";
//     this->entity_type = entity_type;

//     // TODO: loading the player image hardcoded, should load the correct image from the concrete entities
//     sprite = *entity_flyweight->get_image(PLAYER_IMAGE);

//     position = std::make_unique<Coordinates>(100, 100);
//     velocity = std::make_unique<Coordinates>(0, 0);
//     acceleration = std::make_unique<Coordinates>(0, 0);
// }

Entity::~Entity() {
    std::cout << "~Entity()" << "\n";
}

void Entity::draw_sprite() {
    // TODO: who should be responsible for drawing? the player? game? or another class?
    //      there is a lot of information related to drawing:
    //      current frame, number os seconds in a frame etc
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
    al_draw_tinted_bitmap_region(sprite, color, 0,0,191,161, position->get_x(), position->get_y(), 0);
}


void Entity::handle_command(int command) {
    if(command == ALLEGRO_KEY_RIGHT) {
        acceleration->update_x(0.05);
    }
    else if (command == ALLEGRO_KEY_LEFT) {
        acceleration->update_x(-0.05);
    }
    else if (command == ALLEGRO_KEY_UP) {
        acceleration->update_y(-0.05);
    }
    else if (command == ALLEGRO_KEY_DOWN) {
        acceleration->update_y(0.05);
    }
}

void Entity::update_movement() {
    *velocity += *acceleration;
    *position += *velocity;
    // std::cout << "position ";
    // position->print_coordinates();
    // std::cout << "velocity ";
    // velocity->print_coordinates();
    // std::cout << "acceleration ";
    // acceleration->print_coordinates();
}
void Entity::update() {
    update_movement();
    draw_sprite();
}