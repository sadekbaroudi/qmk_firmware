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

#pragma once
#include QMK_KEYBOARD_H
#include "keyboards/fingerpunch/src/fp.h"

uint8_t fp_get_cpi_value_from_mode(uint8_t mode_index);
#ifndef POINTING_DEVICE_COMBINED
void fp_set_cpi(uint8_t value);
void fp_set_cpi_by_mode(uint8_t mode_index);
#else
void fp_set_cpi_combined(uint8_t left_value, uint8_t right_value);
void fp_set_cpi_combined_by_mode(uint8_t left_mode_index, uint8_t right_mode_index);
#endif
#ifdef FP_SLOW_SCROLL
report_mouse_t fp_apply_slow_scrolling(report_mouse_t mouse_report);
#endif
void fp_point_dpi_update(uint8_t action);
void fp_scroll_dpi_update(uint8_t action);
void fp_snipe_dpi_update(uint8_t action);
void fp_apply_dpi_defaults(void);
void fp_apply_dpi(void);
void fp_scroll_layer_set(bool scroll_value);
bool fp_scroll_layer_get(void);
void fp_scroll_keycode_toggle(void);
void fp_scroll_keycode_set(bool scroll_value);
bool fp_scroll_keycode_get(void);
void fp_snipe_layer_set(bool snipe_value);
bool fp_snipe_layer_get(void);
void fp_snipe_keycode_toggle(void);
void fp_snipe_keycode_set(bool snipe_value);
bool fp_snipe_keycode_get(void);
void fp_zoom_layer_set(bool zoom_value);
bool fp_zoom_layer_get(void);
void fp_zoom_keycode_toggle(void);
void fp_zoom_keycode_set(bool zoom_value);
bool fp_zoom_keycode_get(void);
uint32_t fp_zoom_unset_hold(uint32_t triger_time, void *cb_arg);
layer_state_t fp_layer_state_set_pointing(layer_state_t state);
bool fp_process_record_pointing(uint16_t keycode, keyrecord_t *record);

// indexes for modes
#define FP_POINTING_MODE 0
#define FP_SCROLLING_MODE 1
#define FP_SNIPING_MODE 2
#define FP_ZOOMING_MODE 3

// indexes for DPI adjustments, used by dpi update functions
#define FP_DPI_UP 1
#define FP_DPI_DOWN 2
#define FP_DPI_RESET 3
#define FP_POINTING_DPI_MULTIPLIER 100

#ifdef POINTING_DEVICE_ENABLE
// Add MOUSE_EXTENDED_REPORT by default
#    ifndef FP_POINTING_EXTENDED_MOUSE_REPORT_DISABLE
#        define MOUSE_EXTENDED_REPORT
#    endif

#    ifndef FP_POINTING_DEFAULT_DPI
#        define FP_POINTING_DEFAULT_DPI 10
#    endif

#    ifndef FP_POINTING_MIN_DPI
#        define FP_POINTING_MIN_DPI 2
#    endif

#    ifndef FP_POINTING_MAX_DPI
#        define FP_POINTING_MAX_DPI 60
#    endif

#    ifndef FP_POINTING_SNIPING_DPI
#        define FP_POINTING_SNIPING_DPI 2
#    endif

#    ifndef FP_POINTING_SNIPING_LAYER
#        define FP_POINTING_SNIPING_LAYER 2
#    endif

#    ifndef FP_POINTING_SNIPING_MIN_DPI
#        define FP_POINTING_SNIPING_MIN_DPI 2
#    endif

#    ifndef FP_POINTING_SNIPING_MAX_DPI
#        define FP_POINTING_SNIPING_MAX_DPI 5
#    endif

#    ifndef FP_POINTING_SCROLLING_DPI
#        define FP_POINTING_SCROLLING_DPI 2
#    endif

#    ifndef FP_POINTING_SCROLLING_LAYER
#        define FP_POINTING_SCROLLING_LAYER 3
#    endif

#    ifndef FP_POINTING_SCROLLING_MIN_DPI
#        define FP_POINTING_SCROLLING_MIN_DPI 2
#    endif

#    ifndef FP_POINTING_SCROLLING_MAX_DPI
#        define FP_POINTING_SCROLLING_MAX_DPI 10
#    endif

#    ifndef FP_AUTO_MOUSE_TRACKBALL_SENSITIVITY
#        define FP_AUTO_MOUSE_TRACKBALL_SENSITIVITY 3
#    endif

#    ifndef FP_POINTING_ZOOMING_LAYER
#        define FP_POINTING_ZOOMING_LAYER 1
#    endif

#    ifndef FP_SLOW_SCROLL
#        define FP_SLOW_SCROLL_DENOMINATOR 10.0
#    endif
#endif

#ifdef POINTING_DEVICE_COMBINED
#    ifndef FP_POINTING_COMBINED_SCROLLING_LEFT
#        define FP_POINTING_COMBINED_SCROLLING_LEFT true
#    endif

#    ifndef FP_POINTING_COMBINED_SCROLLING_RIGHT
#        define FP_POINTING_COMBINED_SCROLLING_RIGHT false
#    endif

#    ifndef FP_POINTING_COMBINED_SNIPING_LEFT
#        define FP_POINTING_COMBINED_SNIPING_LEFT false
#    endif

#    ifndef FP_POINTING_COMBINED_SNIPING_RIGHT
#        define FP_POINTING_COMBINED_SNIPING_RIGHT false
#    endif
#endif
