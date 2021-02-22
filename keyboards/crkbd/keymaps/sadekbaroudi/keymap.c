/*
Copyright 2019 @foostan
Copyright 2020 Drashna Jaelre <@drashna>

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include QMK_KEYBOARD_H

#define LAYER_IS_ON(layer_state, layer_num) ((layer_state & (1 << layer_num)) > 0)

////// Start RGB backlight timeout
// https://gist.github.com/MaxWinterstein/c99594a5f4f8da942feb72c8233445aa/
#define BACKLIGHT_TIMEOUT 5    // in minutes
static uint16_t idle_timer = 0;
static uint8_t halfmin_counter = 0;
static bool led_on = true;
////// End RGB backlight timeout

// Begin layer lighting
const rgblight_segment_t PROGMEM layer_0_rgb[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, 27, HSV_BLUE}
);

const rgblight_segment_t PROGMEM layer_1_rgb[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, 27, HSV_WHITE}
);

const rgblight_segment_t PROGMEM layer_2_rgb[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, 27, HSV_GREEN}
);

const rgblight_segment_t PROGMEM layer_3_rgb[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, 27, HSV_PURPLE}
);

const rgblight_segment_t PROGMEM layer_4_rgb[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, 27, HSV_YELLOW}
);

const rgblight_segment_t PROGMEM layer_5_rgb[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, 27, HSV_MAGENTA}
);

const rgblight_segment_t PROGMEM layer_6_rgb[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, 27, HSV_CYAN}
);

const rgblight_segment_t PROGMEM layer_capslock_rgb[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, 27, HSV_RED}
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
    // uncomment to set base layer without the abiliby to override
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

// Macro aliases
enum custom_keycodes {
    VIM_W = SAFE_RANGE,
    VIM_Q,
    VIM_SELECT,
    L_CDHOME,
    L_GREP,
    L_FIND,
    L_GITCOMMIT,
    P_ANGBRKT,
    P_PAREN,
    P_CURLY,
    P_BRKT,
    E_ROBOT,
    E_CAT
};


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/*
// SAWDMAKdh-1
[0] = LAYOUT_split_3x6_3(
//---------------------+----------------------+----------------------+----------------------+----------------------+----------------------+----------------------+----------------------+----------------------+----------------------+----------------------+-------------------+
  KC_ESC,                KC_Q,                  KC_W,                  KC_J,                  KC_R,                  KC_T,                  KC_Y,                  KC_U,                  KC_I,                  KC_O,                  KC_P,                  KC_BSLS,
//---------------------+----------------------+----------------------+----------------------+----------------------+----------------------+----------------------+----------------------+----------------------+----------------------+----------------------+-------------------+
  KC_TAB,                LCTL_T(KC_A),          LGUI_T(KC_S),          LALT_T(KC_D),          LSFT_T(KC_F),          KC_G,                  KC_H,                  RSFT_T(KC_N),          RALT_T(KC_E),          RGUI_T(KC_L),          RCTL_T(KC_SCLN),       LT(6,KC_QUOT),
//---------------------+----------------------+----------------------+----------------------+----------------------+----------------------+----------------------+----------------------+----------------------+----------------------+----------------------+-------------------+
  KC_DEL,                KC_Z,                  KC_X,                  KC_C,                  KC_V,                  KC_B,                  KC_K,                  KC_M,                  KC_COMM,               KC_DOT,                KC_SLSH,               KC_BSPC,
//---------------------+----------------------+----------------------+----------------------+----------------------+----------------------+----------------------+----------------------+----------------------+----------------------+----------------------+-------------------+
                                                                       XXXXXXX,               LT(2,KC_ENT),          LT(4,KC_BSPC),         LT(4,KC_BSPC),         LT(3,KC_SPC),          XXXXXXX
//                                                                   +----------------------+----------------------+----------------------+----------------------+----------------------+----------------------+
),

// SAWDMAKdh-2
[0] = LAYOUT_split_3x6_3(
//---------------------+----------------------+----------------------+----------------------+----------------------+----------------------+----------------------+----------------------+----------------------+----------------------+----------------------+-------------------+
  KC_ESC,                KC_Q,                  KC_W,                  KC_F,                  KC_R,                  KC_J,                  KC_Y,                  KC_U,                  KC_I,                  KC_O,                  KC_P,                  KC_BSLS,
//---------------------+----------------------+----------------------+----------------------+----------------------+----------------------+----------------------+----------------------+----------------------+----------------------+----------------------+-------------------+
  KC_TAB,                LCTL_T(KC_A),          LGUI_T(KC_S),          LALT_T(KC_D),          LSFT_T(KC_T),          KC_G,                  KC_H,                  RSFT_T(KC_N),          RALT_T(KC_E),          RGUI_T(KC_L),          RCTL_T(KC_SCLN),       LT(6,KC_QUOT),
//---------------------+----------------------+----------------------+----------------------+----------------------+----------------------+----------------------+----------------------+----------------------+----------------------+----------------------+-------------------+
  KC_DEL,                KC_Z,                  KC_X,                  KC_C,                  KC_V,                  KC_B,                  KC_K,                  KC_M,                  KC_COMM,               KC_DOT,                KC_SLSH,               KC_BSPC,
//---------------------+----------------------+----------------------+----------------------+----------------------+----------------------+----------------------+----------------------+----------------------+----------------------+----------------------+-------------------+
                                                                       XXXXXXX,               LT(2,KC_ENT),          LT(4,KC_BSPC),         LT(4,KC_BSPC),         LT(3,KC_SPC),          XXXXXXX
//                                                                   +----------------------+----------------------+----------------------+----------------------+----------------------+----------------------+
),

// SAWDMAKdh-3
[0] = LAYOUT_split_3x6_3(
//---------------------+----------------------+----------------------+----------------------+----------------------+----------------------+----------------------+----------------------+----------------------+----------------------+----------------------+-------------------+
  KC_ESC,                KC_Q,                  KC_W,                  KC_F,                  KC_J,                  KC_V,                  KC_Y,                  KC_U,                  KC_I,                  KC_O,                  KC_P,                  KC_BSLS,
//---------------------+----------------------+----------------------+----------------------+----------------------+----------------------+----------------------+----------------------+----------------------+----------------------+----------------------+-------------------+
  KC_TAB,                LCTL_T(KC_A),          LGUI_T(KC_R),          LALT_T(KC_S),          LSFT_T(KC_T),          KC_G,                  KC_H,                  RSFT_T(KC_N),          RALT_T(KC_E),          RGUI_T(KC_L),          RCTL_T(KC_SCLN),       LT(6,KC_QUOT),
//---------------------+----------------------+----------------------+----------------------+----------------------+----------------------+----------------------+----------------------+----------------------+----------------------+----------------------+-------------------+
  KC_DEL,                KC_Z,                  KC_X,                  KC_C,                  KC_D,                  KC_B,                  KC_K,                  KC_M,                  KC_COMM,               KC_DOT,                KC_SLSH,               KC_BSPC,
//---------------------+----------------------+----------------------+----------------------+----------------------+----------------------+----------------------+----------------------+----------------------+----------------------+----------------------+-------------------+
                                                                       XXXXXXX,               LT(2,KC_ENT),          LT(4,KC_BSPC),         LT(4,KC_BSPC),         LT(3,KC_SPC),          XXXXXXX
//                                                                   +----------------------+----------------------+----------------------+----------------------+----------------------+----------------------+
),

// COLEMAK-DH-MODBV
[0] = LAYOUT_split_3x6_3(
//---------------------+----------------------+----------------------+----------------------+----------------------+----------------------+----------------------+----------------------+----------------------+----------------------+----------------------+-------------------+
  KC_ESC,                KC_Q,                  KC_W,                  KC_F,                  KC_P,                  KC_V,                  KC_J,                  KC_L,                  KC_U,                  KC_Y,                  KC_SCLN,               KC_BSLS,
//---------------------+----------------------+----------------------+----------------------+----------------------+----------------------+----------------------+----------------------+----------------------+----------------------+----------------------+-------------------+
  KC_TAB,                LCTL_T(KC_A),          LGUI_T(KC_R),          LALT_T(KC_S),          LSFT_T(KC_T),          KC_G,                  KC_H,                  RSFT_T(KC_N),          RALT_T(KC_E),          RGUI_T(KC_I),          RCTL_T(KC_O),          LT(6,KC_QUOT),
//---------------------+----------------------+----------------------+----------------------+----------------------+----------------------+----------------------+----------------------+----------------------+----------------------+----------------------+-------------------+
  KC_DEL,                KC_Z,                  KC_X,                  KC_C,                  KC_D,                  KC_B,                  KC_K,                  KC_M,                  KC_COMM,               KC_DOT,                KC_SLSH,               KC_BSPC,
//---------------------+----------------------+----------------------+----------------------+----------------------+----------------------+----------------------+----------------------+----------------------+----------------------+----------------------+-------------------+
                                                                       XXXXXXX,               LT(2,KC_ENT),          LT(4,KC_BSPC),         LT(4,KC_BSPC),         LT(3,KC_SPC),          XXXXXXX
//                                                                   +----------------------+----------------------+----------------------+----------------------+----------------------+----------------------+
),
*/

