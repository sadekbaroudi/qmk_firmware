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

/* key matrix size */
// Rows are doubled-up
#define MATRIX_ROWS 8
#define MATRIX_COLS 10

// wiring of each half
#define MATRIX_ROW_PINS { GP4, GP29, GP28, GP27 }
#define MATRIX_COL_PINS { GP5, GP6, GP7, GP8, GP9 }

// VIK pin config
#define VIK_SPI_DRIVER    SPID0
#define VIK_SPI_SCK_PIN   GP22
#define VIK_SPI_MOSI_PIN  GP23
#define VIK_SPI_MISO_PIN  GP20
#define VIK_SPI_CS        GP21
#define VIK_I2C_DRIVER    I2CD1
#define VIK_I2C_SDA_PIN   GP2
#define VIK_I2C_SCL_PIN   GP3
#define VIK_GPIO_1        GP15
#define VIK_GPIO_2        GP26
#define VIK_WS2812_DI_PIN GP0

// Got help from https://www.eisbahn.jp/yoichiro/2022/08/luankey_pico_qmk_firmware.html
#define SERIAL_PIO_USE_PIO1
#define SERIAL_USART_TX_PIN GP1     // USART TX pin

#define WS2812_DI_PIN GP0

// Used only if you have a display with RESET unconnected, set to unused pin
#define VIK_DISPLAY_RST_UNUSED_PIN GP11

// https://github.com/sadekbaroudi/vik/tree/master/pcb/pers60-cirque-leds or https://github.com/sadekbaroudi/vik/tree/master/pcb/pers60-pmw3360-leds
#ifdef FP_VIK_PERS60_MODULE
// This config assumes the VIK module is connected to the left half
#define ENCODER_A_PINS { GP14, GP15 }
#define ENCODER_B_PINS { GP13, GP26 }
#define ENCODER_RESOLUTIONS { 2, 1 }
#define ENCODER_A_PINS_RIGHT { GP14 }
#define ENCODER_B_PINS_RIGHT { GP13 }
#define ENCODER_RESOLUTIONS_RIGHT { 2 }
// Switch the default for the PERS60 rotary encoder to scrolling
#define FP_ENC_1_LAYER_SCROLL_WHEEL 0
#define FP_ENC_1_LAYER_SUPER_TAB 5
#else
#define ENCODER_A_PINS { GP14 }
#define ENCODER_B_PINS { GP13 }
#define ENCODER_A_PINS_RIGHT { GP14 }
#define ENCODER_B_PINS_RIGHT { GP13 }
#endif

#ifdef AUDIO_ENABLE
    #define AUDIO_VOICES
    #define AUDIO_PIN GP12
    #define AUDIO_PWM_DRIVER PWMD6
    #define AUDIO_PWM_CHANNEL RP2040_PWM_CHANNEL_A
    #define AUDIO_ENABLE_TONE_MULTIPLEXING
    #define AUDIO_TONE_MULTIPLEXING_RATE_DEFAULT 10
    #define FP_AUDIO_MOUSE_BUTTONS
    #define FP_AUDIO_CUT_COPY_PASTE
    #define FP_AUDIO_SAVE
    #define FP_STARTUP_DARK  HALF_DOT_NOTE(_B5), QUARTER_NOTE(_B5), HALF_NOTE(_E6), HALF_NOTE(_REST), QUARTER_NOTE(_C6), QUARTER_NOTE(_REST), QUARTER_NOTE(_G5), QUARTER_NOTE(_E5), QUARTER_NOTE(_F5), QUARTER_NOTE(_GS5), QUARTER_NOTE(_G5), QUARTER_NOTE(_F5), WHOLE_NOTE(_G5),
    #define STARTUP_SONG SONG(FP_STARTUP_DARK)
    #define DEFAULT_LAYER_SONGS \
        { SONG(QWERTY_SOUND), SONG(COLEMAK_SOUND) }
#endif

#ifdef CIRQUE_ENABLE
    #define POINTING_DEVICE_ROTATION_90
    #define POINTING_DEVICE_LEFT
#endif

#ifdef VIK_TRACKBALL_ENABLE
    #define POINTING_DEVICE_LEFT
#endif

#include "keyboards/fingerpunch/src/config_post.h"
