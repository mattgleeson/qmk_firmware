#include QMK_KEYBOARD_H

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [0] = LAYOUT_ortho_3x10(
    KC_F1, KC_F2, KC_F3, KC_F4, KC_LBRACKET, KC_RBRACKET, KC_VOLU,    KC_PGUP,    RESET,    KC_HOME,
    KC_F5, KC_F6, KC_F7, KC_F8, KC_MPLY,     KC_MNXT,     KC_VOLD,    KC_PGDN,    KC_UP,    KC_END,
    KC_F9,KC_F10,KC_F11,KC_F12, KC_NONUS_HASH, KC_BSLASH,  _______,    KC_LEFT,    KC_DOWN,  KC_RIGHT
  )
};

void keyboard_pre_init_user(void) {
  // Call the keyboard pre init code.

  // Set our LED pins as output
  setPinOutput(D5);
  setPinOutput(B0);
}

void led_set_user(uint8_t usb_led) {
  if (IS_LED_ON(usb_led, USB_LED_NUM_LOCK)) {
    writePinLow(D5);
  } else {
    writePinHigh(D5);
  }

  if (IS_LED_ON(usb_led, USB_LED_CAPS_LOCK)) {
    writePinLow(B0);
  } else {
    writePinHigh(B0);
  }
}
