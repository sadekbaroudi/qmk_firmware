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

// SHIFT REGISTER
// Only needed for matrix_74hc595_spi.c
#define SHIFTREG_MATRIX_COL_CS B6
#define SHIFTREG_DIVISOR 8 // needs to be the same as the PMW33XX_CS_DIVISOR below
#define MATRIX_ROW_PINS_SR { D2, F4, F5, F6, F7, D4 }

// SPI config for shift register (and trackball if enabled)
#define SPI_SCK_PIN B1
#define SPI_MOSI_PIN B2
#define SPI_MISO_PIN B3

#if defined(CONVERT_TO_ELITE_PI) || defined(CONVERT_TO_RP2040_CE) || defined(CONVERT_TO_HELIOS) || defined(CONVERT_TO_LIATRIS) || defined(CONVERT_TO_KB2040) || defined(CONVERT_TO_PROMICRO_RP2040)
#define SPI_DRIVER SPID0
#endif // CONVERT_TO_(any_rp2040)

#ifdef CONVERT_TO_STEMCELL
#define SPI_DRIVER SPID1
#define SPI_SCK_PAL_MODE 5
#define SPI_MOSI_PAL_MODE 5
#define SPI_MISO_PAL_MODE 5
#endif

/* COL2ROW, ROW2COL*/
#define DIODE_DIRECTION COL2ROW

#define ENCODER_A_PINS {C6, E6}
#define ENCODER_B_PINS {D7, B4}


#ifdef FP_EVQ
#define ENCODERS_A_REVERSE
#define ENCODERS_B_REVERSE
#endif

#ifdef FP_EC11
#define ENCODERS_C_REVERSE
#endif

#define ENCODER_RESOLUTION 2

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
