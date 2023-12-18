#include QMK_KEYBOARD_H

uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
  case CTL_A:
  case CTL_O:
    return TAPPING_TERM;// + 200;
  default:
    return TAPPING_TERM;
  }
};
