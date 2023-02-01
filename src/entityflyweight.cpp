#include "entityflyweight.h"

#include <iostream>

std::map<int, std::string> enumToPath = {
    {PLAYER_IMAGE, "./data/images/player/player.png"},
    {DRAGON_IMAGE, "./data/images/dragon/dragon.png"}
};


EntityFlyweight::EntityFlyweight() {
    std::cout << "initing EntityFlyweight" << "\n";
}
EntityFlyweight::~EntityFlyweight() {
    std::cout << "finishing EntityFlyweight" << "\n";
    for (auto& [image_name, created_image]: createdImages) {
        al_destroy_bitmap(*created_image);
        std::cout << "calling al_destroy_bitmap" << "\n";
    }
}

std::shared_ptr<ALLEGRO_BITMAP*> EntityFlyweight::getImage(int image_name) {
    if (createdImages.count(image_name) == 0) {
        createImage(image_name);
    }

    return createdImages[image_name];
}

void EntityFlyweight::createImage(int image_name) {
    std::cout << "calling al_load_bitmap" << "\n";

    std::string imagePath = enumToPath[image_name];

    std::shared_ptr<ALLEGRO_BITMAP*> newImage = std::make_shared<ALLEGRO_BITMAP*>(al_load_bitmap(imagePath.c_str()));

    createdImages[image_name] = newImage;
}