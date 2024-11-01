#pragma once
#include QMK_KEYBOARD_H


#define ___V___ KC_TRNS // clearly show that this is a transparent key
#define _EMPTY_ _______ // clearly show that this is a key that can be used for something new


enum Layer {
    LR_BASE = 0, /// needed?

    LR_QWERTY,
    LR_SYMBOL, // symbols layer (!, @, #, etc)
    LR_SYSCTL, // system control layer (music, volume, arrows, etc)
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
