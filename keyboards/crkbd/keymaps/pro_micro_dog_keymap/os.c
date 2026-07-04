// Copyright 2026
// SPDX-License-Identifier: GPL-2.0-or-later
#include "os.h"
#include "keycodes.h"
#include "eeconfig.h"

// One bit of EEPROM-backed user data. QMK gives every keyboard a spare
// 32-bit "user" EEPROM block for exactly this kind of thing, so no extra
// EEPROM driver work is needed — eeconfig_read_user()/update_user() do it.
typedef union {
    uint32_t raw;
    struct {
        bool windows_mode : 1;
    };
} os_user_config_t;

static os_user_config_t os_config;

void os_init(void) {
    os_config.raw = eeconfig_read_user();
}

os_mode_t os_get_mode(void) {
    return os_config.windows_mode ? OS_MODE_WINDOWS : OS_MODE_MAC;
}

void os_set_mode(os_mode_t mode) {
    os_config.windows_mode = (mode == OS_MODE_WINDOWS);
    eeconfig_update_user(os_config.raw);
}

void os_toggle_mode(void) {
    os_set_mode(os_get_mode() == OS_MODE_MAC ? OS_MODE_WINDOWS : OS_MODE_MAC);
}

const char *os_mode_name(void) {
    return os_get_mode() == OS_MODE_MAC ? "MAC" : "WIN";
}

// Taps `mac_code` in Mac mode, `win_code` in Windows mode. Both are plain
// 16-bit keycodes, so mod-combos like LGUI(LSFT(KC_Z)) work fine here.
static void os_tap(uint16_t mac_code, uint16_t win_code) {
    tap_code16(os_get_mode() == OS_MODE_MAC ? mac_code : win_code);
}

bool os_process_record(uint16_t keycode, keyrecord_t *record) {
    // Only act on key-down; swallow the matching key-up so nothing extra
    // gets sent when the physical key is released.
    switch (keycode) {
        case OS_TOGG:
        case OS_COPY:
        case OS_PASTE:
        case OS_CUT:
        case OS_UNDO:
        case OS_REDO:
        case OS_LOCK:
        case OS_TABF:
        case OS_TABB:
        case OS_LINE_L:
        case OS_LINE_R:
        case OS_WORD_L:
        case OS_WORD_R:
            break;
        default:
            return true; // not ours, let keymap.c / QMK handle it
    }

    if (!record->event.pressed) {
        return false; // consume the release too
    }

    switch (keycode) {
        case OS_TOGG:
            os_toggle_mode();
            break;
        case OS_COPY:
            os_tap(LGUI(KC_C), LCTL(KC_C));
            break;
        case OS_PASTE:
            os_tap(LGUI(KC_V), LCTL(KC_V));
            break;
        case OS_CUT:
            os_tap(LGUI(KC_X), LCTL(KC_X));
            break;
        case OS_UNDO:
            os_tap(LGUI(KC_Z), LCTL(KC_Z));
            break;
        case OS_REDO:
            os_tap(LGUI(LSFT(KC_Z)), LCTL(KC_Y));
            break;
        case OS_LOCK:
            os_tap(LGUI(LCTL(KC_Q)), LGUI(KC_L));
            break;
        case OS_TABF:
            os_tap(LGUI(KC_TAB), LALT(KC_TAB));
            break;
        case OS_TABB:
            os_tap(LGUI(LSFT(KC_TAB)), LALT(LSFT(KC_TAB)));
            break;
        case OS_LINE_L:
            os_tap(LGUI(KC_LEFT), KC_HOME);
            break;
        case OS_LINE_R:
            os_tap(LGUI(KC_RGHT), KC_END);
            break;
        case OS_WORD_L:
            os_tap(LALT(KC_LEFT), LCTL(KC_LEFT));
            break;
        case OS_WORD_R:
            os_tap(LALT(KC_RGHT), LCTL(KC_RGHT));
            break;
    }
    return false;
}
