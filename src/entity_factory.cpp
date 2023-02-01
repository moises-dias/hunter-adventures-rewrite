#include "entity_factory.h"

#include <iostream>

EntityFactory::EntityFactory() {
    std::cout << "initing EntityFactory" << "\n";
    entity_flyweight = std::make_shared<EntityFlyweight>();
}

EntityFactory::~EntityFactory() {
    std::cout << "finishing EntityFactory" << "\n";
}

std::unique_ptr<Entity> EntityFactory::create_entity(int entity_type){
    std::unique_ptr<Entity> new_entity = std::make_unique<Entity>(entity_type, entity_flyweight);
    return std::move(new_entity);
}