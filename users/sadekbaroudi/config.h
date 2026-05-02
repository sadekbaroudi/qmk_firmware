#pragma once

// check to see if we are using the stenographobe, and skip if so... it has its own whole combo scheme
// see keyboards/fingerpunch/stenographobe/keymaps/*/config.h
#if defined(KEYBOARD_fingerpunch_stenographobe)
#elif defined(KEYBOARD_fingerpunch_arachnophobe)
#define COMBO_COUNT 15
#elif defined(KEYBOARD_fingerpunch_personal_smallcat)
#define COMBO_COUNT 53
#else
#define COMBO_COUNT 15
#endif

// -------------------- Combo config ------------------------

#define COMBO_TERM 75

// -------------------- Mouse keys config ------------------------

#ifdef MOUSEKEY_ENABLE
#  define MOUSEKEY_INTERVAL 16
#  define MOUSEKEY_DELAY 0
#  define MOUSEKEY_TIME_TO_MAX 60
#  define MOUSEKEY_MAX_SPEED 7
#  define MOUSEKEY_WHEEL_DELAY 0
#endif

// -------------------- Tap hold stuff config ------------------------

#define TAP_CODE_DELAY 25

#define QUICK_TAP_TERM 0

// -------------------- Leader key config ------------------------

#define LEADER_TIMEOUT 300
#define LEADER_PER_KEY_TIMING

// -------------------- Tap dance config ------------------------
#define TAPPING_TERM 175
#define TAPPING_TERM_PER_KEY

// ----------------- Cirque curved overlay override -----------------

#ifdef CIRQUE_CURVED_OVERLAY_ENABLE
    #define CIRQUE_PINNACLE_CURVED_OVERLAY
#endif

// -------------------- Encoder config ------------------------

// Override encoder settings for all keyboards except vulpes majora
#if !defined(KEYBOARD_fingerpunch_vulpes_majora_v1)
    #define FP_ENC_0_LAYER_VOLUME         0 // default - base layer
    #define FP_ENC_0_LAYER_PGUP_PGDN      1
    #define FP_ENC_0_LAYER_ZOOM           2
    #define FP_ENC_0_LAYER_DPI_POINTING   3
    #define FP_ENC_0_LAYER_SUPER_TAB      4 // right - homing thumb layer
    #define FP_ENC_0_LAYER_SUPER_CTRL_TAB 6
    #define FP_ENC_0_LAYER_SCROLL_WHEEL   7
    #define FP_ENC_0_LAYER_RGB_MODE       5 // right - reachy thumb layer
    #define FP_ENC_0_LAYER_RGB_HUE        8
    #define FP_ENC_0_LAYER_RGB_SAT        9
    #define FP_ENC_0_LAYER_RGB_VAL        10
#endif

// override the default for the scroll wheel encoder on the vulpes minora
#if defined(KEYBOARD_fingerpunch_vulpes_minora) && defined(FP_VIK_PERS60_MODULE)
    // vulpes minora with scroll wheel
    #undef FP_ENC_1_LAYER_SCROLL_WHEEL
    #undef FP_ENC_1_LAYER_SUPER_TAB
    #define FP_ENC_1_LAYER_RGB_MODE       3 // left - homing thumb layer
    #define FP_ENC_1_LAYER_PGUP_PGDN      1
    #define FP_ENC_1_LAYER_ZOOM           2
    #define FP_ENC_1_LAYER_DPI_POINTING   5
    #define FP_ENC_1_LAYER_SCROLL_WHEEL   0 // default - base layer
    #define FP_ENC_1_LAYER_SUPER_CTRL_TAB 6
    #define FP_ENC_1_LAYER_VOLUME         7
    #define FP_ENC_1_LAYER_SUPER_TAB      8
    #define FP_ENC_1_LAYER_RGB_HUE        4 // left - reachy thumb layer
    #define FP_ENC_1_LAYER_RGB_SAT        9
    #define FP_ENC_1_LAYER_RGB_VAL        10
#else
    // all other keyboards
    #define FP_ENC_1_LAYER_SUPER_TAB      3 // left - homing thumb layer
    #define FP_ENC_1_LAYER_PGUP_PGDN      1
    #define FP_ENC_1_LAYER_ZOOM           2
    #define FP_ENC_1_LAYER_DPI_POINTING   5
    #define FP_ENC_1_LAYER_SUPER_CTRL_TAB 0 // default - base layer
    #define FP_ENC_1_LAYER_SCROLL_WHEEL   6
    #define FP_ENC_1_LAYER_VOLUME         7
    #define FP_ENC_1_LAYER_RGB_MODE       8
    #define FP_ENC_1_LAYER_RGB_HUE        4 // left - reachy thumb layer
    #define FP_ENC_1_LAYER_RGB_SAT        9
    #define FP_ENC_1_LAYER_RGB_VAL        10
#endif

// -------------------- Pointing config ------------------------

#ifdef AUTO_MOUSE_DEFAULT_LAYER
    #undef AUTO_MOUSE_DEFAULT_LAYER
#endif
#define AUTO_MOUSE_DEFAULT_LAYER 6

// #ifdef CIRQUE_ENABLE
//     #define POINTING_DEVICE_AUTO_MOUSE_ENABLE
// #endif

// Define only one of the two below, but not both.
// Read here for details: https://github.com/sadekbaroudi/qmk_firmware/tree/master/keyboards/fingerpunch#layer-lighting

// #define FP_LAYER_LIGHTING_AUTO_MOUSE_ENABLE

#define FP_POINTING_SNIPING_LAYER_ENABLE
#define FP_POINTING_SCROLLING_LAYER_ENABLE
#define FP_POINTING_ZOOMING_LAYER_ENABLE

