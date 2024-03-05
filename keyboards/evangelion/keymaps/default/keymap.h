// Copyright 2023 QMK
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H
#include <stdbool.h>
#include <stdint.h>

// Helpful defines
#define GRAVE_MODS (MOD_BIT(KC_LSFT) | MOD_BIT(KC_RSFT) | MOD_BIT(KC_LGUI) | MOD_BIT(KC_RGUI) | MOD_BIT(KC_LALT) | MOD_BIT(KC_RALT))

#define LAYER_CYCLE_START 0
#define LAYER_CYCLE_END 2

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 *  You can use _______ in place for KC_TRNS (transparent)   *
 *  Or you can use XXXXXXX for KC_NO (NOOP)                  *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

// Each layer gets a name for readability.
// The underscores don't mean anything - you can
// have a layer called STUFF or any other name.
// Layer names don't all need to be of the same
// length, and you can also skip them entirely
// and just use numbers.
enum layer_names {
    _BL,
    _NL,
    _SL,
};

enum custom_keycodes {
    KC_LUP = SAFE_RANGE,
    KC_LDOWN
};

void set_higher_layer_user(void);

void set_lower_layer_user(void);
