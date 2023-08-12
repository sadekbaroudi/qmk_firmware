#include QMK_KEYBOARD_H

#define _HOME 0
#define _NAV 1
#define _FN 2
#define _SYM 3
#define _GAME 4
#define _RGB 5
#define _MOUSE 6
#define _AUTO_MOUSE 7

enum combos {
    JK_ESC,
    DF_BKSPC,
    SF_SCROLL_TOGGLE,
    JKLQUOTE_MOUSE,
    PQUOTE_DEL,
    QWER_GAME,
    XCVB_BOOT,
    RFTG_RESET,
    RGB_LAYER,
    CLR_EPROM,
};

enum custom_keycodes {
    DRAG_SCROLL = FP_SAFE_RANGE,
};

bool set_scrolling = false;

// Variables to store accumulated scroll values
float scroll_accumulated_h = 0;
float scroll_accumulated_v = 0;

// Function to handle mouse reports and perform drag scrolling from:
// https://docs.qmk.fm/#/feature_pointing_device?id=advanced-drag-scroll
report_mouse_t pointing_device_task_user(report_mouse_t mouse_report) {
    if (set_scrolling) {
        // Calculate and accumulate scroll values based on mouse movement and divisors
        scroll_accumulated_h += (float)mouse_report.x / SCROLL_DIVISOR_H;
        scroll_accumulated_v += (float)mouse_report.y / SCROLL_DIVISOR_V;

        // Assign integer parts of accumulated scroll values to the mouse report
        mouse_report.h = (int8_t)scroll_accumulated_h;
        mouse_report.v = -(int8_t)scroll_accumulated_v;

        // Update accumulated scroll values by subtracting the integer parts
        scroll_accumulated_h -= (int8_t)scroll_accumulated_h;
        scroll_accumulated_v -= (int8_t)scroll_accumulated_v;

        // Clear the X and Y values of the mouse report
        mouse_report.x = 0;
        mouse_report.y = 0;
    }
    return mouse_report;
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (keycode == DRAG_SCROLL && record->event.pressed) {
        set_scrolling = true;
    } else {
        set_scrolling = false;
    }
    return true;
}

// set the scroll moment key as a mouse key so that it holds the auto mouse layer active
bool is_mouse_record_user(uint16_t keycode, keyrecord_t* record) {
    switch(keycode) {
        case DRAG_SCROLL:
            return true;
    }
    return false;
}

const uint16_t PROGMEM esc_combo[] = {KC_J, KC_K, COMBO_END};
const uint16_t PROGMEM bkspc_combo[] = {KC_D, KC_F, COMBO_END};
const uint16_t PROGMEM scroll_combo[] = {KC_S, KC_F, COMBO_END};
const uint16_t PROGMEM mouse_combo[] = {KC_J, KC_K, KC_L, KC_QUOT, COMBO_END};
const uint16_t PROGMEM del_combo[] = {KC_P, KC_QUOT, COMBO_END};
const uint16_t PROGMEM gl_combo[] = {KC_Q, KC_W, KC_E, KC_R, COMBO_END};
const uint16_t PROGMEM boot_combo[] = {KC_X, KC_C, KC_V, KC_B, COMBO_END};
const uint16_t PROGMEM reset_combo[] = {KC_R, KC_T, KC_F, KC_G, COMBO_END};
const uint16_t PROGMEM rgb_combo[] = {KC_R, KC_G, KC_B, COMBO_END};
const uint16_t PROGMEM eprom_combo[] = {KC_E, KC_D, KC_R, KC_F, COMBO_END};

