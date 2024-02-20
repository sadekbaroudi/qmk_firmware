# See https://github.com/sadekbaroudi/vik

# rules.mk options
# VIK_ENABLE
# VIK_HAPTIC
# VIK_PER56_CIRQUE_LEDS
# VIK_PER56_PMW3360_LEDS
# VIK_PMW3360
# VIK_WEACT_ST7735
# VIK_VIK_GC9A01
# VIK_WAVESHARE_22224
# VIK_AZOTEQ
# VIK_EC11_EVQWGD001
# VIK_TRACKPOINT
# VIK_PEACOCK

ifeq ($(strip $(VIK_HAPTIC)), yes)
   HAPTIC_ENABLE = yes
   HAPTIC_DRIVER = drv2605l
   OPT_DEFS += -DVIK_HAPTIC
endif

ifeq ($(strip $(VIK_PER56_CIRQUE_LEDS)), yes)
   CIRQUE_ENABLE = yes
   ENCODER_ENABLE = yes
#    RGBLIGHT_ENABLE = yes # you need to choose whether or not this is enabled within the keyboard or user rules.mk
   OPT_DEFS += -DVIK_PER56_CIRQUE_LEDS
endif

ifeq ($(strip $(VIK_PER56_PMW3360_LEDS)), yes)
   PMW3360_ENABLE = yes
   ENCODER_ENABLE = yes
#    RGBLIGHT_ENABLE = yes # you need to choose whether or not this is enabled within the keyboard or user rules.mk
   OPT_DEFS += -DVIK_PER56_PMW3360_LEDS
endif

ifeq ($(strip $(VIK_PMW3360)), yes)
   PMW3360_ENABLE = yes
   OPT_DEFS += -DVIK_PMW3360
endif

ifeq ($(strip $(VIK_WEACT_ST7735)), yes)
   # For LCD backlight toggling
   BACKLIGHT_ENABLE = yes
   BACKLIGHT_DRIVER = software

   QUANTUM_PAINTER_ENABLE = yes
   QUANTUM_PAINTER_DRIVERS += st7735_spi
   QUANTUM_PAINTER_LVGL_INTEGRATION = yes
   SRC += keyboards/fingerpunch/src/display/st7735.c
#    WPM_ENABLE 					= yes
   OPT_DEFS += -DVIK_WEACT_ST7735
endif

ifeq ($(strip $(VIK_GC9A01)), yes)
   QUANTUM_PAINTER_ENABLE = yes
   QUANTUM_PAINTER_DRIVERS += gc9a01_spi
   QUANTUM_PAINTER_LVGL_INTEGRATION = yes
   SRC += keyboards/fingerpunch/src/display/gc9a01.c
#    WPM_ENABLE 					= yes
   OPT_DEFS += -DVIK_GC9A01
endif

ifeq ($(strip $(VIK_WAVESHARE_22224)), yes)
   QUANTUM_PAINTER_ENABLE = yes
   QUANTUM_PAINTER_DRIVERS += st7789_spi
   QUANTUM_PAINTER_LVGL_INTEGRATION = yes
   SRC += keyboards/fingerpunch/src/display/waveshare_22224.c
#    WPM_ENABLE 					= yes
   OPT_DEFS += -DVIK_WAVESHARE_22224
endif

ifeq ($(strip $(VIK_AZOTEQ)), yes)
   POINTING_DEVICE_ENABLE := yes
   POINTING_DEVICE_DRIVER := azoteq_iqs5xx
   OPT_DEFS += -DVIK_AZOTEQ
endif

ifeq ($(strip $(VIK_EC11_EVQWGD001)), yes)
   ENCODER_ENABLE := yes
   OPT_DEFS += -DVIK_EC11_EVQWGD001
endif

ifeq ($(strip $(VIK_TRACKPOINT)), yes)

   ###### OVERALL FINDINGS SO FAR
   # AVR interrupt mode doesn't work for RP2040, as it requires PAL_MODE_OUTPUT_OPENDRAIN, which isn't provided for RP2040
   # https://github.com/qmk/qmk_firmware/blob/master/docs/feature_ps2_mouse.md#interrupt-version-arm-chibios-idinterrupt-version-chibios
   # https://github.com/qmk/qmk_firmware/pull/22615#issuecomment-1841537237

   # USART mode won't work, since the pins on the VIK controllers don't use USART for GPIO 1 and GPIO 2
   # https://github.com/qmk/qmk_firmware/blob/master/docs/feature_ps2_mouse.md#usart-version-idusart-version

   # The only thing that's left is busywait, which is not recommended by QMK, and also requires PAL_MODE_OUTPUT_OPENDRAIN
   # https://github.com/qmk/qmk_firmware/blob/master/docs/feature_ps2_mouse.md#busywait-version-idbusywait-version

   # So, our only option is to use two consecutive pins, which means we can't even use the VIK connector...

   # Options are:
   # 1) hand wire from VIK module to a PCB with consecutive GPIO available (assuming RP2040), or hand wire to any two GPIO for non-RP2040 controllers. This also requires a bodge for 3.3v (untested) or a logic level conversion between 3.3v and 5v if using a 3.3v controller
   # 2) figure out an alternative way to get a driver working in QMK with PAL_MODE_OUTPUT_OPENDRAIN on an RP2040 (I don't even know if this is possible)
   ######

   ###### Actual VIK logic and options below:
   # Uncomment these two lines, and one of the modes to test the various options, see:
   # https://discord.com/channels/939959680611020840/1179500491525328926/1189474876386459678
   # PS2_MOUSE_ENABLE = yes
   # PS2_ENABLE = yes

   # Busywait mode: https://github.com/qmk/qmk_firmware/blob/master/docs/feature_ps2_mouse.md#busywait-version-idbusywait-version
   # PS2_DRIVER = busywait

   # If using this mode, also see: keyboards/fingerpunch/svlinky/halconf.h
   # ARM interrupt mode: https://github.com/qmk/qmk_firmware/blob/master/docs/feature_ps2_mouse.md#interrupt-version-arm-chibios-idinterrupt-version-chibios
   # PS2_DRIVER = interrupt

   # RP2040 pio / vendor mode: https://github.com/qmk/qmk_firmware/blob/master/docs/feature_ps2_mouse.md#rp2040-pio-version-idrp2040-pio-version
   # PS2_DRIVER = vendor

   OPT_DEFS += -DVIK_TRACKPOINT
endif

ifeq ($(strip $(VIK_PEACOCK)), yes)
   OPT_DEFS += -DVIK_PEACOCK
   I2C_DRIVER_REQUIRED = yes
   DIGITIZER_ENABLE = yes
   DIGITIZER_DRIVER = maxtouch
endif

ifeq ($(strip $(VIK_RGB_ONLY)), yes)
   OPT_DEFS += -DVIK_RGB_ONLY
endif

ifeq ($(strip $(PMW3360_ENABLE)), yes)
   POINTING_DEVICE_ENABLE := yes
   POINTING_DEVICE_DRIVER := pmw3360
   QUANTUM_LIB_SRC += spi_master.c
   OPT_DEFS += -DVIK_TRACKBALL_ENABLE
endif

ifeq ($(strip $(CIRQUE_ENABLE)), yes)
   MOUSEKEY_ENABLE := yes  # not required, but enabling for mouse button keys
   POINTING_DEVICE_ENABLE := yes
   POINTING_DEVICE_DRIVER = cirque_pinnacle_spi
   OPT_DEFS += -DCIRQUE_ENABLE
endif

ifeq ($(strip $(QUANTUM_PAINTER_ENABLE)), yes)
   SRC += keyboards/fingerpunch/src/display/fp_display.c
endif