#ifdef FP_POINTING_SCROLLING_LAYER
    #undef FP_POINTING_SCROLLING_LAYER
#endif
#define FP_POINTING_SCROLLING_LAYER 4
#ifdef FP_POINTING_ZOOMING_LAYER
    #undef FP_POINTING_ZOOMING_LAYER
#endif
#define FP_POINTING_ZOOMING_LAYER 3

// -------------------- Lighting config ------------------------

// We override vulpes majora with the rgb lighting on the center trackball in the center, else config below for all other boards
#if defined(KEYBOARD_fingerpunch_vulpes_majora_v1) && defined(VIK_RGB_ONLY)
    #define FP_LAYER_LIGHTING_HUE_2 HSV_GREEN
    #define FP_LAYER_LIGHTING_HUE_3 HSV_PURPLE
    #define FP_LAYER_LIGHTING_HUE_4 HSV_YELLOW
    #define FP_LAYER_LIGHTING_HUE_5 HSV_PINK
#elif defined(KEYBOARD_fingerpunch_ffkb_lite_v1) && defined(VIK_EC11_EVQWGD001)
    #define FP_LAYER_LIGHTING_HUE_1 FP_HSV_MINT
    #define FP_LAYER_LIGHTING_HUE_2 HSV_CYAN
    #define FP_LAYER_LIGHTING_HUE_3 FP_HSV_LEMON
    #define FP_LAYER_LIGHTING_HUE_4 HSV_PURPLE
#else
    #define FP_LAYER_LIGHTING_HUE_2 FP_HSV_MINT
    #define FP_LAYER_LIGHTING_HUE_3 FP_HSV_LAVENDER
    #define FP_LAYER_LIGHTING_HUE_4 FP_HSV_LEMON
    #define FP_LAYER_LIGHTING_HUE_5 FP_HSV_MELON
#endif

// These are the colors I used on my ffkb low pro ks-27 with the xvx horizon purple and green keycaps
// #define FP_LAYER_LIGHTING_HUE_2 HSV_GREEN
// #define FP_LAYER_LIGHTING_HUE_3 HSV_ORANGE
// #define FP_LAYER_LIGHTING_HUE_4 HSV_YELLOW
// #define FP_LAYER_LIGHTING_HUE_5 HSV_CYAN
// #define FP_LAYER_LIGHTING_HUE_6 HSV_WHITE

#define RGBLIGHT_LAYERS_RETAIN_VAL

// To enable this, just pass RGB_MATRIX_REACTIVE_LAYERS=yes at the command line when building
// Also, you must make sure that RGB_MATRIX_SOLID_REACTIVE_SIMPLE is enabled
#if defined(RGB_MATRIX_ENABLE) && defined(RGB_MATRIX_REACTIVE_LAYERS)
#define FP_LAYER_LIGHTING_MODE_2 RGB_MATRIX_SOLID_REACTIVE_SIMPLE
#define FP_LAYER_LIGHTING_MODE_3 RGB_MATRIX_SOLID_REACTIVE_SIMPLE
#define FP_LAYER_LIGHTING_MODE_4 RGB_MATRIX_SOLID_REACTIVE_SIMPLE
#define FP_LAYER_LIGHTING_MODE_5 RGB_MATRIX_SOLID_REACTIVE_SIMPLE
#endif

// To enable this, just pass RGBLIGHT_SNAKE_LAYERS=yes at the command line when building
// Also, you must make sure that RGBLIGHT_MODE_SNAKE is enabled
#if defined(RGBLIGHT_ENABLE) && defined(RGBLIGHT_SNAKE_LAYERS)
#define FP_LAYER_LIGHTING_MODE_2 RGBLIGHT_MODE_SNAKE+1
#define FP_LAYER_LIGHTING_MODE_3 RGBLIGHT_MODE_SNAKE+1
#define FP_LAYER_LIGHTING_MODE_4 RGBLIGHT_MODE_SNAKE+1
#define FP_LAYER_LIGHTING_MODE_5 RGBLIGHT_MODE_SNAKE+1
#endif

// To enable this, just pass RGBLIGHT_TWINKLE_LAYERS=yes at the command line when building
// Also, you must make sure that RGBLIGHT_MODE_TWINKLE is enabled
#if defined(RGBLIGHT_ENABLE) && defined(RGBLIGHT_TWINKLE_LAYERS)
#define FP_LAYER_LIGHTING_MODE_2 RGBLIGHT_MODE_TWINKLE+1
#define FP_LAYER_LIGHTING_MODE_3 RGBLIGHT_MODE_TWINKLE+1
#define FP_LAYER_LIGHTING_MODE_4 RGBLIGHT_MODE_TWINKLE+1
#define FP_LAYER_LIGHTING_MODE_5 RGBLIGHT_MODE_TWINKLE+1
#endif

// To enable this, just pass RGB_LED_RING=yes at the command line when building
#if defined(RGBLIGHT_ENABLE) && defined(RGB_LED_RING)
#undef RGBLIGHT_LED_COUNT
#define RGBLIGHT_LED_COUNT 12
#endif

// To enable this, just pass RGB_MATRIX_BAND_VAL_LAYERS=yes at the command line when building
#if defined(RGB_MATRIX_ENABLE) && defined(RGB_MATRIX_BAND_VAL_LAYERS)
#define FP_LAYER_LIGHTING_MODE_2 RGB_MATRIX_BAND_VAL
#define FP_LAYER_LIGHTING_MODE_3 RGB_MATRIX_BAND_VAL
#define FP_LAYER_LIGHTING_MODE_4 RGB_MATRIX_BAND_VAL
#define FP_LAYER_LIGHTING_MODE_5 RGB_MATRIX_BAND_VAL
#endif
