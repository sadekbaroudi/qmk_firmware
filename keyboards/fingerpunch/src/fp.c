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

#include "keyboards/fingerpunch/src/fp.h"
#include "eeconfig.h"
#include "keyboards/fingerpunch/src/fp_os_detection.h"

fp_config_t fp_config;

#if defined(RGBLIGHT_ENABLE) || defined(RGB_MATRIX_ENABLE)
#include "keyboards/fingerpunch/src/fp_rgb_common.h"
#endif
#if defined(POINTING_DEVICE_ENABLE)
#include "keyboards/fingerpunch/src/fp_pointing.h"
#endif
#if defined(QUANTUM_PAINTER_ENABLE)
#include "keyboards/fingerpunch/src/display/fp_display.h"
#endif
#if defined(PIMORONI_TRACKBALL_ENABLE)
#include "color.h"
#endif

#ifndef FP_SUPER_TAB_TIMEOUT
#   define FP_SUPER_TAB_TIMEOUT 500
#endif
#ifndef FP_SUPER_CTRL_TAB_TIMEOUT
#   define FP_SUPER_CTRL_TAB_TIMEOUT 750
#endif

bool is_caps_lock_on = false;
bool is_super_tab_active = false;
bool is_super_ctrl_tab_active = false;
// Note that super tab and super control tab share the same timer! Shouldn't matter, but in case there are issues, note this.
uint16_t super_tab_timer = 0;

bool fp_caps_lock_get(void) {
    return is_caps_lock_on;
}

void fp_caps_lock_toggle(void) {
    is_caps_lock_on = !is_caps_lock_on;
    handle_caps_lock_change();
}

void handle_caps_lock_change(void) {
#if defined(RGBLIGHT_ENABLE) || defined(RGB_MATRIX_ENABLE) // We only do this because we want the layer color to change
    fp_layer_state_set_rgb(layer_state);
#endif  // RGBLIGHT_ENABLE
}

void press_super_tab(bool shift) {
    if (shift) {
        register_code(KC_LSFT);
    } else {
        unregister_code(KC_LSFT);
    }
    if (!is_super_tab_active) {
        is_super_tab_active = true;

    is_mac ? register_code(KC_LGUI) : register_code(KC_LALT);
    }

    super_tab_timer = timer_read();
    tap_code(KC_TAB);
}

void unregister_super_tab(void) {
    if (is_super_tab_active) {
        if (timer_elapsed(super_tab_timer) > FP_SUPER_TAB_TIMEOUT) {
        is_mac ? unregister_code(KC_LGUI) : unregister_code(KC_LALT);
        is_super_tab_active = false;

            if (get_mods() & MOD_MASK_SHIFT) {
                unregister_code(KC_LSFT);
            }
        }
    }
}

void press_super_ctrl_tab(bool shift) {
    if (shift) {
        register_code(KC_LSFT);
    } else {
        unregister_code(KC_LSFT);
    }
    if (!is_super_ctrl_tab_active) {
        is_super_ctrl_tab_active = true;
        register_code(KC_LCTL);
    }

    super_tab_timer = timer_read();
    tap_code(KC_TAB);
}

void unregister_super_ctrl_tab(void) {
    if (is_super_ctrl_tab_active) {
        if (timer_elapsed(super_tab_timer) > FP_SUPER_CTRL_TAB_TIMEOUT) {
            unregister_code(KC_LCTL);
            is_super_ctrl_tab_active = false;

            if (get_mods() & MOD_MASK_SHIFT) {
                unregister_code(KC_LSFT);
            }
        }
    }
}

void matrix_scan_kb(void) {
    // We do this in matrix scan in case there are two keyboards connected and we
    // need to make sure this keyboard is aware
    led_t led_state = host_keyboard_led_state();
    if (led_state.caps_lock != is_caps_lock_on) {
        fp_caps_lock_toggle();
    }

    unregister_super_tab();
    unregister_super_ctrl_tab();

    matrix_scan_user();
}

void keyboard_pre_init_kb(void) {
    eeconfig_read_kb_datablock(&fp_config.raw);
    keyboard_pre_init_user();
}

