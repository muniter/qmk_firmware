
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
  [0] = LAYOUT_moonlander(
    /* KC_GRAVE,       KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_DELETE,                                      WEBUSB_PAIR,    KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          OSM(MOD_RALT), */  
    KC_GRAVE,       KC_1,           KC_2,           KC_3,           KC_4,           KC_5,           KC_DELETE,                                      WEBUSB_PAIR,    KC_6,           KC_7,           KC_8,           KC_9,           KC_0,           OSM(MOD_RALT),  
    KC_TAB,         KC_Q,           KC_W,           KC_E,           KC_R,           KC_T,           KC_DELETE,                                      KC_PAUSE,       KC_Y,           KC_U,           KC_I,           KC_O,           KC_P,           KC_BSLASH,
    LT(6,KC_ESCAPE),HOME_A,         HOME_S,         HOME_D,         HOME_F,         KC_G,           KC_BSPACE,                                      KC_INSERT,      KC_H,           HOME_J,         HOME_K,         HOME_L,         HOME_SCLN,      KC_QUOTE,
    KC_NO,          KC_Z,           KC_X,           KC_C,           KC_V,           KC_B,                                                                           KC_N,           KC_M,           KC_COMMA,       KC_DOT,         KC_SLASH,       KC_NO,
    KC_LCTRL,       KC_LGUI,        KC_LALT,        OSL(7),         LT(3,KC_SPACE),                 LSFT_T(KC_PSCREEN),                             RSFT_T(KC_APPLICATION),         LT(3,KC_ENTER), LT(2,KC_NO),    KC_LBRACKET,    KC_RBRACKET,    KC_RCTRL,
                                                                    OSL(1),         OSM(MOD_RSFT), KC_LEAD,                                         KC_NO,          KC_BSPACE,      LT(6,KC_SPACE)),
  /* Symbols layer */
  [1] = LAYOUT_moonlander(
    TO(0),          KC_F1,          KC_F2,          KC_F3,          KC_F4,          KC_F5,          KC_F11,                                         KC_F12,         KC_F6,          KC_F7,          KC_F8,          KC_F9,          KC_F10,         TO(0),
    KC_TRANSPARENT, KC_EXLM,        KC_AT,          KC_UNDS,        KC_LCBR,        KC_BSLASH,      KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_RCBR,        KC_PLUS,        KC_ASTR,        KC_AMPR,        KC_PIPE,
    KC_TRANSPARENT, KC_HASH,        KC_CIRC,        KC_MINUS,       KC_LPRN,        KC_TILD,        KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_NO,          KC_RPRN,        KC_EQUAL,       KC_NO,          KC_COLN,        KC_DQUO,
    KC_TRANSPARENT, KC_PERC,        KC_DLR,         KC_NO,          KC_LBRACKET,    KC_GRAVE,                                                       KC_TRANSPARENT, KC_RBRACKET,    KC_LABK,        KC_RABK,        KC_QUES,        KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,        TT(6),                                                           KC_TRANSPARENT,         KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
                                                                    KC_TRANSPARENT, KC_LEAD,        KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT
  ),
  /* Media and settings layer */
  [2] = LAYOUT_moonlander(
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, TO(0),          
    KC_TRANSPARENT, MU_MOD,         KC_TRANSPARENT, KC_TRANSPARENT, EEPROM_RESET, KC_TRANSPARENT, KC_TRANSPARENT,                                   KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, MU_TOG,         KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_AUDIO_VOL_DOWN,KC_AUDIO_VOL_UP,KC_AUDIO_MUTE,  KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_CALCULATOR,  KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_MEDIA_REWIND,KC_MEDIA_PREV_TRACK,KC_MEDIA_PLAY_PAUSE,KC_MEDIA_NEXT_TRACK,KC_MEDIA_FAST_FORWARD,KC_TRANSPARENT, 
    RESET,          KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, RGB_MOD,                                                                                                        RGB_TOG,        KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    RGB_VAD,        RGB_VAI,        TOGGLE_LAYER_COLOR,                RGB_SLD,        KC_TRANSPARENT, KC_TRANSPARENT
  ),
  /* Navigation layer */
  [3] = LAYOUT_moonlander(
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 DYN_REC_STOP,   KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, TO(0),          
    KC_TRANSPARENT, KC_TRANSPARENT, KC_F4,          KC_F2,          LCTL(LSFT(KC_Z)),KC_TRANSPARENT, DYN_MACRO_PLAY2,                               DYN_REC_START2, KC_TRANSPARENT, LCTL(KC_Z),     KC_TAB,         LSFT(KC_TAB),   KC_F6,          KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_LGUI,        KC_LALT,        KC_LSFT,        KC_LCTRL,       KC_TRANSPARENT, DYN_MACRO_PLAY1,                                DYN_REC_START1, KC_LEFT,        KC_DOWN,        KC_UP,          KC_RIGHT,       KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, LCTL(KC_Z),     LCTL(KC_X),     LCTL(KC_C),     LCTL(KC_V),     KC_ENTER,                                                                       KC_HOME,        KC_PGDOWN,      KC_PGUP,        KC_END,         KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, TT(8),                                                                          KC_TRANSPARENT, KC_TRANSPARENT, KC_SPACE,       KC_BSPACE,      KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT
  ),
  /* Mouse scrolling layer */
  [4] = LAYOUT_moonlander(
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, TO(0),          
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_MS_BTN1,     KC_MS_BTN2,     KC_MS_BTN3,     KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_MS_RIGHT,    KC_MS_DOWN,     KC_MS_UP,       KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                                                 KC_TRANSPARENT, KC_MS_WH_LEFT,  KC_MS_WH_DOWN,  KC_MS_WH_UP,    KC_MS_WH_RIGHT, KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                                                                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT
  ),
  /* Mouse movement layer */
  [5] = LAYOUT_moonlander(
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_MS_ACCEL0,   KC_MS_ACCEL1,   KC_MS_ACCEL2,   KC_TRANSPARENT, TO(0),          
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_MS_BTN1,     KC_MS_BTN2,     KC_MS_BTN3,     KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                                                 KC_TRANSPARENT, KC_MS_LEFT,     KC_MS_DOWN,     KC_MS_UP,       KC_MS_RIGHT,    KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                                                                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT
  ),
  /* Keypad layer */
  [6] = LAYOUT_moonlander(
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TAB,         KC_SLASH,       KC_ASTR,        KC_EQUAL,       TO(0),          
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_7,           KC_8,           KC_9,           KC_MINUS,       KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_4,           KC_5,           KC_6,           KC_PLUS,        KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_0,           KC_1,           KC_2,           KC_3,           KC_DOT,         KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                                                                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT
  ),
  /* Spanish Accents layer */
  [7] = LAYOUT_moonlander(
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, TO(0),          
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, RALT(KC_E),     KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, RALT(KC_Y), RALT(KC_U),     RALT(KC_I),     RALT(KC_O),     KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, RALT(KC_A),     KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                                                 LALT(KC_N),     KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 RALT(KC_N),     KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                                                                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT
  ),
  /* Firefox layer */
  [8] = LAYOUT_moonlander(
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TRANSPARENT, LCTL(KC_W),     KC_TRANSPARENT, LCTL(KC_R),     KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, LCTL(LSFT(KC_T)),KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, LCTL(LSFT(KC_Y)),KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                                                 KC_TRANSPARENT, LALT(KC_LEFT),  LCTL(KC_PGDOWN),LCTL(KC_PGUP),  LALT(KC_RIGHT), KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                                                                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT
  ),
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case ES_LSPO:
      perform_space_cadet(record, keycode, KC_LSFT, KC_LSFT, KC_8);
      return false;
    case ES_RSPC:
      perform_space_cadet(record, keycode, KC_LSFT, KC_LSFT, KC_9);
      return false;
    case RGB_SLD:
      if (record->event.pressed) {
        rgblight_mode(1);
      }
      return false;
  }
  return true;
}

// Tapping force hold per key
bool get_tapping_force_hold(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case LT(6, KC_SPACE):
            return false;
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

LEADER_EXTERNS();

void matrix_scan_user(void) {
  LEADER_DICTIONARY() {
    leading = false;
    leader_end();

    /* SEQ_ONE_KEY(KC_F) { */
    /*   register_code(KC_S); */
    /*   unregister_code(KC_S); */
    /* } */
    // email
    SEQ_TWO_KEYS(KC_E, KC_M) {
      SEND_STRING("graulopezjavier@gmail.com");
    }
    SEQ_TWO_KEYS(KC_A, KC_S) {
      register_code(KC_LGUI);
      register_code(KC_S);
      unregister_code(KC_S);
      unregister_code(KC_LGUI);
    }
  }
}


