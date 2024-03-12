// Copyright 2023 KirilStrezikozin
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H
#include <stdint.h>

enum layer_names {
    _BL,
    _NL,
    _SL,
};

enum custom_keycodes {
    KC_LUP = SAFE_RANGE,
    KC_LDOWN
};

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 *  You can use _______ in place for KC_TRNS (transparent)   *
 *  Or you can use XXXXXXX for KC_NO (NOOP)                  *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /*
     * ┌───┬───┬───┬───┬───┬───┐       ┌───┬───┬───┬───┬───┬───┐
     * │Esc│ Q │ W │ E │ R │ T │       │ Y │ U │ I │ O │ P │Tab│
     * ├───┼───┼───┼───┼───┼───┤       ├───┼───┼───┼───┼───┼───┤
     * │Ctl│ A │ S │ D │ F │ G │       │ H │ J │ K │ L │ ; │ - │
     * ├───┼───┼───┼───┼───┼───┤       ├───┼───┼───┼───┼───┼───┤
     * │Sht│ Z │ X │ C │ V │ B │       │ N │ M │ , │ . │ / │Sht│
     * └───┴───┴───┴───┴───┴───┘       └───┴───┴───┴───┴───┴───┘
     *               ┌───┐                   ┌───┐
     *               │Spr├───┐           ┌───┤Ent│
     *               └───┤LDw├───┐   ┌───┤LUp├───┘
     *                   └───┤Spc│   │Bks├───┘
     *                       └───┘   └───┘
     *
     * ┌───┬───┬───┬───┬───┬───┐       ┌───┬───┬───┬───┬───┬───┐
     * │   │ - │ = │ [ │ ] │ \ │       │ ~ │ ; │ ' │ ` │ < │ > │
     * ├───┼───┼───┼───┼───┼───┤       ├───┼───┼───┼───┼───┼───┤
     * │   │ 1 │ 2 │ 3 │ 4 │ 5 │       │ 6 │ 7 │ 8 │ 9 │ 0 │ ' │
     * ├───┼───┼───┼───┼───┼───┤       ├───┼───┼───┼───┼───┼───┤
     * │Sht│ ! │ @ │ # │ $ │ % │       │ ^ │ & │ * │ ( │ ) │Sht│
     * └───┴───┴───┴───┴───┴───┘       └───┴───┴───┴───┴───┴───┘
     *               ┌───┐                   ┌───┐
     *               │Spr├───┐           ┌───┤Ent│
     *               └───┤LDw├───┐   ┌───┤LUp├───┘
     *                   └───┤Spc│   │Bks├───┘
     *                       └───┘   └───┘
     */
    [_BL] = LAYOUT_split_3x6_3(
        KC_ESC,  KC_Q,    KC_W,   KC_E,    KC_R,     KC_T,          KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_TAB,
        KC_LCTL, KC_A,    KC_S,   KC_D,    KC_F,     KC_G,          KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_MINS,
        KC_LSFT, KC_Z,    KC_X,   KC_C,    KC_V,     KC_B,          KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,
                                  KC_LGUI, KC_LDOWN, KC_SPC,        KC_BSPC, KC_LUP,  KC_ENT
    ),
    [_NL] = LAYOUT_split_3x6_3(
        XXXXXXX, KC_MINS, KC_EQL, KC_LBRC, KC_RBRC,  KC_BSLS,       KC_NUHS, KC_SCLN, KC_QUOT, KC_GRV,  KC_LT,   KC_GT,
        XXXXXXX, KC_1,    KC_2,   KC_3,    KC_4,     KC_5,          KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_QUOT,
        KC_LSFT, KC_EXLM, KC_AT,  KC_HASH, KC_DLR,   KC_PERC,       KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_RSFT,
                                  KC_LGUI, KC_LDOWN, KC_SPC,        KC_BSPC, KC_LUP,  KC_ENT
    ),
    [_SL] = LAYOUT_split_3x6_3(
        KC_ESC,  KC_Q, KC_W, KC_E, KC_R, KC_T,     KC_Y, KC_U, KC_I,    KC_O,   KC_P,    KC_TAB,
        KC_LCTL, KC_A, KC_S, KC_D, KC_F, KC_G,     KC_H, KC_J, KC_K,    KC_L,   KC_SCLN, KC_UNDS,
        KC_LSFT, KC_Z, KC_X, KC_C, KC_V, KC_B,     KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, KC_NO,
                      KC_LGUI, KC_LDOWN, KC_SPC,     KC_BSPC, KC_LUP, KC_ENT
    )
};
