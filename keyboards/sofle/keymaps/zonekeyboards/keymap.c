#include <stdio.h>

#include QMK_KEYBOARD_H
#include <sendstring_spanish.h>
#include "handlers.c"

#ifdef RGBLIGHT_SLEEP
#    include "rgb.c"
#endif

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
     * |  LCTRL  |   A  |   S  |   D  |   F  |   G  |-------.    ,-------|   H  |   J  |   K  |   L  |   ñ  |  '   |
     * |---------+------+------+------+------+------|  MUTE |    |       |------+------+------+------+------+------|
     * |  LSHFT  |   Z  |   X  |   C  |   V  |   B  |-------|    |-------|   N  |   M  |   ,  |   .  |   /  |RSHFT |
     * `--------------------------------------------/      /     \      \-----------------------------------------'
     *              | LALT | LGUI |EMOJI | SYMB | / SPACE /       \SPACE \  |NUMP  |EMOJI | RGUI | RALT |
     *              |      |      |      |      |/       /         \      \ |      |      |      |      |
     *              `-----------------------------------'           '------''---------------------------'
     */
    [_BASE] = LAYOUT(
        KC_ESC,   ES_1,   ES_2,   ES_3,  ES_4,  ES_5,                   ES_6, ES_7, ES_8, ES_9, ES_0, KC_BSPC,
        KC_TAB,   ES_Q,   ES_W,   ES_E,  ES_R,  ES_T,                   ES_Y, ES_U, ES_I, ES_O, ES_P, KC_ENT,
        KC_LALT,  ES_A,   ES_S,   ES_D,  ES_F,  ES_G,                   ES_H, ES_J, ES_K, ES_L, ES_NTIL, ES_QUOT,
        KC_LSFT, ES_Z,   ES_X,   ES_C,  ES_V,  ES_B, KC_MUTE, XXXXXXX, ES_N, ES_M, ES_COMM, ES_DOT, ES_MINS, KC_RSFT,
                    KC_LCTL,  KC_LGUI,EMOJI,SYMB,  KC_SPC,      KC_SPC, NUMP, EMOJI, KC_RGUI, KC_RALT
    ),

    /* _NUMP
     * ,-----------------------------------------.                     ,-----------------------------------------.
     * |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |                     |  F7  |  F8  |  F9  |  F10  | F11  | F12 |
     * |------+------+------+------+------+------|                     |------+------+------+------+------+------|
     * |   -  |   +  |  7   |   8  |  9   |  ,   |                     |  >   | HOME |   UP |  END |      |ENTER |
     * |------+------+------+------+------+------|                     |------+------+------+------+------+------|
     * |   /  |   *  |  4   |   5  |  6   |  .   |-------.     ,-------|  <   |LEFT  | DOWN | RIGHT|      |      |
     * |------+------+------+------+------+------|  MUTE |     |       |------+------+------+------+------+------|
     * |   ^  |   =  |  1   |   2  |  3   |  0   |-------|     |-------|MSBTN1|MSBTN2|  (   |   )  |      |      |
     * `-----------------------------------------/       /      \      \-----------------------------------------'
     *            | LALT | LGUI |EMOJI | SYMB | / SPACE /        \SPACE \  |NUMP  |EMOJI | RGUI | RALT |
     *            |      |      |      |      |/       /          \      \ |      |      |      |      |
     *            `-----------------------------------'            '------''---------------------------'
     */
    [_NUMP] = LAYOUT(
        KC_F1,  KC_F2,   KC_F3, KC_F4, KC_F5,  KC_F6,                  KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, KC_F12,
        ES_MINS,ES_PLUS, KC_7,  KC_8,  KC_9,   KC_COMM,                ES_RABK, KC_HOME, KC_UP, KC_END, XXXXXXX, _______,
        ES_SLSH,ES_ASTR, KC_4,  KC_5,  KC_6,   KC_DOT,                 ES_LABK, KC_LEFT, KC_DOWN, KC_RIGHT, XXXXXXX, _______,
        ES_CIRC, ES_EQL, KC_1, KC_2, KC_3, KC_0, _______,     _______, KC_MS_BTN1, KC_MS_BTN2, LSFT(KC_9), LSFT(KC_0), XXXXXXX, _______,
                _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
    ),

    /* _SYMB
     * ,----------------------------------------.                      ,-----------------------------------------.
     * |   ª  |   |  |  @   |  #   |  $   | %    |                     |   &  |   /  |   (  |   )  |   =  |  ?   |
     * |------+------+------+------+------+------|                     |------+------+------+------+------+------|
     * |      |  ´   |  `   |  ^   |      |      |                     |      | HOME | UP   | END  |PGUP  |      |
     * |------+------+------+------+------+------|                     |------+------+------+------+------+------|
     * |      |  {   |  }   |  [   |  ]   |  \   |-------.     ,-------|      | LEFT | DOWN |RIGHT |PGDOWN|      |
     * |------+------+------+------+------+------|  MUTE |     |       |------+------+------+------+------+------|
     * |      |  (   |  )   |  <   |  >   |PCREEN|-------|     |-------|      |      |      |      |  ~   |      |
     * `-----------------------------------------/       /      \      \-----------------------------------------'
     *            | LALT | LGUI |EMOJI | SYMB | / SPACE /        \SPACE \  |NUMP  |EMOJI | RGUI | RALT |
     *            |      |      |      |      |/       /          \      \ |      |      |      |      |
     *            `-----------------------------------'            '------''---------------------------'
     */
    [_SYMB] = LAYOUT(
        ES_MINS, ES_PIPE, ES_AT, ES_HASH, ES_DLR, KC_PERC,             ES_AMPR, ES_SLSH, ES_LPRN, ES_RPRN,  ES_EQL,  ES_QUES,
        _______, ES_ACUT, ES_GRV, ES_CIRC, _______, _______,           _______, KC_HOME, KC_UP,   KC_END,   KC_PGUP, _______,
        _______, ES_LCBR, ES_RCBR, ES_LBRC, ES_RBRC, ES_BSLS,          _______, KC_LEFT, KC_DOWN, KC_RIGHT, KC_PGDN, _______,
        _______, ES_LPRN, ES_RPRN, ES_LABK, ES_RABK, KC_PSCR, _______, _______, _______, _______, _______,  _______, KC_TILDE, _______,
                _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
    ),

    /* _EMOJI
     * ,-----------------------------------------.                     ,-----------------------------------------.
     * |      |      |      |      |      |      |                     |      |      |      |      |      |      |
     * |------+------+------+------+------+------|                     |------+------+------+------+------+------|
     * |      |FLIP  |TABLE |SHRUG |ಠ_ಠ  |  🚩  |                     |      |      |      |      |      |      |
     * |------+------+------+------+------+------|                     |------+------+------+------+------+------|
     * |      |  😂  | 🙌  |  😝  |  😆 |  😍  |-------.     ,-------|      |      |      |      |      |      |
     * |------+------+------+------+------+------|       |     |       |------+------+------+------+------+------|
     * |      |  😢  |  😭 |      |      |      |-------|     |-------|      |      |      |      |      |      |
     * `-----------------------------------------/       /      \      \-----------------------------------------'
     *            |      |      |      |      | /       /        \      \  |      |      |      |      |
     *            |      |      |      |      |/       /          \      \ |      |      |      |      |
     *            `-----------------------------------'            '------''---------------------------'
     */
    [_EMOJI] = LAYOUT(
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,           XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX, UC_FLIP, UC_TABL, UC_SHRG, UC_DISA, UC_RED,           XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX, UC_LOL,  UC_HAND, UC_XP,   UC_XD,   UC_LUV,           XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX, UC_SAD, UC_CRY, XXXXXXX, XXXXXXX, XXXXXXX,XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                 XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX
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
