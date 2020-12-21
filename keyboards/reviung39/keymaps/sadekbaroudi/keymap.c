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
#include QMK_KEYBOARD_H

#define LAYER_IS_ON(layer_state, layer_num) ((layer_state & (1 << layer_num)) > 0)

// Begin layer lighting
const rgblight_segment_t PROGMEM layer_0_rgb[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, 11, 10, 10, 255}
);

const rgblight_segment_t PROGMEM layer_1_rgb[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, 11, HSV_GREEN}
);

const rgblight_segment_t PROGMEM layer_2_rgb[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, 11, HSV_BLUE}
);

const rgblight_segment_t PROGMEM layer_3_rgb[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, 11, HSV_YELLOW}
);

const rgblight_segment_t PROGMEM layer_4_rgb[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, 11, HSV_MAGENTA}
);

/* ANIMATIONS
const rgblight_segment_t PROGMEM layer_5_rgb[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, 11, HSV_GOLDENROD}
);
*/

const rgblight_segment_t PROGMEM layer_capslock_rgb[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, 11, HSV_RED}
);


const rgblight_segment_t* const PROGMEM my_rgb_layers[] = RGBLIGHT_LAYERS_LIST(
    layer_0_rgb,
    layer_1_rgb,
    layer_2_rgb,
    layer_3_rgb,
    layer_4_rgb,
    //layer_5_rgb, // ANIMATIONS
    layer_capslock_rgb
);

void keyboard_post_init_user(void) {
    // set default color
    // rgblight_sethsv_noeeprom(HSV_WHITE);
    // Enable the LED layers
    rgblight_layers = my_rgb_layers;
}

uint32_t layer_state_set_user(uint32_t state) {
    // Both layers will light up if both kb layers are active
    rgblight_set_layer_state(0, true);
    rgblight_set_layer_state(1, LAYER_IS_ON(state, 1));
    rgblight_set_layer_state(2, LAYER_IS_ON(state, 2));
    rgblight_set_layer_state(3, LAYER_IS_ON(state, 3));
    rgblight_set_layer_state(4, LAYER_IS_ON(state, 4));
    //rgblight_set_layer_state(5, LAYER_IS_ON(state, 5)); // ANIMATIONS
    return state;
}

bool led_update_user(led_t led_state) {
    rgblight_set_layer_state(5, led_state.caps_lock); // ANIMATIONS change to 6
    return true;
}

