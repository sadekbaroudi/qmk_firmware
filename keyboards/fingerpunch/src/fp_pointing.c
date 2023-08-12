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

#include "keyboards/fingerpunch/src/fp_pointing.h"
#include "keyboards/fingerpunch/src/fp_keyhandler.h"
#include "math.h"
// is_keyboard_master()

#ifdef POINTING_DEVICE_ENABLE

#ifdef FP_POINTING_ACCELERATION_ENABLE
static bool acceleration_enabled = true;
#endif
static bool scrolling_keycode_enabled = false;
static bool scrolling_layer_enabled = false;
static bool sniping_keycode_enabled = false;
static bool sniping_layer_enabled = false;
static bool zooming_keycode_enabled = false;
static bool zooming_layer_enabled = false;
static bool zooming_hold = false;

#ifdef POINTING_DEVICE_COMBINED
void fp_compile_check_combined_default_modes(void) {
    // assert that either both LEFT values are false or only one of them is true
    static_assert( ((FP_POINTING_COMBINED_SCROLLING_LEFT || FP_POINTING_COMBINED_SNIPING_LEFT) && (FP_POINTING_COMBINED_SCROLLING_LEFT != FP_POINTING_COMBINED_SNIPING_LEFT)) || (!FP_POINTING_COMBINED_SCROLLING_LEFT && !FP_POINTING_COMBINED_SNIPING_LEFT), "Cannot specify both FP_POINTING_COMBINED_SCROLLING_LEFT and FP_POINTING_COMBINED_SNIPING_LEFT");
    // assert that either both RIGHT values are false or only one of them is true
    static_assert( ((FP_POINTING_COMBINED_SCROLLING_RIGHT || FP_POINTING_COMBINED_SNIPING_RIGHT) && (FP_POINTING_COMBINED_SCROLLING_RIGHT != FP_POINTING_COMBINED_SNIPING_RIGHT)) || (!FP_POINTING_COMBINED_SCROLLING_RIGHT && !FP_POINTING_COMBINED_SNIPING_RIGHT), "Cannot specify both FP_POINTING_COMBINED_SCROLLING_RIGHT and FP_POINTING_COMBINED_SNIPING_RIGHT");
}
#endif

uint8_t fp_get_cpi_value_from_mode(uint8_t mode_index) {
    switch (mode_index) {
        case FP_POINTING_MODE:
            return fp_config.pointing_dpi;
        case FP_SCROLLING_MODE:
            return fp_config.scrolling_dpi;
        case FP_SNIPING_MODE:
            return fp_config.sniping_dpi;
        default:
            xprintf("fp_get_cpi_value_from_mode: invalid mode, this should never happen");
            return 10;
    }

    return 10;
}

#ifndef POINTING_DEVICE_COMBINED
void fp_set_cpi(uint8_t value) {
    pointing_device_set_cpi((uint16_t)value * FP_POINTING_DPI_MULTIPLIER);
    xprintf("fp_set_cpi: setting value to: %d\n", ((uint16_t)value * FP_POINTING_DPI_MULTIPLIER));
}

void fp_set_cpi_by_mode(uint8_t mode_index) {
    fp_set_cpi(fp_get_cpi_value_from_mode(mode_index));
}
#endif

#ifdef POINTING_DEVICE_COMBINED
void fp_set_cpi_combined(uint8_t left_value, uint8_t right_value) {
    pointing_device_set_cpi_on_side(true, (uint16_t)left_value * FP_POINTING_DPI_MULTIPLIER);
    pointing_device_set_cpi_on_side(false, (uint16_t)right_value * FP_POINTING_DPI_MULTIPLIER);
}

void fp_set_cpi_combined_by_mode(uint8_t left_mode_index, uint8_t right_mode_index) {
    fp_set_cpi_combined((uint16_t)fp_get_cpi_value_from_mode(left_mode_index), (uint16_t)fp_get_cpi_value_from_mode(right_mode_index));
}
#endif

