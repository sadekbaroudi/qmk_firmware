/*
Copyright 2012 Jun Wako <wakojun@gmail.com>

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#pragma once

#include "config_common.h"

/* USB Device descriptor parameter */
#define DEVICE_VER      0x0001
#define VENDOR_ID       0xFEFE
#define PRODUCT_ID      0x7178
#define MANUFACTURER    sadekbaroudi
#define PRODUCT         sadekbaroudi luakeeb
#define DESCRIPTION     sadekbaroudi luakeeb

/* key matrix size */
// Rows are doubled-up
#define MATRIX_ROWS 8
#define MATRIX_COLS 12

/* COL2ROW or ROW2COL */
#define DIODE_DIRECTION COL2ROW

// wiring of each half
#define MATRIX_ROW_PINS { F6, D7, B3, E6 }
#define MATRIX_COL_PINS { F7, F4, D4, F5, B1, B2 }

#define SOFT_SERIAL_PIN D2

#define USE_SERIAL

// BEGIN PWM driver: uncomment if using STeMcell as it's a better led driver
// #define WS2812_PWM_DRIVER PWMD2  // default: PWMD2
// #define WS2812_PWM_CHANNEL 2  // default: 2
// #define WS2812_PWM_PAL_MODE 2  // Pin "alternate function", see the respective datasheet for the appropriate values for your MCU. default: 2
// #define WS2812_DMA_STREAM STM32_DMA1_STREAM2  // DMA Stream for TIMx_UP, see the respective reference manual for the appropriate values for your MCU.
// #define WS2812_DMA_CHANNEL 2  // DMA Channel for TIMx_UP, see the respective reference manual for the appropriate values for your MCU.
// #define WS2812_DMAMUX_ID STM32_DMAMUX1_TIM2_UP // DMAMUX configuration for TIMx_UP -- only required if your MCU has a DMAMUX peripheral, see the respective reference manual for the appropriate values for your MCU.
// END PWM driver: uncomment if using STeMcell as it's a better led driver
#define RGB_DI_PIN D3
#ifdef RGBLIGHT_ENABLE
  #define RGBLIGHT_SPLIT
  #define RGBLED_SPLIT { 21, 21 }
  #ifdef RGBLIGHT_ANIMATIONS
  #undef RGBLIGHT_ANIMATIONS
  #endif
  #define RGBLED_NUM 42
  #define RGBLIGHT_HUE_STEP 16
  #define RGBLIGHT_SAT_STEP 16
  #define RGBLIGHT_VAL_STEP 16
  #define RGBLIGHT_LIMIT_VAL 120 /* The maximum brightness level for RGBLIGHT_ENABLE */
  #define RGBLIGHT_SLEEP  /* If defined, the RGB lighting will be switched off when the host goes to sleep */
// /*== all animations enable ==*/
//  #define RGBLIGHT_ANIMATIONS
// /*== or choose animations ==*/
//   #define RGBLIGHT_EFFECT_BREATHING
//   #define RGBLIGHT_EFFECT_RAINBOW_MOOD
   #define RGBLIGHT_EFFECT_RAINBOW_SWIRL
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

#define ENCODERS_PAD_A {B4}
#define ENCODERS_PAD_B {B5}

#define ENCODER_RESOLUTION 2
// Per encoder settings
//#define ENCODER_RESOLUTIONS { 2, 2 }

/* define if matrix has ghost */
//#define MATRIX_HAS_GHOST

/* number of backlight levels */
// #define BACKLIGHT_LEVELS 3

/* Set 0 if debouncing isn't needed */
#define DEBOUNCE 5

/* Mechanical locking support. Use KC_LCAP, KC_LNUM or KC_LSCR instead in keymap */
#define LOCKING_SUPPORT_ENABLE
/* Locking resynchronize hack */
#define LOCKING_RESYNC_ENABLE

/* disable debug print */
//#define NO_DEBUG

/* disable print */
//#define NO_PRINT

/* disable action features */
//#define NO_ACTION_LAYER
//#define NO_ACTION_TAPPING
//#define NO_ACTION_ONESHOT
//#define NO_ACTION_MACRO
//#define NO_ACTION_FUNCTION

//#define MASTER_RIGHT
#define BOOTMAGIC_LITE_ROW_RIGHT 4
#define BOOTMAGIC_LITE_COLUMN_RIGHT 0
