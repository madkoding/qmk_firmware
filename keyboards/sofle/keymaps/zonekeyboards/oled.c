#pragma once

#ifdef OLED_ENABLE

#    include <string.h>
#    include "lib/lib8tion/lib8tion.h"
#    include "handlers.c"

char wpm_str[4];

static void render_logo(void) {
    static const char PROGMEM qmk_logo[] = {
        0x80, 0x81, 0x82, 0x83, 0x84, 0x85, 0x86, 0x87, 0x88, 0x89, 0x8A, 0x8B, 0x8C,
        0x8D, 0x8E, 0x8F, 0x90, 0x91, 0x92, 0x93, 0x94, 0xA0, 0xA1, 0xA2, 0xA3, 0xA4,
        0xA5, 0xA6, 0xA7, 0xA8, 0xA9, 0xAA, 0xAB, 0xAC, 0xAD, 0xAE, 0xAF, 0xB0, 0xB1,
        0xB2, 0xB3, 0xB4, 0xC0, 0xC1, 0xC2, 0xC3, 0xC4, 0xC5, 0xC6, 0xC7, 0xC8, 0xC9,
        0xCA, 0xCB, 0xCC, 0xCD, 0xCE, 0xCF, 0xD0, 0xD1, 0xD2, 0xD3, 0xD4, 0x00};

    oled_write_P(qmk_logo, false);
}

static void print_status_narrow(void) {
    // Set cursor position
    oled_set_cursor(0, 0);

    switch (get_highest_layer(layer_state)) {
        case _BASE:
            oled_write("Capa base", false);
            break;
        case _UP:
            oled_write("Capa Superior", false);
            break;
        case _DOWN:
            oled_write("Capa Inferior", false);
            break;
        case _LEFT:
            oled_write("Capa Izquierda", false);
            break;
        case _RIGHT:
            oled_write("Capa Derecha", false);
            break;
        case _TUNE:
            oled_write("Capa de ajuste", false);
            break;
        default:
            oled_write("Indefinido", false);
    }
    oled_write_P(PSTR("\n\n"), false);
    led_t led_state = host_keyboard_led_state();
    oled_write_P(led_state.caps_lock ? PSTR("Mayusculas ON") : PSTR("Mayusculas OFF"), false);
}

oled_rotation_t oled_init_user(oled_rotation_t rotation) {
    if (is_keyboard_master()) {
        return OLED_ROTATION_180;
    }
    return rotation;
}

bool oled_task_user(void) {
    if (is_keyboard_master()) {
        print_status_narrow();
    } else {
        render_logo();
    }
    return false;
}

#endif
