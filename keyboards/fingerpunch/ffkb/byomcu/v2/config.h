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

/* key matrix size */
/* Rows are doubled up */
#define MATRIX_ROWS 6
#define MATRIX_COLS 8

// wiring
#define MATRIX_ROW_PINS \
    { D2, F4, F5, F6, F7, B1 }
#define MATRIX_COL_PINS \
    { B5, B4, E6, D7, C6, D4, B2, B3 }

#define ENCODER_A_PINS {D5, B6, D1}
#define ENCODER_B_PINS {B7, F1, D0}

#ifdef FP_EVQ_UNDER_PALMS
#define ENCODERS_A_REVERSE
#define ENCODERS_B_REVERSE
#endif

#ifdef FP_EC11_UNDER_PALMS
#define ENCODERS_C_REVERSE
#endif

#if defined(OLED_ENABLE) || defined(PIMORONI_TRACKBALL_ENABLE)
#undef ENCODER_A_PINS
#define ENCODER_A_PINS {D5, B6}
#undef ENCODER_B_PINS
#define ENCODER_B_PINS {B7, F1}
#endif

#define ENCODER_RESOLUTION 2

#ifdef PIMORONI_TRACKBALL_ENABLE
#define PIMORONI_TRACKBALL_ROTATE
#define PIMORONI_TRACKBALL_CLICK
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

#ifdef AUDIO_ENABLE
    #define AUDIO_VOICES
    #define AUDIO_PIN F0
    #if defined(CONVERT_TO_ELITE_PI) || defined(CONVERT_TO_RP2040_CE) || defined(CONVERT_TO_HELIOS) || defined(CONVERT_TO_LIATRIS) || defined(CONVERT_TO_KB2040) || defined(CONVERT_TO_PROMICRO_RP2040)
    #define AUDIO_PWM_DRIVER PWMD0
    #define AUDIO_PWM_CHANNEL RP2040_PWM_CHANNEL_A
    #else
    #define AUDIO_PWM_DRIVER PWMD2
    #define AUDIO_PWM_CHANNEL 1
    #define AUDIO_STATE_TIMER GPTD4
    #endif
    #define AUDIO_VOICES
    // #define AUDIO_PWM_PAL_MODE 42 // only if using AUDIO_DRIVER = pwm_hardware
    // #define NO_MUSIC_MODE
    #define AUDIO_ENABLE_TONE_MULTIPLEXING
    #define AUDIO_TONE_MULTIPLEXING_RATE_DEFAULT 10
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
    #define FP_HAPTIC_MOUSE_BUTTONS
    #define FP_HAPTIC_CUT_COPY_PASTE
    #define FP_HAPTIC_SAVE
#endif

#include "keyboards/fingerpunch/src/config_post.h"
