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
#define MATRIX_ROWS 9
#define MATRIX_COLS 8

// SHIFT REGISTER
// Only needed for matrix_74hc595_spi.c
#define SHIFTREG_MATRIX_COL_CS B6
#define SHIFTREG_DIVISOR 8 // needs to be the same as the PMW33XX_CS_DIVISOR below
#define MATRIX_ROW_PINS_SR { D4, C6, D7, E6, B4, F4, F5, F6, F7 }

#define WS2812_DI_PIN D3
#ifdef RGBLIGHT_ENABLE
  #ifdef RGBLIGHT_LED_COUNT
    #undef RGBLIGHT_LED_COUNT
  #endif
  #define RGBLIGHT_LED_COUNT 69
#endif

#ifdef RGB_MATRIX_ENABLE
  #ifdef RGB_MATRIX_LED_COUNT
    #undef RGB_MATRIX_LED_COUNT
  #endif
  #define RGB_MATRIX_LED_COUNT 69
#endif

// SPI config for shift register (and trackball if enabled)
#define SPI_SCK_PIN B1
#define SPI_MOSI_PIN B2
#define SPI_MISO_PIN B3

#if defined(CONVERT_TO_ELITE_PI) || defined(CONVERT_TO_RP2040_CE) || defined(CONVERT_TO_HELIOS) || defined(CONVERT_TO_LIATRIS) || defined(CONVERT_TO_KB2040)
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

// Skip encoders and audio if using KB2040, as they can't be used without the bottom 5 pins
#ifndef CONVERT_TO_KB2040
  // If we have audio enabled, that means we're not using the center encoder, as they share a pin on the controller
  // Note that you need to solder the jumper on the pcb and remove teh audio buzzer from the pcb if using the center encoder
  #ifdef AUDIO_ENABLE
      #define ENCODER_A_PINS {C7, D5}
      #define ENCODER_B_PINS {D2, B7}
  #else
      #define ENCODER_A_PINS {C7, D5, F1}
      #define ENCODER_B_PINS {D2, B7, F0}
  #endif

  #ifdef AUDIO_ENABLE
      #define AUDIO_VOICES
      #define AUDIO_PIN F1
      #ifdef CONVERT_TO_STEMCELL
      #define AUDIO_PWM_DRIVER PWMD2
      #define AUDIO_PWM_CHANNEL 1
      #define AUDIO_STATE_TIMER GPTD4
      #endif // CONVERT_TO_STEMCELL
      #if defined(CONVERT_TO_ELITE_PI) || defined(CONVERT_TO_RP2040_CE) || defined(CONVERT_TO_HELIOS) || defined(CONVERT_TO_LIATRIS)
      #define AUDIO_PWM_DRIVER PWMD7
      #define AUDIO_PWM_CHANNEL RP2040_PWM_CHANNEL_A
      #define AUDIO_STATE_TIMER GPTD1
      #endif // CONVERT_TO_(any_rp2040)
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

#ifdef CIRQUE_ENABLE
  // cirque trackpad config
  #define CIRQUE_PINNACLE_ADDR 0x2A
  #define POINTING_DEVICE_ROTATION_90
  #define CIRQUE_PINNACLE_TAP_ENABLE
  #define POINTING_DEVICE_TASK_THROTTLE_MS 5
  #define I2C1_CLOCK_SPEED  400000
  #define I2C1_DUTY_CYCLE FAST_DUTY_CYCLE_2
#endif

#ifdef FP_TRACKBALL_ENABLE
  // Trackball config
  #define PMW33XX_CS_PIN B5
  #define PMW33XX_CS_DIVISOR 8 // needs to be the same as the SHIFTREG_DIVISOR above
  #define POINTING_DEVICE_INVERT_Y
#endif

#include "keyboards/fingerpunch/src/config_post.h"
