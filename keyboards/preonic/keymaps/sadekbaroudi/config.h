#pragma once

#ifdef AUDIO_ENABLE
    #define STARTUP_SONG SONG(PREONIC_SOUND)
    // #define STARTUP_SONG SONG(NO_SOUND)

    #define DEFAULT_LAYER_SONGS { SONG(QWERTY_SOUND), \
                                  SONG(COLEMAK_SOUND), \
                                  SONG(DVORAK_SOUND) \
                                }
#endif

#define MUSIC_MASK (keycode != KC_NO)

/*
 * MIDI options
 */

/* Prevent use of disabled MIDI features in the keymap */
//#define MIDI_ENABLE_STRICT 1

/* enable basic MIDI features:
   - MIDI notes can be sent when in Music mode is on
*/

// #define MIDI_BASIC

/* ws2812 RGB LED */
#undef RGB_DI_PIN
#define RGB_DI_PIN B3 
#undef RGBLED_NUM
#define RGBLED_NUM 16      // Number of LEDs
#define RGBLIGHT_ANIMATIONS
#define RGBLIGHT_HUE_STEP 2
#define RGBLIGHT_SAT_STEP 8
#define RGBLIGHT_VAL_STEP 8
#define RGBLIGHT_LIMIT_VAL 255
#define RGBLIGHT_SLEEP
#define RGBLIGHT_LAYERS

#define TAPPING_FORCE_HOLD
#define IGNORE_MOD_TAP_INTERRUPT

/* enable advanced MIDI features:
   - MIDI notes can be added to the keymap
   - Octave shift and transpose
   - Virtual sustain, portamento, and modulation wheel
   - etc.
*/
//#define MIDI_ADVANCED

/* override number of MIDI tone keycodes (each octave adds 12 keycodes and allocates 12 bytes) */
//#define MIDI_TONE_KEYCODE_OCTAVES 2
