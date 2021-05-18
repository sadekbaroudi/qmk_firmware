/* Copyright 2021 Sadek Baroudi <sadekbaroudi@gmail.com>
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

#include "quantum.h"

/* This a shortcut to help you visually see your layout.
 *
 * The first section contains all of the arguments representing the physical
 * layout of the board and position of the keys.
 *
 * The second converts the arguments into a two-dimensional array which
 * represents the switch matrix.
 */
#define LAYOUT_euclid36( \
    K00, K01, K02, K03, K04,      K09, K08, K07, K06, K05, \
    K10, K11, K12, K13, K14,      K19, K18, K17, K16, K15, \
    K20, K21, K22, K23, K24,      K29, K28, K27, K26, K25, \
              K32, K33, K34,      K37, K36, K35 \
) \
{ \
    { K00,   K01,   K02, K03, K04, K05,   K06, K07, K08,   K09 }, \
    { K10,   K11,   K12, K13, K14, K15,   K16, K17, K18,   K19 }, \
    { K20,   K21,   K22, K23, K24, K25,   K26, K27, K28,   K29 }, \
    { KC_NO, KC_NO, K32, K33, K34, KC_NO, KC_NO, K35, K36, K37 } \
}
