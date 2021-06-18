#include "combos.h"

// COMBOS - https://beta.docs.qmk.fm/using-qmk/software-features/feature_combo
const uint16_t PROGMEM undo_combo[] = {KC_Z, KC_X, COMBO_END};
// TODO - this doesn't work at all since I tuse the KC_SLSH for mouse keys. Need to change that before I can use this.
const uint16_t PROGMEM redo_combo[] = {KC_DOT, KC_SLSH, COMBO_END};
const uint16_t PROGMEM delete_combo[] = {KC_X, KC_C, COMBO_END};
//const uint16_t PROGMEM capsword_combo[] = {KC_X, KC_C, COMBO_END};

combo_t key_combos[COMBO_COUNT] = {
  [UNDO] = COMBO_ACTION(undo_combo),
  [REDO] = COMBO_ACTION(redo_combo),
  [DELETE] = COMBO_ACTION(delete_combo),
//  [CAPSWORD] = COMBO_ACTION(capsword_combo),
};

void process_combo_event(uint16_t combo_index, bool pressed) {
  switch(combo_index) {
    case UNDO:
      if (pressed) {
        tap_code16(LCTL(KC_Z));
      }
      break;
    case REDO:
      if (pressed) {
        tap_code16(LCTL(KC_Y));
      }
      break;
    case DELETE:
      if (pressed) {
        tap_code16(KC_DEL);
      }
      break;
    // case CAPSWORD:
    //   // NOTE: if you change this behavior, may want to update in process_records.c for capsword macro behavior
    //   if (pressed) {
    //     enable_caps_word();
    //   }
    //   break;
  }
}
// END COMBOS