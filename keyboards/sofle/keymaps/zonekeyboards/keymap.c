#include <stdio.h>

#include QMK_KEYBOARD_H
#include <sendstring_spanish.h>
#include "handlers.c"

#ifdef OLED_ENABLE
#    include "oled.c"
#endif

#ifdef ENCODER_ENABLE
#    include "encoder.c"
#endif

#ifdef POINTING_DEVICE_ENABLE
#    include "trackball.c"
#endif

#include "modkeys.c"

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /*
     * _BASE
     * ,--------------------------------------------.                    ,-----------------------------------------.
     * |   ESC   |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  | Bspc |
     * |---------+------+------+------+------+------|                    |------+------+------+------+------+------|
     * |   TAB   |   Q  |   W  |   E  |   R  |   T  |                    |   Y  |   U  |   I  |   O  |   P  |ENTER |
     * |---------+------+------+------+------+------|                    |------+------+------+------+------+------|
     * |  LSHFT  |   A  |   S  |   D  |   F  |   G  |-------.    ,-------|   H  |   J  |   K  |   L  |   ñ  |RSHFT |
     * |---------+------+------+------+------+------|  MUTE |    |       |------+------+------+------+------+------|
     * |  LCTRL  |   Z  |   X  |   C  |   V  |   B  |-------|    |-------|   N  |   M  |   ,  |   .  |   /  |  '   |
     * `--------------------------------------------/      /     \      \-----------------------------------------'
     *              | LALT | LGUI |  [   | SYMB | / SPACE /       \SPACE \  |NUMP  |   ]  | RGUI | RALT |
     *              |      |      |      |      |/       /         \      \ |      |      |      |      |
     *              `-----------------------------------'           '------''---------------------------'
     */
    [_BASE] = LAYOUT(
        KC_ESC,   KC_1,   KC_2,   KC_3,  KC_4,  KC_5,                   KC_6, KC_7, KC_8, KC_9, KC_0, KC_BSPC,
        KC_TAB,   KC_Q,   KC_W,   KC_E,  KC_R,  KC_T,                   KC_Y, KC_U, KC_I, KC_O, KC_P, KC_ENT,
        KC_LSFT,  KC_A,   KC_S,   KC_D,  KC_F,  KC_G,                   KC_H, KC_J, KC_K, KC_L, ES_NTIL, KC_RSFT,
        KC_LCTL, KC_Z,   KC_X,   KC_C,  KC_V,  KC_B, KC_MUTE, XXXXXXX, KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, ES_QUOT,
                    KC_LALT,  KC_LGUI,ES_LBRC,SYMB,  KC_SPC,      KC_SPC, NUMP, ES_RBRC, KC_RGUI, KC_RALT
    ),

    /* _NUMP
     * ,-----------------------------------------.                     ,-----------------------------------------.
     * |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |                     |  F7  |  F8  |  F9  |  F10  | F11  | F12 |
     * |------+------+------+------+------+------|                     |------+------+------+------+------+------|
     * |   -  |   +  |  7   |   8  |  9   |  ,   |                     |  >   | HOME |   UP |  END |      |ENTER |
     * |------+------+------+------+------+------|                     |------+------+------+------+------+------|
     * |  /   |   *  |  4   |   5  |  6   |  .   |-------.     ,-------|  <   |LEFT  | DOWN | RIGHT|      |      |
     * |------+------+------+------+------+------|  MUTE |     |       |------+------+------+------+------+------|
     * |  ^   |   =  |  1   |   2  |  3   |  0   |-------|     |-------|MSBTN1|MSBTN2|  (   |   )  |      |      |
     * `-----------------------------------------/       /      \      \-----------------------------------------'
     *            | LALT | LGUI |  [   | SYMB | / SPACE /        \SPACE \  |NUMP  |   ]  | RGUI | RALT |
     *            |      |      |      |      |/       /          \      \ |      |      |      |      |
     *            `-----------------------------------'            '------''---------------------------'
     */
    [_NUMP] = LAYOUT(
        KC_F1,  KC_F2,   KC_F3, KC_F4, KC_F5,  KC_F6,                  KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, KC_F12,
        _______,ES_PLUS, KC_7,  KC_8,  KC_9,   KC_COMM,                KC_RABK, KC_HOME, KC_UP, KC_END, XXXXXXX, _______,
        _______,ES_ASTR, KC_4,  KC_5,  KC_6,   KC_DOT,                 KC_LABK, KC_LEFT, KC_DOWN, KC_RIGHT, XXXXXXX, _______,
        _______, ES_EQL, KC_1, KC_2, KC_3, KC_0, _______,     _______, KC_MS_BTN1, KC_MS_BTN2, LSFT(KC_9), LSFT(KC_0), XXXXXXX, _______,
                _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
    ),

    /* _SYMB
     * ,----------------------------------------.                      ,-----------------------------------------.
     * |      |   |  |  @   |  #   |  ~   | %    |                     |   6  |   7  |   8  |   9  |   0  |  `   |
     * |------+------+------+------+------+------|                     |------+------+------+------+------+------|
     * |      |  ´   |  `   |      |      | UCIS |                     |  &   | HOME | UP   | END  |PGUP  |BKSPCK|
     * |------+------+------+------+------+------|                     |------+------+------+------+------+------|
     * |      |  {   |  }   |  [   |  ]   |  \   |-------.     ,-------|  |   | LEFT | DOWN |RIGHT |PGDOWN|      |
     * |------+------+------+------+------+------|  MUTE |     |       |------+------+------+------+------+------|
     * |      |  (   |  )   |  <   |  >   |PCREEN|-------|     |-------| =    |      |      |      |  ~   |      |
     * `-----------------------------------------/       /      \      \-----------------------------------------'
     *            | LALT | LGUI |  [   | SYMB | / SPACE /        \SPACE \  |NUMP  |   ]  | RGUI | RALT |
     *            |      |      |      |      |/       /          \      \ |      |      |      |      |
     *            `-----------------------------------'            '------''---------------------------'
     */
    [_SYMB] = LAYOUT(
        _______, ES_PIPE, ES_AT, ES_HASH, ES_TILD, KC_PERC,             _______, _______, _______, _______, _______, _______,
        _______, ES_ACUT, ES_GRV, _______, _______, KC_UCIS,           KC_AMPR, KC_HOME, KC_UP, KC_END, KC_PGUP, _______,
        _______, ES_LCBR, ES_RCBR, ES_LBRC, ES_RBRC, KC_BSLS,           LSFT(KC_BSLS), KC_LEFT, KC_DOWN, KC_RIGHT, KC_PGDN, _______,
        _______, ES_LPRN, ES_RPRN, ES_LABK, ES_RABK, KC_PSCR, _______, XXXXXXX, KC_EQUAL, ALGR(KC_QUOTE), XXXXXXX, ALGR(KC_BSLS), KC_TILDE, _______,
                _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
    ),

    /* _TUNE
     * ,-----------------------------------------.                    ,-----------------------------------------.
     * |      |      |QWERTY|COLEMAK|MACWIN|     |                    |      |      |      |      |      |      |
     * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
     * | QK_BOOT|      |      |      |      |      |                    |      |      |      |      |      |      |
     * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
     * | TOG  |  HUI |  SAI |  VAI |  SPI |  MOD |-------.    ,-------|      | MUTE | VOLD | VOLU | OS   |      |
     * |------+------+------+------+------+------|  MUTE |    |       |------+------+------+------+------+------|
     * |      |  HUD |  SAD |  VAD |  SPD |      |-------|    |-------|      |      |      |      |      |      |
     * `-----------------------------------------/       /     \      \-----------------------------------------'
     *            | LALT | LGUI |  [   | SYMB | / SPACE /       \SPACE \  |NUMP  |   ]  | RGUI | RALT |
     *            |      |      |      |      |/       /         \      \ |      |      |      |      |
     *            `-----------------------------------'           '------''---------------------------'
     */
    [_TUNE] = LAYOUT(
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, CG_TOGG, XXXXXXX,           XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        QK_BOOT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,             XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        RGB_TOG, RGB_HUI, RGB_SAI, RGB_VAI, RGB_SPI, RGB_MOD,           XXXXXXX, KC_MUTE, KC_VOLD, KC_VOLU, OS, XXXXXXX,
        XXXXXXX, RGB_HUD, RGB_SAD, RGB_VAD, RGB_SPD, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
    )
};
