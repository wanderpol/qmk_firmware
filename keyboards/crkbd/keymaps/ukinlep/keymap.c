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
  SDF_ENTER,
  BH_Q, 
  FL_P,
  HG_Z,
  JSlash_X,
  OY_W
};

// const uint16_t PROGMEM snt_combo[] = {LALT_T(KC_S), LCTL_T(KC_N), LSFT_T(KC_T), COMBO_END};
// const uint16_t PROGMEM sdf_combo[] = {LALT_T(KC_S), LCTL_T(KC_D), LSFT_T(KC_F), COMBO_END};
const uint16_t PROGMEM snt_combo[] = {KC_S, KC_N, KC_T, COMBO_END};
const uint16_t PROGMEM sdf_combo[] = {KC_S, KC_D, KC_F, COMBO_END};
const uint16_t PROGMEM bh_combo[] = {KC_B, KC_H, COMBO_END};
const uint16_t PROGMEM fl_combo[] = {KC_F, KC_L, COMBO_END};
const uint16_t PROGMEM hg_combo[] = {KC_H, KC_G, COMBO_END};
const uint16_t PROGMEM jslash_combo[] = {KC_J, KC_SLSH, COMBO_END};
const uint16_t PROGMEM oy_combo[] = {KC_O, KC_Y, COMBO_END};

combo_t key_combos[] = {
  [SNT_ENTER] = COMBO(snt_combo, KC_ENTER),
  [SDF_ENTER] = COMBO(sdf_combo, KC_ENTER),
  [BH_Q] = COMBO(bh_combo, KC_Q),
  [FL_P] = COMBO(fl_combo, KC_P),
  [HG_Z] = COMBO(hg_combo, KC_Z),
  [JSlash_X] = COMBO(jslash_combo, KC_Z)
  [OY_W] = COMBO(oy_combo, KC_W)
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

// Create an instance of 'td_tap_t' for the 'x' tap dance.
static td_tap_t r1tap_state = {
    .is_press_action = true,
    .state = TD_NONE
};
static td_tap_t r2tap_state = {
    .is_press_action = true,
    .state = TD_NONE
};
static td_tap_t r3tap_state = {
    .is_press_action = true,
    .state = TD_NONE
};
static td_tap_t l1tap_state = {
    .is_press_action = true,
    .state = TD_NONE
};
static td_tap_t l2tap_state = {
    .is_press_action = true,
    .state = TD_NONE
};

// Create a global instance of the tapdance state type
// static td_state_t td_state_sss;


// Tap dance enums
enum {
    TD_R1,
    TD_R2,
    TD_R3,
    TD_L1,
    TD_L2
};

td_state_t cur_dance(tap_dance_state_t *state);

// For the x tap dance. Put it here so it can be used in any keymap
void td_r1_finished(tap_dance_state_t *state, void *user_data);
void td_r1_reset(tap_dance_state_t *state, void *user_data);
void td_r2_finished(tap_dance_state_t *state, void *user_data);
void td_r2_reset(tap_dance_state_t *state, void *user_data);
void td_r3_finished(tap_dance_state_t *state, void *user_data);
void td_r3_reset(tap_dance_state_t *state, void *user_data);
void td_l1_finished(tap_dance_state_t *state, void *user_data);
void td_l1_reset(tap_dance_state_t *state, void *user_data);
void td_l2_finished(tap_dance_state_t *state, void *user_data);
void td_l2_reset(tap_dance_state_t *state, void *user_data);


//Tap Dance Definitions
tap_dance_action_t tap_dance_actions[] = {
  //Tap once for Esc, twice for Caps Lock
  [TD_R1] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, td_r1_finished, td_r1_reset),
  [TD_R2] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, td_r2_finished, td_r2_reset),
  [TD_R3] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, td_r3_finished, td_r3_reset),
  [TD_L1] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, td_l1_finished, td_l1_reset),
  [TD_L2] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, td_l2_finished, td_l2_reset),
};


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
       KC_TAB,KC_QUOTE,    KC_B,    KC_H,    KC_G,LSFT(KC_QUOTE),                KC_SCLN,  KC_DOT,KC_SLASH,    KC_J,   KC_X,     KC_Z,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
        // DF(1), LGUI_T(KC_C), LALT_T(KC_S), LCTL_T(KC_N), LSFT_T(KC_T), KC_K,    KC_COMMA, LSFT_T(KC_A), LCTL_T(KC_E), LALT_T(KC_I), LGUI_T(KC_M), KC_Q,
        DF(1), KC_C, KC_S, KC_N, KC_T, KC_K,    KC_COMMA, KC_A, KC_E, KC_I, KC_M, KC_Q,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LSFT,    KC_P,    KC_F,    KC_L,    KC_D,    KC_V,                     KC_MINUS,    KC_U,    KC_O,    KC_Y,    KC_W, KC_RALT,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          QK_GESC,TD(TD_L2),TD(TD_L1), TD(TD_R1),TD(TD_R2),TD(TD_R3)
                                      //`--------------------------'  `--------------------------'
  ),

     [1] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      KC_TRNS,    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                         KC_Y,    KC_U,    KC_I,    KC_O,   KC_P,  KC_TRNS,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
        // DF(0), LGUI_T(KC_A), LALT_T(KC_S), LCTL_T(KC_D), LSFT_T(KC_F), KC_G,        KC_H, LSFT_T(KC_J), LCTL_T(KC_K), LALT_T(KC_L), LGUI_T(KC_SCLN), KC_TRNS,
        DF(0), KC_A, KC_S, KC_D, KC_F, KC_G,        KC_H, KC_J, KC_K, KC_L, KC_SCLN, KC_TRNS,
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
        KC_NO,KC_GRAVE,    KC_4,    KC_5,    KC_6, KC_EQUAL,                       KC_NO,   KC_F4, KC_F5, KC_F6, KC_F11, KC_NO,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
        KC_NO,KC_QUOTE,    KC_1,    KC_2,    KC_3, KC_BSLS,                        KC_NO,   KC_F1, KC_F2, KC_F3, KC_F10, KC_NO,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                             KC_9,    KC_0,KC_MINUS,      KC_NO,   KC_NO,   KC_NO
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
        KC_NO, LGUI(KC_Z), LGUI(KC_X), LGUI(KC_C), LGUI(KC_V), LGUI(KC_B),        KC_DEL, LGUI(KC_LEFT),    KC_PGDN, KC_PGUP, LGUI(KC_RIGHT), KC_NO,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                            KC_NO,   KC_NO,   KC_NO,    KC_BTN1, KC_BTN3, KC_BTN2
                                      //`--------------------------'  `--------------------------'
  ),
   [5] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
        KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,                        KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
        KC_NO, KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT,   KC_NO,                        KC_NO, KC_LSFT, KC_LCTL, KC_LALT, KC_LGUI,   KC_NO,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
        KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,                        KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
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



