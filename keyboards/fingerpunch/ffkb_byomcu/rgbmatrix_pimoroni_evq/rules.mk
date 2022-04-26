# Build Options
#   change yes to no to disable
#
RGBLIGHT_ENABLE = no
RGB_MATRIX_ENABLE = yes
PIMORONI_TRACKBALL_ENABLE = yes
OLED_DRIVER_ENABLE = no
ENCODER_ENABLE = yes

ifeq ($(strip $(PIMORONI_TRACKBALL_ENABLE)), yes)
    POINTING_DEVICE_ENABLE := yes
    POINTING_DEVICE_DRIVER = pimoroni_trackball
    OPT_DEFS += -DPIMORONI_TRACKBALL_ENABLE
endif
