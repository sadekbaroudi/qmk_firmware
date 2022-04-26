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

#define DEVICE_VER      0x0002

/* encoder config */
#define ENCODERS_PAD_A {C7, F0}
#define ENCODERS_PAD_B {F1, F1}
#define ENCODER_RESOLUTION 2

// cirque trackpad config
#define CIRQUE_PINNACLE_ADDR 0x2A
// If using fingerpunch case
// #define POINTING_DEVICE_ROTATION_270
// If using chewiedies case
#define POINTING_DEVICE_ROTATION_90


// #define CIRQUE_PINNACLE_TAPPING_TERM 150
// #define CIRQUE_PINNACLE_TOUCH_DEBOUNCE 100
// #define CIRQUE_PINNACLE_X_LOWER 200
// #define CIRQUE_PINNACLE_X_UPPER 1919
// #define CIRQUE_PINNACLE_Y_LOWER 200
// #define CIRQUE_PINNACLE_Y_UPPER 1471

// Known issue with the cirque and AVR, jumpy mouse movements...
// message from sillyworld 01/31/2022 stating that these improved usability for AVR based MCUs on the cirque
// https://discord.com/channels/440868230475677696/867530303261114398/937731130440970260
//#define F_SCL 100000UL
//#define POINTING_DEVICE_TASK_THROTTLE_MS 5

// Sadek note: tried the above for the cirque fix, and no dice