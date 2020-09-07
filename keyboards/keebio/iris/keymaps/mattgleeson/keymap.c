#include QMK_KEYBOARD_H


#define _QWERTY 0
#define _LOWER 1
#define _RAISE 2
#define _ADJUST 3

enum custom_keycodes {
  QWERTY = SAFE_RANGE,
  LOWER,
  RAISE,
  ADJUST,
};
#include "mg_keys.h"

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [0] = LAYOUT_wrapper(
    MG_LH_R1, MG_RH_R1, MG_LH_R2, MG_RH_R2, MG_LH_R3, MG_RH_R3,
    MG_LH_R4, KC_ESC,
    KC_MEDIA_PLAY_PAUSE, MG_RH_R4,
    /* thumbs */
    MG_LTHUMB_IN, MG_LTHUMB_NEAR, MG_LTHUMB_FAR,
    MG_RTHUMB_FAR, MG_RTHUMB_NEAR, MG_RTHUMB_IN
  ),
  [1] = LAYOUT_wrapper(
    MG_1_LH_R1, MG_1_RH_R1, MG_1_LH_R2, MG_1_RH_R2, MG_1_LH_R3, MG_1_RH_R3,
    MG_1_LH_R4, KC_,
    KC_, MG_1_RH_R4,
    /* thumbs */
    KC_, KC_, KC_,    KC_, KC_, KC_
  ),
  [2] = LAYOUT_wrapper(
    MG_2_LH_R1, MG_2_RH_R1, MG_2_LH_R2, MG_2_RH_R2, MG_2_LH_R3, MG_2_RH_R3,
    MG_2_LH_R4, KC_,
    KC_, MG_2_RH_R4,
    /* thumbs */
    KC_, KC_, KC_,    KC_, KC_, KC_
  ),

};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case QWERTY:
      if (record->event.pressed) {
        set_single_persistent_default_layer(_QWERTY);
      }
      return false;
      break;
    case LOWER:
      if (record->event.pressed) {
        layer_on(_LOWER);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      } else {
        layer_off(_LOWER);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      }
      return false;
      break;
    case RAISE:
      if (record->event.pressed) {
        layer_on(_RAISE);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      } else {
        layer_off(_RAISE);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      }
      return false;
      break;
    case ADJUST:
      if (record->event.pressed) {
        layer_on(_ADJUST);
      } else {
        layer_off(_ADJUST);
      }
      return false;
      break;
  }
  return true;
}

void encoder_update_user(uint8_t index, bool clockwise) {
    if (index == 1) {
        if (clockwise) {
            tap_code(KC_VOLU);
        } else {
            tap_code(KC_VOLD);
        }
    }
    else if (index == 0) {
        if (clockwise) {
            tap_code(KC_PGDN);
        } else {
            tap_code(KC_PGUP);
        }
    }
}