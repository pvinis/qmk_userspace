// pvinis unicorne
// make boardsource/unicorne:pvinis or qmk compile -kb boardsource/unicorne -km pvinis
// make boardsource/unicorne:pvinis:flash or qmk flash -kb boardsource/unicorne -km pvinis

#include QMK_KEYBOARD_H
#if __has_include("keymap.h")
#    include "keymap.h"
#endif



enum Layer {
    LR_BASE = 0, /// needed?

    LR_QWERTY,
    LR_SYMBOLS, // symbols layer (!, @, #, etc)
    LR_SYSCTL,  // system control layer (music, volume, arrows, etc)
};




#define LAYOUT_split_3x6_3_wrapper(...) LAYOUT_split_3x6_3(__VA_ARGS__) // this makes the below definitions work, otherwise i get arg length errors.

// QWERTY
// ┌─────┬─────┬─────┬─────┬─────┐   ┌─────┬─────┬─────┬─────┬─────┐
// │  Q  │  W  │  E  │  R  │  T  │   │  Y  │  U  │  I  │  O  │  P  │
// ├─────┼─────┼─────╆━━━━━╅─────┤   ├─────╆━━━━━╅─────┼─────┼─────┤
// │  A  │  S  │  D  ┃  F  ┃  G  │   │  H  ┃  J  ┃  K  │  L  │  ;  │
// ├─────┼─────┼─────╄━━━━━╃─────┤   ├─────╄━━━━━╃─────┼─────┼─────┤
// │  Z  │  X  │  C  │  V  │  B  │   │  N  │  M  │  ,  │  .  │  /  │
// └─────┴─────┴─────┴─────┴─────┘   └─────┴─────┴─────┴─────┴─────┘
#define _________________QWERTY_L1_________________  KC_Q   , KC_W   , KC_E   , KC_R   , KC_T
#define _________________QWERTY_L2_________________  KC_A   , KC_S   , KC_D   , KC_F   , KC_G
#define _________________QWERTY_L3_________________  KC_Z   , KC_X   , KC_C   , KC_V   , KC_B

#define _________________QWERTY_R1_________________  KC_Y   , KC_U   , KC_I   , KC_O   , KC_P
#define _________________QWERTY_R2_________________  KC_H   , KC_J   , KC_K   , KC_L   , KC_SCLN
#define _________________QWERTY_R3_________________  KC_N   , KC_M   , KC_COMM, KC_DOT , KC_SLSH


// SYMBOL
// ┌─────┬─────┬─────┬─────┬─────┐   ┌─────┬─────┬─────┬─────┬─────┐
// │  !  │  @  │  {  │  }  │  _  │   |  \  │     │  `  │     │     │
// ├─────┼─────┼─────╆━━━━━╅─────┤   ├─────╆━━━━━╅─────┼─────┼─────┤
// │  #  │  $  │  (  ┃  )  ┃  -  │   |  =  ┃  &  ┃  '  │  "  │     │
// ├─────┼─────┼─────╄━━━━━╃─────┤   ├─────╄━━━━━╃─────┼─────┼─────┤
// │  %  │  ^  │  [  │  ]  │  +  │   │  *  │  ~  │  <  │  >  │  /  │
// └─────┴─────┴─────┴─────┴─────┘   └─────┴─────┴─────┴─────┴─────┘
#define _________________SYMBOL_L1_________________  KC_EXLM, KC_AT  , KC_LCBR, KC_RCBR, KC_UNDS
#define _________________SYMBOL_L2_________________  KC_HASH, KC_DLR , KC_LPRN, KC_RPRN, KC_MINS
#define _________________SYMBOL_L3_________________  KC_PERC, KC_CIRC, KC_LBRC, KC_RBRC, KC_PLUS

#define _________________SYMBOL_R1_________________  KC_BSLS, _______, KC_GRV , _______, _______
#define _________________SYMBOL_R2_________________  KC_EQL , KC_AMPR, KC_QUOT, KC_DQUO, KC_PIPE
#define _________________SYMBOL_R3_________________  KC_ASTR, KC_TILD, KC_LABK, KC_RABK, KC_SLSH




#define ___V___ KC_TRNS
#define _EMPTY_ _______




const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    // [LR_BASE] = LAYOUT_split_3x6_3(
    //     KC_TAB , _______, _______, _______, _______, _______,    _______, _______, _V_V_V_, ___V___, _______, _______,
    //     KC_LCTL, _______, _______, _______, _______, _______,    _______, _______, _______, _______, _______, KC_QUOT,
    //     KC_LSFT, _______, _______, _______, _______, _______,    _______, _______, _______, _______, KC_SLSH,
    //                   KC_ESC, KC_LGUI, MO(1),     KC_SPC, KC_ENT, MO(2), KC_RALT),
    [LR_QWERTY] = LAYOUT_split_3x6_3_wrapper(
        KC_TAB , _________________QWERTY_L1_________________,    _________________QWERTY_R1_________________, _EMPTY_,
        KC_LCTL, _________________QWERTY_L2_________________,    _________________QWERTY_R2_________________, KC_ENT ,
        KC_LSFT, _________________QWERTY_L3_________________,    _________________QWERTY_R3_________________, KC_RSFT,
                                  _EMPTY_ , MO(LR_SYMBOL), KC_BSPC,    KC_SPC , _EMPTY_ , _EMPTY_
    ),

    // [1] = LAYOUT_split_3x6_3(_______, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, _______, _______, KC_EXLM, KC_AT, KC_HASH, KC_DLR, KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______),
    // [2] = LAYOUT_split_3x6_3(QK_BOOT, _______, _______, _______, _______, _______, RGB_VAI, RGB_HUI, RGB_SAI, RGB_MOD, RGB_TOG, _______, EE_CLR, _______, _______, _______, _______, _______, RGB_VAD, RGB_HUD, RGB_SAD, RGB_RMOD, CK_TOGG, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______)
    [LR_SYMBOL] = LAYOUT_split_3x6_3_wrapper(
        ___V___, _________________SYMBOL_L1_________________,    _________________SYMBOL_R1_________________, ___V___,
        ___V___, _________________SYMBOL_L2_________________,    _________________SYMBOL_R2_________________, ___V___,
        ___V___, _________________SYMBOL_L3_________________,    _________________SYMBOL_R3_________________, ___V___,
                                  ___V___ , ___V___, ___V___,    ___V___, ___V___, ___V___
    ),

    [LR_SYSCTL] = LAYOUT_split_3x6_3_wrapper(
        ___V___, _________________SYMBOL_L1_________________,    _________________SYMBOL_R1_________________, ___V___,
        ___V___, _________________SYMBOL_L2_________________,    _________________SYMBOL_R2_________________, ___V___,
        ___V___, _________________SYMBOL_L3_________________,    _________________SYMBOL_R3_________________, ___V___,
                                  ___V___ , ___V___, ___V___,    ___V___, ___V___, ___V___
    ),
};
