/* Copyright 2019 gtips
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

#include "sadekbaroudi.h"

#include QMK_KEYBOARD_H

#ifndef UNICODE_ENABLE
#    define UC(x) KC_NO
#endif

/*
 * The `LAYOUT_reviung39_base` macro is a template to allow the use of identical
 * modifiers for the default layouts (eg QWERTY, Colemak, Dvorak, etc), so
 * that there is no need to set them up for each layout, and modify all of
 * them if I want to change them.  This helps to keep consistency and ease
 * of use. K## is a placeholder to pass through the individual keycodes
 */

// clang-format off
#define LAYOUT_reviung39_base( \
    K01, K02, K03, K04, K05, K06, K07, K08, K09, K0A, \
    K11, K12, K13, K14, K15, K16, K17, K18, K19, K1A, \
    K21, K22, K23, K24, K25, K26, K27, K28, K29, K2A  \
  ) \
  LAYOUT_wrapper( \
        KC_ESC,         K01,            K02,            K03,            K04,            K05,                K06,            K07,            K08,            K09,            K0A,            KC_BSLS, \
        KC_TAB,         LCTL_T(K11),    LGUI_T(K12),    LALT_T(K13),    LSFT_T(K14),    K15,                K16,            RSFT_T(K17),    RALT_T(K18),    RGUI_T(K19),    RCTL_T(K1A),    LT(_MOUSE,KC_QUOT), \
        KC_DEL,         K21,            K22,            K23,            K24,            K25,                K26,            K27,            K28,            K29,            K2A,            KC_BSPC, \
                                                            LT(_NAVIGATION,KC_ENT),       LT(_FUNCTION,KC_BSPC),             LT(_SYMBOLS,KC_SPACE) \
    )
/* Re-pass though to allow templates to be used */
#define LAYOUT_reviung39_base_wrapper(...)       LAYOUT_reviung39_base(__VA_ARGS__)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    [_QWERTY] = LAYOUT_reviung39_base_wrapper(
        _________________QWERTY_L1_________________, _________________QWERTY_R1_________________,
        _________________QWERTY_L2_________________, _________________QWERTY_R2_________________,
        _________________QWERTY_L3_________________, _________________QWERTY_R3_________________
    ),

    [_COLEMAK] = LAYOUT_reviung39_base_wrapper(
        ______________COLEMAK_MOD_DH_L1____________, ______________COLEMAK_MOD_DH_R1____________,
        ______________COLEMAK_MOD_DH_L2____________, ______________COLEMAK_MOD_DH_R2____________,
        ______________COLEMAK_MOD_DH_L3____________, ______________COLEMAK_MOD_DH_R3____________
    ),

    [_WORKMAN] = LAYOUT_reviung39_base_wrapper(
        _________________WORKMAN_L1________________, _________________WORKMAN_R1________________,
        _________________WORKMAN_L2________________, _________________WORKMAN_R2________________,
        _________________WORKMAN_L3________________, _________________WORKMAN_R3________________
    ),

    [_NAVIGATION] = LAYOUT_wrapper(
        LALT(KC_F4),           ________________NAVIGATION_1_______________, _________________NUMPAD_1__________________, _______,
        KC_CAPS,               ________________NAVIGATION_2_______________, _________________NUMPAD_2__________________, KC_DOT,
        LCTL(LALT(KC_DELETE)), ________________NAVIGATION_3_______________, _________________NUMPAD_3__________________, _______,
                                                              _______, KC_BSPC, MO(_MEDIA)
    ),

    [_SYMBOLS] = LAYOUT_wrapper(
        KC_GRV,  ________________SYMBOLS_L1_________________, ________________SYMBOLS_R1_________________, _______,
        _______, ________________SYMBOLS_L2_________________, ________________SYMBOLS_R2_________________, _______,
        _______, ________________SYMBOLS_L3_________________, ________________SYMBOLS_R3_________________, _______,
                                              MO(_MEDIA), KC_BSPC, _______
    ),

    [_FUNCTION] = LAYOUT_wrapper(
        _______, ________________SHIFTNAV_1_________________, ________________FUNCTION_1_________________, _______,
        _______, ________________SHIFTNAV_2_________________, ________________FUNCTION_2_________________, _______,
        _______, ________________SHIFTNAV_3_________________, ________________FUNCTION_3_________________, _______,
                                                _______, _______, _______
    ),

    [_MEDIA] = LAYOUT_wrapper(
        RESET,   ___________________RGB_1___________________, _________________MACROS_1__________________, TG(_QWERTY),
        _______, ___________________RGB_2___________________, _________________MACROS_2__________________, TG(_COLEMAK),
        _______, ___________________RGB_3___________________, _________________MACROS_3__________________, TG(_WORKMAN),
                                                _______, _______, _______
    ),
    
    [_MOUSE] = LAYOUT_wrapper(
        _______, __________________MOUSE_1__________________, ___________________BLANK___________________, _______,
        _______, __________________MOUSE_2__________________, ___________________BLANK___________________, _______,
        _______, __________________MOUSE_3__________________, ___________________BLANK___________________, _______,
                                         KC_MS_BTN1,    KC_MS_BTN3,   KC_MS_BTN2
    )

};

