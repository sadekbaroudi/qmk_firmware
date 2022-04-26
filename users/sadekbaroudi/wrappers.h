#pragma once
#include "sadekbaroudi.h"
/*
Since our quirky block definitions are basically a list of comma separated
arguments, we need a wrapper in order for these definitions to be
expanded before being used as arguments to the LAYOUT_xxx macro.
*/

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

// Since barobordhw uses the name LAYOUT_barobordhw instead of LAYOUT
#if (!defined(LAYOUT) && defined(LAYOUT_barobordhw))
#    define LAYOUT LAYOUT_barobordhw
#endif

// Since barobord uses the name LAYOUT_barobord instead of LAYOUT
#if (!defined(LAYOUT) && defined(LAYOUT_barobord))
#    define LAYOUT LAYOUT_barobord
#endif

// Since barobord uses the name LAYOUT_barobord instead of LAYOUT
#if (!defined(LAYOUT) && defined(LAYOUT_ortho_4x12))
#    define LAYOUT LAYOUT_ortho_4x12
#endif

// Since halfdash uses the name LAYOUT_halfdash instead of LAYOUT
#if (!defined(LAYOUT) && defined(LAYOUT_halfdash))
#    define LAYOUT LAYOUT_halfdash
#endif

// Since ffkbhw uses the name LAYOUT_ffkbhw instead of LAYOUT
#if (!defined(LAYOUT) && defined(LAYOUT_ffkbhw))
#    define LAYOUT LAYOUT_ffkbhw
#endif

// Since ffkbhw uses the name LAYOUT_ffkb instead of LAYOUT
#if (!defined(LAYOUT) && defined(LAYOUT_ffkb))
#    define LAYOUT LAYOUT_ffkb
#endif

// Since bgkeeb uses the name LAYOUT_bgkeeb instead of LAYOUT
#if (!defined(LAYOUT) && defined(LAYOUT_bgkeeb))
#    define LAYOUT LAYOUT_bgkeeb
#endif

// Since absolem uses the name LAYOUT_absolem instead of LAYOUT
#if (!defined(LAYOUT) && defined(LAYOUT_absolem))
#    define LAYOUT LAYOUT_absolem
#endif

// Since pinkiesout uses the name LAYOUT_pinkiesout instead of LAYOUT
#if (!defined(LAYOUT) && defined(LAYOUT_pinkiesout))
#    define LAYOUT LAYOUT_pinkiesout
#endif

// Since rockon uses the name LAYOUT_rockon instead of LAYOUT
#if (!defined(LAYOUT) && defined(LAYOUT_rockon))
#    define LAYOUT LAYOUT_rockon
#endif

// Since rockon_bp uses the name LAYOUT_rockon_bp instead of LAYOUT
#if (!defined(LAYOUT) && defined(LAYOUT_rockon_bp))
#    define LAYOUT LAYOUT_rockon_bp
#endif

// Since luakeeb uses the name LAYOUT_luakeeb instead of LAYOUT
#if (!defined(LAYOUT) && defined(LAYOUT_luakeeb))
#    define LAYOUT LAYOUT_luakeeb
#endif

// Since sweeeeep uses the name LAYOUT_sweeeeep instead of LAYOUT
#if (!defined(LAYOUT) && defined(LAYOUT_sweeeeep))
#    define LAYOUT LAYOUT_sweeeeep
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
#define LAYOUT_ffkbhw_wrapper(...)           LAYOUT_ffkbhw(__VA_ARGS__)

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


#define __ALPHA_THUMB_L1__ KC_DEL
#define __ALPHA_THUMB_L2__ KC_ENT
#define __ALPHA_THUMB_L3__ KC_TAB
#define __ALPHA_THUMB_R1__ KC_BSPC
#define __ALPHA_THUMB_R2__ KC_SPACE
#define __ALPHA_THUMB_R3__ KC_QUOT

