#include "satan.h"

// Used for SHIFT_ESC
#define MODS_CTRL_MASK  (MOD_BIT(KC_LSHIFT)|MOD_BIT(KC_RSHIFT))

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
#define _BL 0
#define _FL 1
#define _RL 2

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  /* Keymap _BL: (Base Layer) Default Layer
   * ,-----------------------------------------------------------.
   * |Esc~| 1|  2|  3|  4|  5|  6|  7|  8|  9|  0|  -|  =|Backsp |
   * |-----------------------------------------------------------|
   * |Tab  |  Q|  W|  E|  R|  T|  Y|  U|  I|  O|  P|  [|  ]|  \  |
   * |-----------------------------------------------------------|
   * |Fn     |  A|  S|  D|  F|  G|  H|  J|  K|  L|  ;|  '|Return |
   * |-----------------------------------------------------------|
   * |Shift   |  Z|  X|  C|  V|  B|  N|  M|  ,|  .|  /|Shift     |
   * |-----------------------------------------------------------|
   * |Ctrl|Gui |Alt |      Space            |Alt |Fn  |Gui |Ctrl |
   * `-----------------------------------------------------------'
   */
[_BL] = KEYMAP_HHKB(
  KC_ESC,    KC_1,    KC_2,    KC_3,   KC_4,    KC_5,    KC_6,    KC_7,     KC_8,    KC_9,   KC_0,    KC_MINS, KC_EQL,  KC_BSLS, KC_GRV,\
  KC_TAB,  KC_Q,    KC_W,    KC_E,   KC_R,    KC_T,    KC_Y,    KC_U,     KC_I,    KC_O,   KC_P,    KC_LBRC, KC_RBRC, KC_BSPC, \
  MO(_FL), KC_A,    KC_S,    KC_D,   KC_F,    KC_G,    KC_H,    KC_J,     KC_K,    KC_L,   KC_SCLN, KC_QUOT,           KC_ENT,  \
  OSM(MOD_LSFT), KC_Z,    KC_X,    KC_C,   KC_V,    KC_B,    KC_N,    KC_M,     KC_COMM, KC_DOT, KC_SLSH,       OSM(MOD_RSFT), MO(_RL),\
  KC_LCTL, KC_LGUI, KC_LALT,                           KC_SPC,                            KC_RALT, MO(_FL), KC_RGUI, KC_RCTL),

/* Keymap _FL: Function Layer
   * ,-----------------------------------------------------------.
   * | ~ | F1|F2 |F3 |F4 |F5 |F6 |F7 |F8 |F9 |F10|F11|F12|  DEL  |
   * |-----------------------------------------------------------|
   * |     |  |  | è |  |  |Cal|Home|Ins|End |PrSc|Sclk|Paus|    |
   * |-----------------------------------------------------------|
   * |      | à  |    |   |  |  |Left|Dwn|Up|Rig|PgUp| `  |      |
   * |-----------------------------------------------------------|
   * |        |   |   | ç|  |   |Vdn|Vup|Mute|PgDn|   |          |
   * |-----------------------------------------------------------|
   * |    |    |    |                        |    |Fn  |    |_RL |
   * `-----------------------------------------------------------'
   */
[_FL] = KEYMAP_HHKB(
  KC_TRNS,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,    KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_TRNS, KC_TRNS, \
  KC_TRNS,KC_TRNS, KC_TRNS, M(0),  KC_TRNS, KC_TRNS, KC_CALC, KC_HOME,  KC_INS,  KC_END,  KC_PSCR, KC_SLCK, KC_PAUS, KC_DEL, \
  KC_TRNS, M(1), BL_DEC, BL_INC, BL_TOGG, KC_TRNS, KC_LEFT, KC_DOWN,  KC_UP,   KC_RGHT, KC_PGUP, KC_GRV,           KC_TRNS, \
  KC_TRNS, KC_TRNS, KC_TRNS, RALT(KC_COMM), KC_TRNS, KC_TRNS, KC_VOLD, KC_VOLU,  KC_MUTE, KC_PGDN, KC_TRNS,         KC_TRNS, KC_TRNS, \
  KC_TRNS, KC_TRNS, KC_TRNS,                            KC_BTN3,                             KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS),
  
  /* Keymap _RL: Function Layer
   * ,-----------------------------------------------------------.
   * |   |   |   |   |   |   |   |   |   |   |   |   |   |  RESET|
   * |-----------------------------------------------------------|
   * |     |   |   |   |   |   |   |   |   |   |   |BL-|BL+|BL   |
   * |-----------------------------------------------------------|
   * |      |   |   |   |   |   |   |       |   |   |   |        |
   * |-----------------------------------------------------------|
   * |        | F1|F2 | F3|F4 | F5| F6| F7| F8|   |   |          |
   * |-----------------------------------------------------------|
   * |    |    |    |                        |    |    |    |    |
   * `-----------------------------------------------------------'   
   */
