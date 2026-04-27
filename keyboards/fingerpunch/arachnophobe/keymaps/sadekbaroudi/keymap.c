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

#include "sadekbaroudi.h"
#include QMK_KEYBOARD_H

/*
 * The `LAYOUT_arachnophobe_base` macro is a template to allow the use of identical
 * modifiers for the default layouts (eg ALPHA_ALT, Colemak, Dvorak, etc), so
 * that there is no need to set them up for each layout, and modify all of
 * them if I want to change them.  This helps to keep consistency and ease
 * of use. K## is a placeholder to pass through the individual keycodes
 */

// clang-format off
#define LAYOUT_arachnophobe_base( \
         K02, K03,                     K08, K09,      \
    K11, K12, K13, K14, K15, K16, K17, K18, K19, K1A, \
    K21, K22, K23, K24, K25, K26, K27, K28, K29, K2A, \
              K33, K34, K35, K36, K37, K38 \
  ) \
  LAYOUT_wrapper( \
                        K02,            K03,                                                                                                                 K08,              K09,                         \
        LCTL_T(K11),    LGUI_T(K12),    LALT_T(K13),    LSFT_T(K14),            K15,                           LT(_MOUSE, K16),       RSFT_T(K17),           RALT_T(K18),      RGUI_T(K19),    RCTL_T(K1A), \
        K21,            K22,            K23,            K24,                    K25,                           K26,                   K27,                   K28,              K29,            K2A,         \
                                        K33,            LT(_NAVIGATION,K34),    LT(_FUNCTION,K35),             LT(_MEDIA,K36),        LT(_SYMBOLS,K37),      K38 \
    )

/* Re-pass though to allow templates to be used */
#define LAYOUT_arachnophobe_base_wrapper(...)       LAYOUT_arachnophobe_base(__VA_ARGS__)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    [_ALPHA_ALT] = LAYOUT_arachnophobe_base_wrapper(
           __ALPHA_ALT_L1_K2__, __ALPHA_ALT_L1_K3__,                  __ALPHA_ALT_R1_K3__, __ALPHA_ALT_R1_K4__,
        _________________ALPHA_ALT_L2_________________,            _________________ALPHA_ALT_R2_________________,
        _________________ALPHA_ALT_L3_________________,            _________________ALPHA_ALT_R3_________________,
                                                   __ALPHA_ALT_THUMBS_6__
    ),

    [_ALPHA] = LAYOUT_arachnophobe_base_wrapper(
                __ALPHA_L1_K2__, __ALPHA_L1_K3__,                          __ALPHA_R1_K3__, __ALPHA_R1_K4__,
        __________________ALPHA_L2____________________,            __________________ALPHA_R2____________________,
        __________________ALPHA_L3____________________,            __________________ALPHA_R3____________________,
                                                    __ALPHA_THUMBS_6__
    ),

    [_NAVIGATION] = LAYOUT_wrapper(
                __NAV_1_K2__, __NAV_1_K3__,                                     __NUMPAD_1_K3__, __NUMPAD_1_K4__,
        ________________NAVIGATION_2_______________,        __NUMPAD_1_K2__, __NUMPAD_2_K2__, __NUMPAD_2_K3__, __NUMPAD_2_K4__, __NUMPAD_2_K5__,
        ________________NAVIGATION_3_______________,                        _________________NUMPAD_3__________________, 
                               _______, _______, KC_TAB, KC_BSPC, KC_SPACE, KC_DOT
    ),

    [_SYMBOLS] = LAYOUT_wrapper(
                           __SYMBOLS_L1_K2__, __SYMBOLS_L1_K3__,                                                                            __SYMBOLS_R1_K3__, __SYMBOLS_R1_K4__,
        __SYMBOLS_L2_K1__, __SYMBOLS_L1_K1__, __SYMBOLS_L1_K4__, __SYMBOLS_L1_K5__, _______,                    _______, __SYMBOLS_R1_K1__, __SYMBOLS_R1_K2__, __SYMBOLS_R1_K5__, __SYMBOLS_R2_K5__,
                         ________________SYMBOLS_L3_________________,                                                                ________________SYMBOLS_R3_________________,
                                                                            _______, KC_ENT, KC_DEL,  KC_BSPC, _______, _______
    ),

    [_FUNCTION] = LAYOUT_wrapper(
             __SHIFTNAV_1_K2__, __SHIFTNAV_1_K3__,                             __FUNCION_1_K3__, __FUNCION_1_K4__,
        ________________SHIFTNAV_2_________________, __FUNCION_1_K2__, __FUNCION_2_K2__, __FUNCION_2_K3__, __FUNCION_2_K4__, __FUNCION_1_K5__,
        ________________SHIFTNAV_3_________________, __FUNCION_3_K5__, __FUNCION_3_K2__, __FUNCION_3_K3__, __FUNCION_3_K4__, __FUNCION_2_K5__,
                          _______, _______, _______, N_DEL_LINE, KC_SPACE, _______
    ),

    [_MEDIA] = LAYOUT_wrapper(
        // Note that I used __RGB_1_K1__ instead of __RGB_1_K2__ because that's my firmware reset key
                 __RGB_1_K1__, __RGB_1_K3__,               __MACROS_1_K3__, __MACROS_1_K4__,
        ___________________RGB_2___________________, _________________MACROS_2__________________,
        ___________________RGB_3___________________, _________________MACROS_3__________________,
                          _______, _______, _______, _______, _______, _______
    ),
    
    [_MOUSE] = LAYOUT_wrapper(
                __MOUSE_1_K2__, __MOUSE_1_K3__,                   _______, _______,
        __________________MOUSE_2__________________, ___________________BLANK___________________,
        __________________MOUSE_3__________________, ___________________BLANK___________________,
                _______, MS_BTN1, MS_BTN3, MS_BTN3, MS_BTN2, _______
    )
};

