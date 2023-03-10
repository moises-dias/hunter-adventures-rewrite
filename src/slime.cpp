#include "slime.h"

#include <iostream>

Slime::Slime() {
    std::cout << "Slime()" << "\n";
}

Slime::Slime(std::shared_ptr<EntityFlyweight> entity_flyweight) {
    std::cout << "Slime(entity_flyweight)" << "\n";
    
    sprite = *entity_flyweight->get_image(SLIME_IMAGE);

    entity_class = ENEMY;
    entity_race = SLIME;

}

Slime::~Slime() {
    std::cout << "~Slime()" << "\n";
}