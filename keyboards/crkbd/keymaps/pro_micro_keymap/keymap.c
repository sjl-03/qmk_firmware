#include QMK_KEYBOARD_H
#include "bongo_cat.h"

// Layer names
enum layer_names { _BASE = 0, _NAV, _SYM, _NUM, _LIGHT };

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    [_BASE] = LAYOUT_split_3x6_3(
        KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                      KC_Y,    KC_U,    KC_I,     KC_O,    KC_P,    KC_BSPC,
        KC_LCTL, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                      KC_H,    KC_J,    KC_K,     KC_L,    KC_SCLN, KC_QUOT,
        KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                      KC_N,    KC_M,    KC_COMM,  KC_DOT,  KC_SLSH, KC_ESC,
        KC_LGUI, MO(1),   KC_SPC,  KC_ENT,  MO(2),   KC_RALT
    ),

    [_NAV] = LAYOUT_split_3x6_3(
        KC_TAB,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                      KC_6,    KC_7,    KC_8,     KC_9,    KC_0,    KC_BSPC,
        KC_LCTL, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   KC_LEFT, KC_DOWN, KC_UP,    KC_RIGHT,XXXXXXX, XXXXXXX,
        KC_LSFT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   KC_KB_MUTE, KC_KB_VOLUME_UP, KC_KB_VOLUME_DOWN, XXXXXXX, XXXXXXX, XXXXXXX,
        KC_LGUI, _______, KC_SPC,  KC_ENT,  TG(3),   KC_RALT
    ),

    [_SYM] = LAYOUT_split_3x6_3(
        KC_TAB,  KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC,                   KC_CIRC, KC_AMPR, KC_ASTR,  KC_LPRN, KC_RPRN, KC_BSPC,
        KC_LCTL, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   KC_MINS, KC_EQL,  KC_LBRC,  KC_RBRC, KC_BSLS, KC_GRV,
        KC_LSFT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   KC_UNDS, KC_PLUS, KC_LCBR,  KC_RCBR, KC_PIPE, KC_TILD,
        KC_LGUI, TG(3),   KC_SPC,  KC_ENT,  _______, KC_RALT
    ),

    [_NUM] = LAYOUT_split_3x6_3(
        XXXXXXX, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                      KC_6,    KC_7,    KC_8,     KC_9,    KC_0,    KC_BSPC,
        KC_CAPS, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX,  XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX,  XXXXXXX, XXXXXXX, XXXXXXX,
        KC_LGUI, TG(3),   KC_SPC,  KC_ENT,  TG(3),   KC_RALT
    ),

    [_LIGHT] = LAYOUT_split_3x6_3(
        QK_BOOT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX,  XXXXXXX, XXXXXXX, XXXXXXX,
        RM_TOGG, RM_HUEU, RM_SATU, RM_VALU, XXXXXXX, XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX,  XXXXXXX, XXXXXXX, XXXXXXX,
        RM_NEXT, RM_HUED, RM_SATD, RM_VALD, XXXXXXX, XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX,  XXXXXXX, XXXXXXX, XXXXXXX,
        KC_LGUI, _______, KC_SPC,  KC_ENT,  _______, KC_RALT
    )
};

#ifdef OLED_ENABLE

// Rotation:
// Left (status text): rotated 270
// Right (bongo raw bitmap): rotation 0
oled_rotation_t oled_init_user(oled_rotation_t rotation) {
    if (is_keyboard_left()) {
        return OLED_ROTATION_270;
    }
    return OLED_ROTATION_0;
}

// Left OLED: Caps + Layer + WPM (for troubleshooting)
static void render_status_left(void) {
    oled_set_cursor(0, 0);

    led_t led_state = host_keyboard_led_state();
    oled_write_P(led_state.caps_lock ? PSTR("Caps") : PSTR("    "), false);

    oled_set_cursor(0, 2);
    switch (get_highest_layer(layer_state)) {
        case _BASE:  oled_write_ln_P(PSTR("Main"), false);   break;
        case _NAV:   oled_write_ln_P(PSTR("Nav"), false);    break;
        case _SYM:   oled_write_ln_P(PSTR("Sym"), false);    break;
        case _NUM:   oled_write_ln_P(PSTR("Num"), false); break;
        case _LIGHT: oled_write_ln_P(PSTR("Light"), false);  break;
        default:     oled_write_ln_P(PSTR("L ?"), false);      break;
    }

    // Show WPM on line 3 (128x32 = 4 text rows usually)
    oled_set_cursor(0, 5);
    oled_write_P(PSTR("WPM: "), false);
    oled_write(get_u8_str(get_current_wpm(), ' '), false);
}

bool oled_task_user(void) {
    if (is_keyboard_left()) {
        render_status_left();
    } else {
        render_bongo_cat();
    }
    return false;
}

#endif // OLED_ENABLE
