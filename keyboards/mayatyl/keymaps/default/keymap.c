// Copyright 2023 QMK
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

enum layers {
    LAYER_DEFAULT,
    LAYER_SYMBOL,
    LAYER_MEDIA,
};

enum custom_keycodes {
    MCR_PRNS = SAFE_RANGE, // ()
    MCR_BRCS,              // {}
    MCR_BRCKTS,            // []
    MCR_ANGLS,             // <>
    MCR_ASSGN,             // :=
    MCR_NE,                // !=
    MCR_LE,                // <=
    MCR_GE,                // >=
};

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /*
     * ┌───┬───┬───┬───┬───┬───┐
     * │ ` │ 1 │ 2 │ 3 │ 4 │ 5 │
     * ├───┼───┼───┼───┼───┼───┤
     * │Tab│ Q │ W │ E │ R │ T │
     * ├───┼───┼───┼───┼───┼───┤
     * │Cap│ A │ S │ D │ F │ G │
     * ├───┼───┼───┼───┼───┼───┤
     * │Sft│ Z │ X │ C │ V │ B │
     * ├───┼───┼───┼───┼───┼───┤
     * │Ctl│Win│Alt│   │
     * └───┴───┴───┴───┘
     */
    [LAYER_DEFAULT] = LAYOUT(
        // Left
        KC_GRAVE, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,
        KC_TAB,   KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,
        KC_CAPS,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,
        KC_LSFT,  KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,
        KC_LCTL,  KC_LGUI, KC_LALT, KC_LNG2,
                                    LSFT_T(KC_SPC), LT(LAYER_SYMBOL, KC_TAB), MO(LAYER_MEDIA),
                                        KC_LEFT, KC_RIGHT,

        // Right
        KC_6,    KC_7,    KC_8,     KC_9,    KC_0,         KC_MINUS, KC_EQUAL,
        KC_Y,    KC_U,    KC_I,     KC_O,    KC_P,         KC_LBRC,  KC_RBRC,
        KC_H,    KC_J,    KC_K,     KC_L,    KC_SEMICOLON, KC_QUOTE, KC_BSLS,
        KC_N,    KC_M,    KC_COMMA, KC_DOT,  KC_SLASH,     KC_UP,
                          KC_LNG1,  KC_ESC,  KC_LEFT,      KC_DOWN,  KC_RIGHT,
        LT(LAYER_MEDIA, KC_DEL), LT(LAYER_SYMBOL, KC_BSPC), RSFT_T(KC_ENT),
            KC_DOWN, KC_UP
    ),

    [LAYER_SYMBOL] = LAYOUT(
        // Left
        KC_ESC,      KC_F1,    KC_F2,    KC_F3,      KC_F4,     KC_F5,
        S(KC_GRAVE), S(KC_1),  S(KC_2),  S(KC_3),    S(KC_4),   S(KC_5),
        KC_GRAVE,    KC_1,     KC_2,     KC_3,       KC_4,      KC_5,
        _______,     MCR_PRNS, MCR_BRCS, MCR_BRCKTS, MCR_ANGLS, _______,
        _______,     _______,  _______,  _______,
                                         _______, _______, _______,
                                             KC_HOME, KC_END,

        // Right
        KC_F6,     KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,
        S(KC_6),   S(KC_7), S(KC_8), S(KC_9), S(KC_0), S(KC_MINUS),S(KC_EQUAL),
        KC_6,      KC_7,    KC_8,    KC_9,    KC_0,   KC_MINUS, KC_EQUAL,
        MCR_ASSGN, MCR_NE,  MCR_LE,  MCR_GE,  _______, KC_PGUP,
                            _______, _______, KC_HOME, KC_PGDN, KC_END,
        _______, _______, _______,
            KC_PGDN, KC_PGUP
    ),

    [LAYER_MEDIA] = LAYOUT(
        // Left
        _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______,
                                    _______, _______, _______,
                                        _______, _______,

        // Right
        _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, MS_BTN3, MS_UP,
                          MS_BTN1, MS_BTN2, MS_LEFT, MS_DOWN, MS_RGHT,
        _______, _______, _______,
            MS_WHLD, MS_WHLU
    ),
};
// clang-format on

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case MCR_PRNS:
            if (record->event.pressed) {
                SEND_STRING("()");
                tap_code(KC_LEFT);
            }
            break;
        case MCR_BRCS:
            if (record->event.pressed) {
                SEND_STRING("{}");
                tap_code(KC_LEFT);
            }
            break;
        case MCR_BRCKTS:
            if (record->event.pressed) {
                SEND_STRING("[]");
                tap_code(KC_LEFT);
            }
            break;
        case MCR_ANGLS:
            if (record->event.pressed) {
                SEND_STRING("<>");
                tap_code(KC_LEFT);
            }
            break;
        case MCR_ASSGN:
            if (record->event.pressed) {
                SEND_STRING(":=");
            }
            break;
        case MCR_NE:
            if (record->event.pressed) {
                SEND_STRING("!=");
            }
            return true;
        case MCR_LE:
            if (record->event.pressed) {
                SEND_STRING("<=");
            }
            break;
        case MCR_GE:
            if (record->event.pressed) {
                SEND_STRING(">=");
            }
            break;
    }
    return true;
}
