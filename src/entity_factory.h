#ifndef ENTITYFACTORY_H
#define ENTITYFACTORY_H

#include <memory>
#include <list>
#include <functional>

#include "entity_flyweight.h"
#include "enemy.h"
#include "player.h"
#include "slime.h"
#include "dragon.h"
#include "fire_ball.h"

class EntityFactory {
    public:
        EntityFactory();
        ~EntityFactory();
        void populate_player(std::list<std::shared_ptr<Player>>& player_list);
        void populate_enemy(std::list<std::shared_ptr<Enemy>>& enemy_list, int entity_race);
        void populate_projectile(std::list<std::shared_ptr<Projectile>>& projectile_list, int entity_race);
    private:
        std::shared_ptr<EntityFlyweight> entity_flyweight;
        std::map<int, std::function<std::shared_ptr<Enemy>(std::shared_ptr<EntityFlyweight>&)>> race_to_enemy;
        std::map<int, std::function<std::shared_ptr<Projectile>(std::shared_ptr<EntityFlyweight>&)>> race_to_projectile;
        
};

#endif