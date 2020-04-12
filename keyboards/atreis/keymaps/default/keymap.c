/* Copyright 2018 dek <dek@yolops.net>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#include "atreis.h"
#include "eeconfig.h"

#define _QWERTY 0
#define _FN 1

enum custom_keycodes {
  QWERTY = SAFE_RANGE,
  FN
};

#define KC_ KC_TRNS
#define _______ KC_TRNS

#define KC_FN FN
#define KC_RST RESET
#define KC_BL_S BL_STEP
#define KC_BL_T BL_TOGG
#define KC_R_TG RGB_TOG
#define KC_R_MO RGB_MOD
#define KC_R_HI RGB_HUI
#define KC_R_HD RGB_HUD
#define KC_R_SI RGB_SAI
#define KC_R_SD RGB_SAD
#define KC_R_VI RGB_VAI
#define KC_R_VD RGB_VAD

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
[_QWERTY] = LAYOUT(
    /* LH R1 */
    KC_EQL, KC_1, KC_2, KC_3, KC_4, KC_5,
    /* RH R1 */
    KC_6, KC_7, KC_8, KC_9, KC_0, KC_MINUS,
    /* LH R2 */
    KC_TAB, KC_Q, KC_W, KC_E, KC_R, KC_T,
    /* RH R2 */
    KC_Y, KC_U, KC_I, KC_O, KC_P, KC_BSLASH,
    /* LH R3 (Home) */
    KC_LCTRL, LT(2,KC_A), LGUI_T(KC_S), LALT_T(KC_D), LCTL_T(KC_F), LSFT_T(KC_G),
    /* RH R3 (Home) */
    RSFT_T(KC_H), RCTL_T(KC_J), RALT_T(KC_K), RGUI_T(KC_L), LT(1,KC_SCLN), KC_QUOTE,
    /* LH R4 */
    KC_LSFT, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_TAB,
    /* KC R4 */
    KC_BSPC, KC_N, KC_M, KC_COMMA, KC_DOT, KC_SLASH, KC_RSFT,
  //`----+----+----+--+-+----+----+----/    \----+----+----+----+----+----+----'
                   FN,KC_LSFT,KC_ENT,         KC_SPC,KC_RSFT,KC_ESC
  //                  `----+----+----'        `----+----+----'
  ),
  [_FN] = LAYOUT_kc(
  //,----+----+----+----+----+----.              ,----+----+----+----+----+----.
     F12 , F1 , F2 , F3 , F4 , F5 ,                F6 , F7 , F8 , F9 ,F10 ,EQL ,
  //|----+----+----+----+----+----|              |----+----+----+----+----+----|
     RST ,    ,    ,    ,    ,LBRC,               RBRC,END ,HOME,LBRC,RBRC,DEL ,
  //|----+----+----+----+----+----|              |----+----+----+----+----+----|
     R_TG,R_MO,R_HI,R_SI,R_VI,    ,               LEFT,DOWN, UP ,RGHT,    ,    ,
  //|----+----+----+----+----+----+----.    ,----|----+----+----+----+----+----|
     BL_T,BL_S,R_HD,R_SD,R_VD,LCBR,    ,         ,RCBR,PGDN,PGUP,LCBR,RCBR,PIPE,
  //`----+----+----+--+-+----+----+----/    \----+----+----+----+----+----+----'
                           ,    ,    ,             ,    ,    
  //                  `----+----+----'        `----+----+----'
  )

};

const uint16_t PROGMEM fn_actions[] = {

};

const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt)
{
  // MACRODOWN only works in this function
      switch(id) {
        case 0:
          if (record->event.pressed) {
            register_code(KC_RSFT);
          } else {
            unregister_code(KC_RSFT);
          }
        break;
      }
    return MACRO_NONE;
};


void matrix_init_user(void) {

}

void matrix_scan_user(void) {

}

void persistent_default_layer_set(uint16_t default_layer) {
  eeconfig_update_default_layer(default_layer);
  default_layer_set(default_layer);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case QWERTY:
      if (record->event.pressed) {
        #ifdef AUDIO_ENABLE
          PLAY_SONG(tone_qwerty);
        #endif
        persistent_default_layer_set(1UL<<_QWERTY);
      }
      return false;
      break;
    case FN:
      if (record->event.pressed) {
        layer_on(_FN);
      } else {
        layer_off(_FN);
      }
      return false;
      break;
  }
  // If console is enabled, it will print the matrix position and status of each key pressed
#ifdef CONSOLE_ENABLE
  uprintf("KL: kc: %u, col: %u, row: %u, pressed: %u\n", keycode, record->event.key.col, record->event.key.row, record->event.pressed);
#endif

  return true;
}

void led_set_user(uint8_t usb_led) {

}
