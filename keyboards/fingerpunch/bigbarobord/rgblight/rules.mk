# Build Options
#   change yes to no to disable
#
RGBLIGHT_ENABLE = yes
RGB_MATRIX_ENABLE = no
PIMORONI_TRACKBALL_ENABLE = no
OLED_DRIVER_ENABLE = no
ENCODER_ENABLE = no

ifeq ($(strip $(PIMORONI_TRACKBALL_ENABLE)), yes)
    POINTING_DEVICE_ENABLE := yes
    SRC += drivers/sensors/pimoroni_trackball.c
    QUANTUM_LIB_SRC += i2c_master.c
    OPT_DEFS += -DPIMORONI_TRACKBALL_ENABLE
endif
