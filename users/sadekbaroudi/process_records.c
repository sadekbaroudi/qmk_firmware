#include "sadekbaroudi.h"
#include "casemodes.h"

 // for alternating between 45 degree angle routing and free angle routing with one key
bool kicad_free_angle_routing = false;

__attribute__((weak)) bool process_record_keymap(uint16_t keycode, keyrecord_t *record) { return true; }

__attribute__((weak)) bool process_record_secrets(uint16_t keycode, keyrecord_t *record) { return true; }

// Defines actions tor my global custom keycodes. Defined in sadekbaroudi.h file
// Then runs the _keymap's record handler if not processed here
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    #ifdef CASEMODES_ENABLE
    // Process case modes
    if (!process_case_modes(keycode, record)) {
        return false;
    }
    // If console is enabled, it will print the matrix position and status of each key pressed
    #endif

    if (!(process_record_keymap(keycode, record) && process_record_secrets(keycode, record))) {
        return false;
    }

    switch (keycode) {
        case C_CAPSWORD:
            // NOTE: if you change this behavior, may want to update in keymap.c for COMBO behavior
            #ifdef CASEMODES_ENABLE
            if (record->event.pressed) {
                enable_caps_word();
            }
            #endif
            break;
        case C_HYPHENCASE:
            #ifdef CASEMODES_ENABLE
            if (record->event.pressed) {
                enable_xcase_with(KC_MINS);
            }
            #endif
            break;
        case C_ANYCASE:
            #ifdef CASEMODES_ENABLE
            if (record->event.pressed) {
                enable_xcase();
            }
            #endif
            break;
        case C_UNDERSCORECASE:
            #ifdef CASEMODES_ENABLE
            if (record->event.pressed) {
                enable_xcase_with(KC_UNDS);
            }
            #endif
            break;
	case U_KVM_SWITCH:
	    if (record->event.pressed) {
                register_code(KC_TAB);
		SEND_STRING(SS_DELAY(10) SS_TAP(X_RIGHT) SS_DELAY(10));
		unregister_code(KC_TAB);
	    }
	    break;
        // COMMENT TO DISABLE MACROS
        case M_KI_R_SWAP:
            if (record->event.pressed) {
                register_code(KC_LSFT);
                register_code(KC_LCTL);
                SEND_STRING(SS_TAP(X_COMM) SS_DELAY(300));
                unregister_code(KC_LSFT);
                unregister_code(KC_LCTL);
                // If we're in free angle routing, we tap down to go back to 45 degree angle routing
                if (kicad_free_angle_routing) {
                    SEND_STRING(SS_TAP(X_DOWN) SS_TAP(X_ENTER));
                } else {
                    SEND_STRING(SS_TAP(X_UP) SS_TAP(X_ENTER));
                }
                kicad_free_angle_routing = !kicad_free_angle_routing;
            }
            break;
        case M_KI_R_ANGLE:
            if (record->event.pressed) {
                register_code(KC_LSFT);
                register_code(KC_LCTL);
                SEND_STRING(SS_TAP(X_COMM) SS_DELAY(300));
                unregister_code(KC_LSFT);
                unregister_code(KC_LCTL);
                SEND_STRING(SS_TAP(X_UP) SS_TAP(X_ENTER));
            }
            break;
        case M_KI_R_FREE:
            if (record->event.pressed) {
                register_code(KC_LSFT);
                register_code(KC_LCTL);
                SEND_STRING(SS_TAP(X_COMM) SS_DELAY(300));
                unregister_code(KC_LSFT);
                unregister_code(KC_LCTL);
                SEND_STRING(SS_TAP(X_DOWN) SS_TAP(X_ENTER));
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
        case N_DEL_LINE:
            if (record->event.pressed) {
                SEND_STRING(SS_TAP(X_END));
                register_code(KC_LSFT);
                SEND_STRING(SS_TAP(X_HOME));
                unregister_code(KC_LSFT);
                tap_code(KC_BSPC);
            } else {
                // when keycode is released
            }
            break;
        case N_SEL_LINE:
            if (record->event.pressed) {
                SEND_STRING(SS_TAP(X_END));
                register_code(KC_LSFT);
                SEND_STRING(SS_TAP(X_HOME));
                unregister_code(KC_LSFT);
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
        case P_ARROW:
            if (record->event.pressed) {
                SEND_STRING("->");
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
        case G_GOD_ON:
            if (record->event.pressed) {
                register_code(KC_LSFT);
                SEND_STRING(SS_TAP(X_ENTER));
                unregister_code(KC_LSFT);
                SEND_STRING("GOD MODE ENGAGED"SS_TAP(X_ENTER));
            } else {
                // when keycode is released
            }
            break;
        case G_GOD_OFF:
            if (record->event.pressed) {
                register_code(KC_LSFT);
                SEND_STRING(SS_TAP(X_ENTER));
                unregister_code(KC_LSFT);
                SEND_STRING("GOD MODE DISENGAGED"SS_TAP(X_ENTER));
            } else {
                // when keycode is released
            }
            break;
        case G_PULLING:
            if (record->event.pressed) {
                SEND_STRING(SS_TAP(X_ENTER)"I am pulling, play safe"SS_TAP(X_ENTER));
            } else {
                // when keycode is released
            }
            break;
        case G_PUSH:
            if (record->event.pressed) {
                SEND_STRING(SS_TAP(X_ENTER)"Push the lane out"SS_TAP(X_ENTER));
            } else {
                // when keycode is released
            }
            break;
        // COMMENT TO DISABLE MACROS
    }
    return true;
}
