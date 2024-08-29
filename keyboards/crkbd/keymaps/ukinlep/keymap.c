/*
Copyright 2019 @foostan
Copyright 2020 Drashna Jaelre <@drashna>

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

#include QMK_KEYBOARD_H

enum combos {
  SNT_ENTER,
  BH_Q, 
  FL_Z, 
};

const uint16_t PROGMEM snt_combo[] = {KC_S, KC_N, KC_T, COMBO_END};
const uint16_t PROGMEM bh_combo[] = {KC_B, KC_H, COMBO_END};
const uint16_t PROGMEM fl_combo[] = {KC_F, KC_L, COMBO_END};

combo_t key_combos[] = {
  [SNT_ENTER] = COMBO(snt_combo, KC_ENTER),
  [BH_Q] = COMBO(bh_combo, KC_Q),
  [FL_Z] = COMBO(fl_combo, KC_Z)
};

typedef enum {
    TD_NONE,
    TD_UNKNOWN,
    TD_SINGLE_TAP,
    TD_SINGLE_HOLD,
    TD_DOUBLE_TAP,
    TD_DOUBLE_HOLD,
    TD_DOUBLE_SINGLE_TAP, // Send two single taps
    TD_TRIPLE_TAP,
    TD_TRIPLE_HOLD
} td_state_t;

typedef struct {
    bool is_press_action;
    td_state_t state;
} td_tap_t;

// Tap dance enums
enum {
    X_CTL,
    TD_SHIFT_CAPS,
};

td_state_t cur_dance(tap_dance_state_t *state);

// For the x tap dance. Put it here so it can be used in any keymap
void x_finished(tap_dance_state_t *state, void *user_data);
void x_reset(tap_dance_state_t *state, void *user_data);


//Tap Dance Definitions
tap_dance_state_t tap_dance_actions[] = {
  //Tap once for Esc, twice for Caps Lock
//   [X_CTL] = ACTION_TAP_DANCE_FN_ADVANCED(NULL,x_finished, x_reset),
//   [TD_SHIFT_CAPS] = ACTION_TAP_DANCE_DOUBLE(KC_LSFT, KC_CAPS)
};


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
       KC_TAB,KC_QUOTE,    KC_B,    KC_H,    KC_G,LSFT(KC_QUOTE),                KC_SCLN,  KC_DOT,KC_SLASH,    KC_J,   KC_X,     KC_Z,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
        DF(1), LGUI_T(KC_C), LALT_T(KC_S), LCTL_T(KC_N), LSFT_T(KC_T), KC_K,    KC_COMMA, LSFT_T(KC_A), LCTL_T(KC_E), LALT_T(KC_I), LGUI_T(KC_M), KC_Q,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
        KC_NO,    KC_P,    KC_F,    KC_L,    KC_D,    KC_V,                     KC_MINUS,    KC_U,    KC_O,    KC_Y,    KC_W, KC_RALT,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          //QK_GESC,   TD(5),   TD(3),      TD(0),   TD(2),   TD(1)
                                          QK_GESC,   KC_SPC,   KC_SPC,      KC_LSFT,   KC_SPC, KC_BSPC
                                      //`--------------------------'  `--------------------------'
  ),

     [1] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      KC_TRNS,    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                         KC_Y,    KC_U,    KC_I,    KC_O,   KC_P,  KC_TRNS,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
        DF(0), LGUI_T(KC_A), LALT_T(KC_S), LCTL_T(KC_D), LSFT_T(KC_F), KC_G,        KC_H, LSFT_T(KC_J), LCTL_T(KC_K), LALT_T(KC_L), LGUI_T(KC_SCLN), KC_TRNS,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_TRNS,    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                         KC_N,    KC_M, KC_COMM,  KC_DOT, KC_SLSH,  KC_TRNS,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_TRNS, KC_TRNS, KC_TRNS,    KC_TRNS, KC_TRNS, KC_TRNS
                                      //`--------------------------'  `--------------------------'
  ), 

     [2] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
        KC_NO, KC_LBRC,    KC_7,    KC_8,    KC_9, KC_RBRC,                        KC_NO,   KC_F7,   KC_F8,   KC_F9,  KC_F12,   KC_NO,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
        KC_NO,KC_GRAVE,    KC_4,    KC_5,    KC_6, KC_EQUAL,                       KC_NO, KC_F4, KC_F5, KC_F6, KC_F11, KC_NO,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
        KC_NO,KC_QUOTE,    KC_1,    KC_2,    KC_3, KC_BSLS,                      KC_NO, KC_F1, KC_F2, KC_F3, KC_F10, KC_NO,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                        KC_KP_DOT,    KC_0,KC_MINUS,      KC_NO,   KC_NO,   KC_NO
                                      //`--------------------------'  `--------------------------'
  ), 

     [3] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
        KC_NO, LSFT(KC_LBRC), LSFT(KC_7), LSFT(KC_8), LSFT(KC_9), LSFT(KC_RBRC),   KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
        KC_NO, LSFT(KC_GRAVE), LSFT(KC_4), LSFT(KC_5), LSFT(KC_6), LSFT(KC_EQUAL), KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
        KC_NO, LSFT(KC_QUOTE), LSFT(KC_1), LSFT(KC_2), LSFT(KC_3), LSFT(KC_BSLS),KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                             LSFT(KC_9), LSFT(KC_0), LSFT(KC_MINUS),      KC_NO,   KC_NO,   KC_NO
                                      //`--------------------------'  `--------------------------'
  ), 

     [4] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
        KC_NO, LGUI(KC_Q), LGUI(KC_W), LGUI(KC_E), LGUI(KC_R), LGUI(KC_T),     KC_INSERT, KC_WH_R, KC_WH_U, KC_WH_D, KC_WH_L, KC_NO,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
        KC_NO, LGUI(KC_A), LGUI(KC_S), LGUI(KC_D), LGUI(KC_F), LGUI(KC_G),       KC_CAPS, KC_LEFT, KC_DOWN, KC_UP, KC_RIGHT, KC_NO,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
        KC_NO, LGUI(KC_Z), LGUI(KC_X), LGUI(KC_C), LGUI(KC_V), LGUI(KC_B),     KC_DELETE, LGUI(KC_LEFT),    KC_PGDN, KC_PGUP, LGUI(KC_RIGHT), KC_NO,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                            KC_NO,   KC_NO,   KC_NO,    KC_BTN1, KC_BTN3, KC_BTN2
                                      //`--------------------------'  `--------------------------'
  )
};



td_state_t cur_dance(tap_dance_state_t *state) {
    if (state->count == 1) {
        if (state->interrupted || !state->pressed) return TD_SINGLE_TAP;
        // Key has not been interrupted, but the key is still held. Means you want to send a 'HOLD'.
        else return TD_SINGLE_HOLD;
    } else if (state->count == 2) {
        // TD_DOUBLE_SINGLE_TAP is to distinguish between typing "pepper", and actually wanting a double tap
        // action when hitting 'pp'. Suggested use case for this return value is when you want to send two
        // keystrokes of the key, and not the 'double tap' action/macro.
        if (state->interrupted) return TD_DOUBLE_SINGLE_TAP;
        else if (state->pressed) return TD_DOUBLE_HOLD;
        else return TD_DOUBLE_TAP;
    }

    // Assumes no one is trying to type the same letter three times (at least not quickly).
    // If your tap dance key is 'KC_W', and you want to type "www." quickly - then you will need to add
    // an exception here to return a 'TD_TRIPLE_SINGLE_TAP', and define that enum just like 'TD_DOUBLE_SINGLE_TAP'
    if (state->count == 3) {
        if (state->interrupted || !state->pressed) return TD_TRIPLE_TAP;
        else return TD_TRIPLE_HOLD;
    } else return TD_UNKNOWN;
}

// Create an instance of 'td_tap_t' for the 'x' tap dance.
static td_tap_t xtap_state = {
    .is_press_action = true,
    .state = TD_NONE
};

void x_finished(tap_dance_state_t *state, void *user_data) {
    xtap_state.state = cur_dance(state);
    switch (xtap_state.state) {
        case TD_SINGLE_TAP: register_code(KC_X); break;
        case TD_SINGLE_HOLD: register_code(KC_LCTL); break;
        case TD_DOUBLE_TAP: register_code(KC_ESC); break;
        case TD_DOUBLE_HOLD: register_code(KC_LALT); break;
        // Last case is for fast typing. Assuming your key is `f`:
        // For example, when typing the word `buffer`, and you want to make sure that you send `ff` and not `Esc`.
        // In order to type `ff` when typing fast, the next character will have to be hit within the `TAPPING_TERM`, which by default is 200ms.
        case TD_DOUBLE_SINGLE_TAP: tap_code(KC_X); register_code(KC_X); break;
        default: break;
    }
}

void x_reset(tap_dance_state_t *state, void *user_data) {
    switch (xtap_state.state) {
        case TD_SINGLE_TAP: unregister_code(KC_X); break;
        case TD_SINGLE_HOLD: unregister_code(KC_LCTL); break;
        case TD_DOUBLE_TAP: unregister_code(KC_ESC); break;
        case TD_DOUBLE_HOLD: unregister_code(KC_LALT); break;
        case TD_DOUBLE_SINGLE_TAP: unregister_code(KC_X); break;
        default: break;
    }
    xtap_state.state = TD_NONE;
}

