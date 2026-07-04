// Copyright 2026
// SPDX-License-Identifier: GPL-2.0-or-later
//
// Luna, the OLED pet. Built from simple text-cell "ASCII art" rather than
// a raw pixel bitmap: it's original artwork, trivially easy to tweak, and
// (unlike a hand-written byte-array bitmap) there's no risk of it
// compiling fine but rendering as garbage because a byte was mistyped.
// If you want the denser pixel-art look of your old Sofle pet, swap
// luna_render()'s oled_write_P calls for oled_write_raw_P with your own
// frame data — everything else in this file (state machine, timers,
// hooks) stays the same.
#include "luna.h"

enum luna_mood {
    LUNA_IDLE,
    LUNA_BLINK,
    LUNA_HAPPY,
    LUNA_SLEEPY,
};

static uint32_t last_activity   = 0;
static uint32_t last_blink      = 0;
static bool     blinking        = false;
static uint32_t happy_until     = 0;

#define LUNA_BLINK_EVERY_MS 4000
#define LUNA_BLINK_HOLD_MS 150
#define LUNA_HAPPY_HOLD_MS 600
#define LUNA_SLEEPY_AFTER_MS 60000

void luna_on_keypress(void) {
    last_activity = timer_read32();
    happy_until   = last_activity + LUNA_HAPPY_HOLD_MS;
}

void luna_task(void) {
    uint32_t now = timer_read32();

    if (!blinking && timer_elapsed32(last_blink) > LUNA_BLINK_EVERY_MS) {
        blinking  = true;
        last_blink = now;
    } else if (blinking && timer_elapsed32(last_blink) > LUNA_BLINK_HOLD_MS) {
        blinking  = false;
        last_blink = now;
    }
}

static enum luna_mood luna_current_mood(void) {
    uint32_t now = timer_read32();

    if (now < happy_until) {
        return LUNA_HAPPY;
    }
    if (timer_elapsed32(last_activity) > LUNA_SLEEPY_AFTER_MS) {
        return LUNA_SLEEPY;
    }
    if (blinking) {
        return LUNA_BLINK;
    }
    return LUNA_IDLE;
}

void luna_render(void) {
    switch (luna_current_mood()) {
        case LUNA_HAPPY:
            oled_write_P(PSTR(" /\\_/\\ \n( ^.^ )\n > w <  "), false);
            break;
        case LUNA_SLEEPY:
            oled_write_P(PSTR(" /\\_/\\ \n( -.-)zZ\n >   <  "), false);
            break;
        case LUNA_BLINK:
            oled_write_P(PSTR(" /\\_/\\ \n( -.- )\n > ^ <  "), false);
            break;
        case LUNA_IDLE:
        default:
            oled_write_P(PSTR(" /\\_/\\ \n( o.o )\n > ^ <  "), false);
            break;
    }
}
