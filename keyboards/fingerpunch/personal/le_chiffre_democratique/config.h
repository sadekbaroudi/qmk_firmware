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

/* Mechanical locking support. Use KC_LCAP, KC_LNUM or KC_LSCR instead in keymap */
#define LOCKING_SUPPORT_ENABLE
/* Locking resynchronize hack */
#define LOCKING_RESYNC_ENABLE

/* key matrix size */
/* Rows are doubled up */
#define MATRIX_ROWS 5
#define MATRIX_COLS 8

// SHIFT REGISTER
// Only needed for matrix_74hc595_spi.c
#define SHIFTREG_MATRIX_COL_CS B6
#define SHIFTREG_DIVISOR 8 // needs to be the same as the PMW33XX_CS_DIVISOR below
#define MATRIX_ROW_PINS_SR { C6, D7, E6, B4, B5 }

// SPI config for shift register (and trackball if enabled)
#define SPI_SCK_PIN B1
#define SPI_MOSI_PIN B2
#define SPI_MISO_PIN B3

#if defined(CONVERT_TO_ELITE_PI) || defined(CONVERT_TO_RP2040_CE) || defined(CONVERT_TO_HELIOS) || defined(CONVERT_TO_LIATRIS)
#define SPI_DRIVER SPID0
#endif // CONVERT_TO_(any_rp2040)

#ifdef CONVERT_TO_STEMCELL
#define SPI_DRIVER SPID1
#define SPI_SCK_PAL_MODE 5
#define SPI_MOSI_PAL_MODE 5
#define SPI_MISO_PAL_MODE 5
#endif // CONVERT_TO_STEMCELL

/* COL2ROW, ROW2COL*/
#define DIODE_DIRECTION COL2ROW

#define ENCODER_A_PINS {D2}
#define ENCODER_B_PINS {D3}
#define ENCODER_RESOLUTION 2

// VIK pin config
#define VIK_SPI_DRIVER    SPID0
#define VIK_SPI_SCK_PIN   B1
#define VIK_SPI_MOSI_PIN  B2
#define VIK_SPI_MISO_PIN  B3
#define VIK_SPI_CS        F7
#define VIK_I2C_DRIVER    I2CD1
#define VIK_I2C_SDA_PIN   D1
#define VIK_I2C_SCL_PIN   D0
#define VIK_GPIO_1        F5
#define VIK_GPIO_2        F4
#define VIK_WS2812_DI_PIN D4

// Used only if you have a display with RESET unconnected, set to unused pin
#define VIK_DISPLAY_RST_UNUSED_PIN F6

/* COL2ROW, ROW2COL*/
#define DIODE_DIRECTION COL2ROW

#define WS2812_DI_PIN D4
#ifdef RGBLIGHT_ENABLE
  #define RGBLIGHT_LED_COUNT 47
  #define RGBLIGHT_HUE_STEP 16
  #define RGBLIGHT_SAT_STEP 16
  #define RGBLIGHT_VAL_STEP 16
  #define RGBLIGHT_LIMIT_VAL 100 /* The maximum brightness level for RGBLIGHT_ENABLE */
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

#ifdef RGB_MATRIX_ENABLE
  #define RGB_MATRIX_LED_COUNT 47
  #define RGB_MATRIX_CENTER {100, 32}
  #define RGB_MATRIX_MAXIMUM_BRIGHTNESS 100  /* The maximum brightness level for RGB_MATRIX */
  #define RGB_MATRIX_STARTUP_VAL RGB_MATRIX_MAXIMUM_BRIGHTNESS // Sets the default brightness value, if none has been set
  #define RGB_MATRIX_KEYPRESSES
  #define RGB_MATRIX_FRAMEBUFFER_EFFECTS
  #define RGB_MATRIX_KEYREACTIVE_ENABLED
  #define ENABLE_RGB_MATRIX_ALPHAS_MODS
  #define ENABLE_RGB_MATRIX_GRADIENT_UP_DOWN
  #define ENABLE_RGB_MATRIX_GRADIENT_LEFT_RIGHT
  #define ENABLE_RGB_MATRIX_BREATHING
  #define ENABLE_RGB_MATRIX_BAND_SAT
  #define ENABLE_RGB_MATRIX_BAND_VAL
  #define ENABLE_RGB_MATRIX_BAND_PINWHEEL_SAT
  #define ENABLE_RGB_MATRIX_BAND_PINWHEEL_VAL
  #define ENABLE_RGB_MATRIX_BAND_SPIRAL_SAT
  #define ENABLE_RGB_MATRIX_BAND_SPIRAL_VAL
  #define ENABLE_RGB_MATRIX_CYCLE_ALL
  #define ENABLE_RGB_MATRIX_CYCLE_LEFT_RIGHT
  #define ENABLE_RGB_MATRIX_CYCLE_UP_DOWN
  #define ENABLE_RGB_MATRIX_RAINBOW_MOVING_CHEVRON
  #define ENABLE_RGB_MATRIX_DUAL_BEACON
  #define ENABLE_RGB_MATRIX_CYCLE_PINWHEEL
  #define ENABLE_RGB_MATRIX_CYCLE_SPIRAL
  #define ENABLE_RGB_MATRIX_RAINBOW_BEACON
  #define ENABLE_RGB_MATRIX_RAINBOW_PINWHEELS
  #define ENABLE_RGB_MATRIX_RAINDROPS
  #define ENABLE_RGB_MATRIX_JELLYBEAN_RAINDROPS
  #define ENABLE_RGB_MATRIX_DIGITAL_RAIN
  #define ENABLE_RGB_MATRIX_SOLID_REACTIVE
  #define ENABLE_RGB_MATRIX_SOLID_REACTIVE_SIMPLE
  #define ENABLE_RGB_MATRIX_SOLID_REACTIVE_WIDE
  #define ENABLE_RGB_MATRIX_SOLID_REACTIVE_MULTIWIDE
  #define ENABLE_RGB_MATRIX_SOLID_REACTIVE_CROSS
  #define ENABLE_RGB_MATRIX_SOLID_REACTIVE_MULTICROSS
  #define ENABLE_RGB_MATRIX_SOLID_REACTIVE_NEXUS
  #define ENABLE_RGB_MATRIX_SOLID_REACTIVE_MULTINEXUS
  #define ENABLE_RGB_MATRIX_SPLASH
  #define ENABLE_RGB_MATRIX_MULTISPLASH
  #define ENABLE_RGB_MATRIX_SOLID_SPLASH
  #define ENABLE_RGB_MATRIX_SOLID_MULTISPLASH
#endif

#ifdef CIRQUE_ENABLE
  // cirque trackpad config
  #define CIRQUE_PINNACLE_ADDR 0x2A
  #define POINTING_DEVICE_ROTATION_90
  #define CIRQUE_PINNACLE_TAP_ENABLE
  #define POINTING_DEVICE_TASK_THROTTLE_MS 5
  #define I2C1_CLOCK_SPEED  400000
  #define I2C1_DUTY_CYCLE FAST_DUTY_CYCLE_2
#endif

#ifdef VIK_PMW3360
  #define POINTING_DEVICE_INVERT_Y
#endif

#include "keyboards/fingerpunch/src/config_post.h"
