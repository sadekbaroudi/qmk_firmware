# See https://github.com/sadekbaroudi/vik

# rules.mk options
# VIK_ENABLE
# VIK_HAPTIC
# VIK_ILI9341
# VIK_PER56_CIRQUE_LEDS
# VIK_PER56_PMW3360_LEDS
# VIK_PMW3360
# VIK_WEACT_ST7735
# VIK_GC9A01
# VIK_WAVESHARE_22224
# VIK_AZOTEQ
# VIK_EC11_EVQWGD001
# VIK_CIRQUE
# VIK_TRACKPOINT

# rules.mk options for split right half
# VIK_CIRQUE_RIGHT
# VIK_PER56_CIRQUE_LEDS_RIGHT
# VIK_PER56_PMW3360_LEDS_RIGHT
# VIK_PMW3360_RIGHT
# VIK_AZOTEQ_RIGHT
# VIK_EC11_EVQWGD001_RIGHT

# Cirque options (VIK boards)
# CIRQUE_ENABLE   - enables a cirque pinnacle pad on the VIK connector
# CIRQUE_DRIVER   - "spi" (default) or "i2c"
# CIRQUE_SPI      - shorthand: sets CIRQUE_ENABLE=yes and CIRQUE_DRIVER=spi
# CIRQUE_I2C      - shorthand: sets CIRQUE_ENABLE=yes and CIRQUE_DRIVER=i2c

# Up front rules
include keyboards/fingerpunch/src/vik/rules.vik.pre.mk

# Include the unibody / split left VIK features
include keyboards/fingerpunch/src/vik/rules.vik.main.general.mk
include keyboards/fingerpunch/src/vik/rules.vik.main.pointing.mk

### Begin VIK right half support, if there is a VIK module on the right half
### IMPORTANT: not all modules can work on the slave half, which is a QMK limitation
###            only those that work will be handled here
ifeq ($(strip $(SPLIT_KEYBOARD)), yes)
	include keyboards/fingerpunch/src/vik/rules.vik.right.general.mk
	include keyboards/fingerpunch/src/vik/rules.vik.right.pointing.mk
endif

# Include any post processing that's dependent on everything else
include keyboards/fingerpunch/src/vik/rules.vik.post.mk
