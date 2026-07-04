// Copyright 2026
// SPDX-License-Identifier: GPL-2.0-or-later
//
// These are the ONLY custom keycodes in the whole keymap. Everything else
// is a stock QMK keycode. Each one below means "do the right thing for
// whichever OS mode is currently active" — see os.c for the mapping.
#pragma once

#include QMK_KEYBOARD_H

enum custom_keycodes {
    OS_TOGG = SAFE_RANGE, // flip Mac <-> Windows mode (persists to EEPROM)
    OS_COPY,              // Cmd+C   / Ctrl+C
    OS_PASTE,             // Cmd+V   / Ctrl+V
    OS_CUT,               // Cmd+X   / Ctrl+X
    OS_UNDO,              // Cmd+Z   / Ctrl+Z
    OS_REDO,              // Cmd+Shift+Z / Ctrl+Y
    OS_LOCK,              // Cmd+Ctrl+Q  / Win+L
    OS_TABF,              // Cmd+Tab / Alt+Tab            (switch app forward)
    OS_TABB,              // Cmd+Shift+Tab / Alt+Shift+Tab (switch app backward)
    OS_LINE_L,            // Cmd+Left / Home              (start of line)
    OS_LINE_R,            // Cmd+Right / End              (end of line)
    OS_WORD_L,            // Alt+Left / Ctrl+Left          (word back)
    OS_WORD_R,            // Alt+Right / Ctrl+Right        (word forward)
};
