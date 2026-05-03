
#ifdef ENCODER_ENABLE

#include "keyboards/fingerpunch/src/fp_encoder.h"

#ifdef POINTING_DEVICE_ENABLE
#include "keyboards/fingerpunch/src/fp_pointing.h"
#endif

// Default action for unmapped layers
typedef enum {
    FP_ENC_DEFAULT_VOLUME,
    FP_ENC_DEFAULT_SUPER_CTRL_TAB,
} fp_enc_default_t;

// Convenience macro to expand all layer mappings for a given encoder index
#define FP_ENCODER_LAYERS(n) \
    FP_ENC_##n##_LAYER_PGUP_PGDN, FP_ENC_##n##_LAYER_ZOOM, \
    FP_ENC_##n##_LAYER_DPI_POINTING, FP_ENC_##n##_LAYER_SUPER_TAB, \
    FP_ENC_##n##_LAYER_SUPER_CTRL_TAB, FP_ENC_##n##_LAYER_SCROLL_WHEEL, \
    FP_ENC_##n##_LAYER_VOLUME, FP_ENC_##n##_LAYER_RGB_MODE, \
    FP_ENC_##n##_LAYER_RGB_HUE, FP_ENC_##n##_LAYER_RGB_SAT, \
    FP_ENC_##n##_LAYER_RGB_VAL

// Shared encoder action handler. 'cw' should already be adjusted for reverse direction.
static void fp_encoder_action(bool cw, fp_enc_default_t default_action,
                               uint8_t layer_pgup, uint8_t layer_zoom, uint8_t layer_dpi,
                               uint8_t layer_super_tab, uint8_t layer_super_ctrl_tab,
                               uint8_t layer_scroll, uint8_t layer_volume,
                               uint8_t layer_rgb_mode, uint8_t layer_rgb_hue,
                               uint8_t layer_rgb_sat, uint8_t layer_rgb_val) {
    uint8_t current_layer = get_highest_layer(layer_state);

    if (current_layer == layer_pgup) {
        tap_code(cw ? KC_PGDN : KC_PGUP);
    } else if (current_layer == layer_zoom) {
        tap_code16(cw ? C(S(KC_EQL)) : C(KC_MINS));
#ifdef POINTING_DEVICE_ENABLE
    } else if (current_layer == layer_dpi) {
        fp_point_dpi_update(cw ? FP_DPI_DOWN : FP_DPI_UP);
#endif
    } else if (current_layer == layer_super_tab) {
        press_super_tab(!cw);
    } else if (current_layer == layer_super_ctrl_tab) {
        press_super_ctrl_tab(!cw);
    } else if (current_layer == layer_scroll) {
        tap_code16(cw ? MS_WHLD : MS_WHLU);
    } else if (current_layer == layer_volume) {
        tap_code(cw ? KC_VOLU : KC_VOLD);
#if defined(RGBLIGHT_ENABLE) || defined(RGB_MATRIX_ENABLE)
    } else if (current_layer == layer_rgb_mode) {
        cw ? fp_rgblight_step() : fp_rgblight_step_reverse();
    } else if (current_layer == layer_rgb_hue) {
        cw ? fp_rgblight_increase_hue() : fp_rgblight_decrease_hue();
    } else if (current_layer == layer_rgb_sat) {
        cw ? fp_rgblight_increase_sat() : fp_rgblight_decrease_sat();
    } else if (current_layer == layer_rgb_val) {
        cw ? fp_rgblight_increase_val() : fp_rgblight_decrease_val();
#endif
    } else {
        // Default action for unmapped layers
        if (default_action == FP_ENC_DEFAULT_VOLUME) {
            tap_code(cw ? KC_VOLU : KC_VOLD);
        } else {
            press_super_ctrl_tab(!cw);
        }
    }
}

bool encoder_update_kb(uint8_t index, bool clockwise) {
    if (!encoder_update_user(index, clockwise)) {
      return false;
    }

    if (index == 0) {
        #ifdef ENCODERS_A_REVERSE
        bool cw = !clockwise;
        #else
        bool cw = clockwise;
        #endif
        fp_encoder_action(cw, FP_ENC_DEFAULT_VOLUME, FP_ENCODER_LAYERS(0));
    } else if (index == 1) {
        #ifdef ENCODERS_B_REVERSE
        bool cw = !clockwise;
        #else
        bool cw = clockwise;
        #endif
        fp_encoder_action(cw, FP_ENC_DEFAULT_SUPER_CTRL_TAB, FP_ENCODER_LAYERS(1));
    } else if (index == 2) {
        #ifdef ENCODERS_B_REVERSE
        tap_code16(clockwise ? MS_WHLU : MS_WHLD);
        #else
        tap_code16(clockwise ? MS_WHLD : MS_WHLU);
        #endif
    }

    return true;
}

layer_state_t fp_layer_state_set_encoder(layer_state_t state) {
    switch (get_highest_layer(state)) {
        default:
            break;
    }
    return state;
}

bool fp_process_record_encoder(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
#       ifndef FP_DISABLE_CUSTOM_KEYCODES
        // NOTE TO SELF: IF I EVER ADD KEYCODES HERE, DETERMINE WHETHER THEY ARE CONSIDERED CUSTOM KEYCODES OR NOT
#       endif // FP_DISABLE_CUSTOM_KEYCODES
        default:
            break;
    }

    return true;
}

#endif