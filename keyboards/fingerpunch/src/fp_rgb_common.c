/* Copyright 2022 Sadek Baroudi
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

#include "keyboards/fingerpunch/src/fp_rgb_common.h"

// We must make sure that fp_rgb_matrix.h or fp_rgblight.h are included before this, since it depends on FP_LAYER_LIGHTING_MODE
#ifdef RGBLIGHT_ENABLE
#include "keyboards/fingerpunch/src/fp_rgblight.h"
#endif

#ifdef RGB_MATRIX_ENABLE
#include "keyboards/fingerpunch/src/fp_rgb_matrix.h"
#endif

#if defined(RGBLIGHT_ENABLE) || defined(RGB_MATRIX_ENABLE)

#if !defined(FP_STARTUP_ANIMATION_DISABLE)
static bool    is_enabled;
static bool    is_rgb_startup;
static HSV     old_hsv;
static uint8_t old_mode;
deferred_token rgb_startup_token;

uint32_t fp_rgb_startup_animation(uint32_t triger_time, void *cb_arg) {
    if (is_rgb_startup && is_keyboard_master()) {
        static uint8_t counter = 0;
        counter++;
        rgblight_sethsv_noeeprom((counter + old_hsv.h) % 255, 255, 255);
        if (counter >= 255) {
            is_rgb_startup = false;
            fp_rgb_set_hsv_and_mode(old_hsv.h, old_hsv.s, old_hsv.v, old_mode);
            if (!is_enabled) {
                rgblight_disable_noeeprom();
            }
        }
    }
    return is_rgb_startup ? 10 : 0;
}
#endif

void fp_post_init_rgb_common(void) {
#if !defined(FP_STARTUP_ANIMATION_DISABLE)
    is_enabled = rgblight_is_enabled();
    old_hsv  = rgblight_get_hsv();
    old_mode = rgblight_get_mode();
#if defined(RGBLIGHT_ENABLE)
    rgblight_mode_noeeprom(RGBLIGHT_MODE_STATIC_LIGHT);
#endif
#if defined(RGB_MATRIX_ENABLE)
    rgb_matrix_mode_noeeprom(RGB_MATRIX_SOLID_COLOR);
#endif
    is_rgb_startup = true;
    rgb_startup_token   = defer_exec(300, fp_rgb_startup_animation, NULL);
#endif
}

layer_state_t fp_layer_state_set_rgb(layer_state_t state) {
    switch (get_highest_layer(state)) {
#       if defined(FP_LAYER_LIGHTING_AUTO_MOUSE_ENABLE) && defined(AUTO_MOUSE_DEFAULT_LAYER) && defined(FP_LAYER_LIGHTING_DISABLE)
        case AUTO_MOUSE_DEFAULT_LAYER:
            fp_rgb_set_hsv_and_mode(FP_LAYER_LIGHTING_AUTO_MOUSE_HUE, FP_LAYER_LIGHTING_AUTO_MOUSE_MODE);
            break;
#       endif
        case 0:
#           ifndef FP_LAYER_LIGHTING_DISABLE
            if (fp_caps_lock_get()) {
                fp_rgb_set_hsv_and_mode(FP_LAYER_LIGHTING_CAPS_LOCK_HUE, FP_LAYER_LIGHTING_CAPS_LOCK_MODE);
                xprintf("caps lock /n");
            } else {
#           ifdef FP_LAYER_LIGHTING_DYNAMIC_BASE_LAYER_DISABLE
                fp_rgb_set_hsv_and_mode(FP_LAYER_LIGHTING_HUE_0, FP_LAYER_LIGHTING_MODE_0);
#           else
                fp_rgb_set_hsv_and_mode(fp_config.rgb_hue, fp_config.rgb_sat, fp_config.rgb_val, fp_config.rgb_mode);
#           endif
                xprintf("base layer /n");
            }
#           endif
            break;
        case 1:
#           ifndef FP_LAYER_LIGHTING_DISABLE
            fp_rgb_set_hsv_and_mode(FP_LAYER_LIGHTING_HUE_1, FP_LAYER_LIGHTING_MODE_1);
#           endif
            xprintf("layer 1: hue: {%d, %d, %d}, mode: %d\n", FP_LAYER_LIGHTING_HUE_1, FP_LAYER_LIGHTING_MODE_1);
            break;
        case 2:
#           ifndef FP_LAYER_LIGHTING_DISABLE
            fp_rgb_set_hsv_and_mode(FP_LAYER_LIGHTING_HUE_2, FP_LAYER_LIGHTING_MODE_2);
#           endif
            xprintf("layer 2: hue: {%d, %d, %d}, mode: %d\n", FP_LAYER_LIGHTING_HUE_2, FP_LAYER_LIGHTING_MODE_2);
            break;
        case 3:
#           ifndef FP_LAYER_LIGHTING_DISABLE
            fp_rgb_set_hsv_and_mode(FP_LAYER_LIGHTING_HUE_3, FP_LAYER_LIGHTING_MODE_3);
#           endif
            xprintf("layer 3: hue: {%d, %d, %d}, mode: %d\n", FP_LAYER_LIGHTING_HUE_3, FP_LAYER_LIGHTING_MODE_3);
            break;
        case 4:
#           ifndef FP_LAYER_LIGHTING_DISABLE
            fp_rgb_set_hsv_and_mode(FP_LAYER_LIGHTING_HUE_4, FP_LAYER_LIGHTING_MODE_4);
#           endif
            xprintf("layer 4: hue: {%d, %d, %d}, mode: %d\n", FP_LAYER_LIGHTING_HUE_4, FP_LAYER_LIGHTING_MODE_4);
            break;
        case 5:
#           ifndef FP_LAYER_LIGHTING_DISABLE
            fp_rgb_set_hsv_and_mode(FP_LAYER_LIGHTING_HUE_5, FP_LAYER_LIGHTING_MODE_5);
#           endif
            xprintf("layer 5: hue: {%d, %d, %d}, mode: %d\n", FP_LAYER_LIGHTING_HUE_5, FP_LAYER_LIGHTING_MODE_5);
            break;
        case 6:
#           ifndef FP_LAYER_LIGHTING_DISABLE
            fp_rgb_set_hsv_and_mode(FP_LAYER_LIGHTING_HUE_6, FP_LAYER_LIGHTING_MODE_6);
#           endif
            xprintf("layer 6: hue: {%d, %d, %d}, mode: %d\n", FP_LAYER_LIGHTING_HUE_6, FP_LAYER_LIGHTING_MODE_6);
            break;
        case 7:
#           ifndef FP_LAYER_LIGHTING_DISABLE
            fp_rgb_set_hsv_and_mode(FP_LAYER_LIGHTING_HUE_7, FP_LAYER_LIGHTING_MODE_7);
#           endif
            xprintf("layer 7: hue: {%d, %d, %d}, mode: %d\n", FP_LAYER_LIGHTING_HUE_7, FP_LAYER_LIGHTING_MODE_7);
            break;
        default:
            // default to layer 0 behavior
#           ifndef FP_LAYER_LIGHTING_DISABLE
            fp_rgb_set_hsv_and_mode(FP_LAYER_LIGHTING_HUE_0, FP_LAYER_LIGHTING_MODE_0);
#           endif
            xprintf("layer default: hue: {%d, %d, %d}, mode: %d\n", FP_LAYER_LIGHTING_HUE_0, FP_LAYER_LIGHTING_MODE_0);
            break;
    }
    return state;
}

void fp_rgb_set_config_from_current_values(void) {
    fp_config.rgb_mode = rgblight_get_mode();
    fp_config.rgb_hue = rgblight_get_hue();
    fp_config.rgb_sat = rgblight_get_sat();
    fp_config.rgb_val = rgblight_get_val();
    fp_config.rgb_speed = rgblight_get_speed();
    eeconfig_update_kb_datablock(&fp_config.raw, 0, EECONFIG_KB_DATA_SIZE);
    xprintf("RGB: mode: %u, hue: %u, sat: %u, val: %u, speed: %u\n", fp_config.rgb_mode, fp_config.rgb_hue, fp_config.rgb_sat, fp_config.rgb_val, fp_config.rgb_speed);
}

// Deferred exec function
uint32_t fp_rgb_set_config_from_current_values_deferred(uint32_t triger_time, void *cb_arg) {
    fp_rgb_set_config_from_current_values();
    return 0;
}

bool fp_process_record_rgb_common(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case RGB_MODE_FORWARD ... RGB_MODE_GRADIENT:  // quantum_keycodes.h L400 for definitions
            if (record->event.pressed) {
                fp_rgb_set_hsv_and_mode(fp_config.rgb_hue, fp_config.rgb_sat, fp_config.rgb_val, fp_config.rgb_mode);
            }
            if (!record->event.pressed) {
                // in fp_keyhandler.c, because process_record() gets called before fp_process_record_rgb_common, and because
                //     the rgb light change happens on the key release (!record->event.pressed), that means that this code gets called
                //     before the process_record key release
                // Sooooo, need a defered exec event to handle this
                defer_exec(20, fp_rgb_set_config_from_current_values_deferred, NULL);
            }
            break;
#   ifndef FP_DISABLE_CUSTOM_KEYCODES
#   endif // FP_DISABLE_CUSTOM_KEYCODES
        default:
            break;
    }

    return true;
}

// Returns hue, sat, or val, depending on the value of whichOne (0 for hue, 1 for sat, 2 for val)
uint8_t fp_rgb_get_element_from_hsv(uint8_t hue, uint8_t sat, uint8_t val, uint8_t whichOne) {
    switch (whichOne) {
        case 0:
            return hue;
            xprintf("fp_rgb_get_element_from_hsv: returning hue value: %d", hue);
            break;
        case 1:
            return sat;
            break;
        case 2:
            return val;
            break;
        default:
            break;
    }

    return 0;
}

void fp_rgblight_step(void) {
    fp_rgb_set_hsv_and_mode(fp_config.rgb_hue, fp_config.rgb_sat, fp_config.rgb_val, fp_config.rgb_mode);
    rgblight_step();
    defer_exec(20, fp_rgb_set_config_from_current_values_deferred, NULL);
}

void fp_rgblight_step_reverse(void) {
    fp_rgb_set_hsv_and_mode(fp_config.rgb_hue, fp_config.rgb_sat, fp_config.rgb_val, fp_config.rgb_mode);
    rgblight_step_reverse();
    defer_exec(20, fp_rgb_set_config_from_current_values_deferred, NULL);
}

void fp_rgblight_increase_hue(void) {
    fp_rgb_set_hsv_and_mode(fp_config.rgb_hue, fp_config.rgb_sat, fp_config.rgb_val, fp_config.rgb_mode);
    rgblight_increase_hue();
    defer_exec(20, fp_rgb_set_config_from_current_values_deferred, NULL);
}

void fp_rgblight_decrease_hue(void) {
    fp_rgb_set_hsv_and_mode(fp_config.rgb_hue, fp_config.rgb_sat, fp_config.rgb_val, fp_config.rgb_mode);
    rgblight_decrease_hue();
    defer_exec(20, fp_rgb_set_config_from_current_values_deferred, NULL);
}

void fp_rgblight_increase_sat(void) {
    fp_rgb_set_hsv_and_mode(fp_config.rgb_hue, fp_config.rgb_sat, fp_config.rgb_val, fp_config.rgb_mode);
    rgblight_increase_sat();
    defer_exec(20, fp_rgb_set_config_from_current_values_deferred, NULL);
}

void fp_rgblight_decrease_sat(void) {
    fp_rgb_set_hsv_and_mode(fp_config.rgb_hue, fp_config.rgb_sat, fp_config.rgb_val, fp_config.rgb_mode);
    rgblight_decrease_sat();
    defer_exec(20, fp_rgb_set_config_from_current_values_deferred, NULL);
}

void fp_rgblight_increase_val(void) {
    fp_rgb_set_hsv_and_mode(fp_config.rgb_hue, fp_config.rgb_sat, fp_config.rgb_val, fp_config.rgb_mode);
    rgblight_increase_val();
    defer_exec(20, fp_rgb_set_config_from_current_values_deferred, NULL);
}

void fp_rgblight_decrease_val(void) {
    fp_rgb_set_hsv_and_mode(fp_config.rgb_hue, fp_config.rgb_sat, fp_config.rgb_val, fp_config.rgb_mode);
    rgblight_decrease_val();
    defer_exec(20, fp_rgb_set_config_from_current_values_deferred, NULL);
}

#endif
