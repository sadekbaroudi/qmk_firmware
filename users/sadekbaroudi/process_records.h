#pragma once
#include "sadekbaroudi.h"

#if defined(KEYMAP_SAFE_RANGE)
#    define PLACEHOLDER_SAFE_RANGE KEYMAP_SAFE_RANGE
#else
#    define PLACEHOLDER_SAFE_RANGE SAFE_RANGE
#endif

enum userspace_custom_keycodes {
    VRSN = PLACEHOLDER_SAFE_RANGE,  // Prints QMK Firmware and board info
    KC_RGB_T,                       // Toggles RGB Layer Indication mode
    KC_RGB_BLT,                     // Toggles RGB Base Layer Override mode
    RGB_IDL,                        // RGB Idling animations
    // COMMENT TO DISABLE MACROS
    KC_MAKE,                        // Run keyboard's customized make command
    L_GREP,
    L_FIND,
    L_GITCOMMIT,
    P_ANGBRKT,
    P_PAREN,
    P_CURLY,
    P_BRKT,
    P_ARROW,
    E_ROBOT,
    E_CAT,
    C_CAPSWORD,
    C_HYPHENCASE,
    C_UNDERSCORECASE,
    NEW_SAFE_RANGE                  // use "NEWPLACEHOLDER for keymap specific codes
};

bool process_record_secrets(uint16_t keycode, keyrecord_t *record);
bool process_record_keymap(uint16_t keycode, keyrecord_t *record);

#define KC_SEC1 KC_SECRET_1
#define KC_SEC2 KC_SECRET_2
#define KC_SEC3 KC_SECRET_3
#define KC_SEC4 KC_SECRET_4
#define KC_SEC5 KC_SECRET_5

#define KC_RESET RESET
#define KC_RST   KC_RESET
