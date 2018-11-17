#include QMK_KEYBOARD_H
#include "eeconfig.h"

extern keymap_config_t keymap_config;

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
#define _QWERTY 0
#define _COLEMAK 1
#define _DVORAK 2
#define _LOWER 3
#define _RAISE 4
#define _ADJUST 16

enum custom_keycodes {
  QWERTY = SAFE_RANGE,
  COLEMAK,
  DVORAK,
  LOWER,
  RAISE,
  ADJUST,
  MIN_ARW,
  EQ_ARW,
};

// Fillers to make layering more clear
#define _______ KC_TRNS
#define XXXXXXX KC_NO
#define LOWER MO(_LOWER)
#define RAISE MO(_RAISE)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Qwerty
 * ,-----------------------------------------.             ,-----------------------------------------.
 * |   `  |   1  |   2  |   3  |   4  |   5  |             |   6  |   7  |   8  |   9  |   0  | Bksp |
 * |------+------+------+------+------+------|             |------+------+------+------+------+------|
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |             |   Y  |   U  |   I  |   O  |   P  |  -   |
 * |------+------+------+------+------+------|             |------+------+------+------+------+------|
 * | Shift|   A  |   S  |   D  |   F  |   G  |             |   H  |   J  |   K  |   L  |   ;  |  =   |
 * |------+------+------+------+------+------+-------------+------+------+------+------+------+------|
 * | Ctrl |   Z  |   X  |   C  |   V  |   B  |   \  |   '  |   N  |   M  |   ,  |   .  |   /  |  Del |
 * `-------------+------+------+------+------+------+------+------+------+------+------+-------------'
 *               |  GUI |  Alt |Lower |Space |  Esc |Enter | Shift|Raise |   [  |   ]  |
 *               `---------------------------------------------------------------------'
 */
[_QWERTY] = LAYOUT( \
  KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC, \
  KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_MINS, \
  KC_LSFT, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_EQL,  \
  KC_LCTL, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B, KC_BSLS,  KC_QUOT, KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_DEL , \
                 KC_LGUI, KC_LALT,   LOWER,  KC_SPC,  KC_ESC,  KC_ENT,  KC_LSFT, RAISE,   KC_LBRC, KC_RBRC\
),

/* Colemak
 * ,-----------------------------------------.             ,-----------------------------------------.
 * |   `  |   1  |   2  |   3  |   4  |   5  |             |   6  |   7  |   8  |   9  |   0  | Bksp |
 * |------+------+------+------+------+------|             |------+------+------+------+------+------|
 * | Tab  |   Q  |   W  |   F  |   P  |   G  |             |   J  |   L  |   U  |   Y  |   ;  |   \  |
 * |------+------+------+------+------+------|             |------+------+------+------+------+------|
 * | Shift|   A  |   R  |   S  |   T  |   D  |             |   H  |   N  |   E  |   I  |   O  |  '   |
 * |------+------+------+------+------+------+-------------+------+------+------+------+------+------|
 * | Ctrl |   Z  |   X  |   C  |   V  |   B  |   \  |   '  |   K  |   M  |   ,  |   .  |   /  |  Del |
 * `-------------+------+------+------+------+------+------+------+------+------+------+-------------'
 *               |  GUI |  Alt |Lower |Space |  Esc |Enter | Shift|Raise |   [  |   ]  |
 *               `---------------------------------------------------------------------'
 */
[_COLEMAK] = LAYOUT( \
  KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                   KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC, \
  KC_TAB,  KC_Q,    KC_W,    KC_F,    KC_P,    KC_G,                   KC_J,    KC_L,    KC_U,    KC_Y,    KC_SCLN, KC_MINS, \
  KC_LSFT, KC_A,    KC_R,    KC_S,    KC_T,    KC_D,                   KC_H,    KC_N,    KC_E,    KC_I,    KC_O,    KC_EQL,  \
  KC_LCTL, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B, KC_BSLS, KC_QUOT, KC_K,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_DEL , \
                 KC_LGUI, KC_LALT,   LOWER,  KC_SPC,  KC_ESC, KC_ENT,  KC_LSFT, RAISE,   KC_LBRC, KC_RBRC\
),

