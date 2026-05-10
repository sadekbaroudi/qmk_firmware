VIK_POINTING_LEFT ?= no
VIK_POINTING_RIGHT ?= no

# Cirque driver selection. Default to SPI to preserve existing behavior for
# boards that just set CIRQUE_ENABLE=yes. Boards / build menus may instead set
# CIRQUE_SPI=yes or CIRQUE_I2C=yes (mutually exclusive) to pick the bus.
CIRQUE_DRIVER ?= spi

ifeq ($(strip $(CIRQUE_SPI)), yes)
	CIRQUE_ENABLE := yes
	CIRQUE_DRIVER := spi
endif

ifeq ($(strip $(CIRQUE_I2C)), yes)
	CIRQUE_ENABLE := yes
	CIRQUE_DRIVER := i2c
endif

ifeq ($(strip $(VIK_RGB_ONLY)), yes)
	OPT_DEFS += -DVIK_RGB_ONLY
endif
