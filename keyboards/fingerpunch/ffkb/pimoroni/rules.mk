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
PIMORONI_TRACKBALL_ENABLE = yes
OLED_DRIVER_ENABLE = no
ENCODER_ENABLE = no

ifeq ($(strip $(PIMORONI_TRACKBALL_ENABLE)), yes)
    POINTING_DEVICE_ENABLE := yes
    POINTING_DEVICE_DRIVER = pimoroni_trackball
    OPT_DEFS += -DPIMORONI_TRACKBALL_ENABLE
endif
