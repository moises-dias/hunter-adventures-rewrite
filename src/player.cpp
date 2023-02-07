#include "player.h"

#include <iostream>

Player::Player() {
    std::cout << "Player()" << "\n";
}

Player::Player(std::shared_ptr<EntityFlyweight> entity_flyweight) {
    std::cout << "Player(entity_flyweight)" << "\n";

    //TODO create methods for initing image and coordinates
    sprite = *entity_flyweight->get_image(PLAYER_IMAGE);

}

Player::~Player() {
    std::cout << "~Player()" << "\n";
}

void Player::handle_command(int command) {
    // TODO think of a better structure to this key handle
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
    else if (command == ALLEGRO_KEY_P) {
        this->projectile_to_create = FIRE_BALL;
    }
}