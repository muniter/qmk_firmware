/* Copyright 2020 ZSA Technology Labs, Inc <@zsa>
 * Copyright 2020 Jack Humbert <jack.humb@gmail.com>
 * Copyright 2020 Christopher Courtney <drashna@live.com> (@drashna)
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
// For keylogging
#ifdef CONSOLE_ENABLE
#include "print.h"
#endif

// Layer names
#define _BS 0
#define _SY 1
#define _NU 2
#define _NA 3
#define _SE 4
#define _AC 5

// My special thumb cluster shift
#define OSFT OSM(MOD_RSFT)
#define ACCE_G LT(_AC,KC_G)

// Left-hand home row mods
#define HOME_A LGUI_T(KC_A)
#define HOME_S LALT_T(KC_S)
#define HOME_D LSFT_T(KC_D)
#define HOME_F LCTL_T(KC_F)
// Right-hand home row mods
#define HOME_J RCTL_T(KC_J)
#define HOME_K RSFT_T(KC_K)
#define HOME_L LALT_T(KC_L)
#define HOME_SCLN RGUI_T(KC_SCLN)

#include QMK_KEYBOARD_H
#include "version.h"

enum custom_keycodes {
  RGB_SLD = ML_SAFE_RANGE,
  ES_LSPO,
  ES_RSPC,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_BS] = LAYOUT_moonlander(
    /* KC_GRAVE,       KC_1,           KC_2,           KC_3,           KC_4,           KC_5,           KC_DELETE,                                      WEBUSB_PAIR,    KC_6,           KC_7,           KC_8,           KC_9,           KC_0,           OSM(MOD_RALT), */
    KC_NO,          KC_NO,           KC_NO,           KC_NO,           KC_NO,           KC_NO,           KC_NO,                                      KC_NO,    KC_NO,           KC_NO,           KC_NO,           KC_NO,           KC_NO,           OSM(MOD_RALT),
    KC_NO,          KC_Q,           KC_W,           KC_E,           KC_R,           KC_T,           KC_DELETE,                                      KC_PAUSE,       KC_Y,           KC_U,           KC_I,           KC_O,           KC_P,           KC_BSLASH,
    KC_ESC,      HOME_A,         HOME_S,         HOME_D,         HOME_F,         ACCE_G,         KC_BSPACE,                                      KC_INSERT,      KC_H,           HOME_J,         HOME_K,         HOME_L,         HOME_SCLN,      KC_QUOTE,
    KC_NO,          KC_Z,           KC_X,           KC_C,           KC_V,           KC_B,                                                                           KC_N,           KC_M,           KC_COMMA,       KC_DOT,         KC_SLASH,       KC_NO,
    KC_LEAD,        KC_LGUI,        KC_LALT,        OSL(_AC),       LT(_NA,KC_SPACE),               KC_PSCREEN,                                 RSFT_T(KC_APPLICATION),         LT(_NA,KC_ENTER), LT(_SE,KC_NO),    KC_LBRACKET,    KC_RBRACKET,    KC_RCTRL,
                                                                    OSL(_SY),         OSFT,         KC_LEAD,                                        KC_NO,          KC_BSPACE,      LT(_NU,KC_SPACE)),
  /* Symbols layer */
  [_SY] = LAYOUT_moonlander(
    _______, KC_F1,          KC_F2,          KC_F3,          KC_F4,          KC_F5,          KC_F11,                                  KC_F12,         KC_F6,          KC_F7,          KC_F8,          KC_F9,          KC_F10,         TO(_BS),
    _______, KC_EXLM,        KC_AT,          KC_UNDS,        KC_LCBR,        KC_BSLASH,      _______,                                 _______, _______, KC_RCBR,        KC_PLUS,        KC_ASTR,        KC_AMPR,        KC_PIPE,
    _______, KC_HASH,        KC_CIRC,        KC_MINUS,       KC_LPRN,        KC_TILD,        _______,                                 _______, KC_NO,   KC_RPRN,        KC_EQUAL,       KC_NO,          KC_COLN,        KC_DQUO,
    _______, KC_PERC,        KC_DLR,         KC_NO,          KC_LBRACKET,    KC_GRAVE,                                                         _______, KC_RBRACKET,    KC_LABK,        KC_RABK,        KC_QUES,        _______, 
    _______, _______, _______, _______, _______,                             MO(_NU),                                                   _______,                                 _______, _______, _______, _______, _______, 
                                                                    _______, MO(_NU),        _______,                          _______, _______, _______
  ),
  /* Media and settings layer */
  [_SE] = LAYOUT_moonlander(
    _______, _______, _______, _______, _______, _______, _______,                                 _______, _______, _______, _______, _______, _______, TO(_BS),
    _______, MU_MOD,  _______, _______, EEP_RST, _______, _______,                                 _______, _______, _______, _______, _______, _______, _______,
    _______, MU_TOG,  _______, _______, _______, _______, _______,                                 _______, _______, KC_VOLD, KC_VOLU, KC_MUTE, _______, _______,
    _______, _______, _______, KC_CALC,  _______, _______,                                                  KC_MRWD, KC_MPRV, KC_MPLY, KC_MNXT, KC_MFFD, _______,
    RESET,  _______, _______, _______, _______, RGB_MOD,                                           RGB_TOG,          _______, _______, _______, _______, _______, 
                                       RGB_VAD, RGB_VAI, TOGGLE_LAYER_COLOR,              RGB_SLD, _______, _______
  ),
  /* Navigation layer */
  [_NA] = LAYOUT_moonlander(
    _______, _______, _______, _______, _______, _______, _______,                                 DYN_REC_STOP,   _______, _______, _______, _______, _______, TO(_BS),          
    _______, _______, KC_F4,          KC_F2,          LCTL(LSFT(KC_Z)),_______, DYN_MACRO_PLAY2,                               DYN_REC_START2, _______, LCTL(KC_Z),     KC_TAB,         LSFT(KC_TAB),   KC_F6,          _______, 
    _______, KC_LGUI,        KC_LALT,        KC_LSFT,        KC_LCTRL,       _______, DYN_MACRO_PLAY1,                                DYN_REC_START1, KC_LEFT,        KC_DOWN,        KC_UP,          KC_RIGHT,       _______, _______, 
    _______, LCTL(KC_Z),     LCTL(KC_X),     LCTL(KC_C),     LCTL(KC_V),     KC_ENTER,                                                                       KC_HOME,        KC_PGDOWN,      KC_PGUP,        KC_END,         _______, _______, 
    _______, _______, _______, _______, _______, _______,                                                                          _______, _______, KC_SPACE,       KC_BSPACE,      _______, _______, 
    _______, _______, _______,                 _______, _______, _______
  ),
  /* Numpad layer */
  [_NU] = LAYOUT_moonlander(
    _______, _______, _______, _______, _______, _______, _______,                                 _______, _______, KC_TAB,         KC_SLASH,       KC_ASTR,        KC_EQUAL,       TO(_BS),          
    _______, _______, _______, _______, _______, _______, _______,                                 _______, _______, KC_7,           KC_8,           KC_9,           KC_MINUS,       _______, 
    _______, KC_ESC,  _______, _______, KC_TAB,  _______, _______,                            _______, _______,      LCTL_T(KC_4),   LSFT_T(KC_5),   LALT_T(KC_6),   LGUI_T(KC_PLUS),_______, 
    _______, _______, _______, _______, _______, _______,                                 KC_0,           KC_1,           KC_2,           KC_3,           KC_DOT,         _______, 
    _______, _______, _______, _______, _______, _______,                                                                                                 _______, _______, _______, _______, _______, _______, 
    _______, _______, _______, _______, _______, _______
  ),
  /* Spanish Accents layer */
  [_AC] = LAYOUT_moonlander(
    _______, _______, _______, _______, _______, _______, _______,                                 _______, _______, _______, _______, _______, _______, TO(_BS),          
    _______, _______, _______, RALT(KC_E),     _______, _______, _______,                                 _______, RALT(KC_Y), RALT(KC_U),     RALT(KC_I),     RALT(KC_O),     _______, _______, 
    _______, RALT(KC_A),     _______, _______, _______, _______, _______,                                                                 LALT(KC_N),     _______, _______, _______, _______, _______, _______, 
    _______, _______, _______, _______, _______, _______,                                 RALT(KC_N),     _______, _______, _______, _______, _______, 
    _______, _______, _______, _______, _______, _______,                                                                                                 _______, _______, _______, _______, _______, _______, 
    _______, _______, _______,                 _______, _______, _______
  ),
};

