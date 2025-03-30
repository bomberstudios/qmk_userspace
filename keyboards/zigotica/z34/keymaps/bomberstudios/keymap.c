// z34
#include QMK_KEYBOARD_H

// Keyboard Layers
enum layers { _COLEMAK, _QWERTY, _MOVE, _NUMBER, _SYMBOL, _ADJUST };

enum custom_keycodes { M_EMAIL = SAFE_RANGE, CPYPASTE, CMD_TAB, CTL_TAB, RANDOM, M_PASS, M_PASS2, GLOBE };

bool process_record_user(uint16_t keycode, keyrecord_t* record) {
    switch (keycode) {
        case M_EMAIL:
            if (record->event.pressed) {
                SEND_STRING(SECRET_EMAIL);
            }
            return false;
        case M_PASS:
            if (record->event.pressed) {
                SEND_STRING(SECRET_PASSWORD);
            }
            return false;
        case M_PASS2:
            if (record->event.pressed) {
                SEND_STRING(SECRET_PASSWORD_2);
            }
            return false;
        case GLOBE:
            if (record->event.pressed) {
                host_consumer_send(AC_NEXT_KEYBOARD_LAYOUT_SELECT);
            } else {
                host_consumer_send(0);
            }
            return false;
    }
    return true;
};

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_COLEMAK] = LAYOUT(
        KC_Q,  KC_W,  KC_F,  KC_P,  KC_G,       KC_J,  KC_L,  KC_U,    KC_Y,   KC_SCLN,
        CTL_A, ALT_R, CMD_S, SHT_T, KC_D,       KC_H,  SHT_N, CMD_E,   ALT_I,  CTL_O,
        KC_Z,  KC_X,  KC_C,  KC_V,  KC_B,       KC_K,  KC_M,  KC_COMM, KC_DOT, KC_SLSH,
                             L_NUM, KC_BSPC,    SPC_3, L_SYM
    ),
    [_QWERTY]  = LAYOUT(KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, CTL_A, ALT_S, CMD_D, SHT_F, KC_G, KC_H, SHT_J, CMD_K, ALT_L, CTL_CLN, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, L_NUM, KC_BSPC, SPC_3, L_SYM),
    [_MOVE]    = LAYOUT(
        KC_ESC,   L_COL, CTL_TAB, CMD_TAB,  LINEDEL,        LINEUP,   START,   KC_UP,   END,      ZOOMLEFT,
        Ctrl,     Alt,   Cmd,     Shift,    LINEDUP,        LINEDWN,  KC_LEFT, KC_DOWN, KC_RIGHT, ZOOMRIGHT,
        ZOOMFULL, CUT,   COPY,    CPYPASTE, SKRUN,          ZOOMFULL, SHT_SCR, SHT_ARE, SHT_OPT,  MOVETOLAPTOP,
                                  KC_ESC,   _______,        _______,  KC_PENT
    ),
    [_NUMBER]  = LAYOUT(
        KC_F1,  KC_F2,  KC_F3,  KC_F4,  KC_F5,          _______, KC_7, KC_8, KC_9, _______,
        CMD_1,  CMD_2,  CMD_3,  CMD_4,  CMD_5,          _______, KC_4, KC_5, KC_6, KC_0,
        KC_F6,  KC_F7,  KC_F8,  KC_F9,  KC_F10,         _______, KC_1, KC_2, KC_3, KC_PENT,
                                _______,_______,        _______, KC_0
    ),
    [_SYMBOL]  = LAYOUT(KC_EXLM, KC_AT, KC_HASH, KC_DLR, KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, M_EMAIL, _______, KC_GRV, KC_QUOT, KC_COLN, KC_BSLS, KC_MINS, KC_EQL, KC_LBRC, KC_RBRC, QK_BOOT, _______, KC_TILD, KC_DQUO, KC_SCLN, KC_PIPE, KC_UNDS, KC_PLUS, KC_LCBR, KC_RCBR, L_ADJ, KC_DEL, _______, _______),
    [_ADJUST]  = LAYOUT(QWERTY, COLEMAK, KC_HASH, KC_DLR, KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_VOLU, M_EMAIL, _______, KC_GRV, KC_QUOT, KC_COLN, KC_BSLS, KC_MPLY, KC_EQL, KC_LBRC, KC_MUTE, QK_BOOT, _______, KC_TILD, KC_DQUO, KC_SCLN, KC_PIPE, KC_UNDS, KC_PLUS, KC_LCBR, KC_VOLD, L_ADJ, KC_DEL, _______, _______)
};

const char chordal_hold_layout[MATRIX_ROWS][MATRIX_COLS] PROGMEM =
    LAYOUT(
        'L', 'L', 'L', 'L', 'L',  'R', 'R', 'R', '*', '*',
        'L', 'L', 'L', 'L', 'L',  'R', 'R', 'R', 'R', 'R',
        'L', 'L', 'L', 'L', 'L',  '*', 'R', 'R', 'R', 'R',
                       '*', '*',  '*', '*'
    );
// clang-format on
