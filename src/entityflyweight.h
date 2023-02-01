#ifndef ENTITYFLYWEIGHT_H
#define ENTITYFLYWEIGHT_H

#include <memory>
#include <list>
#include <map>
#include <string>

#include <allegro5/allegro.h>

enum FILES {PLAYER_IMAGE, DRAGON_IMAGE};

//TODO: change entity_class variable name to image_name or something
class EntityFlyweight {
    public:
        EntityFlyweight();
        ~EntityFlyweight();
        void createImage(int entity_class);
        std::shared_ptr<ALLEGRO_BITMAP*> getImage(int entity_class);
        // std::shared_ptr<zzz> getAudio(int entity_class);
    private:
        std::map<int, std::shared_ptr<ALLEGRO_BITMAP*>> createdImages;

};

#endif