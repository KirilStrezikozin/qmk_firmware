// Copyright 2023 KirilStrezikozin
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H
#include "layers.h"

#include <stdbool.h>
#include <stdint.h>

#define LAYER_CYCLE_START 0
#define LAYER_CYCLE_END 2

#ifndef LAYERS_RECYCLE
#    define LAYERS_RECYCLE false
#endif

bool layer_move_down() {
    uint8_t current_layer = get_highest_layer(layer_state);

    if (current_layer >= LAYER_CYCLE_END) {
        if (!LAYERS_RECYCLE) {
            return false;
        }
        layer_move(LAYER_CYCLE_START);
    } else {
        layer_move(current_layer + 1);
    }
    return true;
}

bool layer_move_up() {
    uint8_t current_layer = get_highest_layer(layer_state);

    if (current_layer <= LAYER_CYCLE_START) {
        if (!LAYERS_RECYCLE) {
            return false;
        }
        layer_move(LAYER_CYCLE_END);
    } else {
        layer_move(current_layer - 1);
    }
    return true;
}
