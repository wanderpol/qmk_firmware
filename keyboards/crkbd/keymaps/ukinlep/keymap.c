#include QMK_KEYBOARD_H

enum combos {
  SNT_ENTER,
  SDF_ENTER,
  BH_W,
  FL_X,
  LD_P,
  HG_Q,
  CS_Z,
  NM_12_0,
  NM_23_DOT,
  NM_45_MINUS,
  NM_56_PLUS,
  NM_78_DIVIDE,
  NM_89_MULTIPLY,
  KVM_SWITCH_1,
  KVM_SWITCH_2,
  KVM_SWITCH_3,
  KVM_SWITCH_4,
  PSWD
};

bool is_mac = false;  // 기본은 Windows


// OS 단축키 정의
// #define COPY  (is_mac ? LGUI(KC_C) : LCTL(KC_C))
// #define PASTE (is_mac ? LGUI(KC_V) : LCTL(KC_V))
// #define CUT   (is_mac ? LGUI(KC_X) : LCTL(KC_X))
// #define ALL   (is_mac ? LGUI(KC_A) : LCTL(KC_A))
// #define CLSWN    (is_mac ? LGUI(KC_Q) : LCTL(KC_Q))
// #define NEWTAB   (is_mac ? LGUI(KC_T) : LCTL(KC_T))
// #define NEWWIN   (is_mac ? LGUI(KC_N) : LCTL(KC_N))
// #define SWITCHWIN   (is_mac ? LGUI(KC_TAB) : LALT(KC_TAB))
// #define CLOSETAB   (is_mac ? LGUI(KC_W) : LCTL(KC_W))
// #define SAVE   (is_mac ? LGUI(KC_S) : LCTL(KC_S))
// #define UNDO   (is_mac ? LGUI(KC_Z) : LCTL(KC_Z))

#define HR_C_LG LGUI_T(KC_C)
#define HR_C_LA LALT_T(KC_S)
#define HR_C_LC LCTL_T(KC_N)
#define HR_C_LS LSFT_T(KC_T)
#define HR_C_RS LSFT_T(KC_A)
#define HR_C_RC LCTL_T(KC_E)
#define HR_C_RA LALT_T(KC_I)
#define HR_C_RG LGUI_T(KC_M)

#define HR_Q_LG LGUI_T(KC_A)
#define HR_Q_LA LALT_T(KC_S)
#define HR_Q_LC LCTL_T(KC_D)
#define HR_Q_LS LSFT_T(KC_F)
#define HR_Q_RS LSFT_T(KC_J)
#define HR_Q_RC LCTL_T(KC_K)
#define HR_Q_RA LALT_T(KC_L)
#define HR_Q_RG LGUI_T(KC_SCLN)

// const uint16_t PROGMEM snt_combo[] = {LALT_T(KC_S), LCTL_T(KC_N), LSFT_T(KC_T), COMBO_END};
// const uint16_t PROGMEM sdf_combo[] = {LALT_T(KC_S), LCTL_T(KC_D), LSFT_T(KC_F), COMBO_END};
const uint16_t PROGMEM snt_combo[] = {HR_C_LA, HR_C_LC, HR_C_LS, COMBO_END};
const uint16_t PROGMEM sdf_combo[] = {HR_Q_LA, HR_Q_LC, HR_Q_LS, COMBO_END};
const uint16_t PROGMEM bh_combo[] = {KC_B, KC_H, COMBO_END};
const uint16_t PROGMEM fl_combo[] = {KC_F, KC_L, COMBO_END};
const uint16_t PROGMEM ld_combo[] = {KC_L, KC_D, COMBO_END};
const uint16_t PROGMEM hg_combo[] = {KC_H, KC_G, COMBO_END};
const uint16_t PROGMEM cs_combo[] = {HR_C_LG, HR_C_LA, COMBO_END};
const uint16_t PROGMEM nm_12_combo[] = {KC_1, KC_2, COMBO_END};
const uint16_t PROGMEM nm_23_combo[] = {KC_2, KC_3, COMBO_END};
const uint16_t PROGMEM nm_45_combo[] = {KC_4, KC_5, COMBO_END};
const uint16_t PROGMEM nm_56_combo[] = {KC_5, KC_6, COMBO_END};
const uint16_t PROGMEM nm_78_combo[] = {KC_7, KC_8, COMBO_END};
const uint16_t PROGMEM nm_89_combo[] = {KC_8, KC_9, COMBO_END};
const uint16_t PROGMEM kvm_switch_1[] = {KC_SCRL, KC_F, COMBO_END};
const uint16_t PROGMEM kvm_switch_2[] = {KC_SCRL, KC_L, COMBO_END};
const uint16_t PROGMEM kvm_switch_3[] = {KC_SCRL, KC_D, COMBO_END};
const uint16_t PROGMEM kvm_switch_4[] = {KC_SCRL, KC_S, COMBO_END};
const uint16_t PROGMEM pswd[] = {KC_SCRL, QK_GESC, COMBO_END};

