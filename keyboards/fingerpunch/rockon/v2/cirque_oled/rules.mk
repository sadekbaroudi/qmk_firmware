# Build Options
#   change yes to no to disable
#
RGBLIGHT_ENABLE = no
RGB_MATRIX_ENABLE = no
PIMORONI_TRACKBALL_ENABLE = no
OLED_ENABLE = yes
ENCODER_ENABLE = no
CIRQUE_ENABLE = yes
MOUSEKEY_ENABLE = yes

ifeq ($(strip $(CIRQUE_ENABLE)), yes)
   POINTING_DEVICE_ENABLE = yes
   POINTING_DEVICE_DRIVER = cirque_pinnacle_i2c
endif

ifeq ($(strip $(PIMORONI_TRACKBALL_ENABLE)), yes)
    POINTING_DEVICE_ENABLE := yes
    SRC += drivers/sensors/pimoroni_trackball.c
    QUANTUM_LIB_SRC += i2c_master.c
    OPT_DEFS += -DPIMORONI_TRACKBALL_ENABLE
endif
