// Copyright (C) 2019, 2020  Keyboard.io, Inc
//
// this is the style you want to emulate.
// This is the canonical layout file for the Quantum project. If you want to add another keyboard,

#include QMK_KEYBOARD_H
#include "mg_keys.h"

enum layer_names {
    _QW,
    _RS,
    _LW,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_QW] = LAYOUT_wrapper( /* Qwerty */
    MG_ALH_R2,                      MG_ARH_R2,
    MG_ALH_R3,                      MG_ARH_R3,
    MG_ALH_R4, KC_GRAVE, KC_BSLASH, MG_ARH_R4,
    KC_ESC, KC_DEL, MG_LTHUMB_IN, MG_LTHUMB_NEAR, MG_LTHUMB_FAR, KC_MINS,
    /* */                     KC_QUOT, MG_RTHUMB_FAR, MG_RTHUMB_NEAR, MG_RTHUMB_IN, KC_RGUI, KC_EQL
  ),
  [_RS] = LAYOUT_wrapper(
    MG_1_ALH_R2,                   MG_1_ARH_R2,
    MG_1_ALH_R3,                   MG_1_ARH_R3,
    MG_1_ALH_R4, _______, _______, MG_1_ARH_R4,
    TG(_LW), KC_INS,  KC_LGUI, KC_LSFT, KC_BSPC, KC_LCTL, KC_LALT, KC_SPC,  KC_TRNS, KC_DOT, KC_0, KC_EQL
  ),
  [_LW] = LAYOUT_wrapper(
    MG_2_ALH_R2,                   MG_2_ARH_R2,
    MG_2_ALH_R3,                   MG_2_ARH_R3,
    MG_2_ALH_R4, _______, _______, MG_2_ARH_R4,
    KC_NO,   KC_VOLD, KC_LGUI, KC_LSFT, KC_BSPC, KC_LCTL, KC_LALT, KC_SPC,  TO(_QW), KC_PSCR, KC_SLCK, KC_PAUS
  )
};
