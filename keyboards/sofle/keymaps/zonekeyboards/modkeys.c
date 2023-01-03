#pragma once

#include "handlers.c"

uint8_t MOUSE_BUTTONS;
uint8_t mod_state;
bool    key_registered;

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

        case EMOJI:
            if (record->event.pressed) {
                layer_on(_EMOJI);
                update_tri_layer(_SYMB, _NUMP, _TUNE);
            } else {
                layer_off(_EMOJI);
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

        case UC_FLIP:
            if (record->event.pressed) {
                send_unicode_string("(ノಠ痊ಠ)ノ彡┻━┻");
            }
            break;

        case UC_TABL:
            if (record->event.pressed) {
                send_unicode_string("┬─┬ノ( º _ ºノ)");
            }
            break;

        case UC_SHRG:
            if (record->event.pressed) {
                send_unicode_string("¯\\_(ツ)_/¯");
            }
            break;

        case UC_DISA:
            if (record->event.pressed) {
                send_unicode_string("ಠ_ಠ");
            }
            break;
        case UC_LOL:
            if (record->event.pressed) {
                send_unicode_string("😂");
            }
            break;
        case UC_HAND:
            if (record->event.pressed) {
                send_unicode_string("🙌");
            }
            break;
        case UC_XP:
            if (record->event.pressed) {
                send_unicode_string("😝");
            }
            break;
        case UC_XD:
            if (record->event.pressed) {
                send_unicode_string("😆");
            }
            break;
        case UC_LUV:
            if (record->event.pressed) {
                send_unicode_string("😍");
            }
            break;
        case UC_SAD:
            if (record->event.pressed) {
                send_unicode_string("😢");
            }
            break;
        case UC_CRY:
            if (record->event.pressed) {
                send_unicode_string("😭");
            }
            break;
        case UC_RED:
            if (record->event.pressed) {
                send_unicode_string("🚩");
            }
            break;
    }
    return true; // other keycodes are still processed by QMK
}
