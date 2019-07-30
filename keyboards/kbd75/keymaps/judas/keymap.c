#include QMK_KEYBOARD_H
#include "quantum.h"

#define _______ KC_TRNS

//Macro Keycodes
enum
{
  M_CAPSLOCK = SAFE_RANGE
};

//Tap Dance Declarations
enum
{
  TD_PLUS = 0,
  TD_LSOP,
  TD_RSCP,
  TD_WIND,
  TD_LBRKT,
  TD_RBRKT,
  TD_LOCK,
  TD_PRSC
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  /*
  * ,---------------------------------------------------------------.
  * |Esc| F1| F2| F3| F4| F5| F6| F7| F8| F9|F10|F11|F12|Prs|Del|Pau|
  * |---------------------------------------------------------------|
  * |`  |  1|  2|  3|  4|  5|  6|  7|  8|  9|  0|  -|  =|   BSpc|Hom|
  * |---------------------------------------------------------------|
  * |Tab  |  Q|  W|  E|  R|  T|  Y|  U|  I|  O|  P|  [|  ]|  \  |End|
  * |---------------------------------------------------------------|
  * |CAPS  |  A|  S|  D|  F|  G|  H|  J|  K|  L|  ;|  '|     Ent|PgU|
  * |---------------------------------------------------------------|
  * |Shift  |  Z|  X|  C|  V|  B|  N|  M|  ,|  .|  /|  Shift| Up|PgD|
  * |---------------------------------------------------------------|
  * |Ctrl|Win|Alt |           Space          |Alt|Fn | +|Lef|Dow|Rig|
  * `---------------------------------------------------------------'
  */
  [0] = LAYOUT(
    KC_ESC,   KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,    KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_F11,   KC_F12,TD(TD_PRSC),  KC_DEL,    TD(TD_LOCK),
    KC_GRV,   KC_1,     KC_2,     KC_3,     KC_4,     KC_5,     KC_6,     KC_7,     KC_8,     KC_9,     KC_0,     KC_MINS,    KC_EQL,   KC_DEL,   KC_BSPC,  KC_HOME,
    KC_TAB,   KC_Q,     KC_W,     KC_E,     KC_R,     KC_T,     KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,TD(TD_LBRKT),TD(TD_RBRKT),  KC_BSLS,            KC_END,
    M_CAPSLOCK,  KC_A,     KC_S,     KC_D,     KC_F,     KC_G,     KC_H,     KC_J,     KC_K,     KC_L,     KC_SCLN,  KC_QUOT,                        KC_ENT,   KC_PGUP,
    TD(TD_LSOP),  MO(1),KC_Z,     KC_X,     KC_C,     KC_V,     KC_B,     KC_N,     KC_M,     KC_COMM,  KC_DOT,   KC_SLSH,TD(TD_RSCP),            KC_UP,    KC_PGDN,
    KC_LCTL,TD(TD_WIND),  KC_LALT,                    KC_SPC,   KC_SPC,   KC_SPC,                       KC_RALT,  MO(1),   TD(TD_PLUS),  KC_LEFT,  KC_DOWN,  KC_RGHT
  ),

  /*
  * ,---------------------------------------------------------------.
  * |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |Slp|
  * |---------------------------------------------------------------|
  * |   |   |   |   |   |   |   |   |   |   |   |   |   |  Reset|   |
  * |---------------------------------------------------------------|
  * |     |RgT|RgM|RH+|RH-|RS+|RS-|RV+|RV-|   |   |   |   |     |   |
  * |---------------------------------------------------------------|
  * |      |   |   |   |   |   |   |   |   |   |   |   |        |VlU|
  * |---------------------------------------------------------------|
  * |       |   |   |   |Bl-|BlT|Bl+|BlS|   |   |   |   Mute|F23|VlD|
  * |---------------------------------------------------------------|
  * |    |   |    |           Play           |   |   |  |Prv|F24|Nxt|
  * `---------------------------------------------------------------'
  */
  [1] = LAYOUT(
    _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  KC_SLEP,
    _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  RESET,    _______,
    _______,  RGB_TOG,  RGB_MOD,  RGB_HUI,  RGB_HUD,  RGB_SAI,  RGB_SAD,  RGB_VAI,  RGB_VAD,  _______,  _______,  _______,  _______,  _______,            _______,
    _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,                      _______,  KC_VOLU,
    _______,  _______,  _______,  _______,  BL_DEC,   BL_TOGG,  BL_INC,   BL_STEP,  _______,  _______,  _______,  _______,  KC_MUTE,            KC_F23,  KC_VOLD,
    _______,  _______,  _______,                      _______,  KC_MPLY,  _______,                      _______,  _______,  _______,  KC_MPRV,  KC_F24,  KC_MNXT
  ),
};

//Tap Dance Functions
void danceLeftSpaceCadetFinish(qk_tap_dance_state_t *state, void *user_data) {
  if (state->count == 1) {
    register_code (KC_LSFT);
  } else {
    register_code (KC_LSFT);
    register_code (KC_9);
  }
}

void danceLeftSpaceCadetReset (qk_tap_dance_state_t *state, void *user_data) {
  if (state->count == 1) {
    unregister_code (KC_LSFT);
  } else {
    unregister_code (KC_LSFT);
    unregister_code (KC_9);
  }
}

void danceRightSpaceCadetFinish(qk_tap_dance_state_t *state, void *user_data) {
  if (state->count == 1) {
    register_code (KC_RSFT);
  } else {
    register_code (KC_RSFT);
    register_code (KC_0);
  }
}

void danceRightSpaceCadetReset (qk_tap_dance_state_t *state, void *user_data) {
  if (state->count == 1) {
    unregister_code (KC_RSFT);
  } else {
    unregister_code (KC_RSFT);
    unregister_code (KC_0);
  }
}

