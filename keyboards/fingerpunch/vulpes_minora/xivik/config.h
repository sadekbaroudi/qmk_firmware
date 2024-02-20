/*
Copyright 2023 Sadek Baroudi <sadekbaroudi@gmail.com>

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
#ifdef FP_XIVIK_V01
    #define MATRIX_ROW_PINS { GP1, GP24, GP9, GP8 }
    #define MATRIX_COL_PINS { GP2, GP3, GP4, GP5, GP6 }
#else
    #define MATRIX_ROW_PINS { GP1, GP23, GP20, GP22 }
    #define MATRIX_COL_PINS { GP2, GP3, GP5, GP6, GP4 }
#endif

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
#else
    #define VIK_I2C_SDA_PIN   GP8
    #define VIK_I2C_SCL_PIN   GP9
#endif
#define VIK_GPIO_1        GP18
#define VIK_GPIO_2        GP10
#define VIK_WS2812_DI_PIN GP16

// Used only if you have a weact st7735 display, set to unused pin
#define VIK_ST7735_UNUSED_PIN GP11

// Split config
#define SERIAL_PIO_USE_PIO1
#ifdef FP_XIVIK_V01
    #define SERIAL_USART_TX_PIN GP7
#else
    // USART TX pin
    #define SERIAL_USART_TX_PIN GP21
#endif

#define WS2812_DI_PIN GP0

#ifdef ENCODER_ENABLE
    // In case there is a VIK module that has an encode
    #define ENCODERS_PAD_A { GP18 }
    #define ENCODERS_PAD_B { GP10 }
#endif

#ifdef CIRQUE_ENABLE
    #define POINTING_DEVICE_ROTATION_90
    #define POINTING_DEVICE_LEFT
#endif

#ifdef VIK_TRACKBALL_ENABLE
    #define POINTING_DEVICE_LEFT
#endif

#ifdef VIK_PEACOCK
    #define POINTING_DEVICE_LEFT
#endif

#include "keyboards/fingerpunch/src/config_post.h"