#define __ALPHA_THUMBS_LEFT_2__                             __ALPHA_THUMB_L2__, __ALPHA_THUMB_L3__
#define __ALPHA_THUMBS_RIGHT_2__                            __ALPHA_THUMB_R1__, __ALPHA_THUMB_R2__

#define __ALPHA_THUMBS_LEFT_3__                             __ALPHA_THUMB_L1__, __ALPHA_THUMB_L2__, __ALPHA_THUMB_L3__
#define __ALPHA_THUMBS_RIGHT_3__                            __ALPHA_THUMB_R1__, __ALPHA_THUMB_R2__, __ALPHA_THUMB_R3__

#define __ALPHA_THUMBS_4__                                  __ALPHA_THUMBS_LEFT_2__, __ALPHA_THUMBS_RIGHT_2__
#define __ALPHA_THUMBS_5__                                  __ALPHA_THUMB_L1__, __ALPHA_THUMB_L2__, __ALPHA_THUMB_R1__, __ALPHA_THUMB_R2__, __ALPHA_THUMB_R3__
#define __ALPHA_THUMBS_6__                                  __ALPHA_THUMBS_LEFT_3__, __ALPHA_THUMBS_RIGHT_3__

#define __ALPHA_ALT_THUMB_L1__ __ALPHA_THUMB_L1__
#define __ALPHA_ALT_THUMB_L2__ KC_O
#define __ALPHA_ALT_THUMB_L3__ __ALPHA_THUMB_L3__
#define __ALPHA_ALT_THUMB_R1__ __ALPHA_THUMB_R1__
#define __ALPHA_ALT_THUMB_R2__ __ALPHA_THUMB_R2__
#define __ALPHA_ALT_THUMB_R3__ __ALPHA_THUMB_R3__

#define __ALPHA_ALT_THUMBS_LEFT_2__                         __ALPHA_ALT_THUMB_L2__, __ALPHA_ALT_THUMB_L3__
#define __ALPHA_ALT_THUMBS_RIGHT_2__                        __ALPHA_ALT_THUMB_R1__, __ALPHA_ALT_THUMB_R2__

#define __ALPHA_ALT_THUMBS_LEFT_3__                         __ALPHA_ALT_THUMB_L1__, __ALPHA_ALT_THUMB_L2__, __ALPHA_ALT_THUMB_L3__
#define __ALPHA_ALT_THUMBS_RIGHT_3__                        __ALPHA_ALT_THUMB_R1__, __ALPHA_ALT_THUMB_R2__, __ALPHA_ALT_THUMB_R3__

#define __ALPHA_ALT_THUMBS_4__                              __ALPHA_ALT_THUMBS_LEFT_2__, __ALPHA_ALT_THUMBS_RIGHT_2__
#define __ALPHA_ALT_THUMBS_5__                              __ALPHA_ALT_THUMB_L1__, __ALPHA_ALT_THUMB_L2__, __ALPHA_ALT_THUMB_R1__, __ALPHA_ALT_THUMB_R2__, __ALPHA_ALT_THUMB_R3__
#define __ALPHA_ALT_THUMBS_6__                              __ALPHA_ALT_THUMBS_LEFT_3__, __ALPHA_ALT_THUMBS_RIGHT_3__


#define _________________ALPHA_ALT_L1_________________			KC_Q,    KC_W,    KC_F,    KC_P,    KC_B
#define _________________ALPHA_ALT_L2_________________			KC_A,    KC_R,    KC_S,    KC_T,    KC_G
#define _________________ALPHA_ALT_L3_________________			KC_Z,    KC_X,    KC_C,    KC_D,    KC_V

#define _________________ALPHA_ALT_R1_________________			KC_J,    KC_L,    KC_U,    KC_Y,    KC_SCLN
#define _________________ALPHA_ALT_R2_________________			KC_M,    KC_N,    KC_E,    KC_I,    KC_H
#define _________________ALPHA_ALT_R3_________________			KC_K,    KC_NO,   KC_COMM, KC_DOT,  KC_SLASH

