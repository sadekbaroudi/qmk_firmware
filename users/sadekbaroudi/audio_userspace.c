#ifdef AUDIO_ENABLE
#include "audio_userspace.h"
#include "song_list.h"
#include "musical_notes.h"

#define ZELDA_SECRET_SONG HALF_NOTE(_G6), HALF_NOTE(_FS6), HALF_NOTE(_DS6), HALF_NOTE(_A5), HALF_NOTE(_GS5), HALF_NOTE(_E6), HALF_NOTE(_G6), WHOLE_DOT_NOTE(_AS6)

float zelda_secret_song[][2] = SONG(ZELDA_SECRET_SONG);
#endif
