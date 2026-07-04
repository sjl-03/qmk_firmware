// Copyright 2026
// SPDX-License-Identifier: GPL-2.0-or-later
//
// Layers only. Everything else (home row mod behaviour, OS switching,
// OLED, RGB, combos, key overrides) lives in its own file — see
// keyboard.h for the full list.
//
// Thumb keys, both layers (they don't change with layer, only tap-vs-hold
// output does):
//   left:  LT(_NUM, KC_ESC)   MO(_NAV)   KC_SPC
//   right: KC_ENT             MO(_SYM)   LT(_FUN, KC_BSPC)
// Holding _NAV and _SYM together momentarily activates _ADJUST (see
// layer_state_set_user in keyboard.c).
#include "keyboard.h"

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    [_BASE] = LAYOUT_split_3x6_3(
      KC_TAB,   KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,             KC_Y,    KC_U,    KC_I,    KC_O,      KC_P,      KC_BSPC,
      CW_TOGG,  HR_A,    HR_S,    HR_D,    HR_F,    KC_G,             KC_H,    HR_J,    HR_K,    HR_L,      HR_SCLN,   KC_QUOT,
      KC_LSFT,  KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,             KC_N,    KC_M,    KC_COMM, KC_DOT,    KC_SLSH,   KC_RSFT,
                          LT(_NUM, KC_ESC), MO(_NAV), KC_SPC,         KC_ENT,  MO(_SYM), LT(_FUN, KC_BSPC)
    ),

    [_NAV] = LAYOUT_split_3x6_3(
      KC_TRNS,  KC_NO,     KC_NO,   KC_NO,     KC_NO,      KC_NO,            KC_PGUP,  OS_LINE_L,  KC_UP,   OS_LINE_R,  OS_TABB,       OS_TABF,
      KC_TRNS,  KC_LGUI,   KC_LALT, KC_LCTL,   KC_LSFT,    KC_NO,            KC_PGDN,  KC_LEFT,    KC_DOWN, KC_RGHT,    OS_WORD_L,     OS_WORD_R,
      KC_TRNS,  OS_UNDO,   OS_CUT,  OS_COPY,   OS_PASTE,   KC_NO,            OS_REDO,  KC_NO,      KC_NO,   KC_NO,      QK_REPEAT_KEY, KC_NO,
                            KC_TRNS, KC_TRNS,   KC_TRNS,          KC_TRNS,  KC_TRNS,  KC_TRNS
    ),

    [_SYM] = LAYOUT_split_3x6_3(
      KC_TRNS,  KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC,          KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN,           KC_BSPC,
      KC_TRNS,  KC_MINS, KC_UNDS, KC_EQL,  KC_PLUS, KC_GRV,           KC_TILD, KC_LBRC, KC_RBRC, KC_LCBR, KC_RCBR,           KC_PIPE,
      KC_TRNS,  KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,            KC_BSLS, KC_SLSH, S(KC_SLSH), KC_NO, QK_ALT_REPEAT_KEY, KC_NO,
                         KC_TRNS, KC_TRNS, KC_TRNS,          KC_TRNS, KC_TRNS, KC_TRNS
    ),

    [_NUM] = LAYOUT_split_3x6_3(
      KC_TRNS,  KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,            KC_SLSH, KC_7,    KC_8,    KC_9,    KC_ASTR, KC_BSPC,
      KC_TRNS,  KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT, KC_NO,            KC_DOT,  KC_4,    KC_5,    KC_6,    KC_PLUS, KC_ENT,
      KC_TRNS,  KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,            KC_0,    KC_1,    KC_2,    KC_3,    KC_MINS, KC_EQL,
                         KC_TRNS, KC_TRNS, KC_TRNS,          KC_TRNS, KC_TRNS, KC_TRNS
    ),

    [_FUN] = LAYOUT_split_3x6_3(
      KC_TRNS,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,            KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,
      KC_TRNS,  KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT, KC_F12,           KC_MPRV, KC_MPLY, KC_MNXT, KC_MUTE, KC_VOLD, KC_VOLU,
      KC_TRNS,  KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,            KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
                         KC_TRNS, KC_TRNS, KC_TRNS,          KC_TRNS, KC_TRNS, KC_TRNS
    ),

    [_ADJUST] = LAYOUT_split_3x6_3(
      QK_BOOT,  KC_NO,    KC_NO,    KC_NO,    KC_NO,   KC_NO,            KC_NO,     KC_NO,     KC_NO,     KC_NO,     KC_NO,     QK_BOOT,
      KC_NO,    OS_TOGG,  KC_NO,    KC_NO,    KC_NO,   KC_NO,            RGB_TOG,   RGB_MOD,   RGB_HUI,   RGB_SAI,   RGB_VAI,   OS_LOCK,
      KC_NO,    DM_REC1,  DM_REC2,  DM_RSTP,  KC_NO,   KC_NO,            RGB_RMOD,  DM_PLY1,   DM_PLY2,   RGB_HUD,   RGB_SAD,   RGB_VAD,
                          KC_TRNS,  KC_TRNS,  KC_TRNS,          KC_TRNS,  KC_TRNS,  KC_TRNS
    ),
};
// clang-format on
