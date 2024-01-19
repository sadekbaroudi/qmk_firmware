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

// clang-format off
#define LAYOUT_svlinky_base( \
    K01, K02, K03, K04, K05, K06, K07, K08, K09, K10, \
    K11, K12, K13, K14, K15, K16, K17, K18, K19, K20, \
    K21, K22, K23, K24, K25, K26, K27, K28, K29, K30, \
    K31, K32, K33, K34, K35, K36, K37, K38, K39, K40, \
    K41, K42, K43, K44, K45, K46, K47, K48, K49, K50, \
    K51, K52, K53, K54, K55, K56, K57, K58, K59, K60, \
    K61, K62, K63, K64, K65, K66, K67, K68, K69, K70, \
    K71, K72, K73, K74, K75, K76, K77, K78, K79, K80 \
  ) \
  LAYOUT_wrapper( \
        K01, K02, K03, K04, K05, K06, K07, K08, K09, K10, \
        K11, K12, K13, K14, K15, K16, K17, K18, K19, K20, \
        K21, K22, K23, K24, K25, K26, K27, K28, K29, K30, \
        K31, K32, K33, K34, K35, K36, K37, K38, K39, K40, \
        K41, K42, K43, K44, K45, K46, K47, K48, K49, K50, \
        K51, K52, K53, K54, K55, K56, K57, K58, K59, K60, \
        K61, K62, K63, K64, K65, K66, K67, K68, K69, K70, \
        K71, K72, K73, K74, K75, K76, K77, K78, K79, K80 \
    )

