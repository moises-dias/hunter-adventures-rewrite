#include "player.h"

#include <iostream>

Player::Player() {
    std::cout << "Player()" << "\n";
}

Player::Player(std::shared_ptr<EntityFlyweight> entity_flyweight) {
    std::cout << "Player(entity_flyweight)" << "\n";

    this->entity_type = entity_type;

    //TODO create methods for initing image and coordinates
    sprite = *entity_flyweight->get_image(PLAYER_IMAGE);

    position = std::make_unique<Coordinates>(100, 100);
    velocity = std::make_unique<Coordinates>(0, 0);
    acceleration = std::make_unique<Coordinates>(0, 0);
}

Player::~Player() {
    std::cout << "~Player()" << "\n";
}