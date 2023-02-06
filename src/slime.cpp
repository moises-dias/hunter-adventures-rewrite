#include "slime.h"

#include <iostream>

Slime::Slime() {
    std::cout << "Slime()" << "\n";
}

Slime::Slime(std::shared_ptr<EntityFlyweight> entity_flyweight) {
    std::cout << "Slime(entity_flyweight)" << "\n";
    
    sprite = *entity_flyweight->get_image(DRAGON_IMAGE);

    // TODO: check what should be default of entity class
    init_position();
}

Slime::~Slime() {
    std::cout << "~Slime()" << "\n";
}