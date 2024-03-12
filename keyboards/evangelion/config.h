// Copyright 2024 KirilStrezikozin (@KirilStrezikozin)
// SPDX-License-Identifier: GPL-2.0-or-later
//
// Envangelion Corne

#pragma once

/*
 * Feature disable options
 *  These options are also useful to firmware size reduction.
 */

/* disable debug print */
//#define NO_DEBUG

/* disable print */
//#define NO_PRINT

/* disable action features */
//#define NO_ACTION_LAYER
//#define NO_ACTION_TAPPING
//#define NO_ACTION_ONESHOT

#define SPLIT_USB_DETECT

#define BOTH_SHIFTS_TURNS_ON_CAPS_WORD
#define CAPS_WORD_INVERT_ON_SHIFT
#define CAPS_WORD_IDLE_TIMEOUT 3000

#define TAPPING_TERM 200

#define LAYERS_RECYCLE true