/* This is the target
#define _________________ALPHA_ALT_L1_________________			KC_ENT,  KC_Q,    KC_W,    KC_P,    KC_B
#define _________________ALPHA_ALT_L2_________________			KC_A,    KC_R,    KC_S,    KC_T,    KC_G
#define _________________ALPHA_ALT_L3_________________			KC_Z,    KC_X,    KC_C,    KC_D,    KC_V

#define _________________ALPHA_ALT_R1_________________			KC_J,    KC_L,    KC_U,    KC_Y,    KC_SCLN
#define _________________ALPHA_ALT_R2_________________			KC_F,    KC_N,    KC_E,    KC_I,    KC_H
#define _________________ALPHA_ALT_R3_________________			KC_K,    KC_M,    KC_COMM, KC_DOT,  KC_SLASH
*/

// ALPHA
#define __________________ALPHA_L1____________________			KC_Q,    KC_W,    KC_F,    KC_P,    KC_B
#define __________________ALPHA_L2____________________			KC_A,    KC_R,    KC_S,    KC_T,    KC_G
#define __________________ALPHA_L3____________________			KC_Z,    KC_X,    KC_C,    KC_D,    KC_V

#define __________________ALPHA_R1____________________			KC_J,    KC_L,    KC_U,    KC_Y,    KC_SCLN
#define __________________ALPHA_R2____________________			KC_M,    KC_N,    KC_E,    KC_I,    KC_O
#define __________________ALPHA_R3____________________			KC_K,    KC_H,    KC_COMM, KC_DOT,  KC_SLASH

// BLANK FULL LINE
#define ___________________BLANK___________________			_______, _______, _______, _______, _______

// NAVIGATION

#define __META_NAV_1_K1__ KC_ESC
#define __META_NAV_1_K2__ KC_PGUP
#define __META_NAV_1_K3__ KC_UP
#define __META_NAV_1_K4__ KC_PGDN
#define __META_NAV_1_K5__ _______

#define __META_NAV_2_K1__ KC_HOME
#define __META_NAV_2_K2__ KC_LEFT
#define __META_NAV_2_K3__ KC_DOWN
#define __META_NAV_2_K4__ KC_RGHT
#define __META_NAV_2_K5__ KC_END

#define _________________META_NAV_1________________     __META_NAV_1_K1__, __META_NAV_1_K2__, __META_NAV_1_K3__, __META_NAV_1_K4__, __META_NAV_1_K5__
#define _________________META_NAV_2________________     __META_NAV_2_K1__, __META_NAV_2_K2__, __META_NAV_2_K3__, __META_NAV_2_K4__, __META_NAV_2_K5__

#define __NAV_3_K1__ LCTL(KC_Z)
#define __NAV_3_K2__ LCTL(KC_X)
#define __NAV_3_K3__ LCTL(KC_C)
#define __NAV_3_K4__ _______
#define __NAV_3_K5__ LCTL(KC_V)

#define ________________NAVIGATION_1_______________			_________________META_NAV_1________________
#define ________________NAVIGATION_2_______________			_________________META_NAV_2________________
#define ________________NAVIGATION_3_______________			__NAV_3_K1__, __NAV_3_K2__, __NAV_3_K3__, __NAV_3_K4__, __NAV_3_K5__

#define __NUMPAD_1_K1__ KC_ASTR
#define __NUMPAD_1_K2__ KC_7
#define __NUMPAD_1_K3__ KC_8
#define __NUMPAD_1_K4__ KC_9
#define __NUMPAD_1_K5__ KC_MINS

#define __NUMPAD_2_K1__ KC_SLSH
#define __NUMPAD_2_K2__ KC_4
#define __NUMPAD_2_K3__ KC_5
#define __NUMPAD_2_K4__ KC_6
#define __NUMPAD_2_K5__ KC_PLUS

#define __NUMPAD_3_K1__ KC_EQL
#define __NUMPAD_3_K2__ KC_1
#define __NUMPAD_3_K3__ KC_2
#define __NUMPAD_3_K4__ KC_3
#define __NUMPAD_3_K5__ KC_0

