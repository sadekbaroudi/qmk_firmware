SRC += sadekbaroudi.c \
       process_records.c

COMMAND_ENABLE   = no  # Commands for debug and configuration
CONSOLE_ENABLE = no         # Console for debug
UNICODE_ENABLE   = no  # Unicode
SWAP_HANDS_ENABLE= no  # Allow swapping hands of keyboard
BACKLIGHT_ENABLE = no
NKRO_ENABLE      = no
RAW_ENABLE       = no
CASEMODES_ENABLE = yes
COMBO_ENABLE     = yes
LTO_ENABLE       = no

# UNCOMMENT TO DISABLE MACROS
#EXTRAFLAGS     += -flto
# UNCOMMENT TO DISABLE MACROS

SPACE_CADET_ENABLE    = no
GRAVE_ESC_ENABLE      = no



ifneq ($(strip $(NO_SECRETS)), yes)
    ifneq ("$(wildcard $(USER_PATH)/secrets.c)","")
        SRC += secrets.c
    endif
    ifeq ($(strip $(NO_SECRETS)), lite)
        OPT_DEFS += -DNO_SECRETS
    endif
endif

ifeq ($(strip $(RGBLIGHT_ENABLE)), yes)
    SRC += rgb_stuff.c
    ifeq ($(strip $(RGBLIGHT_NOEEPROM)), yes)
        OPT_DEFS += -DRGBLIGHT_NOEEPROM
    endif
endif

# RGB_MATRIX_ENABLE ?= no
# ifneq ($(strip $(RGB_MATRIX_ENABLE)), no)
#     SRC += rgb_matrix_stuff.c
# endif

ifdef CONSOLE_ENABLE
    ifeq ($(strip $(KEYLOGGER_ENABLE)), yes)
        OPT_DEFS += -DKEYLOGGER_ENABLE
    endif
endif

ifeq ($(strip $(RAW_ENABLE)), yes)
    SRC += hid.c
endif

ifeq ($(strip $(ENCODER_ENABLE)), yes)
    SRC += encoder_stuff.c
endif

ifeq ($(strip $(CASEMODES_ENABLE)), yes)
    SRC += casemodes.c
endif

ifeq ($(strip $(COMBO_ENABLE)), yes)
    SRC += combos.c
endif

ifeq ($(strip $(PIMORONI_TRACKBALL_ENABLE)), yes)
    POINTING_DEVICE_ENABLE := yes
    SRC += drivers/sensors/pimoroni_trackball.c
    QUANTUM_LIB_SRC += i2c_master.c
    OPT_DEFS += -DPIMORONI_TRACKBALL_ENABLE
endif

