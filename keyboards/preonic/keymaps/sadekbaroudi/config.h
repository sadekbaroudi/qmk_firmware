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

#define MIDI_BASIC

/*
Sadek:

#define TAPPING_FORCE_HOLD
https://beta.docs.qmk.fm/using-qmk/software-features/tap_hold#tapping-force-hold

This causes a problem when I try to quickly type a keystroke, followed by another keystroke that is on another layer, and the key to get to that layer uses the same key that I just typed.
For instance, my space key is also a LT -> 1... So if I type the string "Hello -- testing" very quickly, where the dash is LT -> 1 (a key), and space is the key I use to get to layer 1. If I type fast enough, then it just prints two spaces, and won't let me go to layer 1. Anyway, it's confusing, but just turn this feature on. It's off by default


#define IGNORE_MOD_TAP_INTERRUPT
This one screws me up when I type too fast. Currently, when I try to type the following string:
"test text"
what happens is the space ends up sending shift-t since I use the spacebar as shift as well. I type quickly and press the T key before I let go of the space and it reads it as capital T. Enabling this setting fixes the issue.

 */
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
