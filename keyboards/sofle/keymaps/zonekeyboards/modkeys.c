#pragma once

#include "handlers.c"

uint8_t MOUSE_BUTTONS;
uint8_t mod_state;
bool    key_registered;

const qk_ucis_symbol_t ucis_symbol_table[] = UCIS_TABLE(
    UCIS_SYM("poop", 0x1F4A9),               // 💩
    UCIS_SYM("rofl", 0x1F923),               // 🤣
    UCIS_SYM("cuba", 0x1F1E8, 0x1F1FA),      // 🇨🇺
    UCIS_SYM("look", 0x0CA0, 0x005F, 0x0CA0) // ಠ_ಠ
);

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case SYMB:
            if (record->event.pressed) {
                layer_on(_SYMB);
                update_tri_layer(_SYMB, _NUMP, _TUNE);
            } else {
                layer_off(_SYMB);
                update_tri_layer(_SYMB, _NUMP, _TUNE);
            }
            return false;

        case NUMP:
            if (record->event.pressed) {
                layer_on(_NUMP);
                update_tri_layer(_SYMB, _NUMP, _TUNE);
            } else {
                layer_off(_NUMP);
                update_tri_layer(_SYMB, _NUMP, _TUNE);
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

        case KC_UCIS:
            if (record->event.pressed) {
                qk_ucis_start(); // or whatever it is called
            }
            return true; // we dont want QMK to handle a custom keycode, will only make the program slower and nothing else is gonna be run

    }
    return true; // other keycodes are still processed by QMK
}
