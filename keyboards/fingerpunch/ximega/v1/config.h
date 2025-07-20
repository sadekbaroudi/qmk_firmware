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

// wiring of each half
#define MATRIX_ROW_PINS { GP24, GP7, GP4, GP5 }
#define MATRIX_COL_PINS { GP10, GP11, GP6, GP12, GP13, GP14, GP15, GP16 }

// VIK pin config
#define VIK_SPI_DRIVER    SPID0
#define VIK_SPI_SCK_PIN   GP22
#define VIK_SPI_MOSI_PIN  GP23
#define VIK_SPI_MISO_PIN  GP20
#define VIK_SPI_CS        GP9
#define VIK_I2C_DRIVER    I2CD1
#define VIK_I2C_SDA_PIN   GP2
#define VIK_I2C_SCL_PIN   GP3
#define VIK_GPIO_1        GP26
#define VIK_GPIO_2        GP27
#define VIK_WS2812_DI_PIN GP25

// VIK2 config (not supported for now, need to add support for 2 VIK connectors)
#define VIK2_SPI_DRIVER    SPID0
#define VIK2_SPI_SCK_PIN   GP22
#define VIK2_SPI_MOSI_PIN  GP23
#define VIK2_SPI_MISO_PIN  GP20
#define VIK2_SPI_CS        GP21
#define VIK2_I2C_DRIVER    I2CD1
#define VIK2_I2C_SDA_PIN   GP2
#define VIK2_I2C_SCL_PIN   GP3
#define VIK2_GPIO_1        GP28
#define VIK2_GPIO_2        GP29
#define VIK2_WS2812_DI_PIN GP8

// Used only if you have a display with RESET unconnected, set to unused pin
#define VIK_DISPLAY_RST_UNUSED_PIN GP17

// Encoder configuration from VIK
#ifdef VIK_EC11_EVQWGD001
    #define ENCODER_A_PINS { GP26 }
    #define ENCODER_B_PINS { GP27 }
    #define ENCODER_RESOLUTIONS { 2 }
#elif defined(VIK_PER56_CIRQUE_LEDS) || defined(VIK_PER56_PMW3360_LEDS)
    #define ENCODER_A_PINS { GP26 }
    #define ENCODER_B_PINS { GP27 }
    #define ENCODER_RESOLUTIONS { 1 }
#else
    #define ENCODER_A_PINS { }
    #define ENCODER_B_PINS { }
    #define ENCODER_RESOLUTIONS { }
#endif

#ifdef VIK_EC11_EVQWGD001_RIGHT
    #define ENCODER_A_PINS_RIGHT { GP26 }
    #define ENCODER_B_PINS_RIGHT { GP27 }
    #define ENCODER_RESOLUTIONS_RIGHT { 2 }
#elif defined(VIK_PER56_CIRQUE_LEDS_RIGHT) || defined(VIK_PER56_PMW3360_LEDS_RIGHT)
    #define ENCODER_A_PINS_RIGHT { GP26 }
    #define ENCODER_B_PINS_RIGHT { GP27 }
    #define ENCODER_RESOLUTIONS_RIGHT { 1 }
#else
    #define ENCODER_A_PINS_RIGHT { }
    #define ENCODER_B_PINS_RIGHT { }
    #define ENCODER_RESOLUTIONS_RIGHT { }
#endif

#include "keyboards/fingerpunch/src/config_post.h"