// If osm shift is held
static bool osm_shift_held = false;
// If the symbols were turned on by the logic
static bool turned_on_symbols = false;
// If any symbol was used while turned on by the logic
static bool used_a_symbol = false;
// Keep track of the mod states
uint8_t mod_state;
uint8_t oneshot_mod_state;
// Timer to track wether to space or not
static uint16_t my_space_timer;

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    /* #ifdef CONSOLE_ENABLE */
    /*     if (record->event.pressed) { */
    /*         uprintf("0x%04X,%u,%u,%u\n", keycode, record->event.key.row, record->event.key.col, get_highest_layer(layer_state)); */
    /*     } */
    /* #endif */
    //If pressed any key when the symbol layer was activated save it to not send the space
    if (record->event.pressed && turned_on_symbols) {
        used_a_symbol = true;
    }
    switch (keycode) {
        case LT(_NU,KC_SPACE):
            if (record-> event.pressed && osm_shift_held) {
                my_space_timer = timer_read();
                // Save the mods and clear them
                mod_state = get_mods();
                oneshot_mod_state = get_oneshot_mods();
                clear_mods();
                // Turn on thelayer
                layer_on(_SY);
                turned_on_symbols = true;
                return false;
            } else if (turned_on_symbols) {
                // If less than tapping term and didn't use any symbols
                if (timer_elapsed(my_space_timer) < TAPPING_TERM && !used_a_symbol) {
                    tap_code(KC_SPACE);
                }
                turned_on_symbols = false;
                used_a_symbol = false;
                layer_off(_SY);
                // Restore the mods after removing the layer if shift is being held still
                if (osm_shift_held) {
                    set_mods(mod_state);
                    set_oneshot_mods(mod_state);
                }
                return false;
            }
            return true;
        case OSFT:
            // Set the variable when the key is held
            if (record-> event.pressed) {
                osm_shift_held = true;
            } else {
                osm_shift_held = false;
            }
            return true;
        case KC_PSCREEN:
            // Combo OSFT and KC_PSCREEN for caps lock
            if (record-> event.pressed && osm_shift_held) {
                tap_code(KC_CAPS);
                return false;
            }
            return true;
    }
    return true;
}