/* Re-pass though to allow templates to be used */
#define LAYOUT_svlinky_base_wrapper(...)       LAYOUT_svlinky_base(__VA_ARGS__)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    [_ALPHA_ALT] = LAYOUT_wrapper(
        KC_Q,         KC_W,         KC_E,         KC_R,         KC_T,         KC_Y,    KC_U,         KC_I,         KC_O,         KC_P,
        KC_A,         KC_S,         KC_D,         KC_F,         KC_G,         KC_H,    KC_J,         KC_K,         KC_L,         KC_SCLN,
        KC_Z,         KC_X,         KC_C,         KC_V,         KC_B,         KC_N,    KC_M,         KC_COMM,      KC_DOT,       KC_SLSH,
        KC_0,         KC_1,         KC_2,         KC_3,         KC_4,         KC_5,    KC_6,         KC_7,         KC_8,         KC_9,
        KC_Q,         KC_W,         KC_E,         KC_R,         KC_T,         KC_Y,    KC_U,         KC_I,         KC_O,         KC_P,
        KC_A,         KC_S,         KC_D,         KC_F,         KC_G,         KC_H,    KC_J,         KC_K,         KC_L,         KC_SCLN,
        KC_Z,         KC_X,         KC_C,         KC_V,         KC_B,         KC_N,    KC_M,         KC_COMM,      KC_DOT,       KC_SLSH,
        KC_0,         KC_1,         KC_2,         KC_3,         KC_4,         KC_5,    KC_6,         KC_7,         KC_8,         KC_9
    ),

    [_ALPHA] = LAYOUT_wrapper(
        KC_Q,         KC_W,         KC_E,         KC_R,         KC_T,         KC_Y,    KC_U,         KC_I,         KC_O,         KC_P,
        KC_A,         KC_S,         KC_D,         KC_F,         KC_G,         KC_H,    KC_J,         KC_K,         KC_L,         KC_SCLN,
        KC_Z,         KC_X,         KC_C,         KC_V,         KC_B,         KC_N,    KC_M,         KC_COMM,      KC_DOT,       KC_SLSH,
        KC_0,         KC_1,         KC_2,         KC_3,         KC_4,         KC_5,    KC_6,         KC_7,         KC_8,         KC_9,
        KC_Q,         KC_W,         KC_E,         KC_R,         KC_T,         KC_Y,    KC_U,         KC_I,         KC_O,         KC_P,
        KC_A,         KC_S,         KC_D,         KC_F,         KC_G,         KC_H,    KC_J,         KC_K,         KC_L,         KC_SCLN,
        KC_Z,         KC_X,         KC_C,         KC_V,         KC_B,         KC_N,    KC_M,         KC_COMM,      KC_DOT,       KC_SLSH,
        KC_0,         KC_1,         KC_2,         KC_3,         KC_4,         KC_5,    KC_6,         KC_7,         KC_8,         KC_9
    ),

    [_NAVIGATION] = LAYOUT_wrapper(
        KC_Q,         KC_W,         KC_E,         KC_R,         KC_T,         KC_Y,    KC_U,         KC_I,         KC_O,         KC_P,
        KC_A,         KC_S,         KC_D,         KC_F,         KC_G,         KC_H,    KC_J,         KC_K,         KC_L,         KC_SCLN,
        KC_Z,         KC_X,         KC_C,         KC_V,         KC_B,         KC_N,    KC_M,         KC_COMM,      KC_DOT,       KC_SLSH,
        KC_0,         KC_1,         KC_2,         KC_3,         KC_4,         KC_5,    KC_6,         KC_7,         KC_8,         KC_9,
        KC_Q,         KC_W,         KC_E,         KC_R,         KC_T,         KC_Y,    KC_U,         KC_I,         KC_O,         KC_P,
        KC_A,         KC_S,         KC_D,         KC_F,         KC_G,         KC_H,    KC_J,         KC_K,         KC_L,         KC_SCLN,
        KC_Z,         KC_X,         KC_C,         KC_V,         KC_B,         KC_N,    KC_M,         KC_COMM,      KC_DOT,       KC_SLSH,
        KC_0,         KC_1,         KC_2,         KC_3,         KC_4,         KC_5,    KC_6,         KC_7,         KC_8,         KC_9
    ),

    [_SYMBOLS] = LAYOUT_wrapper(
        KC_Q,         KC_W,         KC_E,         KC_R,         KC_T,         KC_Y,    KC_U,         KC_I,         KC_O,         KC_P,
        KC_A,         KC_S,         KC_D,         KC_F,         KC_G,         KC_H,    KC_J,         KC_K,         KC_L,         KC_SCLN,
        KC_Z,         KC_X,         KC_C,         KC_V,         KC_B,         KC_N,    KC_M,         KC_COMM,      KC_DOT,       KC_SLSH,
        KC_0,         KC_1,         KC_2,         KC_3,         KC_4,         KC_5,    KC_6,         KC_7,         KC_8,         KC_9,
        KC_Q,         KC_W,         KC_E,         KC_R,         KC_T,         KC_Y,    KC_U,         KC_I,         KC_O,         KC_P,
        KC_A,         KC_S,         KC_D,         KC_F,         KC_G,         KC_H,    KC_J,         KC_K,         KC_L,         KC_SCLN,
        KC_Z,         KC_X,         KC_C,         KC_V,         KC_B,         KC_N,    KC_M,         KC_COMM,      KC_DOT,       KC_SLSH,
        KC_0,         KC_1,         KC_2,         KC_3,         KC_4,         KC_5,    KC_6,         KC_7,         KC_8,         KC_9
    ),

    [_FUNCTION] = LAYOUT_wrapper(
        KC_Q,         KC_W,         KC_E,         KC_R,         KC_T,         KC_Y,    KC_U,         KC_I,         KC_O,         KC_P,
        KC_A,         KC_S,         KC_D,         KC_F,         KC_G,         KC_H,    KC_J,         KC_K,         KC_L,         KC_SCLN,
        KC_Z,         KC_X,         KC_C,         KC_V,         KC_B,         KC_N,    KC_M,         KC_COMM,      KC_DOT,       KC_SLSH,
        KC_0,         KC_1,         KC_2,         KC_3,         KC_4,         KC_5,    KC_6,         KC_7,         KC_8,         KC_9,
        KC_Q,         KC_W,         KC_E,         KC_R,         KC_T,         KC_Y,    KC_U,         KC_I,         KC_O,         KC_P,
        KC_A,         KC_S,         KC_D,         KC_F,         KC_G,         KC_H,    KC_J,         KC_K,         KC_L,         KC_SCLN,
        KC_Z,         KC_X,         KC_C,         KC_V,         KC_B,         KC_N,    KC_M,         KC_COMM,      KC_DOT,       KC_SLSH,
        KC_0,         KC_1,         KC_2,         KC_3,         KC_4,         KC_5,    KC_6,         KC_7,         KC_8,         KC_9
    ),

    [_MEDIA] = LAYOUT_wrapper(
        KC_Q,         KC_W,         KC_E,         KC_R,         KC_T,         KC_Y,    KC_U,         KC_I,         KC_O,         KC_P,
        KC_A,         KC_S,         KC_D,         KC_F,         KC_G,         KC_H,    KC_J,         KC_K,         KC_L,         KC_SCLN,
        KC_Z,         KC_X,         KC_C,         KC_V,         KC_B,         KC_N,    KC_M,         KC_COMM,      KC_DOT,       KC_SLSH,
        KC_0,         KC_1,         KC_2,         KC_3,         KC_4,         KC_5,    KC_6,         KC_7,         KC_8,         KC_9,
        KC_Q,         KC_W,         KC_E,         KC_R,         KC_T,         KC_Y,    KC_U,         KC_I,         KC_O,         KC_P,
        KC_A,         KC_S,         KC_D,         KC_F,         KC_G,         KC_H,    KC_J,         KC_K,         KC_L,         KC_SCLN,
        KC_Z,         KC_X,         KC_C,         KC_V,         KC_B,         KC_N,    KC_M,         KC_COMM,      KC_DOT,       KC_SLSH,
        KC_0,         KC_1,         KC_2,         KC_3,         KC_4,         KC_5,    KC_6,         KC_7,         KC_8,         KC_9
    ),
    
    [_MOUSE] = LAYOUT_wrapper(
        KC_Q,         KC_W,         KC_E,         KC_R,         KC_T,         KC_Y,    KC_U,         KC_I,         KC_O,         KC_P,
        KC_A,         KC_S,         KC_D,         KC_F,         KC_G,         KC_H,    KC_J,         KC_K,         KC_L,         KC_SCLN,
        KC_Z,         KC_X,         KC_C,         KC_V,         KC_B,         KC_N,    KC_M,         KC_COMM,      KC_DOT,       KC_SLSH,
        KC_0,         KC_1,         KC_2,         KC_3,         KC_4,         KC_5,    KC_6,         KC_7,         KC_8,         KC_9,
        KC_Q,         KC_W,         KC_E,         KC_R,         KC_T,         KC_Y,    KC_U,         KC_I,         KC_O,         KC_P,
        KC_A,         KC_S,         KC_D,         KC_F,         KC_G,         KC_H,    KC_J,         KC_K,         KC_L,         KC_SCLN,
        KC_Z,         KC_X,         KC_C,         KC_V,         KC_B,         KC_N,    KC_M,         KC_COMM,      KC_DOT,       KC_SLSH,
        KC_0,         KC_1,         KC_2,         KC_3,         KC_4,         KC_5,    KC_6,         KC_7,         KC_8,         KC_9
    )

};
