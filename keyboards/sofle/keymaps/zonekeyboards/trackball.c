#pragma once

#ifdef POINTING_DEVICE_ENABLE

#include "handlers.c"
uint16_t trackball_led_timer;

layer_state_t layer_state_set_user(layer_state_t state) {
    state = update_tri_layer_state(state, _UP, _DOWN, _TUNE);
    switch (biton32(state)) {
        case _UP:
            pimoroni_trackball_set_rgbw(255, 0, 0, 0.5);
            break;
        case _DOWN:
            pimoroni_trackball_set_rgbw(0, 0, 255, 0.5);
            break;
        case _LEFT:
            pimoroni_trackball_set_rgbw(0, 255, 0, 0.5);
            break;
        case _RIGHT:
            pimoroni_trackball_set_rgbw(0, 255, 255, 0.5);
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

#endif
