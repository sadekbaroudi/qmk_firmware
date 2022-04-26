/*
Copyright 2021 Sadek Baroudi <sadekbaroudi@gmail.com>

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#ifndef XOIVIOX_RGBMATRIX
#define XOIVIOX_RGBMATRIX
#endif

#ifndef XOIVIOX_OLED
#define XOIVIOX_OLED
#endif

#undef ENCODERS_PAD_A
#define ENCODERS_PAD_A {D7, D4}
#undef ENCODERS_PAD_B
#define ENCODERS_PAD_B {B4, D6}

#pragma once
#include "config_common.h"
