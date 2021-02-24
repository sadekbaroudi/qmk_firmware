#include "sadekbaroudi.h"

userspace_config_t userspace_config;
bool is_caps_lock_on;

__attribute__((weak)) void keyboard_pre_init_keymap(void) {}

void keyboard_pre_init_user(void) {
    userspace_config.raw = eeconfig_read_user();
    keyboard_pre_init_keymap();
}
// Add reconfigurable functions here, for keymap customization
// This allows for a global, userspace functions, and continued
// customization of the keymap.  Use _keymap instead of _user
// functions in the keymaps
__attribute__((weak)) void matrix_init_keymap(void) {}

// Call user matrix init, set default RGB colors and then
// call the keymap's init function
void matrix_init_user(void) {
    matrix_init_keymap();
}

__attribute__((weak)) void keyboard_post_init_keymap(void) {}

void keyboard_post_init_user(void) {
    is_caps_lock_on = false;
#if defined(RGBLIGHT_ENABLE)
    keyboard_post_init_rgb_light();
#endif
#if defined(RGB_MATRIX_ENABLE)
    keyboard_post_init_rgb_matrix();
#endif
    keyboard_post_init_keymap();
}

__attribute__((weak)) void shutdown_keymap(void) {}

void rgb_matrix_update_pwm_buffers(void);

void shutdown_user(void) {
#ifdef RGBLIGHT_ENABLE
    rgblight_enable_noeeprom();
    rgblight_mode_noeeprom(1);
    rgblight_setrgb_red();
#endif  // RGBLIGHT_ENABLE
#ifdef RGB_MATRIX_ENABLE
    rgb_matrix_set_color_all(0xFF, 0x00, 0x00);
    rgb_matrix_update_pwm_buffers();

#endif  // RGB_MATRIX_ENABLE
    shutdown_keymap();
}

__attribute__((weak)) void suspend_power_down_keymap(void) {}

void suspend_power_down_user(void) { suspend_power_down_keymap(); }

__attribute__((weak)) void suspend_wakeup_init_keymap(void) {}

void suspend_wakeup_init_user(void) { suspend_wakeup_init_keymap(); }

__attribute__((weak)) void matrix_scan_keymap(void) {}

// No global matrix scan code, so just run keymap's matrix
// scan function
void matrix_scan_user(void) {
    static bool has_ran_yet;
    if (!has_ran_yet) {
        has_ran_yet = true;
        startup_user();
    }


#if defined(RGBLIGHT_ENABLE)
    matrix_scan_rgb_light();
    led_t led_state = host_keyboard_led_state();
    if (led_state.caps_lock != is_caps_lock_on) {
        is_caps_lock_on = led_state.caps_lock;
        layer_state_set_user(layer_state);
    }
#endif  // RGBLIGHT_ENABLE
#if defined(RGB_MATRIX_ENABLE)
    matrix_scan_rgb_matrix();
#endif

    matrix_scan_keymap();
}

__attribute__((weak)) layer_state_t layer_state_set_keymap(layer_state_t state) { return state; }

// on layer change, no matter where the change was initiated
// Then runs keymap's layer change check
layer_state_t layer_state_set_user(layer_state_t state) {
    //state = update_tri_layer_state(state, _NAVIGATION, _SYMBOLS, _MEDIA);
#if defined(RGBLIGHT_ENABLE)
    state = layer_state_set_rgb_light(state);
#endif  // RGBLIGHT_ENABLE
    return layer_state_set_keymap(state);
}

__attribute__((weak)) layer_state_t default_layer_state_set_keymap(layer_state_t state) { return state; }

// Runs state check and changes underglow color and animation
layer_state_t default_layer_state_set_user(layer_state_t state) {
    state = default_layer_state_set_keymap(state);
#if 0
#    if defined(RGBLIGHT_ENABLE) || defined(RGB_MATRIX_ENABLE)
  state = default_layer_state_set_rgb(state);
#    endif  // RGBLIGHT_ENABLE
#endif
    return state;
}

__attribute__((weak)) void led_set_keymap(uint8_t usb_led) {}

// Any custom LED code goes here.
// So far, I only have keyboard specific code,
// So nothing goes here.
void led_set_user(uint8_t usb_led) { led_set_keymap(usb_led); }

__attribute__((weak)) void eeconfig_init_keymap(void) {}

void eeconfig_init_user(void) {
    userspace_config.raw              = 0;
    userspace_config.rgb_base_layer_override = false;
    userspace_config.rgb_layer_change = true;
    userspace_config.mode = RGBLIGHT_MODE_STATIC_LIGHT;
    userspace_config.hue = 169; // BLUE
    userspace_config.sat = 255;
    userspace_config.val = 255;
    userspace_config.speed = 1;
    eeconfig_update_user(userspace_config.raw);
    eeconfig_init_keymap();
    keyboard_init();
}

bool hasAllBitsInMask(uint8_t value, uint8_t mask) {
    value &= 0xF;
    mask &= 0xF;

    return (value & mask) == mask;
}
