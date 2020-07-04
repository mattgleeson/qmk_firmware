#define KC_ KC_TRNS
#define KC__ KC_TRNS
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

#define KC_GPM_LIKE_SONG C(S(KC_UP))
#define KC_MAC_SHOW_WINS LCTL(KC_UP)

#define MG_HOME_L LT(2,KC_A), LGUI_T(KC_S), LALT_T(KC_D), LCTL_T(KC_F), LSFT_T(KC_G)
#define MG_HOME_R RSFT_T(KC_H), RCTL_T(KC_J), RALT_T(KC_K), RGUI_T(KC_L), LT(1,KC_SCLN)

#define MG_LTHUMB_NEAR KC_TAB
#define MG_LTHUMB_FAR KC_ENT
#define MG_LTHUMB_IN MO(2)
#define MG_RTHUMB_NEAR KC_SPC
#define MG_RTHUMB_FAR KC_BSPC
#define MG_RTHUMB_IN MO(1)

#define MG_ALH_R2 KC_Q, KC_W, KC_E, KC_R, KC_T
#define MG_ALH_R3 MG_HOME_L
#define MG_ALH_R4 KC_Z, KC_X, KC_C, KC_V, KC_B

#define MG_ARH_R2 KC_Y, KC_U, KC_I, KC_O, KC_P
#define MG_ARH_R3 MG_HOME_R
#define MG_ARH_R4 KC_N, KC_M, KC_COMMA, KC_DOT, KC_SLASH

/* LAYER 1 */
#define MG_1_ALH_R2 KC_EXLM, KC_AT,   KC_LCBR, KC_RCBR, KC_PIPE
#define MG_1_ALH_R3 _______, KC_DLR,  KC_LPRN, KC_RPRN, KC_GRAVE
#define MG_1_ALH_R4 KC_PERC, KC_CIRC, KC_LBRC, KC_RBRC, KC_TILD

#define MG_1_ARH_R2 KC_UP,   KC_7,    KC_8,    KC_9,    KC_0
#define MG_1_ARH_R3 KC_DOWN, KC_4,    KC_5,    KC_6,    _______
#define MG_1_ARH_R4 RESET,   KC_1,    KC_2,    KC_3,    KC_BSLASH

/* LAYER 2 */
#define MG_2_ALH_R2 KC_DEL,  _______, KC_MS_U, _______, _______
#define MG_2_ALH_R3 _______, KC_MS_L, KC_MS_D, KC_MS_R, _______
#define MG_2_ALH_R4 KC_ESC,  _______, _______, _______, RESET

#define MG_2_ARH_R2 KC_END,  KC_PGDN, KC_PGUP, KC_HOME, _______
#define MG_2_ARH_R3 KC_LEFT, KC_DOWN, KC_UP,   KC_RIGHT, KC_BRIGHTNESS_DOWN
#define MG_2_ARH_R4 KC_GPM_LIKE_SONG, KC_AUDIO_VOL_DOWN, KC_AUDIO_VOL_UP, KC_MEDIA_PLAY_PAUSE, KC_MEDIA_NEXT_TRACK


#define MG_LH_R1 KC_EQL, KC_1, KC_2, KC_3, KC_4, KC_5
#define MG_LH_R2 KC_TAB, MG_ALH_R2
#define MG_LH_R3 LCTL_T(KC_ESC), MG_HOME_L
#define MG_LH_R4 KC_LSFT, MG_ALH_R4

#define MG_RH_R1 KC_6, KC_7, KC_8, KC_9, KC_0, KC_MINUS
#define MG_RH_R2 MG_ARH_R2, KC_BSLASH
#define MG_RH_R3 MG_HOME_R, KC_QUOTE
#define MG_RH_R4 MG_ARH_R4, KC_RSFT

#define MG_1_LH_R1 KC_ESC, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5
#define MG_1_LH_R2 KC_DEL,  MG_1_ALH_R2
#define MG_1_LH_R3 KC_CAPS, MG_1_ALH_R3
#define MG_1_LH_R4 _______, MG_1_ALH_R4

#define MG_1_RH_R1 KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11
#define MG_1_RH_R2 MG_1_ARH_R2, KC_F12
#define MG_1_RH_R3 MG_1_ARH_R3, _______
#define MG_1_RH_R4 MG_1_ARH_R4, _______

#define MG_2_LH_R1 _______, _______, _______, _______, _______, _______
#define MG_2_LH_R2 _______, MG_2_ALH_R2
#define MG_2_LH_R3 _______, MG_2_ALH_R3
#define MG_2_LH_R4 _______, MG_2_ALH_R4

#define MG_2_RH_R1 _______, _______, _______, _______, _______, _______
#define MG_2_RH_R2 MG_2_ARH_R2, _______
#define MG_2_RH_R3 MG_2_ARH_R3, KC_BRIGHTNESS_UP
#define MG_2_RH_R4 MG_2_ARH_R4, _______

#define MG_12X4 MG_LH_R1, MG_RH_R1, MG_LH_R2, MG_RH_R2, MG_LH_R3, MG_RH_R3, MG_LH_R4, MG_RH_R4
#define MG_1_12X4 MG_1_LH_R1, MG_1_RH_R1, MG_1_LH_R2, MG_1_RH_R2, MG_1_LH_R3, MG_1_RH_R3, MG_1_LH_R4, MG_1_RH_R4
#define MG_2_12X4 MG_2_LH_R1, MG_2_RH_R1, MG_2_LH_R2, MG_2_RH_R2, MG_2_LH_R3, MG_2_RH_R3, MG_2_LH_R4, MG_2_RH_R4

