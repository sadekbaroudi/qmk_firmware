
#ifdef ENCODER_ENABLE

#include "keyboards/fingerpunch/src/fp_encoder.h"

#ifdef POINTING_DEVICE_ENABLE
#include "keyboards/fingerpunch/src/fp_pointing.h"
#endif

bool encoder_update_kb(uint8_t index, bool clockwise) {
    if (!encoder_update_user(index, clockwise)) {
      return false; /* Don't process further events if user function exists and returns false */
    }
    // default behavior if undefined
    if (index == 0) {
        switch(biton32(layer_state)){
            case FP_ENC_0_LAYER_PGUP_PGDN: //_SYMBOLS:
                // Page up / page down
                if (clockwise) {
                    #ifdef ENCODERS_A_REVERSE
                    tap_code(KC_PGUP);
                    #else
                    tap_code(KC_PGDN);
                    #endif
                } else {
                    #ifdef ENCODERS_A_REVERSE
                    tap_code(KC_PGDN);
                    #else
                    tap_code(KC_PGUP);
                    #endif
                }
                break;
            case FP_ENC_0_LAYER_ZOOM: //_MEDIA:
                // zoom in and out
                if (clockwise) {
                    #ifdef ENCODERS_A_REVERSE
                    tap_code16(C(KC_MINS));
                    #else
                    tap_code16(C(S(KC_EQL)));
                    #endif
                } else {
                    #ifdef ENCODERS_A_REVERSE
                    tap_code16(C(S(KC_EQL)));
                    #else
                    tap_code16(C(KC_MINS));
                    #endif
                }
                break;
#ifdef POINTING_DEVICE_ENABLE
            case FP_ENC_0_LAYER_DPI_POINTING: //_NAVIGATION:
                // word select left and right
                if (clockwise) {
                    #ifdef ENCODERS_A_REVERSE
                    fp_point_dpi_update(FP_DPI_UP);
                    #else
                    fp_point_dpi_update(FP_DPI_DOWN);
                    #endif
                } else {
                    #ifdef ENCODERS_A_REVERSE
                    fp_point_dpi_update(FP_DPI_DOWN);
                    #else
                    fp_point_dpi_update(FP_DPI_UP);
                    #endif
                }
                break;
#endif
            case FP_ENC_0_LAYER_SUPER_TAB: //_FUNCTION:
                // super alt tab
                if (clockwise) {
                    #ifdef ENCODERS_A_REVERSE
                    press_super_tab(true);
                    #else
                    press_super_tab(false);
                    #endif
                } else {
                    #ifdef ENCODERS_A_REVERSE
                    press_super_tab(false);
                    #else
                    press_super_tab(true);
                    #endif
                }
                break;
            case FP_ENC_0_LAYER_SUPER_CTRL_TAB:
                // super ctrl tab
                // switch between browser windows, or files in vscode
                if (clockwise) {
                    #ifdef ENCODERS_A_REVERSE
                    press_super_ctrl_tab(true);
                    #else
                    press_super_ctrl_tab(false);
                    #endif
                } else {
                    #ifdef ENCODERS_A_REVERSE
                    press_super_ctrl_tab(false);
                    #else
                    press_super_ctrl_tab(true);
                    #endif
                }
                break;
            case FP_ENC_0_LAYER_SCROLL_WHEEL:
                // scroll wheel
                if (clockwise){
                    #ifdef ENCODERS_A_REVERSE
                    tap_code16(MS_WHLU);
                    #else
                    tap_code16(MS_WHLD);
                    #endif
                } else{
                    #ifdef ENCODERS_A_REVERSE
                    tap_code16(MS_WHLD);
                    #else
                    tap_code16(MS_WHLU);
                    #endif
                }
                break;
#if defined(RGBLIGHT_ENABLE) || defined(RGB_MATRIX_ENABLE)
            case FP_ENC_0_LAYER_RGB_MODE:
                // rgb mode step
                if (clockwise){
                    #ifdef ENCODERS_A_REVERSE
                    fp_rgblight_step_reverse();
                    #else
                    fp_rgblight_step();
                    #endif
                } else{
                    #ifdef ENCODERS_A_REVERSE
                    fp_rgblight_step();
                    #else
                    fp_rgblight_step_reverse();
                    #endif
                }
                break;
            case FP_ENC_0_LAYER_RGB_HUE:
                // rgb hue change
                if (clockwise){
                    #ifdef ENCODERS_A_REVERSE
                    fp_rgblight_decrease_hue();
                    #else
                    fp_rgblight_increase_hue();
                    #endif
                } else{
                    #ifdef ENCODERS_A_REVERSE
                    fp_rgblight_increase_hue();
                    #else
                    fp_rgblight_decrease_hue();
                    #endif
                }
                break;
            case FP_ENC_0_LAYER_RGB_SAT:
                // rgb saturation change
                if (clockwise){
                    #ifdef ENCODERS_A_REVERSE
                    fp_rgblight_decrease_sat();
                    #else
                    fp_rgblight_increase_sat();
                    #endif
                } else{
                    #ifdef ENCODERS_A_REVERSE
                    fp_rgblight_increase_sat();
                    #else
                    fp_rgblight_decrease_sat();
                    #endif
                }
                break;
            case FP_ENC_0_LAYER_RGB_VAL:
                // rgb value (brightness) change
                if (clockwise){
                    #ifdef ENCODERS_A_REVERSE
                    fp_rgblight_decrease_val();
                    #else
                    fp_rgblight_increase_val();
                    #endif
                } else{
                    #ifdef ENCODERS_A_REVERSE
                    fp_rgblight_increase_val();
                    #else
                    fp_rgblight_decrease_val();
                    #endif
                }
                break;
#endif // RGBLIGHT_ENABLE || RGB_MATRIX_ENABLE
            case FP_ENC_0_LAYER_VOLUME:
            default:
                // volume up and down
                if (clockwise){
                    #ifdef ENCODERS_A_REVERSE
                    tap_code(KC_VOLD);
                    #else
                    tap_code(KC_VOLU);
                    #endif
                } else{
                    #ifdef ENCODERS_A_REVERSE
                    tap_code(KC_VOLU);
                    #else
                    tap_code(KC_VOLD);
                    #endif
                }
                break;
        }
    } else if (index == 1) {
        switch(biton32(layer_state)){
            case FP_ENC_1_LAYER_PGUP_PGDN: //_SYMBOLS:
                // Page up / page down
                if (clockwise) {
                    #ifdef ENCODERS_B_REVERSE
                    tap_code(KC_PGUP);
                    #else
                    tap_code(KC_PGDN);
                    #endif
                } else {
                    #ifdef ENCODERS_B_REVERSE
                    tap_code(KC_PGDN);
                    #else
                    tap_code(KC_PGUP);
                    #endif
                }
                break;
            case FP_ENC_1_LAYER_ZOOM: //_MEDIA:
                // zoom in and out
                if (clockwise) {
                    #ifdef ENCODERS_B_REVERSE
                    tap_code16(C(KC_MINS));
                    #else
                    tap_code16(C(S(KC_EQL)));
                    #endif
                } else {
                    #ifdef ENCODERS_B_REVERSE
                    tap_code16(C(S(KC_EQL)));
                    #else
                    tap_code16(C(KC_MINS));
                    #endif
                }
                break;
#ifdef POINTING_DEVICE_ENABLE
            case FP_ENC_1_LAYER_DPI_POINTING: //_NAVIGATION:
                // word select left and right
                if (clockwise) {
                    #ifdef ENCODERS_B_REVERSE
                    fp_point_dpi_update(FP_DPI_UP);
                    #else
                    fp_point_dpi_update(FP_DPI_DOWN);
                    #endif
                } else {
                    #ifdef ENCODERS_B_REVERSE
                    fp_point_dpi_update(FP_DPI_DOWN);
                    #else
                    fp_point_dpi_update(FP_DPI_UP);
                    #endif
                }
                break;
#endif
            case FP_ENC_1_LAYER_SUPER_TAB: //_FUNCTION:
                // super alt tab
                if (clockwise) {
                    #ifdef ENCODERS_B_REVERSE
                    press_super_tab(true);
                    #else
                    press_super_tab(false);
                    #endif
                } else {
                    #ifdef ENCODERS_B_REVERSE
                    press_super_tab(false);
                    #else
                    press_super_tab(true);
                    #endif
                }
                break;
            case FP_ENC_1_LAYER_SCROLL_WHEEL:
                // scroll wheel
                if (clockwise){
                    #ifdef ENCODERS_B_REVERSE
                    tap_code16(MS_WHLU);
                    #else
                    tap_code16(MS_WHLD);
                    #endif
                } else{
                    #ifdef ENCODERS_B_REVERSE
                    tap_code16(MS_WHLD);
                    #else
                    tap_code16(MS_WHLU);
                    #endif
                }
                break;
            case FP_ENC_1_LAYER_VOLUME:
                // volume up and down
                if (clockwise){
                    #ifdef ENCODERS_B_REVERSE
                    tap_code(KC_VOLD);
                    #else
                    tap_code(KC_VOLU);
                    #endif
                } else{
                    #ifdef ENCODERS_B_REVERSE
                    tap_code(KC_VOLU);
                    #else
                    tap_code(KC_VOLD);
                    #endif
                }
                break;
#if defined(RGBLIGHT_ENABLE) || defined(RGB_MATRIX_ENABLE)
            case FP_ENC_1_LAYER_RGB_MODE:
                // rgb mode step
                if (clockwise){
                    #ifdef ENCODERS_B_REVERSE
                    fp_rgblight_step_reverse();
                    #else
                    fp_rgblight_step();
                    #endif
                } else{
                    #ifdef ENCODERS_B_REVERSE
                    fp_rgblight_step();
                    #else
                    fp_rgblight_step_reverse();
                    #endif
                }
                break;
            case FP_ENC_1_LAYER_RGB_HUE:
                // rgb hue change
                if (clockwise){
                    #ifdef ENCODERS_B_REVERSE
                    fp_rgblight_decrease_hue();
                    #else
                    fp_rgblight_increase_hue();
                    #endif
                } else{
                    #ifdef ENCODERS_B_REVERSE
                    fp_rgblight_increase_hue();
                    #else
                    fp_rgblight_decrease_hue();
                    #endif
                }
                break;
            case FP_ENC_1_LAYER_RGB_SAT:
                // rgb saturation change
                if (clockwise){
                    #ifdef ENCODERS_B_REVERSE
                    fp_rgblight_decrease_sat();
                    #else
                    fp_rgblight_increase_sat();
                    #endif
                } else{
                    #ifdef ENCODERS_B_REVERSE
                    fp_rgblight_increase_sat();
                    #else
                    fp_rgblight_decrease_sat();
                    #endif
                }
                break;
            case FP_ENC_1_LAYER_RGB_VAL:
                // rgb value (brightness) change
                if (clockwise){
                    #ifdef ENCODERS_B_REVERSE
                    fp_rgblight_decrease_val();
                    #else
                    fp_rgblight_increase_val();
                    #endif
                } else{
                    #ifdef ENCODERS_B_REVERSE
                    fp_rgblight_increase_val();
                    #else
                    fp_rgblight_decrease_val();
                    #endif
                }
                break;
#endif // RGBLIGHT_ENABLE || RGB_MATRIX_ENABLE
            case FP_ENC_1_LAYER_SUPER_CTRL_TAB:
            default:
                // super ctrl tab
                // switch between browser windows, or files in vscode
                if (clockwise) {
                    #ifdef ENCODERS_B_REVERSE
                    press_super_ctrl_tab(true);
                    #else
                    press_super_ctrl_tab(false);
                    #endif
                } else {
                    #ifdef ENCODERS_B_REVERSE
                    press_super_ctrl_tab(false);
                    #else
                    press_super_ctrl_tab(true);
                    #endif
                }
                break;
        }
    }
    else if (index == 2) {
        switch(biton32(layer_state)){
            default:
                // scroll wheel
                if (clockwise){
                    #ifdef ENCODERS_B_REVERSE
                    tap_code16(MS_WHLU);
                    #else
                    tap_code16(MS_WHLD);
                    #endif
                } else{
                    #ifdef ENCODERS_B_REVERSE
                    tap_code16(MS_WHLD);
                    #else
                    tap_code16(MS_WHLU);
                    #endif
                }
                break;
        }
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