/* Dvorak
 * ,-----------------------------------------.             ,-----------------------------------------.
 * |   `  |   1  |   2  |   3  |   4  |   5  |             |   6  |   7  |   8  |   9  |   0  | Bksp |
 * |------+------+------+------+------+------|             |------+------+------+------+------+------|
 * | Tab  |   "  |   ,  |   .  |   P  |   Y  |             |   F  |   G  |   C  |   R  |   L  |   \  |
 * |------+------+------+------+------+------|             |------+------+------+------+------+------|
 * | Shift|   A  |   O  |   E  |   U  |   I  |             |   D  |   H  |   T  |   N  |   S  |  '   |
 * |------+------+------+------+------+------+-------------+------+------+------+------+------+------|
 * | Ctrl |   ;  |   Q  |   J  |   K  |   X  |   \  |   '  |   B  |   M  |   W  |   V  |   Z  |  Del |
 * `-------------+------+------+------+------+------+------+------+------+------+------+-------------'
 *               |  GUI |  Alt |Lower |Space |  Esc |Enter | Shift|Raise |   [  |   ]  |
 *               `---------------------------------------------------------------------'
 */
[_DVORAK] = LAYOUT( \
  KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                   KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC, \
  KC_TAB,  KC_QUOT, KC_COMM, KC_DOT,  KC_P,    KC_Y,                   KC_F,    KC_G,    KC_C,    KC_R,    KC_L,    KC_MINS, \
  KC_LSFT, KC_A,    KC_O,    KC_E,    KC_U,    KC_I,                   KC_D,    KC_H,    KC_T,    KC_N,    KC_S,    KC_EQL,  \
  KC_LCTL, KC_SCLN, KC_Q,    KC_J,    KC_K,    KC_X, KC_BSLS, KC_QUOT, KC_B,    KC_M,    KC_W,    KC_V,    KC_Z,    KC_DEL , \
                 KC_LGUI, KC_LALT,   LOWER,  KC_SPC, KC_ESC,  KC_ENT,  KC_LSFT, RAISE,   KC_LBRC, KC_RBRC\
),

/* Lower
 * ,-----------------------------------------.             ,-----------------------------------------.
 * |   ~  |   !  |   @  |   #  |   $  |   %  |             |   ^  |   &  |   *  |   (  |   )  | Bksp |
 * |------+------+------+------+------+------|             |------+------+------+------+------+------|
 * |      | Home |  UP  |  End | PgUp |      |             | PgUp | Home |  UP  |  End |      |  _   |
 * |------+------+------+------+------+------.             ,------+------+------+------+------+------|
 * |      | LEFT | DOWN | RIGHT| PgDn |      |             | PgDn | LEFT | DOWN | RIGHT|   :  |  +   |
 * |------+------+------+------+------+------+-------------+------+------+------+------+------+------|
 * |      | _    |  ->  |  =>  |      |      |   |  |   "  |      |      |   <  |   >  |   ?  | Del  |
 * `-------------+------+------+------+------+------+------+------+------+------+------+-------------'
 *               |      |      |      |      |      |      |      |      |   {  |   }  |
 *               `---------------------------------------------------------------------'
 */
[_LOWER] = LAYOUT( \
  KC_TILD, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC,                   KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_BSPC, \
  _______, KC_HOME,   KC_UP,  KC_END, KC_PGUP, _______,                   KC_PGUP, KC_HOME,   KC_UP,  KC_END, _______, KC_UNDS, \
  _______, KC_LEFT, KC_DOWN, KC_RGHT, KC_PGDN, _______,                   KC_PGDN, KC_LEFT, KC_DOWN, KC_RGHT, KC_COLN, KC_PLUS, \
  _______, KC_UNDS, MIN_ARW,  EQ_ARW, _______, _______, KC_PIPE, KC_DQUO, _______, _______, KC_LABK, KC_RABK, KC_QUES, KC_DEL, \
                    _______, _______, _______, _______, _______, _______, _______, _______, KC_LCBR, KC_RCBR\
),