[_RL] = KEYMAP_HHKB(
  KC_GRV,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, RESET, KC_TRNS,  \
  KC_TRNS, M(11), M(12), M(13), M(14), M(15), M(16), M(17), M(18), M(19), M(20),  BL_DEC,  BL_INC,  BL_TOGG, \
  KC_TRNS, M(21), M(22), M(23), M(24), M(25), M(26), M(27), M(28), M(29), KC_TRNS, KC_TRNS,          KC_TRNS, \
  KC_TRNS, M(30), M(31), M(32), M(33), M(34), M(35), KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                   KC_TRNS, KC_TRNS, \
  KC_TRNS, KC_TRNS, KC_TRNS,                            KC_TRNS,                            KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS),
};

enum function_id {
    SHIFT_ESC,
};

/*
 * Macro definition
 */
const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt) {
    if (record->event.pressed){
        switch (id) {
            /* è */
            case 0:
                return MACRO( T(GRV), T(E), END );
                /* à */
            case 1:
                return MACRO( T(GRV), T(A), END );
            case 11:                                                               
                SEND_STRING(":pallascat1: ");
                return false;
            case 12:                                                               
                SEND_STRING(":pallascat2: ");
                return false;
            case 13:                                                               
                SEND_STRING(":pallascat3: ");
                return false;
            case 14:                                                               
                SEND_STRING(":pallascat4: ");
                return false;
            case 15:                                                               
                SEND_STRING(":pallascat5: ");
                return false;
            case 16:                                                               
                SEND_STRING(":pallascat6: ");
                return false;
            case 17:                                                               
                SEND_STRING(":pallascat7: ");
                return false;
            case 18:                                                               
                SEND_STRING(":pallascat8: ");
                return false;
            case 19:                                                               
                SEND_STRING(":pallascat9: ");
                return false;
            case 20:                                                               
                SEND_STRING(":pallascat10: ");
                return false;
            case 21:                                                               
                SEND_STRING(":pallascat11: ");
                return false;
            case 22:                                                               
                SEND_STRING(":pallascat12: ");
                return false;
            case 23:                                                               
                SEND_STRING(":pallascat13: ");
                return false;
            case 24:                                                               
                SEND_STRING(":pallascat14: ");
                return false;
            case 25:                                                               
                SEND_STRING(":pallascat15: ");
                return false;
            case 26:                                                               
                SEND_STRING(":pallascat16: ");
                return false;
            case 27:                                                               
                SEND_STRING(":pallascat17: ");
                return false;
            case 28:                                                               
                SEND_STRING(":pallascat18: ");
                return false;
            case 29:                                                               
                SEND_STRING(":pallascat19: ");
                return false;
            case 30:                                                               
                SEND_STRING(":pallascat20: ");
                return false;
            case 31:                                                               
                SEND_STRING(":pallascat21: ");
                return false;
            case 32:                                                               
                SEND_STRING(":pallascat22: ");
                return false;
            case 33:                                                               
                SEND_STRING(":pallascat23: ");
                return false;
            case 34:                                                               
                SEND_STRING(":pallascat24: ");
                return false;
            case 35:                                                               
                SEND_STRING(":pallascat25: ");
                return false;
        }
    }
    return MACRO_NONE;
};

const uint16_t PROGMEM fn_actions[] = {
  [0]  = ACTION_FUNCTION(SHIFT_ESC),
};

void action_function(keyrecord_t *record, uint8_t id, uint8_t opt) {
  static uint8_t shift_esc_shift_mask;
  switch (id) {
    case SHIFT_ESC:
      shift_esc_shift_mask = get_mods()&MODS_CTRL_MASK;
      if (record->event.pressed) {
        if (shift_esc_shift_mask) {
          add_key(KC_GRV);
          send_keyboard_report();
        } else {
          add_key(KC_ESC);
          send_keyboard_report();
        }
      } else {
        if (shift_esc_shift_mask) {
          del_key(KC_GRV);
          send_keyboard_report();
        } else {
          del_key(KC_ESC);
          send_keyboard_report();
        }
      }
      break;
  }
}

