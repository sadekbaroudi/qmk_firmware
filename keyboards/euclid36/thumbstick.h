#pragma once

typedef enum {
    THUMBSTICK_MODE_MOUSE = 0,
    THUMBSTICK_MODE_ARROWS,
    THUMBSTICK_MODE_SCROLL,
    _THUMBSTICK_MODE_LAST  // Do not use, except for looping through enum values
} thumbstick_mode_t;

// Parameters
#define THUMBSTICK_DEAD_ZONE 15  // Values below this are ignored (deadzone)
#define THUMBSTICK_FINE_ZONE 40  // Values below this enable fine movement

#define THUMBSTICK_MODE THUMBSTICK_MODE_MOUSE
#define THUMBSTICK_SPEED 40  // Range [0 - 127]
#define THUMBSTICK_FINE_SPEED 20
#define THUMBSTICK_SCROLL_SPEED 1

#define THUMBSTICK_EIGHT_AXIS true
#define THUMBSTICK_AXIS_SEPARATION 24  // range [0 - 127], angle away from diagonals

// Implicit and derived constants
#define THUMBSTICK_TIMEOUT 10          // Mouse report throttling time in ms
#define THUMBSTICK_SCROLL_TIMEOUT 200  // Mouse scroll throttling time in ms
#define THUMBSTICK_RANGE_START 0
#define THUMBSTICK_RANGE_STOP 1023
#define THUMBSTICK_RANGE_CENTER (THUMBSTICK_RANGE_STOP - THUMBSTICK_RANGE_START + 1) / 2
#define THUMBSTICK_RANGE_MOVEMENT (THUMBSTICK_RANGE_CENTER - THUMBSTICK_DEAD_ZONE)
#if THUMBSTICK_SPEED > 127
#    undef THUMBSTICK_SPEED
#    define THUMBSTICK_SPEED 127
#endif

#include "timer.h"
#include "analog.h"
#include "pointing_device.h"
#include "lib/lib8tion/lib8tion.h"

#if defined THUMBSTICK_DEBUG
#    include "print.h"
uint16_t rawX;
uint16_t rawY;
uint16_t distX;
uint16_t distY;
uint16_t thumbstickLogTimer;
#endif

typedef struct {
    thumbstick_mode_t mode;
} thumbstick_config_t;

typedef struct {
    int16_t x;
    int16_t y;
} thumbstick_vector_t;

typedef struct {
    bool up;
    bool right;
    bool down;
    bool left;
} thumbstick_direction_t;

typedef struct {
    thumbstick_config_t    config;
    thumbstick_vector_t    vector;
    thumbstick_direction_t direction;
    thumbstick_direction_t lastDirection;
    report_mouse_t         report;
} thumbstick_state_t;

uint16_t thumbstickTimer;
uint16_t thumbstickScrollTimer;

thumbstick_state_t thumbstick_state;

void thumbstick_mode_set(thumbstick_mode_t mode);
void thumbstick_vector_set(thumbstick_vector_t vector);

thumbstick_mode_t   thumbstick_mode_get(void);
thumbstick_vector_t thumbstick_vector_get(void);

void thumbstick_mode_cycle_forward(void);
void thumbstick_mode_cycle_backward(void);

void thumbstick_init(void);

// Axis-level wrapper to read raw value, do logging and calculate speed
int8_t thumbstick_get_component(uint8_t pin);

// Get mouse speed
int8_t thumbstick_get_mouse_speed(int8_t component);

// Fix direction within one of 8 axes (or 4 if 8-axis is disabled)
thumbstick_direction_t thumbstick_get_discretized_direction(thumbstick_vector_t vector, bool eightAxis);

// Read analog values into vectors
void thumbstick_read_vectors(void);

// Perform actions based on state
void thumbstick_process_state(report_mouse_t*);

void update_keycode_status(uint16_t keycode, bool last, bool current);