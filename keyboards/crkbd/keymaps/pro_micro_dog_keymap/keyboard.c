// Copyright 2026
// SPDX-License-Identifier: GPL-2.0-or-later
//
// This file is the ONLY place QMK's global hook functions
// (process_record_user, layer_state_set_user, oled_task_user, ...) are
// defined. Each one is a thin dispatcher into whichever module actually
// owns that behaviour (os.c, luna.c, rgb.c) — this file itself has no
// feature logic of its own, just wiring, plus one small example key
// override.
#include "keyboard.h"

// ---------------------------------------------------------------------
// Init
// ---------------------------------------------------------------------
void keyboard_post_init_user(void) {
    os_init();
    rgb_set_layer_color(_BASE);
}

// ---------------------------------------------------------------------
// Layers -> tri-layer (_NAV + _SYM held together = _ADJUST) + RGB
// ---------------------------------------------------------------------
layer_state_t layer_state_set_user(layer_state_t state) {
    state = update_tri_layer_state(state, _NAV, _SYM, _ADJUST);
    rgb_set_layer_color(get_highest_layer(state));
    return state;
}

// ---------------------------------------------------------------------
// Keypress dispatch: OS shortcuts first, then let Luna know we're typing
// ---------------------------------------------------------------------
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (!os_process_record(keycode, record)) {
        return false;
    }
    if (record->event.pressed) {
        luna_on_keypress();
    }
    return true;
}

// ---------------------------------------------------------------------
// Scan loop: only Luna's animation timer needs polling
// ---------------------------------------------------------------------
void matrix_scan_user(void) {
    luna_task();
}

// ---------------------------------------------------------------------
// OLED
// ---------------------------------------------------------------------
oled_rotation_t oled_init_user(oled_rotation_t rotation) {
    return OLED_ROTATION_270;
}

static const char *layer_name(uint8_t layer) {
    switch (layer) {
        case _BASE:   return "Base";
        case _NAV:    return "Nav";
        case _SYM:    return "Sym";
        case _NUM:    return "Num";
        case _FUN:    return "Fun";
        case _ADJUST: return "Adjust";
        default:      return "?";
    }
}

static void render_status(void) {
    oled_write_P(PSTR("Layer: "), false);
    oled_write_ln(layer_name(get_highest_layer(layer_state)), false);

    oled_write_P(PSTR("OS:    "), false);
    oled_write_ln(os_mode_name(), false);

    oled_write_P(PSTR("WPM:   "), false);
    oled_write_ln(get_u8_str(get_current_wpm(), ' '), false);

    oled_write_P(PSTR("\n"), false);
}

bool oled_task_user(void) {
    render_status();
    luna_render();
    return false;
}

// ---------------------------------------------------------------------
// Key overrides: one small example — Shift+Backspace sends Delete.
// Add more entries to the array below as you find shortcuts you want.
// ---------------------------------------------------------------------
const key_override_t delete_key_override = ko_make_basic(MOD_MASK_SHIFT, KC_BSPC, KC_DEL);

const key_override_t *key_overrides[] = {
    &delete_key_override,
    NULL,
};
