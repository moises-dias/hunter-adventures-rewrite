#include "entity.h"

#include <memory>
#include <iostream>

Entity::Entity() {
    std::cout << "Entity()" << "\n";

    projectile_to_create = -1;
    // TODO where to init bounding box values?
    bounding_box = std::make_shared<BoundingBox>(200, 200, 200, 200);
}

Entity::~Entity() {
    std::cout << "~Entity()" << "\n";
}

void Entity::draw_sprite() {
    // TODO: who should be responsible for drawing? the player? game? or another class?
    //      there is a lot of information related to drawing:
    //      current frame, number os seconds in a frame etc


    // TODO: update hardcoded 191 and 161 values from initial project example
    al_draw_bitmap_region(sprite, 0,0,191,161, position->get_x(), position->get_y(), 0);
}

void Entity::update_movement() {
    *velocity += *acceleration;
    *position += *velocity;
}
void Entity::update() {
    update_movement();
    draw_sprite();
    // TODO set the initial values of bounding box with the initial value of the entity
    // TODO create method for updating bounding box
    bounding_box->set_x(position->get_x());
    bounding_box->set_y(position->get_y());
    bounding_box->draw();
}

void Entity::init_position() {
    position = std::make_unique<Coordinates>(100, 100);
    velocity = std::make_unique<Coordinates>(0, 0);
    acceleration = std::make_unique<Coordinates>(0, 0);
}

void Entity::init_position(float x_position, float y_position) {

    bounding_box->set_x(x_position);
    bounding_box->set_y(y_position);

    position = std::make_unique<Coordinates>(x_position, y_position);
    velocity = std::make_unique<Coordinates>(0, 0);
    acceleration = std::make_unique<Coordinates>(0, 0);
}

void Entity::set_projectile_to_create(int projectile_to_create) {
    this->projectile_to_create = projectile_to_create;
}

int Entity::get_projectile_to_create() {
    return projectile_to_create;
}

float Entity::get_x() {
    return position->get_x();
}

float Entity::get_y() {
    return position->get_y();
}

std::shared_ptr<BoundingBox> Entity::get_bounding_box() {
    return this->bounding_box;
}
