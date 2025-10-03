// Copyright 2023 QMK
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

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
    [0] = LAYOUT(
        // Left
        KC_GRAVE, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,
        KC_TAB,   KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,
        KC_CAPS,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,
        KC_LSFT,  KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,
        KC_LCTL,  KC_LGUI, KC_LALT, KC_ESC,
                                        KC_SPC, KC_BSPC, KC_DEL,
                                            KC_HOME, KC_END,

        // Right
        KC_6,    KC_7,    KC_8,     KC_9,    KC_0,         KC_MINUS, KC_EQUAL,
        KC_Y,    KC_U,    KC_I,     KC_O,    KC_P,         KC_LBRC,  KC_RBRC,
        KC_H,    KC_J,    KC_K,     KC_L,    KC_SEMICOLON, KC_QUOTE, KC_BSLS,
        KC_N,    KC_M,    KC_COMMA, KC_DOT,  KC_SLASH,     KC_UP,
                          KC_HOME,  KC_END,  KC_LEFT,      KC_DOWN,  KC_RIGHT,
        KC_SPC, KC_ESC, KC_ENT,
            KC_PGUP, KC_PGDN
    )
};
