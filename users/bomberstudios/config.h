#pragma once

#include "layout.h"

// Tapping terms
#undef TAPPING_TERM
#define TAPPING_TERM 150
// Turns out I'm not using this anymore
// #define TAPPING_TERM_PER_KEY

// Permissive Hold and Hold On Other Key Press are mutually exclusive, so we can't have both. See https://docs.qmk.fm/tap_hold#permissive-hold
// Triggers mod if you tap another key while holding.
// #define PERMISSIVE_HOLD
// Hold On Other Key Press triggers mods a bit too aggressively. Trying to type "entity" moderately quick
// gives me "eTiY". I don't think I prefer this behavior. But let's try it combined with Flow Tap and see if that helps. If not, I'll try Permissive Hold instead.
#define HOLD_ON_OTHER_KEY_PRESS

// Chordal Hold. See https://docs.qmk.fm/tap_hold#chordal-hold
// Constrains holds to opposite-hand combinations (with exceptions for combos)
#define CHORDAL_HOLD

// Retro Tapping. See https://docs.qmk.fm/tap_hold#retro-tapping
// Holding and releasing a dual-function key without pressing another key will result in nothing happening. With retro tapping enabled, releasing the key without pressing another will send the original keycode even if it is outside the tapping term.
// #define RETRO_TAPPING // wish there was a retro tapping per key, because I'd like to have this only for some keys.
// Update in september 2026: there's a retro tapping per key now: https://docs.qmk.fm/tap_hold#retro-tapping

// Flow Tap. See https://docs.qmk.fm/tap_hold#flow-tap
// Disables holds when typing quickly
// I think this is making my problem with home row mods worse, because I type fast. So I'm going to try disabling it for now.
#define FLOW_TAP_TERM 150

// Speculative Hold. See https://docs.qmk.fm/tap_hold#speculative-hold
// I hope this makes it easier to use Ctrl + Trackpad gestures to zoom in/out on macOS
// Sept 2026: seems to be working pretty well
#define SPECULATIVE_HOLD

// #define UNICODE_SELECTED_MODES UC_MAC

// Only for splits, this assumes we'll flash the halves using
// :avrdude-split-left
#ifdef SPLIT_KEYBOARD
#    define EE_HANDS
#endif

#undef NO_DEBUG
#define NO_DEBUG
#undef NO_PRINT
#define NO_PRINT

// #ifdef TAP_DANCE_ENABLE
// #include "tap_dances.h"
// #endif

#define COMBO_COUNT 29
// There's a way to make this dynamic, see
// https://github.com/whydobearsxplod/qmk_user_folder for more info

#ifdef QAZ
#    define COMBO_TERM 100
// TODO: actually, what I want to do is define an entirely different set of
// combos for the qaz, because the ones that use the home row don't really make
// sense for row-staggered keyboards. But while I get there, this will do...
#endif

#define ENABLE_COMPILE_KEYCODE
