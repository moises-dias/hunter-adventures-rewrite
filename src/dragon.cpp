#include "dragon.h"

#include <iostream>

Dragon::Dragon() {
    std::cout << "Dragon()" << "\n";
}

Dragon::Dragon(std::shared_ptr<EntityFlyweight> entity_flyweight) {
    std::cout << "Dragon(entity_flyweight)" << "\n";
    
    sprite = *entity_flyweight->get_image(DRAGON_IMAGE);

    entity_class = ENEMY;
    entity_race = DRAGON;
}

Dragon::~Dragon() {
    std::cout << "~Dragon()" << "\n";
}