#include "sadekbaroudi.h"

#include QMK_KEYBOARD_H

#define _GAME 0
#define _FUNCTION 1
#define _KICAD 2
#define _FUSION 3
#define _ALPHA 4

enum custom_keycodes {
  GAME = NEW_SAFE_RANGE,
  FUNCTION,
  KICAD,
  FUSION,
  ALPHA,
};

// +-------+-------+-------+-------+-------+-------+-------+
// |       |       |       |       |       |       |       |
// +-------+-------+-------+-------+-------+-------+-------+
// |       |       |       |       |       |       |       |
// +-------+-------+-------+-------+-------+-------+-------+
// |       |       |       |       |       |       |       |
// +-------+-------+-------+-------+-------+-------+-------+           +-------+
// |       |       |       |       |       |       |                   |       |
// +-------+-------+-------+-------+-------+-------+-------+   +-------+-------+-------+
// |       |       |       |       |       |       |       |   |       |       |       |    <--- 5 way nav
// +-------+-------+-------+       +-------+-------+-------+   +-------+-------+-------+
//                                                                     |       |
//                                                                     +-------+
//                                 +-------+-------+-------+
//                                 |       |       |       |   <--- 3 way thumb
//                                 +-------+-------+-------+

//    ----.
//         '..
//            '
//        +-------+
//        |       |
//        |       |    <---- foot pedal via TRRS
//        |       |
//        +-------+

// clang-format off
#define LAYOUT_halfdash_base( \
    K01, K02, K03, K04, K05, K06, K07, \
    K11, K12, K13, K14, K15, K16, K17, \
    K21, K22, K23, K24, K25, K26, K27, \
    K31, K32, K33, K34, K35, K36, \
    K41, K42, K43, K44, K45, K46, K47 \
  ) \
  LAYOUT_wrapper( \
    K01, K02, K03, K04, K05, K06, K07, \
    K11, K12, K13, K14, K15, K16, K17, \
    K21, K22, K23, K24, K25, K26, K27, \
    K31, K32, K33, K34, K35, K36, \
    K41, K42, K43, K44, K45, K46, K47 \
  )

/* Re-pass though to allow templates to be used */
#define LAYOUT_halfdash_base_wrapper(...)       LAYOUT_halfdash_base(__VA_ARGS__)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [_GAME] = LAYOUT_wrapper( \
    __GAMES_R0_L__,     ___________________GAMES_0_________________,     __GAMES_R0_R__, \
    __GAMES_R1_L__,     ___________________GAMES_1_________________,     __GAMES_R1_R__, \
    __GAMES_R2_L__,     ___________________GAMES_2_________________,     __GAMES_R2_R__, \
    __GAMES_R3_L__,     ___________________GAMES_3_________________,                                               KC_UP, \
    __GAMES_R4_1__, __GAMES_R4_2__, MO(_FUNCTION),      __GAMES_R4_3__, __GAMES_TH_L__, __GAMES_TH_C__,   KC_LEFT, KC_MPLY, KC_RIGHT,  \
                                                                                                                   KC_DOWN, \
                                                        TO(_ALPHA),   KC_MUTE,   TO(_KICAD), \
    KC_LSFT \
  ),

  [_FUNCTION] = LAYOUT_wrapper( \
    QK_BOOT, TG(_KICAD), TG(_FUSION),      TG(_ALPHA),        KC_4,     KC_5,       KC_LBRC, \
    KC_TAB,  UG_TOGG,    UG_PREV, UG_NEXT,  _______,  UG_SPDU,    BL_ON, \
    KC_CAPS, KC_RGB_BLT, UG_HUEU,          UG_SATU,           UG_VALU,  UG_SPDU,    BL_OFF, \
    KC_LSFT, KC_RGB_T,   UG_HUED,          UG_SATD,           UG_VALD,  UG_SPDD,                                KC_UP, \
    KC_LCTL, KC_LGUI,   _______,                              KC_LALT,  KC_BSPC,   KC_SPC,             KC_LEFT, KC_MPLY, KC_RIGHT,  \
                                                                                                                KC_DOWN, \
                                                   KC_VOLD,   KC_MUTE,   KC_VOLU, \
    KC_LSFT \
  ),

  [_KICAD] = LAYOUT_wrapper( \
    __KICAD_R0_L__,     ___________________KICAD_0_________________,     __KICAD_R0_R__, \
    __KICAD_R1_L__,     ___________________KICAD_1_________________,     __KICAD_R1_R__, \
    __KICAD_R2_L__,     ___________________KICAD_2_________________,     __KICAD_R2_R__, \
    __KICAD_R3_L__,     ___________________KICAD_3_________________,                                            KC_UP, \
    __KICAD_R4_1__, __KICAD_R4_2__, TG(_KICAD),    __KICAD_R4_3__, __KICAD_TH_L__, __KICAD_TH_C__,     KC_LEFT, KC_MPLY, KC_RIGHT,  \
                                                                                                                KC_DOWN, \
                                                   TO(_GAME),   KC_MUTE,   TO(_FUSION), \
    KC_LSFT \
  ),

  [_FUSION] = LAYOUT_wrapper( \
    KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_LBRC, \
    KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_MINS, \
    KC_CAPS, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_DEL , \
    KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                                        LCTL(KC_UP), \
    KC_LCTL, KC_LGUI, TG(_FUSION),      KC_LALT, KC_BSPC,  KC_SPC,             LCTL(KC_LEFT), LCTL(LALT(KC_W)), LCTL(KC_RIGHT),  \
                                                                                              LCTL(KC_DOWN), \
                                                   TO(_KICAD),   KC_MUTE,   TO(_ALPHA), \
    KC_LSFT \
  ),

  [_ALPHA] = LAYOUT_wrapper( \
    KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_LBRC, \
    KC_TAB,  KC_Q,    KC_W,    KC_F,    KC_P,    KC_B,    KC_MINS, \
    KC_CAPS, KC_A,    KC_R,    KC_S,    KC_T,    KC_G,    KC_DEL , \
    KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_D,    KC_V,                              KC_VOLU, \
    KC_LCTL, KC_LGUI, TG(_ALPHA),       KC_LALT, KC_BSPC,  KC_SPC,         KC_MPRV, KC_MPLY, KC_MNXT,  \
                                                                                    KC_VOLD, \
                                                   TO(_FUSION),   KC_MUTE,   TO(_GAME), \
    KC_LSFT \
  ),
};
