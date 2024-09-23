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

#include "keyboards/fingerpunch/src/fp_haptic.h"
#include "keyboards/fingerpunch/src/fp_os_detection.h"

#ifdef HAPTIC_ENABLE

#include "drivers/haptic/drv2605l.h"

layer_state_t fp_layer_state_set_haptic(layer_state_t state) {
    switch (get_highest_layer(state)) {
        default:
            break;
    }
    return state;
}

bool fp_process_record_haptic(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
#       ifndef FP_DISABLE_CUSTOM_KEYCODES
        // NOTE TO SELF: IF I EVER ADD KEYCODES HERE, DETERMINE WHETHER THEY ARE CONSIDERED CUSTOM KEYCODES OR NOT
        // In the case of the mouse buttons and ctrl-x,c,v,s features below, they are treated independently, so they aren't effected by FP_DISABLE_CUSTOM_KEYCODES
#       endif // FP_DISABLE_CUSTOM_KEYCODES
#       ifdef FP_HAPTIC_MOUSE_BUTTONS
        case KC_BTN1:
            if (record->event.pressed) {
                drv2605l_pulse(DRV2605L_EFFECT_MEDIUM_CLICK_1_100);
            }
            break;
        case KC_BTN2:
            if (record->event.pressed) {
                drv2605l_pulse(DRV2605L_EFFECT_SHORT_DOUBLE_CLICK_STRONG_1_100);
            }
            break;
        case KC_BTN3:
            if (record->event.pressed) {
                drv2605l_pulse(DRV2605L_EFFECT_MEDIUM_CLICK_1_100);
            }
            break;
#       endif
#       ifdef FP_HAPTIC_CUT_COPY_PASTE
        case KC_C: // copy
            if (record->event.pressed) {
                if ((((get_mods() & MOD_MASK_GUI) || (get_oneshot_mods() & MOD_MASK_GUI)) && !is_mac) ||
                (((get_mods() & MOD_MASK_CTRL) || (get_oneshot_mods() & MOD_MASK_CTRL)) && !is_mac)) {
                    drv2605l_pulse(DRV2605L_EFFECT_LONG_DOUBLE_SHARP_CLICK_STRONG_1_100);
                }
            }
            break;
        case KC_X: // cut
            if (record->event.pressed) {
                if ((((get_mods() & MOD_MASK_GUI) || (get_oneshot_mods() & MOD_MASK_GUI)) && is_mac) || (((get_mods() & MOD_MASK_CTRL) || (get_oneshot_mods() & MOD_MASK_CTRL)) && !is_mac)) {
                    drv2605l_pulse(DRV2605L_EFFECT_LONG_DOUBLE_SHARP_CLICK_STRONG_1_100);
                }
            }
            break;
        case KC_V: // paste
            if (record->event.pressed) {
                if ((((get_mods() & MOD_MASK_GUI) || (get_oneshot_mods() & MOD_MASK_GUI)) && is_mac) ||
                (((get_mods() & MOD_MASK_CTRL) || (get_oneshot_mods() & MOD_MASK_CTRL)) && !is_mac)) {
                    drv2605l_pulse(DRV2605L_EFFECT_SOFT_BUMP_100);
                }
            }
            break;
#       endif
#       ifdef FP_HAPTIC_SAVE
        case KC_S: // save
        case LALT_T(KC_S): // for my keymap, since I use homerow mods
            if (record->event.pressed) {
                if ((((get_mods() & MOD_MASK_GUI) || (get_oneshot_mods() & MOD_MASK_GUI)) && is_mac) ||
                (((get_mods() & MOD_MASK_CTRL) || (get_oneshot_mods() & MOD_MASK_CTRL)) && !is_mac)) {
                    drv2605l_pulse(DRV2605L_EFFECT_SOFT_BUMP_100);
                }
            }
            break;
#endif
        default:
            break;
            }

    return true;
}

__attribute__((weak)) bool get_haptic_enabled_key_user(uint16_t keycode, keyrecord_t *record) { return false; }

// manually handle haptic, see https://github.com/sadekbaroudi/qmk_firmware/blob/master/keyboards/fingerpunch/README.md#get-haptic-enabled-key-override
bool get_haptic_enabled_key(uint16_t keycode, keyrecord_t *record) {
    bool returnValue = false;

    // Note to self: Be careful when setting anything to true in this switch statement, as it cannot be overridden in the
    // get_haptic_enabled_key_user call, since it's an ||
    switch (keycode) {
        default:
            returnValue = false;
            break;
    }

    return (returnValue || get_haptic_enabled_key_user(keycode, record));
}
#endif
