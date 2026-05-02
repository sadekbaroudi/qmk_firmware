// check to see if we are using the stenographobe, and skip if so... it has its own whole combo scheme
// see keyboards/fingerpunch/stenographobe/keymaps/*/keymap.c
#ifndef KEYBOARD_fingerpunch_stenographobe
#include "combos.h"
#include "sadekbaroudi.h"

// COMBOS - https://beta.docs.qmk.fm/using-qmk/software-features/feature_combo
const uint16_t PROGMEM undo_combo[] = {KC_Z, KC_X, COMBO_END};
#ifdef KEYBOARD_fingerpunch_arachnophobe
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
#endif
#ifdef KEYBOARD_fingerpunch_personal_smallcat
// Corner keys
// Base layer
const uint16_t PROGMEM q_combo[] = {KC_W, KC_F, COMBO_END};
const uint16_t PROGMEM b_combo[] = {KC_F, KC_P, COMBO_END};
const uint16_t PROGMEM z_combo[] = {KC_X, KC_C, COMBO_END};
const uint16_t PROGMEM v_combo[] = {KC_C, KC_D, COMBO_END};
const uint16_t PROGMEM j_combo[] = {KC_L, KC_U, COMBO_END};
const uint16_t PROGMEM k_combo[] = {KC_H, KC_COMM, COMBO_END};
const uint16_t PROGMEM semi_combo[] = {KC_U, KC_Y, COMBO_END};
const uint16_t PROGMEM slash_combo[] = {KC_COMM, KC_DOT, COMBO_END};
// Nav section
const uint16_t PROGMEM nav_tl_combo[] = {__NAV_1_K2__, __NAV_1_K3__, COMBO_END};
const uint16_t PROGMEM nav_tr_combo[] = {__NAV_1_K3__, __NAV_1_K4__, COMBO_END};
const uint16_t PROGMEM nav_bl_combo[] = {__NAV_3_K2__, __NAV_3_K3__, COMBO_END};
const uint16_t PROGMEM nav_br_combo[] = {__NAV_3_K3__, __NAV_3_K4__, COMBO_END};
// Numpad section
const uint16_t PROGMEM num_tl_combo[] = {__NUMPAD_1_K2__, __NUMPAD_1_K3__, COMBO_END};
const uint16_t PROGMEM num_tr_combo[] = {__NUMPAD_1_K3__, __NUMPAD_1_K4__, COMBO_END};
const uint16_t PROGMEM num_bl_combo[] = {__NUMPAD_3_K2__, __NUMPAD_3_K3__, COMBO_END};
const uint16_t PROGMEM num_br_combo[] = {__NUMPAD_3_K3__, __NUMPAD_3_K4__, COMBO_END};
// Symbols section
const uint16_t PROGMEM sym_l_tl_combo[] = {__SYMBOLS_L1_K2__, __SYMBOLS_L1_K3__, COMBO_END};
const uint16_t PROGMEM sym_l_tr_combo[] = {__SYMBOLS_L1_K3__, __SYMBOLS_L1_K4__, COMBO_END};
const uint16_t PROGMEM sym_l_bl_combo[] = {__META_NAV_L1_K2__, __META_NAV_L1_K3__, COMBO_END};
const uint16_t PROGMEM sym_l_br_combo[] = {__META_NAV_L1_K3__, __META_NAV_L1_K4__, COMBO_END};
const uint16_t PROGMEM sym_r_tl_combo[] = {__SYMBOLS_R1_K2__, __SYMBOLS_R1_K3__, COMBO_END};
const uint16_t PROGMEM sym_r_tr_combo[] = {__SYMBOLS_R1_K3__, __SYMBOLS_R1_K4__, COMBO_END};
const uint16_t PROGMEM sym_r_bl_combo[] = {__META_NAV_L2_K2__, __META_NAV_L2_K3__, COMBO_END};
const uint16_t PROGMEM sym_r_br_combo[] = {__META_NAV_L2_K3__, __META_NAV_L2_K4__, COMBO_END};
// Shift Nav section
const uint16_t PROGMEM shiftnav_tl_combo[] = {__SHIFTNAV_1_K2__, __SHIFTNAV_1_K3__, COMBO_END};
const uint16_t PROGMEM shiftnav_tr_combo[] = {__SHIFTNAV_1_K3__, __SHIFTNAV_1_K4__, COMBO_END};
const uint16_t PROGMEM shiftnav_bl_combo[] = {__SHIFTNAV_3_K2__, __SHIFTNAV_3_K3__, COMBO_END};
const uint16_t PROGMEM shiftnav_br_combo[] = {__SHIFTNAV_3_K3__, __SHIFTNAV_3_K4__, COMBO_END};
// Function section
const uint16_t PROGMEM function_tl_combo[] = {__FUNCTION_1_K2__, __FUNCTION_1_K3__, COMBO_END};
const uint16_t PROGMEM function_tr_combo[] = {__FUNCTION_1_K3__, __FUNCTION_1_K4__, COMBO_END};
const uint16_t PROGMEM function_bl_combo[] = {__FUNCTION_3_K2__, __FUNCTION_3_K3__, COMBO_END};
const uint16_t PROGMEM function_br_combo[] = {__FUNCTION_3_K3__, __FUNCTION_3_K4__, COMBO_END};
// RGB section
const uint16_t PROGMEM rgb_tl_combo[] = {__RGB_1_K2__, __RGB_1_K3__, COMBO_END};
const uint16_t PROGMEM rgb_tr_combo[] = {__RGB_1_K3__, __RGB_1_K4__, COMBO_END};
const uint16_t PROGMEM rgb_bl_combo[] = {__RGB_3_K2__, __RGB_3_K3__, COMBO_END};
const uint16_t PROGMEM rgb_br_combo[] = {__RGB_3_K3__, __RGB_3_K4__, COMBO_END};
// Macros section
const uint16_t PROGMEM macros_tl_combo[] = {__MACROS_1_K2__, __MACROS_1_K3__, COMBO_END};
const uint16_t PROGMEM macros_tr_combo[] = {__MACROS_1_K3__, __MACROS_1_K4__, COMBO_END};
const uint16_t PROGMEM macros_bl_combo[] = {__MACROS_3_K2__, __MACROS_3_K3__, COMBO_END};
const uint16_t PROGMEM macros_br_combo[] = {__MACROS_3_K3__, __MACROS_3_K4__, COMBO_END};
// Thumbs
const uint16_t PROGMEM thumb_l_combo[] = {LSFT_T(__ALPHA_L2_K4__), __ALPHA_L2_K5__, COMBO_END};
const uint16_t PROGMEM thumb_r_combo[] = {LT(_MOUSE, __ALPHA_R2_K1__), RSFT_T(__ALPHA_R2_K2__), COMBO_END};
const uint16_t PROGMEM alt_thumb_l_combo[] = {LSFT_T(__ALPHA_ALT_L2_K4__), __ALPHA_ALT_L2_K5__, COMBO_END};
const uint16_t PROGMEM alt_thumb_r_combo[] = {LT(_MOUSE, __ALPHA_ALT_R2_K1__), RSFT_T(__ALPHA_ALT_R2_K2__), COMBO_END};
const uint16_t PROGMEM thumb_l_reachy_nav_combo[] = {__NAV_2_K4__, __NAV_2_K5__, COMBO_END};
const uint16_t PROGMEM thumb_r_reachy_num_combo[] = {__NUMPAD_2_K1__, __NUMPAD_2_K2__, COMBO_END};
const uint16_t PROGMEM thumb_l_reachy_sym_combo[] = {__SYMBOLS_L2_K4__, __SYMBOLS_L2_K5__, COMBO_END};
const uint16_t PROGMEM thumb_r_reachy_sym_combo[] = {__SYMBOLS_R1_K1__, __SYMBOLS_R1_K2__, COMBO_END};
#endif

