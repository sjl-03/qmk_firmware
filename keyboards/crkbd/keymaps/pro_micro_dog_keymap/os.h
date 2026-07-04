// Copyright 2026
// SPDX-License-Identifier: GPL-2.0-or-later
//
// Runtime Mac <-> Windows switching. One base layer, one set of keycodes;
// the *meaning* of GUI/ALT and a handful of shortcut keycodes changes
// depending on os_get_mode(). This replaces having two duplicate base
// layers.
#pragma once

#include QMK_KEYBOARD_H

typedef enum {
    OS_MODE_MAC = 0,
    OS_MODE_WINDOWS = 1,
} os_mode_t;

// Call once from keyboard_post_init_user().
void os_init(void);

os_mode_t   os_get_mode(void);
void        os_set_mode(os_mode_t mode);
void        os_toggle_mode(void);
const char *os_mode_name(void); // "MAC" or "WIN", for the OLED

// Handles all OS_* keycodes from keycodes.h. Returns false when it
// consumed the keypress (caller should stop further processing), true
// otherwise.
bool os_process_record(uint16_t keycode, keyrecord_t *record);
