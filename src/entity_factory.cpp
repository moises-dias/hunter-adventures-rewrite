#include "entity_factory.h"

#include <iostream>

EntityFactory::EntityFactory() {
    std::cout << "EntityFactory()" << "\n";
    entity_flyweight = std::make_shared<EntityFlyweight>();

    add_entity_to_list = {
        { WARRIOR , [](auto& entity_list, auto& entity_flyweight) {entity_list.push_back(std::make_shared<Player>(entity_flyweight)); } },
        { SLIME , [](auto& entity_list, auto& entity_flyweight) {entity_list.push_back(std::make_shared<Slime>(entity_flyweight)); } },
        { DRAGON , [](auto& entity_list, auto& entity_flyweight) {entity_list.push_back(std::make_shared<Dragon>(entity_flyweight)); } },
        { FIRE_BALL , [](auto& entity_list, auto& entity_flyweight) {entity_list.push_back(std::make_shared<FireBall>(entity_flyweight)); } },
    };
}

EntityFactory::~EntityFactory() {
    std::cout << "~EntityFactory()" << "\n";
}

void EntityFactory::populate_entity(std::list<std::shared_ptr<Entity>>& entity_list, int entity_race) {

    add_entity_to_list[entity_race](entity_list, entity_flyweight);
}