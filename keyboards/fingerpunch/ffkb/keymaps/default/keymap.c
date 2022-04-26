#include QMK_KEYBOARD_H

#ifdef ENCODER_ENABLE
bool is_alt_tab_active = false;
uint16_t alt_tab_timer = 0;
#endif

// Defines names for use in layer keycodes and the keymap
enum layer_names {
    _QWERTY,
    _COLEMAK,
    _LOWER,
    _RAISE,
    _ADJUST
};

#define LOWER MO(_LOWER)
#define RAISE MO(_RAISE)


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
[_QWERTY] = LAYOUT_ffkb(
  KC_ESC,  KC_Q,         KC_W,         KC_E,         KC_R,         KC_T,         KC_Y,    KC_U,         KC_I,         KC_O,         KC_P,             KC_BSPC,
  KC_TAB,  LCTL_T(KC_A), LGUI_T(KC_S), LALT_T(KC_D), LSFT_T(KC_F), KC_G,         KC_H,    RSFT_T(KC_J), RALT_T(KC_K), RGUI_T(KC_L), RCTL_T(KC_SCLN),  KC_QUOT,
  KC_LSFT, KC_Z,         KC_X,         KC_C,         KC_V,         KC_B,         KC_N,    KC_M,         KC_COMM,      KC_DOT,       KC_SLSH,          KC_RSFT,
                       KC_MUTE,      KC_BSLS,        KC_ENT,       LOWER,        RAISE,   KC_SPC,       KC_DEL,       LCTL(KC_BSPC),
                                                                        LALT(KC_TAB)
),

/* Colemak-dh
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
[_COLEMAK] = LAYOUT_ffkb(
  KC_ESC,  KC_Q,         KC_W,         KC_F,         KC_P,         KC_B,         KC_J,    KC_L,         KC_U,         KC_Y,         KC_SCLN,          KC_BSPC,
  KC_TAB,  LCTL_T(KC_A), LGUI_T(KC_R), LALT_T(KC_S), LSFT_T(KC_T), KC_G,         KC_M,    RSFT_T(KC_N), RALT_T(KC_E), RGUI_T(KC_I), RCTL_T(KC_O),     KC_QUOT,
  KC_LSFT, KC_Z,         KC_X,         KC_C,         KC_D,         KC_V,         KC_K,    KC_H,         KC_COMM,      KC_DOT,       KC_SLSH,          KC_RSFT,
                       KC_MUTE,      KC_BSLS,        KC_ENT,       LOWER,        RAISE,   KC_SPC,       KC_DEL,       LCTL(KC_BSPC),
                                                                        LALT(KC_TAB)
),


/* Raise
 *
 * ,-----------------------------------------.             ,-----------------------------------------.
 * |  `   |   1  |   2  |   3  |   4  |   5  |             |   6  |   7  |   8  |   9  |   0  |      |
 * |------+------+------+------+------+------|   ,------.  |------+------+------+------+------+------|
 * | Home | Left | Down |  Up  | Right| End  |   |ALTTAB|  |      |   -  |   =  |   [  |   ]  |      |
 * |------+------+------+------+------+------|   `------'  |------+------+------+------+------+------|
 * |      |      | PgDn | PgUp |      |      |             |      |      |      |      |      |      |
 * `-----------------------------------------'             `-----------------------------------------'
 *          ,------.        ,--------------------.    ,--------------------.        ,------.
 *          | MUTE |        |   \  | Enter| LOWER|    | RAISE| Space| Del  |        | DELW |
 *          `------'        `--------------------'    `--------------------.        `------'
 */

[_RAISE] = LAYOUT_ffkb(
  KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,         KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    _______,
  KC_HOME, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_TAB,       _______, KC_MINS, KC_EQL,  KC_LBRC, KC_RBRC, _______,
  _______, _______, KC_PGDN, KC_PGUP, _______, _______,      _______, _______, _______, _______, _______, _______,
                    _______, _______, _______, _______,      _______, _______, _______, _______,
                                                      _______
),



/* Raise
 *
 * ,-----------------------------------------.             ,-----------------------------------------.
 * |      |   !  |   @  |   #  |   $  |   %  |             |   ^  |   &  |   *  |   (  |   )  |      |
 * |------+------+------+------+------+------|   ,------.  |------+------+------+------+------+------|
 * |      |      |      |      |      |      |   |ALTTAB|  |      |   _  |   +  |   {  |   }  |      |
 * |------+------+------+------+------+------|   `------'  |------+------+------+------+------+------|
 * |      |  Caps|      |      |      |      |             |      |      |      |   |  |   "  |      |
 * `-----------------------------------------'             `-----------------------------------------'
 *          ,------.        ,--------------------.    ,--------------------.        ,------.
 *          | MUTE |        |   \  | Enter| LOWER|    | RAISE| Space| Del  |        | DELW |
 *          `------'        `--------------------'    `--------------------.        `------'
 */

