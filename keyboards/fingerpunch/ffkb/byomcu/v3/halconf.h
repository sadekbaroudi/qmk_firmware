/*
 * Copyright 2022 Charly Delay <charly@codesink.dev> (@0xcharly)
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#pragma once

#if defined(CONVERT_TO_ELITE_PI) || defined(CONVERT_TO_RP2040_CE) || defined(CONVERT_TO_HELIOS) || defined(CONVERT_TO_LIATRIS) || defined(CONVERT_TO_KB2040) || defined(CONVERT_TO_SPARKFUN_RP2040)
#define HAL_USE_PWM    TRUE
#define HAL_USE_I2C    TRUE
#define HAL_USE_PAL    TRUE
#define HAL_USE_SPI    TRUE
#endif // CONVERT_TO_(any_rp2040)

#ifdef CONVERT_TO_STEMCELL
#define HAL_USE_SERIAL TRUE
#define HAL_USE_SPI TRUE
#define SPI_USE_WAIT TRUE
#define SPI_SELECT_MODE SPI_SELECT_MODE_PAD
#endif

#include_next "halconf.h"
