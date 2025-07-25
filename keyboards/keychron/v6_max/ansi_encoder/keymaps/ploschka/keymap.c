/* Copyright 2024 @ Keychron (https://www.keychron.com)
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

#include "keycodes.h"
#include QMK_KEYBOARD_H
#include "keychron_common.h"

enum layers {
    BASE_LAYER,
    MOUSE_LAYER,
    MOTION_LAYER,
    COOL_KEYS,
    FN_LYR,
};

//     [LAYER] = LAYOUT_ansi_109(
//         _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,
//         ESCAPE    F1        F2        F3        F4        F5        F6        F7        F8        F9        F10       F11       F12       ENCODER   PRINT     MIC       LIGHT     CIRCLE    TRIANG    SQUARE    CROSS
//         _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,
//         GRAVE     1         2         3         4         5         6         7         8         9         0         -         =         BACKSPC   INSERT    HOME      PGUP      NUMLCK    /         *         -
//         _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______
//         TAB       Q         W         E         R         T         Y         U         I         O         P         [         ]         \         DEL       END       PGDWN     P7        P8        P9
//         _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,            _______,                                _______,  _______,  _______,  _______
//         CAPS      A         S         D         F         G         H         J         K         L         ;         '                   ENTER                                   P4        P5        P6        PPLUS
//         _______,            _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,            _______,            _______,            _______,  _______,  _______,
//         SHIFT               Z         X         C         V         B         N         M         ,         .         /                   RSHIFT              UP                  P1        P2        P3
//         _______,  _______,  _______,                                _______,                                _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,            _______,  _______),
//         CONTROL   WIN       ALT                                     SPACE                                   RALT      RWIN      FN        RCTRL     LEFT      DOWN      RIGHT     P0                  P.        PENT

#define MOTIONS LT(MOTION_LAYER, KC_ESCAPE)
#define MOUSTOG TG(MOUSE_LAYER)

const uint16_t G_COOL = LT(COOL_KEYS, KC_G);
const uint16_t H_COOL = LT(COOL_KEYS, KC_H);

const uint16_t LBR = S(KC_LBRC);
const uint16_t RBR = S(KC_RBRC);
const uint16_t DASH = KC_MINS;
const uint16_t SUB = S(KC_MINS);
const uint16_t S_QUOT = KC_QUOT;
const uint16_t D_QUOT = S(KC_QUOT);
const uint16_t EQUAL = KC_EQL;
const uint16_t PLUS = S(KC_EQL);

#define C_BKSPC C(KC_BACKSPACE)
#define C_DELET C(KC_DELETE)

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [BASE_LAYER] = LAYOUT_ansi_109(
        KC_ESC,   KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,    KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_F11,   KC_F12,     KC_MUTE,    KC_PSCR,  KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    MOUSTOG,
        KC_GRV,   KC_1,     KC_2,     KC_3,     KC_4,     KC_5,     KC_6,     KC_7,     KC_8,     KC_9,     KC_0,     KC_MINS,  KC_EQL,     KC_BSPC,    KC_INS,   KC_HOME,  KC_PGUP,  KC_NUM,   KC_PSLS,  KC_PAST,  KC_PMNS,
        KC_TAB,   KC_Q,     KC_W,     KC_E,     KC_R,     KC_T,     KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,     KC_LBRC,  KC_RBRC,    KC_BSLS,    KC_DEL,   KC_END,   KC_PGDN,  KC_P7,    KC_P8,    KC_P9,
        MOTIONS,  KC_A,     KC_S,     KC_D,     KC_F,     G_COOL,   H_COOL,   KC_J,     KC_K,     KC_L,     KC_SCLN,  KC_QUOT,              KC_ENT,                                   KC_P4,    KC_P5,    KC_P6,    KC_PPLS,
        SC_LSPO,            KC_Z,     KC_X,     KC_C,     KC_V,     KC_B,     KC_N,     KC_M,     KC_COMM,  KC_DOT,   KC_SLSH,              SC_RSPC,              KC_UP,              KC_P1,    KC_P2,    KC_P3,
        KC_LCTL,  KC_LWIN,  KC_LALT,                                KC_SPC,                                 KC_RALT,  KC_RWIN,  MO(FN_LYR), KC_RCTL,    KC_LEFT,  KC_DOWN,  KC_RGHT,  KC_P0,              KC_PDOT,  KC_PENT),
    [MOUSE_LAYER] = LAYOUT_ansi_109(
        _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,    _______,    _______,  _______,  _______,  _______,  _______,  _______,  _______,
        _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,    _______,    _______,  _______,  MS_WHLU,  _______,  _______,  _______,  _______,
        _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,    _______,    _______,  _______,  MS_WHLD,  MS_BTN1,  MS_UP,    MS_BTN2,
        _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,              _______,                                  MS_LEFT,  MS_DOWN,  MS_RGHT,  _______,
        _______,            _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,              _______,              _______,            _______,  _______,  _______,
        _______,  _______,  _______,                                _______,                                _______,  _______,  _______,    _______,    _______,  _______,  _______,  _______,            _______,  _______),
    [MOTION_LAYER] = LAYOUT_ansi_109(
        _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,    _______,    _______,  _______,  _______,  _______,  _______,  _______,  _______,
        _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,    _______,    _______,  _______,  _______,  _______,  _______,  _______,  _______,
        _______,  _______,  _______,  KC_ENTER, _______,  _______,  _______,  KC_HOME,  KC_END,   _______,  _______,  _______,  _______,    _______,    _______,  _______,  _______,  _______,  _______,  _______,
        _______,  _______,  _______,  _______,  _______,  _______,  KC_LEFT,  KC_DOWN,  KC_UP,    KC_RIGHT, _______,  _______,              _______,                                  _______,  _______,  _______,  _______,
        _______,            _______,  _______,  _______,  _______,  _______,  KC_BSPC,  KC_DEL,   C_BKSPC,  C_DELET,  _______,              _______,              _______,            _______,  _______,  _______,
        _______,  _______,  _______,                                _______,                                _______,  _______,  _______,    _______,    _______,  _______,  _______,  _______,            _______,  _______),
    [COOL_KEYS] = LAYOUT_ansi_109(
        _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,
        _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,
        _______,  _______,  _______,  LBR,      KC_LBRC,  _______,  _______,  KC_RBRC,  RBR,      _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,
        _______,  _______,  _______,  EQUAL,    PLUS,     _______,  _______,  DASH,     SUB,      _______,  _______,  _______,            _______,                                _______,  _______,  _______,  _______,
        _______,            _______,  _______,  _______,  _______,  _______,  S_QUOT,   D_QUOT,   _______,  _______,  _______,            _______,            _______,            _______,  _______,  _______,
        _______,  _______,  _______,                                _______,                                _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,            _______,  _______),
    [FN_LYR] = LAYOUT_ansi_109(
        _______,  KC_BRID,  KC_BRIU,  _______,  _______,  RGB_VAD,  RGB_VAI,  KC_MPRV,  KC_MPLY,  KC_MNXT,  KC_MUTE,  KC_VOLD,  KC_VOLU,    RGB_TOG,    _______,  _______,  _______,  _______,  _______,  _______,  _______,
        _______,  BT_HST1,  BT_HST2,  BT_HST3,  P2P4G,    _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,    _______,    _______,  _______,  _______,  _______,  _______,  _______,  _______,
        RGB_TOG,  RGB_MOD,  RGB_VAI,  RGB_HUI,  RGB_SAI,  RGB_SPI,  _______,  _______,  _______,  _______,  _______,  _______,  _______,    _______,    _______,  _______,  _______,  _______,  _______,  _______,
        _______,  RGB_RMOD, RGB_VAD,  RGB_HUD,  RGB_SAD,  RGB_SPD,  _______,  _______,  _______,  _______,  _______,  _______,              _______,                                  _______,  _______,  _______,  _______,
        _______,            _______,  _______,  _______,  _______,  BAT_LVL,  NK_TOGG,  _______,  _______,  _______,  _______,              _______,              _______,            _______,  _______,  _______,
        _______,  _______,  _______,                                _______,                                _______,  _______,  _______,    _______,    _______,  _______,  _______,  _______,            _______,  _______),
};

#if defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][2] = {
    [BASE_LAYER] = {ENCODER_CCW_CW(KC_VOLD, KC_VOLU)},
    [MOUSE_LAYER] = {ENCODER_CCW_CW(_______, _______)},
    [MOTION_LAYER] = {ENCODER_CCW_CW(_______, _______)},
    [COOL_KEYS] = {ENCODER_CCW_CW(_______, _______)},
    [FN_LYR]   = {ENCODER_CCW_CW(RGB_VAD, RGB_VAI)},
};
#endif // ENCODER_MAP_ENABLE

// clang-format on
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    return true;
}