// COLEMAK-DH
[0] = LAYOUT_split_3x6_3(
//---------------------+----------------------+----------------------+----------------------+----------------------+----------------------+----------------------+----------------------+----------------------+----------------------+----------------------+-------------------+
  KC_ESC,                KC_Q,                  KC_W,                  KC_F,                  KC_P,                  KC_B,                  KC_J,                  KC_L,                  KC_U,                  KC_Y,                  KC_SCLN,               KC_BSLS,
//---------------------+----------------------+----------------------+----------------------+----------------------+----------------------+----------------------+----------------------+----------------------+----------------------+----------------------+-------------------+
  KC_TAB,                LCTL_T(KC_A),          LGUI_T(KC_R),          LALT_T(KC_S),          LSFT_T(KC_T),          KC_G,                  KC_M,                  RSFT_T(KC_N),          RALT_T(KC_E),          RGUI_T(KC_I),          RCTL_T(KC_O),          LT(6,KC_QUOT),
//---------------------+----------------------+----------------------+----------------------+----------------------+----------------------+----------------------+----------------------+----------------------+----------------------+----------------------+-------------------+
  KC_DEL,                KC_Z,                  KC_X,                  KC_C,                  KC_D,                  KC_V,                  KC_K,                  KC_H,                  KC_COMM,               KC_DOT,                KC_SLSH,               KC_BSPC,
//---------------------+----------------------+----------------------+----------------------+----------------------+----------------------+----------------------+----------------------+----------------------+----------------------+----------------------+-------------------+
                                                                       XXXXXXX,               LT(2,KC_ENT),          LT(4,KC_DEL),          LT(4,KC_BSPC),         LT(3,KC_SPC),          XXXXXXX
//                                                                   +----------------------+----------------------+----------------------+----------------------+----------------------+----------------------+
),

