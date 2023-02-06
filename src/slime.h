#ifndef SLIME_H
#define SLIME_H

#include "enemy.h"

class Slime : public Enemy {
    public:
        Slime();
        Slime(std::shared_ptr<EntityFlyweight> entity_flyweight);
        ~Slime();
};

#endif