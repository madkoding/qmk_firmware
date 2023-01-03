#pragma once

#include <string.h>
#include "lib/lib8tion/lib8tion.h"
#include "handlers.c"

char wpm_str[4];

static void print_status_narrow(void) {
    // Print current mode
    oled_write_P(PSTR("\n\n"), false);
    oled_write_ln_P(PSTR("MODE"), false);
    if (keymap_config.swap_lctl_lgui) {
        oled_write_ln_P(PSTR("MAC"), false);
    } else {
        oled_write_ln_P(PSTR("WIN"), false);
    }

    // Print current layer
    oled_write_ln_P(PSTR(""), false);
    oled_write_ln_P(PSTR("LAYER"), false);
    switch (get_highest_layer(layer_state)) {
        case _BASE:
            oled_write_ln_P(PSTR("Base\n\n"), false);
            break;
        case _NUMP:
            oled_write_ln_P(PSTR("Num\n\n"), false);
            break;
        case _SYMB:
            oled_write_ln_P(PSTR("Symb\n\n"), false);
            break;
        case _TUNE:
            oled_write_ln_P(PSTR("Tune\n\n"), false);
            break;
        case _EMOJI:
            oled_write_ln_P(PSTR("Emoji\n\n"), false);
            break;
        default:
            oled_write_ln_P(PSTR("Undef\n"), false);
    }
    oled_write_P(PSTR("\n\n"), false);
    led_t led_usb_state = host_keyboard_led_state();
    oled_write_ln_P(PSTR("CPSLK"), led_usb_state.caps_lock);
}

oled_rotation_t oled_init_user(oled_rotation_t rotation) {
    if (is_keyboard_master()) {
        return OLED_ROTATION_270;
    }
    return rotation;
}

bool oled_task_user(void) {
    if (is_keyboard_master()) {
        print_status_narrow();
    }
    return false;
}

