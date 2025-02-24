#pragma once
#include QMK_KEYBOARD_H


#define ___V___ KC_TRNS // clearly show that this is a transparent key
#define _EMPTY_ _______ // clearly show that this is a key that can be used for something new


// My own keycodes
enum UserspaceCustomKeycodes {
  PV_ = SAFE_RANGE,

  PV_VRSN, // print firmware version
  PV_MAKE, // print the make command of the keyboard

  PV_TEST, // for quick testing purposes

  PV_SAFE_RANGE, // used for extra keycodes in individual keymaps
};


enum Layers {
    LR_QWERTY = 0,
    LR_SYMBOL, // symbols layer (!, @, #, etc)
    LR_SYSCTL, // system control layer (music, volume, arrows, etc)
    LR_KBCTL,  // keyboard control (version, make, flash, etc)
    LR_NUMBER, // number layer (numpad)
};

// Layer switchers
#define BASE    TO(LR_BASE)
#define QWERTY  TO(LR_QWERTY)

#define SYMBOL  MO(LR_SYMBOL)
#define SYSCTL  MO(LR_SYSCTL)
#define KBCTL   MO(LR_KBCTL)
#define NUMBER  MO(LR_NUMBER)


// custom keys
#define PV_TAB_NUM LT(LR_NUMBER, KC_TAB) // tap: tab, hold: number layer
#define PV_ESCC  CTL_T(KC_ESC) // tap: esc, hold: ctrl
#define PV_LOCK  LCTL(LGUI(KC_Q)) // lock computer


#define LAYOUT_wrapper(...)             LAYOUT(__VA_ARGS__) // this makes the below definitions work, otherwise i get arg length errors.
#define LAYOUT_split_3x6_3_wrapper(...) LAYOUT_split_3x6_3(__VA_ARGS__)

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

// Symbols
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

#define _________________SYMBOL_R1_________________  KC_BSLS, _EMPTY_, KC_GRV , _EMPTY_, _EMPTY_
#define _________________SYMBOL_R2_________________  KC_EQL , KC_AMPR, KC_QUOT, KC_DQUO, KC_PIPE
#define _________________SYMBOL_R3_________________  KC_ASTR, KC_TILD, KC_LABK, KC_RABK, KC_SLSH

// System Control
// ┌─────┬─────┬─────┬─────┬─────┐   ┌─────┬─────┬─────┬─────┬─────┐
// │     │     │     │     │FLASH│   │MUTE │HOME │  ↑ │ END │LOCK │
// ├─────┼─────┼─────╆━━━━━╅─────┤   ├─────╆━━━━━╅─────┼─────┼─────┤
// │     │     │     ┃     ┃ RGB │   │VOLUP┃  ← ┃  ↓ │  → │SLEEP│
// ├─────┼─────┼─────╄━━━━━╃─────┤   ├─────╄━━━━━╃─────┼─────┼─────┤
// │     │     │     │VRSN │MAKE │   │VOLDN│MPREV│MPLAY│MNEXT│ PWR │
// └─────┴─────┴─────┴─────┴─────┘   └─────┴─────┴─────┴─────┴─────┘
#define _________________SYSCTL_L1_________________  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, QK_BOOT
#define _________________SYSCTL_L2_________________  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, RGB_TOG
#define _________________SYSCTL_L3_________________  XXXXXXX, XXXXXXX, XXXXXXX, PV_VRSN, PV_MAKE

#define _________________SYSCTL_R1_________________  KC_MUTE , KC_HOME , KC_UP   , KC_END , PV_LOCK
#define _________________SYSCTL_R2_________________  KC_VOLU , KC_LEFT , KC_DOWN , KC_RGHT, KC_SLEP
#define _________________SYSCTL_R3_________________  KC_VOLD , KC_MPRV , KC_MPLY , KC_MNXT, KC_PWR

// Number
// ┌─────┬─────┬─────┬─────┬─────┐   ┌─────┬─────┬─────┬─────┬─────┐
// │     │     │     │     │     │   |     │  7  │  8  │  9  │     │
// ├─────┼─────┼─────╆━━━━━╅─────┤   ├─────╆━━━━━╅─────┼─────┼─────┤
// │     │     │     ┃     ┃     │   |     ┃  4  ┃  5  │  6  │     │
// ├─────┼─────┼─────╄━━━━━╃─────┤   ├─────╄━━━━━╃─────┼─────┼─────┤
// │     │     │     │     │     │   │     │  1  │  2  │  3  │  .  │
// └─────┴─────┴─────┴─────┴─────┘   └─────┴─────┴─────┴─────┴─────┘
#define _________________NUMBER_L1_________________  _EMPTY_, _EMPTY_, _EMPTY_, _EMPTY_, _EMPTY_
#define _________________NUMBER_L2_________________  _EMPTY_, _EMPTY_, _EMPTY_, _EMPTY_, _EMPTY_
#define _________________NUMBER_L3_________________  _EMPTY_, _EMPTY_, _EMPTY_, _EMPTY_, _EMPTY_

#define _________________NUMBER_R1_________________  _EMPTY_, KC_7, KC_8, KC_9, _EMPTY_
#define _________________NUMBER_R2_________________  _EMPTY_, KC_4, KC_5, KC_6, _EMPTY_
#define _________________NUMBER_R3_________________  _EMPTY_, KC_1, KC_2, KC_3, KC_DOT

// F keys
// ┌─────┬─────┬─────┬─────┬─────┐   ┌─────┬─────┬─────┬─────┬─────┐
// │ F1  │ F2  │ F3  │ F4  │ F5  │   │ F6  │ F7  │ F8  │ F9  │ F10 │
// └─────┴─────┴─────┴─────┴─────┘   └─────┴─────┴─────┴─────┴─────┘
#define ______________________F_L__________________  KC_F1, KC_F2, KC_F3, KC_F4, KC_F5
#define ______________________F_R__________________  KC_F6, KC_F7, KC_F8, KC_F9, KC_F10

// QWERTY with mods
// ┌───────┬───────┬───────┲━━━━━━━┱───────┐   ┌───────┲━━━━━━━┱───────┬───────┬───────┐
// │ ctl/A │ sft/S │ cmd/D ┃ opt/F ┃   G   │   │   H   ┃ opt/J ┃ cmd/K │ sft/L │ ctl/; │
// └───────┴───────┴───────┺━━━━━━━┹───────┘   └───────┺━━━━━━━┹───────┴───────┴───────┘
// #define _____________MOD_QWERTY_L2_________________  CTL_T(KC_A), SFT_T(KC_S), GUI_T(KC_D), ALT_T(KC_F),       KC_G
#define _____________MOD_QWERTY_L2_________________        KC_A ,       KC_S ,       KC_D , ALT_T(KC_F),       KC_G
#define _____________MOD_QWERTY_R2_________________        KC_H , ALT_T(KC_J), GUI_T(KC_K), SFT_T(KC_L), CTL_T(KC_SCLN)




/// game/regular mode
/// isaac mode
