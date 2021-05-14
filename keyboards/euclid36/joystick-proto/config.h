#pragma once

#define DEVICE_VER 0x0002


#ifdef THUMBSTICK_ENABLE
//#    define THUMBSTICK_FLIP_X
//#    define THUMBSTICK_FLIP_Y // uncomment for PSP joystick, comment for trackpoint, but need to fix this so they're the same TODO
#    define THUMBSTICK_PIN_X F7
#    define THUMBSTICK_PIN_Y F6
#endif
