#include "player.h"

#include <iostream>

Player::Player() {

}

Player::Player(std::shared_ptr<EntityFlyweight> entity_flyweight) {
    std::cout << "initing entity" << "\n";
    this->entity_type = entity_type;

    // TODO: loading the player image hardcoded, should load the correct image from the concrete entities
    sprite = *entity_flyweight->get_image(PLAYER_IMAGE);

    position = std::make_unique<Coordinates>(100, 100);
    velocity = std::make_unique<Coordinates>(0, 0);
    acceleration = std::make_unique<Coordinates>(0, 0);
}

Player::~Player() {
    
}