combo_t key_combos[] = {
  [SNT_ENTER] = COMBO(snt_combo, KC_ENTER),
  [SDF_ENTER] = COMBO(sdf_combo, KC_ENTER),
  [BH_W] = COMBO(bh_combo, KC_W),
  [FL_X] = COMBO(fl_combo, KC_X),
  [LD_P] = COMBO(ld_combo, KC_P),
  [HG_Q] = COMBO(hg_combo, KC_Q),
  [CS_Z] = COMBO(cs_combo, KC_Z),
  [NM_12_0] = COMBO(nm_12_combo, KC_0),
  [NM_23_DOT] = COMBO(nm_23_combo, KC_DOT),
  [NM_45_MINUS] = COMBO(nm_45_combo, KC_MINUS),
  [NM_56_PLUS] = COMBO(nm_56_combo, LSFT(KC_EQUAL)),
  [NM_78_DIVIDE] = COMBO(nm_78_combo, KC_SLSH),
  [NM_89_MULTIPLY] = COMBO(nm_89_combo,LSFT(KC_8)),
  [KVM_SWITCH_1] = COMBO(kvm_switch_1, KC_NO),
  [KVM_SWITCH_2] = COMBO(kvm_switch_2, KC_NO),
  [KVM_SWITCH_3] = COMBO(kvm_switch_3, KC_NO),
  [KVM_SWITCH_4] = COMBO(kvm_switch_4, KC_NO),
  [KVM_SWITCH_4] = COMBO(kvm_switch_4, KC_NO),
  [PSWD] = COMBO(pswd, KC_NO)
};

