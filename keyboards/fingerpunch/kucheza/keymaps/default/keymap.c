#include QMK_KEYBOARD_H

// Defines names for use in layer keycodes and the keymap
enum layer_names {
    _QWERTY,
    _COLEMAK,
    _RGB
};

// +-------+-------+-------+-------+-------+-------+-------+
// |       |       |       |       |       |       |       |
// +-------+-------+-------+-------+-------+-------+-------+
// |       |       |       |       |       |       |       |
// +-------+-------+-------+-------+-------+-------+-------+
// |       |       |       |       |       |       |       |
// +-------+-------+-------+-------+-------+-------+-------+           +-------+
// |       |       |       |       |       |       |                   |       |
// +-------+-------+-------+-------+-------+-------+-------+   +-------+-------+-------+
// |       |       |       |       |       |       |       |   |       |       |       |    <--- 5 way nav
// +-------+-------+-------+       +-------+-------+-------+   +-------+-------+-------+
//                                                                     |       |
//                                                                     +-------+
//                                 +-------+-------+-------+
//                                 |       |       |       |   <--- 3 way thumb
//                                 +-------+-------+-------+

//    ----.
//         '..
//            '
//        +-------+
//        |       |
//        |       |    <---- foot pedal via TRRS
//        |       |
//        +-------+


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {


[_QWERTY] = LAYOUT_kucheza(
    KC_ESC,    KC_1,      KC_2,      KC_3,      KC_4,      KC_5,      KC_6,
    KC_TAB,    KC_Q,      KC_W,      KC_E,      KC_R,      KC_T,      KC_LBRC,
    KC_CAPS,   KC_A,      KC_S,      KC_D,      KC_F,      KC_G,      KC_LCBR,
    KC_LSFT,   KC_Z,      KC_X,      KC_C,      KC_V,      KC_B,                           KC_VOLU,
    KC_LCTL,   KC_LGUI,   KC_LALT,              KC_DEL,    MO(_RGB),  KC_SPC,     KC_MPRV, KC_MPLY, KC_MNXT,
                                                                                           KC_VOLD,
                                                KC_VOLD,   KC_MUTE,   KC_VOLU,
    KC_LSFT
),

[_COLEMAK] = LAYOUT_kucheza(
    KC_ESC,    KC_1,      KC_2,      KC_3,      KC_4,      KC_5,      KC_6,
    KC_TAB,    KC_Q,      KC_W,      KC_F,      KC_P,      KC_B,      KC_LBRC,
    KC_CAPS,   KC_A,      KC_R,      KC_S,      KC_T,      KC_G,      KC_LCBR,
    KC_LSFT,   KC_Z,      KC_X,      KC_C,      KC_D,      KC_V,                           KC_VOLU,
    KC_LCTL,   KC_LGUI,   KC_LALT,              KC_DEL,    MO(_RGB),  KC_SPC,     KC_MPRV, KC_MPLY, KC_MNXT,
                                                                                           KC_VOLD,
                                                KC_VOLD,   KC_MUTE,   KC_VOLU,
    KC_LSFT
),

[_RGB] =  LAYOUT_kucheza(
    QK_BOOT,   KC_F1,        KC_F2,        KC_F3,        KC_F4,        KC_F5,        _______,
    _______,   UG_TOGG,      UG_PREV,     UG_NEXT,      _______,      TG(_QWERTY),  _______,
    _______,   UG_SPDU,      UG_HUEU,      UG_SATU,      UG_VALU,      KC_END,       _______,
    _______,   UG_SPDD,      UG_HUED,      UG_SATD,      UG_VALD,      TG(_COLEMAK),                       _______,
    _______,   _______,      _______,                    _______,      _______,      _______,     _______, _______, _______,
                                                                                                           _______,
                                                         _______,      _______,      _______,
    _______
)
};
