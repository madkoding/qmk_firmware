#include <stdio.h>
#include QMK_KEYBOARD_H
#include "handlers.c"
#include "matrix.c"
#include "oled.c"
#include "encoder.c"
#include "trackball.c"
#include "modkeys.c"

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /*
     * _BASE
     * ,--------------------------------------------.                    ,-----------------------------------------.
     * |   ESC   |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  | Bspc |
     * |---------+------+------+------+------+------|                    |------+------+------+------+------+------|
     * |   TAB   |   Q  |   W  |   E  |   R  |   T  |                    |   Y  |   U  |   I  |   O  |   P  |ENTER |
     * |---------+------+------+------+------+------|                    |------+------+------+------+------+------|
     * |   LALT  |   A  |   S  |   D  |   F  |   G  |-------.    ,-------|   H  |   J  |   K  |   L  |   ;  |  '   |
     * |---------+------+------+------+------+------|  MUTE |    |       |------+------+------+------+------+------|
     * |  LSHFT  |   Z  |   X  |   C  |   V  |   B  |-------|    |-------|   N  |   M  |   ,  |   .  |   /  |RSHFT |
     * `--------------------------------------------/      /     \      \-----------------------------------------'
     *              | LCTRL| LGUI |EMOJI | SYMB | / SPACE /       \SPACE \  |NUMP  |EMOJI | RGUI | RALT |
     *              |      |      |      |      |/       /         \      \ |      |      |      |      |
     *              `-----------------------------------'           '------''---------------------------'
     */
    [_BASE] = LAYOUT(
        KC_ESC,   KC_1,   KC_2,   KC_3,  KC_4,  KC_5,                   KC_6, KC_7, KC_8, KC_9, KC_0, KC_BSPC,
        KC_TAB,   KC_Q,   KC_W,   KC_E,  KC_R,  KC_T,                   KC_Y, KC_U, KC_I, KC_O, KC_P, KC_ENT,
        KC_LALT,  KC_A,   KC_S,   KC_D,  KC_F,  KC_G,                   KC_H, KC_J, KC_K, KC_L, KC_SCLN, KC_QUOT,
        KC_LSFT, KC_Z,   KC_X,   KC_C,  KC_V,  KC_B, KC_MUTE, XXXXXXX, KC_N, KC_M, KC_COMM, KC_DOT, KC_SLASH, KC_RSFT,
                    KC_LCTL,  KC_LGUI, LEFT, DOWN, KC_SPC,      KC_SPC, UP, RIGHT, KC_RGUI, KC_RALT
    ),

    /* _UP
     * ,-----------------------------------------.                     ,-----------------------------------------.
     * |  F12 |  F1  |  F2  |  F3  |  F4  |  F5  |                     |  F6  |  F7  |  F8  |  F9  |  F10 | F11  |
     * |------+------+------+------+------+------|                     |------+------+------+------+------+------|
     * |      |      |      |      |      |      |                     |      |      | HOME |  UP  | END  |ENTER |
     * |------+------+------+------+------+------|                     |------+------+------+------+------+------|
     * |      |      |      |      |      |      |-------.     ,-------|      |      | LEFT | DOWN | RIGHT|  +   |
     * |------+------+------+------+------+------|  MUTE |     |       |------+------+------+------+------+------|
     * |      |      |      |      |      |      |-------|     |-------|MSBTN1|MSBTN2|  (   |   )  |   _  |      |
     * `-----------------------------------------/       /      \      \-----------------------------------------'
     *            | LCTRL| LGUI |EMOJI | SYMB | / SPACE /        \SPACE \  |NUMP  |EMOJI | RGUI | RALT |
     *            |      |      |      |      |/       /          \      \ |      |      |      |      |
     *            `-----------------------------------'            '------''---------------------------'
     */
    [_UP] = LAYOUT(
        KC_F12, KC_F1,  KC_F2,   KC_F3, KC_F4, KC_F5,                    KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11,
        _______,XXXXXXX, XXXXXXX,  XXXXXXX,  XXXXXXX,   XXXXXXX,                XXXXXXX, XXXXXXX,KC_HOME, KC_UP, KC_END, _______,
        _______,XXXXXXX, XXXXXXX,  XXXXXXX,  XXXXXXX,   XXXXXXX,                 XXXXXXX, XXXXXXX,KC_LEFT, KC_DOWN, KC_RIGHT, KC_PLUS,
        _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______,     _______, KC_MS_BTN1, KC_MS_BTN2, LSFT(KC_9), LSFT(KC_0), LSFT(KC_MINS), _______,
                _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
    ),

    /* _DOWN
     * ,----------------------------------------.                      ,-----------------------------------------.
     * |   ª  |   |  |  @   |  #   |  $   | %    |                     |      |      |      |      |      |      |
     * |------+------+------+------+------+------|                     |------+------+------+------+------+------|
     * |      |  ´   |  `   |  ^   |      |      |                     |      |      | HOME |  UP  | END  |ENTER |
     * |------+------+------+------+------+------|                     |------+------+------+------+------+------|
     * |      |      |      |      |      |      |-------.     ,-------|      |      | LEFT | DOWN | RIGHT|  *   |
     * |------+------+------+------+------+------|  MUTE |     |       |------+------+------+------+------+------|
     * |      |      |      |      |      |PCREEN|-------|     |-------|      |      |  [   |  ]   |  ~   |      |
     * `-----------------------------------------/       /      \      \-----------------------------------------'
     *            | RCTL | LGUI |EMOJI | SYMB | / SPACE /        \SPACE \  |NUMP  |EMOJI | RGUI | RALT |
     *            |      |      |      |      |/       /          \      \ |      |      |      |      |
     *            `-----------------------------------'            '------''---------------------------'
     */
    [_DOWN] = LAYOUT(
        KC_MINS, KC_PIPE, KC_AT, KC_HASH, KC_DLR, KC_PERC,             XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,  XXXXXXX,  _______,
        _______, KC_QUOT, KC_GRV, KC_CIRC, XXXXXXX, XXXXXXX,           XXXXXXX,XXXXXXX, KC_HOME, KC_UP,   KC_END,  _______,
        _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,          _______,_______, KC_LEFT, KC_DOWN, KC_RIGHT, KC_ASTR,
        _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_PSCR, _______, _______, _______, _______, KC_LBRC, KC_RBRC, KC_TILDE, _______,
                KC_RCTL, _______, _______, _______, _______, _______, _______, _______, _______, _______
    ),

    /* _LEFT
     * ,-----------------------------------------.                     ,-----------------------------------------.
     * |      |      |      |      |      |      |                     |      |      |      |      |      |      |
     * |------+------+------+------+------+------|                     |------+------+------+------+------+------|
     * |      |      |      |      |      |      |                     |      |      |      |      |      |      |
     * |------+------+------+------+------+------|                     |------+------+------+------+------+------|
     * |      |      |      |      |      |      |-------.     ,-------|      |      |      |      |      |  =   |
     * |------+------+------+------+------+------|       |     |       |------+------+------+------+------+------|
     * |      |      |      |      |      |      |-------|     |-------|      |      |  <   |  >   |      |      |
     * `-----------------------------------------/       /      \      \-----------------------------------------'
     *            | LCTL | LGUI |EMOJI | SYMB | / SPACE /        \SPACE \  |NUMP  |EMOJI | RGUI | RALT |
     *            |      |      |      |      |/       /          \      \ |      |      |      |      |
     *            `-----------------------------------'            '------''---------------------------'
     */
    [_LEFT] = LAYOUT(
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,           XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,           XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,           XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_EQL,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_LABK, KC_RABK, XXXXXXX, XXXXXXX,
                 _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
    ),

    /* _RIGHT
     * ,-----------------------------------------.                     ,-----------------------------------------.
     * |      |      |      |      |      |      |                     |      |      |      |      |      |      |
     * |------+------+------+------+------+------|                     |------+------+------+------+------+------|
     * |      |      |      |  é   |      |      |                     |      |  ú   |  í   |  ó   |      |      |
     * |------+------+------+------+------+------|                     |------+------+------+------+------+------|
     * |      |  á   |      |      |      |      |-------.     ,-------|      |      |      |      |      |  -   |
     * |------+------+------+------+------+------|       |     |       |------+------+------+------+------+------|
     * |      |      |      |      |      |      |-------|     |-------|   ñ  |      |  {   |  }   |   \  |      |
     * `-----------------------------------------/       /      \      \-----------------------------------------'
     *            | LCTL | LGUI |EMOJI | SYMB | / SPACE /        \SPACE \  |NUMP  |EMOJI | RGUI | RALT |
     *            |      |      |      |      |/       /          \      \ |      |      |      |      |
     *            `-----------------------------------'            '------''---------------------------'
     */
    [_RIGHT] = LAYOUT(
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,           XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX, XP(ECUTELOW,ECUTE), XXXXXXX, XXXXXXX,           XXXXXXX, XP(UCUTELOW,UCUTE), XP(ICUTELOW,ICUTE), XP(OCUTELOW,OCUTE), XXXXXXX, XXXXXXX,
        XXXXXXX, XP(ACUTELOW,ACUTE) , XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,           XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_MINS,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,XXXXXXX, XXXXXXX, XP(ENIELOW,ENIE), XXXXXXX, KC_LCBR, KC_RCBR, KC_BSLS, XXXXXXX,
                 _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
    ),


    /* _TUNE
     * ,-----------------------------------------.                    ,-----------------------------------------.
     * |      |      |QWERTY|COLEMAK|MACWIN|     |                    |      |      |      |      |      |      |
     * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
     * |RESET |      |      |      |      |      |                    |      |      |      |      |      |      |
     * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
     * | TOG  |  HUI |  SAI |  VAI |  SPI |  MOD |-------.    ,-------|      | MUTE | VOLD | VOLU | OS   |      |
     * |------+------+------+------+------+------|  MUTE |    |       |------+------+------+------+------+------|
     * |      |  HUD |  SAD |  VAD |  SPD |      |-------|    |-------|      |      |      |      |      |      |
     * `-----------------------------------------/       /     \      \-----------------------------------------'
     *            | LCTL | LGUI |  [   | SYMB | / SPACE /       \SPACE \  |NUMP  |   ]  | RGUI | RALT |
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


