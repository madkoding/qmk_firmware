#pragma once

#include "handlers.c"
uint16_t trackball_led_timer;

layer_state_t layer_state_set_user(layer_state_t state) {
    state = update_tri_layer_state(state, _NUMP, _SYMB, _TUNE);
    switch (biton32(state)) {
        case _NUMP:
            pimoroni_trackball_set_rgbw(255, 0, 0, 0.5);
            break;
        case _SYMB:
            pimoroni_trackball_set_rgbw(0, 0, 255, 0.5);
            break;
        case _TUNE:
            pimoroni_trackball_set_rgbw(255, 0, 255, 0.5);
            break;
        case _BASE:
            pimoroni_trackball_set_rgbw(255, 255, 255, 0.5);
            break;
    }
    return state;
}

void keyboard_post_init_kb(void) {
    keyboard_post_init_user();
    pimoroni_trackball_set_rgbw(255, 255, 255, 0.5);
}