void fp_point_dpi_update(uint8_t action) {
    xprintf("Pointing DPI update, action %u, before value: %u\n", action, fp_config.pointing_dpi);
    switch (action) {
        case FP_DPI_UP:
            if (fp_config.pointing_dpi >= FP_POINTING_MAX_DPI) {
                fp_config.pointing_dpi = FP_POINTING_MAX_DPI;
            } else {
                fp_config.pointing_dpi += 1;
            }
            break;
        case FP_DPI_DOWN:
            if (fp_config.pointing_dpi <= FP_POINTING_MIN_DPI) {
                fp_config.pointing_dpi = FP_POINTING_MIN_DPI;
            } else {
                fp_config.pointing_dpi -= 1;
            }
            break;
        case FP_DPI_RESET:
            fp_config.pointing_dpi = FP_POINTING_DEFAULT_DPI;
            break;
        default:
            break;
    }

    eeconfig_update_kb_datablock(&fp_config.raw);
    #ifdef CONSOLE_ENABLE
    fp_log_eeprom();
    #endif
    fp_apply_dpi();
    xprintf("Pointing DPI update, action %u, after value: %u\n", action, fp_config.pointing_dpi);
}

void fp_scroll_dpi_update(uint8_t action) {
    xprintf("Scrolling DPI update, action %u, before value: %u\n", action, fp_config.scrolling_dpi);
    switch (action) {
        case FP_DPI_UP:
            if (fp_config.scrolling_dpi >= FP_POINTING_SCROLLING_MAX_DPI) {
                fp_config.scrolling_dpi = FP_POINTING_SCROLLING_MAX_DPI;
            } else {
                fp_config.scrolling_dpi += 1;
            }
            break;
        case FP_DPI_DOWN:
            if (fp_config.scrolling_dpi <= FP_POINTING_SCROLLING_MIN_DPI) {
                fp_config.scrolling_dpi = FP_POINTING_SCROLLING_MIN_DPI;
            } else {
                fp_config.scrolling_dpi -= 1;
            }
            break;
        case FP_DPI_RESET:
            fp_config.scrolling_dpi = FP_POINTING_SCROLLING_DPI;
            break;
        default:
            break;
    }

    eeconfig_update_kb_datablock(&fp_config.raw);
    fp_apply_dpi();
    xprintf("Scrolling DPI update, action %u, after value: %u\n", action, fp_config.scrolling_dpi);
}

void fp_snipe_dpi_update(uint8_t action) {
    xprintf("Sniping DPI update, action %u, before value: %u\n", action, fp_config.sniping_dpi);
    switch (action) {
        case FP_DPI_UP:
            if (fp_config.sniping_dpi >= FP_POINTING_SNIPING_MAX_DPI) {
                fp_config.sniping_dpi = FP_POINTING_SNIPING_MAX_DPI;
            } else {
                fp_config.sniping_dpi += 1;
            }
            break;
        case FP_DPI_DOWN:
            if (fp_config.sniping_dpi <= FP_POINTING_SNIPING_MIN_DPI) {
                fp_config.sniping_dpi = FP_POINTING_SNIPING_MIN_DPI;
            } else {
                fp_config.sniping_dpi -= 1;
            }
            break;
        case FP_DPI_RESET:
            fp_config.sniping_dpi = FP_POINTING_SNIPING_DPI;
            break;
        default:
            break;
    }

    eeconfig_update_kb_datablock(&fp_config.raw);
    fp_apply_dpi();
    xprintf("Sniping DPI update, action %u, after value: %u\n", action, fp_config.sniping_dpi);
}

void fp_apply_dpi_defaults(void) {
#ifdef POINTING_DEVICE_COMBINED
    uint8_t left_mode = FP_POINTING_MODE;
    uint8_t right_mode = FP_POINTING_MODE;

    if (FP_POINTING_COMBINED_SCROLLING_LEFT) {
        left_mode = FP_SCROLLING_MODE;
    }
    if (FP_POINTING_COMBINED_SNIPING_LEFT) {
        left_mode = FP_SNIPING_MODE;
    }

    if (FP_POINTING_COMBINED_SCROLLING_RIGHT) {
        right_mode = FP_SCROLLING_MODE;
    }
    if (FP_POINTING_COMBINED_SNIPING_RIGHT) {
        right_mode = FP_SNIPING_MODE;
    }

    fp_set_cpi_combined_by_mode(left_mode, right_mode);
#else
    fp_set_cpi_by_mode(FP_POINTING_MODE);
#endif
}

