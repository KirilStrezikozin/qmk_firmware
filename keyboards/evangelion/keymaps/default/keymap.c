// Copyright 2023 KirilStrezikozin
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

#include "layout.c"
#include "layers.c"

#include <stdbool.h>
#include <stdint.h>

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    static uint16_t KC_LUP_timer;
    static uint16_t KC_LDOWN_timer;
    static uint16_t KC_ALT_ENT_timer;

    static bool layer_down_pressed = false;
    static bool layer_up_pressed   = false;

    switch (keycode) {
        case KC_LUP:
            if (record->event.pressed) {
                // key is held, pressed
                KC_LUP_timer     = timer_read();
                layer_up_pressed = layer_move_up();
            } else {
                if (timer_elapsed(KC_LUP_timer) < TAPPING_TERM) {
                    // key is tapped, released
                } else {
                    // key is held, released
                    if (layer_up_pressed) {
                        (void)layer_move_down();
                    }
                }
                layer_up_pressed = false;
            }

            return false;

        case KC_LDOWN:
            if (record->event.pressed) {
                // key is held, pressed
                KC_LDOWN_timer     = timer_read();
                layer_down_pressed = layer_move_down();
            } else {
                if (timer_elapsed(KC_LDOWN_timer) < TAPPING_TERM) {
                    // key is tapped, released
                } else {
                    // key is held, released
                    if (layer_down_pressed) {
                        (void)layer_move_up();
                    }
                }
                layer_down_pressed = false;
            }

            return false;

        case KC_ALT_ENT:
            if (record->event.pressed) {
                // key is held, pressed
                KC_ALT_ENT_timer = timer_read();
                register_code(KC_LALT);
            } else {
                // key is held, released
                unregister_code(KC_LALT);
                if (timer_elapsed(KC_ALT_ENT_timer) < TAPPING_TERM) {
                    // key is tapped, released
                    register_code(KC_ENT);
                    unregister_code(KC_ENT);
                }
            }

            return false;
    }

    return true;
}
