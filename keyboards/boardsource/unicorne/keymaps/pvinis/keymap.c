// pvinis unicorne
// qmk compile -kb boardsource/unicorne -km pvinis
// qmk flash -kb boardsource/unicorne -km pvinis

#include "pvinis.h"


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [LR_QWERTY] = LAYOUT_split_3x6_3_wrapper(
        PV_TAB_NUM, _________________QWERTY_L1_________________,    _________________QWERTY_R1_________________, _EMPTY_,
        KC_LCTL   , _________________QWERTY_L2_________________,    _________________QWERTY_R2_________________, KC_ENT ,
        KC_LSFT   , _________________QWERTY_L3_________________,    _________________QWERTY_R3_________________, KC_RSFT,
                                   _EMPTY_, SYMBOL , KC_BSPC,    KC_SPC , SYSCTL , _EMPTY_
    ),

    // [2] = LAYOUT_split_3x6_3(QK_BOOT, , , , , RGB_TOG,  EE_CLR, , , , , CK_TOGG, QK_MAKE
    [LR_SYMBOL] = LAYOUT_split_3x6_3_wrapper(
        ___V___, _________________SYMBOL_L1_________________,    _________________SYMBOL_R1_________________, ___V___,
        ___V___, _________________SYMBOL_L2_________________,    _________________SYMBOL_R2_________________, ___V___,
        ___V___, _________________SYMBOL_L3_________________,    _________________SYMBOL_R3_________________, ___V___,
                                  ___V___ , ___V___, ___V___,    ___V___, ___V___, ___V___
    ),

    [LR_SYSCTL] = LAYOUT_split_3x6_3_wrapper(
        ___V___, _________________SYSCTL_L1_________________,    _________________SYSCTL_R1_________________, ___V___,
        ___V___, _________________SYSCTL_L2_________________,    _________________SYSCTL_R2_________________, ___V___,
        ___V___, _________________SYSCTL_L3_________________,    _________________SYSCTL_R3_________________, ___V___,
                                  ___V___ , ___V___, ___V___,    ___V___, ___V___, ___V___
    ),

    [LR_NUMBER] = LAYOUT_split_3x6_3_wrapper(
        ___V___, _________________NUMBER_L1_________________,    _________________NUMBER_R1_________________, ___V___,
        ___V___, _________________NUMBER_L2_________________,    _________________NUMBER_R2_________________, ___V___,
        ___V___, _________________NUMBER_L3_________________,    _________________NUMBER_R3_________________, ___V___,
                                  ___V___ , ___V___, ___V___,    ___V___, KC_0   , ___V___
    ),
};

