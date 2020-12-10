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

#include QMK_KEYBOARD_H
#include "muse.h"

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

[0] = LAYOUT_ortho_5x12(
  KC_NO,                 KC_NO,                 KC_NO,                 KC_NO,                 KC_NO,                 KC_NO,                 KC_NO,                 KC_NO,                 KC_NO,                 KC_NO,                 KC_NO,                 KC_NO,
  LALT_T(KC_TAB),        KC_Q,                  KC_W,                  KC_E,                  KC_R,                  KC_T,                  KC_Y,                  KC_U,                  KC_I,                  KC_O,                  KC_P,                  KC_BSLS,
  LGUI_T(KC_ESC),        KC_A,                  KC_S,                  KC_D,                  KC_F,                  KC_G,                  KC_H,                  KC_J,                  KC_K,                  KC_L,                  KC_SCLN,               RCTL_T(KC_QUOT),
  LCTL_T(KC_DEL),        KC_Z,                  KC_X,                  KC_C,                  KC_V,                  KC_B,                  KC_N,                  KC_M,                  KC_COMM,               KC_DOT,                KC_SLSH,               KC_BSPC,
  KC_NO,                 KC_NO,                 KC_NO,                 KC_NO,                 LT(1,KC_TAB),          KC_NO,        LSFT_T(KC_SPC),        LT(2,KC_ENT),          KC_NO,                 KC_NO,                 KC_NO,                 KC_N
),

[1] = LAYOUT_ortho_5x12(
  KC_NO,                 KC_NO,                 KC_NO,                 KC_NO,                 KC_NO,                 KC_NO,                 KC_NO,                 KC_NO,                 KC_NO,                 KC_NO,                 KC_NO,                 KC_NO,
  LGUI(LSFT(KC_S)),      LCTL(KC_W),            KC_PGUP,               KC_UP,                 KC_PGDN,               LCTL(KC_TAB),          KC_ASTR,               KC_7,                  KC_8,                  KC_9,                  KC_PLUS,               KC_DEL,
  LALT(KC_F4),           KC_HOME,               KC_LEFT,               KC_DOWN,               KC_RGHT,               KC_END,                KC_SLSH,               KC_4,                  KC_5,                  KC_6,                  KC_MINS,               KC_DOT,
  LCTL(LALT(KC_DELETE)), LCTL(KC_Z),            LCTL(KC_X),            LCTL(KC_C),            LCTL(KC_V),            LCTL(LSFT(KC_TAB)),    KC_PEQL,               KC_1,                  KC_2,                  KC_3,                  KC_0,                  KC_NO,
  KC_NO,                 KC_NO,                 KC_NO,                 KC_NO,                 KC_NO,                 KC_NO,                 KC_NO,                 MO(3),                 KC_NO,                 KC_NO,                 KC_NO,                 KC_NO
),

[2] = LAYOUT_ortho_5x12(
  KC_NO,                 KC_NO,                 KC_NO,                 KC_NO,                 KC_NO,                 KC_NO,                 KC_NO,                 KC_NO,                 KC_NO,                 KC_NO,                 KC_NO,                 KC_NO,
  KC_GRV,                KC_EXLM,               KC_AT,                 KC_HASH,               KC_DLR,                KC_PERC,               KC_CIRC,               KC_AMPR,               KC_ASTR,               KC_LPRN,               KC_RPRN,               KC_NO,
  KC_NO,                 KC_MINS,               KC_LBRC,               KC_LCBR,               KC_LPRN,               KC_LT,                 KC_GT,                 KC_RPRN,               KC_RCBR,               KC_RBRC,               KC_PLUS,               KC_NO,
  KC_NO,                 KC_UNDS,               KC_EQL,                KC_NO,                 LCTL(LGUI(KC_LEFT)),   KC_NO,                 KC_NO,                 LCTL(LGUI(KC_RIGHT)),  KC_NO,                 KC_NO,                 KC_SLSH,               KC_NO,
  KC_NO,                 KC_NO,                 KC_NO,                 KC_NO,                 MO(3),                 KC_NO,                 KC_NO,                 KC_NO,                 KC_NO,                 KC_NO,                 KC_NO,                 KC_NO
),

[3] = LAYOUT_ortho_5x12(
  RGB_TOG,               BL_TOGG,               KC_NO,                 KC_NO,                 KC_NO,                 KC_NO,                 KC_NO,                 KC_NO,                 KC_NO,                 KC_NO,                 MU_MOD,                MU_TOG,
  RESET,                 KC_NO,                 LSFT(KC_PGDN),         LSFT(KC_UP),           LSFT(KC_PGUP),         KC_NO,                 KC_MPLY,               KC_F7,                 KC_F8,                 KC_F9,                 KC_F10,                KC_NO,
  KC_NO,                 LSFT(KC_HOME),         LSFT(KC_LEFT),         LSFT(KC_DOWN),         LSFT(KC_RGHT),         LSFT(KC_END),          KC_VOLU,               KC_F4,                 KC_F5,                 KC_F6,                 KC_F11,                KC_MFFD,
  KC_NO,                 LCTL(KC_Z),            LCTL(KC_X),            LCTL(KC_C),            LCTL(KC_V),            DM_PLY1,               KC_VOLD,               KC_F1,                 KC_F2,                 KC_F3,                 KC_F12,                KC_MRWD,
  KC_NO,                 KC_NO,                 KC_NO,                 KC_NO,                 KC_TRNS,               KC_NO,               DM_REC1,               KC_TRNS,               KC_NO,                 KC_NO,                 KC_NO,                 KC_NO
)

};