void fp_apply_dpi(void) {
    // sniping dpi always wins, since the intent of it is to be moving slowly in sniping mode
    if(fp_snipe_layer_get() || fp_snipe_keycode_get()) {
#ifdef POINTING_DEVICE_COMBINED
        fp_set_cpi_combined_by_mode(FP_SNIPING_MODE, FP_SNIPING_MODE);
#else
        fp_set_cpi_by_mode(FP_SNIPING_MODE);
#endif
    } else if (fp_scroll_layer_get() || fp_scroll_keycode_get()) {
#ifdef POINTING_DEVICE_COMBINED
        fp_set_cpi_combined_by_mode(FP_SCROLLING_MODE, FP_SCROLLING_MODE);
#else
        fp_set_cpi_by_mode(FP_SCROLLING_MODE);
#endif
    } else {
        // if not sniping or scrolling, set to default values
        fp_apply_dpi_defaults();
    }
}

void fp_scroll_layer_set(bool scroll_value) {
    scrolling_layer_enabled = scroll_value;
    fp_apply_dpi();
}

bool fp_scroll_layer_get(void) {
    return scrolling_layer_enabled;
}

void fp_scroll_keycode_toggle(void) {
    scrolling_keycode_enabled = !scrolling_keycode_enabled;
    fp_apply_dpi();
}

void fp_scroll_keycode_set(bool scroll_value) {
    scrolling_keycode_enabled = scroll_value;
    fp_apply_dpi();
}

bool fp_scroll_keycode_get(void) {
    return scrolling_keycode_enabled;
}

void fp_snipe_layer_set(bool snipe_value) {
    sniping_layer_enabled = snipe_value;
    fp_apply_dpi();
}

bool fp_snipe_layer_get(void) {
    return sniping_layer_enabled;
}

void fp_snipe_keycode_toggle(void) {
    sniping_keycode_enabled = !sniping_keycode_enabled;
    fp_apply_dpi();
}

void fp_snipe_keycode_set(bool snipe_value) {
    sniping_keycode_enabled = snipe_value;
    fp_apply_dpi();
}

bool fp_snipe_keycode_get(void) {
    return sniping_keycode_enabled;
}

void fp_zoom_layer_set(bool zoom_value) {
    zooming_layer_enabled = zoom_value;
}

bool fp_zoom_layer_get(void) {
    return zooming_layer_enabled;
}

void fp_zoom_keycode_toggle(void) {
    zooming_keycode_enabled = !zooming_keycode_enabled;
}

void fp_zoom_keycode_set(bool zoom_value) {
    zooming_keycode_enabled = zoom_value;
}

bool fp_zoom_keycode_get(void) {
    return zooming_keycode_enabled;
}

uint32_t fp_zoom_unset_hold(uint32_t triger_time, void *cb_arg) {
    zooming_hold = false;
    return 0;
}

#ifdef FP_SLOW_SCROLLING
// Variables to store accumulated scroll values
float scroll_accumulated_h = 0;
float scroll_accumulated_v = 0;

