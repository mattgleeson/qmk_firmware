#undef TAPPING_TERM
#define TAPPING_TERM 200
#undef IGNORE_MOD_TAP_INTERRUPT
#define IGNORE_MOD_TAP_INTERRUPT 1

#define LAYOUT_wrapper(...) LAYOUT(__VA_ARGS__)

#define KC_GPM_LIKE_SONG C(S(KC_UP))
#define KC_MAC_SHOW_WINS LCTL(KC_UP)

#define MG_HOME_L KC_LCTRL, LT(2,KC_A), LGUI_T(KC_S), LALT_T(KC_D), LCTL_T(KC_F), LSFT_T(KC_G)
#define MG_HOME_R RSFT_T(KC_H), RCTL_T(KC_J), RALT_T(KC_K), RGUI_T(KC_L), LT(1,KC_SCLN), KC_QUOTE

#define MG_LH_R1 KC_EQL, KC_1, KC_2, KC_3, KC_4, KC_5
#define MG_RH_R1 KC_6, KC_7, KC_8, KC_9, KC_0, KC_MINUS
#define MG_LH_R2 KC_TAB, KC_Q, KC_W, KC_E, KC_R, KC_T
#define MG_RH_R2 KC_Y, KC_U, KC_I, KC_O, KC_P, KC_BSLASH
#define MG_LH_R3 MG_HOME_L
#define MG_RH_R3 MG_HOME_R
#define MG_LH_R4 KC_LSFT, KC_Z, KC_X, KC_C, KC_V, KC_B
#define MG_RH_R4 KC_N, KC_M, KC_COMMA, KC_DOT, KC_SLASH, KC_RSFT

#define MG_1_LH_R1 KC_ESC, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5
#define MG_1_LH_R2 _______, KC_EXLM, KC_AT, KC_LCBR, KC_RCBR, KC_PIPE
#define MG_1_LH_R3 KC_CAPS, _______, KC_DLR, KC_LPRN, KC_RPRN, KC_GRAVE
#define MG_1_LH_R4 _______, KC_PERCENT, KC_CIRCUMFLEX, KC_LBRACKET, KC_RBRACKET, KC_TILD

#define MG_1_RH_R1 KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11
#define MG_1_RH_R2 KC_UP, KC_7, KC_8, KC_9, KC_ASTR, KC_F12
#define MG_1_RH_R3 KC_DOWN, KC_4, KC_5, KC_6, _______, _______
#define MG_1_RH_R4 RESET, KC_1, KC_2, KC_3, KC_BSLASH, _______

#define MG_2_LH_R1 _______, _______, _______, _______, _______, _______
#define MG_2_LH_R2 _______, _______, _______, KC_MS_UP, _______, _______
#define MG_2_LH_R3 _______, _______, KC_MS_LEFT, KC_MS_DOWN, KC_MS_RIGHT, _______
#define MG_2_LH_R4 _______, _______, _______, _______, _______, RESET

#define MG_2_RH_R1 _______, _______, _______, _______, _______, _______
#define MG_2_RH_R2 KC_END, KC_PGDN, KC_PGUP, KC_HOME, _______, _______
#define MG_2_RH_R3 KC_LEFT, KC_DOWN, KC_UP, KC_RIGHT, KC_BRIGHTNESS_DOWN, KC_BRIGHTNESS_UP
#define MG_2_RH_R4 KC_GPM_LIKE_SONG, KC_AUDIO_VOL_DOWN, KC_AUDIO_VOL_UP, KC_MEDIA_PLAY_PAUSE, KC_MEDIA_NEXT_TRACK, _______

#define MG_12X4 MG_LH_R1, MG_RH_R1, MG_LH_R2, MG_RH_R2, MG_LH_R3, MG_RH_R3, MG_LH_R4, MG_RH_R4
#define MG_1_12X4 MG_1_LH_R1, MG_1_RH_R1, MG_1_LH_R2, MG_1_RH_R2, MG_1_LH_R3, MG_1_RH_R3, MG_1_LH_R4, MG_1_RH_R4
#define MG_2_12X4 MG_2_LH_R1, MG_2_RH_R1, MG_2_LH_R2, MG_2_RH_R2, MG_2_LH_R3, MG_2_RH_R3, MG_2_LH_R4, MG_2_RH_R4
