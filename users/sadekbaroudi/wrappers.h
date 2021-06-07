#pragma once
#include "sadekbaroudi.h"
/*
Since our quirky block definitions are basically a list of comma separated
arguments, we need a wrapper in order for these definitions to be
expanded before being used as arguments to the LAYOUT_xxx macro.
*/
#if (!defined(LAYOUT) && defined(KEYMAP))
#    define LAYOUT KEYMAP
#endif

// Since Reviung39 uses the name LAYOUT_reviung39 instead of LAYOUT
#if (!defined(LAYOUT) && defined(LAYOUT_reviung39))
#    define LAYOUT LAYOUT_reviung39
#endif

// Since Reviung41 uses the name LAYOUT_reviung41 instead of LAYOUT
#if (!defined(LAYOUT) && defined(LAYOUT_reviung41))
#    define LAYOUT LAYOUT_reviung41
#endif

// Since Reviung39 uses the name LAYOUT_reviung39 instead of LAYOUT
#if (!defined(LAYOUT) && defined(LAYOUT_ortho_5x12))
#    define LAYOUT LAYOUT_ortho_5x12
#endif

// Since enigma36 uses the name LAYOUT_enigma36 instead of LAYOUT
#if (!defined(LAYOUT) && defined(LAYOUT_enigma36))
#    define LAYOUT LAYOUT_enigma36
#endif

// Since Euclid36 uses the name LAYOUT_euclid36 instead of LAYOUT
#if (!defined(LAYOUT) && defined(LAYOUT_euclid36))
#    define LAYOUT LAYOUT_euclid36
#endif

// Since euclid36proto uses the name LAYOUT_euclid36proto instead of LAYOUT
#if (!defined(LAYOUT) && defined(LAYOUT_euclid36proto))
#    define LAYOUT LAYOUT_euclid36proto
#endif

// Since pteron38 uses the name LAYOUT_pteron38 instead of LAYOUT
#if (!defined(LAYOUT) && defined(LAYOUT_pteron38))
#    define LAYOUT LAYOUT_pteron38
#endif


// clang-format off
#define LAYOUT_ergodox_wrapper(...)          LAYOUT_ergodox(__VA_ARGS__)
#define LAYOUT_ergodox_pretty_wrapper(...)   LAYOUT_ergodox_pretty(__VA_ARGS__)
#define KEYMAP_wrapper(...)                  LAYOUT(__VA_ARGS__)
#define LAYOUT_wrapper(...)                  LAYOUT(__VA_ARGS__)
#define LAYOUT_ortho_4x12_wrapper(...)       LAYOUT_ortho_4x12(__VA_ARGS__)
#define LAYOUT_ortho_5x12_wrapper(...)       LAYOUT_ortho_5x12(__VA_ARGS__)
#define LAYOUT_gergo_wrapper(...)            LAYOUT_gergo(__VA_ARGS__)
#define LAYOUT_split_3x6_3_wrapper(...)      LAYOUT_split_3x6_3(__VA_ARGS__)
#define LAYOUT_reviung39_wrapper(...)        LAYOUT_reviung39(__VA_ARGS__)
#define LAYOUT_pteron38_wrapper(...)         LAYOUT_pteron38(__VA_ARGS__)

/*
Blocks for each of the four major keyboard layouts
Organized so we can quickly adapt and modify all of them
at once, rather than for each keyboard, one at a time.
And this allows for much cleaner blocks in the keymaps.
For instance Tap/Hold for Control on all of the layouts

NOTE: These are all the same length.  If you do a search/replace
  then you need to add/remove underscores to keep the
  lengths consistent.
*/

#define _________________META_NAV_1________________			KC_ESC,  KC_PGUP, KC_UP,   KC_PGDN, _______
#define _________________META_NAV_2________________			KC_HOME, KC_LEFT, KC_DOWN, KC_RGHT, KC_END

