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
#include <stdio.h>
#include "keymap_spanish.h"

extern uint8_t is_master;

#define _COLEMAKDH 0
#define _LOWER 1
#define _RAISE 2
#define _ADJUST 3


// Left-hand home row mods
#define HOME_A LGUI_T(KC_A)
#define HOME_R LALT_T(KC_R)
#define HOME_S LCTL_T(KC_S)
#define HOME_T LSFT_T(KC_T)

// Right-hand home row mods
#define HOME_N RSFT_T(KC_N)
#define HOME_E RCTL_T(KC_E)
#define HOME_I LALT_T(KC_I)
#define HOME_O RGUI_T(KC_O)

enum custom_keycodes {
    COLEMAKDH = SAFE_RANGE,
    LOWER,
    RAISE,
    ADJUST,
    BACKLIST
};

enum combos {
    HCOMA_ESC,

    PH_BSLASH,
    DL_SLASH,
    
    PB_LBRC,
    JL_RBRC,

    PG_LPRN,
    ML_RPRN,

    DV_LCBR,
    KH_RCBR,

    GM_RCBR
};

const uint16_t PROGMEM hcoma_combo[] = {ES_H, ES_COMM, COMBO_END};

const uint16_t PROGMEM ph_combo[] = {ES_P, ES_H, COMBO_END};
const uint16_t PROGMEM dl_combo[] = {ES_D, ES_L, COMBO_END};

const uint16_t PROGMEM pb_combo[] = {ES_P, ES_B, COMBO_END};
const uint16_t PROGMEM jl_combo[] = {ES_J, ES_L, COMBO_END};

const uint16_t PROGMEM pg_combo[] = {ES_P, ES_G, COMBO_END};
const uint16_t PROGMEM ml_combo[] = {ES_M, ES_L, COMBO_END};

const uint16_t PROGMEM dv_combo[] = {ES_D, ES_V, COMBO_END};
const uint16_t PROGMEM kh_combo[] = {ES_K, ES_H, COMBO_END};

const uint16_t PROGMEM gm_combo[] = {ES_G, ES_M, COMBO_END};

combo_t key_combos[COMBO_COUNT] = {
    [HCOMA_ESC] = COMBO(hcoma_combo, KC_ESC),

    [PH_BSLASH] = COMBO(ph_combo, ES_BSLS),
    [DL_SLASH] = COMBO(dl_combo, ES_SLSH),

    [PB_LBRC] = COMBO(pb_combo, ES_LBRC),
    [JL_RBRC] = COMBO(jl_combo, ES_RBRC),

    [PG_LPRN] = COMBO(pg_combo, ES_LPRN),
    [ML_RPRN] = COMBO(ml_combo, ES_RPRN),

    [DV_LCBR] = COMBO(dv_combo, ES_LCBR),
    [KH_RCBR] = COMBO(kh_combo, ES_RCBR),

    [GM_RCBR] = COMBO(gm_combo, ES_PIPE),
};

uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch(keycode) {
        case LT(_RAISE, KC_BSPC):
            return TAPPING_TERM_BSPC;
        case LT(_LOWER, KC_TAB):
            return TAPPING_TERM_BSPC;
        default:
            return TAPPING_TERM;
    }
}

//bool get_tapping_force_hold(uint16_t keycode, keyrecord_t *record) {
  //  switch (keycode) {
    //    case LT(_RAISE,KC_BSPC):
      //      return false;
        //default:
          //  return true;
  // }
//}

// Para HOME ROW: PERMISSIVE HOLD PER KEY (only for 'F', 'J' and shift keys)
/* It allows to register a shifted key even if all the operation
   has been produced within the tapping_term */
bool get_permissive_hold(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case HOME_A:
            // Immediately select the hold action when another key is tapped.
            return true;
 
        case HOME_R:
            // Immediately select the hold action when another key is tapped.
            return true;
 
        case HOME_S:
            // Immediately select the hold action when another key is tapped.
            return true;
 
        case HOME_T:
            // Immediately select the hold action when another key is tapped.
            return true;
 
        case HOME_N:
            // Immediately select the hold action when another key is tapped.
            return true;
 
        case HOME_E:
            // Immediately select the hold action when another key is tapped.
            return true;
 
        case HOME_I:
            // Immediately select the hold action when another key is tapped.
            return true;
 
        case HOME_O:
            // Immediately select the hold action when another key is tapped.
            return true;
 
        case KC_LSFT:
            // Immediately select the hold action when another key is tapped.
            return true;
 
        case KC_RSFT:
            // Immediately select the hold action when another key is tapped.
            return true;
 
        default:
            // Do not select the hold action when another key is tapped.
            return false;
    }
}
 
 
 