// Function to handle mouse reports and perform drag scrolling from:
// https://docs.qmk.fm/#/feature_pointing_device?id=advanced-drag-scroll
report_mouse_t apply_slow_scrolling(report_mouse_t mouse_report) {
    if (set_scrolling) {
        // Calculate and accumulate scroll values based on mouse movement and divisors
        scroll_accumulated_h += (float)mouse_report.x / FP_SCROLL_DIVISOR_H;
        scroll_accumulated_v += (float)mouse_report.y / FP_SCROLL_DIVISOR_V;

        // Assign integer parts of accumulated scroll values to the mouse report
        mouse_report.h = (int8_t)scroll_accumulated_h;
        mouse_report.v = -(int8_t)scroll_accumulated_v;

        // Update accumulated scroll values by subtracting the integer parts
        scroll_accumulated_h -= (int8_t)scroll_accumulated_h;
        scroll_accumulated_v -= (int8_t)scroll_accumulated_v;

        // Clear the X and Y values of the mouse report
        mouse_report.x = 0;
        mouse_report.y = 0;
    }
    return mouse_report;
}
#endif

// set the scroll moment key as a mouse key so that it holds the auto mouse layer active
bool is_mouse_record_kb(uint16_t keycode, keyrecord_t* record) {
    switch(keycode) {
        case FP_SCROLL_MOMENT:
            return true;
    }
    return false;
}

report_mouse_t pointing_device_task_kb(report_mouse_t mouse_report) {
#ifdef CONSOLE_ENABLE
    if (mouse_report.x != 0) {
        xprintf("fingerpunch mouse report x: %d\n", mouse_report.x);
    }
    if (mouse_report.y != 0) {
        xprintf("fingerpunch mouse report y: %d\n", mouse_report.y);
    }
#endif
    if (fp_scroll_layer_get() || fp_scroll_keycode_get()) {
#ifdef FP_SLOW_SCROLLING
        mouse_report = apply_slow_scrolling(mouse_report);
#else
        mouse_report.h = mouse_report.x;
        mouse_report.v = -mouse_report.y;
        mouse_report.x = 0;
        mouse_report.y = 0;
#endif
    } else if (fp_zoom_layer_get() || fp_zoom_keycode_get()) {
        bool zoom_in = false;
        mouse_xy_report_t zoom_value = mouse_report.y;
        if (zoom_value < 0) {
            zoom_in = true;
            zoom_value = -zoom_value;
        }

        // Set timer to prevent mass zoom and set threshold for zoom value, otherwise too sensitive
        if (!zooming_hold && zoom_value > 1) {
#ifdef FP_MAC_PREFERRED
            register_code(KC_LGUI);
#else
            register_code(KC_LCTL);
#endif
            zooming_hold = true;
            defer_exec(50, fp_zoom_unset_hold, NULL);
            if (zoom_in) {
                register_code(KC_LSFT);
                tap_code(KC_EQUAL);
                unregister_code(KC_LSFT);
            } else {
                tap_code(KC_MINUS);
            }
#ifdef FP_MAC_PREFERRED
            unregister_code(KC_LGUI);
#else
            unregister_code(KC_LCTL);
#endif
        }

        mouse_report.h = 0;
        mouse_report.v = 0;
        mouse_report.x = 0;
        mouse_report.y = 0;

    }
#ifdef FP_POINTING_ACCELERATION_ENABLE
    // Don't run acceleration unless you're in regular mousing mode, and acceleration is explicitly enabled
    if (!fp_scroll_layer_get() && !fp_scroll_keycode_get() && !fp_snipe_layer_get() && !fp_snipe_keycode_get() && !fp_zoom_layer_get() && !fp_zoom_keycode_get() && acceleration_enabled) {
        mouse_xy_report_t x = mouse_report.x, y = mouse_report.y;
        mouse_report.x = 0;
        mouse_report.y = 0;

        x = (mouse_xy_report_t)(x > 0 ? x * x / 16 + x : -x * x / 16 + x);
        y = (mouse_xy_report_t)(y > 0 ? y * y / 16 + y : -y * y / 16 + y);

        mouse_report.x = x;
        mouse_report.y = y;
    }
#endif
    mouse_report = pointing_device_task_user(mouse_report);
    return mouse_report;
}

