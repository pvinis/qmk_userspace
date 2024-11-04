// pvinis unicorne
// qmk compile -kb boardsource/unicorne -km pvinis
// qmk flash -kb boardsource/unicorne -km pvinis

#include "pvinis.h"

#include "version.h"


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [LR_QWERTY] = LAYOUT_split_3x6_3_wrapper(
        PV_TAB_NUM, _________________QWERTY_L1_________________,    _________________QWERTY_R1_________________, _EMPTY_,
        PV_ESCC   , _________________QWERTY_L2_________________,    _________________QWERTY_R2_________________, KC_ENT ,
        KC_LSFT   , _________________QWERTY_L3_________________,    _________________QWERTY_R3_________________, KC_RSFT,
                                      KC_LGUI, SYMBOL , KC_BSPC,    KC_SPC , SYSCTL , KC_HYPR
    ),

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
        ___V___, KC_F1  , KC_F2  , KC_F3  , KC_F4  , KC_F5  ,  _________________NUMBER_R1_________________, ___V___,
        ___V___, KC_F6  , KC_F7  , KC_F8  , KC_F9  , KC_F10 ,  _________________NUMBER_R2_________________, ___V___,
        ___V___, KC_F11 , KC_F12 , KC_F13 , KC_F14 , KC_F15 ,  _________________NUMBER_R3_________________, ___V___,
                                   ___V___, ___V___, ___V___,    ___V___, KC_0   , KC_DOT
    ),
};


bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
   case PV_VRSN:
		if (record->event.pressed) {
			SEND_STRING(QMK_KEYBOARD "/" QMK_KEYMAP " @ " QMK_VERSION);
		}
		return false;

    case PV_MAKE:
        if (record->event.pressed) {
            SEND_STRING("qmk flash -kb " QMK_KEYBOARD " -km " QMK_KEYMAP);
            SEND_STRING(SS_TAP(X_ENTER));
        }
        return false;

    default:
      return true;
  }
}


float scroll_accumulated_h = 0;
float scroll_accumulated_v = 0;

report_mouse_t pointing_device_task_combined_user(report_mouse_t left_report, report_mouse_t right_report) {
    // Calculate and accumulate scroll values based on mouse movement and divisors
    scroll_accumulated_h += (float)left_report.x / 24.0;
    scroll_accumulated_v += (float)left_report.y / 24.0;

    // Assign integer parts of accumulated scroll values to the mouse report
    left_report.h = (int8_t)scroll_accumulated_h;
    left_report.v = (int8_t)scroll_accumulated_v;

    // Update accumulated scroll values by subtracting the integer parts
    scroll_accumulated_h -= (int8_t)scroll_accumulated_h;
    scroll_accumulated_v -= (int8_t)scroll_accumulated_v;

    // Clear the X and Y values of the mouse report
    left_report.x = 0;
    left_report.y = 0;

    return pointing_device_combine_reports(left_report, right_report);
}
