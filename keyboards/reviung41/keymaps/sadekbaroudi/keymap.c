/* Copyright 2019 gtips
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

#ifndef UNICODE_ENABLE
#    define UC(x) KC_NO
#endif

/*
 * The `LAYOUT_reviung41_base` macro is a template to allow the use of identical
 * modifiers for the default layouts (eg QWERTY, Colemak, Dvorak, etc), so
 * that there is no need to set them up for each layout, and modify all of
 * them if I want to change them.  This helps to keep consistency and ease
 * of use. K## is a placeholder to pass through the individual keycodes
 */

// clang-format off
#define LAYOUT_reviung41_base( \
    K01, K02, K03, K04, K05, K06, K07, K08, K09, K0A, \
    K11, K12, K13, K14, K15, K16, K17, K18, K19, K1A, \
    K21, K22, K23, K24, K25, K26, K27, K28, K29, K2A  \
  ) \
  LAYOUT_wrapper( \
        _______,         K01,            K02,            K03,            K04,            K05,                K06,            K07,            LT(_WINNAV,K08),  K09,            K0A,             _______, \
        KC_TAB,          LCTL_T(K11),    LGUI_T(K12),    LALT_T(K13),    LSFT_T(K14),    K15,                K16,            RSFT_T(K17),    RALT_T(K18),      RGUI_T(K19),    RCTL_T(K1A),     _______, \
        _______,         LSFT_T(K21),    K22,            K23,            K24,            K25,                K26,            K27,            K28,              K29,            RSFT_T(K2A),     _______, \
                                             KC_DEL,          LT(_NAVIGATION,KC_ENT),       LT(_FUNCTION,KC_BSPC),       LT(_SYMBOLS,KC_SPACE),     LT(_MOUSE,KC_QUOT)  \
    )
/* Re-pass though to allow templates to be used */
#define LAYOUT_reviung41_base_wrapper(...)       LAYOUT_reviung41_base(__VA_ARGS__)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    [_QWERTY] = LAYOUT_reviung41_base_wrapper(
        _________________QWERTY_L1_________________, _________________QWERTY_R1_________________,
        _________________QWERTY_L2_________________, _________________QWERTY_R2_________________,
        _________________QWERTY_L3_________________, _________________QWERTY_R3_________________
    ),

    [_COLEMAK] = LAYOUT_reviung41_base_wrapper(
        ______________COLEMAK_MOD_DH_L1____________, ______________COLEMAK_MOD_DH_R1____________,
        ______________COLEMAK_MOD_DH_L2____________, ______________COLEMAK_MOD_DH_R2____________,
        ______________COLEMAK_MOD_DH_L3____________, ______________COLEMAK_MOD_DH_R3____________
    ),

    [_WORKMAN] = LAYOUT_reviung41_base_wrapper(
        _________________WORKMAN_L1________________, _________________WORKMAN_R1________________,
        _________________WORKMAN_L2________________, _________________WORKMAN_R2________________,
        _________________WORKMAN_L3________________, _________________WORKMAN_R3________________
    ),

    [_NAVIGATION] = LAYOUT_wrapper(
        _______, ________________NAVIGATION_1_______________, _________________NUMPAD_1__________________, _______,
        _______, ________________NAVIGATION_2_______________, _________________NUMPAD_2__________________, _______,
        _______, ________________NAVIGATION_3_______________, _________________NUMPAD_3__________________, KC_DOT,
                                       _______, _______, KC_BSPC, MO(_MEDIA), KC_DOT
    ),

    [_SYMBOLS] = LAYOUT_wrapper(
        _______, ________________SYMBOLS_L1_________________, ________________SYMBOLS_R1_________________, _______,
        _______, ________________SYMBOLS_L2_________________, ________________SYMBOLS_R2_________________, _______,
        _______, ________________SYMBOLS_L3_________________, ________________SYMBOLS_R3_________________, _______,
                                    _______, MO(_MEDIA), KC_BSPC, _______, _______
    ),

    [_FUNCTION] = LAYOUT_wrapper(
        _______, ________________SHIFTNAV_1_________________, ________________FUNCTION_1_________________, _______,
        _______, ________________SHIFTNAV_2_________________, ________________FUNCTION_2_________________, _______,
        _______, ________________SHIFTNAV_3_________________, ________________FUNCTION_3_________________, _______,
                                       _______, _______, _______, _______, _______
    ),

    [_MEDIA] = LAYOUT_wrapper(
        _______, ___________________RGB_1___________________, _________________MACROS_1__________________, _______,
        _______, ___________________RGB_2___________________, _________________MACROS_2__________________, _______,
        _______, ___________________RGB_3___________________, _________________MACROS_3__________________, _______,
                                       _______, _______, _______, _______, _______
    ),
    
    [_MOUSE] = LAYOUT_wrapper(
        _______, __________________MOUSE_1__________________, ___________________BLANK___________________, _______,
        _______, __________________MOUSE_2__________________, ___________________BLANK___________________, _______,
        _______, __________________MOUSE_3__________________, ___________________BLANK___________________, _______,
                                    _______, KC_MS_BTN1,  KC_MS_BTN3,  KC_MS_BTN2, _______
    ),

    [_WINNAV] = LAYOUT_wrapper(
        _______, __________________WIN_NAV_1________________, ___________________BLANK___________________, _______,
        _______, __________________WIN_NAV_2________________, ___________________BLANK___________________, _______,
        _______, ___________________BLANK___________________, ___________________BLANK___________________, _______,
                                       _______, _______, _______, _______, _______
    )

};

