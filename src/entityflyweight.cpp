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

std::shared_ptr<ALLEGRO_BITMAP*> EntityFlyweight::getImage(int image_name) {
    if (createdImages.count(image_name) == 0) {
        createImage(image_name);
    }

    return createdImages[image_name];
}

void EntityFlyweight::createImage(int image_name) {

    std::string imagePath = enumToPath[image_name];

    std::shared_ptr<ALLEGRO_BITMAP*> newImage = std::make_shared<ALLEGRO_BITMAP*>(al_load_bitmap(imagePath.c_str()));

    createdImages[image_name] = newImage;
}