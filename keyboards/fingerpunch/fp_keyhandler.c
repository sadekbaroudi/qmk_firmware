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

#include "keyboards/fingerpunch/fp_keyhandler.h"

bool process_record_kb(uint16_t keycode, keyrecord_t *record) {
    // If console is enabled, it will print the matrix position and status of each key pressed
#ifdef KEYLOGGER_ENABLE
    uprintf("KL: kc: 0x%04X, col: %2u, row: %2u, pressed: %1d, time: %5u, int: %1d, count: %u\n", keycode, record->event.key.col, record->event.key.row, record->event.pressed, record->event.time, record->tap.interrupted, record->tap.count);
#endif // KEYLOGGER_ENABLE

    if (!(process_record_user(keycode, record)
#if    defined(RGBLIGHT_ENABLE) || defined(RGB_MATRIX_ENABLE)
          && fp_process_record_rgb_common(keycode, record)
#endif
#ifdef RGBLIGHT_ENABLE
          && fp_process_record_rgblight(keycode, record)
#endif
#ifdef RGB_MATRIX_ENABLE
          && fp_process_record_rgb_matrix(keycode, record)
#endif
#ifdef FP_UNICODE_ENABLE
          && fp_process_record_unicode(keycode, record)
#endif
#ifdef HAPTIC_ENABLE
          && fp_process_record_haptic(keycode, record)
#endif
#if defined(POINTING_DEVICE_ENABLE)
          && fp_process_record_pointing(keycode, record)
#endif
          && true)) {
        return false;
    }
    switch (keycode) {
#ifndef FP_DISABLE_CUSTOM_KEYCODES
        case KC_CAPS_LOCK:
            if (record->event.pressed) {
                fp_caps_lock_toggle();
            }
            break;
        case FP_SUPER_TAB:
            if (record->event.pressed) {
                if (get_mods() & MOD_MASK_SHIFT) {
                    press_super_tab(true);
                } else {
                    press_super_tab(false);
                }
            }
            break;
#endif
        default:
            break;
    }

    return true;
}
