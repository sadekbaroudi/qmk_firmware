/* Copyright 2022 Sadek Baroudi
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include "keyboards/fingerpunch/src/fp_audio.h"

#ifdef AUDIO_ENABLE

#include "song_list.h"
#include "musical_notes.h"

/**
#define BREVE_NOTE(note) MUSICAL_NOTE(note, 128)
#define WHOLE_NOTE(note) MUSICAL_NOTE(note, 64)
#define HALF_NOTE(note) MUSICAL_NOTE(note, 32)
#define QUARTER_NOTE(note) MUSICAL_NOTE(note, 16)
#define EIGHTH_NOTE(note) MUSICAL_NOTE(note, 8)
#define SIXTEENTH_NOTE(note) MUSICAL_NOTE(note, 4)
#define THIRTYSECOND_NOTE(note) MUSICAL_NOTE(note, 2)

#define BREVE_DOT_NOTE(note) MUSICAL_NOTE(note, 128 + 64)
#define WHOLE_DOT_NOTE(note) MUSICAL_NOTE(note, 64 + 32)
#define HALF_DOT_NOTE(note) MUSICAL_NOTE(note, 32 + 16)
#define QUARTER_DOT_NOTE(note) MUSICAL_NOTE(note, 16 + 8)
#define EIGHTH_DOT_NOTE(note) MUSICAL_NOTE(note, 8 + 4)
#define SIXTEENTH_DOT_NOTE(note) MUSICAL_NOTE(note, 4 + 2)
#define THIRTYSECOND_DOT_NOTE(note) MUSICAL_NOTE(note, 2 + 1)
 */

#define FP_MOUSE_SOUND_1 EIGHTH_NOTE(_B2),
#define FP_MOUSE_SOUND_2 EIGHTH_NOTE(_B3),
#define FP_MOUSE_SOUND_3 EIGHTH_NOTE(_B2), EIGHTH_NOTE(_B2),

#define FP_CUT_SOUND EIGHTH_NOTE(_B4), EIGHTH_NOTE(_B3), EIGHTH_NOTE(_B4),
#define FP_COPY_SOUND EIGHTH_NOTE(_B3), EIGHTH_NOTE(_B4),
#define FP_PASTE_SOUND EIGHTH_NOTE(_B4), EIGHTH_NOTE(_B3),

#define FP_SAVE_SOUND EIGHTH_NOTE(_F4), EIGHTH_NOTE(_F5),

#define FP_STARTUP_LIGHT HALF_NOTE(_E6), HALF_NOTE(_F6), HALF_NOTE(_C6), WHOLE_NOTE(_A5), WHOLE_DOT_NOTE(_F5),
#define FP_STARTUP_LIGHT_EXT HALF_NOTE(_E6), HALF_NOTE(_F6), HALF_NOTE(_C6), WHOLE_NOTE(_A5), WHOLE_DOT_NOTE(_F5), WHOLE_DOT_NOTE(_D5), WHOLE_DOT_NOTE(_G5), WHOLE_DOT_NOTE(_C5),
#define FP_STARTUP_DARK  HALF_DOT_NOTE(_B5), QUARTER_NOTE(_B5), HALF_NOTE(_E6), HALF_NOTE(_REST), QUARTER_NOTE(_C6), QUARTER_NOTE(_REST), QUARTER_NOTE(_G5), QUARTER_NOTE(_E5), QUARTER_NOTE(_F5), QUARTER_NOTE(_GS5), QUARTER_NOTE(_G5), QUARTER_NOTE(_F5), WHOLE_NOTE(_G5),
#define FP_STARTUP_FLOW_DOWN WHOLE_NOTE(_E6), HALF_NOTE(_REST), HALF_NOTE(_C6), WHOLE_NOTE(_G5), HALF_NOTE(_A5), WHOLE_NOTE(_D5), WHOLE_NOTE(_E5), WHOLE_NOTE(_C5),

float fp_mouse_sound_1[][2] = SONG(FP_MOUSE_SOUND_1);
float fp_mouse_sound_2[][2] = SONG(FP_MOUSE_SOUND_2);
float fp_mouse_sound_3[][2] = SONG(FP_MOUSE_SOUND_3);

