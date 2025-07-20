#pragma once

#include "keyboards/fingerpunch/src/config_pre.h"

#define RP2040_BOOTLOADER_DOUBLE_TAP_RESET
#define RP2040_BOOTLOADER_DOUBLE_TAP_RESET_TIMEOUT 1000U

#define BOOTMAGIC_LITE_ROW 0
#define BOOTMAGIC_LITE_COLUMN 0

/* key matrix size */
/* Rows are doubled up */
#define MATRIX_ROWS 6
#define MATRIX_COLS 8

// SHIFT REGISTER
// Only needed for matrix_74hc595_spi.c
#define SHIFTREG_MATRIX_COL_CS GP9
#define SHIFTREG_DIVISOR 8 // needs to be the same as the PMW33XX_CS_DIVISOR below
#define MATRIX_ROW_PINS_SR {GP4, GP5, GP6, GP7, GP8, GP0}

#define I2C_DRIVER I2CD1

// SPI config for shift register (and trackball if enabled)
#define SPI_DRIVER SPID0
#define SPI_SCK_PIN GP22
#define SPI_MOSI_PIN GP23
#define SPI_MISO_PIN GP20

// Sadek: Modified to fit my fingerpunch firmware encoder order
// #define ENCODER_A_PINS {GP29, GP10, GP27}
// #define ENCODER_B_PINS {GP28, GP11, GP16}
// #define ENCODER_RESOLUTIONS { 1, 4, 4}
#define ENCODER_A_PINS { GP16, GP11, GP29 }
#define ENCODER_B_PINS { GP27, GP10, GP28 }
#define ENCODER_RESOLUTIONS { 4, 4, 1}

#define PMW33XX_CS_PIN GP1
#define PMW33XX_CS_DIVISOR 8 // needs to be the same as the SHIFTREG_DIVISOR above
// #define POINTING_DEVICE_INVERT_Y
#define POINTING_DEVICE_INVERT_X

#define LCD_DC_PIN GP14
#define LCD_CS_PIN GP26
#define LCD_RST_PIN GP12
// #define LCD_POWER_ENABLE_PIN GP13

#define QUANTUM_PAINTER_CONCURRENT_ANIMATIONS 8
#define QUANTUM_PAINTER_LOAD_FONTS_TO_RAM TRUE
#define QUANTUM_PAINTER_NUM_IMAGES 14
#define QUANTUM_PAINTER_SUPPORTS_256_PALETTE TRUE
#define QUANTUM_PAINTER_PIXDATA_BUFFER_SIZE 128
#define QUANTUM_PAINTER_DISPLAY_TIMEOUT 0
// #define LCD_ACTIVITY_TIMEOUT 30000

#define FB_ERM_LRA 1
#define FB_BRAKEFACTOR 3 // For 1x:0, 2x:1, 3x:2, 4x:3, 6x:4, 8x:5, 16x:6, Disable Braking:7
#define FB_LOOPGAIN 1 // For  Low:0, Medium:1, High:2, Very High:3
#define RATED_VOLTAGE 2
#define V_PEAK 2.8
#define V_RMS 2.0
#define F_LRA 150 // resonance freq
#define DRV_GREETING  alert_750ms

#ifdef BACKLIGHT_ENABLE
#define BACKLIGHT_PWM_DRIVER PWMD6
#define BACKLIGHT_PWM_CHANNEL 2
#define BACKLIGHT_PIN GP13
#define BACKLIGHT_LEVELS 1
#define BACKLIGHT_ON_STATE 1
#endif //BACKLIGHT_ENABLE

#define WS2812_DI_PIN GP25
#define RGBLIGHT_LED_COUNT 63

#define RGBLIGHT_DEFAULT_HUE 180
#define RGBLIGHT_DEFAULT_SAT 255
#define RGBLIGHT_DEFAULT_VAL 75
#define RGBLIGHT_SLEEP

#ifdef RGB_MATRIX_ENABLE

#ifdef MCU_HELIOS
  #define WS2812_DI_PIN GP25
#else
  #define WS2812_DI_PIN GP27
#endif
#define WS2812_DI_PIN GP25

#define DRIVER_LED_TOTAL 63
#define RGB_MATRIX_LED_COUNT 63

#endif // defined(RGB_MATRIX_ENABLE)

#include "keyboards/fingerpunch/src/config_post.h"
