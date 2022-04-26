# MCU name
MCU = STM32F401

# Bootloader selection
BOOTLOADER = stm32-dfu

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
#RGBLIGHT_ENABLE = yes
#RGBLIGHT_DRIVER = WS2812
RGB_MATRIX_ENABLE = yes
RGB_MATRIX_DRIVER = WS2812
#// disable testing
WS2812_DRIVER = pwm

MIDI_ENABLE = no            # MIDI support
UNICODE_ENABLE = no         # Unicode
BLUETOOTH_ENABLE = no       # Enable Bluetooth with the Adafruit EZ-Key HID
AUDIO_ENABLE = no           # Audio output on port C6
FAUXCLICKY_ENABLE = no      # Use buzzer to emulate clicky switches
ENCODER_ENABLE = no
OLED_ENABLE = yes
# EXTRAFLAGS     += -flto     # macros disabled, if you need the extra space
MOUSEKEY_ENABLE = yes

# disable testing
# EEPROM_DRIVER = spi
DEBOUNCE_TYPE = asym_eager_defer_pk
OPT_DEFS += -DSTM32_DMA_REQUIRED=TRUE

KEYBOARD_SHARED_EP = yes    # Free up some extra endpoints - needed if console+mouse+extra

CIRQUE_ENABLE = yes

DEFERRED_EXEC_ENABLE             = yes
ENCODER_MAP_ENABLE               = yes

# // disable testing
ifeq ($(strip $(CIRQUE_ENABLE)), yes)
   POINTING_DEVICE_ENABLE = yes
   POINTING_DEVICE_DRIVER = cirque_pinnacle_i2c
endif
