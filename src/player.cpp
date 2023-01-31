// #include "player.h"

// #include <iostream>


// Player::Player() {
//     std::cout << "initing player" << "\n";
//     x_position = 500;
//     y_position = 500;
//     sprite_path = "./images/dragon.png";
//     sprite = al_load_bitmap("./images/dragon.png");
// }

// Player::~Player() {
//     std::cout << "finishing player" << "\n";
//     al_destroy_bitmap(sprite);
// }

// void Player::draw_sprite() {
//     // TODO: who should be responsible for drawing? the player? game? or another class?
//     auto color = al_map_rgba(0,255,255,255);
//     al_draw_tinted_bitmap_region(sprite, color, 0,0,191,161, x_position, y_position, 0);
//     // al_draw_bitmap_region(sprite, 0, 0, 191, 161, x_position, y_position, 0);
// }

// void Player::update_x_position(int value) {
//     x_position += value;
// }

// void Player::update_y_position(int value) {
//     y_position += value;
// }

// void Player::update_position(std::vector<int> coordinates) {
//     x_position += coordinates[0];
//     y_position += coordinates[1];
// }