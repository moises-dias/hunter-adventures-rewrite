#include "slime.h"

#include <iostream>

Slime::Slime() {
    std::cout << "Slime()" << "\n";
}

Slime::Slime(std::shared_ptr<EntityFlyweight> entity_flyweight) {
    std::cout << "Slime(entity_flyweight)" << "\n";
    
    this->entity_type = entity_type;

    sprite = *entity_flyweight->get_image(DRAGON_IMAGE);

    position = std::make_unique<Coordinates>(100, 100);
    velocity = std::make_unique<Coordinates>(0, 0);
    acceleration = std::make_unique<Coordinates>(0, 0);
}

Slime::~Slime() {
    std::cout << "~Slime()" << "\n";
}