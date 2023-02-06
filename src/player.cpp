#include "player.h"

#include <iostream>

Player::Player() {
    std::cout << "Player()" << "\n";
}

Player::Player(std::shared_ptr<EntityFlyweight> entity_flyweight) {
    std::cout << "Player(entity_flyweight)" << "\n";

    //TODO create methods for initing image and coordinates
    sprite = *entity_flyweight->get_image(PLAYER_IMAGE);

    init_position();
}

Player::~Player() {
    std::cout << "~Player()" << "\n";
}