// HOLD ON OTHER KEY PRESS:
/* If you press a dual-role key, press another key, and then release the dual-role key,
   (all within the tapping term), by default the dual-role key will perform its tap action.
   However, if HOLD_ON_OTHER_KEY_PRESS is enabled, the dual-role key will perform its hold
   action instead */
bool get_hold_on_other_key_press(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        // case LSFT_SFEN:
            // Immediately select the hold action when another key is pressed.
           // return true;
 
        /*case MO(1):
            // Immediately select the hold action when another key is pressed.
            return true; */
 
        default:
            // Do not select the hold action when another key is pressed.
            return false;
    }
}

void matrix_init_user(void) {                 
  set_unicode_input_mode(UC_WINC);
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_COLEMAKDH] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
       KC_TAB,    ES_Q,    ES_W,    ES_F,    ES_P,    ES_B,                         ES_J,    ES_L,    ES_U,    ES_Y, ES_NTIL, ES_QUOT, 
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
 OSM(MOD_LCTL),   HOME_A, HOME_R, HOME_S, HOME_T,    ES_G,                         ES_M,    HOME_N,  HOME_E,  HOME_I, HOME_O, ES_ACUT, 
 // OSM(MOD_LCTL),   ES_A, ES_R, ES_S, ES_T,    ES_G,                         ES_M,    ES_N,  ES_E,  ES_I, ES_O, ES_ACUT, 
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
 OSM(MOD_LSFT),   ES_Z,    ES_X,    ES_C,    ES_D,    ES_V,                         ES_K,    ES_H, ES_COMM,  ES_DOT, ES_MINS, KC_RBRC, 
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
        OSM(MOD_LALT),   GUI_T(KC_ENT),  LT(_LOWER, KC_TAB),                   LT(_RAISE,KC_BSPC),  KC_SPC, OSM(MOD_RALT) 
                                      //`--------------------------'  `--------------------------'
  ),

  [_LOWER] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      ES_MORD, ES_EXLM, ES_DQUO, ES_BULT,  ES_DLR, ES_PERC,                      ES_AMPR, ES_SLSH, ES_LPRN, ES_RPRN,  ES_EQL, ES_QUES,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______,    ES_1,    ES_2,    ES_3,    ES_4,    ES_5,                         ES_6,    ES_7,    ES_8,    ES_9,    ES_0, ES_IQUE,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_CAPS, ES_IEXL, ES_LABK, ES_RABK, ES_LBRC, ES_RBRC,                      ES_LCBR, ES_RCBR, ES_BSLS, ES_PIPE, ES_CIRC, ES_GRV,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          _______, _______,  LOWER,     ADJUST, _______, _______
                                      //`--------------------------'  `--------------------------'
  ),

  [_RAISE] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      KC_ESC ,   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                        KC_F6,   KC_F7,   KC_F8,   KC_F9,  KC_F10,  KC_DEL,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______,LCTL(KC_Y),LCA(KC_LEFT),LCA(KC_RIGHT),LALT(KC_LEFT),LALT(KC_RIGHT), KC_LEFT, KC_DOWN,   KC_UP,KC_RIGHT,  KC_APP,  KC_F11,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______,LCTL(KC_Z),LCTL(KC_X),LCTL(KC_C),KC_INS,LCTL(KC_V),                KC_HOME, KC_PGDN, KC_PGUP, KC_END,  KC_PSCR,  KC_F12,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          _______, _______,  ADJUST,     RAISE, _______, _______
                                      //`--------------------------'  `--------------------------'
  ),

  [_ADJUST] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      RGB_TOG, RGB_HUI, RGB_SAI, RGB_VAI, KC_VOLU, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX, XXXXXXX,   ES_AT, ES_HASH, ES_TILD, XXXXXXX,                       ES_NOT, RCS(KC_Z), XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      RGB_MOD, RGB_HUD, RGB_SAD, RGB_VAD, KC_VOLD, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          XXXXXXX, XXXXXXX,  ADJUST,     ADJUST, XXXXXXX, XXXXXXX
                                      //`--------------------------'  `--------------------------'
  )
  
};