#define _________________NUMPAD_1__________________			__NUMPAD_1_K1__, __NUMPAD_1_K2__, __NUMPAD_1_K3__, __NUMPAD_1_K4__, __NUMPAD_1_K5__
#define _________________NUMPAD_2__________________			__NUMPAD_2_K1__, __NUMPAD_2_K2__, __NUMPAD_2_K3__, __NUMPAD_2_K4__, __NUMPAD_2_K5__
#define _________________NUMPAD_3__________________			__NUMPAD_3_K1__, __NUMPAD_3_K2__, __NUMPAD_3_K3__, __NUMPAD_3_K4__, __NUMPAD_3_K5__

// SYMBOLS

#define __SYMBOLS_L1_K1__ KC_EXLM
#define __SYMBOLS_L1_K2__ KC_AT
#define __SYMBOLS_L1_K3__ KC_HASH
#define __SYMBOLS_L1_K4__ KC_DLR
#define __SYMBOLS_L1_K5__ KC_PERC

#define __SYMBOLS_L2_K1__ KC_MINS
#define __SYMBOLS_L2_K2__ KC_LBRC
#define __SYMBOLS_L2_K3__ KC_LCBR
#define __SYMBOLS_L2_K4__ KC_LPRN
#define __SYMBOLS_L2_K5__ KC_LT

#define __META_NAV_L1_K1__ KC_CAPS
#define __META_NAV_L1_K2__ KC_GRV
#define __META_NAV_L1_K3__ LCTL(LSFT(KC_TAB))
#define __META_NAV_L1_K4__ LCTL(LGUI(KC_LEFT))
#define __META_NAV_L1_K5__ C_CAPSWORD

#define __SYMBOLS_R1_K1__ KC_CIRC
#define __SYMBOLS_R1_K2__ KC_AMPR
#define __SYMBOLS_R1_K3__ KC_ASTR
#define __SYMBOLS_R1_K4__ KC_UNDS
#define __SYMBOLS_R1_K5__ KC_EQL

#define __SYMBOLS_R2_K1__ KC_GT
#define __SYMBOLS_R2_K2__ KC_RPRN
#define __SYMBOLS_R2_K3__ KC_RCBR
#define __SYMBOLS_R2_K4__ KC_RBRC
#define __SYMBOLS_R2_K5__ KC_PLUS

#define __META_NAV_L2_K1__ C_UNDERSCORECASE
#define __META_NAV_L2_K2__ LCTL(LGUI(KC_RIGHT))
#define __META_NAV_L2_K3__ LCTL(KC_TAB)
#define __META_NAV_L2_K4__ C_ANYCASE
#define __META_NAV_L2_K5__ KC_BSLS


#define _________________META_NAV_L1_______________     __META_NAV_L1_K1__, __META_NAV_L1_K2__, __META_NAV_L1_K3__, __META_NAV_L1_K4__, __META_NAV_L1_K5__
#define _________________META_NAV_R1_______________     __META_NAV_L2_K1__, __META_NAV_L2_K2__, __META_NAV_L2_K3__, __META_NAV_L2_K4__, __META_NAV_L2_K5__

#define ________________SYMBOLS_L1_________________			__SYMBOLS_L1_K1__, __SYMBOLS_L1_K2__, __SYMBOLS_L1_K3__, __SYMBOLS_L1_K4__, __SYMBOLS_L1_K5__
#define ________________SYMBOLS_L2_________________			__SYMBOLS_L2_K1__, __SYMBOLS_L2_K2__, __SYMBOLS_L2_K3__, __SYMBOLS_L2_K4__, __SYMBOLS_L2_K5__
#define ________________SYMBOLS_L3_________________			_________________META_NAV_L1_______________

