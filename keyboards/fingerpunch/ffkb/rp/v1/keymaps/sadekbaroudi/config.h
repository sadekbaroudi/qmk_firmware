// --------------------------- Other keyboard build specific configs ------------------------------
#ifdef FFKB_TRACKPOINT_BUILD
#undef ENCODERS_PAD_A
#undef ENCODERS_PAD_B
#ifdef RGBLIGHT_LED_COUNT
    #undef RGBLIGHT_LED_COUNT
#endif
#define RGBLIGHT_LED_COUNT 7
#define PS2_CLOCK_PIN GP8
#define PS2_DATA_PIN  GP7
#endif
