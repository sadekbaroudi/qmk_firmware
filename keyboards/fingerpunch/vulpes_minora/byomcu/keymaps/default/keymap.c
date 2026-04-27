#include QMK_KEYBOARD_H

// Defines names for use in layer keycodes and the keymap
enum layer_names {
    _QWERTY,
    _COLEMAK,
    _LOWER,
    _RAISE,
    _ADJUST
};

enum custom_keycodes {
    QWERTY = SAFE_RANGE,
    LOWER,
    RAISE,
    ADJUST
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {


/* Qwerty
 *
 * ,----------------------------------.           ,----------------------------------.
 * |   Q  |   W  |   E  |   R  |   T  |           |   Y  |   U  |   I  |   O  |   P  |
 * |------+------+------+------+------|           |------+------+------+------+------|
 * |   A  |   S  |   D  |   F  |   G  |           |   H  |   J  |   K  |   L  |   ;  |
 * |------+------+------+------+------|           |------+------+------+------+------|
 * |   Z  |   X  |   C  |   V  |   B  |           |   N  |   M  |   ,  |   .  |   /  |
 * `----------------------------------'           `----------------------------------'
 *        ,------.  ,--------------------.    ,--------------------. ,------.
 *        | MUTE |  | LOWER| Enter|  Del |    |BckSpc| Space| RAISE| | MUTE |
 *        `------'  `--------------------'    `--------------------. `------'
 */

// Default config uses home row mods. So hold each of the keys on the home row to use ctrl, gui, alt, or shift
[_QWERTY] = LAYOUT_split_3x5_4(
  KC_Q,         KC_W,         KC_E,         KC_R,         KC_T,         KC_Y,    KC_U,         KC_I,         KC_O,         KC_P,
  LCTL_T(KC_A), LGUI_T(KC_S), LALT_T(KC_D), LSFT_T(KC_F), KC_G,         KC_H,    RSFT_T(KC_J), RALT_T(KC_K), RGUI_T(KC_L), RCTL_T(KC_SCLN),
  KC_Z,         KC_X,         KC_C,         KC_V,         KC_B,         KC_N,    KC_M,         KC_COMM,      KC_DOT,       KC_SLSH,
                KC_MUTE,      LOWER,        KC_ENT,       KC_DEL,       KC_BSPC, KC_SPC,       RAISE,        KC_MUTE
),

/* Colemak
 *
 * ,----------------------------------.           ,----------------------------------.
 * |   Q  |   W  |   F  |   P  |   B  |           |   J  |   L  |   U  |   Y  |   ;  |
 * |------+------+------+------+------|           |------+------+------+------+------|
 * |   A  |   R  |   S  |   T  |   G  |           |   M  |   N  |   E  |   I  |   O  |
 * |------+------+------+------+------|           |------+------+------+------+------|
 * |   Z  |   X  |   C  |   D  |   V  |           |   K  |   H  |   ,  |   .  |   /  |
 * `-------------+--------------------'           `----------------------------------'
 *        ,------.  ,--------------------.    ,--------------------.  ,------.
 *        | MUTE |  | LOWER| Enter|   '  |    |BckSpc| Space| RAISE|  | MUTE |
 *        `------'  `--------------------'    `--------------------.  `------'
 */

// Default config uses home row mods. So hold each of the keys on the home row to use ctrl, gui, alt, or shift
[_COLEMAK] = LAYOUT_split_3x5_4(
  KC_Q,         KC_W,         KC_F,         KC_P,         KC_B,         KC_J,    KC_L,         KC_U,         KC_Y,         KC_SCLN,
  LCTL_T(KC_A), LGUI_T(KC_R), LALT_T(KC_S), LSFT_T(KC_T), KC_G,         KC_M,    RSFT_T(KC_N), RALT_T(KC_E), RGUI_T(KC_I), RCTL_T(KC_O),
  KC_Z,         KC_X,         KC_C,         KC_D,         KC_V,         KC_K,    KC_H,         KC_COMM,      KC_DOT,       KC_SLSH,
                KC_MUTE,      LOWER,        KC_ENT,       KC_QUOT,      KC_BSPC, KC_SPC,       RAISE,        KC_MUTE
),

/* Raise
 *
 * ,----------------------------------.           ,----------------------------------.
 * |   1  |   2  |   3  |   4  |   5  |           |   6  |   7  |   8  |   9  |   0  |
 * |------+------+------+------+------|           |------+------+------+------+------|
 * | Left | Down |  Up  | Right| Tab  |           |      |   -  |   =  |   [  |   ]  |
 * |------+------+------+------+------|           |------+------+------+------+------|
 * |  Ctrl|   `  |  GUI |  Alt |      |           |      |      |      |   \  |   '  |
 * `----------------------------------'           `----------------------------------'
 *        ,------.  ,--------------------.    ,--------------------.  ,------.
 *        | MUTE |  | LOWER|      |      |    |      |      | RAISE|  | MUTE |
 *        `------'  `--------------------'    `--------------------.  `------'
 */
[_RAISE] = LAYOUT_split_3x5_4(
  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,         KC_6,    KC_7,    KC_8,    KC_9,    KC_0,
  KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_TAB,       _______, KC_MINS, KC_EQL,  KC_LBRC, KC_RBRC,
  KC_LCTL, KC_GRV,  KC_LGUI, KC_LALT, _______,      _______, _______, _______, KC_BSLS, KC_QUOT,
           _______, _______, _______, _______,      _______, _______, _______, _______
),

/* Lower
 *
 * ,----------------------------------.           ,----------------------------------.
 * |   !  |   @  |   #  |   $  |   %  |           |   ^  |   &  |   *  |   (  |   )  |
 * |------+------+------+------+------|           |------+------+------+------+------|
 * |  Esc |      |      |      |      |           |      |   _  |   +  |   {  |   }  |
 * |------+------+------+------+------|           |------+------+------+------+------|
 * |  Caps|   ~  |      |Reset |Btldr |           |      |      |      |   |  |   '  |
 * `----------------------------------'           `----------------------------------'
 *        ,------.  ,--------------------.    ,--------------------.  ,------.
 *        | MUTE |  | LOWER|      |      |    |  Del |      | RAISE|  | MUTE |
 *        `------'  `--------------------'    `--------------------.  `------'
 */
[_LOWER] = LAYOUT_split_3x5_4(
  KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC,      KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN,
  KC_ESC,  _______, _______, _______, _______,      _______, KC_UNDS, KC_PLUS, KC_LCBR, KC_RCBR,
  KC_CAPS, KC_TILD, _______, QK_RBT,  QK_BOOT,      _______, _______, _______, KC_PIPE,  KC_DQT,
           _______, _______, _______, _______,      KC_DEL,  _______, _______, _______
),

/* Adjust (Lower + Raise)
 *
 * ,----------------------------------.           ,----------------------------------.
 * | RGB_T| RGB_R| RGB_F|      |QWERTY|           |   F1 |  F2  |  F3  |  F4  |  F5  |
 * |------+------+------+------+------|           |------+------+------+------+------|
 * | SPD_I| HUE_I| SAT_I| VAL_I|COLEMK|           |   F6 |  F7  |  F8  |  F9  |  F10 |
 * |------+------+------+------+------|           |------+------+------+------+------|
 * | SPD_D| HUE_D| SAT_D| VAL_D|      |           |  F11 |  F12 |      |Reset | Btldr|
 * `----------------------------------'           `----------------------------------'
 *        ,------.  ,--------------------.    ,--------------------.  ,------.
 *        | MUTE |  | LOWER|      |      |    |      |      | RAISE|  | MUTE |
 *        `------'  `--------------------'    `--------------------.  `------'
 */
[_ADJUST] =  LAYOUT_split_3x5_4(
  UG_TOGG, UG_PREV, UG_NEXT, _______, TO(_QWERTY),       KC_F1,   KC_F2,   KC_F3,   KC_F4,    KC_F5,
  UG_SPDU, UG_HUEU,  UG_SATU, UG_VALU, TO(_COLEMAK),      KC_F6,   KC_F7,   KC_F8,   KC_F9,    KC_F10,
  UG_SPDD, UG_HUED,  UG_SATD, UG_VALD, _______,           KC_F11,  KC_F12,  _______, QK_RBT,   QK_BOOT,
           _______,  _______, _______, _______,           _______, _______, _______, _______
)
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case LOWER:
            if (record->event.pressed) {
                layer_on(_LOWER);
                update_tri_layer(_LOWER, _RAISE, _ADJUST);
            } else {
                layer_off(_LOWER);
                update_tri_layer(_LOWER, _RAISE, _ADJUST);
            }
            return false;
            break;
        case RAISE:
            if (record->event.pressed) {
                layer_on(_RAISE);
                update_tri_layer(_LOWER, _RAISE, _ADJUST);
            } else {
                layer_off(_RAISE);
                update_tri_layer(_LOWER, _RAISE, _ADJUST);
            }
            return false;
            break;
        case ADJUST:
            if (record->event.pressed) {
                layer_on(_ADJUST);
            } else {
                layer_off(_ADJUST);
            }
            return false;
            break;
        default:
            break;
    }

    return true;
}