// See https://github.com/sadekbaroudi/vik

/**
 * Modules:
 * VIK_HAPTIC
 * VIK_PER56_CIRQUE_LEDS
 * VIK_PER56_PMW3360_LEDS
 * VIK_PMW3360
 * VIK_WEACT_ST7735
 * VIK_VIK_GC9A01
 * VIK_WAVESHARE_22224
 * VIK_AZOTEQ
 * VIK_EC11_EVQWGD001
 * VIK_TRACKPOINT
 * VIK_PEACOCK
 * 
 * Pin config:
 * VIK_SPI_DRIVER
 * VIK_SPI_SCK_PIN
 * VIK_SPI_MOSI_PIN
 * VIK_SPI_MISO_PIN
 * VIK_SPI_CS
 * VIK_I2C_DRIVER
 * VIK_I2C_SDA_PIN
 * VIK_I2C_SCL_PIN
 * VIK_GPIO_1
 * VIK_GPIO_2
 * VIK_WS2812_DI_PIN
 * 
 * Options:
 * VIK_RGB_ONLY
 * VIK_RETAIN_KB_WS2812_DI_PIN
 */

// For VIK SPI
#ifndef SPI_SCK_PIN
    #define SPI_SCK_PIN VIK_SPI_SCK_PIN
#endif
#ifndef SPI_MOSI_PIN
    #define SPI_MOSI_PIN VIK_SPI_MOSI_PIN
#endif
#ifndef SPI_MISO_PIN
    #define SPI_MISO_PIN VIK_SPI_MISO_PIN
#endif
#ifndef SPI_DRIVER
    #define SPI_DRIVER VIK_SPI_DRIVER
#endif

#ifndef VIK_I2C_DRIVER
    #define VIK_I2C_DRIVER I2CD1
#endif

#ifndef I2C_DRIVER
    #define I2C_DRIVER VIK_I2C_DRIVER
#endif

#ifndef I2C1_SCL_PIN
    #define I2C1_SCL_PIN VIK_I2C_SCL_PIN
#endif

#ifndef I2C1_SDA_PIN
    #define I2C1_SDA_PIN VIK_I2C_SDA_PIN
#endif

// This can be removed after upgrading QMK to the latest version
#ifndef WS2812_DI_PIN
    #define WS2812_DI_PIN VIK_WS2812_DI_PIN
#endif

#ifndef WS2812_DI_PIN
    #define WS2812_DI_PIN VIK_WS2812_DI_PIN
#endif

#ifdef VIK_HAPTIC
    #define FB_ERM_LRA 1
    #define FB_BRAKEFACTOR 3 // For 1x:0, 2x:1, 3x:2, 4x:3, 6x:4, 8x:5, 16x:6, Disable Braking:7
    #define FB_LOOPGAIN 1 // For  Low:0, Medium:1, High:2, Very High:3
    #define RATED_VOLTAGE 2
    #define V_PEAK 2.8
    #define V_RMS 2.0
    #define F_LRA 150 // resonance freq
    #define DRV_GREETING  alert_750ms
    #define FP_HAPTIC_MOUSE_BUTTONS
    #define FP_HAPTIC_CUT_COPY_PASTE
    #define FP_HAPTIC_SAVE
#endif

#ifdef VIK_PER56_CIRQUE_LEDS
    #ifdef RGBLED_NUM
        #undef RGBLED_NUM
    #endif
    #if !defined(VIK_RETAIN_KB_WS2812_DI_PIN)
        #ifdef WS2812_DI_PIN
            #undef WS2812_DI_PIN
        #endif
        #define WS2812_DI_PIN VIK_WS2812_DI_PIN
    #endif
    #define RGBLED_NUM 4
#endif

#ifdef VIK_PER56_PMW3360_LEDS
    // Trackball config
    #define PMW33XX_CS_PIN VIK_SPI_CS
    #define PMW33XX_CPI 1000
    #define PMW33XX_CS_DIVISOR 8

    #ifdef RGBLED_NUM
        #undef RGBLED_NUM
    #endif
    #if !defined(VIK_RETAIN_KB_WS2812_DI_PIN)
        #ifdef WS2812_DI_PIN
            #undef WS2812_DI_PIN
        #endif
        #define WS2812_DI_PIN VIK_WS2812_DI_PIN
    #endif
    #define RGBLED_NUM 4
