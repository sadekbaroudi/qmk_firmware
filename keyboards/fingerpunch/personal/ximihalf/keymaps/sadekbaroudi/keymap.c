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
 * The `LAYOUT_luakeeb_base` macro is a template to allow the use of identical
 * modifiers for the default layouts (eg ALPHA_ALT, Colemak, Dvorak, etc), so
 * that there is no need to set them up for each layout, and modify all of
 * them if I want to change them.  This helps to keep consistency and ease
 * of use. K## is a placeholder to pass through the individual keycodes
 */

// Note: changed the thumb keys from the following, testing out a new layout:
//                             KC_DEL, LT(_NAVIGATION,KC_ENT), LT(_FUNCTION,KC_TAB),           LT(_FUNCTION,KC_BSPC), LT(_SYMBOLS,KC_SPACE), KC_QUOT "\"
//                                            _______, KC_BSPC, LT(_NAVIGATION,KC_ENT),           LT(_SYMBOLS,KC_SPACE), KC_QUOT, _______ "\"

// clang-format off
#define LAYOUT_ximi_base( \
    K01, K02, K03, K04, K05, \
    K11, K12, K13, K14, K15, \
    K21, K22, K23, K24, K25, \
              K33, K34, K35 \
  ) \
  LAYOUT_wrapper( \
        MS_BTN3,      K01,             K02,            K03,            LT(_FUNCTION, K04),  K05, \
        MS_BTN1,      LCTL_T(K11),     LGUI_T(K12),    LALT_T(K13),    LSFT_T(K14),         K15, \
        MS_BTN2,      K21,             K22,            K23,            K24,                 K25, \
                                                          K33,            LT(_NAVIGATION,K34), LT(_FUNCTION,K35), \
                                                          C(KC_Z),        C(S(KC_Z)),          C(KC_Y) \
    )

/* Re-pass though to allow templates to be used */
#define LAYOUT_ximi_base_wrapper(...)       LAYOUT_ximi_base(__VA_ARGS__)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    [_ALPHA_ALT] = LAYOUT_ximi_base_wrapper(
        _________________ALPHA_ALT_L1_________________,
        _________________ALPHA_ALT_L2_________________,
        _________________ALPHA_ALT_L3_________________,
                                             __ALPHA_ALT_THUMBS_LEFT_3__
    ),

    [_ALPHA] = LAYOUT_ximi_base_wrapper(
        __________________ALPHA_L1____________________,
        __________________ALPHA_L2____________________,
        __________________ALPHA_L3____________________,
                                             __ALPHA_THUMBS_LEFT_3__
    ),

    [_NAVIGATION] = LAYOUT_wrapper(
        _______, ________________NAVIGATION_1_______________,
        _______, ________________NAVIGATION_2_______________,
        _______, ________________NAVIGATION_3_______________,
                                   _______, _______,  KC_TAB,
                                   _______, _______, _______
    ),

    [_SYMBOLS] = LAYOUT_wrapper(
        _______, ________________SYMBOLS_L1_________________,
        _______, ________________SYMBOLS_L2_________________,
        _______, ________________SYMBOLS_L3_________________,
                                   _______,  KC_ENT,  KC_DEL,
                                   _______, _______, _______
    ),

    [_FUNCTION] = LAYOUT_wrapper(
        _______, ________________SHIFTNAV_1_________________,
        _______, ________________SHIFTNAV_2_________________,
        _______, ________________SHIFTNAV_3_________________,
                                   _______, _______, _______,
                                   _______, _______, _______
    ),

    [_MEDIA] = LAYOUT_wrapper(
        _______, ___________________RGB_1___________________,
        _______, ___________________RGB_2___________________,
        _______, ___________________RGB_3___________________,
                                   _______, _______, _______,
                                   _______, _______, _______
    ),

    [_MOUSE] = LAYOUT_wrapper(
        _______, __________________MOUSE_1__________________,
        _______, __________________MOUSE_2__________________,
        _______, __________________MOUSE_3__________________,
                             _______, MS_BTN1, MS_BTN3,
                                   _______, _______, _______
    )

};
