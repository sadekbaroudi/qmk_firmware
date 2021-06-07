#include "hid.h"
#include "raw_hid.h"
#include <stdbool.h>
#include <string.h>
#ifdef RGBLIGHT_ENABLE
#include "rgblight.h"
#endif

#define RAW_EPSIZE 32

__attribute__((weak)) bool raw_hid_receive_keymap(uint8_t *data, uint8_t length) { return false; }

void raw_hid_receive(uint8_t *data, uint8_t length) {
	#ifdef RGBLIGHT_ENABLE
	if (raw_hid_receive_keymap(data, length)) {
		return;
	}

	// Send back the data to debug/validate on the client. This code can be removed once confirmed stable
	raw_hid_send(data, length);

	for (int i = 0; i < length; i++) {
		if (i < RGBLED_NUM) {
			if (data[i] != 0) {
				rgblight_sethsv_at(data[i], 255, 255, i);
			}
		}
	}
	#endif
}