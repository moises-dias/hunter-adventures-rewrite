#include "entity_factory.h"

#include <iostream>

EntityFactory::EntityFactory() {
    std::cout << "EntityFactory()" << "\n";
    entity_flyweight = std::make_shared<EntityFlyweight>();
}

EntityFactory::~EntityFactory() {
    std::cout << "~EntityFactory()" << "\n";
}

void EntityFactory::populate_player(std::list<std::shared_ptr<Player>>& player_list) {
    std::shared_ptr<Player> new_player = std::make_shared<Player>(entity_flyweight);
    player_list.push_back(new_player);
}
void EntityFactory::populate_enemy(std::list<std::shared_ptr<Enemy>>& enemy_list, int entity_type) {
    // TODO BEFORE MERGE structure to create different enemies
    // if entity_type = ...
    std::shared_ptr<Enemy> new_enemy = std::make_shared<Slime>(entity_flyweight);
    enemy_list.push_back(new_enemy);
}