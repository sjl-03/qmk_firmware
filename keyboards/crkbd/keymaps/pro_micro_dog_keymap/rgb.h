// Copyright 2026
// SPDX-License-Identifier: GPL-2.0-or-later
#pragma once

#include QMK_KEYBOARD_H

// Sets underglow to the colour assigned to `layer` (see rgb.c). Safe to
// call with any uint8_t; out-of-range values fall back to the base color.
void rgb_set_layer_color(uint8_t layer);
