/* Copyright 2015-2017 Jack Humbert
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include "sadekbaroudi.h"
#include QMK_KEYBOARD_H

// clang-format off
#define LAYOUT_ortho_4x12_base( \
    K01, K02, K03, K04, K05, K06, K07, K08, K09, K0A, \
    K11, K12, K13, K14, K15, K16, K17, K18, K19, K1A, \
    K21, K22, K23, K24, K25, K26, K27, K28, K29, K2A, \
              K33, K34, K35, K36, K37, K38 \
  ) \
  LAYOUT_ortho_4x12_wrapper( \
        K01,            K02,            K03,            LT(_FUNCTION, K04),     K05,            FP_SCROLL_TOG,        _______,               K06,                   LT(_FUNCTION, K07),    K08,               K09,            K0A,        \
        LCTL_T(K11),    LGUI_T(K12),    LALT_T(K13),    LSFT_T(K14),            K15,            MS_BTN1,           _______,               LT(_MOUSE, K16),       RSFT_T(K17),           RALT_T(K18),       RGUI_T(K19),    RCTL_T(K1A),\
        K21,            K22,            K23,            K24,                    K25,            MS_BTN2,           _______,               K26,                   K27,                   K28,               K29,            K2A,        \
        _______,        _______,        _______,        K33,            LT(_NAVIGATION,K34),    LT(_FUNCTION,K35),    LT(_MEDIA,K36),        LT(_SYMBOLS,K37),      K38,                   _______,           _______,        _______     \
    )

/* Re-pass though to allow templates to be used */
#define LAYOUT_ortho_4x12_base_wrapper(...)       LAYOUT_ortho_4x12_base(__VA_ARGS__)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    [_ALPHA_ALT] = LAYOUT_ortho_4x12_base_wrapper(
        _________________ALPHA_ALT_L1_________________, _________________ALPHA_ALT_R1_________________,
        _________________ALPHA_ALT_L2_________________, _________________ALPHA_ALT_R2_________________,
        _________________ALPHA_ALT_L3_________________, _________________ALPHA_ALT_R3_________________,
                                             __ALPHA_ALT_THUMBS_6__
    ),

    [_ALPHA] = LAYOUT_ortho_4x12_base_wrapper(
        __________________ALPHA_L1____________________, __________________ALPHA_R1____________________,
        __________________ALPHA_L2____________________, __________________ALPHA_R2____________________,
        __________________ALPHA_L3____________________, __________________ALPHA_R3____________________,
                                              __ALPHA_THUMBS_6__
    ),

    [_NAVIGATION] = LAYOUT_wrapper(
        ________________NAVIGATION_1_______________, _______, _______, _________________NUMPAD_1__________________,
        ________________NAVIGATION_2_______________, _______, _______, _________________NUMPAD_2__________________,
        ________________NAVIGATION_3_______________, _______, _______, _________________NUMPAD_3__________________,
        _______, _______, _______, _______, _______, KC_TAB, KC_BSPC, KC_SPACE, KC_DOT, _______, _______, _______
    ),

    [_SYMBOLS] = LAYOUT_wrapper(
        ________________SYMBOLS_L1_________________, _______, _______, ________________SYMBOLS_R1_________________,
        ________________SYMBOLS_L2_________________, _______, _______, ________________SYMBOLS_R2_________________,
        ________________SYMBOLS_L3_________________, _______, _______, ________________SYMBOLS_R3_________________,
        _______, _______, _______, _______, KC_ENT, KC_DEL,   KC_BSPC, _______, _______, _______, _______, _______
    ),

    [_FUNCTION] = LAYOUT_wrapper(
        ________________SHIFTNAV_1_________________, _______, _______, ________________FUNCTION_1_________________,
        ________________SHIFTNAV_2_________________, _______, _______, ________________FUNCTION_2_________________,
        ________________SHIFTNAV_3_________________, _______, _______, ________________FUNCTION_3_________________,
        _______, ___________________BLANK___________________, N_DEL_LINE, KC_SPACE, _______, _______, _______, _______
    ),

    [_MEDIA] = LAYOUT_wrapper(
        ___________________RGB_1___________________, _______, _______, _________________MACROS_1__________________,
        ___________________RGB_2___________________, _______, _______, _________________MACROS_2__________________,
        ___________________RGB_3___________________, _______, _______, _________________MACROS_3__________________,
        _______, ___________________BLANK___________________, ___________________BLANK___________________, _______
    ),

    [_MOUSE] = LAYOUT_wrapper(
        __________________MOUSE_1__________________,       _______, _______,      ___________________BLANK___________________,
        __________________MOUSE_2__________________,       _______, _______,      ___________________BLANK___________________,
        __________________MOUSE_3__________________,       _______, _______,      ___________________BLANK___________________,
        _______, _______, _______, _______, MS_BTN1, MS_BTN3, MS_BTN3, MS_BTN2, _______, _______, _______, _______
    )
};

