#pragma once
#define EE_HANDS

// encoder support
#undef TAP_CODE_DELAY
#define TAP_CODE_DELAY 15

// Optimize compilation size
#ifndef NO_DEBUG
#    define NO_DEBUG
#endif // !NO_DEBUG
#if !defined(NO_PRINT) && !defined(CONSOLE_ENABLE)
#    define NO_PRINT
#endif // !NO_PRINT

// Pointer device
#define SPLIT_POINTING_ENABLE
#define POINTING_DEVICE_ROTATION_90
#define POINTING_DEVICE_RIGHT

// ws2812 RGB LED
#define RGBLIGHT_SLEEP
#define RGBLIGHT_LAYERS
#define RGB_DI_PIN D3

// RGB LIGHTS
#ifdef RGB_MATRIX_ENABLE
    #    define RGBLED_NUM 35 // Number of LEDs
    #    define RGBLED_NUM 35 // Number of LEDs
    #    define RGB_MATRIX_LED_COUNT RGBLED_NUM
#endif

#ifdef RGBLIGHT_ENABLE
    #    undef RGBLED_NUM
    #    define RGBLED_NUM 70
    #    define RGBLED_SPLIT  { 35, 35 } // haven't figured out how to use this yet
    #    define RGBLIGHT_LIMIT_VAL 150
    #    define RGBLIGHT_HUE_STEP 10
    #    define RGBLIGHT_SAT_STEP 17
    #    define RGBLIGHT_VAL_STEP 17
    // #define RGBLIGHT_EFFECT_BREATHING
    // #define RGBLIGHT_EFFECT_RAINBOW_MOOD
    // #define RGBLIGHT_EFFECT_RAINBOW_SWIRL
    // #define RGBLIGHT_EFFECT_SNAKE
    // #define RGBLIGHT_EFFECT_KNIGHT
    // #define RGBLIGHT_EFFECT_CHRISTMAS
    #define RGBLIGHT_EFFECT_STATIC_GRADIENT
    // #define RGBLIGHT_EFFECT_RGB_TEST
    // #define RGBLIGHT_EFFECT_ALTERNATING
    // #define RGBLIGHT_EFFECT_TWINKLE
#endif

#define UNICODE_SELECTED_MODES UNICODE_MODE_WINCOMPOSE