#define ________________SYMBOLS_R1_________________			__SYMBOLS_R1_K1__, __SYMBOLS_R1_K2__, __SYMBOLS_R1_K3__, __SYMBOLS_R1_K4__, __SYMBOLS_R1_K5__
#define ________________SYMBOLS_R2_________________			__SYMBOLS_R2_K1__, __SYMBOLS_R2_K2__, __SYMBOLS_R2_K3__, __SYMBOLS_R2_K4__, __SYMBOLS_R2_K5__
#define ________________SYMBOLS_R3_________________			_________________META_NAV_R1_______________

// SHIFT NAVIGATION LAYER

#define __SHIFTNAV_1_K1__ _______
#define __SHIFTNAV_1_K2__ LSFT(KC_PGUP)
#define __SHIFTNAV_1_K3__ LSFT(KC_UP)
#define __SHIFTNAV_1_K4__ LSFT(KC_PGDN)
#define __SHIFTNAV_1_K5__ _______

#define __SHIFTNAV_2_K1__ LSFT(KC_HOME)
#define __SHIFTNAV_2_K2__ LSFT(KC_LEFT)
#define __SHIFTNAV_2_K3__ LSFT(KC_DOWN)
#define __SHIFTNAV_2_K4__ LSFT(KC_RGHT)
#define __SHIFTNAV_2_K5__ LSFT(KC_END)

#define __SHIFTNAV_3_K1__ LCTL(KC_Z)
#define __SHIFTNAV_3_K2__ LCTL(KC_X)
#define __SHIFTNAV_3_K3__ LCTL(KC_C)
#define __SHIFTNAV_3_K4__ KC_MUTE
#define __SHIFTNAV_3_K5__ LCTL(KC_V)

#define ________________SHIFTNAV_1_________________			__SHIFTNAV_1_K1__, __SHIFTNAV_1_K2__, __SHIFTNAV_1_K3__, __SHIFTNAV_1_K4__, __SHIFTNAV_1_K5__
#define ________________SHIFTNAV_2_________________			__SHIFTNAV_2_K1__, __SHIFTNAV_2_K2__, __SHIFTNAV_2_K3__, __SHIFTNAV_2_K4__, __SHIFTNAV_2_K5__
#define ________________SHIFTNAV_3_________________			__SHIFTNAV_3_K1__, __SHIFTNAV_3_K2__, __SHIFTNAV_3_K3__, __SHIFTNAV_3_K4__, __SHIFTNAV_3_K5__

#define __FUNCION_1_K1__ KC_MPLY
#define __FUNCION_1_K2__ KC_F7
#define __FUNCION_1_K3__ KC_F8
#define __FUNCION_1_K4__ KC_F9
#define __FUNCION_1_K5__ KC_F10

#define __FUNCION_2_K1__ KC_VOLU
#define __FUNCION_2_K2__ KC_F4
#define __FUNCION_2_K3__ KC_F5
#define __FUNCION_2_K4__ KC_F6
#define __FUNCION_2_K5__ KC_F11

#define __FUNCION_3_K1__ KC_VOLD
#define __FUNCION_3_K2__ KC_F1
#define __FUNCION_3_K3__ KC_F2
#define __FUNCION_3_K4__ KC_F3
#define __FUNCION_3_K5__ KC_F12

#define ________________FUNCTION_1_________________			__FUNCION_1_K1__, __FUNCION_1_K2__, __FUNCION_1_K3__, __FUNCION_1_K4__, __FUNCION_1_K5__
#define ________________FUNCTION_2_________________			__FUNCION_2_K1__, __FUNCION_2_K2__, __FUNCION_2_K3__, __FUNCION_2_K4__, __FUNCION_2_K5__
#define ________________FUNCTION_3_________________			__FUNCION_3_K1__, __FUNCION_3_K2__, __FUNCION_3_K3__, __FUNCION_3_K4__, __FUNCION_3_K5__

// MEDIA LAYER

#define __RGB_1_K1__ RGB_TOG
#define __RGB_1_K2__ RGB_MODE_REVERSE
#define __RGB_1_K3__ RGB_MODE_FORWARD
#define __RGB_1_K4__ _______
#define __RGB_1_K5__ TG(_ALPHA_ALT)

