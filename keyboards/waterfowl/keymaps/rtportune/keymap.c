#include QMK_KEYBOARD_H

#define TAPPING_TERM 200

//Left hand home row modifiers
#define HOME_A LCTL_T(KC_A)
#define HOME_S LSFT_T(KC_S)
#define HOME_D LALT_T(KC_D)

//Right hand home row modifiers
#define HOME_SCLN RCTL_T(KC_SCLN)
#define HOME_L RSFT_T(KC_L)
#define HOME_K LALT_T(KC_K)

// Defines names for use in layer keycodes and the keymap
enum layer_names {
    _QWERTY,
    _NAVNUM,
    _SYM,
    _FUNC,
	_GAMING
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

[_QWERTY] = LAYOUT(
	KC_Q,				KC_W,				KC_E,				KC_R,				KC_T,			KC_Y,	KC_U,				KC_I,				KC_O,				KC_P,
	HOME_A,	            HOME_S,	            HOME_D,	            KC_F,	            KC_G,			KC_H,	KC_J,	            HOME_K,	            HOME_L,	            HOME_SCLN,
	KC_Z,				KC_X,				KC_C,				KC_V,				KC_B,			KC_N,	KC_M,				KC_COMM,			KC_DOT,				KC_SLSH,
	KC_1,				KC_LGUI,		    KC_BSPC,		    MO(1),				KC_CAPS,		KC_MPLY,MO(2),				MEH_T(KC_SPC),		KC_ENT,		        KC_4
),

[_NAVNUM] = LAYOUT(
	KC_ESC,		KC_F1,		    KC_F2,			KC_F3,      KC_F4,				KC_7,	    KC_8,	KC_9,		KC_PSCR,	    KC_MINS,
	KC_TAB,	    KC_F5,		    KC_F6,		    KC_F7,	    KC_F8,				KC_4,		KC_5,	KC_6,		KC_INS,			KC_PLUS,
	KC_NO,		KC_F9,			KC_F10,			KC_F11,		KC_F12,				KC_1,		KC_2,	KC_3,		KC_DEL,			KC_ASTR,
	KC_1,		KC_TRNS,	    KC_TRNS,	    KC_TRNS,    KC_CAPS,			KC_NUM,		MO(3),	KC_0,	    KC_DOT,	        KC_4
),

[_SYM] = LAYOUT(
	KC_PERC,	KC_UP,			KC_LBRC,		KC_RBRC,	KC_BSLS,		KC_NO,		KC_NO,		KC_CIRC,	KC_NO,			KC_NO,
	KC_LEFT,	KC_DOWN,		KC_RGHT,		KC_RPRN,	KC_PIPE,		KC_UNDS,	KC_QUOT,	KC_DQT,		KC_TILD,		KC_GRV,
	KC_DLR,		KC_NO,			KC_LCBR,		KC_RCBR,	KC_AMPR,		KC_NO,		KC_NO,		KC_NO,		KC_NO,			KC_NO,
	KC_1,		LT(3,KC_DEL),	LT(1,KC_SPC),	KC_TAB,		KC_CAPS,		KC_NUM,		KC_ESC,		KC_BSPC,	LT(2,KC_ENT),	KC_4
),

[_FUNC] =  LAYOUT(
	KC_NO,	KC_NO,			KC_NO,			KC_NO,	KC_NO,			KC_NO,	KC_F7,	KC_F8,		KC_F9,			TG(4),
	KC_NO,	KC_NO,			KC_NO,			KC_NO,	KC_NO,			KC_NO,	KC_F4,	KC_F5,		KC_F6,			KC_F12,
	QK_BOOT,	KC_NO,			KC_NO,			KC_NO,	KC_NO,			KC_F10,	KC_F1,	KC_F2,		KC_F3,			KC_F13,
	KC_1,	LT(3,KC_DEL),	LT(1,KC_SPC),	KC_TAB,	KC_CAPS,		KC_NUM,	KC_ESC,	KC_BSPC,	LT(2,KC_ENT),	KC_4
),

[_GAMING] = LAYOUT(
	KC_TAB,				KC_Q,				KC_W,				KC_E,				KC_R,			KC_Y,	KC_U,				KC_I,				KC_O,				KC_P,
	KC_LSFT,	        KC_A,	            KC_S,	            KC_D,	            KC_F,			KC_H,	KC_J,	            KC_K,	            KC_L,	            KC_SCLN,
	KC_LCTL,		    KC_Z,				KC_X,				KC_C,				KC_V,			KC_N,	KC_M,				KC_COMM,			KC_DOT,				KC_SLSH,
	KC_LCTL,			KC_LGUI,		    KC_SPC,		        KC_LALT,		    KC_CAPS,		KC_NUM,	MO(1),				MEH_T(KC_SPC),		KC_ENT,		        TG(4)
),
};

//Combo section
const uint16_t PROGMEM openParenCombo[] = {KC_Y, KC_U, COMBO_END};
const uint16_t PROGMEM closeParenCombo[] = {KC_U, KC_I, COMBO_END};
const uint16_t PROGMEM openBraceCombo[] = {KC_H, KC_J, COMBO_END};
const uint16_t PROGMEM closeBraceCombo[] = {KC_J, HOME_K, COMBO_END};
const uint16_t PROGMEM openBracketCombo[] = {KC_N, KC_M, COMBO_END};
const uint16_t PROGMEM closeBracketCombo[] = {KC_M, KC_COMM, COMBO_END};
const uint16_t PROGMEM dashCombo[] = {KC_R, KC_T, COMBO_END};
const uint16_t PROGMEM underscoreCombo[] = {KC_F, KC_G, COMBO_END};
const uint16_t PROGMEM equalsCombo[] = {KC_V, KC_B, COMBO_END};
const uint16_t PROGMEM aposCombo[] = {HOME_K, HOME_L, COMBO_END};
const uint16_t PROGMEM quoteCombo[] = {KC_COMM, KC_DOT, COMBO_END};

combo_t key_combos[] = {
	COMBO(openParenCombo, KC_LPRN),
	COMBO(closeParenCombo, KC_RPRN),
	COMBO(openBraceCombo, KC_LCBR),
	COMBO(closeBraceCombo, KC_RCBR),
	COMBO(openBracketCombo, KC_LBRC),
	COMBO(closeBracketCombo, KC_RBRC),
	COMBO(dashCombo, KC_PMNS),
	COMBO(underscoreCombo, KC_UNDS),
	COMBO(equalsCombo, KC_EQL),
	COMBO(aposCombo, KC_QUOT),
	COMBO(quoteCombo, KC_DQUO)
};