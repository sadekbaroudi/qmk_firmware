#include QMK_KEYBOARD_H

// Defines names for use in layer keycodes and the keymap
enum layer_names {
    _QWERTY,
    _COLEMAK,
    _LOWER,
    _RAISE,
    _ADJUST,
    _MOUSE
};

#define LOWER MO(_LOWER)
#define RAISE MO(_RAISE)


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* 
 *  Key layout visual aid
 *
 * ,-----------------------------------------.                                          ,-----------------------------------------.
 * |  ESC |   Q  |   W  |   E  |   R  |   T  |                                          |   Y  |   U  |   I  |   O  |   P  |BckSpc|
 * |------+------+------+------+------+------|                                          |------+------+------+------+------+------|
 * |  TAB |   A  |   S  |   D  |   F  |   G  |                                          |   H  |   J  |   K  |   L  |   ;  |  '   |
 * |------+------+------+------+------+------|                                          |------+------+------+------+------+------|
 * |  SFT |   Z  |   X  |   C  |   V  |   B  |                                          |   N  |   M  |   ,  |   .  |   /  | SFT  |
 * `-----------------------------------------'                                          `-----------------------------------------'
 *                          ,--------------------.      ,--------------------.      ,--------------------.
 *                          |   \  | Enter| LOWER|      | RAISE| Space| Del  |      | RAISE| Space| Del  |
 *                          `--------------------'      `--------------------'      `--------------------'
 *          ,------.        ,--------------------.                                  ,--------------------.        ,------.
 *          |Vol Up|        |Mouse1|Mouse3|Mouse2|                                  |Vol Up| Mute |Vol Dn|        |Vol Up|
 *   ,------+------+------. `--------------------'                                  `--------------------' ,------+------+------.
 *   | Prev | Play | Next |   3 way thumb rocker                                      3 way thumb rocker   | Prev | Play | Next |  5 way switch
 *   `------+------+------'                                                                                `------+------+------'
 *          |Vol Dn|                                                                                              |Vol Dn|
 *          `------'                                                                                              `------'
 */

// Default config uses home row mods. So hold each of the keys on the home row to use ctrl, gui, alt, or shift
[_QWERTY] = LAYOUT_vulpes_majora(
  KC_ESC,  KC_Q,         KC_W,         KC_E,         KC_R,         KC_T,                                                      KC_Y,    KC_U,         KC_I,         KC_O,         KC_P,             KC_BSPC,
  KC_TAB,  LCTL_T(KC_A), LGUI_T(KC_S), LALT_T(KC_D), LSFT_T(KC_F), KC_G,                                                      KC_H,    RSFT_T(KC_J), RALT_T(KC_K), RGUI_T(KC_L), RCTL_T(KC_SCLN),  KC_QUOT,
  KC_LSFT, KC_Z,         KC_X,         KC_C,         KC_V,         KC_B,                                                      KC_N,    KC_M,         KC_COMM,      KC_DOT,       KC_SLSH,          KC_RSFT,
                                     KC_BSLS,        KC_ENT,       LOWER,        MS_BTN3,     MS_BTN1,   MS_BTN2,    RAISE,   KC_SPC,       KC_DEL,
           KC_VOLU,                  MS_BTN1,     MS_BTN3,   MS_BTN2,                                                KC_VOLD, KC_MUTE,      KC_VOLU,                    KC_VOLU,
  KC_MPRV, KC_MPLY, KC_MNXT,                                                                                                                                            KC_MPRV, KC_MPLY, KC_MNXT,
           KC_VOLD,                                                                                                                                                              KC_VOLD
),

