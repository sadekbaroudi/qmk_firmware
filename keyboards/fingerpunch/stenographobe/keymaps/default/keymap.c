#include QMK_KEYBOARD_H

// Defines names for use in layer keycodes and the keymap
enum layer_names {
    _QWERTY,
    _NAVIGATION,
    _SYMBOLS,
    _FUNCTION,
    _MOUSE
};

// Please see the readme.md in the stenographobe folder to see a visual for the default layout

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    [_QWERTY] = LAYOUT_stenographobe(
      KC_W,   LCTL_T(KC_A),      LGUI_T(KC_R),      LALT_T(KC_S),       LSFT_T(KC_T),       KC_G,                LT(_MOUSE, KC_M),    RSFT_T(KC_N),     RALT_T(KC_E),    RGUI_T(KC_I),     RCTL_T(KC_O),    KC_U,
      KC_F,   KC_Z,              KC_X,              KC_C,               KC_D,               KC_V,                KC_K,                KC_H,             KC_COMM,         KC_DOT,           KC_SLSH,         KC_Y,
                                KC_DEL,  LT(_NAVIGATION, KC_ENT),  LT(_FUNCTION, KC_TAB),                KC_BSPC,          LT(_SYMBOLS, KC_SPC),           KC_QUOT
    ),


    [_NAVIGATION] = LAYOUT_stenographobe(
        KC_PGUP, KC_HOME, KC_LEFT, KC_DOWN, KC_RGHT, KC_END,                   KC_ASTR, KC_4, KC_5, KC_6, KC_PLUS, KC_8,
        KC_UP,   KC_ESC,  KC_PGUP, KC_PGDN, _______, _______,                  KC_EQL,  KC_1, KC_2, KC_3, KC_0,    KC_9,
                                   _______, _______, KC_TAB, KC_BSPC, KC_SPACE, KC_DOT
    ),

    [_SYMBOLS] = LAYOUT_stenographobe(
        KC_AT,   KC_MINS, KC_EXLM, KC_DLR,  KC_PERC, _______,          _______, KC_CIRC, KC_AMPR, KC_EQL, KC_PLUS,  KC_ASTR,
        KC_HASH, KC_CAPS, KC_GRV,  _______, _______, _______,          _______, _______, _______, _______, _______, KC_UNDS,
                                _______, KC_ENT, KC_DEL,  KC_BSPC, _______, _______
    ),

    [_FUNCTION] = LAYOUT_stenographobe(
        LSFT(KC_PGUP), LSFT(KC_HOME), LSFT(KC_LEFT), LSFT(KC_DOWN), LSFT(KC_RGHT), LSFT(KC_END),                                          KC_F7,  KC_F4, KC_F5, KC_F6, KC_F10, KC_F8,
        LSFT(KC_UP),   _______,       LSFT(KC_PGUP), LSFT(KC_PGDN), _______,       _______,                                               KC_F12, KC_F1, KC_F2, KC_F3, KC_F11, KC_F9,
                                                                      _______, _______, _______, _______, KC_SPACE, _______
    ),

    [_MOUSE] = LAYOUT_stenographobe(
        MS_WHLU, MS_WHLL, MS_LEFT,  MS_DOWN,    MS_RGHT,  MS_WHLR,            _______, _______, _______, _______, _______, _______,
        MS_UP,    QK_BOOT,       MS_WHLU, MS_WHLD, MS_ACL1, MS_ACL2,              _______, _______, _______, _______, _______, _______,
                                                    _______, MS_BTN1, MS_BTN3, MS_BTN3, MS_BTN2, _______
    )
};

enum combo_events {
  UNDO,
  Q,
  P,
  B,
  J,
  L,
  SEMICOLON,
  LBRACKET,
  LCURLY,
  LPAREN,
  LANGLE,
  RANGLE,
  RPAREN,
  RCURLY,
  RBRACKET,
};