#ifdef POINTING_DEVICE_COMBINED
report_mouse_t pointing_device_task_combined_kb(report_mouse_t left_report, report_mouse_t right_report) {
    // if we have any modes activated, we should process each report first
    if (fp_scroll_layer_get() || fp_scroll_keycode_get() || fp_zoom_layer_get() || fp_zoom_keycode_get()) {
        left_report = pointing_device_task_kb(left_report);
        right_report = pointing_device_task_kb(right_report);
    } else {
        if (FP_POINTING_COMBINED_SCROLLING_LEFT) {
#ifdef FP_SLOW_SCROLLING
            left_report = apply_slow_scrolling(left_report);
#else
            left_report.h = left_report.x;
            left_report.v = -left_report.y;
            left_report.x = 0;
            left_report.y = 0;
#endif
        }

        if (FP_POINTING_COMBINED_SCROLLING_RIGHT) {
#ifdef FP_SLOW_SCROLLING
            right_report = apply_slow_scrolling(right_report);
#else
            right_report.h = right_report.x;
            right_report.v = -right_report.y;
            right_report.x = 0;
            right_report.y = 0;
#endif
        }
    }

    return pointing_device_task_combined_user(left_report, right_report);
}
#endif

layer_state_t fp_layer_state_set_pointing(layer_state_t state) {
    switch (get_highest_layer(state)) {
#ifdef FP_POINTING_SCROLLING_LAYER_ENABLE
        case FP_POINTING_SCROLLING_LAYER:
            fp_scroll_layer_set(true);
            break;
#endif
#ifdef FP_POINTING_SNIPING_LAYER_ENABLE
        case FP_POINTING_SNIPING_LAYER:
            fp_snipe_layer_set(true);
            break;
#endif
#ifdef FP_POINTING_ZOOMING_LAYER_ENABLE
        case FP_POINTING_ZOOMING_LAYER:
            fp_zoom_layer_set(true);
            break;
#endif
        default:
#ifdef POINTING_DEVICE_AUTO_MOUSE_ENABLE
            // If we hit one of the FP_POINTING_X_LAYERS, and then trigger auto mouse layer, we don't want to
            // disable the scroll/snipe adjustments because we used the pointing device
            // Problem happens when POINTING_DEVICE_AUTO_MOUSE_ENABLE and FP_POINTING_X_LAYER_ENABLE
            // are enabled at the samet time
            if (get_highest_layer(state) == AUTO_MOUSE_DEFAULT_LAYER) {
                break;
            }
#endif
#ifdef FP_POINTING_SCROLLING_LAYER_ENABLE
            if (fp_scroll_layer_get()) {
                fp_scroll_layer_set(false);
            }
#endif
#ifdef FP_POINTING_SNIPING_LAYER_ENABLE
            if (fp_snipe_layer_get()) {
                fp_snipe_layer_set(false);
            }
#endif
#ifdef FP_POINTING_ZOOMING_LAYER_ENABLE
            if (fp_zoom_layer_get()) {
                fp_zoom_layer_set(false);
            }
#endif
            break;
    }
    return state;
}

void pointing_device_init_kb(void) {
#   ifdef POINTING_DEVICE_AUTO_MOUSE_ENABLE
    set_auto_mouse_enable(true);         // always required before the auto mouse feature will work
#   endif

    pointing_device_init_user();
}

#ifdef FP_TRACKBALL_ENABLE
// Override when using a trackball so that you can account for accidental triggers due to a sensitive sensor
bool auto_mouse_activation(report_mouse_t mouse_report) {
    // If we're in sniping mode, lower the threshold, otherwise give it some room to move for accidental triggers of auto mouse layer
    if (fp_snipe_layer_get() || fp_snipe_keycode_get()) {
        return fabs(mouse_report.x) >= 0.5 || fabs(mouse_report.y) >= 0.5 || fabs(mouse_report.h) >= 0.5 || fabs(mouse_report.v) >= 0.5 || mouse_report.buttons;
    } else {
        return fabs(mouse_report.x) >= FP_AUTO_MOUSE_TRACKBALL_SENSITIVITY ||
               fabs(mouse_report.y) >= FP_AUTO_MOUSE_TRACKBALL_SENSITIVITY ||
               fabs(mouse_report.h) >= FP_AUTO_MOUSE_TRACKBALL_SENSITIVITY ||
               fabs(mouse_report.v) >= FP_AUTO_MOUSE_TRACKBALL_SENSITIVITY ||
               mouse_report.buttons;
    }
}
#endif

