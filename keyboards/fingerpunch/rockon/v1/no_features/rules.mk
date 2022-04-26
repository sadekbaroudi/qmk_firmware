# MCU name
MCU = atmega32u4

# Bootloader selection
#   Teensy       halfkay
#   Pro Micro    caterina
#   Atmel DFU    atmel-dfu
#   LUFA DFU     lufa-dfu
#   QMK DFU      qmk-dfu
#   ATmega32A    bootloadHID
#   ATmega328P   USBasp
BOOTLOADER = atmel-dfu

# Build Options
#   change yes to no to disable
#
RGBLIGHT_ENABLE = no
RGB_MATRIX_ENABLE = no
PIMORONI_TRACKBALL_ENABLE = no
OLED_ENABLE = no
OLED_DRIVER_ENABLE = no
ENCODER_ENABLE = no

ifeq ($(strip $(PIMORONI_TRACKBALL_ENABLE)), yes)
    POINTING_DEVICE_ENABLE := yes
    SRC += drivers/sensors/pimoroni_trackball.c
    QUANTUM_LIB_SRC += i2c_master.c
    OPT_DEFS += -DPIMORONI_TRACKBALL_ENABLE
endif
