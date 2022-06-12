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
#include "bigbarobord.h"
#ifdef RGB_MATRIX_ENABLE


led_config_t g_led_config = { {
    {0,      8,  9,  17, 18,     33, 34, 42, 43},
    {1,      7,  10, 16, 19,     32, 35, 41, 44},
    {2,      6,  11, 15, 20,     31, 36, 40, 45},
    {3,      5,  12, 14, 21,     30, 37, 39, 46},
    {4,      13, 22, 23, 24,     27, 28, 29, 38},
    {NO_LED, 25, 26, 51, NO_LED, 50, 49, 48, 47}
}, {
    {22, 1}, {14, 11}, {7, 20}, {0, 30}, {13, 38}, {21, 28}, {28, 18}, {36, 9}, {44, 0}, {62, 1},
    {55, 5}, {47, 20}, {39, 30}, {31, 40}, {54, 37}, {61, 27}, {69, 18}, {77, 8}, {92, 14}, {85, 24},
    {77, 33}, {69, 43}, {44, 49}, {61, 55}, {77, 63}, {86, 51}, {136, 51}, {145, 63}, {161, 56}, {178, 49},
    {153, 43}, {145, 33}, {137, 24}, {130, 14}, {145, 8}, {153, 18}, {161, 27}, {168, 37}, {191, 40}, {183, 30},
    {175, 20}, {167, 11}, {160, 1}, {178, 0}, {186, 9}, {194, 18}, {201, 28}, {209, 38}, {223, 30}, {215, 20},
    {208, 11}, {200, 1}
}, {
    4, 4, 4, 4, 1, 4, 4, 4, 4, 4,
    4, 4, 4, 1, 4, 4, 4, 4, 4, 4,
    4, 4, 1, 1, 1, 1, 1, 1, 1, 1,
    4, 4, 4, 4, 4, 4, 4, 4, 1, 4,
    4, 4, 4, 4, 4, 4, 4, 1, 4, 4,
    4, 4
} };

#endif

/*
22, 1
14, 11
7, 20
0, 30
13, 38
21, 28
28, 18
36, 9
44, 0
62, 1
55, 5
47, 20
39, 30
31, 40
54, 37
61, 27
69, 18
77, 8
92, 14
85, 24
77, 33
69, 43
44, 49
61, 55
77, 63
86, 51
136, 51
145, 63
161, 56
178, 49
153, 43
145, 33
137, 24
130, 14
145, 8
153, 18
161, 27
168, 37
191, 40
183, 30
175, 20
167, 11
160, 1
178, 0
186, 9
194, 18
201, 28
209, 38
223, 30
215, 20
208, 11
200, 1
*/