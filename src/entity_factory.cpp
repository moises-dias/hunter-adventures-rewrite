#include "entity_factory.h"

#include <iostream>

EntityFactory::EntityFactory() {
    std::cout << "EntityFactory()" << "\n";
    entity_flyweight = std::make_shared<EntityFlyweight>();

    race_to_enemy = {
        { SLIME , [](auto& entity_flyweight) {return std::make_shared<Slime>(entity_flyweight); } },
        { DRAGON , [](auto& entity_flyweight) {return std::make_shared<Dragon>(entity_flyweight); } }
    };
    race_to_projectile = {
        { FIRE_BALL , [](auto& entity_flyweight) {return std::make_shared<FireBall>(entity_flyweight); } }
    };
}

EntityFactory::~EntityFactory() {
    std::cout << "~EntityFactory()" << "\n";
}

void EntityFactory::populate_player(std::list<std::shared_ptr<Player>>& player_list) {
    std::shared_ptr<Player> new_player = std::make_shared<Player>(entity_flyweight);
    player_list.push_back(new_player);
}
void EntityFactory::populate_enemy(std::list<std::shared_ptr<Enemy>>& enemy_list, int entity_race) {

    // TODO create a separate file for all enums?
    std::shared_ptr<Enemy> new_enemy;
    new_enemy = race_to_enemy[entity_race](entity_flyweight);
    enemy_list.push_back(new_enemy);
}

void EntityFactory::populate_projectile(std::list<std::shared_ptr<Projectile>>& projectile_list, int entity_race) {

    std::shared_ptr<Projectile> new_projectile;
    new_projectile = race_to_projectile[entity_race](entity_flyweight);
    projectile_list.push_back(new_projectile);
}