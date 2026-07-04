// Copyright 2026
// SPDX-License-Identifier: GPL-2.0-or-later
//
// Whole-board underglow colour indicates the active layer. Uses rgblight
// (not RGB Matrix) — see rules.mk if you want per-key RGB Matrix instead.
#include "rgb.h"
#include "keyboard.h"

typedef struct {
    uint8_t h;
    uint8_t s;
    uint8_t v;
} layer_color_t;

// clang-format off
static const layer_color_t layer_colors[LAYER_COUNT] = {
    [_BASE]   = {  0,   0, 130 }, // White
    [_NAV]    = {149, 255, 180 }, // Blue
    [_SYM]    = {197, 255, 180 }, // Purple
    [_NUM]    = { 43, 255, 180 }, // Yellow
    [_FUN]    = { 85, 255, 180 }, // Green
    [_ADJUST] = {  0, 255, 180 }, // Red
};
// clang-format on

void rgb_set_layer_color(uint8_t layer) {
    if (layer >= LAYER_COUNT) {
        layer = _BASE;
    }
    rgblight_sethsv_noeeprom(layer_colors[layer].h, layer_colors[layer].s, layer_colors[layer].v);
}