combo_t key_combos[COMBO_COUNT] = {
  [UNDO] = COMBO_ACTION(undo_combo),
#ifdef KEYBOARD_fingerpunch_arachnophobe
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
#endif
#ifdef KEYBOARD_fingerpunch_personal_smallcat
// Base layer
  [Q] = COMBO_ACTION(q_combo),
  [B] = COMBO_ACTION(b_combo),
  [Z] = COMBO_ACTION(z_combo),
  [V] = COMBO_ACTION(v_combo),
  [J] = COMBO_ACTION(j_combo),
  [K] = COMBO_ACTION(k_combo),
  [SEMICOLON] = COMBO_ACTION(semi_combo),
  [SLASH] = COMBO_ACTION(slash_combo),
// Nav section
  [NAV_TL] = COMBO_ACTION(nav_tl_combo),
  [NAV_TR] = COMBO_ACTION(nav_tr_combo),
  [NAV_BL] = COMBO_ACTION(nav_bl_combo),
  [NAV_BR] = COMBO_ACTION(nav_br_combo),
// Numpad section
  [NUM_TL] = COMBO_ACTION(num_tl_combo),
  [NUM_TR] = COMBO_ACTION(num_tr_combo),
  [NUM_BL] = COMBO_ACTION(num_bl_combo),
  [NUM_BR] = COMBO_ACTION(num_br_combo),
// Symbols section
  [SYM_L_TL] = COMBO_ACTION(sym_l_tl_combo),
  [SYM_L_TR] = COMBO_ACTION(sym_l_tr_combo),
  [SYM_L_BL] = COMBO_ACTION(sym_l_bl_combo),
  [SYM_L_BR] = COMBO_ACTION(sym_l_br_combo),
  [SYM_R_TL] = COMBO_ACTION(sym_r_tl_combo),
  [SYM_R_TR] = COMBO_ACTION(sym_r_tr_combo),
  [SYM_R_BL] = COMBO_ACTION(sym_r_bl_combo),
  [SYM_R_BR] = COMBO_ACTION(sym_r_br_combo),
// Shift Nav section
  [SHIFTNAV_TL] = COMBO_ACTION(shiftnav_tl_combo),
  [SHIFTNAV_TR] = COMBO_ACTION(shiftnav_tr_combo),
  [SHIFTNAV_BL] = COMBO_ACTION(shiftnav_bl_combo),
  [SHIFTNAV_BR] = COMBO_ACTION(shiftnav_br_combo),
// Function section
  [FUNCTION_TL] = COMBO_ACTION(function_tl_combo),
  [FUNCTION_TR] = COMBO_ACTION(function_tr_combo),
  [FUNCTION_BL] = COMBO_ACTION(function_bl_combo),
  [FUNCTION_BR] = COMBO_ACTION(function_br_combo),
// RGB section
  [RGB_TL] = COMBO_ACTION(rgb_tl_combo),
  [RGB_TR] = COMBO_ACTION(rgb_tr_combo),
  [RGB_BL] = COMBO_ACTION(rgb_bl_combo),
  [RGB_BR] = COMBO_ACTION(rgb_br_combo),
// Macros section
  [MACROS_TL] = COMBO_ACTION(macros_tl_combo),
  [MACROS_TR] = COMBO_ACTION(macros_tr_combo),
  [MACROS_BL] = COMBO_ACTION(macros_bl_combo),
  [MACROS_BR] = COMBO_ACTION(macros_br_combo),
// Thumbs
  [THUMB_L] = COMBO_ACTION(thumb_l_combo),
  [THUMB_R] = COMBO_ACTION(thumb_r_combo),
  [ALT_THUMB_L] = COMBO_ACTION(alt_thumb_l_combo),
  [ALT_THUMB_R] = COMBO_ACTION(alt_thumb_r_combo),
  [THUMB_L_REACHY_NAV] = COMBO_ACTION(thumb_l_reachy_nav_combo),
  [THUMB_R_REACHY_NUM] = COMBO_ACTION(thumb_r_reachy_num_combo),
  [THUMB_L_REACHY_SYM] = COMBO_ACTION(thumb_l_reachy_sym_combo),
  [THUMB_R_REACHY_SYM] = COMBO_ACTION(thumb_r_reachy_sym_combo),
#endif
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
#if defined(KEYBOARD_fingerpunch_arachnophobe)
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
#elif defined(KEYBOARD_fingerpunch_personal_smallcat)
    case Q:
      if (pressed) {
        tap_code16(KC_Q);
      }
      break;
    case B:
      if (pressed) {
        tap_code16(KC_B);
      }
      break;
    case Z:
      if (pressed) {
        tap_code16(KC_Z);
      }
      break;
    case V:
      if (pressed) {
        tap_code16(KC_V);
      }
      break;
    case J:
      if (pressed) {
        tap_code16(KC_J);
      }
      break;
    case K:
      if (pressed) {
        tap_code16(KC_K);
      }
      break;
    case SEMICOLON:
      if (pressed) {
        tap_code16(KC_SCLN);
      }
      break;
    case SLASH:
      if (pressed) {
        tap_code16(KC_SLSH);
      }
      break;
    case NAV_TL:
      if (pressed) {
        // tap_code16(KC_ESC);
        tap_code16(__NAV_1_K1__);
      }
      break;
    case NAV_TR:
    // This is blank on my main layout
    //   if (pressed) {
    //     tap_code16(__NAV_3_K5__);
    //   }
      break;
    case NAV_BL:
      if (pressed) {
        // tap_code16(KC_ESC);
        tap_code16(__NAV_3_K1__);
      }
      break;
    case NAV_BR:
      if (pressed) {
        // tap_code16(LCTL(LGUI(KC_RIGHT)));
        tap_code16(__NAV_3_K5__);
      }
      break;
    case NUM_TL:
      if (pressed) {
        tap_code16(__NUMPAD_1_K1__);
      }
      break;
    case NUM_TR:
      if (pressed) {
        tap_code16(__NUMPAD_1_K5__);
      }
      break;
    case NUM_BL:
      if (pressed) {
        tap_code16(__NUMPAD_3_K1__);
      }
      break;
    case NUM_BR:
      if (pressed) {
        tap_code16(__NUMPAD_3_K5__);
      }
      break;
    case SYM_L_TL:
      if (pressed) {
        tap_code16(__SYMBOLS_L1_K1__);
      }
      break;
    case SYM_L_TR:
      if (pressed) {
        tap_code16(__SYMBOLS_L1_K5__);
      }
      break;
    case SYM_L_BL:
      if (pressed) {
        tap_code16(__META_NAV_L1_K1__);
      }
      break;
    case SYM_L_BR:
      if (pressed) {
        tap_code16(__META_NAV_L1_K5__);
      }
      break;
    case SYM_R_TL:
      if (pressed) {
        tap_code16(__SYMBOLS_R1_K1__);
      }
      break;
    case SYM_R_TR:
      if (pressed) {
        tap_code16(__SYMBOLS_R1_K5__);
      }
      break;
    case SYM_R_BL:
      if (pressed) {
        tap_code16(__META_NAV_L2_K1__);
      }
      break;
    case SYM_R_BR:
      if (pressed) {
        tap_code16(__META_NAV_L2_K5__);
      }
// Shift Nav section
    case SHIFTNAV_TL:
      if (pressed) {
          tap_code16(__SHIFTNAV_1_K1__);
      }
      break;
    case SHIFTNAV_TR:
      if (pressed) {
          tap_code16(__SHIFTNAV_1_K5__);
      }
      break;
    case SHIFTNAV_BL:
      if (pressed) {
          tap_code16(__SHIFTNAV_3_K1__);
      }
      break;
    case SHIFTNAV_BR:
      if (pressed) {
          tap_code16(__SHIFTNAV_3_K5__);
      }
      break;
// Function section
    case FUNCTION_TL:
      if (pressed) {
          tap_code16(__FUNCTION_1_K1__);
      }
      break;
    case FUNCTION_TR:
      if (pressed) {
          tap_code16(__FUNCTION_1_K5__);
      }
      break;
    case FUNCTION_BL:
      if (pressed) {
          tap_code16(__FUNCTION_3_K1__);
      }
      break;
    case FUNCTION_BR:
      if (pressed) {
          tap_code16(__FUNCTION_3_K5__);
      }
      break;
// RGB section
    case RGB_TL:
      if (pressed) {
          tap_code16(__RGB_1_K1__);
      }
      break;
    case RGB_TR:
      if (pressed) {
          tap_code16(__RGB_1_K5__);
      }
      break;
    case RGB_BL:
      if (pressed) {
          tap_code16(__RGB_3_K1__);
      }
      break;
    case RGB_BR:
      // This key is blank on the default layout
      // if (pressed) {
      //     tap_code16(__RGB_3_K5__);
      // }
      break;
// Macros section
    case MACROS_TL:
      if (pressed) {
          tap_code16(__MACROS_1_K1__);
      }
      break;
    case MACROS_TR:
      if (pressed) {
          tap_code16(__MACROS_1_K5__);
      }
      break;
    case MACROS_BL:
      if (pressed) {
          tap_code16(__MACROS_3_K1__);
      }
      break;
    case MACROS_BR:
      if (pressed) {
          tap_code16(__MACROS_3_K5__);
      }
      break;
// Thumbs
    case THUMB_L:
      if (pressed) {
          tap_code16(__ALPHA_THUMB_L3__);
      }
      break;
    case THUMB_R:
      if (pressed) {
          tap_code16(__ALPHA_THUMB_R1__);
      }
      break;
    case ALT_THUMB_L:
      if (pressed) {
          tap_code16(__ALPHA_ALT_THUMB_L3__);
      }
      break;
    case ALT_THUMB_R:
      if (pressed) {
          tap_code16(__ALPHA_ALT_THUMB_R1__);
      }
      break;
    case THUMB_L_REACHY_NAV:
      if (pressed) {
          tap_code16(__ALPHA_THUMB_L3__);
      }
      break;
    case THUMB_R_REACHY_NUM:
      if (pressed) {
          tap_code16(__ALPHA_THUMB_R1__);
      }
      break;
    case THUMB_L_REACHY_SYM:
      if (pressed) {
          tap_code16(__ALPHA_THUMB_L1__);
      }
      break;
    case THUMB_R_REACHY_SYM:
      if (pressed) {
          tap_code16(__ALPHA_THUMB_R1__);
      }
      break;
#endif
  }
}
// END COMBOS
#endif
