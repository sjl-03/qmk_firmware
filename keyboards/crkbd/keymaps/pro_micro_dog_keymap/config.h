// Copyright 2026
// SPDX-License-Identifier: GPL-2.0-or-later
#pragma once

// --- Home row mods ------------------------------------------------------
// This trio is what makes fast rolling home-row-mod typing not misfire —
// it's the built-in QMK equivalent of what people mean by "Achordion-style"
// tap-hold behaviour, no external library needed.
#define TAPPING_TERM 190
#define TAPPING_TERM_PER_KEY   // per-key term is defined in homerow.c
#define PERMISSIVE_HOLD
#define HOLD_ON_OTHER_KEY_PRESS
#define CHORDAL_HOLD           // opposite-hand key = safe to resolve hold early

// --- Combos ---------------------------------------------------------------
#define COMBO_COUNT 2   // must match COMBO_LENGTH in combos.c
#define COMBO_TERM 40   // ms — combos use plain keys, so this can be tight

// --- OLED -------------------------------------------------------------
#define OLED_TIMEOUT 60000 // sleep the OLED after 60s idle

// --- NKRO -----------------------------------------------------------------
#define FORCE_NKRO // always on, no toggle needed
