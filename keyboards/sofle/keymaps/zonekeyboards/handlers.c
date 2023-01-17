#pragma once

enum sofle_layers {
    _BASE,
    _UP,
    _DOWN,
    _LEFT,
    _RIGHT,
    _TUNE
    };

enum custom_keycodes {
    DOWN = SAFE_RANGE,
    UP,
    LEFT,
    RIGHT,
    OS,
    KC_MOUSE_BTN1,
    KC_MOUSE_BTN2
        };

enum td_keycodes {
    ESCAPE,
    COMMAND,
    ALT,
    ESC_SYM
        };

enum unicode_names {
    ENIE,
    ACUTE,
    ECUTE,
    ICUTE,
    OCUTE,
    UCUTE,
    ENIELOW,
    ACUTELOW,
    ECUTELOW,
    ICUTELOW,
    OCUTELOW,
    UCUTELOW
};

const uint32_t unicode_map[] PROGMEM = {
    [ENIE]  = 0x00D1,  // Ñ
    [ACUTE]  = 0x00C1,  // Á
    [ECUTE]  = 0x00C9,  // É
    [ICUTE]  = 0x00CD,  // Í
    [OCUTE]  = 0x00D3,  // Ó
    [UCUTE]  = 0x00DA,  // Ú
    [ENIELOW]  = 0x00F1,  // ñ
    [ACUTELOW]  = 0x00E1,  // á
    [ECUTELOW]  = 0x00E9,  // é
    [ICUTELOW]  = 0x00ED,  // í
    [OCUTELOW]  = 0x00F3,  // ó
    [UCUTELOW]  = 0x00FA,  // ú
};