float fp_cut_sound[][2] = SONG(FP_CUT_SOUND);
float fp_copy_sound[][2] = SONG(FP_COPY_SOUND);
float fp_paste_sound[][2] = SONG(FP_PASTE_SOUND);

float fp_save_sound[][2] = SONG(FP_SAVE_SOUND);

float fp_startup_light[][2] = SONG(FP_STARTUP_LIGHT);
float fp_startup_light_ext[][2] = SONG(FP_STARTUP_LIGHT_EXT);
float fp_startup_dark[][2] = SONG(FP_STARTUP_DARK);
float fp_startup_flow_down[][2] = SONG(FP_STARTUP_FLOW_DOWN);

layer_state_t fp_layer_state_set_audio(layer_state_t state) {
    switch (get_highest_layer(state)) {
        default:
            break;
    }
    return state;
}

bool fp_process_record_audio(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
#       ifndef FP_DISABLE_CUSTOM_KEYCODES
        // NOTE TO SELF: IF I EVER ADD KEYCODES HERE, DETERMINE WHETHER THEY ARE CONSIDERED CUSTOM KEYCODES OR NOT
        // In the case of the mouse buttons and ctrl-x,c,v,s features below, they are treated independently, so they aren't effected by FP_DISABLE_CUSTOM_KEYCODES
#       endif // FP_DISABLE_CUSTOM_KEYCODES
#       ifdef FP_AUDIO_MOUSE_BUTTONS
        case MS_BTN1:
            if (record->event.pressed) {
                PLAY_SONG(fp_mouse_sound_1);
            }
            break;
        case MS_BTN2:
            if (record->event.pressed) {
                PLAY_SONG(fp_mouse_sound_2);
            }
            break;
        case MS_BTN3:
            if (record->event.pressed) {
                PLAY_SONG(fp_mouse_sound_3);
            }
            break;
#       endif
#       ifdef FP_AUDIO_CUT_COPY_PASTE
        case KC_C: // copy
            if (record->event.pressed) {
#               ifdef FP_MAC_PREFERRED
                if ((get_mods() & MOD_MASK_GUI) || (get_oneshot_mods() & MOD_MASK_GUI)) {
#               else
                if ((get_mods() & MOD_MASK_CTRL) || (get_oneshot_mods() & MOD_MASK_CTRL)) {
#               endif
                    PLAY_SONG(fp_copy_sound);
                }
            }
            break;
        case KC_X: // cut
            if (record->event.pressed) {
#               ifdef FP_MAC_PREFERRED
                if ((get_mods() & MOD_MASK_GUI) || (get_oneshot_mods() & MOD_MASK_GUI)) {
#               else
                if ((get_mods() & MOD_MASK_CTRL) || (get_oneshot_mods() & MOD_MASK_CTRL)) {
#               endif
                    PLAY_SONG(fp_cut_sound);
                }
            }
            break;
        case KC_V: // paste
            if (record->event.pressed) {
#               ifdef FP_MAC_PREFERRED
                if ((get_mods() & MOD_MASK_GUI) || (get_oneshot_mods() & MOD_MASK_GUI)) {
#               else
                if ((get_mods() & MOD_MASK_CTRL) || (get_oneshot_mods() & MOD_MASK_CTRL)) {
#               endif
                    PLAY_SONG(fp_paste_sound);
                }
            }
            break;
#       endif
#       ifdef FP_AUDIO_SAVE
        case KC_S: // save
        case LALT_T(KC_S): // for my keymap, since I use homerow mods
            if (record->event.pressed) {
#               ifdef FP_MAC_PREFERRED
                if ((get_mods() & MOD_MASK_GUI) || (get_oneshot_mods() & MOD_MASK_GUI)) {
#               else
                if ((get_mods() & MOD_MASK_CTRL) || (get_oneshot_mods() & MOD_MASK_CTRL)) {
#               endif
                    PLAY_SONG(fp_save_sound);
                }
            }
            break;
#endif
        default:
            break;
    }

    return true;
}
#endif