void persistent_default_layer_set(uint16_t default_layer) {
  eeconfig_update_default_layer(default_layer);
  default_layer_set(default_layer);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case COLEMAKDH:
      if (record->event.pressed) {
        persistent_default_layer_set(1UL<<_COLEMAKDH);
      }
      return false;
    case LOWER:
      if (record->event.pressed) {
        layer_on(_LOWER);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      } else {
        layer_off(_LOWER);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      }
      return false;
    case RAISE:
      if (record->event.pressed) {
        layer_on(_RAISE);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      } else {
        layer_off(_RAISE);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      }
      return false;
    case ADJUST:
        if (record->event.pressed) {
          layer_on(_ADJUST);
        } else {
          layer_off(_ADJUST);
        }
        return false;
    default:
      return true;
  }
  return true;
}

#ifdef OLED_ENABLE
oled_rotation_t oled_init_user(oled_rotation_t rotation) {
  if (!is_keyboard_master()) {
    return OLED_ROTATION_180;  // flips the display 180 degrees if offhand
  }
  return rotation;
}

#define L_BASE 0
#define L_LOWER 2
#define L_RAISE 4
#define L_ADJUST 8

void oled_render_layer_state(void) {
    oled_write_P(PSTR("Layer: "), false);
    switch (layer_state) {
        case L_BASE:
            oled_write_ln_P(PSTR("ColemakDH"), false);
            break;
        case L_LOWER:
            oled_write_ln_P(PSTR("Lower"), false);
            break;
        case L_RAISE:
            oled_write_ln_P(PSTR("Raise"), false);
            break;
        case L_ADJUST:
        case L_ADJUST|L_LOWER:
        case L_ADJUST|L_RAISE:
        case L_ADJUST|L_LOWER|L_RAISE:
            oled_write_ln_P(PSTR("Adjust"), false);
            break;
    }
}


//void oled_render_logo(void) {
//    static const char PROGMEM crkbd_logo[] = {
//        0x80, 0x81, 0x82, 0x83, 0x84, 0x85, 0x86, 0x87, 0x88, 0x89, 0x8a, 0x8b, 0x8c, 0x8d, 0x8e, 0x8f, 0x90, 0x91, 0x92, 0x93, 0x94,
//        0xa0, 0xa1, 0xa2, 0xa3, 0xa4, 0xa5, 0xa6, 0xa7, 0xa8, 0xa9, 0xaa, 0xab, 0xac, 0xad, 0xae, 0xaf, 0xb0, 0xb1, 0xb2, 0xb3, 0xb4,
//        0xc0, 0xc1, 0xc2, 0xc3, 0xc4, 0xc5, 0xc6, 0xc7, 0xc8, 0xc9, 0xca, 0xcb, 0xcc, 0xcd, 0xce, 0xcf, 0xd0, 0xd1, 0xd2, 0xd3, 0xd4,
//        0};
//    oled_write_P(crkbd_logo, false);
//}

void oled_show_locks(void) {
  led_t led_state = host_keyboard_led_state();
    oled_write_P(led_state.num_lock ? PSTR("NUM ") : PSTR("    "), false);
    oled_write_P(led_state.caps_lock ? PSTR("CAP ") : PSTR("    "), false);
    oled_write_P(led_state.scroll_lock ? PSTR("SCR ") : PSTR("    "), false);
}

bool oled_task_user(void) {
    if (is_keyboard_master()) {
        oled_render_layer_state();
        oled_show_locks();
        // render_status();
    } else {
       // oled_render_logo();
       // oled_scroll_left();
    }
    return false;
}

// bool process_record_user(uint16_t keycode, keyrecord_t *record) {
//  if (record->event.pressed) {
//    set_keylog(keycode, record);
//  }
//  return true;
// }
#endif // OLED_ENABLE
