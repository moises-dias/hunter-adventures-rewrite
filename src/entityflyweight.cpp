#include "entityflyweight.h"

std::map<int, std::string> enumToPath = {
    {PLAYER_IMAGE, "./data/images/player/player.png"},
    {DRAGON_IMAGE, "./data/images/dragon/dragon.png"}
};


EntityFlyweight::EntityFlyweight() {

}
EntityFlyweight::~EntityFlyweight() {
    // TODO: delete everything loaded (images and audios)
}

std::shared_ptr<ALLEGRO_BITMAP*> EntityFlyweight::getImage(int entity_class) {
    if (createdImages.count(entity_class) == 0) {
        createImage(entity_class);
    }

    return createdImages[entity_class];
}

void EntityFlyweight::createImage(int entity_class) {

    std::shared_ptr<ALLEGRO_BITMAP*> newImage = std::make_shared<ALLEGRO_BITMAP*>(al_load_bitmap("imagePath"));

    std::string imagePath = enumToPath[entity_class];

    *newImage = al_load_bitmap(imagePath.c_str());

    createdImages[entity_class] = newImage;
}