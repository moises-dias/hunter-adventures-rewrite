#include "slime.h"

#include <iostream>

Slime::Slime() {
    std::cout << "Slime()" << "\n";
}

Slime::Slime(std::shared_ptr<EntityFlyweight> entity_flyweight) {
    std::cout << "Slime(entity_flyweight)" << "\n";
    
    sprite = *entity_flyweight->get_image(DRAGON_IMAGE);

    // TODO: create a method on entity with the default init
    // TODO: check what should be default of entity class
    position = std::make_unique<Coordinates>(100, 100);
    velocity = std::make_unique<Coordinates>(0, 0);
    acceleration = std::make_unique<Coordinates>(0, 0);
}

Slime::~Slime() {
    std::cout << "~Slime()" << "\n";
}