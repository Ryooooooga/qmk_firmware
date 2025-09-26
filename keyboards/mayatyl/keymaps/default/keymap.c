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
        KC_GRAVE,KC_1,    KC_2,    KC_3,    KC_4,    KC_5,
        KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,
        KC_CAPS, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,
        KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,
        KC_LCTL, KC_LGUI, KC_LALT, KC_ESC,
                                        KC_SPC, KC_BSPC, KC_DEL,
                                            KC_HOME, KC_END
    )
};
