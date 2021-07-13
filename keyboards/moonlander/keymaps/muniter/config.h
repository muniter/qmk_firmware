/*
  Set any config.h overrides for your specific keymap here.
  See config.h options at https://docs.qmk.fm/#/config_options?id=the-configh-file
*/
//#define WAIT_FOR_USB
#define ORYX_CONFIGURATOR

#define ONESHOT_TAP_TOGGLE 3

#undef ONESHOT_TIMEOUT
#define ONESHOT_TIMEOUT 1900

// Mod tap configuration (For fast typist)
// Typing term
#define TAPPING_TERM 180
// Avoids triggering the mod when not needed
#define IGNORE_MOD_TAP_INTERRUPT
// Triggers the mod when It should
#define PERMISSIVE_HOLD
// Do not repeat a ModTap key when held after a press
#define TAPPING_FORCE_HOLD_PER_KEY

// Disable RGB after 10 minutes without keypresses time in ms
#define RGB_DISABLE_TIMEOUT 600000
// Default mode for rgb effects
#define RGB_MATRIX_STARTUP_MODE RGB_MATRIX_TYPING_HEATMAP

#define LEADER_TIMEOUT 300
#define LEADER_PER_KEY_TIMING
// Leader sends exact keycodes
#define LEADER_KEY_STRICT_KEY_PROCESSING

// Combos
/* #define COMBO_COUNT 1 */
// The idea is to chord thigns fast.
/* #define COMBO_TERM 50 */
