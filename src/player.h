#ifndef PLAYER_H
#define PLAYER_H

#include "entity.h"

class Player : public Entity {
    public:
        Player();
        Player(std::shared_ptr<EntityFlyweight> entity_flyweight);
        ~Player();
        void handle_command(int command);
    private:
};

#endif