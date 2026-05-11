# MCU name
MCU = RP2040
BOOTLOADER = rp2040

VIK_ENABLE = yes

# -----------------------------------------------------------------------------
# Translate the new fp_build.json `VIK_BUILD` flag (none|left|right) into the
# legacy VIK_BUILD_LEFT / VIK_BUILD_RIGHT make flags consumed by
# keyboards/fingerpunch/src/vik/rules.vik.*.mk. Consumers passing the legacy
# flags directly continue to work because we only set a legacy flag when the
# new flag is non-default.
VIK_BUILD ?= none
ifeq ($(strip $(VIK_BUILD)), left)
   VIK_BUILD_LEFT := yes
endif
ifeq ($(strip $(VIK_BUILD)), right)
   VIK_BUILD_RIGHT := yes
endif
# -----------------------------------------------------------------------------

# Build Options
#   change yes to no to disable
#
BOOTMAGIC_ENABLE = no       # Virtual DIP switch configuration
EXTRAKEY_ENABLE = yes       # Audio control and System control
CONSOLE_ENABLE = no        # Console for debug
COMMAND_ENABLE = no        # Commands for debug and configuration
# Do not enable SLEEP_LED_ENABLE. it uses the same timer as BACKLIGHT_ENABLE
SLEEP_LED_ENABLE = no       # Breathing sleep LED during USB suspend
# if this doesn't work, see here: https://github.com/tmk/tmk_keyboard/wiki/FAQ#nkro-doesnt-work
NKRO_ENABLE = no            # USB Nkey Rollover
BACKLIGHT_ENABLE = no       # Enable keyboard backlight functionality

# Either do RGBLIGHT_ENABLE or RGB_MATRIX_ENABLE and RGB_MATRIX_DRIVER
RGBLIGHT_ENABLE ?= no
RGB_MATRIX_ENABLE ?= no      # not supported yet, but will add
RGB_MATRIX_DRIVER = ws2812
WS2812_DRIVER = vendor

MIDI_ENABLE = no            # MIDI support
UNICODE_ENABLE = no         # Unicode
BLUETOOTH_ENABLE = no       # Enable Bluetooth with the Adafruit EZ-Key HID
FAUXCLICKY_ENABLE = no      # Use buzzer to emulate clicky switches
ENCODER_ENABLE ?= no
EXTRAFLAGS     += -flto     # macros enable or disable
MOUSEKEY_ENABLE = yes

SPLIT_KEYBOARD = yes
SERIAL_DRIVER = vendor

#HAPTIC FEEDBACK
HAPTIC_ENABLE ?= no
HAPTIC_DRIVER = drv2605l

AUDIO_ENABLE ?= yes
AUDIO_DRIVER = pwm_hardware

ifeq ($(strip $(RGB_MATRIX_ENABLE)), yes)
   RGB_MATRIX_CUSTOM_KB = yes
   OPT_DEFS += -DRGB_MATRIX_CUSTOM_KB
endif

# If you want to use VIK2 port's RGB instead of per key rgb and VIK1, enable this
FP_VIK2_RGB ?= no

ifeq ($(strip $(FP_VIK2_RGB)), yes)
   OPT_DEFS += -DFP_VIK2_RGB
endif

# include here so that if VIK enables the PMW3360, the OPT_DEFS get set appropriately for ximega
include keyboards/fingerpunch/src/rules.mk