// QWERTY
[1] = LAYOUT_split_3x6_3(
//---------------------+----------------------+----------------------+----------------------+----------------------+----------------------+----------------------+----------------------+----------------------+----------------------+----------------------+-------------------+
  KC_ESC,                KC_Q,                  KC_W,                  KC_E,                  KC_R,                  KC_T,                  KC_Y,                  KC_U,                  KC_I,                  KC_O,                  KC_P,                  KC_BSLS,
//---------------------+----------------------+----------------------+----------------------+----------------------+----------------------+----------------------+----------------------+----------------------+----------------------+----------------------+-------------------+
  KC_TAB,                LCTL_T(KC_A),          LGUI_T(KC_S),          LALT_T(KC_D),          LSFT_T(KC_F),          KC_G,                  KC_H,                  RSFT_T(KC_J),          RALT_T(KC_K),          RGUI_T(KC_L),          RCTL_T(KC_SCLN),       LT(6,KC_QUOT),
//---------------------+----------------------+----------------------+----------------------+----------------------+----------------------+----------------------+----------------------+----------------------+----------------------+----------------------+-------------------+
  KC_DEL,                KC_Z,                  KC_X,                  KC_C,                  KC_V,                  KC_B,                  KC_N,                  KC_M,                  KC_COMM,               KC_DOT,                KC_SLSH,               KC_BSPC,
//---------------------+----------------------+----------------------+----------------------+----------------------+----------------------+----------------------+----------------------+----------------------+----------------------+----------------------+-------------------+
                                                                       XXXXXXX,               LT(2,KC_ENT),          LT(4,KC_DEL),          LT(4,KC_BSPC),         LT(3,KC_SPC),          XXXXXXX
//                                                                   +----------------------+----------------------+----------------------+----------------------+----------------------+----------------------+
),

