#ifndef ENTITYFLYWEIGHT_H
#define ENTITYFLYWEIGHT_H

#include <memory>
#include <list>
#include <map>
#include <string>

#include <allegro5/allegro.h>

enum FILES {PLAYER_IMAGE, DRAGON_IMAGE, SLIME_IMAGE, FIRE_BALL_IMAGE};

class EntityFlyweight {
    public:
        EntityFlyweight();
        ~EntityFlyweight();
        void create_image(int image_id);
        std::shared_ptr<ALLEGRO_BITMAP*> get_image(int image_id);

    private:
        std::map<int, std::shared_ptr<ALLEGRO_BITMAP*>> created_images;
};

#endif