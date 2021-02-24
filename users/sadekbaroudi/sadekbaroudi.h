/* Copyright 2020 Christopher Courtney, aka Drashna Jael're  (@drashna) <drashna@live.com>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#pragma once
#include QMK_KEYBOARD_H

#include "version.h"
#include "eeprom.h"
#include "wrappers.h"
#include "process_records.h"
#if defined(RGBLIGHT_ENABLE)
#    include "rgb_stuff.h"
#endif
#if defined(RGB_MATRIX_ENABLE)
#    include "rgb_matrix_stuff.h"
#endif

/* Define layer names */
enum userspace_layers {
    _COLEMAK  = 0,
    _QWERTY,
    _WORKMAN,
    _NAVIGATION,
    _SYMBOLS,
    _FUNCTION,
    _MEDIA,
    _MOUSE
};

void          matrix_init_keymap(void);
void          shutdown_keymap(void);
void          suspend_power_down_keymap(void);
void          suspend_wakeup_init_keymap(void);
void          matrix_scan_keymap(void);
layer_state_t layer_state_set_keymap(layer_state_t state);
layer_state_t default_layer_state_set_keymap(layer_state_t state);
void          led_set_keymap(uint8_t usb_led);
void          eeconfig_init_keymap(void);
bool          hasAllBitsInMask(uint8_t value, uint8_t mask);

// clang-format off
typedef union {
    uint32_t raw;
    struct {
        bool    rgb_layer_change        :1;
        bool    rgb_base_layer_override :1;
        bool    rgb_matrix_idle_anim    :1;
        uint8_t mode;                   //:default 1; RGBLIGHT_MODE_STATIC_LIGHT;
        uint8_t hue;                    //:0-255;
        uint8_t sat;                    //:0-255;
        uint8_t val;                    //:0-255;
        uint8_t speed;                  //:default 1;
    };
} userspace_config_t;
// clang-format on

extern userspace_config_t userspace_config;
extern bool is_caps_lock_on;
