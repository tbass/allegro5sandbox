#include "stdafx.h"



int main(int argc, char** argv)
{
    assert(argc);
    assert(argv);

    if (!al_init()) {
        return -1;
    }
    if (!al_install_keyboard()) {
        return -1;
    }
    if (!al_install_mouse()) {
        return -1;
    }
    if (!al_init_image_addon()) {
        return -1;
    }

    if (!al_init_primitives_addon()) {
        return -1;
    }

    if (!al_init_font_addon()) {
        return -1;
    }

    if (!al_init_ttf_addon()) {
        return -1;
    }

    al_set_new_display_option(ALLEGRO_VSYNC, 1, ALLEGRO_REQUIRE);
    ALLEGRO_DISPLAY *display = al_create_display(1024, 768);

    ALLEGRO_FONT *smallFont = al_create_builtin_font();
//    ALLEGRO_FONT *ttf_font = al_load_font("saxmono.ttf", 18, 0);
    ALLEGRO_FONT *ttf_font = al_load_ttf_font("saxmono.ttf", 18, 0);

    ALLEGRO_TIMER *timer = al_create_timer(1.f / 60.f);

    ALLEGRO_EVENT_QUEUE *queue = al_create_event_queue();
    al_register_event_source(queue, al_get_keyboard_event_source());
    al_register_event_source(queue, al_get_mouse_event_source());
    al_register_event_source(queue, al_get_timer_event_source(timer));
    al_register_event_source(queue, al_get_display_event_source(display));

    srand((unsigned int)time(NULL));

    al_start_timer(timer);

    bool bRunning = true;
    bool bDoRedraw = false;

    uint version = al_get_allegro_version();

    while (bRunning) {
        ALLEGRO_EVENT evt;
        al_wait_for_event(queue, &evt);
        switch (evt.type) {
            case ALLEGRO_EVENT_DISPLAY_CLOSE:
                bRunning = false;
                break;
            case ALLEGRO_EVENT_KEY_UP:
                if (evt.keyboard.keycode == ALLEGRO_KEY_ESCAPE) {
                    bRunning = false;
                }
                break;
            case ALLEGRO_EVENT_TIMER:
                if (evt.timer.source == timer) {
                    bDoRedraw = true;
                }
                break;
            default:
                break;
        }
        if (bDoRedraw && al_is_event_queue_empty(queue)) {
            al_clear_to_color(al_map_rgb(5, 10, 5));
            al_draw_textf(smallFont, al_map_rgb(255, 255, 255),
                          0, 0, 0,
                          "%i.%i.%i", version >> 24, (version >> 16) & 255, (version >> 8) & 255);
            al_draw_text(ttf_font, al_map_rgb(255, 255, 255),
                         100, 100, 0,
                         "Allegro5 sandbox");
            al_flip_display();
            bDoRedraw = false;
        }
    }

    al_stop_timer(timer);

//    al_shutdown_ttf_addon();
    al_shutdown_font_addon();
    al_shutdown_primitives_addon();
    al_shutdown_image_addon();

    return 0;
}
