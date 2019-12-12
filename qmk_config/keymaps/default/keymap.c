#include QMK_KEYBOARD_H
#include "keymap_german.h"

extern keymap_config_t keymap_config;

// Keymap Layers

#define _BASE		0
#define _NUMBERS	1

// Defines for task-manager etc.
#define CALTDEL	LCTL(LALT(KC_DEL))
#define TSKMGR	LCTL(LSFT(KC_ESC))

#define KC_P00	(SAFE_RANGE + 0)
#define KC_00	(SAFE_RANGE + 1)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Base
 * ,---------------------------------.
 * |  NL  |   /  |   *  |  =   | ENCV |
 * |------+------|------|------+------|
 * |   7  |   8  |   9  |  -   |      |
 * |------+------|------|------+------|
 * |   4  |   5  |   6  |  +   | ENCH |
 * |------+------|------|------+------|
 * |   1  |   2  |   3  |  ENT |      |
 * |------+------|------|------+------|
 * |   0  |  00  |   .  |      |      |
 * `----------------------------------'
 */
[_BASE] = LAYOUT( \
	KC_NLCK,		KC_PSLS,	KC_PAST,	KC_PEQL,		KC_MS_BTN1,	\
    KC_P7,     		KC_P8,		KC_P9,		KC_PMNS,		KC_NO,		\
	KC_P4,     		KC_P5,		KC_P6,		KC_PPLS,		KC_MS_BTN2,	\
	KC_P1,     		KC_P2,		KC_P3,		KC_PENT,		KC_NO,		\
	KC_P0,   		KC_P00,		KC_PDOT,	KC_NO,			KC_NO		\
),
/* Numbers
	Same as Base, but with normal Numbers instead of Numblock
*/

[_NUMBERS] = LAYOUT( \
	_______,		DE_SLSH,	DE_ASTR,	DE_EQL,			_______,	\
    KC_7,     		KC_8,		KC_9,		DE_MINS,		KC_NO,		\
	KC_4,     		KC_5,		KC_6,		DE_PLUS,		_______,	\
	KC_1,     		KC_2,		KC_3,		KC_ENT,			KC_NO,		\
	KC_0,   		KC_00,		DE_DOT,		KC_NO,			KC_NO		\
)
};

// Combos

enum combos {
	CMB_RESET,
	CMB_LAYER_0,
	CMB_LAYER_1
};

const uint16_t PROGMEM combo_reset[]	= {KC_NLCK, KC_KP_EQUAL, COMBO_END};
const uint16_t PROGMEM combo_layer_0[]	= {KC_NLCK, KC_1,	COMBO_END};
const uint16_t PROGMEM combo_layer_1[]	= {KC_NLCK, KC_P2,	COMBO_END};


combo_t key_combos[COMBO_COUNT] = {
	[CMB_RESET]	  = COMBO_ACTION(combo_reset),
	[CMB_LAYER_0] = COMBO_ACTION(combo_layer_0),
	[CMB_LAYER_1] = COMBO_ACTION(combo_layer_1),
};

// User Functions

void matrix_init_user(void) {

}

void process_combo_event(uint8_t combo_index, bool pressed) {
  switch(combo_index) {
    case CMB_RESET:
      if (pressed) {
		reset_keyboard();
      }
      break;
	  
	case CMB_LAYER_0:
      if (pressed) {
		layer_move(_BASE);
      }
      break;
	  
	case CMB_LAYER_1:
      if (pressed) {
		layer_move(_NUMBERS);
      }
      break;
  }
}

void encoder_update_user(uint8_t index, bool clockwise) {
  if (index == 0) { /* Top encoder */
    if (clockwise) {
      tap_code(KC_MS_UP);
    } else {
      tap_code(KC_MS_DOWN);
    }
  } else if (index == 1) { /* Bottom encoder */  
    if (clockwise) {
      tap_code(KC_MS_LEFT);
    } else {
      tap_code(KC_MS_RIGHT);
    }
  }
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case KC_P00:
      if (record->event.pressed) {
		SEND_STRING(SS_TAP(X_KP_0) SS_TAP(X_KP_0));
      }
      break;
	case KC_00:
      if (record->event.pressed) {
		SEND_STRING("00");
      }
      break;
  }
  return true;
};

#ifdef OLED_DRIVER_ENABLE
void oled_task_user(void) {
  
  // Host Keyboard Layer Status
  oled_write_P(PSTR("Layer: "), false);
  
  switch (get_highest_layer(layer_state)) {
    case _BASE:
      oled_write_P(PSTR("Default\n"), false);
      break;
    case _NUMBERS:
      oled_write_P(PSTR("Numbers\n"), false);
      break;
    default:
      oled_write_ln_P(PSTR("Undefined"), false);
  }

  // Host Keyboard LED Status
  uint8_t led_usb_state = host_keyboard_leds();
  oled_write_P(led_usb_state & (1<<USB_LED_NUM_LOCK) ? PSTR("NUMLCK ") : PSTR("       "), false);
  oled_write_P(led_usb_state & (1<<USB_LED_CAPS_LOCK) ? PSTR("CAPLCK ") : PSTR("       "), false);
  oled_write_P(led_usb_state & (1<<USB_LED_SCROLL_LOCK) ? PSTR("SCRLCK ") : PSTR("       "), false);
}
#endif