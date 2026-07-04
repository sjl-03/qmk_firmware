// Copyright 2026
// SPDX-License-Identifier: GPL-2.0-or-later
//
// Home row mods, QWERTY, GACS order (pinky -> index = GUI, ALT, CTRL, SHIFT).
// The actual "don't misfire while typing fast" behaviour comes from
// config.h (PERMISSIVE_HOLD, HOLD_ON_OTHER_KEY_PRESS, CHORDAL_HOLD) plus
// the per-key tapping term below — that combination is what people mean
// when they say "Achordion-style" home row mods; it's now built into QMK
// core so there's no external library to vendor in.
#pragma once

#include QMK_KEYBOARD_H

#define HR_A LGUI_T(KC_A)
#define HR_S LALT_T(KC_S)
#define HR_D LCTL_T(KC_D)
#define HR_F LSFT_T(KC_F)

#define HR_J RSFT_T(KC_J)
#define HR_K RCTL_T(KC_K)
#define HR_L RALT_T(KC_L)
#define HR_SCLN RGUI_T(KC_SCLN)

// Defined in homerow.c, called by QMK core (declared here just for
// documentation/discoverability — QMK finds it by name, not via this
// header).
uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record);
