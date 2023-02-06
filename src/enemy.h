#ifndef ENEMY_H
#define ENEMY_H

#include "entity.h"

class Enemy : public Entity {
    public:
        Enemy();
        // Enemy(int entity_type, std::shared_ptr<EntityFlyweight> entity_flyweight);
        ~Enemy();
};

#endif