// Tapping force hold per key
bool get_tapping_force_hold(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case LT(6, KC_SPACE):
            return true;
        case HOME_A:
            return true;
        case HOME_S:
            return true;
        case HOME_D:
            return true;
        case HOME_F:
            return true;
        case HOME_J:
            return true;
        case HOME_K:
            return true;
        case HOME_L:
            return true;
        case HOME_SCLN:
            return true;
        default:
            return false;
    }
}
// Combo functionality
enum combos {
    JF_ESC
};

// Turn on capslock when pressed with print screen
/* const uint16_t PROGMEM jf_esc_combo[] = {HOME_F, HOME_J, COMBO_END}; */

/* combo_t key_combos[COMBO_COUNT] = { */
/*   [JF_ESC] = COMBO(jf_esc_combo, KC_ESC) */
/* }; */

/* void process_combo_event(uint16_t combo_index, bool pressed) { */
/*     switch(combo_index) { */
/*         case CAPS_LOCK: */
/*           if (pressed) { */
/*               tap_code(KC_CAPS); */
/*           } */
/*           break; */
/*       } */
/* } */

// Leader functionality
LEADER_EXTERNS();
void matrix_scan_user(void) {
    // Documentation https://beta.docs.qmk.fm/using-qmk/advanced-keycodes/feature_leader_key
    LEADER_DICTIONARY() {
        leading = false;
        leader_end();

        // Reload sway
        SEQ_TWO_KEYS(HOME_S, KC_R) {
            register_code(KC_LGUI);
            tap_code(KC_F2);
            unregister_code(KC_LGUI);
        }
        SEQ_TWO_KEYS(KC_E, KC_M) {
            SEND_STRING("graulopezjavier@gmail.com");
        }
        SEQ_TWO_KEYS(KC_U, HOME_S) {
            SEND_STRING("muniter");
        }
    }
}