#define _________________META_NAV_L1_______________			KC_CAPS,               KC_GRV,                LCTL(LSFT(KC_TAB)),    LCTL(LGUI(KC_LEFT)),   _______
#define _________________META_NAV_R1_______________			_______,               LCTL(LGUI(KC_RIGHT)),  LCTL(KC_TAB),          _______,               KC_BSLS

#define __________________WIN_NAV_1________________			_______,               _______,               LGUI(KC_UP),           _______,               _______
#define __________________WIN_NAV_2________________			_______,               LGUI(KC_LEFT),         LGUI(KC_DOWN),         LGUI(KC_RGHT),         _______

#define _________________QWERTY_L1_________________			KC_Q,    KC_W,    KC_E,    KC_R,    KC_T
#define _________________QWERTY_L2_________________			KC_A,    KC_S,    KC_D,    KC_F,    KC_G
#define _________________QWERTY_L3_________________			KC_Z,    KC_X,    KC_C,    KC_V,    KC_B

#define _________________QWERTY_R1_________________			KC_Y,    KC_U,    KC_I,    KC_O,    KC_P
#define _________________QWERTY_R2_________________			KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN
#define _________________QWERTY_R3_________________			KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLASH

#define _________________COLEMAK_L1________________			KC_Q,    KC_W,    KC_F,    KC_P,    KC_G
#define _________________COLEMAK_L2________________			KC_A,    KC_R,    KC_S,    KC_T,    KC_D
#define _________________COLEMAK_L3________________			KC_Z,    KC_X,    KC_C,    KC_V,    KC_B

#define _________________COLEMAK_R1________________			KC_J,    KC_L,    KC_U,    KC_Y,    KC_SCLN
#define _________________COLEMAK_R2________________			KC_H,    KC_N,    KC_E,    KC_I,    KC_O
#define _________________COLEMAK_R3________________			KC_K,    KC_M,    KC_COMM, KC_DOT,  KC_SLASH

#define ______________COLEMAK_MOD_DH_L1____________			KC_Q,    KC_W,    KC_F,    KC_P,    KC_B
#define ______________COLEMAK_MOD_DH_L2____________			KC_A,    KC_R,    KC_S,    KC_T,    KC_G
#define ______________COLEMAK_MOD_DH_L3____________			KC_Z,    KC_X,    KC_C,    KC_D,    KC_V

#define ______________COLEMAK_MOD_DH_R1____________			KC_J,    KC_L,    KC_U,    KC_Y,    KC_SCLN
#define ______________COLEMAK_MOD_DH_R2____________			KC_M,    KC_N,    KC_E,    KC_I,    KC_O
#define ______________COLEMAK_MOD_DH_R3____________			KC_K,    KC_H,    KC_COMM, KC_DOT,  KC_SLASH

#define _________________WORKMAN_L1________________			KC_Q,    KC_D,    KC_R,   KC_W,     KC_B
#define _________________WORKMAN_L2________________			KC_A,    KC_S,    KC_H,   KC_T,     KC_G
#define _________________WORKMAN_L3________________			KC_Z,    KC_X,    KC_M,   KC_C,     KC_V

#define _________________WORKMAN_R1________________			KC_J,    KC_F,    KC_U,    KC_P,    KC_SCLN
#define _________________WORKMAN_R2________________			KC_Y,    KC_N,    KC_E,    KC_O,    KC_I
#define _________________WORKMAN_R3________________			KC_K,    KC_L,    KC_COMM, KC_DOT,  KC_SLASH

#define ___________________BLANK___________________			_______, _______, _______, _______, _______

#define ________________NAVIGATION_1_______________			_________________META_NAV_1________________
#define ________________NAVIGATION_2_______________			_________________META_NAV_2________________
#define ________________NAVIGATION_3_______________			LCTL(KC_Z), LCTL(KC_X), LCTL(KC_C), _______, LCTL(KC_V)