void td_r1_finished(tap_dance_state_t *state, void *user_data) {
    r1tap_state.state = cur_dance(state);
    switch (r1tap_state.state) {
        case TD_SINGLE_TAP: set_oneshot_mods(MOD_BIT(KC_LSFT)); break;
        case TD_SINGLE_HOLD: layer_on(2); break;
        case TD_DOUBLE_TAP: register_code(KC_CAPS); break;
        case TD_DOUBLE_HOLD: layer_on(3); break;
        // case TD_DOUBLE_SINGLE_TAP: break;
        default: break;
    }
}

void td_r1_reset(tap_dance_state_t *state, void *user_data) {
    switch (r1tap_state.state) {
        // case TD_SINGLE_TAP: clear_oneshot_mods(); break;
        case TD_SINGLE_HOLD: layer_off(2); break;
        case TD_DOUBLE_TAP: unregister_code(KC_CAPS); break;
        case TD_DOUBLE_HOLD: layer_off(3); break;
        // case TD_DOUBLE_SINGLE_TAP: break;
        default: break;
    }
    r1tap_state.state = TD_NONE;
}

void td_r2_finished(tap_dance_state_t *state, void *user_data) {
    r2tap_state.state = cur_dance(state);
    switch (r2tap_state.state) {
        case TD_SINGLE_TAP: register_code(KC_SPC); break;
        case TD_SINGLE_HOLD: layer_on(3); break;
        case TD_DOUBLE_TAP: register_code(KC_SPC); break;
        case TD_DOUBLE_HOLD: register_code(KC_SPC); break;
        case TD_DOUBLE_SINGLE_TAP: tap_code(KC_SPC); register_code(KC_SPC);  break;
        default: break;
    }
}

