/*
Copyright 2021 Sadek Baroudi <sadekbaroudi@gmail.com>

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

#include "keyboards/fingerpunch/src/config_pre.h"

/* Debounce reduces chatter (unintended double-presses) - set 0 if debouncing is not needed */
#define DEBOUNCE 5

/* COL2ROW, ROW2COL*/
#define DIODE_DIRECTION COL2ROW

#define WS2812_DI_PIN B7
#ifdef RGBLIGHT_ENABLE
  // #define DEFAULT_RGB_LAYER_MODE RGBLIGHT_MODE_TWINKLE+2
  #define WS2812_BYTE_ORDER WS2812_BYTE_ORDER_RGB
  #define RGBLIGHT_LED_COUNT 2
  #define RGBLIGHT_HUE_STEP 16
  #define RGBLIGHT_SAT_STEP 16
  #define RGBLIGHT_VAL_STEP 16
  #define RGBLIGHT_LIMIT_VAL 50 /* The maximum brightness level for RGBLIGHT_ENABLE */
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

/* Mechanical locking support. Use KC_LCAP, KC_LNUM or KC_LSCR instead in keymap */
#define LOCKING_SUPPORT_ENABLE
/* Locking resynchronize hack */
#define LOCKING_RESYNC_ENABLE

#if defined(FP_CONVERT_TO_SVLINKY_V01) || defined(FP_CONVERT_TO_SVLINKY_V02)
// VIK pin config
#define VIK_SPI_DRIVER    SPID1
#define VIK_SPI_SCK_PIN   GP14
#define VIK_SPI_MOSI_PIN  GP15
#define VIK_SPI_MISO_PIN  GP12
#define VIK_SPI_CS        GP13
#define VIK_I2C_DRIVER    I2CD1
#define VIK_I2C_SDA_PIN   GP10
#define VIK_I2C_SCL_PIN   GP11
#ifdef FP_CONVERT_TO_SVLINKY_V01
#define VIK_GPIO_1        GP18
#define VIK_GPIO_2        GP24
#else // svlinky v0.2
#define VIK_GPIO_1        GP26
#define VIK_GPIO_2        GP27
#endif
#define VIK_WS2812_DI_PIN GP16

#ifdef VIK_EC11_EVQWGD001
#define ENCODER_A_PINS {GP18}
#define ENCODER_B_PINS {GP24}
#endif
#endif

#include "keyboards/fingerpunch/src/config_post.h"