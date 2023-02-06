#ifndef DRAGON_H
#define DRAGON_H

#include "enemy.h"

class Dragon : public Enemy {
    public:
        Dragon();
        Dragon(std::shared_ptr<EntityFlyweight> entity_flyweight);
        ~Dragon();
};

#endif