[_RAISE] = LAYOUT_ffkb(
  KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,         KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    _______,
  KC_HOME, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_TAB,       _______, KC_MINS, KC_EQL,  KC_LBRC, KC_RBRC, _______,
  _______, _______, KC_PGDN, KC_PGUP, _______, _______,      _______, _______, _______, _______, _______, _______,
                    _______, _______, _______, _______,      _______, _______, _______, _______,
                                                      _______
),
/* Lower
 *
 * ,-----------------------------------------.             ,-----------------------------------------.
 * |      |   !  |   @  |   #  |   $  |   %  |             |   ^  |   &  |   *  |   (  |   )  |      |
 * |------+------+------+------+------+------|   ,------.  |------+------+------+------+------+------|
 * |      |      |      |      |      |      |   |ALTTAB|  |      |   _  |   +  |   {  |   }  |      |
 * |------+------+------+------+------+------|   `------'  |------+------+------+------+------+------|
 * |      |  Caps|      |      |      |      |             |      |      |      |   |  |   "  |      |
 * `-----------------------------------------'             `-----------------------------------------'
 *          ,------.        ,--------------------.    ,--------------------.        ,------.
 *          | MUTE |        |   \  | Enter| LOWER|    | RAISE| Space| Del  |        | DELW |
 *          `------'        `--------------------'    `--------------------.        `------'
 */
[_LOWER] = LAYOUT_ffkb(
  _______, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC,      KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, _______,
  _______, _______, _______, _______, _______, _______,      _______, KC_UNDS, KC_PLUS, KC_LCBR, KC_RCBR, _______,
  _______, KC_CAPS, _______, _______, _______, _______,      _______, _______, _______, KC_PIPE,  KC_DQT, _______,
                    _______, _______, _______, _______,      _______, _______, _______, _______,
                                                      _______
),

/* Adjust (Lower + Raise)

 * ,-----------------------------------------.             ,-----------------------------------------.
 * |      | RGB_T| RGB_R| RGB_F|      |QWERTY|             |   F1 |  F2  |  F3  |  F4  |  F5  |      |
 * |------+------+------+------+------+------|   ,------.  |------+------+------+------+------+------|
 * |      | SPD_I| HUE_I| SAT_I| VAL_I|COLEMK|   |ALTTAB|  |   F6 |  F7  |  F8  |  F9  |  F10 |      |
 * |------+------+------+------+------+------|   `------'  |------+------+------+------+------+------|
 * |      | SPD_D| HUE_D| SAT_D| VAL_D|      |             |  F11 |  F12 |      |      | Reset|      |
 * `-----------------------------------------'             `-----------------------------------------'
 *          ,------.        ,--------------------.    ,--------------------.        ,------.
 *          | MUTE |        |   \  | Enter| LOWER|    | RAISE| Space| Del  |        | DELW |
 *          `------'        `--------------------'    `--------------------.        `------'
 */
[_ADJUST] =  LAYOUT_ffkb(
  _______, RGB_TOG, RGB_RMOD, RGB_MOD, _______, TO(_QWERTY),       KC_F1,   KC_F2,   KC_F3,   KC_F4,    KC_F5,  _______,
  _______, RGB_SPI, RGB_HUI,  RGB_SAI, RGB_VAI, TO(_COLEMAK),      KC_F6,   KC_F7,   KC_F8,   KC_F9,    KC_F10, _______,
  _______, RGB_SPD, RGB_HUD,  RGB_SAD, RGB_VAD, _______,           KC_F11,  KC_F12,  _______, _______,  RESET,  _______,
                     _______, _______, _______, _______,           _______, _______, _______, _______,
                                                         _______
)
};

layer_state_t layer_state_set_user(layer_state_t state) {
  return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}

#ifdef ENCODER_ENABLE
void press_super_alt_tab(bool shift) {
    if (shift) {
        register_code(KC_LSHIFT);
    }
    if (!is_alt_tab_active) {
        is_alt_tab_active = true;
        register_code(KC_LALT);
    }
    alt_tab_timer = timer_read();
    tap_code(KC_TAB);
    if (shift) {
        unregister_code(KC_LSHIFT);
    }
}

