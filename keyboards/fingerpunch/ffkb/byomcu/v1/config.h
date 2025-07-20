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

#include "keyboards/fingerpunch/src/config_post.h"
