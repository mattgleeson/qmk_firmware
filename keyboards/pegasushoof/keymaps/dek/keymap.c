/*
Copyright 2016 Daniel Svensson <dsvensson@gmail.com>

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include "pegasushoof.h"

#define _______ KC_TRNS

#define KM_QWERTY  0
#define KM_FN      1

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
	/* Layer 0: Standard ISO layer */
	[KM_QWERTY] = KEYMAP( \
		KC_ESC,          KC_F1,  KC_F2,  KC_F3,  KC_F4,  KC_F5,  KC_F6,  KC_F7,  KC_F8,  KC_F9,  KC_F10, KC_F11, KC_F12,   KC_PSCR,KC_SLCK,KC_PAUS, \
		KC_GRV,  KC_1,   KC_2,   KC_3,   KC_4,   KC_5,   KC_6,   KC_7,   KC_8,   KC_9,   KC_0,   KC_MINS,KC_EQL, KC_BSLS,  KC_INS, KC_HOME,KC_PGUP, \
		KC_TAB,  KC_Q,   KC_W,   KC_E,   KC_R,   KC_T,   KC_Y,   KC_U,   KC_I,   KC_O,   KC_P,   KC_LBRC,KC_RBRC,KC_BSPC,  KC_DEL, KC_END, KC_PGDN, \
		KC_FN0,  KC_A,   KC_S,   KC_D,   KC_F,   KC_G,   KC_H,   KC_J,   KC_K,   KC_L,   KC_SCLN,KC_QUOT,        KC_ENT,                            \
		KC_LSFT, KC_NUBS,KC_Z,   KC_X,   KC_C,   KC_V,   KC_B,   KC_N,   KC_M,   KC_COMM,KC_DOT, KC_SLSH,        KC_RSFT,          KC_UP,           \
		KC_LCTL, KC_LGUI,KC_LALT,                       KC_SPC,                          KC_RALT,KC_FN0, KC_RGUI,KC_RCTL,  KC_LEFT,KC_DOWN,KC_RGHT),
	/* Layer 1: Function layer */
	[KM_FN] = KEYMAP( \
		_______,        _______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,   KC_WAKE,KC_PWR, KC_SLEP, \
		_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,   _______,_______,KC_VOLU, \
		_______,_______,_______,_______,_______,_______,_______,KC_HOME,_______, KC_END,_______,_______,_______, KC_DEL,   _______,_______,KC_VOLD, \
		_______,_______,_______,_______,_______,_______,KC_LEFT,KC_DOWN,  KC_UP,KC_RGHT,KC_PGUP, KC_GRV,        _______,                            \
		_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,KC_PGDN,_______,        _______,           KC_MPLY,         \
		_______,_______,_______,                        _______,                        _______,_______,RESET  ,_______,   KC_MPRV,KC_MSTP,KC_MNXT)
};

const uint16_t PROGMEM fn_actions[] = {
	[0] = ACTION_LAYER_MOMENTARY(KM_FN)
};

void matrix_scan_user(void) {

    uint8_t layer = biton32(layer_state);

    ph_caps_led_off();
    ph_sclk_led_off();

    switch (layer) {
        case 1:
            ph_caps_led_on();
            break;
        default:
            // none
            break;
    }

};