bool encoder_update_user(uint8_t index, bool clockwise) {
    // default behavior if undefined
    if (index == 0) {
        // Conditional to reverse the direction of encoder number 1
        // The reason I have this is that for some of my boards, it supports two different types of encoders, and they may differ in direction
        #ifdef ENCODERS_A_REVERSE
        if (!clockwise) {
        #else
        if (clockwise) {
        #endif
            tap_code(KC_VOLU);
        } else {
            tap_code(KC_VOLD);
        }
    }
    else if (index == 1) {
      // Conditional to reverse the direction of encoder number 1
      // The reason I have this is that for some of my boards, it supports two different types of encoders, and they may differ in direction
      #ifdef ENCODERS_B_REVERSE
      if (!clockwise) {
      #else
      if (clockwise) {
      #endif
        tap_code16(C(KC_RGHT));
      }
      else{
        tap_code16(C(KC_LEFT));
      }
    }
    else if (index == 2) {
      #ifdef ENCODERS_C_REVERSE
      if (!clockwise) {
      #else
      if (clockwise) {
      #endif
        press_super_alt_tab(true);
      } else {
        press_super_alt_tab(false);
      }
    }

    return true;
}
#endif

#ifdef OLED_ENABLE


oled_rotation_t oled_init_user(oled_rotation_t rotation) {
      return OLED_ROTATION_180;
}


// Commenting out logo as it takes up a lot of space :(
static void render_logo(void) {
    // ffkb logo, 128x32px
    static const char PROGMEM ffkb_logo[] = {
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x10, 0xf0, 0xf0, 0xf0, 0xf0, 0xf0, 0xf0, 0xf0, 
    0xf0, 0x10, 0x10, 0x10, 0x90, 0x30, 0x30, 0x60, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xc0, 0xf0, 0xf8, 0xfc, 0x3c, 0x3c, 0x38, 0x70, 
    0x70, 0xe0, 0xe0, 0xc0, 0xc0, 0x80, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 
    0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0x80, 0xc0, 0xc0, 0xe0, 0xe0, 0x70, 
    0x70, 0x38, 0x3c, 0x3c, 0xfc, 0xf8, 0xf0, 0xc0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x00, 0x00, 0x10, 0xf0, 0xf0, 0xf0, 0xf0, 0xf0, 0xf0, 0xf0, 0xf0, 0x10, 0x00, 
    0x80, 0x90, 0xd0, 0xf0, 0x30, 0x30, 0x10, 0x10, 0x10, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x20, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 
    0x3f, 0x21, 0x01, 0x01, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x80, 0xc0, 0xe7, 0xff, 0x7f, 0x7f, 0xbc, 0x9e, 0x8e, 0x8f, 
    0x87, 0x87, 0x83, 0x83, 0x81, 0x81, 0x81, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x81, 0x81, 0x81, 0x83, 0x83, 0x87, 0x87, 
    0x8f, 0x8e, 0x9e, 0xbc, 0x7f, 0x7f, 0xff, 0xe7, 0xc0, 0x80, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x00, 0x00, 0x20, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0x23, 0x07, 
    0x0f, 0x3f, 0x3f, 0x3f, 0x3f, 0x3e, 0x3c, 0x38, 0x30, 0x20, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x04, 0xfc, 0xfc, 0xfc, 0xfc, 0xfc, 0xfc, 0xfc, 
    0xfc, 0x44, 0x44, 0x44, 0xe4, 0x0c, 0x0c, 0x18, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
    0x02, 0x06, 0x06, 0x07, 0x0f, 0x0f, 0x0f, 0x1f, 0x1f, 0x1b, 0x3b, 0x3b, 0x73, 0x73, 0x73, 0xe3, 
    0xe3, 0xdf, 0xdf, 0xdf, 0x8b, 0x83, 0x03, 0x03, 0x07, 0x1f, 0xfe, 0xfc, 0xf8, 0xe0, 0x00, 0x00, 
    0x00, 0x00, 0xe0, 0xf8, 0xfc, 0xfe, 0x1f, 0x07, 0x03, 0x03, 0x83, 0x8b, 0xdf, 0xdf, 0xdf, 0xe3, 
    0xe3, 0x73, 0x73, 0x73, 0x3b, 0x3b, 0x1b, 0x1f, 0x1f, 0x0f, 0x0f, 0x0f, 0x07, 0x06, 0x06, 0x02, 
    0x00, 0x00, 0x00, 0x00, 0x00, 0x04, 0xfc, 0xfc, 0xfc, 0xfc, 0xfc, 0xfc, 0xfc, 0xfc, 0x44, 0x44, 
    0x44, 0xfc, 0xfc, 0xfc, 0xfc, 0xf8, 0xb8, 0xb8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x08, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 
    0x0f, 0x08, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x01, 0x01, 0x03, 0x03, 0x07, 0x07, 0x0f, 0x0e, 0x1f, 0x3f, 0x3f, 0x3f, 0x36, 0x36, 
    0x36, 0x36, 0x3f, 0x3f, 0x3f, 0x1f, 0x0e, 0x0f, 0x07, 0x07, 0x03, 0x03, 0x01, 0x01, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x00, 0x00, 0x08, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x08, 0x08, 
    0x08, 0x0f, 0x0f, 0x0f, 0x07, 0x07, 0x07, 0x07, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
    };
    oled_write_raw_P(ffkb_logo, sizeof(ffkb_logo));

}

/*
static void render_status(void) {
    oled_write_P(PSTR("    Layer: "), false);
    switch (get_highest_layer(layer_state|default_layer_state)) {
        case _ALPHA_ALT:
            oled_write_P(PSTR("Alphalt   "), false);
            break;
        case _ALPHA:
            oled_write_P(PSTR("Alpha     "), false);
            break;
        case _NAVIGATION:
            oled_write_P(PSTR("Nav       "), false);
            break;
        case _SYMBOLS:
            oled_write_P(PSTR("Symbols   "), false);
            break;
        case _FUNCTION:
            oled_write_P(PSTR("Function  "), false);
            break;
        case _MEDIA:
            oled_write_P(PSTR("Media     "), false);
            break;
        case _MOUSE:
            oled_write_P(PSTR("Mouse     "), false);
            break;
        default:
            oled_write_P(PSTR("Unkn      "), false);
            break;
    }

    // // Write host Keyboard LED Status to OLEDs
    // led_t led_usb_state = host_keyboard_led_state();
    // oled_write_P(led_usb_state.num_lock    ? PSTR("NUMLCK ") : PSTR("       "), false);
    // oled_write_P(led_usb_state.caps_lock   ? PSTR("CAPLCK ") : PSTR("       "), false);
    // oled_write_P(led_usb_state.scroll_lock ? PSTR("SCRLCK ") : PSTR("       "), false);

    // ffkb logo, 128x48px
    static const char ffkb_logo_small [] PROGMEM = {
    0x00, 0x00, 0x00, 0x00, 0x40, 0x40, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0x40, 0x40, 
    0x40, 0x40, 0xc0, 0xc0, 0xc0, 0x00, 0x00, 0x40, 0x40, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 
    0xc0, 0x40, 0x40, 0x40, 0x40, 0xc0, 0xc0, 0xc0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
    0xf8, 0xfe, 0x8e, 0xdc, 0xf0, 0x70, 0x60, 0x30, 0x30, 0x30, 0x30, 0x30, 0x30, 0x30, 0x30, 0x30, 
    0x30, 0x70, 0xf0, 0xd8, 0x9c, 0x9e, 0xfc, 0xf0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x40, 0x40, 
    0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0x40, 0x40, 0x00, 0x40, 0x40, 0xc0, 0xc0, 0xc0, 
    0x40, 0x40, 0x40, 0x40, 0x00, 0x00, 0x40, 0x40, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 
    0x40, 0x40, 0x40, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0x80, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x10, 0x10, 
    0x18, 0x3c, 0x00, 0x00, 0x03, 0x00, 0x00, 0x00, 0x00, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
    0xff, 0x10, 0x10, 0x18, 0x3c, 0x00, 0x00, 0x03, 0x00, 0x00, 0x00, 0x00, 0x20, 0x30, 0x78, 0x7c, 
    0xff, 0xd7, 0x9b, 0x18, 0x78, 0x78, 0x18, 0x30, 0x70, 0xe0, 0x00, 0x00, 0x00, 0xc0, 0xe0, 0x30, 
    0x18, 0x58, 0x78, 0x18, 0x99, 0x9b, 0xf7, 0xfc, 0x78, 0x30, 0x20, 0x20, 0x00, 0x00, 0x00, 0x00, 
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x38, 0x78, 0xfc, 0xfc, 0xfe, 0xff, 0xf8, 0xf0, 
    0xc0, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
    0x10, 0x10, 0x10, 0xff, 0xff, 0xff, 0xff, 0xff, 0xef, 0xe7, 0xc0, 0x00, 0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x00, 0x00, 0x08, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x08, 0x00, 
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x08, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 
    0x0f, 0x08, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
    0x00, 0x01, 0x01, 0x01, 0x03, 0x07, 0x0e, 0x0c, 0x18, 0x3f, 0x7f, 0x68, 0x68, 0x3f, 0x3f, 0x0c, 
    0x0c, 0x06, 0x03, 0x03, 0x01, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x08, 
    0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x08, 0x00, 0x01, 0x0b, 0x0f, 0x0f, 0x0f, 0x0f, 
    0x0f, 0x0f, 0x0e, 0x0c, 0x00, 0x00, 0x00, 0x08, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 
    0x08, 0x08, 0x0c, 0x0f, 0x0f, 0x0f, 0x07, 0x07, 0x07, 0x03, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00
    };
    oled_write_raw_P(ffkb_logo_small, sizeof(ffkb_logo_small));
}
*/

bool oled_task_user(void) {
    // If you don't want to display the logo, switch
    if (false) {
        //render_status();
    } else if (true) {
        render_logo();
    } else {
        //render_logo_text();
    }
    return true;
}

#endif