#endif

#ifdef VIK_PMW3360
    // Trackball config
    #define PMW33XX_CS_PIN VIK_SPI_CS
    #define PMW33XX_CPI 1000
    #define PMW33XX_CS_DIVISOR 8
#endif

#ifdef VIK_WEACT_ST7735
    // /* LCD config */
    #define DISPLAY_CS_PIN VIK_SPI_CS
    #define DISPLAY_DC_PIN VIK_GPIO_1

    // To dynamically control the backlight with BL_TOGG keycode
    #define BACKLIGHT_PIN VIK_GPIO_2

    // Must be defined by the keyboard itself, needs a free unused pin for reset
    #define DISPLAY_RST_PIN VIK_ST7735_UNUSED_PIN
#endif

#ifdef VIK_GC9A01
    // /* LCD config */
    #define DISPLAY_CS_PIN VIK_SPI_CS
    #define DISPLAY_DC_PIN VIK_GPIO_1

    // To dynamically control the backlight with BL_TOGG keycode
    #define DISPLAY_RST_PIN VIK_GPIO_2
#endif

#ifdef VIK_WAVESHARE_22224
    // /* LCD config */
    #define DISPLAY_CS_PIN VIK_SPI_CS
    #define DISPLAY_DC_PIN VIK_GPIO_1

    // To dynamically control the backlight with BL_TOGG keycode
    #define BACKLIGHT_PIN VIK_GPIO_2

    // Must be defined by the keyboard itself, needs a free unused pin for reset
    #define DISPLAY_RST_PIN VIK_ST7735_UNUSED_PIN
#endif

#ifdef VIK_AZOTEQ
    // default to AZOTEQ_IQS5XX_TPS43... shouldn't really do this
    #if !defined(AZOTEQ_IQS5XX_TPS43) && !defined(AZOTEQ_IQS5XX_TPS65)
        // #warning "fingerpunch:vik:azoteq: no azoteq profile defined, defaulted to AZOTEQ_IQS5XX_TPS43"
        #define AZOTEQ_IQS5XX_TPS43
        #define AZOTEQ_IQS5XX_PRESS_AND_HOLD_ENABLE true
        #define AZOTEQ_IQS5XX_SWIPE_X_ENABLE true
        #define AZOTEQ_IQS5XX_SWIPE_Y_ENABLE true
        #define AZOTEQ_IQS5XX_ZOOM_ENABLE true
        // Can only use motion pin on unibodies
        #ifndef SPLIT_KEYBOARD
            #define POINTING_DEVICE_MOTION_PIN VIK_GPIO_2
        #endif
    #endif
#endif

#ifdef VIK_EC11_EVQWGD001
    #ifdef VIK_RGB_ONLY
        #ifdef RGBLED_NUM
            #undef RGBLED_NUM
        #endif
        #if !defined(VIK_RETAIN_KB_WS2812_DI_PIN)
            #ifdef WS2812_DI_PIN
                #undef WS2812_DI_PIN
            #endif
            #define WS2812_DI_PIN VIK_WS2812_DI_PIN
        #endif
        #define RGBLED_NUM 4
    #endif
#endif

#ifdef VIK_TRACKPOINT
    #define PS2_CLOCK_PIN VIK_GPIO_2
    #define PS2_DATA_PIN  VIK_GPIO_1
#endif

#ifdef VIK_PEACOCK
    // Can only use motion pin on unibodies
    #ifndef SPLIT_KEYBOARD
        #define DIGITIZER_MOTION_PIN VIK_GPIO_1
        #define DIGITIZER_MOTION_PIN_ACTIVE_LOW yes
        #define POINTING_DEVICE_MOTION_PIN VIK_GPIO_1
    #endif
#endif

#ifdef CIRQUE_ENABLE
    #define CIRQUE_PINNACLE_SPI_CS_PIN VIK_SPI_CS
#endif