enum custom_keycodes {
    OS_TOGGLE = SAFE_RANGE,
    COPY,
    PASTE,
    CUT,
    ALL,
    CLSWN,
    NEWTAB,
    NEWWIN,
    SWITCHWIN,
    CLOSETAB,
    SAVE,
    UNDO,
    REPLACE,
    FIND,
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

// Create a global instance of the tapdance state type
// static td_state_t td_state_sss;


// Tap dance enums
enum {
    TD_R1,
};

td_state_t cur_dance(tap_dance_state_t *state);

// For the x tap dance. Put it here so it can be used in any keymap
void td_r1_finished(tap_dance_state_t *state, void *user_data);
void td_r1_reset(tap_dance_state_t *state, void *user_data);


//Tap Dance Definitions
tap_dance_action_t tap_dance_actions[] = {
  //Tap once for Esc, twice for Caps Lock
  [TD_R1] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, td_r1_finished, td_r1_reset),
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
    OS_TOGGLE, KC_QUOT,    KC_B,    KC_H,    KC_G,LSFT(KC_QUOT),                KC_SLSH, KC_COMM,  KC_DOT,    KC_J,    KC_X, KC_SCRL,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LGUI, HR_C_LG, HR_C_LA, HR_C_LC, HR_C_LS,LT(5, KC_K),            LT(4, KC_SCLN), HR_C_RS, HR_C_RC, HR_C_RA, HR_C_RG,   DF(1),
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LCTL,  KC_EQL,    KC_F,    KC_L,    KC_D,    KC_V,                     KC_MINS,    KC_U,    KC_O,    KC_Y,    KC_W, KC_RALT,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                 QK_GESC, LT(2,KC_R), LT(3, KC_TAB),  TD(TD_R1), LT(5, KC_SPC),KC_BSPC
                                      //`--------------------------'  `--------------------------'
  ),
  
     [1] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      KC_TRNS,    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                         KC_Y,    KC_U,    KC_I,    KC_O,   KC_P,  KC_TRNS,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_TRNS, HR_Q_LG, HR_Q_LA, HR_Q_LC, HR_Q_LS,LT(5, KC_G),               LT(4, KC_H), HR_Q_RS, HR_Q_RC, HR_Q_RA, HR_Q_RG,   DF(0),
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_TRNS,    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                         KC_N,    KC_M, KC_COMM,  KC_DOT, KC_SLSH, KC_TRNS,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_TRNS, KC_TRNS, KC_TRNS,    KC_TRNS, KC_TRNS, KC_TRNS
                                      //`--------------------------'  `--------------------------'
  ),

     [2] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.                          
      KC_TRNS, KC_LBRC,    KC_7,    KC_8,    KC_9, KC_RBRC,                    KC_NO,LSFT(KC_7), LSFT(KC_8), LSFT(KC_9), KC_NO, KC_NO,                   
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|                          
      KC_TRNS,LSFT(KC_LBRC),KC_4,   KC_5,    KC_6,LSFT(KC_RBRC),          KC_GRV,LSFT(KC_4), LSFT(KC_5), LSFT(KC_6), KC_BSLS,   KC_NO,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|                          
      KC_TRNS,LSFT(KC_9),  KC_1,    KC_2,    KC_3,LSFT(KC_0),          LSFT(KC_GRV), LSFT(KC_1), LSFT(KC_2), LSFT(KC_3),LSFT(KC_BSLS), KC_NO,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                            KC_NO,   KC_NO,   KC_NO,      KC_NO,   KC_NO,   KC_NO 
                                      //`--------------------------'  `--------------------------'
  ),

    [3] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.         
      KC_TRNS,   CLSWN,CLOSETAB,LGUI(KC_E),REPLACE, NEWTAB,                      KC_CAPS,  KC_DEL,  KC_INS, KC_PSCR, KC_PAUS,   KC_NO,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_TRNS,     ALL,    SAVE,LGUI(KC_D),  FIND, LGUI(KC_G),                   KC_PGUP, KC_LEFT, KC_DOWN,   KC_UP,KC_RIGHT,   KC_NO,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_TRNS,    UNDO,     CUT,    COPY,   PASTE, LGUI(KC_B),                   KC_PGDN,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                            KC_NO,   KC_NO,   KC_NO,    KC_HOME, KC_END,    KC_NO
                                      //`--------------------------'  `--------------------------'
  ),

     [4] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
        KC_NO,   KC_NO,   KC_F7,   KC_F8,   KC_F9,  KC_F12,                        KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
        KC_NO,   KC_NO,   KC_F4,   KC_F5,   KC_F6,  KC_F11,                        KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
        KC_NO,   KC_NO,   KC_F1,   KC_F2,   KC_F3,  KC_F10,                        KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                            KC_NO,   KC_NO,   KC_NO,      KC_NO,   KC_NO,   KC_NO
                                      //`--------------------------'  `--------------------------'
  ),

   [5] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      KC_TRNS,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,                        KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_TRNS,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,                        KC_NO, MS_LEFT, MS_DOWN,   MS_UP, MS_RGHT,   KC_NO,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_TRNS,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,                        KC_NO, MS_WHLL, MS_WHLD, MS_WHLU, MS_WHLR,   KC_NO,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                            KC_NO,   KC_NO,   KC_NO,    MS_BTN1, MS_BTN2,   KC_NO
                                      //`--------------------------'  `--------------------------'
  )
};