// NAVIGATION AND NUMBERS
[2] = LAYOUT_split_3x6_3(
//---------------------+----------------------+----------------------+----------------------+----------------------+----------------------+----------------------+----------------------+----------------------+----------------------+----------------------+-------------------+
  LALT(KC_F4),           LCTL(KC_W),            KC_PGUP,               KC_UP,                 KC_PGDN,               LCTL(LSFT(KC_TAB)),    KC_ASTR,               KC_7,                  KC_8,                  KC_9,                  KC_PLUS,               _______,
//---------------------+----------------------+----------------------+----------------------+----------------------+----------------------+----------------------+----------------------+----------------------+----------------------+----------------------+-------------------+
  KC_CAPS,               KC_HOME,               KC_LEFT,               KC_DOWN,               KC_RGHT,               KC_END,                KC_SLSH,               KC_4,                  KC_5,                  KC_6,                  KC_MINS,               KC_DOT,
//---------------------+----------------------+----------------------+----------------------+----------------------+----------------------+----------------------+----------------------+----------------------+----------------------+----------------------+-------------------+
  LCTL(LALT(KC_DELETE)), LCTL(KC_Z),            LCTL(KC_X),            LCTL(KC_C),            LCTL(KC_V),            LCTL(KC_TAB),          KC_EQL,                KC_1,                  KC_2,                  KC_3,                  KC_0,                  _______,
//---------------------+----------------------+----------------------+----------------------+----------------------+----------------------+----------------------+----------------------+----------------------+----------------------+----------------------+-------------------+
                                                                       XXXXXXX,               _______,               KC_DEL,                KC_BSPC,               MO(5),                 XXXXXXX
//                                                                   +----------------------+----------------------+----------------------+----------------------+----------------------+----------------------+
),

// SYMBOLS
[3] = LAYOUT_split_3x6_3(
//---------------------+----------------------+----------------------+----------------------+----------------------+----------------------+----------------------+----------------------+----------------------+----------------------+----------------------+-------------------+
  KC_GRV,                KC_EXLM,               KC_AT,                 KC_HASH,               KC_DLR,                KC_PERC,               KC_CIRC,               KC_AMPR,               KC_ASTR,               KC_LPRN,               KC_RPRN,               _______,
//---------------------+----------------------+----------------------+----------------------+----------------------+----------------------+----------------------+----------------------+----------------------+----------------------+----------------------+-------------------+
  _______,               KC_MINS,               KC_LBRC,               KC_LCBR,               KC_LPRN,               KC_LT,                 KC_GT,                 KC_RPRN,               KC_RCBR,               KC_RBRC,               KC_PLUS,               _______,
//---------------------+----------------------+----------------------+----------------------+----------------------+----------------------+----------------------+----------------------+----------------------+----------------------+----------------------+-------------------+
  _______,               KC_UNDS,               KC_EQL,                _______,               LCTL(LGUI(KC_LEFT)),   _______,               _______,               LCTL(LGUI(KC_RIGHT)),  _______,               _______,               KC_SLSH,               _______,
//---------------------+----------------------+----------------------+----------------------+----------------------+----------------------+----------------------+----------------------+----------------------+----------------------+----------------------+-------------------+
                                                                       XXXXXXX,               MO(5),                 KC_DEL,                KC_BSPC,               _______,               XXXXXXX
//                                                                   +----------------------+----------------------+----------------------+----------------------+----------------------+----------------------+
),

// SHIFT NAVIGATION, F KEYS, MEDIA KEYS
[4] = LAYOUT_split_3x6_3(
//---------------------+----------------------+----------------------+----------------------+----------------------+----------------------+----------------------+----------------------+----------------------+----------------------+----------------------+-------------------+
  _______,               _______,               LSFT(KC_PGDN),         LSFT(KC_UP),           LSFT(KC_PGUP),         _______,               KC_MPLY,               KC_F7,                 KC_F8,                 KC_F9,                 KC_F10,                _______,
//---------------------+----------------------+----------------------+----------------------+----------------------+----------------------+----------------------+----------------------+----------------------+----------------------+----------------------+-------------------+
  _______,               LSFT(KC_HOME),         LSFT(KC_LEFT),         LSFT(KC_DOWN),         LSFT(KC_RGHT),         LSFT(KC_END),          KC_VOLU,               KC_F4,                 KC_F5,                 KC_F6,                 KC_F11,                KC_MFFD,
//---------------------+----------------------+----------------------+----------------------+----------------------+----------------------+----------------------+----------------------+----------------------+----------------------+----------------------+-------------------+
  _______,               LCTL(KC_Z),            LCTL(KC_X),            LCTL(KC_C),            LCTL(KC_V),            _______,               KC_VOLD,               KC_F1,                 KC_F2,                 KC_F3,                 KC_F12,                KC_MRWD,
//---------------------+----------------------+----------------------+----------------------+----------------------+----------------------+----------------------+----------------------+----------------------+----------------------+----------------------+-------------------+
                                                                       XXXXXXX,               KC_TRNS,               _______,               _______,               _______,               XXXXXXX
//                                                                   +----------------------+----------------------+----------------------+----------------------+----------------------+----------------------+
),

