// Copyright 2026
// SPDX-License-Identifier: GPL-2.0-or-later
#include "combos.h"
#include "keycodes.h"

enum combo_events {
    COMBO_ESC,
    COMBO_LOCK,
    COMBO_LENGTH, // keep last — must match COMBO_COUNT in config.h
};

// clang-format off
const uint16_t PROGMEM combo_esc[]  = {KC_Q, KC_W, COMBO_END};
const uint16_t PROGMEM combo_lock[] = {KC_COMM, KC_DOT, COMBO_END};

combo_t key_combos[] = {
    [COMBO_ESC]  = COMBO(combo_esc,  KC_ESC),
    [COMBO_LOCK] = COMBO(combo_lock, OS_LOCK), // works fine: combos feed
                                                // straight back through
                                                // process_record_user
};
// clang-format on