combo_t key_combos[] = {
    [JK_ESC] = COMBO(esc_combo, KC_ESC),
    [DF_BKSPC] = COMBO(bkspc_combo, KC_BSPC),
    [SF_SCROLL_TOGGLE] = COMBO(scroll_combo, FP_SCROLL_TOG),
    [JKLQUOTE_MOUSE] = COMBO(mouse_combo, TO(_MOUSE)),
    [PQUOTE_DEL] = COMBO(del_combo, KC_DEL),
    [QWER_GAME] = COMBO(gl_combo, TO(_GAME)),
    [XCVB_BOOT] = COMBO(boot_combo, QK_BOOT),
    [RFTG_RESET] = COMBO(reset_combo, QK_RBT),
    [RGB_LAYER] = COMBO(rgb_combo, TO(_RGB)),
    [CLR_EPROM] = COMBO(eprom_combo, EE_CLR),
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /*
    * ┌─────┬─────┬─────┬─────┬─────┐       ┌─────┬─────┬─────┬─────┬─────┐
    * │  Q  │  W  │  E  │  R  │  T  │       │  Y  │  U  │  I  │  O  │  P  │
    * ├─────┼─────┼─────┼─────┼─────┤       ├─────┼─────┼─────┼─────┼─────┤
    * │  A  │  S  │  D  │  F  │  G  │       │  H  │  J  │  K  │  L  │  '  │
    * ├─────┼─────┼─────┼─────┼─────┤       ├─────┼─────┼─────┼─────┼─────┤
    * │ Z/⇧ │  X  │  C  │  V  │  B  │       │  N  │  M  │  ,  │  .  │ENT/⇧│
    * └─────┴─────┴─────┴─────┴─────┘       └─────┴─────┴─────┴─────┴─────┘
    *   ┌─────┐    ┌─────┐                           ┌─────┐   ┌─────┐
    *   │Mute │    │ GUI ├─────┐               ┌─────┤ ALT │   │Mute │
    *   └─────┘    └─────┤ NAV ├─────┐   ┌─────┤ SPC ├─────┘   └─────┘
    *                    └─────┤ CTL │   │ SYM ├─────┘
    *                          └─────┘   └─────┘
    */
    [_HOME] = LAYOUT_ximi(
        KC_TAB,  KC_Q,    KC_W,     KC_E,    KC_R,       KC_T,                         KC_Y, KC_U,    KC_I,    KC_O,    KC_P,        KC_BSPC,
        KC_LCTL, KC_A,    KC_S,     KC_D,    KC_F,       KC_G,                         KC_H, KC_J,    KC_K,    KC_L,    KC_QUOT,     KC_NO,
        KC_LSFT, MT(MOD_LSFT, KC_Z),KC_X,    KC_C,       KC_V,   KC_B,         KC_N,   KC_M, KC_COMM, KC_DOT,  MT(MOD_RSFT, KC_ENT), KC_RSFT,
        KC_MUTE,           KC_LGUI, OSL(_NAV), KC_LCTL,              OSL(_SYM),   KC_SPC,  KC_RALT,          KC_MUTE,
        KC_ESC, TO(_MOUSE), C(KC_Y),              KC_VOLD,      KC_MUTE, KC_VOLU
    ),
    /*
    * ┌─────┬─────┬─────┬─────┬─────┐       ┌─────┬─────┬─────┬─────┬─────┐
    * │ TAB │  7  │  8  │  9  │  -  │       │ TAB←│     │     │ TAB→│ BSP │
    * ├─────┼─────┼─────┼─────┼─────┤       ├─────┼─────┼─────┼─────┼─────┤
    * │  0  │  4  │  5  │  6  │ ENTR│       │  ←  │  ↓  │  ↑  │  →  │ HOME│
    * ├─────┼─────┼─────┼─────┼─────┤       ├─────┼─────┼─────┼─────┼─────┤
    * │     │  1  │  2  │  3  │  .  │       │ FN  │ FN  │     │     │     │
    * └─────┴─────┴─────┴─────┴─────┘       └─────┴─────┴─────┴─────┴─────┘
    *    ┌─────┐    ┌─────┐                           ┌─────┐   ┌─────┐
    *    │Mute │    │ GUI ├─────┐               ┌─────┤ ALT │   │Mute │
    *    └─────┘    └─────┤ NAV ├─────┐   ┌─────┤ SPC ├─────┘   └─────┘
    *                     └─────┤ CTL │   │ SYM ├─────┘
    *                           └─────┘   └─────┘
    */

    [_NAV] = LAYOUT_ximi(
        KC_TAB,  KC_TAB,   KC_7,    KC_8,    KC_9,    KC_MINUS,                           C(S(KC_TAB)), KC_TRNS, KC_TRNS, C(KC_TAB),KC_BSPC,  KC_TRNS,
        KC_LCTL, KC_0,     KC_4,    KC_5,    KC_6,    KC_ENT,                             KC_LEFT,   KC_DOWN,   KC_UP,   KC_RIGHT, TO(_HOME), KC_TRNS,
        KC_LSFT, KC_TRNS,  KC_1,    KC_2,    KC_3,    KC_LALT,                            MO(_FN),   MO(_FN),   KC_TRNS, KC_TRNS,  KC_TRNS,   KC_TRNS,
        KC_MUTE,           KC_LGUI, OSL(_NAV), KC_LCTL,              OSL(_SYM),   KC_SPC,  KC_RALT,          KC_MUTE,
        C(KC_Z), C(S(KC_Z)), C(KC_Y),              KC_VOLD,      KC_MUTE, KC_VOLU
    ),
    /*
    * ┌─────┬─────┬─────┬─────┬─────┐       ┌─────┬─────┬─────┬─────┬─────┐
    * │ TAB │ F7  │ F8  │ F9  │     │       │ F11 │ F12 │ F13 │ F14 │ F15 │
    * ├─────┼─────┼─────┼─────┼─────┤       ├─────┼─────┼─────┼─────┼─────┤
    * │ F10 │ F4  │ F5  │ F6  │     │       │ F16 │ F17 │ F18 │ F19 │ F20 │
    * ├─────┼─────┼─────┼─────┼─────┤       ├─────┼─────┼─────┼─────┼─────┤
    * │     │ F1  │ F2  │ F3  │     │       │-----│-----│     │     │     │
    * └─────┴─────┴─────┴─────┴─────┘       └─────┴─────┴─────┴─────┴─────┘
    *    ┌─────┐    ┌─────┐                           ┌─────┐   ┌─────┐
    *    │Mute │    │ GUI ├─────┐               ┌─────┤ ALT │   │Mute │
    *    └─────┘    └─────┤ NAV ├─────┐   ┌─────┤ SPC ├─────┘   └─────┘
    *                     └─────┤ CTL │   │ SYM ├─────┘
    *                           └─────┘   └─────┘
    */

    [_FN] = LAYOUT_ximi(
        KC_TAB,  KC_TAB,   KC_F7,    KC_F8,    KC_F9,    _______,                             KC_F11,    KC_F12,  KC_F13,     KC_F14,     KC_F15,     _______,
        KC_LCTL, KC_F10,   KC_F4,    KC_F5,    KC_F6,    _______,                             KC_F16,    KC_F17,  KC_F18,     KC_F19,     KC_F20,     _______,
        KC_LSFT, KC_TRNS,  KC_F1,    KC_F2,    KC_F3,    _______,                             _______,   _______, _______,    _______,    _______,    _______,
        KC_MUTE,           KC_LGUI, OSL(_NAV), KC_LCTL,              OSL(_SYM),   KC_SPC,  KC_RALT,          KC_MUTE,
        C(KC_Z), C(S(KC_Z)), C(KC_Y),              KC_VOLD,      KC_MUTE, KC_VOLU
    ),
    /*
    * ┌─────┬─────┬─────┬─────┬─────┐       ┌─────┬─────┬─────┬─────┬─────┐
    * │  !  │  @  │  +  │  =  │  -  │       │  %  │  &  │  *  │  (  │  )  │
    * ├─────┼─────┼─────┼─────┼─────┤       ├─────┼─────┼─────┼─────┼─────┤
    * │  #  │  `  │  |  │  [  │  ]  │       │  }  │  {  │  :  │  ;  │  /  │
    * ├─────┼─────┼─────┼─────┼─────┤       ├─────┼─────┼─────┼─────┼─────┤
    * │     │  ~  │  \  │  $  │     │       │     │  _  │  ^  │  ?  │     │
    * └─────┴─────┴─────┴─────┴─────┘       └─────┴─────┴─────┴─────┴─────┘
    *    ┌─────┐    ┌─────┐                           ┌─────┐   ┌─────┐
    *    │Mute │    │ GUI ├─────┐               ┌─────┤ ALT │   │Mute │
    *    └─────┘    └─────┤ NAV ├─────┐   ┌─────┤ SPC ├─────┘   └─────┘
    *                     └─────┤ CTL │   │ SYM ├─────┘
    *                           └─────┘   └─────┘
    */

    [_SYM] = LAYOUT_ximi(
        KC_TRNS, S(KC_1),  S(KC_2),   S(KC_EQL),  KC_EQL,   KC_MINUS,                          S(KC_5),    S(KC_7),     S(KC_8),    S(KC_9),    S(KC_0), KC_TRNS,
        KC_LCTL, S(KC_3),  KC_GRAVE,  S(KC_BSLS), KC_LBRC,  KC_RBRC,                           S(KC_RBRC), S(KC_LBRC),  S(KC_SCLN), KC_SCLN,    KC_SLSH, KC_TRNS,
        KC_LSFT, KC_TRNS,  S(KC_GRV), KC_BSLS,    S(KC_4),  KC_TRNS,                           KC_TRNS,    S(KC_MINUS), S(KC_6),    S(KC_SLSH), KC_TRNS, KC_TRNS,
        KC_MUTE,           KC_LGUI, OSL(_NAV), KC_LCTL,              OSL(_SYM),   KC_SPC,  KC_RALT,          KC_MUTE,
        C(KC_Z), C(S(KC_Z)), C(KC_Y),              KC_VOLD,      KC_MUTE, KC_VOLU
    ),
    /*
    * ┌─────┬─────┬─────┬─────┬─────┐
    * │ ESC │  Q  │  W  │  E  │  R  │
    * ├─────┼─────┼─────┼─────┼─────┤
    * │ SFT │  A  │  S  │  D  │  F  │
    * ├─────┼─────┼─────┼─────┼─────┤
    * │ CTL │  Z  │  X  │  C  │  V  │
    * └─────┴─────┴─────┴─────┴─────┘
    *    ┌─────┐    ┌─────┐
    *    │Mute │    │ GUI ├─────┐
    *    └─────┘    └─────┤ NAV ├─────┐
    *                     └─────┤ CTL │
    *                           └─────┘
    */
    [_GAME] = LAYOUT_ximi(
        KC_TRNS, KC_ESC,  KC_Q, KC_W,  KC_E,   KC_R,                          TO(_HOME), TO(_HOME), TO(_HOME), TO(_HOME), TO(_HOME), TO(_HOME),
        KC_LCTL, KC_LSFT, KC_A, KC_S,   KC_D,  KC_F,                          TO(_HOME), TO(_HOME), TO(_HOME), TO(_HOME), TO(_HOME), TO(_HOME),
        KC_LSFT, KC_LCTL, KC_Z, KC_X,   KC_C,  KC_V,                          TO(_HOME), TO(_HOME), TO(_HOME), TO(_HOME), TO(_HOME), TO(_HOME),
        KC_MUTE,           KC_LGUI, OSL(_NAV), KC_LCTL,              OSL(_SYM),   KC_SPC,  KC_RALT,          KC_MUTE,
        C(KC_Z), C(S(KC_Z)), C(KC_Y),              KC_VOLD,      KC_MUTE, KC_VOLU
    ),

    /* RGB Layer (rgb combo)
     *
     * ,-----------------------------------------.
     * | ____ | RGB_T| RGB_R| RGB_F|      |QWERTY|
     * |------+------+------+------+------+------|
     * | ____ | SPD_I| HUE_I| SAT_I| VAL_I|COLEMK|
     * |------+------+------+------+------+------|
     * | ____ | SPD_D| HUE_D| SAT_D| VAL_D|      |
     * `-----------------------------------------'
     */
    [_RGB] =  LAYOUT_ximi(
        _______,      RGB_TOG, RGB_RMOD, RGB_MOD, _______, _______,      _______,  _______,   _______,   _______,    _______,     _______,
        _______,      RGB_SPI, RGB_HUI,  RGB_SAI, RGB_VAI, _______,      _______,  _______,   _______,   _______,    TO(_HOME),  _______,
        _______,      RGB_SPD, RGB_HUD,  RGB_SAD, RGB_VAD, _______,      _______,  _______,   _______,   _______,    _______,     _______,
        _______,           _______, _______, _______,           _______, _______, _______,          _______,
        _______, _______, _______,           _______, _______, _______
    ),

    /*
    * ┌─────┬─────┬─────┬─────┬─────┐       ┌─────┬─────┬─────┬─────┬─────┐
    * │     │     │  📜 │     │     │       │     │  ↓  │  ↑  │     │     │
    * ├─────┼─────┼─────┼─────┼─────┤       ├─────┼─────┼─────┼─────┼─────┤
    * │     │ 🖱️1 │ 🖱️3 │ 🖱️2 │     │       │ 🖰 ← │ 🖰↓  │ 🖰↑  │ 🖰→  │ HOME│
    * ├─────┼─────┼─────┼─────┼─────┤       ├─────┼─────┼─────┼─────┼─────┤
    * │     │     │     │     │     │       │     │     │     │     │     │
    * └─────┴─────┴─────┴─────┴─────┘       └─────┴─────┴─────┴─────┴─────┘
    *    ┌─────┐    ┌─────┐                           ┌─────┐   ┌─────┐
    *    │Mute │    │ GUI ├─────┐               ┌─────┤ ALT │   │Mute │
    *    └─────┘    └─────┤ NAV ├─────┐   ┌─────┤ SPC ├─────┘   └─────┘
    *                     └─────┤ CTL │   │ SYM ├─────┘
    *                           └─────┘   └─────┘
    */

    [_MOUSE] = LAYOUT_ximi(
        _______, _______,  _______,    DRAG_SCROLL,    _______,    _______,           KC_TRNS,   KC_WH_U,   KC_WH_D, KC_TRNS,  KC_TRNS,    KC_TRNS,
        _______, _______,  KC_BTN1,    KC_BTN3,    KC_BTN2,    _______,                    KC_MS_L,   KC_MS_D,   KC_MS_U, KC_MS_R,  TO(_HOME),  KC_TRNS,
        _______, _______,  _______,    _______,    _______,    _______,                    KC_TRNS,   KC_TRNS,   KC_TRNS, KC_TRNS,  KC_TRNS,    KC_TRNS,
        KC_MUTE,           KC_LGUI, OSL(_NAV), KC_LCTL,              OSL(_SYM),   KC_SPC,  KC_RALT,          KC_MUTE,
                           C(KC_Z), C(S(KC_Z)), C(KC_Y),              KC_VOLD,      KC_MUTE, KC_VOLU
    ),
    [_AUTO_MOUSE] = LAYOUT_ximi(
        _______, _______,  _______,    DRAG_SCROLL,    _______,    _______,           KC_TRNS,   KC_WH_U,   KC_WH_D, KC_TRNS,  KC_TRNS,    KC_TRNS,
        _______, _______,  KC_BTN1,    KC_BTN3,    KC_BTN2,    _______,                    KC_MS_L,   KC_MS_D,   KC_MS_U, KC_MS_R,  KC_TRNS,  KC_TRNS,
        _______, _______,  _______,    _______,    _______,    _______,                    KC_TRNS,   KC_TRNS,   KC_TRNS, KC_TRNS,  KC_TRNS,    KC_TRNS,
        KC_MUTE,           KC_LGUI, OSL(_NAV), KC_LCTL,              OSL(_SYM),   KC_SPC,  KC_RALT,          KC_MUTE,
                           C(KC_Z), C(S(KC_Z)), C(KC_Y),              KC_VOLD,      KC_MUTE, KC_VOLU
    )
};