// Macro aliases
enum custom_keycodes {
    VIM_W = SAFE_RANGE,
    VIM_Q,
    VIM_SELECT,
    L_CDHOME,
    L_GREP,
    L_FIND,
    L_GITCOMMIT
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    // do stuff when macro keys are pressed
    switch (keycode) {
    case VIM_W:
        if (record->event.pressed) {
            SEND_STRING(SS_TAP(X_ESC)":w\n");
        } else {
            // when keycode is released
        }
        break;
    case VIM_Q:
        if (record->event.pressed) {
            SEND_STRING(SS_TAP(X_ESC)":q\n");
        } else {
            // when keycode is released
        }
        break;
    case VIM_SELECT:
        if (record->event.pressed) {
            SEND_STRING(SS_TAP(X_ESC)"V"SS_TAP(X_DOWN));
        } else {
            // when keycode is released
        }
        break;
    case L_CDHOME:
        if (record->event.pressed) {
            SEND_STRING("cd ~/\n");
        } else {
            // when keycode is released
        }
        break;
    case L_GREP:
        if (record->event.pressed) {
            SEND_STRING("grep -rn \"");
        } else {
            // when keycode is released
        }
        break;
    case L_FIND:
        if (record->event.pressed) {
            SEND_STRING("find . -name \"");
        } else {
            // when keycode is released
        }
        break;
    case L_GITCOMMIT:
        if (record->event.pressed) {
            SEND_STRING("git commit -a -m \"\""SS_TAP(X_LEFT));
        } else {
            // when keycode is released
        }
        break;
    }
    return true;
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
// ANIMATIONS - if adding animation layer back, remember to add a key to go to that layer, I was using LT(5,KC_ESC), on the escape key before
[0] = LAYOUT_reviung39(
  KC_ESC,                KC_Q,                  KC_W,                  KC_E,                  KC_R,                  KC_T,                  KC_Y,                  KC_U,                  KC_I,                  KC_O,                  KC_P,                  KC_BSLS,
  KC_TAB,                LCTL_T(KC_A),          LGUI_T(KC_S),          LALT_T(KC_D),          LSFT_T(KC_F),          KC_G,                  KC_H,                  RSFT_T(KC_J),          RALT_T(KC_K),          RGUI_T(KC_L),          RCTL_T(KC_SCLN),       KC_QUOT,
  KC_DEL,                KC_Z,                  KC_X,                  KC_C,                  KC_V,                  KC_B,                  KC_N,                  KC_M,                  KC_COMM,               KC_DOT,                KC_SLSH,               KC_BSPC,
                                                                                              LT(1,KC_ENT),                   LT(3,KC_CAPS),                       LT(2,KC_SPC)
),

[1] = LAYOUT_reviung39(
  LALT(KC_F4),           LCTL(KC_W),            KC_PGUP,               KC_UP,                 KC_PGDN,               LCTL(KC_TAB),          KC_ASTR,               KC_7,                  KC_8,                  KC_9,                  KC_PLUS,               KC_DEL,
  KC_CAPS,               KC_HOME,               KC_LEFT,               KC_DOWN,               KC_RGHT,               KC_END,                KC_SLSH,               KC_4,                  KC_5,                  KC_6,                  KC_MINS,               KC_DOT,
  LCTL(LALT(KC_DELETE)), LCTL(KC_Z),            LCTL(KC_X),            LCTL(KC_C),            LCTL(KC_V),            LCTL(LSFT(KC_TAB)),    KC_PEQL,               KC_1,                  KC_2,                  KC_3,                  KC_0,                  KC_NO,
                                                                                              KC_NO,                             KC_NO,                            MO(4)
),

[2] = LAYOUT_reviung39(
  KC_GRV,                KC_EXLM,               KC_AT,                 KC_HASH,               KC_DLR,                KC_PERC,               KC_CIRC,               KC_AMPR,               KC_ASTR,               KC_LPRN,               KC_RPRN,               KC_NO,
  KC_NO,                 KC_MINS,               KC_LBRC,               KC_LCBR,               KC_LPRN,               KC_LT,                 KC_GT,                 KC_RPRN,               KC_RCBR,               KC_RBRC,               KC_PLUS,               KC_NO,
  KC_NO,                 KC_UNDS,               KC_EQL,                KC_NO,                 LCTL(LGUI(KC_LEFT)),   KC_NO,                 KC_NO,                 LCTL(LGUI(KC_RIGHT)),  KC_NO,                 KC_NO,                 KC_SLSH,               KC_NO,
                                                                                              MO(4),                             KC_NO,                            KC_NO
),

[3] = LAYOUT_reviung39(
  KC_NO,                 KC_NO,                 LSFT(KC_PGDN),         LSFT(KC_UP),           LSFT(KC_PGUP),         KC_NO,                 KC_MPLY,               KC_F7,                 KC_F8,                 KC_F9,                 KC_F10,                KC_NO,
  KC_NO,                 LSFT(KC_HOME),         LSFT(KC_LEFT),         LSFT(KC_DOWN),         LSFT(KC_RGHT),         LSFT(KC_END),          KC_VOLU,               KC_F4,                 KC_F5,                 KC_F6,                 KC_F11,                KC_MFFD,
  KC_NO,                 LCTL(KC_Z),            LCTL(KC_X),            LCTL(KC_C),            LCTL(KC_V),            KC_NO,                 KC_VOLD,               KC_F1,                 KC_F2,                 KC_F3,                 KC_F12,                KC_MRWD,
                                                                                              KC_TRNS,                           KC_NO,                            KC_NO
),

[4] = LAYOUT_reviung39(
  KC_NO,                 VIM_Q,                 VIM_W,                 KC_NO,                 KC_NO,                 KC_NO,                 KC_NO,                 KC_NO,                 KC_NO,                 KC_NO,                 KC_NO,                 KC_NO,
  KC_NO,                 KC_NO,                 VIM_SELECT,            KC_NO,                 L_FIND,                L_GREP,                L_CDHOME,              KC_NO,                 KC_NO,                 KC_NO,                 KC_NO,                 KC_NO,
  KC_NO,                 KC_NO,                 KC_NO,                 L_GITCOMMIT,           KC_NO,                 KC_NO,                 KC_NO,                 KC_NO,                 KC_NO,                 KC_NO,                 KC_NO,                 KC_NO,
                                                                                              KC_NO,                             KC_NO,                            KC_NO
),

/* ANIMATIONS
[5] = LAYOUT_reviung39(
  KC_NO,                 KC_NO,                 KC_NO,                 KC_NO,                 KC_NO,                 KC_NO,                 RGB_TOG,               RGB_HUD,               RGB_HUI,               RGB_SAD,               RGB_SAI,               KC_NO,
  KC_NO,                 KC_NO,                 KC_NO,                 KC_NO,                 KC_NO,                 KC_NO,                 KC_NO,                 RGB_VAD,               RGB_VAI,               RGB_RMOD,              RGB_MOD,               KC_NO,
  KC_NO,                 KC_NO,                 KC_NO,                 KC_NO,                 KC_NO,                 KC_NO,                 KC_NO,                 KC_NO,                 KC_NO,                 KC_NO,                 KC_NO,                 KC_NO,
                                                                                              KC_NO,                             KC_NO,                            KC_NO
)
*/

};