extern bool g_suspend_state;
extern rgb_config_t rgb_matrix_config;

void keyboard_post_init_user(void) {
    rgb_matrix_enable();
}

const uint8_t PROGMEM ledmap[][DRIVER_LED_TOTAL][3] = {
    [1] = { {175,238,222}, {175,238,222}, {175,238,222}, {175,238,222}, {175,238,222}, {175,238,222}, {175,238,222}, {175,238,222}, {175,238,222}, {175,238,222}, {175,238,222}, {175,238,222}, {175,238,222}, {175,238,222}, {175,238,222}, {175,238,222}, {175,238,222}, {175,238,222}, {175,238,222}, {175,238,222}, {175,238,222}, {175,238,222}, {175,238,222}, {175,238,222}, {175,238,222}, {175,238,222}, {175,238,222}, {175,238,222}, {175,238,222}, {175,238,222}, {175,238,222}, {175,238,222}, {175,238,222}, {175,238,222}, {175,238,222}, {175,238,222}, {175,238,222}, {175,238,222}, {175,238,222}, {175,238,222}, {175,238,222}, {175,238,222}, {175,238,222}, {175,238,222}, {175,238,222}, {175,238,222}, {175,238,222}, {175,238,222}, {175,238,222}, {175,238,222}, {175,238,222}, {175,238,222}, {175,238,222}, {175,238,222}, {175,238,222}, {175,238,222}, {175,238,222}, {175,238,222}, {175,238,222}, {175,238,222}, {175,238,222}, {175,238,222}, {175,238,222}, {175,238,222}, {175,238,222}, {175,238,222}, {175,238,222}, {175,238,222}, {175,238,222}, {175,238,222}, {175,238,222}, {175,238,222} },

    [2] = { {45,224,242}, {45,224,242}, {45,224,242}, {45,224,242}, {45,224,242}, {45,224,242}, {45,224,242}, {45,224,242}, {45,224,242}, {45,224,242}, {45,224,242}, {45,224,242}, {45,224,242}, {45,224,242}, {45,224,242}, {45,224,242}, {45,224,242}, {45,224,242}, {45,224,242}, {45,224,242}, {45,224,242}, {45,224,242}, {45,224,242}, {45,224,242}, {45,224,242}, {45,224,242}, {45,224,242}, {45,224,242}, {45,224,242}, {45,224,242}, {45,224,242}, {45,224,242}, {45,224,242}, {45,224,242}, {45,224,242}, {45,224,242}, {45,224,242}, {45,224,242}, {45,224,242}, {45,224,242}, {45,224,242}, {45,224,242}, {45,224,242}, {45,224,242}, {45,224,242}, {45,224,242}, {45,224,242}, {45,224,242}, {45,224,242}, {45,224,242}, {45,224,242}, {45,224,242}, {45,224,242}, {45,224,242}, {45,224,242}, {45,224,242}, {45,224,242}, {45,224,242}, {45,224,242}, {45,224,242}, {45,224,242}, {45,224,242}, {45,224,242}, {45,224,242}, {45,224,242}, {45,224,242}, {45,224,242}, {45,224,242}, {45,224,242}, {45,224,242}, {45,224,242}, {45,224,242} },

    [3] = { {255,241,229}, {255,241,229}, {255,241,229}, {255,241,229}, {255,241,229}, {255,241,229}, {255,241,229}, {255,241,229}, {255,241,229}, {255,241,229}, {255,241,229}, {255,241,229}, {255,241,229}, {255,241,229}, {255,241,229}, {255,241,229}, {255,241,229}, {255,241,229}, {255,241,229}, {255,241,229}, {255,241,229}, {255,241,229}, {255,241,229}, {255,241,229}, {255,241,229}, {255,241,229}, {255,241,229}, {255,241,229}, {255,241,229}, {255,241,229}, {255,241,229}, {255,241,229}, {255,241,229}, {255,241,229}, {255,241,229}, {255,241,229}, {255,241,229}, {255,241,229}, {255,241,229}, {255,241,229}, {255,241,229}, {255,241,229}, {255,241,229}, {255,241,229}, {255,241,229}, {255,241,229}, {255,241,229}, {255,241,229}, {31,255,255}, {255,241,229}, {255,241,229}, {255,241,229}, {255,241,229}, {31,255,255}, {255,241,229}, {255,241,229}, {255,241,229}, {255,241,229}, {31,255,255}, {255,241,229}, {255,241,229}, {255,241,229}, {255,241,229}, {31,255,255}, {255,241,229}, {255,241,229}, {255,241,229}, {255,241,229}, {255,241,229}, {255,241,229}, {255,241,229}, {255,241,229} },

    [4] = { {255,241,229}, {255,241,229}, {255,241,229}, {255,241,229}, {255,241,229}, {255,241,229}, {255,241,229}, {255,241,229}, {255,241,229}, {255,241,229}, {255,241,229}, {255,241,229}, {255,241,229}, {255,241,229}, {255,241,229}, {255,241,229}, {255,241,229}, {255,241,229}, {255,241,229}, {255,241,229}, {255,241,229}, {255,241,229}, {255,241,229}, {255,241,229}, {255,241,229}, {255,241,229}, {255,241,229}, {255,241,229}, {255,241,229}, {255,241,229}, {255,241,229}, {255,241,229}, {255,241,229}, {255,241,229}, {255,241,229}, {255,241,229}, {255,241,229}, {255,241,229}, {31,255,255}, {255,241,229}, {255,241,229}, {255,241,229}, {255,241,229}, {31,255,255}, {255,241,229}, {255,241,229}, {255,241,229}, {31,255,255}, {31,255,255}, {255,241,229}, {255,241,229}, {255,241,229}, {31,255,255}, {31,255,255}, {255,241,229}, {255,241,229}, {255,241,229}, {31,255,255}, {31,255,255}, {255,241,229}, {255,241,229}, {255,241,229}, {255,241,229}, {31,255,255}, {255,241,229}, {255,241,229}, {255,241,229}, {255,241,229}, {255,241,229}, {255,241,229}, {255,241,229}, {255,241,229} },

    [5] = { {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,0}, {0,0,0}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,0}, {0,0,0}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0} },

    [6] = { {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {31,255,255}, {31,255,255}, {31,255,255}, {31,255,255}, {0,0,255}, {31,255,255}, {141,255,233}, {0,0,0}, {141,255,233}, {0,0,0}, {31,255,255}, {141,255,233}, {141,255,233}, {141,255,233}, {0,0,0}, {31,255,255}, {141,255,233}, {141,255,233}, {141,255,233}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,255}, {141,255,233}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0} },

};