#define __RGB_2_K1__ KC_RGB_BLT
#define __RGB_2_K2__ RGB_HUI
#define __RGB_2_K3__ RGB_SAI
#define __RGB_2_K4__ RGB_VAI
#define __RGB_2_K5__ TG(_ALPHA)

#define __RGB_3_K1__ KC_RGB_T
#define __RGB_3_K2__ RGB_HUD
#define __RGB_3_K3__ RGB_SAD
#define __RGB_3_K4__ RGB_VAD
#define __RGB_3_K5__ _______

#define ___________________RGB_1___________________			__RGB_1_K1__, __RGB_1_K2__, __RGB_1_K3__, __RGB_1_K4__, __RGB_1_K5__
#define ___________________RGB_2___________________			__RGB_2_K1__, __RGB_2_K2__, __RGB_2_K3__, __RGB_2_K4__, __RGB_2_K5__
#define ___________________RGB_3___________________			__RGB_3_K1__, __RGB_3_K2__, __RGB_3_K3__, __RGB_3_K4__, __RGB_3_K5__

#define __MACROS_1_K1__ RGB_SPI
#define __MACROS_1_K2__ L_FIND
#define __MACROS_1_K3__ L_GITCOMMIT
#define __MACROS_1_K4__ _______
#define __MACROS_1_K5__ E_ROBOT

#define __MACROS_2_K1__ P_ANGBRKT
#define __MACROS_2_K2__ P_PAREN
#define __MACROS_2_K3__ P_CURLY
#define __MACROS_2_K4__ P_BRKT
#define __MACROS_2_K5__ P_ARROW

#define __MACROS_3_K1__ RGB_SPD
#define __MACROS_3_K2__ L_GREP
#define __MACROS_3_K3__ _______
#define __MACROS_3_K4__ _______
#define __MACROS_3_K5__ E_CAT

// // UNCOMMENT TO DISABLE MACROS
// #define _________________MACROS_1__________________			___________________BLANK___________________
// #define _________________MACROS_2__________________			___________________BLANK___________________
// #define _________________MACROS_3__________________			___________________BLANK___________________

// COMMENT TO DISABLE MACROS
#define _________________MACROS_1__________________			__MACROS_1_K1__, __MACROS_1_K2__, __MACROS_1_K3__, __MACROS_1_K4__, __MACROS_1_K5__
#define _________________MACROS_2__________________			__MACROS_2_K1__, __MACROS_2_K2__, __MACROS_2_K3__, __MACROS_2_K4__, __MACROS_2_K5__
#define _________________MACROS_3__________________			__MACROS_3_K1__, __MACROS_3_K2__, __MACROS_3_K3__, __MACROS_3_K4__, __MACROS_3_K5__

// MOUSE LAYER

#define __MOUSE_1_K1__ RESET
#define __MOUSE_1_K2__ KC_MS_WH_UP
#define __MOUSE_1_K3__ KC_MS_UP
#define __MOUSE_1_K4__ KC_MS_WH_DOWN
#define __MOUSE_1_K5__ _______

#define __MOUSE_2_K1__ KC_MS_WH_LEFT
#define __MOUSE_2_K2__ KC_MS_LEFT
#define __MOUSE_2_K3__ KC_MS_DOWN
#define __MOUSE_2_K4__ KC_MS_RIGHT
#define __MOUSE_2_K5__ KC_MS_WH_RIGHT

#define __MOUSE_3_K1__ EEP_RST
#define __MOUSE_3_K2__ _______
#define __MOUSE_3_K3__ KC_MS_ACCEL0
#define __MOUSE_3_K4__ KC_MS_ACCEL1
#define __MOUSE_3_K5__ KC_MS_ACCEL2