bool fp_process_record_pointing(uint16_t keycode, keyrecord_t *record) {
#   ifndef FP_DISABLE_CUSTOM_KEYCODES
    switch (keycode) {
        case FP_ACCEL_TOG:
#       ifdef FP_POINTING_ACCELERATION_ENABLE
            acceleration_enabled = !acceleration_enabled;
#       endif
            break;
        case FP_SCROLL_MOMENT:
            if (record->event.pressed) {
                fp_scroll_keycode_set(true);
            } else {
                fp_scroll_keycode_set(false);
            }
            break;
        case FP_SCROLL_TOG:
            if (record->event.pressed) {
                fp_scroll_keycode_toggle();
            }
            break;
        case FP_SCROLL_ON:
            if (record->event.pressed) {
                fp_scroll_keycode_set(true);
            }
            break;
        case FP_SCROLL_OFF:
            if (record->event.pressed) {
                fp_scroll_keycode_set(false);
            }
            break;
        case FP_SNIPE_MOMENT:
            if (record->event.pressed) {
                fp_snipe_keycode_set(true);
            } else {
                fp_snipe_keycode_set(false);
            }
            break;
        case FP_SNIPE_TOG:
            if (record->event.pressed) {
                fp_snipe_keycode_toggle();
            }
            break;
        case FP_SNIPE_ON:
            if (record->event.pressed) {
                fp_snipe_keycode_set(true);
            }
            break;
        case FP_SNIPE_OFF:
            if (record->event.pressed) {
                fp_snipe_keycode_set(false);
            }
            break;
        case FP_ZOOM_MOMENT:
            if (record->event.pressed) {
                fp_zoom_keycode_set(true);
            } else {
                fp_zoom_keycode_set(false);
            }
            break;
        case FP_ZOOM_TOG:
            if (record->event.pressed) {
                fp_zoom_keycode_toggle();
            }
            break;
        case FP_ZOOM_ON:
            if (record->event.pressed) {
                fp_zoom_keycode_set(true);
            }
            break;
        case FP_ZOOM_OFF:
            if (record->event.pressed) {
                fp_zoom_keycode_set(false);
            }
            break;
        case FP_POINT_DPI_UP:
            if (record->event.pressed) {
                fp_point_dpi_update(FP_DPI_UP);
            }
            break;
        case FP_POINT_DPI_DN:
            if (record->event.pressed) {
                fp_point_dpi_update(FP_DPI_DOWN);
            }
            break;
        case FP_POINT_DPI_RESET:
            if (record->event.pressed) {
                fp_point_dpi_update(FP_DPI_RESET);
            }
            break;
        case FP_SCROLL_DPI_UP:
            if (record->event.pressed) {
                fp_scroll_dpi_update(FP_DPI_UP);
            }
            break;
        case FP_SCROLL_DPI_DN:
            if (record->event.pressed) {
                fp_scroll_dpi_update(FP_DPI_DOWN);
            }
            break;
        case FP_SCROLL_DPI_RESET:
            if (record->event.pressed) {
                fp_scroll_dpi_update(FP_DPI_RESET);
            }
            break;
        case FP_SNIPE_DPI_UP:
            if (record->event.pressed) {
                fp_snipe_dpi_update(FP_DPI_UP);
            }
            break;
        case FP_SNIPE_DPI_DN:
            if (record->event.pressed) {
                fp_snipe_dpi_update(FP_DPI_DOWN);
            }
            break;
        case FP_SNIPE_DPI_RESET:
            if (record->event.pressed) {
                fp_snipe_dpi_update(FP_DPI_RESET);
            }
            break;
        default:
            break;
    }
#   endif // FP_DISABLE_CUSTOM_KEYCODES

    return true;
}

#endif