// Default config uses home row mods. So hold each of the keys on the home row to use ctrl, gui, alt, or shift
[_COLEMAK] = LAYOUT_vulpes_majora(
  KC_ESC,  KC_Q,         KC_W,         KC_F,         KC_P,         KC_B,                                                      KC_J,    KC_L,         KC_U,         KC_Y,         KC_SCLN,          KC_BSPC,
  KC_TAB,  LCTL_T(KC_A), LGUI_T(KC_R), LALT_T(KC_S), LSFT_T(KC_T), KC_G,                                                      KC_M,    RSFT_T(KC_N), RALT_T(KC_E), RGUI_T(KC_I), RCTL_T(KC_O),     KC_QUOT,
  KC_LSFT, KC_Z,         KC_X,         KC_C,         KC_D,         KC_V,                                                      KC_K,    KC_H,         KC_COMM,      KC_DOT,       KC_SLSH,          KC_RSFT,
                                     KC_BSLS,        KC_ENT,       LOWER,        MS_BTN3,     MS_BTN1,   MS_BTN2,    RAISE,   KC_SPC,       KC_DEL,
           KC_VOLU,                  MS_BTN1,     MS_BTN3,   MS_BTN2,                                                KC_VOLD, KC_MUTE,      KC_VOLU,                    KC_VOLU,
  KC_MPRV, KC_MPLY, KC_MNXT,                                                                                                                                            KC_MPRV, KC_MPLY, KC_MNXT,
           KC_VOLD,                                                                                                                                                              KC_VOLD
),

[_RAISE] = LAYOUT_vulpes_majora(
  KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                                KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    _______,
  KC_HOME, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_TAB,                              _______, KC_MINS, KC_EQL,  KC_LBRC, KC_RBRC, _______,
  _______, _______, KC_PGDN, KC_PGUP, _______, _______,                             _______, _______, _______, _______, _______, _______,
                             _______, _______, _______,  _______, _______, _______, _______, _______, _______,
           _______,          _______, _______, _______,                             _______, _______, _______,          _______,
  _______, _______, _______,                                                                                   _______, _______, _______,
           _______,                                                                                                     _______
),

[_LOWER] = LAYOUT_vulpes_majora(
  _______, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC,                             KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, _______,
  _______, _______, _______, _______, _______,  EE_CLR,                             _______, KC_UNDS, KC_PLUS, KC_LCBR, KC_RCBR, _______,
  _______, KC_CAPS, _______, _______, QK_RBT,  QK_BOOT,                             _______, _______, _______, KC_PIPE,  KC_DQT, _______,
                             _______, _______, _______,  _______, _______, _______, _______, _______, _______,
           _______,          _______, _______, _______,                             _______, _______, _______,          _______,
  _______, _______, _______,                                                                                   _______, _______, _______,
           _______,                                                                                                     _______
),

[_ADJUST] =  LAYOUT_vulpes_majora(
  _______, UG_TOGG, UG_PREV, UG_NEXT, _______, TO(_QWERTY),                         KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   _______,
  _______, UG_SPDU, UG_HUEU,  UG_SATU, UG_VALU, TO(_COLEMAK),                        KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  _______,
  _______, UG_SPDD, UG_HUED,  UG_SATD, UG_VALD, _______,                             KC_F11,  KC_F12,  _______, _______, QK_BOOT, _______,
                              _______, _______, _______,  _______, _______, _______, _______, _______, _______,
           _______,           _______, _______, _______,                             _______, _______, _______,          _______,
  _______, _______, _______,                                                                                    _______, _______, _______,
           _______,                                                                                                      _______
), 

[_MOUSE] =  LAYOUT_vulpes_majora(
  _______, _______, MS_WHLU, _______, MS_WHLD, _______,                             _______, _______, _______, _______, _______, _______,
  _______, MS_WHLL, MS_BTN3, MS_BTN2, MS_BTN1, MS_WHLR,                             _______, _______, _______, _______, _______, _______,
  _______, _______, _______, _______, _______, _______,                             _______, _______, _______, _______, _______, _______,
                             _______, _______, _______,  _______, _______, _______, _______, _______, _______,
           _______,          _______, _______, _______,                             _______, _______, _______,          _______,
  _______, _______, _______,                                                                                   _______, _______, _______,
           _______,                                                                                                     _______
)
};

layer_state_t layer_state_set_user(layer_state_t state) {
  return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}
