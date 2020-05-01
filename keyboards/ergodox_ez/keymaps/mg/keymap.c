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

#define KC_GPM_LIKE_SONG C(S(KC_UP))
#define KC_MAC_SHOW_WINS LCTL(KC_UP)

enum custom_keycodes {
  RGB_SLD = SAFE_RANGE,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [0] = LAYOUT_ergodox_pretty(
    /* LH R1 */
    KC_EQL, KC_1, KC_2, KC_3, KC_4, KC_5, KC_ESCAPE,
    /* RH R1 */
    KC_ENT, KC_6, KC_7, KC_8, KC_9, KC_0, KC_MINUS,
    /* LH R2 */
    KC_TAB, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_HOME,
    /* RH R2 */
    KC_PGUP, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_BSLASH,
    /* LH R3 (Home) */
    KC_LCTRL, LT(2,KC_A), LGUI_T(KC_S), LALT_T(KC_D), LCTL_T(KC_F), LSFT_T(KC_G),
    /* RH R3 (Home) */
    RSFT_T(KC_H), RCTL_T(KC_J), RALT_T(KC_K), RGUI_T(KC_L), LT(1,KC_SCLN), KC_QUOTE,
    /* LH R4 */
    KC_LSFT, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_END,
    /* RH R4 */
    KC_PGDOWN, KC_N, KC_M, KC_COMMA, KC_DOT, KC_SLASH, KC_RSFT,
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
  [1] = LAYOUT_ergodox_pretty(
    /* LH R1 */
    KC_ESC, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, _______,
    /* RH R1 */
    _______, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11,
    /* LH R2 */
    _______, KC_EXLM, KC_AT, KC_LCBR, KC_RCBR, KC_PIPE, _______,
    /* RH R2 */
    _______, KC_UP, KC_7, KC_8, KC_9, KC_ASTR, KC_F12,
    /* LH R3 (Home) */
    _______, _______, KC_DLR, KC_LPRN, KC_RPRN, KC_GRAVE,
    /* RH R3 (Home) */
    KC_DOWN, KC_4, KC_5, KC_6, _______, _______,
    /* LH R4 */
    _______, KC_PERCENT, KC_CIRCUMFLEX, KC_LBRACKET, KC_RBRACKET, KC_TILD, _______,
    /* RH R4 */
    _______, KC_AMPR, KC_1, KC_2, KC_3, KC_BSLASH, _______,
    /* LH R5 */
    _______, _______, _______, _______, _______,
    /* RH R5 */
    _______, KC_DOT, KC_0, KC_EQUAL, _______,
    /* thumbs */
    _______, _______, _______, _______,
    _______, _______,
    _______, _______, _______, _______, _______, _______
  ),
  [2] = LAYOUT_ergodox_pretty(
    /* R1 */
    _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______,
    /* R2 */
    _______, _______, _______, KC_MS_UP, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______,
    /* R3 */
    _______, _______, KC_MS_LEFT, KC_MS_DOWN, KC_MS_RIGHT, _______,
    KC_LEFT, KC_DOWN, KC_UP, KC_RIGHT, _______, KC_MEDIA_PLAY_PAUSE,
    /* R4 */
    _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, KC_MEDIA_PREV_TRACK, KC_MEDIA_NEXT_TRACK, _______, _______,
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
