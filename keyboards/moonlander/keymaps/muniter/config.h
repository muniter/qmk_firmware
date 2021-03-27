/*
  Set any config.h overrides for your specific keymap here.
  See config.h options at https://docs.qmk.fm/#/config_options?id=the-configh-file
*/
#define ORYX_CONFIGURATOR
#undef TAPPING_TERM
#define TAPPING_TERM 180

#define ONESHOT_TAP_TOGGLE 3

#undef ONESHOT_TIMEOUT
#define ONESHOT_TIMEOUT 1900

#define IGNORE_MOD_TAP_INTERRUPT
#define PERMISSIVE_HOLD

#define USB_SUSPEND_WAKEUP_DELAY 0
#define RGB_MATRIX_STARTUP_SPD 60
// Default mode for rgb effects
#define RGB_MATRIX_STARTUP_MODE RGB_MATRIX_TYPING_HEATMAP
// RGB off when PC is sleeping
#define RGBLIGHT_SLEEP

#define LEADER_TIMEOUT 300
#define LEADER_PER_KEY_TIMING
