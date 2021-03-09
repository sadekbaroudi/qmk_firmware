/*
This is the c configuration file for the keymap

Copyright 2012 Jun Wako <wakojun@gmail.com>
Copyright 2015 Jack Humbert

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

//#define USE_MATRIX_I2C

/* Select hand configuration */

#define MASTER_LEFT
// #define MASTER_RIGHT
// #define EE_HANDS

#define USE_SERIAL_PD2

// OLED disabled, remove this line when re-enabling.
// Seeing latency from slave side, so removing this to fix, per
// https://www.reddit.com/r/olkb/comments/g5h7jo/slave_side_of_split_keyboard_sends_keystrokes/
#undef SSD1306OLED

#ifdef RGBLIGHT_ENABLE
    #undef RGBLED_NUM
    #define RGBLED_NUM 27
    //#define RGBLED_SPLIT { 27, 27 }
    #define RGBLIGHT_LIMIT_VAL 120
    #define RGBLIGHT_LAYERS
    //#define RGBLIGHT_SPLIT
#endif

#define OLED_FONT_H "keyboards/crkbd/lib/glcdfont.c"

