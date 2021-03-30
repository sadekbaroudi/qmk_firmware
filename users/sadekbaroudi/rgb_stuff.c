#include "sadekbaroudi.h"
#include "rgb_stuff.h"
#include "eeprom.h"

bool    has_initialized;

void rgblight_sethsv_default_helper(uint8_t index) { rgblight_sethsv_at(rgblight_get_hue(), rgblight_get_sat(), rgblight_get_val(), index); }

bool process_record_user_rgb_light(uint16_t keycode, keyrecord_t *record) {
    uint16_t temp_keycode = keycode;
    // Filter out the actual keycode from MT and LT keys.
    if ((keycode >= QK_MOD_TAP && keycode <= QK_MOD_TAP_MAX) || (keycode >= QK_LAYER_TAP && keycode <= QK_LAYER_TAP_MAX)) {
        temp_keycode &= 0xFF;
    }

    switch (temp_keycode) {
    }
    return true;
}

#if defined(RGBLIGHT_STARTUP_ANIMATION)
static bool is_enabled;
static bool is_rgblight_startup;
static uint8_t old_hue;
static uint16_t rgblight_startup_loop_timer;
#endif

void keyboard_post_init_rgb_light(void) {
#if defined(RGBLIGHT_STARTUP_ANIMATION)
    is_enabled = rgblight_is_enabled();
    if (userspace_config.rgb_layer_change) {
        rgblight_enable_noeeprom();
    }
    if (rgblight_is_enabled()) {
        layer_state_set_rgb_light(layer_state);
        old_hue = rgblight_get_hue();
        rgblight_mode_noeeprom(RGBLIGHT_MODE_STATIC_LIGHT);
        is_rgblight_startup = true;
    }
#endif
    layer_state_set_rgb_light(layer_state);
}

void matrix_scan_rgb_light(void) {

#if defined(RGBLIGHT_STARTUP_ANIMATION)
    if (is_rgblight_startup && is_keyboard_master()) {
        if (timer_elapsed(rgblight_startup_loop_timer) > 10) {
            static uint8_t counter;
            counter++;
            rgblight_sethsv_noeeprom((counter + old_hue) % 255, 255, 255);
            rgblight_startup_loop_timer = timer_read();
            if (counter == 255) {
                is_rgblight_startup = false;
                if (!is_enabled) {
                    rgblight_disable_noeeprom();
                }
                if (userspace_config.rgb_layer_change) {
                    layer_state_set_rgb_light(layer_state);
                }
            }
        }
    }
#endif
}

void rgblight_set_hsv_and_mode(uint8_t hue, uint8_t sat, uint8_t val, uint8_t mode) {
    rgblight_mode_noeeprom(mode);
    rgblight_sethsv_noeeprom(hue, sat, val);
}

layer_state_t layer_state_set_rgb_light(layer_state_t state) {
#ifdef RGBLIGHT_ENABLE
    if (userspace_config.rgb_layer_change) {
        //uint8_t mode = layer_state_cmp(state,_MEDIA) ? RGBLIGHT_MODE_BREATHING : RGBLIGHT_MODE_STATIC_LIGHT;
        uint8_t mode = RGBLIGHT_MODE_STATIC_LIGHT;
        switch (get_highest_layer(state|default_layer_state)) {
            case _COLEMAK:
                if (is_caps_lock_on) { // If caps lock is enabled, force this setting
                    uint8_t caps_lock_rgb_hue = 0; // RED
                    uint8_t caps_lock_rgb_mode = mode;
                    #ifdef CAPS_LOCK_RGB_HUE
                    caps_lock_rgb_hue = CAPS_LOCK_RGB_HUE;
                    #endif
                    #ifdef CAPS_LOCK_RGB_MODE
                    caps_lock_rgb_mode = CAPS_LOCK_RGB_MODE;
                    #endif
                    rgblight_set_hsv_and_mode(caps_lock_rgb_hue, 255, 255, caps_lock_rgb_mode);
                } else if (userspace_config.rgb_base_layer_override) { // If the base layer override is enabled, use that
                    rgblight_set_hsv_and_mode(userspace_config.hue, userspace_config.sat, userspace_config.val, userspace_config.mode);
                } else { // if base layer override is disabled, always show the base setting
                    uint8_t base_layer_rgb_hue = 167; // BLUE
                    uint8_t base_layer_rgb_mode = mode;
                    #ifdef BASE_LAYER_RGB_HUE
                    base_layer_rgb_hue = BASE_LAYER_RGB_HUE;
                    #endif
                    #ifdef BASE_LAYER_RGB_MODE
                    base_layer_rgb_mode = BASE_LAYER_RGB_MODE;
                    #endif
                    rgblight_set_hsv_and_mode(base_layer_rgb_hue, 255, 255, base_layer_rgb_mode);
                }
                break;
            case _QWERTY:
                rgblight_set_hsv_and_mode(10, 10, 255, mode); // white
                break;
            case _WORKMAN:
                rgblight_set_hsv_and_mode(HSV_MAGENTA, mode);
                break;
            case _NAVIGATION:
                rgblight_set_hsv_and_mode(HSV_GREEN, mode);
                break;
            case _SYMBOLS:
                rgblight_set_hsv_and_mode(HSV_PURPLE, mode);
                break;
            case _FUNCTION:
                rgblight_set_hsv_and_mode(HSV_YELLOW, mode);
                break;
            case _MOUSE:
                rgblight_set_hsv_and_mode(HSV_CYAN, mode);
                break;
            case _MEDIA:
                rgblight_set_hsv_and_mode(16, 255, 255, mode); // orange
                break;
            case _WINNAV:
                rgblight_set_hsv_and_mode(10, 10, 255, mode); // near-white
                break;
            default:
                rgblight_set_hsv_and_mode(HSV_SPRINGGREEN, mode);
                break;
        }
    }
#endif  // RGBLIGHT_ENABLE

    return state;
}
