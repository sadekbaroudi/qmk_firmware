#include QMK_KEYBOARD_H

// Defines names for use in layer keycodes and the keymap
enum layer_names {
    _ABCD,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Qwerty
 *
 * ,-----------------------------------------.             ,-----------------------------------------.
 * |  ESC |   Q  |   W  |   E  |   R  |   T  |             |   Y  |   U  |   I  |   O  |   P  |BckSpc|
 * |------+------+------+------+------+------|   ,------.  |------+------+------+------+------+------|
 * |  TAB |   A  |   S  |   D  |   F  |   G  |   |ALTTAB|  |   H  |   J  |   K  |   L  |   ;  |  '   |
 * |------+------+------+------+------+------|   `------'  |------+------+------+------+------+------|
 * |  SFT |   Z  |   X  |   C  |   V  |   B  |             |   N  |   M  |   ,  |   .  |   /  | SFT  |
 * `-----------------------------------------'             `-----------------------------------------'
 *          ,------.        ,--------------------.    ,--------------------.        ,------.
 *          | MUTE |        |   \  | Enter| LOWER|    | RAISE| Space| Del  |        | DELW |
 *          `------'        `--------------------'    `--------------------.        `------'
 */

// Default config uses home row mods. So hold each of the keys on the home row to use ctrl, gui, alt, or shift
[_ABCD] = LAYOUT_stemcell_jumper_tester(
  KC_A, KC_B,
  KC_C, KC_D
),

};
