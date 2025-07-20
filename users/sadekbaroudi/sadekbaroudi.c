#include "sadekbaroudi.h"

userspace_config_t userspace_config;

// Leader key combos - TODO move into another file?
#if defined(LEADER_ENABLE)
LEADER_EXTERNS();

void matrix_scan_leader_key(void) {
  LEADER_DICTIONARY() {
    leading = false;
    leader_end();

    // Time shortcuts
    SEQ_TWO_KEYS(KC_H, KC_SLSH) {
      SEND_STRING("1:00");
    }
    SEQ_TWO_KEYS(KC_COMM, KC_SLSH) {
      SEND_STRING("2:00");
    }
    SEQ_TWO_KEYS(KC_DOT, KC_SLSH) {
      SEND_STRING("3:00");
    }
    SEQ_TWO_KEYS(KC_N, KC_SLSH) {
      SEND_STRING("4:00");
    }
    SEQ_TWO_KEYS(KC_E, KC_SLSH) {
      SEND_STRING("5:00");
    }
    SEQ_TWO_KEYS(KC_I, KC_SLSH) {
      SEND_STRING("6:00");
    }
    SEQ_TWO_KEYS(KC_L, KC_SLSH) {
      SEND_STRING("7:00");
    }
    SEQ_TWO_KEYS(KC_U, KC_SLSH) {
      SEND_STRING("8:00");
    }
    SEQ_TWO_KEYS(KC_Y, KC_SLSH) {
      SEND_STRING("9:00");
    }
    SEQ_THREE_KEYS(KC_H, KC_SLSH, KC_SLSH) {
      SEND_STRING("10:00");
    }
    SEQ_THREE_KEYS(KC_H, KC_H, KC_SLSH) {
      SEND_STRING("11:00");
    }
    SEQ_THREE_KEYS(KC_H, KC_COMM, KC_SLSH) {
      SEND_STRING("12:00");
    }
    SEQ_TWO_KEYS(KC_H, KC_DOT) {
      SEND_STRING("1:30");
    }
    SEQ_TWO_KEYS(KC_COMM, KC_DOT) {
      SEND_STRING("2:30");
    }
    SEQ_TWO_KEYS(KC_DOT, KC_DOT) {
      SEND_STRING("3:30");
    }
    SEQ_TWO_KEYS(KC_N, KC_DOT) {
      SEND_STRING("4:30");
    }
    SEQ_TWO_KEYS(KC_E, KC_DOT) {
      SEND_STRING("5:30");
    }
    SEQ_TWO_KEYS(KC_I, KC_DOT) {
      SEND_STRING("6:30");
    }
    SEQ_TWO_KEYS(KC_L, KC_DOT) {
      SEND_STRING("7:30");
    }
    SEQ_TWO_KEYS(KC_U, KC_DOT) {
      SEND_STRING("8:30");
    }
    SEQ_TWO_KEYS(KC_Y, KC_DOT) {
      SEND_STRING("9:30");
    }
    SEQ_THREE_KEYS(KC_H, KC_SLSH, KC_DOT) {
      SEND_STRING("10:30");
    }
    SEQ_THREE_KEYS(KC_H, KC_H, KC_DOT) {
      SEND_STRING("11:30");
    }
    SEQ_THREE_KEYS(KC_H, KC_COMM, KC_DOT) {
      SEND_STRING("12:30");
    }
  }
}
#endif

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
    keyboard_post_init_keymap();
}

__attribute__((weak)) void shutdown_keymap(void) {}

void rgb_matrix_update_pwm_buffers(void);

__attribute__((weak)) void suspend_power_down_keymap(void) {}

void suspend_power_down_user(void) { suspend_power_down_keymap(); }

__attribute__((weak)) void suspend_wakeup_init_keymap(void) {}

void suspend_wakeup_init_user(void) { suspend_wakeup_init_keymap(); }

__attribute__((weak)) void matrix_scan_keymap(void) {}

// No global matrix scan code, so just run keymap's matrix
// scan function
void matrix_scan_user(void) {
#if defined(LEADER_ENABLE)
    matrix_scan_leader_key();
#endif

    matrix_scan_keymap();
}

__attribute__((weak)) layer_state_t layer_state_set_keymap(layer_state_t state) { return state; }

// on layer change, no matter where the change was initiated
// Then runs keymap's layer change check
layer_state_t layer_state_set_user(layer_state_t state) {
    return layer_state_set_keymap(state);
}

__attribute__((weak)) layer_state_t default_layer_state_set_keymap(layer_state_t state) { return state; }

layer_state_t default_layer_state_set_user(layer_state_t state) {
    state = default_layer_state_set_keymap(state);
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
    eeconfig_update_user(userspace_config.raw);
    eeconfig_init_keymap();
    keyboard_init();
}

uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        // I always type the shift keys too fast, so tapping term of 200 is way too high
        case LSFT_T(KC_T):
        case RSFT_T(KC_N):
            return 150;
        default:
            return TAPPING_TERM;
    }
}


// This was added to deal with this issue:
// * https://www.reddit.com/r/olkb/comments/mwf5re/help_needed_controlling_individual_rgb_leds_on_a/
// * https://github.com/qmk/qmk_firmware/issues/12037
#ifdef SPLIT_KEYBOARD
void housekeeping_task_user(void) {
    static layer_state_t old_layer_state = 0;
    if (!is_keyboard_master() && old_layer_state != layer_state) {
        old_layer_state = layer_state;
        layer_state_set_user(layer_state);
    }
}
#endif
