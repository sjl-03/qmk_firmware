// Copyright 2026
// SPDX-License-Identifier: GPL-2.0-or-later
//
// Shared declarations used across keymap.c / keyboard.c / rgb.c / luna.c.
// The layer enum lives here (instead of being duplicated) so every module
// can refer to layers by name.
#pragma once

#include QMK_KEYBOARD_H
#include "keycodes.h"
#include "os.h"
#include "homerow.h"
#include "luna.h"
#include "rgb.h"

enum layers {
    _BASE = 0,
    _NAV,
    _SYM,
    _NUM,
    _FUN,
    _ADJUST,
};

#define LAYER_COUNT 6