void td_r2_reset(tap_dance_state_t *state, void *user_data) {
    switch (r2tap_state.state) {
        case TD_SINGLE_TAP: unregister_code(KC_SPC); break;
        case TD_SINGLE_HOLD: layer_off(3); break;
        case TD_DOUBLE_TAP: unregister_code(KC_SPC); break;
        case TD_DOUBLE_HOLD: unregister_code(KC_SPC); break;
        case TD_DOUBLE_SINGLE_TAP: unregister_code(KC_SPC); break;
        default: break;
    }
    r2tap_state.state = TD_NONE;
}

void td_r3_finished(tap_dance_state_t *state, void *user_data) {
    r3tap_state.state = cur_dance(state);
    switch (r3tap_state.state) {
        case TD_SINGLE_TAP: register_code(KC_BSPC); break;
        case TD_SINGLE_HOLD: register_code(KC_BSPC); break;
        // case TD_DOUBLE_TAP: tap_code16(C(KC_SPC)); break;
        case TD_DOUBLE_TAP: register_code(KC_DEL); break;
        case TD_DOUBLE_HOLD: register_code(KC_DEL); break;
        // case TD_DOUBLE_SINGLE_TAP: break;
        default: break;
    }
}

void td_r3_reset(tap_dance_state_t *state, void *user_data) {
    switch (r3tap_state.state) {
        case TD_SINGLE_TAP: unregister_code(KC_BSPC); break;
        case TD_SINGLE_HOLD: unregister_code(KC_BSPC); break;
        case TD_DOUBLE_TAP: unregister_code(KC_DEL); break;
        case TD_DOUBLE_HOLD: unregister_code(KC_DEL); break;
        // case TD_DOUBLE_SINGLE_TAP: break;
        default: break;
    }
    r3tap_state.state = TD_NONE;
}


void td_l1_finished(tap_dance_state_t *state, void *user_data) {
    l1tap_state.state = cur_dance(state);
    switch (l1tap_state.state) {
        case TD_SINGLE_TAP: register_code(KC_TAB); break;
        case TD_SINGLE_HOLD: layer_on(4); break;
        case TD_DOUBLE_TAP: register_code(KC_CAPS); break;
        case TD_DOUBLE_HOLD: layer_on(5); break;
        // case TD_DOUBLE_SINGLE_TAP: break;
        default: break;
    }
}

void td_l1_reset(tap_dance_state_t *state, void *user_data) {
    switch (l1tap_state.state) {
        case TD_SINGLE_TAP: unregister_code(KC_TAB); break;
        case TD_SINGLE_HOLD: layer_off(4); break;
        case TD_DOUBLE_TAP: unregister_code(KC_CAPS); break;
        case TD_DOUBLE_HOLD: layer_off(5); break;
        // case TD_DOUBLE_SINGLE_TAP: break;
        default: break;
    }
    l1tap_state.state = TD_NONE;
}

void td_l2_finished(tap_dance_state_t *state, void *user_data) {
    l2tap_state.state = cur_dance(state);
    switch (l2tap_state.state) {
        case TD_SINGLE_TAP: register_code(KC_R); break;
        case TD_SINGLE_HOLD: layer_on(5); break;
        case TD_DOUBLE_TAP: register_code(KC_R); break;
        case TD_DOUBLE_HOLD: layer_on(5); break;
        case TD_DOUBLE_SINGLE_TAP: tap_code(KC_R); register_code(KC_R);  break;
        default: break;
    }
}

void td_l2_reset(tap_dance_state_t *state, void *user_data) {
    switch (l2tap_state.state) {
        case TD_SINGLE_TAP: unregister_code(KC_R); break;
        case TD_SINGLE_HOLD: layer_off(5); break;
        case TD_DOUBLE_TAP: unregister_code(KC_R); break;
        case TD_DOUBLE_HOLD: layer_off(5); break;
        case TD_DOUBLE_SINGLE_TAP: unregister_code(KC_R);  break;
        default: break;
    }
    l2tap_state.state = TD_NONE;
}

// bool process_record_user(uint16_t keycode, keyrecord_t *record) {
//     tap_dance_action_t *action;

//     switch (keycode) {
//         case TD(CT_CLN):  // list all tap dance keycodes with tap-hold configurations
//             action = &tap_dance_actions[QK_TAP_DANCE_GET_INDEX(keycode)];
//             if (!record->event.pressed && action->state.count && !action->state.finished) {
//                 tap_dance_tap_hold_t *tap_hold = (tap_dance_tap_hold_t *)action->user_data;
//                 tap_code16(tap_hold->tap);
//             }
//     }
//     return true;
// }
