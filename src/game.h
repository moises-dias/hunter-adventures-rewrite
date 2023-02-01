#ifndef GAME_H
#define GAME_H

#include <memory>

#include <allegro5/allegro.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include <allegro5/allegro_image.h>
#include <allegro5/keyboard.h>

#include "entitymanager.h"

class Game {
    public:
        Game();
        ~Game();
        void init_allegro_dependencies();
        void init_images();
        void init_display(int window_width, int window_height);
        void init_fonts();
        void init_timer();
        void setup_event_queue();
        void start_timer();
        void main_game_loop();
    private:
        ALLEGRO_BITMAP* bg;
        ALLEGRO_DISPLAY* display;
        ALLEGRO_FONT* font;
        ALLEGRO_TIMER* timer;
        ALLEGRO_EVENT_QUEUE* event_queue;
        std::unique_ptr<EntityManager> entityManager;

};

#endif