// MACROS
[5] = LAYOUT_split_3x6_3(
//---------------------+----------------------+----------------------+----------------------+----------------------+----------------------+----------------------+----------------------+----------------------+----------------------+----------------------+-------------------+
  _______,               VIM_Q,                 VIM_W,                 _______,               _______,               _______,               L_CDHOME,              _______,               _______,               _______,               _______,               TG(1),
//---------------------+----------------------+----------------------+----------------------+----------------------+----------------------+----------------------+----------------------+----------------------+----------------------+----------------------+-------------------+
  _______,               _______,               VIM_SELECT,            _______,               L_FIND,                L_GREP,                P_ANGBRKT,             P_PAREN,               P_CURLY,               P_BRKT,                _______,               _______,
//---------------------+----------------------+----------------------+----------------------+----------------------+----------------------+----------------------+----------------------+----------------------+----------------------+----------------------+-------------------+
  _______,               _______,               _______,               L_GITCOMMIT,           _______,               _______,               _______,               _______,               _______,               _______,               _______,               _______,
//---------------------+----------------------+----------------------+----------------------+----------------------+----------------------+----------------------+----------------------+----------------------+----------------------+----------------------+-------------------+
                                                                       XXXXXXX,               _______,               EEPROM_RESET,          EEPROM_RESET,          _______,               XXXXXXX
//                                                                   +----------------------+----------------------+----------------------+----------------------+----------------------+----------------------+
),

// ASCII ART and RGB
[6] = LAYOUT_split_3x6_3(
//---------------------+----------------------+----------------------+----------------------+----------------------+----------------------+----------------------+----------------------+----------------------+----------------------+----------------------+-------------------+
  RGB_TOG,               RGB_MODE_REVERSE,      RGB_MODE_FORWARD,               _______,               E_ROBOT,               _______,               _______,               _______,               _______,               _______,               _______,               _______,
//---------------------+----------------------+----------------------+----------------------+----------------------+----------------------+----------------------+----------------------+----------------------+----------------------+----------------------+-------------------+
  RGB_MODE_PLAIN,        RGB_HUI,               RGB_SAI,               RGB_VAI,               _______,               _______,               _______,               _______,               _______,               _______,               _______,               _______,
//---------------------+----------------------+----------------------+----------------------+----------------------+----------------------+----------------------+----------------------+----------------------+----------------------+----------------------+-------------------+
  _______,               RGB_HUD,               RGB_SAD,               RGB_VAD,               E_CAT,                 _______,               _______,               _______,               _______,               _______,               _______,               _______,
//---------------------+----------------------+----------------------+----------------------+----------------------+----------------------+----------------------+----------------------+----------------------+----------------------+----------------------+-------------------+
                                                                       XXXXXXX,               _______,               _______,               _______,               _______,               XXXXXXX
//                                                                   +----------------------+----------------------+----------------------+----------------------+----------------------+----------------------+
)

};


#ifdef OLED_DRIVER_ENABLE
oled_rotation_t oled_init_user(oled_rotation_t rotation) {
  if (!is_master) {
    return OLED_ROTATION_180;  // flips the display 180 degrees if offhand
  }
  return rotation;
}

#define L_BASE 0
#define L_LOWER 2
#define L_RAISE 4
#define L_ADJUST 8

void oled_render_layer_state(void) {
    oled_write_P(PSTR("Layer: "), false);
    switch (layer_state) {
        case L_BASE:
            oled_write_ln_P(PSTR("Default"), false);
            break;
        case L_LOWER:
            oled_write_ln_P(PSTR("Lower"), false);
            break;
        case L_RAISE:
            oled_write_ln_P(PSTR("Raise"), false);
            break;
        case L_ADJUST:
        case L_ADJUST|L_LOWER:
        case L_ADJUST|L_RAISE:
        case L_ADJUST|L_LOWER|L_RAISE:
            oled_write_ln_P(PSTR("Adjust"), false);
            break;
    }
}


