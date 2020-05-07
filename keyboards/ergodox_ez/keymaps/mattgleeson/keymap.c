#include QMK_KEYBOARD_H
#include "version.h"
#include "keymap_german.h"
#include "keymap_nordic.h"
#include "keymap_french.h"
#include "keymap_spanish.h"
#include "keymap_hungarian.h"
#include "keymap_swedish.h"
#include "keymap_br_abnt2.h"
#include "keymap_canadian_multilingual.h"
#include "keymap_german_ch.h"
#include "keymap_jp.h"
#include "keymap_bepo.h"

#define KC_MAC_UNDO LGUI(KC_Z)
#define KC_MAC_CUT LGUI(KC_X)
#define KC_MAC_COPY LGUI(KC_C)
#define KC_MAC_PASTE LGUI(KC_V)
#define KC_PC_UNDO LCTL(KC_Z)
#define KC_PC_CUT LCTL(KC_X)
#define KC_PC_COPY LCTL(KC_C)
#define KC_PC_PASTE LCTL(KC_V)
#define ES_LESS_MAC KC_GRAVE
#define ES_GRTR_MAC LSFT(KC_GRAVE)
#define ES_BSLS_MAC ALGR(KC_6)
#define NO_PIPE_ALT KC_GRAVE
#define NO_BSLS_ALT KC_EQUAL

enum custom_keycodes {
  RGB_SLD = SAFE_RANGE,
};

#define LAYOUT_ergodox_pretty_wrapper(...)       LAYOUT_ergodox_pretty(__VA_ARGS__)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [0] = LAYOUT_ergodox_pretty_wrapper(
    MG_LH_R1, KC_ESCAPE,
    KC_ENT, MG_RH_R1,
    MG_LH_R2, KC_HOME,
    KC_PGUP, MG_RH_R2,
    MG_HOME_L,
    MG_HOME_R,
    MG_LH_R4, KC_END,
    KC_PGDOWN, MG_RH_R4,
    /* LH R5 */
    LT(1,KC_GRAVE), KC_QUOTE, KC_LALT, KC_LEFT, KC_LSFT,
    /* RH R5 */
    KC_RSFT, KC_DOWN, KC_LBRACKET, KC_RBRACKET, RESET,
    /* thumb LH top */
    KC_AUDIO_VOL_DOWN, KC_AUDIO_VOL_UP,
    /* thumb RH top */
    KC_MEDIA_PLAY_PAUSE, KC_MEDIA_NEXT_TRACK,
    /* thumb LH mid */
    _______,
    /* thumb RH mid */
    KC_GPM_LIKE_SONG,
    /* thumb LH bottom */
    KC_TAB, KC_ENTER, KC_MAC_SHOW_WINS,
    /* thumb RH bottom */
    KC_ENTER, KC_BSPACE, KC_SPACE
  ),
  [1] = LAYOUT_ergodox_pretty_wrapper(
    MG_1_LH_R1, _______,
    _______, MG_1_RH_R1,
    MG_1_LH_R2, _______,
    _______, MG_1_RH_R2,
    MG_1_LH_R3,
    MG_1_RH_R3,
    MG_1_LH_R4, _______,
    _______, MG_1_RH_R4,
    /* LH R5 */
    _______, _______, _______, _______, _______,
    /* RH R5 */
    _______, KC_DOT, KC_0, KC_EQUAL, _______,
    /* thumbs */
    _______, _______, _______, _______,
    _______, _______,
    _______, _______, _______, _______, _______, _______
  ),
  [2] = LAYOUT_ergodox_pretty_wrapper(
    MG_2_LH_R1, _______,
    _______, MG_2_RH_R1,
    MG_2_LH_R2, _______,
    _______, MG_2_RH_R2,
    MG_2_LH_R3,
    MG_2_RH_R3,
    MG_2_LH_R4, _______,
    _______, MG_2_RH_R4,
    /* R5 */
    _______, _______, _______, KC_MS_BTN1, KC_MS_BTN2,
    KC_AUDIO_VOL_UP, KC_AUDIO_VOL_DOWN, KC_AUDIO_MUTE, _______, _______,
    /* thumbs */
    _______, _______, _______, _______,
    _______, _______,
    _______, _______, _______, _______, _______, KC_WWW_BACK
  ),
};


bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
  }
  return true;
}

uint32_t layer_state_set_user(uint32_t state) {
  uint8_t layer = biton32(state);
  ergodox_board_led_off();
  ergodox_right_led_1_off();
  ergodox_right_led_2_off();
  ergodox_right_led_3_off();
  switch (layer) {
    case 1:
      ergodox_right_led_1_on();
      break;
    case 2:
      ergodox_right_led_2_on();
      break;
    case 3:
      ergodox_right_led_3_on();
      break;
    case 4:
      ergodox_right_led_1_on();
      ergodox_right_led_2_on();
      break;
    case 5:
      ergodox_right_led_1_on();
      ergodox_right_led_3_on();
      break;
    case 6:
      ergodox_right_led_2_on();
      ergodox_right_led_3_on();
      break;
    case 7:
      ergodox_right_led_1_on();
      ergodox_right_led_2_on();
      ergodox_right_led_3_on();
      break;
    default:
      break;
  }
  return state;
};
