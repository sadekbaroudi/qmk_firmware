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

#include "config_common.h"

/* USB Device descriptor parameter */
#define DEVICE_VER      0x0001
#define VENDOR_ID       0xFEFE
#define PRODUCT_ID      0x5111
#define MANUFACTURER    sadekbaroudi
#define PRODUCT         sadekbaroudi sweeeeep
#define DESCRIPTION     sadekbaroudi sweeeeep

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


#define TAP_CODE_DELAY 25
#define TAPPING_FORCE_HOLD
#define IGNORE_MOD_TAP_INTERRUPT

#define RGB_DI_PIN D3
#ifdef RGBLIGHT_ENABLE
  #define RGBLED_NUM 36
  #define RGBLED_SPLIT {18, 18}
  #define RGBLIGHT_HUE_STEP 16
  #define RGBLIGHT_SAT_STEP 16
  #define RGBLIGHT_VAL_STEP 16
  #define RGBLIGHT_LIMIT_VAL 150 /* The maximum brightness level for RGBLIGHT_ENABLE */
  #define RGBLIGHT_SLEEP  /* If defined, the RGB lighting will be switched off when the host goes to sleep */
// /*== all animations enable ==*/
  #define RGBLIGHT_ANIMATIONS
// /*== or choose animations ==*/
//   #define RGBLIGHT_EFFECT_BREATHING
//   #define RGBLIGHT_EFFECT_RAINBOW_MOOD
//   #define RGBLIGHT_EFFECT_RAINBOW_SWIRL
//   #define RGBLIGHT_EFFECT_SNAKE
//   #define RGBLIGHT_EFFECT_KNIGHT
//   #define RGBLIGHT_EFFECT_CHRISTMAS
//   #define RGBLIGHT_EFFECT_STATIC_GRADIENT
//   #define RGBLIGHT_EFFECT_RGB_TEST
//   #define RGBLIGHT_EFFECT_ALTERNATING
// /*== customize breathing effect ==*/
//   /*==== (DEFAULT) use fixed table instead of exp() and sin() ====*/
//   #define RGBLIGHT_BREATHE_TABLE_SIZE 256      // 256(default) or 128 or 64
//   /*==== use exp() and sin() ====*/
//   #define RGBLIGHT_EFFECT_BREATHE_CENTER 1.85  // 1 to 2.7
//   #define RGBLIGHT_EFFECT_BREATHE_MAX    255   // 0 to 255
#endif

#ifdef OLED_ENABLE
#define OLED_DISPLAY_128X32
#endif

#define UNUSED_PINS

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
#define ENCODERS_PAD_A {D1}
#define ENCODERS_PAD_B {D0}
#define ENCODERS_PAD_A_RIGHT {D1}
#define ENCODERS_PAD_B_RIGHT {D0}
#endif

#define EE_HANDS
