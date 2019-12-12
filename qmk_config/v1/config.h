/*
Copyright 2019 KW

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

#ifndef V1_CONFIG_H
#define V1_CONFIG_H

#include "../config.h"

#define DEVICE_VER      0x0001

#define MATRIX_ROW_PINS { F0, F1, F4, F5, F6 }
#define MATRIX_COL_PINS { D6, D7, B4, B5, B6 }
#define UNUSED_PINS

#define ENCODERS_PAD_A { C6, D2 }
#define ENCODERS_PAD_B { C7, D3 }
#define ENCODER_RESOLUTION 4

#define DIODE_DIRECTION COL2ROW

#define COMBO_COUNT 	3

#endif
