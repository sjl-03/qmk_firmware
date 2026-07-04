// Copyright 2026
// SPDX-License-Identifier: GPL-2.0-or-later
#pragma once

#include QMK_KEYBOARD_H

// Call every matrix scan (from matrix_scan_user) to drive animation timing.
void luna_task(void);

// Call from oled_task_user() to draw Luna at the cursor position it leaves
// the OLED in.
void luna_render(void);

// Call from process_record_user() on every keypress so Luna perks up.
void luna_on_keypress(void);
