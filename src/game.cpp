#include "game.h"

#include <vector>
#include <map>
#include <iostream>
#include <algorithm>

Game::Game(){
    std::cout << "Game()" << "\n";

    const int window_width = 1280;
    const int window_height = 720;

    init_allegro_dependencies();
    init_display(window_width, window_height);
    init_images();
    init_fonts();
    init_timer();
    setup_event_queue();
    start_timer();

    entity_manager = std::make_unique<EntityManager>();

    // TODO: create game state classes, creation of player and enemies will be on gameplay state

    entity_manager->create_player();
    entity_manager->create_enemy(SLIME);
    entity_manager->create_enemy(DRAGON);
    entity_manager->create_enemy(DRAGON);

    main_game_loop();


}

Game::~Game() {
    std::cout << "~Game()" << "\n";
    al_destroy_bitmap(bg);
    al_destroy_font(font);
    al_destroy_display(display);
    al_destroy_event_queue(event_queue);
}

void Game::init_allegro_dependencies() {
    al_init();
    al_init_font_addon();
    al_init_ttf_addon();
    al_init_primitives_addon();
    al_init_image_addon();
    al_install_keyboard();
}

void Game::init_images() {
    bg = al_load_bitmap("./data/images/bg.png");
}

void Game::init_display(const int window_width, const int window_height) {
    display = al_create_display(window_width, window_height);
    // al_set_window_position(display, 200, 200);
    al_set_window_title(display, "Hunter Adventures!");
}

void Game::init_fonts() {
    font = al_load_font("./fonts/font.ttf", 25, 0);
}

void Game::init_timer() {
    timer = al_create_timer(1.0 / 30.0);
}

void Game::setup_event_queue() {
    event_queue = al_create_event_queue();
    al_register_event_source(event_queue, al_get_display_event_source(display));
    al_register_event_source(event_queue, al_get_timer_event_source(timer));
    al_register_event_source(event_queue, al_get_keyboard_event_source() ); 
}

void Game::start_timer() {
    al_start_timer(timer);
}

void Game::handle_event() {
    ALLEGRO_EVENT event;
    al_wait_for_event(event_queue, &event);
    
    if( event.type == ALLEGRO_EVENT_DISPLAY_CLOSE ) {
        shutdown_game = true;
    }
    else if( event.type == ALLEGRO_EVENT_KEY_DOWN) {
        bool command_key_pressed = std::find(COMMAND_KEYS.begin(), COMMAND_KEYS.end(), event.keyboard.keycode) != COMMAND_KEYS.end();
        if(command_key_pressed) {
            entity_manager->handle_command(event.keyboard.keycode);
        }
    }
}

void Game::update_screen() {
    al_clear_to_color(al_map_rgb(255,255,255));
    // TODO: draw the background on what class? is this an entity?
    al_draw_bitmap(bg, 0, 0, 0);
    // TODO fix entities being updated on the update_screen method.
    entity_manager->update_entities();
    al_flip_display();
}

void Game::main_game_loop() {

    while(!shutdown_game){
        update_screen();
        handle_event();
    }
}