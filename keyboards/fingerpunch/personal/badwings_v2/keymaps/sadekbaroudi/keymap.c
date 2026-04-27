/* Copyright 2021 Sadek Baroudi
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

/*
 * The `LAYOUT_badwings_v2_base` macro is a template to allow the use of identical
 * modifiers for the default layouts (eg ALPHA_ALT, Colemak, Dvorak, etc), so
 * that there is no need to set them up for each layout, and modify all of
 * them if I want to change them.  This helps to keep consistency and ease
 * of use. K## is a placeholder to pass through the individual keycodes
 */

#include "sadekbaroudi.h"
#include QMK_KEYBOARD_H

// clang-format off
#define LAYOUT_badwings_v2_base( \
     K00, K10, K20, K30, K40,    K44, K34, K24, K14, K04,  \
     K01, K11, K21, K31, K41,    K45, K35, K25, K15, K05,  \
     K02, K12, K22, K32, K42,    K46, K36, K26, K16, K06,  \
               K23, K33, K43,    K47, K37, K27  \
  ) \
  LAYOUT_wrapper( \
        K00,            K10,            K20,            LT(_FUNCTION, K30),     K40,                      K44,                   LT(_FUNCTION, K34),    K24,              K14,            K04,         \
        LCTL_T(K01),    LGUI_T(K11),    LALT_T(K21),    LSFT_T(K31),            K41,                      LT(_MOUSE, K45),       RSFT_T(K35),           RALT_T(K25),      RGUI_T(K15),    RCTL_T(K05), \
        K02,            K12,            K22,            K32,                    K42,                      K46,                   K36,                   K26,              K16,            K06,         \
                                        K23,            LT(_NAVIGATION,K33),    LT(_FUNCTION,K43),        LT(_MEDIA,K47),        LT(_SYMBOLS,K37),      K27 \
    )

/* Re-pass though to allow templates to be used */
#define LAYOUT_badwings_v2_base_wrapper(...)       LAYOUT_badwings_v2_base(__VA_ARGS__)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    [_ALPHA_ALT] = LAYOUT_badwings_v2_base_wrapper(
        _________________ALPHA_ALT_L1_________________, _________________ALPHA_ALT_R1_________________,
        _________________ALPHA_ALT_L2_________________, _________________ALPHA_ALT_R2_________________,
        _________________ALPHA_ALT_L3_________________, _________________ALPHA_ALT_R3_________________,
                                             __ALPHA_ALT_THUMBS_6__
    ),

    [_ALPHA] = LAYOUT_badwings_v2_base_wrapper(
        __________________ALPHA_L1____________________, __________________ALPHA_R1____________________,
        __________________ALPHA_L2____________________, __________________ALPHA_R2____________________,
        __________________ALPHA_L3____________________, __________________ALPHA_R3____________________,
                                              __ALPHA_THUMBS_6__
    ),

    [_NAVIGATION] = LAYOUT_wrapper(
        ________________NAVIGATION_1_______________, _________________NUMPAD_1__________________,
        ________________NAVIGATION_2_______________, _________________NUMPAD_2__________________,
        ________________NAVIGATION_3_______________, _________________NUMPAD_3__________________,
                           _______, _______, KC_TAB, KC_BSPC, KC_SPACE, KC_DOT
    ),

    [_SYMBOLS] = LAYOUT_wrapper(
        ________________SYMBOLS_L1_________________, ________________SYMBOLS_R1_________________,
        ________________SYMBOLS_L2_________________, ________________SYMBOLS_R2_________________,
        ________________SYMBOLS_L3_________________, ________________SYMBOLS_R3_________________,
                            _______, KC_ENT, KC_DEL,  KC_BSPC, _______, _______
    ),

    [_FUNCTION] = LAYOUT_wrapper(
        ________________SHIFTNAV_1_________________, ________________FUNCTION_1_________________,
        ________________SHIFTNAV_2_________________, ________________FUNCTION_2_________________,
        ________________SHIFTNAV_3_________________, ________________FUNCTION_3_________________,
                 MS_BTN3, MS_BTN1, MS_BTN2, N_DEL_LINE, KC_SPACE, _______
    ),

    [_MEDIA] = LAYOUT_wrapper(
        ___________________RGB_1___________________, _________________MACROS_1__________________,
        ___________________RGB_2___________________, _________________MACROS_2__________________,
        ___________________RGB_3___________________, _________________MACROS_3__________________,
                          _______, _______, _______, _______, _______, _______
    ),

    [_MOUSE] = LAYOUT_wrapper(
        _______________AUTO_MOUSE_1________________, ___________________BLANK___________________,
        _______________AUTO_MOUSE_2________________, ___________________BLANK___________________,
        _______________AUTO_MOUSE_3________________, ___________________BLANK___________________,
                    _______, MS_BTN1, MS_BTN3, MS_BTN3, MS_BTN2, _______
    )
};
