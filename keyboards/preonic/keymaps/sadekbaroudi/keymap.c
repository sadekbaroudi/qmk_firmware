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
#include "muse.h"

#ifndef UNICODE_ENABLE
#    define UC(x) KC_NO
#endif


// clang-format off
#define LAYOUT_ortho_5x12_base( \
    K01, K02, K03, K04, K05, K06, K07, K08, K09, K0A, \
    K11, K12, K13, K14, K15, K16, K17, K18, K19, K1A, \
    K21, K22, K23, K24, K25, K26, K27, K28, K29, K2A  \
  ) \
  LAYOUT_ortho_5x12_wrapper( \
        KC_1,           KC_2,           KC_3,           KC_4,                      KC_5,                 _______,        _______,        KC_6,                 KC_7,                   KC_8,                  KC_9,           KC_0, \
        K01,            K02,            K03,            K04,                       K05,                  _______,        _______,        K06,                  K07,                    K08,                   K09,            K0A, \
        LCTL_T(K11),    LGUI_T(K12),    LALT_T(K13),    LSFT_T(K14),               K15,                  _______,        _______,        K16,                  RSFT_T(K17),            RALT_T(K18),           RGUI_T(K19),    RCTL_T(K1A), \
        K21,            K22,            K23,            K24,                       K25,                  _______,        _______,        K26,                  K27,                    K28,                   K29,            LT(_MOUSE, K2A), \
        _______,        _______,        KC_DEL,         LT(_NAVIGATION, KC_ENT),   LT(_FUNCTION,KC_TAB), _______,        _______,        LT(_FUNCTION,KC_BSPC), LT(_SYMBOLS,KC_SPACE), KC_QUOT,               _______,        _______ \
    )

/* Re-pass though to allow templates to be used */
#define LAYOUT_ortho_5x12_base_wrapper(...)       LAYOUT_ortho_5x12_base(__VA_ARGS__)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    [_QWERTY] = LAYOUT_ortho_5x12_base_wrapper(
        _________________QWERTY_L1_________________, _________________QWERTY_R1_________________,
        _________________QWERTY_L2_________________, _________________QWERTY_R2_________________,
        _________________QWERTY_L3_________________, _________________QWERTY_R3_________________
    ),

    [_COLEMAK] = LAYOUT_ortho_5x12_base_wrapper(
        ______________COLEMAK_MOD_DH_L1____________, ______________COLEMAK_MOD_DH_R1____________,
        ______________COLEMAK_MOD_DH_L2____________, ______________COLEMAK_MOD_DH_R2____________,
        ______________COLEMAK_MOD_DH_L3____________, ______________COLEMAK_MOD_DH_R3____________
    ),

    [_WORKMAN] = LAYOUT_ortho_5x12_base_wrapper(
        _________________WORKMAN_L1________________, _________________WORKMAN_R1________________,
        _________________WORKMAN_L2________________, _________________WORKMAN_R2________________,
        _________________WORKMAN_L3________________, _________________WORKMAN_R3________________
    ),

    [_NAVIGATION] = LAYOUT_wrapper(
        ___________________BLANK___________________, _______, _______, ___________________BLANK___________________,
        ________________NAVIGATION_1_______________, _______, _______, _________________NUMPAD_1__________________,
        ________________NAVIGATION_2_______________, _______, _______, _________________NUMPAD_2__________________,
        ________________NAVIGATION_3_______________, _______, _______, _________________NUMPAD_3__________________,
        _______, _______, _______, _______,  KC_TAB, _______, _______, KC_BSPC, MO(_MEDIA), KC_DOT, _______, _______
    ),

    [_SYMBOLS] = LAYOUT_wrapper(
        ___________________BLANK___________________,   _______, _______, ___________________BLANK___________________,
        ________________SYMBOLS_L1_________________,   _______, _______, ________________SYMBOLS_R1_________________,
        ________________SYMBOLS_L2_________________,   _______, _______, ________________SYMBOLS_R2_________________,
        ________________SYMBOLS_L3_________________,   _______, _______, ________________SYMBOLS_R3_________________,
        _______, _______, _______, MO(_MEDIA), KC_TAB, _______, _______, KC_BSPC, _______, _______, _______, _______
    ),

    [_FUNCTION] = LAYOUT_wrapper(
        ___________________BLANK___________________, _______, _______, ___________________BLANK___________________,
        ________________SHIFTNAV_1_________________, _______, _______, ________________FUNCTION_1_________________,
        ________________SHIFTNAV_2_________________, _______, _______, ________________FUNCTION_2_________________,
        ________________SHIFTNAV_3_________________, _______, _______, ________________FUNCTION_3_________________,
        ___________________BLANK___________________, _______, _______, ___________________BLANK___________________
    ),

    [_MEDIA] = LAYOUT_wrapper(
        ___________________BLANK___________________, _______, _______, ___________________BLANK___________________,
        ___________________RGB_1___________________, _______, _______, _________________MACROS_1__________________,
        ___________________RGB_2___________________, _______, _______, _________________MACROS_2__________________,
        ___________________RGB_3___________________, _______, _______, _________________MACROS_3__________________,
        ___________________BLANK___________________, _______, _______, ___________________BLANK___________________
    ),
    
    [_MOUSE] = LAYOUT_wrapper(
        ___________________BLANK___________________,       _______,    _______,    ___________________BLANK___________________,
        __________________MOUSE_1__________________,       _______,    _______,    ___________________BLANK___________________,
        __________________MOUSE_2__________________,       _______,    _______,    ___________________BLANK___________________,
        __________________MOUSE_3__________________,       _______,    _______,    ___________________BLANK___________________,
        _______, _______, _______, KC_MS_BTN1, KC_MS_BTN3, _______,    _______,    KC_MS_BTN3, KC_MS_BTN2, _______, _______, _______
    )

};