void keyboard_post_init_kb(void) {
    #ifdef CONSOLE_ENABLE
    fp_log_eeprom();
    #endif

    #if defined(PIMORONI_TRACKBALL_ENABLE) && !defined(RGBLIGHT_ENABLE)
    pimoroni_trackball_set_rgbw(RGB_BLUE, 0x00);
    #endif

    #if defined(POINTING_DEVICE_ENABLE)
    fp_apply_dpi();
    #endif

    #if defined(RGBLIGHT_ENABLE) || defined(RGB_MATRIX_ENABLE)
    fp_post_init_rgb_common();
    #endif

    #if defined(RGBLIGHT_ENABLE)
    fp_post_init_rgblight();
    #endif

    #if defined(RGB_MATRIX_ENABLE)
    fp_post_init_rgb_matrix();
    #endif

    #if defined(QUANTUM_PAINTER_ENABLE)
    fp_post_init_qp();
    #endif

    keyboard_post_init_user();
}

layer_state_t layer_state_set_kb(layer_state_t state) {
#if defined(RGBLIGHT_ENABLE) || defined(RGB_MATRIX_ENABLE)
    state = fp_layer_state_set_rgb(state);
#endif
#ifdef RGBLIGHT_ENABLE
    state = fp_layer_state_set_rgblight(state);
#endif  // RGBLIGHT_ENABLE
#ifdef RGB_MATRIX_ENABLE
    state = fp_layer_state_set_rgb_matrix(state);
#endif  // RGB_MATRIX_ENABLE
#ifdef ENCODER_ENABLE
    state = fp_layer_state_set_encoder(state);
#endif  // ENCODER_ENABLE
#ifdef HAPTIC_ENABLE
    state = fp_layer_state_set_haptic(state);
#endif  // HAPTIC_ENABLE
#ifdef AUDIO_ENABLE
    state = fp_layer_state_set_audio(state);
#endif  // AUDIO_ENABLE
#ifdef POINTING_DEVICE_ENABLE
    state = fp_layer_state_set_pointing(state);
#endif  // POINTING_DEVICE_ENABLE

    return layer_state_set_user(state);
}

void eeconfig_init_kb(void) {
    fp_config.raw              = 0;
    #if defined(RGBLIGHT_ENABLE) || defined(RGB_MATRIX_ENABLE)
    fp_config.rgb_mode         = FP_LAYER_LIGHTING_MODE_0;
    fp_config.rgb_hue          = fp_rgb_get_element_from_hsv(FP_LAYER_LIGHTING_HUE_0, 0);
    #endif
    fp_config.rgb_sat          = 255;
    fp_config.rgb_val          = 255;
    fp_config.rgb_speed        = 1;
    #ifdef POINTING_DEVICE_ENABLE
    fp_config.pointing_dpi = FP_POINTING_DEFAULT_DPI;
    fp_config.sniping_dpi = FP_POINTING_SNIPING_DPI;
    fp_config.scrolling_dpi = FP_POINTING_SCROLLING_DPI;
    #endif
    eeconfig_update_kb_datablock(&fp_config.raw);
    eeconfig_init_user();
}

#ifdef CONSOLE_ENABLE
void fp_log_eeprom() {
    xprintf("fp_log_eeprom\n");
    xprintf("fp_config.raw = '%llu'\n", fp_config.raw);
    #if defined(RGBLIGHT_ENABLE) || defined(RGB_MATRIX_ENABLE)
    xprintf("fp_config.rgb_mode = '%u'\n", fp_config.rgb_mode);
    xprintf("fp_config.rgb_hue = '%u'\n", fp_config.rgb_hue);
    xprintf("fp_config.rgb_sat = '%u'\n", fp_config.rgb_sat);
    xprintf("fp_config.rgb_val = '%u'\n", fp_config.rgb_val);
    xprintf("fp_config.rgb_speed = '%u'\n", fp_config.rgb_speed);
    #endif
    #ifdef POINTING_DEVICE_ENABLE
    xprintf("fp_config.pointing_dpi = '%u'\n", fp_config.pointing_dpi);
    xprintf("fp_config.sniping_dpi = '%u'\n", fp_config.sniping_dpi);
    xprintf("fp_config.scrolling_dpi = '%u'\n", fp_config.scrolling_dpi);
    #endif
}
#endif
