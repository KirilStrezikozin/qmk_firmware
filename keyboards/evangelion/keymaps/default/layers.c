// Copyright 2023 KirilStrezikozin
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H
#include "layers.h"

#include <stdbool.h>
#include <stdint.h>

#define LAYER_CYCLE_START 0
#define LAYER_CYCLE_END 2

bool layer_move_down() {
    uint8_t current_layer = get_highest_layer(layer_state);

    if (current_layer >= LAYER_CYCLE_END) {
        return false;
    }

    uint8_t lower_layer = current_layer + 1;
    layer_move(lower_layer);
    return true;
}

bool layer_move_up() {
    uint8_t current_layer = get_highest_layer(layer_state);

    if (current_layer <= LAYER_CYCLE_START) {
        return false;
    }

    uint8_t higher_layer = current_layer - 1;
    layer_move(higher_layer);
    return true;
}