#define __________________MOUSE_1__________________     __MOUSE_1_K1__, __MOUSE_1_K2__, __MOUSE_1_K3__, __MOUSE_1_K4__, __MOUSE_1_K5__
#define __________________MOUSE_2__________________     __MOUSE_2_K1__, __MOUSE_2_K2__, __MOUSE_2_K3__, __MOUSE_2_K4__, __MOUSE_2_K5__
#define __________________MOUSE_3__________________     __MOUSE_3_K1__, __MOUSE_3_K2__, __MOUSE_3_K3__, __MOUSE_3_K4__, __MOUSE_3_K5__

//                                                      Zoom Home           Add Line            Add Arc            Add Polygon         Add Circle
#define ___________________KICAD_0_________________     KC_HOME,            LCTL(LSFT(KC_L)),   LCTL(LSFT(KC_A)),  LCTL(LSFT(KC_P)),   LCTL(LSFT(KC_C))
//                                                      Drag 45 degree      Move Dialog         Flip               Pos Relative        Select Net
#define ___________________KICAD_1_________________     KC_D,               LSFT(KC_M),         KC_F,              LSFT(KC_P),         KC_GRV
//                                                      Create Track        End Track           Edit Property      Move                Fill Zones
#define ___________________KICAD_2_________________     LCTL_T(KC_X),       LGUI_T(KC_END),     LALT_T(KC_E),      LSFT_T(KC_M),       KC_B
//                                                      Undo                Redo                Rotate             Add Via             Front<->Back
#define ___________________KICAD_3_________________     LCTL(KC_X),         LCTL(KC_Y),         KC_R,              LCTL(LSFT(KC_V)),   KC_V
#define __KICAD_R0_L__ KC_ESC
#define __KICAD_R1_L__ KC_TAB            // Drag free angl
#define __KICAD_R2_L__ LCTL(KC_C)        // Copy
#define __KICAD_R3_L__ LCTL(KC_V)        // Paste
#define __KICAD_R0_R__ LCTL(LSFT(KC_T))  // Add Text
#define __KICAD_R1_R__ LSFT(KC_GRV)      // Stop SelctNet
#define __KICAD_R2_R__ LCTL(KC_B)        // Unfill Zones
#define __KICAD_R3_R__ LCTL(LSFT(KC_M))  // Measure
#define __KICAD_TH_L__ KC_DEL            // Delete
#define __KICAD_TH_C__ KC_ENT            // Enter
#define __KICAD_TH_R__ LSFT(KC_DEL)      // Delete track, note that this only deletes the current copper line up to pads or vias
#define __KICAD_R4_1__ __KICAD_R3_R__
#define __KICAD_R4_2__ LALT(KC_3)        // 3D Viewer
#define __KICAD_R4_3__ KC_U              // Select track, double press for all connected... // used to be this --> LCTL(KC_E)        // Edit Footprint

#define ___________________GAMES_0_________________     KC_F1,   KC_F2,   KC_C,    KC_V,    KC_G
#define ___________________GAMES_1_________________     KC_Q,    KC_W,    KC_E,    KC_R,    KC_D
#define ___________________GAMES_2_________________     KC_A,    KC_F,    KC_TAB,  KC_L,    KC_H
#define ___________________GAMES_3_________________     KC_T,    KC_COMM, KC_K,    KC_SCLN, KC_DOT
#define __GAMES_R0_L__ KC_F4
#define __GAMES_R1_L__ KC_Z
#define __GAMES_R2_L__ KC_P
#define __GAMES_R3_L__ KC_LSFT
#define __GAMES_R0_R__ KC_N
#define __GAMES_R1_R__ KC_Y
#define __GAMES_R2_R__ KC_F7
#define __GAMES_R3_R__ KC_ESC
#define __GAMES_TH_L__ KC_LALT
#define __GAMES_TH_C__ KC_X
#define __GAMES_TH_R__ KC_B
#define __GAMES_R4_1__ KC_J
#define __GAMES_R4_2__ __GAMES_R3_R__
#define __GAMES_R4_3__ KC_LCTL


// clang-format on