void danceLeftBracketCadetFinish(qk_tap_dance_state_t *state, void *user_data) {
  if (state->count == 1) {
    register_code (KC_LBRC);
  } else {
    register_code (KC_LSFT);
    register_code (KC_LBRC);
  }
}

void danceLeftBracketCadetReset (qk_tap_dance_state_t *state, void *user_data) {
  if (state->count == 1) {
    unregister_code (KC_LBRC);
  } else {
    unregister_code (KC_LSFT);
    unregister_code (KC_LBRC);
  }
}

void danceRightBracketCadetFinish(qk_tap_dance_state_t *state, void *user_data) {
  if (state->count == 1) {
    register_code (KC_RBRC);
  } else {
    register_code (KC_RSFT);
    register_code (KC_RBRC);
  }
}

void danceRightBracketCadetReset (qk_tap_dance_state_t *state, void *user_data) {
  if (state->count == 1) {
    unregister_code (KC_RBRC);
  } else {
    unregister_code (KC_RSFT);
    unregister_code (KC_RBRC);
  }
}

void danceWindowsDesktopFinish(qk_tap_dance_state_t *state, void *user_data) {
  if (state->count == 1) {
    register_code (KC_LGUI);
  } else {
    register_code (KC_LGUI);
    register_code (KC_D);
  }
}

void danceWindowsDesktopReset (qk_tap_dance_state_t *state, void *user_data) {
  if (state->count == 1) {
    unregister_code (KC_LGUI);
  } else {
    unregister_code (KC_LGUI);
    unregister_code (KC_D);
  }
}

void dancePlusMulUndFinish(qk_tap_dance_state_t *state, void *user_data) {
  if (state->count == 1) {
    register_code (KC_PPLS);
  }
  else if(state->count == 2) {
    register_code (KC_PAST);
  }else {
    register_code (KC_LSFT);
    register_code (KC_MINS);
  }
}

void dancePlusMulUndReset (qk_tap_dance_state_t *state, void *user_data) {
  if (state->count == 1) {
    unregister_code (KC_PPLS);
  }
  else if(state->count == 2) {
    unregister_code (KC_PAST);
  }else {
    unregister_code (KC_LSFT);
    unregister_code (KC_MINS);
  }
}

void danceLockFinish(qk_tap_dance_state_t *state, void *user_data) {
  if (state->count == 2) {
    register_code (KC_LGUI);
    register_code (KC_L);
  }
}

void danceLockReset (qk_tap_dance_state_t *state, void *user_data) {
  if (state->count == 2) {
    unregister_code (KC_LGUI);
    unregister_code (KC_L);
  }
}

void dancePrintScreenFinish(qk_tap_dance_state_t *state, void *user_data) {
  if (state->count == 1) {
    register_code (KC_PSCR);
  } else {
    register_code (KC_LGUI);
    register_code (KC_LSFT);
    register_code (KC_S);
  }
}

void dancePrintScreenReset (qk_tap_dance_state_t *state, void *user_data) {
  if (state->count == 1) {
    unregister_code (KC_PSCR);
  } else {
    unregister_code (KC_LGUI);
    unregister_code (KC_LSFT);
    unregister_code (KC_S);
  }
}

//Tap dance definitions
qk_tap_dance_action_t tap_dance_actions[] =
{
  //Tap once for left shift, twice for open parenthesis (Space Cadet Shift)
  [TD_LSOP] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, danceLeftSpaceCadetFinish, danceLeftSpaceCadetReset),
  //Tap once for right shift, twice for close parenthesis (Space Cadet Shift)
  [TD_RSCP] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, danceRightSpaceCadetFinish, danceRightSpaceCadetReset),
  //Tap once for left GUI, twice for Ctrl+D (Show/Hide Desktop) ###WIP###
  [TD_WIND] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, danceWindowsDesktopFinish, danceWindowsDesktopReset),
  //Tap once for +, twice for *, thrice for _
  [TD_PLUS] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, dancePlusMulUndFinish, dancePlusMulUndReset),
  //Tap once for [, twice for { (Left Bracket Cadet)
  [TD_LBRKT] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, danceLeftBracketCadetFinish, danceLeftBracketCadetReset),
  //Tap once for ], twice for } (Right Bracket Cadet)
  [TD_RBRKT] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, danceRightBracketCadetFinish, danceRightBracketCadetReset),
  //Tap twice to lock computer, tapping once does nothing
  [TD_LOCK] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, danceLockFinish, danceLockReset),
  //Tap once for PrintScreen, tap twice for Screen Snip
  [TD_PRSC] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, dancePrintScreenFinish, dancePrintScreenReset)
};

bool process_record_user(uint16_t keycode, keyrecord_t *record)
{
  if(record->event.pressed)
  {
    switch(keycode)
    {
      case M_CAPSLOCK:
        if(host_keyboard_leds() & (1<<USB_LED_CAPS_LOCK))
        {
          //Set RGB underglow to rainbow swirl + 5 when capslock disabled
          rgblight_mode(14);
        }
        else
        {
          //Set RGB underglow to red breathing + 3 when capslock enabled
          rgblight_setrgb(255, 0, 0);
          rgblight_mode(5);
        }
        SEND_STRING(SS_TAP(X_CAPSLOCK));
        return false;
        break;
    }
  }
  return true;
}

void led_set_user(uint8_t usb_led) {
    if (usb_led & (1 << USB_LED_CAPS_LOCK)) {
        DDRB |= (1 << 2); PORTB &= ~(1 << 2);
    } else {
        DDRB &= ~(1 << 2); PORTB &= ~(1 << 2);
    }
}
