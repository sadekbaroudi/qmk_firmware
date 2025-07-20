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

#include "keyboards/fingerpunch/src/config_pre.h"

#define RP2040_BOOTLOADER_DOUBLE_TAP_RESET

/* key matrix size */
#define MATRIX_ROWS 4
#define MATRIX_COLS 8

// For shift register (and optionally trackball)
#define SPI_SCK_PIN GP22
#define SPI_MOSI_PIN GP23
#define SPI_MISO_PIN GP20

// wiring of each half
#define MATRIX_ROW_PINS { GP29, GP28, GP27, GP24 }
#define MATRIX_COL_PINS { GP10, GP11, GP26, GP12, GP13, GP14, GP15, GP16 }

/* COL2ROW or ROW2COL */
#define DIODE_DIRECTION COL2ROW

#define ENCODER_A_PINS { GP7 }
#define ENCODER_B_PINS { GP8 }

#define WS2812_DI_PIN GP25
#ifdef RGBLIGHT_ENABLE
    #define RGBLIGHT_SPLIT
    #define RGBLED_SPLIT { 21, 21 }
    #define RGBLIGHT_LED_COUNT 42
    #define RGBLIGHT_HUE_STEP 16
    #define RGBLIGHT_SAT_STEP 16
    #define RGBLIGHT_VAL_STEP 16
    #define RGBLIGHT_LIMIT_VAL 180 /* The maximum brightness level for RGBLIGHT_ENABLE */
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
    #define SPLIT_TRANSPORT_MIRROR
    #define RGB_MATRIX_LED_COUNT 42 // Number of LEDs
    #define RGB_MATRIX_SPLIT { 21, 21 }
    #define RGB_MATRIX_MAXIMUM_BRIGHTNESS 180
    #define RGB_MATRIX_STARTUP_HUE 35
    #define RGB_MATRIX_STARTUP_VAL RGB_MATRIX_MAXIMUM_BRIGHTNESS
    #define RGB_MATRIX_SLEEP
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

/* Set 0 if debouncing isn't needed */
#define DEBOUNCE 5

/* audio support */
// Pending https://github.com/qmk/qmk_firmware/pull/17723 and https://github.com/qmk/qmk_firmware/pull/17706
#ifdef AUDIO_ENABLE
    #define AUDIO_PIN GP18
    #define AUDIO_PWM_DRIVER PWMD1
    // #define AUDIO_PWM_CHANNEL 1
    #define AUDIO_PWM_CHANNEL RP2040_PWM_CHANNEL_A
    #define FP_AUDIO_MOUSE_BUTTONS
    #define FP_AUDIO_CUT_COPY_PASTE
    #define FP_AUDIO_SAVE
    #define STARTUP_SONG SONG(STARTUP_SOUND)
    #define DEFAULT_LAYER_SONGS \
        { SONG(QWERTY_SOUND), SONG(COLEMAK_SOUND) }
#endif

#ifdef HAPTIC_ENABLE
    #define FB_ERM_LRA 1
    #define FB_BRAKEFACTOR 3 // For 1x:0, 2x:1, 3x:2, 4x:3, 6x:4, 8x:5, 16x:6, Disable Braking:7
    #define FB_LOOPGAIN 1 // For  Low:0, Medium:1, High:2, Very High:3
    #define RATED_VOLTAGE 2
    #define V_PEAK 2.8
    #define V_RMS 2.0
    #define F_LRA 150 // resonance freq
    #define DRV_GREETING  alert_750ms
#endif

/* Mechanical locking support. Use KC_LCAP, KC_LNUM or KC_LSCR instead in keymap */
#define LOCKING_SUPPORT_ENABLE
/* Locking resynchronize hack */
#define LOCKING_RESYNC_ENABLE

#ifdef CIRQUE_ENABLE
    // cirque trackpad config
    #define CIRQUE_PINNACLE_ADDR 0x2A
    // Uncomment 2 lines below to switch to relative mode and enable right click
    // Note that tap to click doesn't work on the slave side unless you enable relative mode
    // #define CIRQUE_PINNACLE_POSITION_MODE CIRQUE_PINNACLE_RELATIVE_MODE
    // #define CIRQUE_PINNACLE_SECONDARY_TAP_ENABLE
    #define CIRQUE_PINNACLE_TAP_ENABLE
    #define POINTING_DEVICE_TASK_THROTTLE_MS 5
    #define POINTING_DEVICE_ROTATION_90 // move to cirque specific config
    #define POINTING_DEVICE_ROTATION_90_RIGHT
#endif

#ifdef FP_TRACKBALL_ENABLE
    // Trackball config
    #define PMW33XX_CS_PIN GP9
    #define PMW33XX_CS_DIVISOR 8

    /* SPI config for pmw3360 sensor. */
    #define SPI_DRIVER SPID0
    // #define SPI_SCK_PAL_MODE 5 // already defined in chibios
    // #define SPI_MOSI_PAL_MODE 5 // already defined in chibios
    // #define SPI_MISO_PAL_MODE 5 // already defined in chibios
#endif

#include "keyboards/fingerpunch/src/config_post.h"
