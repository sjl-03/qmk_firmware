// Copyright 2026
// SPDX-License-Identifier: GPL-2.0-or-later
#include "homerow.h"

// Index-finger SHIFT mods (F, J) need to resolve fast since they're used
// constantly for capitalisation while typing at speed. Pinky/ring GUI,
// ALT and CTRL mods are held deliberately far more often than tapped
// mid-word, so they get a longer window before they're forced to "hold".
uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case HR_F:
        case HR_J:
            return TAPPING_TERM - 20;

        case HR_A:
        case HR_SCLN:
        case HR_D:
        case HR_K:
            return TAPPING_TERM + 30;

        case HR_S:
        case HR_L:
            return TAPPING_TERM + 15;

        default:
            return TAPPING_TERM;
    }
}
