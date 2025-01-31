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
#define SPLIT_LAYER_STATE_ENABLE
#define SPLIT_LED_STATE_ENABLE
#define SPLIT_MODS_ENABLE

#ifndef POINTING_DEVICE_ENABLE
#    define SPLIT_WATCHDOG_ENABLE
//#    define POINTING_DEVICE_ROTATION_180
#    define POINTING_DEVICE_RIGHT
#endif

#ifdef WPM_ENABLE
#    define SPLIT_WPM_ENABLE
#endif

#ifdef OLED_ENABLE
#    undef SPLIT_OLED_ENABLE
#endif

// ws2812 RGB LED
#define RGB_DI_PIN D3
#define RGBLIGHT_SLEEP
#define RGBLIGHT_LAYERS

#ifdef RGB_MATRIX_ENABLE
#    define RGBLED_NUM 72
#    define RGB_MATRIX_LED_COUNT RGBLED_NUM
#    define RGB_MATRIX_MAXIMUM_BRIGHTNESS 120 // limits maximum brightness of LEDs to 150 out of 255. Higher may cause the controller to crash.
#    define RGB_MATRIX_HUE_STEP 8
#    define RGB_MATRIX_SAT_STEP 8
#    define RGB_MATRIX_VAL_STEP 8
#    define RGB_MATRIX_SPD_STEP 10
#    define RGB_MATRIX_SPLIT { 36, 36 }
#    define RGB_MATRIX_TIMEOUT 360000 // 360 seconds
#    define RGB_DISABLE_WHEN_USB_SUSPENDED
#endif

// RGB Lights
#ifdef RGBLIGHT_ENABLE
// #define RGBLIGHT_SLEEP
// #define RGBLIGHT_TIMEOUT 360000 // 360 seconds
#    define RGBLIGHT_LAYERS
#    undef RGBLED_NUM
#    define RGBLED_NUM 70
#    define RGBLED_SPLIT { 35, 35 }
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
// #define RGBLIGHT_EFFECT_STATIC_GRADIENT
// #define RGBLIGHT_EFFECT_RGB_TEST
// #define RGBLIGHT_EFFECT_ALTERNATING
// #define RGBLIGHT_EFFECT_TWINKLE
#endif

#define MEDIA_KEY_DELAY 2
#define UNICODE_SELECTED_MODES UNICODE_MODE_WINCOMPOSE