/*
#define LAYER_IS_ON(layer_state, layer_num) ((layer_state & (1 << layer_num)) > 0)


////// Start RGB backlight timeout
// https://gist.github.com/MaxWinterstein/c99594a5f4f8da942feb72c8233445aa/
#define BACKLIGHT_TIMEOUT 5    // in minutes
static uint16_t idle_timer = 0;
static uint8_t halfmin_counter = 0;
static bool led_on = true;
////// End RGB backlight timeout

// Begin layer lighting

    // example of multicolor layer
    //{0, 5, HSV_BLUE},   // left side of underglow is blue
    //{5, 5, HSV_YELLOW}, // right side of underglow is yellow
    //{10, 1, HSV_GREEN}  // middle top side light is green
    //

// uncomment to set base layer without the abiliby to override
const rgblight_segment_t PROGMEM layer_0_rgb[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, 11, HSV_BLUE}
    // with retro keycaps
    //
    //{0, 1, HSV_RED},
    //{1, 2, HSV_BLUE},
    //{3, 1, 16, 255, 255}, // orange
    //{4, 5, 16, 255, 90}, // brown
    //{9, 1, HSV_YELLOW},
    //{10, 1, 10, 10, 255}
    //
);

const rgblight_segment_t PROGMEM layer_1_rgb[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, 11, 10, 10, 255}
);

const rgblight_segment_t PROGMEM layer_2_rgb[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, 11, HSV_GREEN}
);

const rgblight_segment_t PROGMEM layer_3_rgb[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, 11, HSV_PURPLE}
);

const rgblight_segment_t PROGMEM layer_4_rgb[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, 11, HSV_YELLOW}
);

const rgblight_segment_t PROGMEM layer_5_rgb[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, 11, HSV_MAGENTA}
);

const rgblight_segment_t PROGMEM layer_6_rgb[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, 11, HSV_CYAN}
);

const rgblight_segment_t PROGMEM layer_capslock_rgb[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, 11, HSV_RED}
);


const rgblight_segment_t* const PROGMEM my_rgb_layers[] = RGBLIGHT_LAYERS_LIST(
    layer_0_rgb,
    layer_1_rgb,
    layer_2_rgb,
    layer_3_rgb,
    layer_4_rgb,
    layer_5_rgb,
    layer_6_rgb,
    layer_capslock_rgb
);

void keyboard_post_init_user(void) {
    // set default color
    // rgblight_sethsv_noeeprom(HSV_WHITE);
    // Enable the LED layers
    rgblight_layers = my_rgb_layers;

    rgblight_enable_noeeprom();
}

uint32_t layer_state_set_user(uint32_t state) {
    // Comment this next line to allow for RGB override through RGB keys
    //rgblight_set_layer_state(0, true);
    rgblight_set_layer_state(1, LAYER_IS_ON(state, 1));
    rgblight_set_layer_state(2, LAYER_IS_ON(state, 2));
    rgblight_set_layer_state(3, LAYER_IS_ON(state, 3));
    rgblight_set_layer_state(4, LAYER_IS_ON(state, 4));
    rgblight_set_layer_state(5, LAYER_IS_ON(state, 5));
    rgblight_set_layer_state(6, LAYER_IS_ON(state, 6));
    return state;
}

bool led_update_user(led_t led_state) {
    rgblight_set_layer_state(7, led_state.caps_lock);
    return true;
}

void matrix_scan_user(void) {
    ////// Start RGB backlight timeout
    // idle_timer needs to be set one time
    if (idle_timer == 0) idle_timer = timer_read();

    if ( led_on && timer_elapsed(idle_timer) > 30000) {
        halfmin_counter++;
        idle_timer = timer_read();
    }

    if ( led_on && halfmin_counter >= BACKLIGHT_TIMEOUT * 2) {
        rgblight_disable_noeeprom();
        led_on = false;
        halfmin_counter = 0;
    }
    ////// End RGB backlight timeout
}

bool process_record_keymap(uint16_t keycode, keyrecord_t *record) {
    ////// Start RGB backlight timeout
    if (led_on == false) {
        rgblight_enable_noeeprom();
        led_on = true;
    }
    idle_timer = timer_read();
    halfmin_counter = 0;
    ////// End RGB backlight timeout

    return true;
};
*/