#ifndef FIREBALL_H
#define FIREBALL_H

#include "projectile.h"

class FireBall : public Projectile {
    public:
        FireBall();
        FireBall(std::shared_ptr<EntityFlyweight> entity_flyweight);
        ~FireBall();
};

#endif