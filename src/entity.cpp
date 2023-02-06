#include "entity.h"

#include <memory>
#include <iostream>

Entity::Entity() {
    std::cout << "Entity()" << "\n";
}

Entity::~Entity() {
    std::cout << "~Entity()" << "\n";
}

void Entity::draw_sprite() {
    // TODO: who should be responsible for drawing? the player? game? or another class?
    //      there is a lot of information related to drawing:
    //      current frame, number os seconds in a frame etc

    // TODO: remove this color used on debug at the first steps of the project
    auto color = al_map_rgba(255, 255, 255, 255);
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
}
void Entity::update() {
    update_movement();
    draw_sprite();
}