char keylog_str[24] = {};

const char code_to_name[60] = {
    ' ', ' ', ' ', ' ', 'a', 'b', 'c', 'd', 'e', 'f',
    'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p',
    'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z',
    '1', '2', '3', '4', '5', '6', '7', '8', '9', '0',
    'R', 'E', 'B', 'T', '_', '-', '=', '[', ']', '\\',
    '#', ';', '\'', '`', ',', '.', '/', ' ', ' ', ' '};

void set_keylog(uint16_t keycode, keyrecord_t *record) {
  char name = ' ';
    if ((keycode >= QK_MOD_TAP && keycode <= QK_MOD_TAP_MAX) ||
        (keycode >= QK_LAYER_TAP && keycode <= QK_LAYER_TAP_MAX)) { keycode = keycode & 0xFF; }
  if (keycode < 60) {
    name = code_to_name[keycode];
  }

  // update keylog
  snprintf(keylog_str, sizeof(keylog_str), "%dx%d, k%2d : %c",
           record->event.key.row, record->event.key.col,
           keycode, name);
}

void oled_render_keylog(void) {
    oled_write(keylog_str, false);
}

void render_bootmagic_status(bool status) {
    /* Show Ctrl-Gui Swap options */
    static const char PROGMEM logo[][2][3] = {
        {{0x97, 0x98, 0}, {0xb7, 0xb8, 0}},
        {{0x95, 0x96, 0}, {0xb5, 0xb6, 0}},
    };
    if (status) {
        oled_write_ln_P(logo[0][0], false);
        oled_write_ln_P(logo[0][1], false);
    } else {
        oled_write_ln_P(logo[1][0], false);
        oled_write_ln_P(logo[1][1], false);
    }
}

void oled_render_logo(void) {
    static const char PROGMEM crkbd_logo[] = {
        0x80, 0x81, 0x82, 0x83, 0x84, 0x85, 0x86, 0x87, 0x88, 0x89, 0x8a, 0x8b, 0x8c, 0x8d, 0x8e, 0x8f, 0x90, 0x91, 0x92, 0x93, 0x94,
        0xa0, 0xa1, 0xa2, 0xa3, 0xa4, 0xa5, 0xa6, 0xa7, 0xa8, 0xa9, 0xaa, 0xab, 0xac, 0xad, 0xae, 0xaf, 0xb0, 0xb1, 0xb2, 0xb3, 0xb4,
        0xc0, 0xc1, 0xc2, 0xc3, 0xc4, 0xc5, 0xc6, 0xc7, 0xc8, 0xc9, 0xca, 0xcb, 0xcc, 0xcd, 0xce, 0xcf, 0xd0, 0xd1, 0xd2, 0xd3, 0xd4,
        0};
    oled_write_P(crkbd_logo, false);
}

void oled_task_user(void) {
    if (is_master) {
        oled_render_layer_state();
        oled_render_keylog();
    } else {
        oled_render_logo();
    }
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

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (record->event.pressed) {
        set_keylog(keycode, record);
    }

    ////// Start RGB backlight timeout
    if (led_on == false) {
        rgblight_enable_noeeprom();
        led_on = true;
    }
    idle_timer = timer_read();
    halfmin_counter = 0;
    ////// End RGB backlight timeout

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
    case P_ANGBRKT:
        if (record->event.pressed) {
            SEND_STRING("<>"SS_TAP(X_LEFT));
        } else {
            // when keycode is released
        }
        break;
    case P_PAREN:
        if (record->event.pressed) {
            SEND_STRING("()"SS_TAP(X_LEFT));
        } else {
            // when keycode is released
        }
        break;
    case P_CURLY:
        if (record->event.pressed) {
            SEND_STRING("{}"SS_TAP(X_LEFT));
        } else {
            // when keycode is released
        }
        break;
    case P_BRKT:
        if (record->event.pressed) {
            SEND_STRING("[]"SS_TAP(X_LEFT));
        } else {
            // when keycode is released
        }
        break;
    case E_ROBOT:
        if (record->event.pressed) {
            SEND_STRING("d[o_0]b");
        } else {
            // when keycode is released
        }
        break;
    case E_CAT:
        if (record->event.pressed) {
            SEND_STRING("=^..^=");
        } else {
            // when keycode is released
        }
        break;
    }

    return true;
}
#endif // OLED_DRIVER_ENABLE
