/* Copyright 2025 Sadek Baroudi
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
 * The `LAYOUT_ffkb_base` macro is a template to allow the use of identical
 * modifiers for the default layouts (eg ALPHA_ALT, Colemak, Dvorak, etc), so
 * that there is no need to set them up for each layout, and modify all of
 * them if I want to change them.  This helps to keep consistency and ease
 * of use. K## is a placeholder to pass through the individual keycodes
 */

// clang-format off
#define LAYOUT_smallcat_base( \
         K02, K03, K04,           K07, K08, K09, \
    K11, K12, K13, K14, K15, K16, K17, K18, K19, K1A, \
         K22, K23, K24,           K27, K28, K29, \
                   K34, K35, K36, K37 \
  ) \
  LAYOUT_wrapper( \
                        K02,            K03,            K04,                                                                     K07,                   K08,              K09,            \
        LCTL_T(K11),    LGUI_T(K12),    LALT_T(K13),    LSFT_T(K14),            K15,                      LT(_MOUSE, K16),       RSFT_T(K17),           RALT_T(K18),      RGUI_T(K19),    RCTL_T(K1A), \
                        K22,            K23,            K24,                                                                     K27,                   K28,              K29,            \
                                                        LT(_FUNCTION,K34),    LT(_NAVIGATION,K35),        LT(_SYMBOLS,K36),      LT(_MEDIA,K37) \
    )

/* Re-pass though to allow templates to be used */
#define LAYOUT_smallcat_base_wrapper(...)       LAYOUT_smallcat_base(__VA_ARGS__)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

 [_ALPHA_ALT] = LAYOUT_smallcat_base_wrapper(
     __ALPHA_ALT_L1_K2__, __ALPHA_ALT_L1_K3__, __ALPHA_ALT_L1_K4__,            __ALPHA_ALT_R1_K2__, __ALPHA_ALT_R1_K3__, __ALPHA_ALT_R1_K4__,
            _________________ALPHA_ALT_L2_________________,                           _________________ALPHA_ALT_R2_________________,
     __ALPHA_ALT_L3_K2__, __ALPHA_ALT_L3_K3__, __ALPHA_ALT_L3_K4__,            __ALPHA_ALT_R3_K2__, __ALPHA_ALT_R3_K3__, __ALPHA_ALT_R3_K4__,
                                             __ALPHA_ALT_THUMBS_LEFT_2_TUCKY__, __ALPHA_ALT_THUMBS_RIGHT_2_TUCKY__
 ),

 [_ALPHA] = LAYOUT_smallcat_base_wrapper(
    __ALPHA_L1_K2__, __ALPHA_L1_K3__, __ALPHA_L1_K4__,            __ALPHA_R1_K2__, __ALPHA_R1_K3__, __ALPHA_R1_K4__,
    __________________ALPHA_L2____________________,                   __________________ALPHA_R2____________________,
    __ALPHA_L3_K2__, __ALPHA_L3_K3__, __ALPHA_L3_K4__,            __ALPHA_R3_K2__, __ALPHA_R3_K3__, __ALPHA_R3_K4__,
                                     __ALPHA_THUMBS_LEFT_2_TUCKY__, __ALPHA_THUMBS_RIGHT_2_TUCKY__
),

 [_NAVIGATION] = LAYOUT_wrapper(
             __NAV_1_K2__, __NAV_1_K3__, __NAV_1_K4__,                    __NUMPAD_1_K2__,  __NUMPAD_1_K3__, __NUMPAD_1_K4__,
     ________________NAVIGATION_2_______________,                             _________________NUMPAD_2__________________,
             __NAV_3_K2__, __NAV_3_K3__, __NAV_3_K4__,                    __NUMPAD_3_K2__,  __NUMPAD_3_K3__, __NUMPAD_3_K4__,
                                  _______, _______, /*KC_TAB, KC_BSPC,*/ KC_SPACE, KC_DOT
 ),

 [_SYMBOLS] = LAYOUT_wrapper(
    __SYMBOLS_L1_K2__, __SYMBOLS_L1_K3__, __SYMBOLS_L1_K4__,                    __SYMBOLS_R1_K2__, __SYMBOLS_R1_K3__, __SYMBOLS_R1_K4__,
           ________________SYMBOLS_L2_________________,                             ________________SYMBOLS_R2_________________,
    __META_NAV_L1_K2__, __META_NAV_L1_K3__, __META_NAV_L1_K4__,                 __META_NAV_L2_K2__, __META_NAV_L2_K3__, __META_NAV_L2_K4__,
                                         _______, KC_ENT, /*KC_DEL,  KC_BSPC,*/ _______, _______
 ),

 [_FUNCTION] = LAYOUT_wrapper(
    __SHIFTNAV_1_K2__, __SHIFTNAV_1_K3__, __SHIFTNAV_1_K4__,                    __FUNCTION_1_K2__, __FUNCTION_1_K3__, __FUNCTION_1_K4__,
          ________________SHIFTNAV_2_________________,                                ________________FUNCTION_2_________________,
    __SHIFTNAV_3_K2__, __SHIFTNAV_3_K3__, __SHIFTNAV_3_K4__,                    __FUNCTION_3_K2__, __FUNCTION_3_K3__, __FUNCTION_3_K4__,
                                         _______, _______, /*_______, N_DEL_LINE,*/ KC_SPACE, _______
 ),

 [_MEDIA] = LAYOUT_wrapper(
                  __RGB_1_K2__, __RGB_1_K3__, __RGB_1_K4__,                             __MACROS_1_K2__, __MACROS_1_K3__, __MACROS_1_K4__,
    __RGB_2_K1__, __RGB_2_K2__, __RGB_2_K3__, __RGB_2_K4__, __RGB_2_K5__,                    _________________MACROS_2__________________,
                  __RGB_3_K2__, __RGB_3_K3__, __RGB_3_K4__,                             __MACROS_3_K2__, __MACROS_3_K3__, __MACROS_3_K4__,
                                                _______,  _______, /*_______, _______,*/ _______, _______
 ),

 [_MOUSE] = LAYOUT_wrapper(
          __MOUSE_1_K2__, __MOUSE_1_K3__, __MOUSE_1_K4__,                             _______, _______, _______,
           __________________MOUSE_2__________________,                      _______, _______, _______, _______, _______,
          __MOUSE_3_K2__, __MOUSE_3_K3__, __MOUSE_3_K4__,                             _______, _______, _______,
                                 _______, MS_BTN1, /*MS_BTN3, MS_BTN3,*/ MS_BTN2, _______
 )
};

// Combo definitions in
// users/sadekbaroudi/combos.c