// COMBOS - https://beta.docs.qmk.fm/using-qmk/software-features/feature_combo
const uint16_t PROGMEM undo_combo[] = {KC_Z, KC_X, COMBO_END};
const uint16_t PROGMEM q_combo[] = {KC_X, KC_C, COMBO_END};
const uint16_t PROGMEM p_combo[] = {LSFT_T(KC_T), KC_G, COMBO_END};
const uint16_t PROGMEM b_combo[] = {KC_D, KC_V, COMBO_END};
const uint16_t PROGMEM j_combo[] = {KC_K, KC_H, COMBO_END};
const uint16_t PROGMEM l_combo[] = {LT(_MOUSE, KC_M), RSFT_T(KC_N), COMBO_END};
const uint16_t PROGMEM semicolon_combo[] = {KC_COMMA, KC_DOT, COMBO_END};

const uint16_t PROGMEM lbracket_combo[] = {LGUI_T(KC_R), KC_X, COMBO_END};
const uint16_t PROGMEM lcurly_combo[] = {LALT_T(KC_S), KC_C, COMBO_END};
const uint16_t PROGMEM lparen_combo[] = {LSFT_T(KC_T), KC_D, COMBO_END};
const uint16_t PROGMEM langle_combo[] = {KC_G, KC_V, COMBO_END};
const uint16_t PROGMEM rangle_combo[] = {LT(_MOUSE, KC_M), KC_K, COMBO_END};
const uint16_t PROGMEM rparen_combo[] = {RSFT_T(KC_N), KC_H, COMBO_END};
const uint16_t PROGMEM rcurly_combo[] = {RALT_T(KC_E), KC_COMMA, COMBO_END};
const uint16_t PROGMEM rbracket_combo[] = {RGUI_T(KC_I), KC_DOT, COMBO_END};

combo_t key_combos[COMBO_COUNT] = {
  [UNDO] = COMBO_ACTION(undo_combo),
  [Q] = COMBO_ACTION(q_combo),
  [P] = COMBO_ACTION(p_combo),
  [B] = COMBO_ACTION(b_combo),
  [J] = COMBO_ACTION(j_combo),
  [L] = COMBO_ACTION(l_combo),
  [SEMICOLON] = COMBO_ACTION(semicolon_combo),
  [LBRACKET] = COMBO_ACTION(lbracket_combo),
  [LCURLY] = COMBO_ACTION(lcurly_combo),
  [LPAREN] = COMBO_ACTION(lparen_combo),
  [LANGLE] = COMBO_ACTION(langle_combo),
  [RANGLE] = COMBO_ACTION(rangle_combo),
  [RPAREN] = COMBO_ACTION(rparen_combo),
  [RCURLY] = COMBO_ACTION(rcurly_combo),
  [RBRACKET] = COMBO_ACTION(rbracket_combo),
};

void process_combo_event(uint16_t combo_index, bool pressed) {
  // can comment out if I use the apostrophe below
  //static uint16_t kc;
  switch(combo_index) {
    case UNDO:
      if (pressed) {
        tap_code16(LCTL(KC_Z));
      }
      break;
    case Q:
      if (pressed) {
        tap_code16(KC_Q);
      }
      break;
    case P:
      if (pressed) {
        tap_code16(KC_P);
      }
      break;
    case B:
      if (pressed) {
        tap_code16(KC_B);
      }
      break;
    case J:
      if (pressed) {
        tap_code16(KC_J);
      }
      break;
    case L:
      if (pressed) {
        tap_code16(KC_L);
      }
      break;
    case SEMICOLON:
      if (pressed) {
        tap_code16(KC_COLON);
      }
      break;
    case LBRACKET:
      if (pressed) {
        tap_code16(LBRACKET);
      }
      break;
    case LCURLY:
      if (pressed) {
        tap_code16(KC_LCBR);
      }
      break;
    case LPAREN:
      if (pressed) {
        tap_code16(KC_LPRN);
      }
      break;
    case LANGLE:
      if (pressed) {
        tap_code16(KC_LABK);
      }
      break;
    case RANGLE:
      if (pressed) {
        tap_code16(KC_RABK);
      }
      break;
    case RPAREN:
      if (pressed) {
        tap_code16(KC_RPRN);
      }
      break;
    case RCURLY:
      if (pressed) {
        tap_code16(KC_RCBR);
      }
      break;
    case RBRACKET:
      if (pressed) {
        tap_code16(RBRACKET);
      }
      break;
  }
}
// END COMBOS
