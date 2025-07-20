/* Copyright 2022 Sadek Baroudi <sadekbaroudi@gmail.com>
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

#pragma once

#include "keyboards/fingerpunch/src/config_pre.h"

/*
 * Keyboard Matrix Assignments
 *
 * Change this to how you wired your keyboard
 * COLS: AVR pins used for columns, left to right
 * ROWS: AVR pins used for rows, top to bottom
 * DIODE_DIRECTION: COL2ROW = COL = Anode (+), ROW = Cathode (-, marked on diode)
 *                  ROW2COL = ROW = Anode (+), COL = Cathode (-, marked on diode)
 *                  NO_DIODE = switches are directly connected to AVR pins
 *
*/
#define DIRECT_PINS { \
    { B5, F7, F6, F5, F4 }, \
    { B4, D4, C6, D7, E6 }, \
    { B3, B2, B6, B7, D5 }, \
    { F0, F1, C7, NO_PIN, NO_PIN } \
}

/*
#define DIRECT_PINS_RIGHT { \
    { B5, F7, F6, F5, F4 }, \
    { B4, D4, C6, D7, E6 }, \
    { B3, B2, B6, B7, D5 }, \
    { F0, F1, C7, NO_PIN, NO_PIN } \
}
*/

#define WS2812_DI_PIN D3
#ifdef RGBLIGHT_ENABLE
  #define RGBLIGHT_LED_COUNT 36
  #define RGBLED_SPLIT {18, 18}
  #define RGBLIGHT_HUE_STEP 16
  #define RGBLIGHT_SAT_STEP 16
  #define RGBLIGHT_VAL_STEP 16
  #define RGBLIGHT_LIMIT_VAL 150 /* The maximum brightness level for RGBLIGHT_ENABLE */
  #define RGBLIGHT_SLEEP  /* If defined, the RGB lighting will be switched off when the host goes to sleep */
  #define RGBLIGHT_EFFECT_ALTERNATING
  #define RGBLIGHT_EFFECT_BREATHING
  #define RGBLIGHT_EFFECT_CHRISTMAS
  #define RGBLIGHT_EFFECT_KNIGHT
  #define RGBLIGHT_EFFECT_RAINBOW_MOOD
  #define RGBLIGHT_EFFECT_RAINBOW_SWIRL
  #define RGBLIGHT_EFFECT_SNAKE
  #define RGBLIGHT_EFFECT_STATIC_GRADIENT
  #define RGBLIGHT_EFFECT_TWINKLE
#endif

#ifdef OLED_ENABLE
#define OLED_DISPLAY_128X32
#endif

/* Debounce reduces chatter (unintended double-presses) - set 0 if debouncing is not needed */
#define DEBOUNCE 5

/* Mechanical locking support. Use KC_LCAP, KC_LNUM or KC_LSCR instead in keymap */
#define LOCKING_SUPPORT_ENABLE
/* Locking resynchronize hack */
#define LOCKING_RESYNC_ENABLE

/* Serial settings */
#define USE_SERIAL
/* serial.c configuration for split keyboard */
#define SOFT_SERIAL_PIN D2

#ifdef ENCODER_ENABLE
#define ENCODER_A_PINS {D1}
#define ENCODER_B_PINS {D0}
#define ENCODER_A_PINS_RIGHT {D1}
#define ENCODER_B_PINS_RIGHT {D0}
#endif

#define MASTER_LEFT

/* Backwards compatibility with existing out-of-tree keymaps */
#define LAYOUT_sweeeeep LAYOUT_split_3x5_3

#include "keyboards/fingerpunch/src/config_post.h"
