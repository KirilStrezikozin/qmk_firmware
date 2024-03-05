// Copyright 2023 QMK
// SPDX-License-Identifier: GPL-2.0-or-later

#include "keymap.h"


void set_higher_layer_user(void) {
  uint8_t current_layer = get_highest_layer(layer_state);
  if (current_layer > LAYER_CYCLE_END || current_layer < LAYER_CYCLE_START) {
      return;
  }

  uint8_t higher_layer = current_layer - 1;
  if (higher_layer < LAYER_CYCLE_START) {
    higher_layer = LAYER_CYCLE_START;
  }

  layer_move(higher_layer);
}

void set_lower_layer_user(void) {
  uint8_t current_layer = get_highest_layer(layer_state);
  if (current_layer > LAYER_CYCLE_END || current_layer < LAYER_CYCLE_START) {
      return;
  }

  uint8_t lower_layer = current_layer + 1;
  if (lower_layer > LAYER_CYCLE_END) {
    lower_layer = LAYER_CYCLE_END;
  }

  layer_move(lower_layer);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case KC_LUP:
      if (!record->event.pressed) {
        return false;
      }

      set_higher_layer_user();
      break;

    case KC_LDOWN:
      if (!record->event.pressed) {
        return false;
      }

      set_lower_layer_user();
      break;
  }

  return true;
}

void caps_word_set_user(bool active) {
    if (active) {
        // Do something when Caps Word activates.
    } else {
        // Do something when Caps Word deactivates.
    }
}

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /*
     * ┌───┬───┬───┬───┬───┬───┐       ┌───┬───┬───┬───┬───┬───┐
     * │Esc│ Q │ W │ E │ R │ T │       │ Y │ U │ I │ O │ P │Tab│
     * ├───┼───┼───┼───┼───┼───┤       ├───┼───┼───┼───┼───┼───┤
     * │Ctl│ A │ S │ D │ F │ G │       │ H │ J │ K │ L │ ; │ _ │
     * ├───┼───┼───┼───┼───┼───┤       ├───┼───┼───┼───┼───┼───┤
     * │   │ Z │ X │ C │ V │ B │       │ N │ M │ , │ . │ / │   │
     * └───┴───┴───┴───┴───┴───┘       └───┴───┴───┴───┴───┴───┘
     *               ┌───┐                   ┌───┐
     *               │Spr├───┐           ┌───┤Sht│
     *               └───┤LUp├───┐   ┌───┤LDw├───┘
     *                   └───┤Spc│   │Bks├───┘
     *                       └───┘   └───┘
     */
    [_BL] = LAYOUT_split_3x6_3(
        KC_ESC,  KC_Q, KC_W, KC_E, KC_R, KC_T,     KC_Y, KC_U, KC_I,    KC_O,   KC_P,    KC_TAB,
        KC_LCTL, KC_A, KC_S, KC_D, KC_F, KC_G,     KC_H, KC_J, KC_K,    KC_L,   KC_SCLN, KC_UNDS,
        KC_LSFT, KC_Z, KC_X, KC_C, KC_V, KC_B,     KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, KC_NO,
                      KC_LGUI, KC_LUP, KC_SPC,     KC_BSPC, KC_LDOWN, KC_ENT
    ),
    [_NL] = LAYOUT_split_3x6_3(
        KC_ESC,  KC_Q, KC_W, KC_E, KC_R, KC_T,     KC_Y, KC_U, KC_I,    KC_O,   KC_P,    KC_TAB,
        KC_LCTL, KC_A, KC_S, KC_D, KC_F, KC_G,     KC_H, KC_J, KC_K,    KC_L,   KC_SCLN, KC_UNDS,
        KC_LSFT, KC_Z, KC_X, KC_C, KC_V, KC_B,     KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, KC_NO,
                      KC_LGUI, KC_LUP, KC_SPC,     KC_BSPC, KC_LDOWN, KC_ENT
    ),
    [_SL] = LAYOUT_split_3x6_3(
        KC_ESC,  KC_Q, KC_W, KC_E, KC_R, KC_T,     KC_Y, KC_U, KC_I,    KC_O,   KC_P,    KC_TAB,
        KC_LCTL, KC_A, KC_S, KC_D, KC_F, KC_G,     KC_H, KC_J, KC_K,    KC_L,   KC_SCLN, KC_UNDS,
        KC_LSFT, KC_Z, KC_X, KC_C, KC_V, KC_B,     KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, KC_NO,
                      KC_LGUI, KC_LUP, KC_SPC,     KC_BSPC, KC_LDOWN, KC_ENT
    )
};
