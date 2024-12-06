#include QMK_KEYBOARD_H

#include "eeprom.h"

#include "keymap_swedish.h"

#define KC_MAC_UNDO LGUI(KC_Z)
#define KC_MAC_CUT LGUI(KC_X)
#define KC_MAC_COPY LGUI(KC_C)
#define KC_MAC_PASTE LGUI(KC_V)
#define KC_PC_UNDO LCTL(KC_Z)
#define KC_PC_CUT LCTL(KC_X)
#define KC_PC_COPY LCTL(KC_C)
#define KC_PC_PASTE LCTL(KC_V)
#define ES_LESS_MAC KC_GRAVE
#define ES_GRTR_MAC LSFT(KC_GRAVE)
#define ES_BSLS_MAC ALGR(KC_6)
#define NO_PIPE_ALT KC_GRAVE
#define NO_BSLS_ALT KC_EQUAL
#define LSA_T(kc) MT(MOD_LSFT | MOD_LALT, kc)
#define BP_NDSH_MAC ALGR(KC_8)
#define SE_SECT_MAC ALGR(KC_6)

enum layers {
  _BASE,
  _LOWER,
  _RAISE,
  _NAV,
  _FUNCTION,
};

#define LOWER LT(_LOWER, KC_SPACE)
#define RAISE LT(_RAISE, KC_ENT)
#define FUNCTION LT(_FUNCTION, KC_BSPC)
#define NAV LT(_NAV, KC_ESC)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_BASE] = LAYOUT(
    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,               KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,        
    KC_A,    KC_S,    KC_D,    KC_F,    KC_G,               KC_H,    KC_J,    KC_K,    KC_L,    KC_NO, 
    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,               KC_N,    KC_M,    SE_ARNG, SE_ADIA, SE_ODIA,          
                                  FUNCTION,    NAV,    LOWER,    RAISE
  ),

  [_LOWER] = LAYOUT(
    KC_EXLM,    SE_AT,    KC_HASH,    SE_DLR,     KC_PERC,             SE_CIRC,    SE_AMPR,    SE_LPRN,    SE_RPRN,    SE_PIPE,
    KC_TRNS,    SE_TILD,  MT(SE_BSLS, SE_SLSH),    MT(MOD_LSFT | KC_QUOT, KC_QUOT),    SE_LABK,             SE_RABK,    SE_LCBR,    SE_RCBR,    SE_LBRC,    SE_RBRC,        
    KC_TRNS,    KC_TRNS,  KC_TRNS,    KC_EXLM,    SE_QUES,             SE_EQL,     SE_PLUS,    SE_ASTR,    SE_MINS,    SE_PIPE,
                                                KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS        
  ),

  [_RAISE] = LAYOUT(
    KC_1,         KC_2,          KC_3,          KC_4,          KC_5,               KC_6,       KC_7,       KC_8,      KC_9,        KC_0,          
    KC_DELETE,    LCTL(KC_Z),    KC_TRNS,    KC_TRNS,    KC_TRNS,            KC_LEFT,    KC_DOWN,    KC_UP,     KC_RIGHT,    KC_TRNS, 
    TG(6),        LCTL(KC_Y),    KC_TRNS,       KC_TRNS,       KC_TRNS,            KC_TRNS,    KC_HOME,    KC_END,    KC_PGUP,     KC_PGDN,
                                                        KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS
  ),

  [_NAV] = LAYOUT(
    KC_TRNS,             KC_MS_BTN1,    KC_MS_UP,       KC_MS_BTN2,     KC_TRNS,                 KC_TRNS,    KC_TRNS,    KC_MS_WH_UP,      KC_MS_BTN3,       KC_TRNS,
    KC_MS_ACCEL1,        KC_TRNS,       KC_MS_LEFT,     KC_MS_DOWN,     KC_MS_RIGHT,             KC_TRNS,    KC_TRNS,    KC_MS_WH_LEFT,    KC_MS_WH_DOWN,    KC_MS_WH_RIGHT,
    KC_MS_ACCEL2,        KC_TRNS,       KC_MS_ACCEL0,   KC_MS_ACCEL1,   KC_MS_ACCEL2,            KC_TRNS,    KC_TRNS,    KC_MS_BTN4,       KC_MS_BTN5,       KC_TRNS, 
                                                                    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS
  ),

  [_FUNCTION] = LAYOUT(
    KC_F1,      KC_F2,      KC_F3,      KC_F4,      KC_F5,              KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,         
    KC_F11,     KC_F12,     KC_TRNS,    KC_TRNS,    KC_TRNS,            KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,
    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,            KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, QK_BOOT, 
                                    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS
  )
};

