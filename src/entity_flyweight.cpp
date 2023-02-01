#include "entity_flyweight.h"

#include <iostream>

std::map<int, std::string> enum_to_path = {
    {PLAYER_IMAGE, "./data/images/player/player.png"},
    {DRAGON_IMAGE, "./data/images/dragon/dragon.png"}
};


EntityFlyweight::EntityFlyweight() {
    std::cout << "initing EntityFlyweight" << "\n";
}
EntityFlyweight::~EntityFlyweight() {
    std::cout << "finishing EntityFlyweight" << "\n";
    for (auto& [image_name, created_image]: created_images) {
        al_destroy_bitmap(*created_image);
        std::cout << "calling al_destroy_bitmap" << "\n";
    }
}

std::shared_ptr<ALLEGRO_BITMAP*> EntityFlyweight::get_image(int image_name) {
    if (created_images.count(image_name) == 0) {
        create_image(image_name);
    }

    return created_images[image_name];
}

void EntityFlyweight::create_image(int image_name) {
    std::cout << "calling al_load_bitmap" << "\n";

    std::string image_path = enum_to_path[image_name];

    std::shared_ptr<ALLEGRO_BITMAP*> new_image = std::make_shared<ALLEGRO_BITMAP*>(al_load_bitmap(image_path.c_str()));

    created_images[image_name] = new_image;
}