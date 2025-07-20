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

// NOTE: All logic for the modules can be found in:
// keyboards/fingerpunch/src/vik/config.vik.pre.h
// keyboards/fingerpunch/src/vik/config.vik.post.h
// keyboards/fingerpunch/src/vik/rules.mk

#pragma once

#include "keyboards/fingerpunch/src/config_pre.h"

#define RP2040_BOOTLOADER_DOUBLE_TAP_RESET

/* Set 0 if debouncing isn't needed */
#define DEBOUNCE 5

/* Mechanical locking support. Use KC_LCAP, KC_LNUM or KC_LSCR instead in keymap */
#define LOCKING_SUPPORT_ENABLE
/* Locking resynchronize hack */
#define LOCKING_RESYNC_ENABLE

/* key matrix size */
// Rows are doubled-up
#define MATRIX_ROWS 4
#define MATRIX_COLS 7

// VIK pin config
#define VIK_SPI_DRIVER    SPID1
#define VIK_SPI_SCK_PIN   GP14
#define VIK_SPI_MOSI_PIN  GP15
#define VIK_SPI_MISO_PIN  GP12
#define VIK_SPI_CS        GP13
#define VIK_I2C_DRIVER    I2CD1
#ifdef FP_XIVIK_V01
    #define VIK_I2C_SDA_PIN   GP22
    #define VIK_I2C_SCL_PIN   GP23
#else // v0.2 or v0.3
    #define VIK_I2C_SDA_PIN   GP8
    #define VIK_I2C_SCL_PIN   GP9
#endif
#if defined(FP_XIVIK_V01) || defined(FP_XIVIK_V02)
#define VIK_GPIO_1        GP18
#define VIK_GPIO_2        GP10
#else // If we're here, it's v03
#define VIK_GPIO_1        GP26
#define VIK_GPIO_2        GP27
#endif
#define VIK_WS2812_DI_PIN GP16

// Used only if you have a display with RESET unconnected, set to unused pin
#define VIK_DISPLAY_RST_UNUSED_PIN GP11

// All the through hole pins from the controller
#ifdef FP_XIVIK_V01
#define MATRIX_ROW_PINS { GP24, GP9, GP8, GP7 }
#define MATRIX_COL_PINS { GP0, GP1, GP2, GP3, GP4, GP5, GP6 }
#elif defined(FP_XIVIK_V02)
#define MATRIX_ROW_PINS { GP23, GP20, GP22, GP21 }
#define MATRIX_COL_PINS { GP0, GP1, GP2, GP3, GP5, GP6, GP4 }
#else // If we're here, it's v03
#define MATRIX_ROW_PINS { GP23, GP20, GP22, GP21 }
#define MATRIX_COL_PINS { GP0, GP1, GP2, GP3, GP6, GP7, GP4 }
#endif

/* COL2ROW or ROW2COL */
#define DIODE_DIRECTION COL2ROW

// For VIK modules with encoders
#ifdef ENCODER_ENABLE
#if defined(FP_XIVIK_V01) || defined(FP_XIVIK_V02)
#define ENCODER_A_PINS { GP18 }
#define ENCODER_B_PINS { GP10 }
#else // If we're here, it's v03
#define ENCODER_A_PINS { GP26 }
#define ENCODER_B_PINS { GP27 }
#endif
#endif

#ifdef CIRQUE_ENABLE
    // cirque trackpad config
    #define CIRQUE_PINNACLE_SPI_CS_PIN VIK_SPI_CS
    // Uncomment 2 lines below to switch to relative mode and enable right click
    // Note that tap to click doesn't work on the slave side unless you enable relative mode
    // #define CIRQUE_PINNACLE_POSITION_MODE CIRQUE_PINNACLE_RELATIVE_MODE
    // #define CIRQUE_PINNACLE_SECONDARY_TAP_ENABLE
    #define CIRQUE_PINNACLE_TAP_ENABLE
    #define POINTING_DEVICE_TASK_THROTTLE_MS 5
#endif

// If directly testing with xivik, use VIK RGB only
#ifndef VIK_RGB_ONLY
#define VIK_RGB_ONLY
#endif

#define WS2812_DI_PIN GP16
#ifdef RGBLIGHT_ENABLE
    #define RGBLIGHT_LED_COUNT 10 // Arbitrary number, gets overridden by the vik module stuff below
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

#include "keyboards/fingerpunch/src/config_post.h"
