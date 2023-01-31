#include "game.h"

#include <iostream>

Game::Game(){
    std::cout << "initing Game" << "\n";

    const int window_width = 1280;
    const int window_height = 720;

    init_allegro_dependencies();
    init_display(window_width, window_height);
    init_images();
    init_fonts();
    init_timer();
    setup_event_queue();
    start_timer();

    main_game_loop();


}
Game::~Game() {
    std::cout << "finishing Game" << "\n";
    al_destroy_bitmap(bg);
    al_destroy_bitmap(sprite);
    al_destroy_font(font);
    al_destroy_display(display);
    al_destroy_event_queue(event_queue);
}

void Game::init_allegro_dependencies() {
    al_init();
    al_init_font_addon();
    al_init_ttf_addon();
    al_init_image_addon();
    al_install_keyboard();
}

void Game::init_images() {
    sprite = al_load_bitmap("./images/dragon.png");
    bg = al_load_bitmap("./images/bg.png");
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

void Game::main_game_loop() {
    float frame = 0.f;
    int pos_x = 0, pos_y = 0;
    int current_frame_y = 161;

    while(true){
        ALLEGRO_EVENT event;
        al_wait_for_event(event_queue, &event);
        if( event.type == ALLEGRO_EVENT_DISPLAY_CLOSE ){
            break;
        }else if( event.keyboard.keycode == ALLEGRO_KEY_RIGHT ){
            current_frame_y = 161;
            pos_x += 20;
        }else if( event.keyboard.keycode == ALLEGRO_KEY_LEFT ){
            current_frame_y = 161 * 3;
            pos_x -= 20;
        }else if( event.keyboard.keycode == ALLEGRO_KEY_DOWN ){
            current_frame_y = 161 * 2;
            pos_y += 20;
        }else if( event.keyboard.keycode == ALLEGRO_KEY_UP ){
            current_frame_y = 0;
            pos_y -= 20;
        }

        frame += 0.3f;
        if( frame > 3){
        frame -= 3;
        }

        al_clear_to_color(al_map_rgb(255,255,255));
        al_draw_bitmap(bg, 0, 0, 0);
        al_draw_text(font, al_map_rgb(0,0,0), 7, 7, 0, "SCORE: dragon");
        al_draw_text(font, al_map_rgb(255,255,255), 5, 5, 0, "SCORE: dragon");
        al_draw_bitmap_region(sprite, 191 * (int)frame, current_frame_y, 191, 161, pos_x, pos_y, 0);
        al_flip_display();
    }
}