#define _________________NUMPAD_1__________________			KC_ASTR, KC_7,    KC_8,    KC_9,    KC_PLUS
#define _________________NUMPAD_2__________________			KC_SLSH, KC_4,    KC_5,    KC_6,    KC_MINS
#define _________________NUMPAD_3__________________			KC_EQL,  KC_1,    KC_2,    KC_3,    KC_0

#define ________________SYMBOLS_L1_________________			KC_EXLM,               KC_AT,                 KC_HASH,               KC_DLR,                KC_PERC
#define ________________SYMBOLS_L2_________________			KC_MINS,               KC_LBRC,               KC_LCBR,               KC_LPRN,               KC_LT
#define ________________SYMBOLS_L3_________________			_________________META_NAV_L1_______________

#define ________________SYMBOLS_R1_________________			KC_CIRC,               KC_AMPR,               KC_ASTR,               KC_UNDS,               KC_EQL
#define ________________SYMBOLS_R2_________________			KC_GT,                 KC_RPRN,               KC_RCBR,               KC_RBRC,               KC_PLUS
#define ________________SYMBOLS_R3_________________			_________________META_NAV_R1_______________

#define ________________SHIFTNAV_1_________________			_______,               LSFT(KC_PGDN),         LSFT(KC_UP),           LSFT(KC_PGUP),         _______
#define ________________SHIFTNAV_2_________________			LSFT(KC_HOME),         LSFT(KC_LEFT),         LSFT(KC_DOWN),         LSFT(KC_RGHT),         LSFT(KC_END)
#define ________________SHIFTNAV_3_________________			LCTL(KC_Z),            LCTL(KC_X),            LCTL(KC_C),            LCTL(KC_V),            _______

#define ________________FUNCTION_1_________________			KC_MPLY,               KC_F7,                 KC_F8,                 KC_F9,                 KC_F10
#define ________________FUNCTION_2_________________			KC_VOLU,               KC_F4,                 KC_F5,                 KC_F6,                 KC_F11
#define ________________FUNCTION_3_________________			KC_VOLD,               KC_F1,                 KC_F2,                 KC_F3,                 KC_F12

#define ___________________RGB_1___________________			RGB_TOG,               RGB_MODE_REVERSE,      RGB_MODE_FORWARD,      _______,               TG(_QWERTY)
#define ___________________RGB_2___________________			KC_RGB_BLT,            RGB_HUI,               RGB_SAI,               RGB_VAI,               TG(_COLEMAK)
#define ___________________RGB_3___________________			KC_RGB_T,              RGB_HUD,               RGB_SAD,               RGB_VAD,               TG(_WORKMAN)

#define __________________MOUSE_1__________________			RESET,                 KC_MS_WH_UP,           KC_MS_UP,              KC_MS_WH_DOWN,         _______
#define __________________MOUSE_2__________________			KC_MS_WH_LEFT,         KC_MS_LEFT,            KC_MS_DOWN,            KC_MS_RIGHT,           KC_MS_WH_RIGHT
#define __________________MOUSE_3__________________			KC_MS_ACCEL0,          KC_MS_ACCEL1,          KC_MS_ACCEL2,          _______,               _______


// COMMENT TO REENABLE MACROS
#define _________________MACROS_1__________________			___________________BLANK___________________
#define _________________MACROS_2__________________			___________________BLANK___________________
#define _________________MACROS_3__________________			___________________BLANK___________________

// UNCOMMENT TO REENABLE MACROS
// #define _________________MACROS_1__________________			VRSN,                  L_FIND,                L_GITCOMMIT,           _______,               E_ROBOT
// #define _________________MACROS_2__________________			P_ANGBRKT,             P_PAREN,               P_CURLY,               P_BRKT,                _______
// #define _________________MACROS_3__________________			KC_MAKE,               L_GREP,                _______,               _______,               E_CAT

// clang-format on
