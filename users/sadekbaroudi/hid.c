#include "hid.h"
#include "raw_hid.h"
#include <stdbool.h>
#include <string.h>
#include "rgblight.h"

#define RAW_EPSIZE 32

__attribute__((weak)) bool raw_hid_receive_keymap(uint8_t *data, uint8_t length) { return false; }

void raw_hid_receive(uint8_t *data, uint8_t length) {
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

	// // Example code if you want to send back a response to the client to use for whatever reason
	// uint8_t response[RAW_EPSIZE];
	// memset(response, 0, RAW_EPSIZE);

	// if (data[0] == 0x02) {
	// 	response[0] = 'Y';
	// } else {
	// 	response[0] = 'N';
	// }
	// raw_hid_send(response, sizeof(response));

}