/* Raise
 * ,-----------------------------------------.             ,-----------------------------------------.
 * |  Esc |  F1  |  F2  |  F3  |  F4  |  F5  |             |  F6  |  F7  |  F8  |  F9  |  F10 | Bksp |
 * |------+------+------+------+------+------.             ,------+------+------+------+------+------|
 * |      | Home |  UP  |  End | PgUp |      |             | PgUp | Home |  UP  |  End |      | F11  |
 * |------+------+------+------+------+------.             ,------+------+------+------+------+------|
 * |      | LEFT | DOWN | RIGHT| PgDn |      |             | PgDn | LEFT | DOWN | RIGHT|      | F12  |
 * |------+------+------+------+------+------+-------------+------+------+------+------+------+------|
 * |      | _    |  ->  |  =>  |      |      |      |      |      |      |      |      |      | Del  |
 * `-------------+------+------+------+------+------+------+------+------+------+------+-------------'
 *               |      |      |      |      |      |      |      |      |      |      |
 *               `---------------------------------------------------------------------'
 */
[_RAISE] = LAYOUT( \
  KC_ESC,    KC_F1,  KC_F2,    KC_F3,   KC_F4,   KC_F5,                     KC_F6,   KC_F7,   KC_F8,   KC_F9,  KC_F10, KC_BSPC, \
  _______, KC_HOME,   KC_UP,  KC_END, KC_PGUP, _______,                   KC_PGUP, KC_HOME,   KC_UP,  KC_END, _______,  KC_F11, \
  _______, KC_LEFT, KC_DOWN, KC_RGHT, KC_PGDN, _______,                   KC_PGDN, KC_LEFT, KC_DOWN, KC_RGHT, _______,  KC_F12, \
  _______, KC_UNDS, MIN_ARW,  EQ_ARW, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_DEL,  \
                    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______\
),

/* Adjust (Lower + Raise)
 * ,-----------------------------------------.             ,-----------------------------------------.
 * |      |      |      |      |      |      |             |      |      |      |      |      |      |
 * |------+------+------+------+------+------.             ,------+------+------+------+------+------|
 * |      | Reset|RGB Tg|RGB Md|Hue Up|Hue Dn|             |Sat Up|Sat Dn|Val Up|Val Dn|      |      |
 * |------+------+------+------+------+------.             ,------+------+------+------+------+------|
 * |      |      |      |Aud on|Audoff|AGnorm|             |AGswap|      |BL TOG|BL STP|      |      |
 * |------+------+------+------+------+------+-------------+------+------+------+------+------+------|
 * |Qwerty|Colemk|Dvorak|      |      |      |      |      |      |      |      |      |      |      |
 * `-------------+------+------+------+------+------+------+------+------+------+------+-------------'
 *               |      |      |      |      |      |      |      |      |      |      |
 *               `---------------------------------------------------------------------'
 */
[_ADJUST] =  LAYOUT( \
  _______, _______, _______, _______, _______, _______,                   _______, _______, _______, _______, _______, _______, \
  _______, RESET  , RGB_TOG, RGB_MOD, RGB_HUD, RGB_HUI,                   RGB_SAD, RGB_SAI, RGB_VAD, RGB_VAI, _______, _______, \
  _______, _______, _______, AU_ON,   AU_OFF,  AG_NORM,                   AG_SWAP, _______, BL_TOGG, BL_STEP, _______, _______, \
  QWERTY,  COLEMAK, DVORAK,  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
                    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______\
)


};

uint32_t layer_state_set_user(uint32_t state) {
  return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case QWERTY:
      if (record->event.pressed) {
        set_single_persistent_default_layer(_QWERTY);
      }
      return false;
      break;
    case COLEMAK:
      if (record->event.pressed) {
        set_single_persistent_default_layer(_COLEMAK);
      }
      return false;
      break;
    case DVORAK:
      if (record->event.pressed) {
        set_single_persistent_default_layer(_DVORAK);
      }
      return false;
      break;
    case MIN_ARW:
      if (record->event.pressed) {
        SEND_STRING("->");
      }
      return false;
      break;
    case EQ_ARW:
      if (record->event.pressed) {
        SEND_STRING("=>");
      }
      return false;
      break;
  }
  return true;
}
