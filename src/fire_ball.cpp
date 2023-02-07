#include "fire_ball.h"

#include <iostream>

FireBall::FireBall() {
    std::cout << "FireBall()" << "\n";
}

FireBall::FireBall(std::shared_ptr<EntityFlyweight> entity_flyweight) {
    std::cout << "FireBall(entity_flyweight)" << "\n";
    
    sprite = *entity_flyweight->get_image(FIRE_BALL_IMAGE);

    entity_class = PLAYER_PROJECTILE;
    entity_race = FIRE_BALL;

}

FireBall::~FireBall() {
    std::cout << "~FireBall()" << "\n";
}