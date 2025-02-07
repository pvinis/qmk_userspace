// pvinis unicorne
// qmk compile -kb boardsource/unicorne -km pvinis
// qmk flash -kb boardsource/unicorne -km pvinis

#include "pvinis.h"

// #include "version.h"
// #include "lib/oled.h"



const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [LR_QWERTY] = LAYOUT_split_3x6_3_wrapper(
        PV_TAB_NUM, _________________QWERTY_L1_________________,    _________________QWERTY_R1_________________, KC_F12 ,
        PV_ESCC   , _________________QWERTY_L2_________________,    _________________QWERTY_R2_________________, KC_ENT ,
        KC_LSFT   , _________________QWERTY_L3_________________,    _________________QWERTY_R3_________________, KC_RSFT,
                                      KC_LGUI, SYMBOL , KC_BSPC,    KC_SPC , SYSCTL , KC_HYPR
    ),

    // [2] = LAYOUT_split_3x6_3(QK_BOOT, , , , , RGB_TOG,  EE_CLR, , , , , CK_TOGG, QK_MAKE
    [LR_SYMBOL] = LAYOUT_split_3x6_3_wrapper(
        QK_BOOT, _________________SYMBOL_L1_________________,    _________________SYMBOL_R1_________________, ___V___,
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

report_mouse_t pointing_device_task_user(report_mouse_t mouse_report) {
    // Calculate and accumulate scroll values based on mouse movement and divisors
    scroll_accumulated_h += (float)mouse_report.x / 32.0;
    scroll_accumulated_v -= (float)mouse_report.y / 32.0;

    // Assign integer parts of accumulated scroll values to the mouse report
    mouse_report.h = (int8_t)scroll_accumulated_h;
    mouse_report.v = (int8_t)scroll_accumulated_v;

    // Update accumulated scroll values by subtracting the integer parts
    scroll_accumulated_h -= (int8_t)scroll_accumulated_h;
    scroll_accumulated_v -= (int8_t)scroll_accumulated_v;

    // Clear the X and Y values of the mouse report
    mouse_report.x = 0;
    mouse_report.y = 0;

    return mouse_report;
}


static const char PROGMEM pavlos_text[] = {
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x30, 0x70, 0x70, 0xf0, 0xf0, 0xf0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xfc, 0xfc, 0xfc, 0x18, 0x0c, 0x0c, 0x1c,
	0x3c, 0xfc, 0xf8, 0xc0, 0x00, 0x00, 0x00, 0x38, 0x38, 0x3c, 0x1c, 0x0c, 0x0c, 0x9c, 0xfc, 0xf8,
	0xe0, 0x00, 0x00, 0x00, 0x1c, 0xfc, 0xfc, 0xe0, 0x00, 0x00, 0x80, 0xf8, 0xfc, 0x7c, 0x0c, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0xff, 0xff, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xf0,
	0xf8, 0xfc, 0x1c, 0x0c, 0x0c, 0x1c, 0x3c, 0xf8, 0xf0, 0xc0, 0x00, 0x00, 0x00, 0xf0, 0xf8, 0xfc,
	0x9c, 0x8c, 0x0c, 0x1c, 0x3c, 0x38, 0x30, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0xff, 0xff, 0x60, 0xe0, 0xc0, 0xe0,
	0xf0, 0xff, 0x7f, 0x0f, 0x00, 0x00, 0x18, 0x7e, 0xff, 0xe7, 0xe3, 0xc3, 0xc3, 0x63, 0xff, 0xff,
	0xff, 0x00, 0x00, 0x00, 0x00, 0x01, 0x0f, 0xff, 0xfe, 0xf8, 0xff, 0x3f, 0x07, 0x00, 0x00, 0x00,
	0x00, 0x00, 0xe0, 0xe0, 0xe0, 0xff, 0xff, 0xff, 0xe0, 0xe0, 0xe0, 0x00, 0x00, 0x00, 0x00, 0x1f,
	0x7f, 0xff, 0xe0, 0xe0, 0xc0, 0xe0, 0xf0, 0x7f, 0x3f, 0x0f, 0x00, 0x00, 0x00, 0x70, 0xf1, 0xe3,
	0xe3, 0xc3, 0xc7, 0xe7, 0xfe, 0x7e, 0x38, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x3f, 0x3f, 0x3f, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
};
// https://javl.github.io/image2cpp
bool oled_task_user(void) {
    if (is_keyboard_master()) {
        oled_write_P(PSTR("Nothing to see here yet :)"), false);
    } else {
        // render_layer_state();
        oled_write_raw_P(pavlos_text, sizeof(pavlos_text));
    }

    return false;
}

oled_rotation_t oled_init_user(oled_rotation_t rotation) {
    if (is_keyboard_master()) {
        return rotation;
    } else {
        return OLED_ROTATION_0;
    }
}
