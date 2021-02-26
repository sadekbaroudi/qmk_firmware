#pragma once
#include "quantum.h"

bool          process_record_user_rgb_light(uint16_t keycode, keyrecord_t *record);
void          keyboard_post_init_rgb_light(void);
void          matrix_scan_rgb_light(void);
layer_state_t layer_state_set_rgb_light(layer_state_t state);
layer_state_t default_layer_state_set_rgb_light(layer_state_t state);
void          rgblight_sethsv_default_helper(uint8_t index);
void          rgblight_set_hsv_and_mode(uint8_t hue, uint8_t sat, uint8_t val, uint8_t mode);

#if defined(RGBLIGHT_TWINKLE)
void scan_rgblight_fadeout(void);
#endif
