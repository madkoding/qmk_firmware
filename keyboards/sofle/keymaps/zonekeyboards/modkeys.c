#pragma once

#include "handlers.c"

uint8_t MOUSE_BUTTONS;
uint8_t mod_state;
bool    key_registered;

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case DOWN:
            if (record->event.pressed) {
                layer_on(_DOWN);
                update_tri_layer(_DOWN, _UP, _TUNE);
            } else {
                layer_off(_DOWN);
                update_tri_layer(_DOWN, _UP, _TUNE);
            }
            return false;

        case UP:
            if (record->event.pressed) {
                layer_on(_UP);
                update_tri_layer(_DOWN, _UP, _TUNE);
            } else {
                layer_off(_UP);
                update_tri_layer(_DOWN, _UP, _TUNE);
            }
            return false;

        case LEFT:
            if (record->event.pressed) {
                layer_on(_LEFT);
                update_tri_layer(_DOWN, _UP, _TUNE);
            } else {
                layer_off(_LEFT);
                update_tri_layer(_DOWN, _UP, _TUNE);
            }
            return false;

        case RIGHT:
            if (record->event.pressed) {
                layer_on(_RIGHT);
                update_tri_layer(_DOWN, _UP, _TUNE);
            } else {
                layer_off(_RIGHT);
                update_tri_layer(_DOWN, _UP, _TUNE);
            }
            return false;

        case KC_MOUSE_BTN1:
            if (record->event.pressed) {
                MOUSE_BUTTONS |= (1 << 0);
            } else {
                MOUSE_BUTTONS &= ~(1 << 0);
            }
            return false;

        case KC_MOUSE_BTN2:
            if (record->event.pressed) {
                MOUSE_BUTTONS |= (1 << 1);
            } else {
                MOUSE_BUTTONS &= ~(1 << 1);
            }
            return false;

    }
    return true; // other keycodes are still processed by QMK
}
