// Copyright 2022 Manna Harbour
// https://github.com/manna-harbour/miryoku

// This program is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation, either version 2 of the License, or (at your option) any later version. This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details. You should have received a copy of the GNU General Public License along with this program. If not, see <http://www.gnu.org/licenses/>.

#include QMK_KEYBOARD_H
#include "users/manna-harbour_miryoku/manna-harbour_miryoku.h"
#ifdef ENCODER_ENABLE
bool encoder_update_user(uint8_t index, bool clockwise) {
    // default behavior if undefined
    if (index == 0) {
        // Conditional to reverse the direction of encoder number 1
        // The reason I have this is that for some of my boards, it supports two different types of encoders, and they may differ in direction
        #ifdef ENCODERS_A_REVERSE
        if (!clockwise) {
        #else
        if (clockwise) {
        #endif
            switch (get_highest_layer(layer_state)) {
                default:
                    tap_code(KC_VOLU);
            }
        } else {
            switch (get_highest_layer(layer_state)) {
                default:
                    tap_code(KC_VOLD);
            }
        }
    }
    else if (index == 1) {
      // Conditional to reverse the direction of encoder number 1
      // The reason I have this is that for some of my boards, it supports two different types of encoders, and they may differ in direction
      #ifdef ENCODERS_B_REVERSE
      if (!clockwise) {
      #else
      if (clockwise) {
      #endif
        switch (get_highest_layer(layer_state)) {
            case NAV:
                tap_code(KC_RGHT);
                break;
            default:
                tap_code(KC_WH_D);
        }
      } else {
        switch (get_highest_layer(layer_state)) {
            case NAV:
                tap_code(KC_LEFT);
                break;
            default:
                tap_code(KC_WH_U);
        }
      }
    }

    return true;
}
#endif

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (record->event.pressed) {
	switch (keycode) {
	    case KC_COLN:
		if ((get_mods() & MOD_MASK_SHIFT)) {
		    uint8_t mods = get_mods();
		    clear_mods();
		    register_code(KC_SCLN);
		    set_mods(mods);
		    return false;
		} else {
		    return true;
		}
	    default:
		return true;
	}
    }
    return true;
}

bool get_hold_on_other_key_press(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case LCTL_T(KC_ESC):
	case KC_LSPO:
	case KC_RSPC:
            // Immediately select the hold action when another key is tapped.
            return true;
        default:
            // Do not select the hold action when another key is tapped.
            return false;
    }
}