void set_layer_color(int layer) {
    for (int i = 0; i < DRIVER_LED_TOTAL; i++) {
        HSV hsv = {
            .h = pgm_read_byte(&ledmap[layer][i][0]),
            .s = pgm_read_byte(&ledmap[layer][i][1]),
            .v = pgm_read_byte(&ledmap[layer][i][2]),
        };
        if (!hsv.h && !hsv.s && !hsv.v) {
            rgb_matrix_set_color( i, 0, 0, 0 );
        } else {
            RGB rgb = hsv_to_rgb( hsv );
            float f = (float)rgb_matrix_config.hsv.v / UINT8_MAX;
            rgb_matrix_set_color( i, f * rgb.r, f * rgb.g, f * rgb.b );
        }
    }
}

void rgb_matrix_indicators_user(void) {
    if (g_suspend_state || keyboard_config.disable_layer_led) { return; }
    switch (biton32(layer_state)) {
        case 1:
            set_layer_color(1);
            break;
        case 2:
            set_layer_color(2);
            break;
        case 3:
            set_layer_color(3);
            break;
        case 4:
            set_layer_color(4);
            break;
        case 5:
            set_layer_color(5);
            break;
        case 6:
            set_layer_color(6);
            break;
        default:
            if (rgb_matrix_get_flags() == LED_FLAG_NONE)
                rgb_matrix_set_color_all(0, 0, 0);
            break;
    }
}