void process_combo_event(uint16_t combo_index, bool pressed) {
  switch(combo_index) {
    case KVM_SWITCH_1:
      if (pressed) {
        tap_code16(KC_SCRL);
        tap_code16(KC_SCRL);
        tap_code16(KC_1);
      }
      break;
    case KVM_SWITCH_2:
      if (pressed) {
        tap_code16(KC_SCRL);
        tap_code16(KC_SCRL);
        tap_code16(KC_2);
      }
      break;
    case KVM_SWITCH_3:
      if (pressed) {
        tap_code16(KC_SCRL);
        tap_code16(KC_SCRL);
        tap_code16(KC_3);
      }
      break;
    case KVM_SWITCH_4:
      if (pressed) {
        tap_code16(KC_SCRL);
        tap_code16(KC_SCRL);
        tap_code16(KC_4);
      }
      break;
    case PSWD:
      if (pressed) {
        SEND_STRING("");
      }
      break;
  }
}

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
        case TD_SINGLE_HOLD: layer_on(4); break;
        //case TD_DOUBLE_TAP: register_code(KC_CAPS); break;
        //case TD_DOUBLE_HOLD: layer_on(3); break;
        // case TD_DOUBLE_SINGLE_TAP: break;
        default: break;
    }
}

void td_r1_reset(tap_dance_state_t *state, void *user_data) {
    switch (r1tap_state.state) {
        // case TD_SINGLE_TAP: clear_oneshot_mods(); break;
        case TD_SINGLE_HOLD: layer_off(4); break;
        //case TD_DOUBLE_TAP: unregister_code(KC_CAPS); break;
        //case TD_DOUBLE_HOLD: layer_off(3); break;
        // case TD_DOUBLE_SINGLE_TAP: break;
        default: break;
    }
    r1tap_state.state = TD_NONE;
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (record->event.pressed) {
        switch(keycode) {
            case COPY:
                tap_code16(is_mac ? LGUI(KC_C) : LCTL(KC_C)); //
                return false;
            case PASTE:
                tap_code16(is_mac ? LGUI(KC_V) : LCTL(KC_V));
                return false;
            case CUT:
                tap_code16(is_mac ? LGUI(KC_X) : LCTL(KC_X));
                return false;
            case ALL:
                tap_code16(is_mac ? LGUI(KC_A) : LCTL(KC_A));
                return false;
            case CLSWN:
                tap_code16(is_mac ? LGUI(KC_Q) : LCTL(KC_Q));
                return false;
            case NEWTAB:
                tap_code16(is_mac ? LGUI(KC_T) : LCTL(KC_T));
                return false;
            case NEWWIN:
                tap_code16(is_mac ? LGUI(KC_N) : LCTL(KC_N));
                return false;
            case SWITCHWIN:
                tap_code16(is_mac ? LGUI(KC_TAB) : LALT(KC_TAB));
                return false;
            case CLOSETAB:
                tap_code16(is_mac ? LGUI(KC_W) : LCTL(KC_W));
                return false;
            case SAVE:
                tap_code16(is_mac ? LGUI(KC_S) : LCTL(KC_S));
                return false;
            case UNDO:
                tap_code16(is_mac ? LGUI(KC_Z) : LCTL(KC_Z));
                return false;
            case FIND:
                tap_code16(is_mac ? LGUI(KC_F) : LCTL(KC_F));
                return false;
            case REPLACE:
                tap_code16(is_mac ? LGUI(KC_R) : LCTL(KC_R));
                return false;
            case OS_TOGGLE:
                is_mac = !is_mac;
                return false;
        }
    }
    return true;
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
