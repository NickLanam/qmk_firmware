#include QMK_KEYBOARD_H
#include "version.h"
#include "keymap_korean.h"

#define MOON_LED_LEVEL LED_LEVEL

enum custom_keycodes {
  RGB_SLD = ML_SAFE_RANGE,
  MC_KVM1,
  MC_KVM2,
};

enum layer_names {
  BASE,
  GAME,
  SYM_NUM,
  MOU_NAV,
  NUMPAD,
  BOARD_CTRL,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  /*
   * Base layer: typing normally
   * TODO: Fill this out and make one for the other layers too
   *
   *                      ┌──────┐                                                ┌──────┐
   *               ┌──────┤      ├──────┐                                  ┌──────┤      ├──────┐
   * ┌──────┬──────┤      ├──────┤      ├──────┬──────┐      ┌──────┬──────┤      ├──────┤      ├──────┬──────┐
   * |      │      ├──────┤      ├──────┤      │      │      │      │      ├──────┤      ├──────┤      │      │
   * ├──────┼──────┤      ├──────┤      ├──────┼──────┤      ├──────┼──────┤      ├──────┤      ├──────┼──────┤
   * │      │      ├──────┤      ├──────┤      │      │      │      │      ├──────┤      ├──────┤      │      │
   * ├──────┼──────┤      ├──────┤      ├──────┼──────┤      ├──────┼──────┤      ├──────┤      ├──────┼──────┤
   * │      │      ├──────┤      ├──────┤      │      │      │      │      ├──────┤      ├──────┤      │      │
   * ├──────┼──────┤      ├──────┤      ├──────┼──────┘      └──────┼──────┤      ├──────┤      ├──────┼──────┤
   * │      │      ├──────┤      ├──────┤      │                    │      ├──────┤      ├──────┤      │      │
   * ├──────┼──────┤      ├──────┤      ├──────┘                    └──────┤      ├──────┤      ├──────┼──────┤
   * │      │      ├──────┘      └──────┘                                  └──────┘      └──────┤      │      │
   * └──────┴──────┘                      ┌───────┐              ┌───────┐                      └──────┴──────┘
   *                                      │       │              │       │
   *                                      ├───┬───┼───┐      ┌───┼───┬───┤
   *                                      │   │   │   │      │   │   │   │
   *                                      └───┴───┴───┘      └───┴───┴───┘
   */
  [BASE] = LAYOUT_moonlander(
    TT(5),          KC_F1,          KC_F2,          KC_F3,          KC_F4,          KC_F5,          KC_LCBR,                                        KC_RCBR,        KC_F6,          KC_F7,          KC_F8,          KC_F9,          KC_F10,         TT(4),          
    KC_MINUS,       KC_Q,           KC_W,           KC_E,           KC_R,           KC_T,           KC_LBRACKET,                                    KC_RBRACKET,    KC_Y,           KC_U,           KC_I,           KC_O,           KC_P,           KC_EQUAL,       
    KC_BSPACE,      KC_A,           LSFT_T(KC_S),   LGUI_T(KC_D),   KC_F,           KC_G,           KC_LPRN,                                        KC_RPRN,        KC_H,           KC_J,           RGUI_T(KC_K),   RSFT_T(KC_L),   KC_SCOLON,      KC_DELETE,      
    KC_LSHIFT,      LCTL_T(KC_Z),   KC_X,           KC_C,           KC_V,           KC_B,                                                                           KC_N,           KC_M,           KC_COMMA,       KC_DOT,         RCTL_T(KC_SLASH),KC_RSHIFT,      
    KC_LCTRL,       KC_LALT,        KC_LGUI,        KC_F11,         LALT_T(KC_QUOTE),               KC_TAB,                                         KC_ESCAPE,                      LALT_T(KC_GRAVE),KC_F12,        KC_RGUI,        KC_RALT,        KC_RCTRL,       
                                                                    LT(2,KC_SPACE), LT(3,KC_ENTER), TT(2),                                          TT(3),          LT(3,KC_ENTER), LT(2,KC_SPACE)
  ),
  [GAME] = LAYOUT_moonlander(
    _______,        _______,        _______,        _______,        _______,        _______,        _______,                                        _______,        _______,        _______,        _______,        _______,        _______,        _______,        
    KC_TAB,         _______,        _______,        _______,        _______,        _______,        _______,                                        _______,        _______,        _______,        _______,        _______,        _______,        _______,        
    _______,        _______,        KC_S,           KC_D,           KC_F,           _______,        _______,                                        _______,        _______,        KC_J,           KC_K,           KC_L,           _______,        _______,        
    _______,        KC_Z,           _______,        _______,        _______,        _______,                                                                        _______,        _______,        _______,        _______,        KC_SLASH,       _______,        
    _______,        _______,        _______,        _______,        KC_LALT,                        KC_MINUS,                                       _______,                        KC_LALT,        _______,        _______,        _______,        _______,        
                                                                    KC_SPACE,       KC_ENTER,       _______,                                        _______,        KC_ENTER,       KC_SPACE
  ),
  [SYM_NUM] = LAYOUT_moonlander(
    TO(0),          XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,        KC_AUDIO_MUTE,                                  KC_MEDIA_PREV_TRACK,XXXXXXX,        KC_NUMLOCK,     KC_KP_SLASH,    KC_KP_ASTERISK, KC_KP_MINUS,    _______,        
    _______,        KC_EXLM,        KC_AT,          KC_HASH,        KC_DLR,         XXXXXXX,        KC_AUDIO_VOL_UP,                                KC_MEDIA_NEXT_TRACK,XXXXXXX,        KC_7,           KC_8,           KC_9,           KC_KP_PLUS,     _______,        
    _______,        KC_PERC,        KC_CIRC,        KC_AMPR,        KC_ASTR,        KC_PIPE,        KC_AUDIO_VOL_DOWN,                                                                KC_MEDIA_PLAY_PAUSE,XXXXXXX,        KC_4,           KC_5,           KC_6,           KC_KP_EQUAL,    _______,        
    _______,        KC_MINUS,       KC_UNDS,        KC_EQUAL,       KC_PLUS,        KC_BSLASH,                                      XXXXXXX,        KC_1,           KC_2,           KC_3,           XXXXXXX,        _______,        
    _______,        MC_KVM1,        MC_KVM2,        XXXXXXX,        XXXXXXX,        _______,                                                                                                        _______,        KC_0,           KC_KP_DOT,      KC_KP_ENTER,    XXXXXXX,        _______,        
    _______,        _______,        _______,                        _______,        _______,        KC_TRANSPARENT
  ),
  [MOU_NAV] = LAYOUT_moonlander(
    TO(0),          KC_MS_ACCEL0,   KC_MS_ACCEL1,   KC_MS_ACCEL2,   XXXXXXX,        XXXXXXX,        KC_AUDIO_MUTE,                                  KC_MEDIA_PREV_TRACK,KC_PAUSE,       KC_PSCREEN,     KC_INSERT,      KC_SCROLLLOCK,  _______,        _______,        
    _______,        KC_MS_WH_LEFT,  KC_MS_WH_DOWN,  KC_MS_WH_UP,    KC_MS_WH_RIGHT, XXXXXXX,        KC_AUDIO_VOL_UP,                                KC_MEDIA_NEXT_TRACK,XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,        _______,        _______,        
    KC_CAPSLOCK,    KC_MS_LEFT,     KC_MS_DOWN,     KC_MS_UP,       KC_MS_RIGHT,    XXXXXXX,        KC_AUDIO_VOL_DOWN,                                                                KC_MEDIA_PLAY_PAUSE,KC_LEFT,        KC_DOWN,        KC_UP,          KC_RIGHT,       _______,        _______,        
    _______,        KC_MS_BTN1,     KC_MS_BTN2,     KC_MS_BTN3,     KC_MS_BTN4,     KC_MS_BTN5,                                     KC_HOME,        KC_PGDOWN,      KC_PGUP,        KC_END,         _______,        _______,        
    _______,        MC_KVM1,        MC_KVM2,        XXXXXXX,        XXXXXXX,        _______,                                                                                                        _______,        XXXXXXX,        XXXXXXX,        XXXXXXX,        _______,        _______,        
    _______,        _______,        _______,                        _______,        _______,        KC_TRANSPARENT
  ),
  [NUMPAD] = LAYOUT_moonlander(
    TO(0),          _______,        _______,        _______,        _______,        _______,        _______,                                        _______,        _______,        KC_NUMLOCK,     KC_KP_SLASH,    KC_KP_ASTERISK, KC_KP_MINUS,    _______,        
    _______,        _______,        _______,        _______,        _______,        _______,        _______,                                        _______,        _______,        KC_KP_7,        KC_KP_8,        KC_KP_9,        KC_KP_PLUS,     _______,        
    _______,        _______,        _______,        _______,        _______,        _______,        _______,                                                                        _______,        _______,        KC_KP_4,        KC_KP_5,        KC_KP_6,        KC_KP_EQUAL,    _______,        
    _______,        _______,        _______,        _______,        _______,        _______,                                        _______,        KC_KP_1,        KC_KP_2,        KC_KP_3,        XXXXXXX,        _______,        
    _______,        _______,        _______,        _______,        _______,        _______,                                                                                                        _______,        KC_KP_0,        KC_KP_DOT,      KC_KP_ENTER,    XXXXXXX,        _______,        
    _______,        _______,        _______,                        _______,        _______,        _______
  ),
  [BOARD_CTRL] = LAYOUT_moonlander(
    TO(0),          TO(1),          TO(2),          TO(3),          TO(4),          XXXXXXX,        XXXXXXX,                                        WEBUSB_PAIR,    MOON_LED_LEVEL, KC_SYSTEM_POWER,KC_SYSTEM_SLEEP,XXXXXXX,        KC_SYSTEM_WAKE, RESET,          
    XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,                                        XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,        
    RGB_HUI,        RGB_VAI,        RGB_MOD,        RGB_SPI,        TOGGLE_LAYER_COLOR,RGB_SAI,        XXXXXXX,                                                                        MU_MOD,         MU_ON,          AU_ON,          XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,        
    RGB_HUD,        RGB_VAD,        RGB_SLD,        RGB_SPD,        RGB_TOG,        RGB_SAD,                                        MU_OFF,         AU_OFF,         XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,        
    XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,        DYN_MACRO_PLAY1,                                                                                                DYN_MACRO_PLAY2,XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,        
    XXXXXXX,        DYN_REC_START1, DYN_REC_STOP,                   DYN_REC_STOP,   DYN_REC_START2, KC_NO
  ),
};

extern bool g_suspend_state;
extern rgb_config_t rgb_matrix_config;

void keyboard_post_init_user(void) {
  rgb_matrix_enable();
}

// TODO: Define all of these colors. Prettify the layout of the LEDs first though.
#define DIMWHITE {0, 0, 119};

const uint8_t PROGMEM ledmap[][DRIVER_LED_TOTAL][3] = {
    [BASE] = { {0,0,119}, {0,0,119}, {0,0,119}, {0,0,119}, {0,0,119}, {0,0,119}, {0,0,119}, {0,0,119}, {0,0,119}, {0,0,119}, {0,0,119}, {0,0,119}, {0,0,119}, {0,0,119}, {0,0,119}, {0,0,119}, {0,0,119}, {0,0,119}, {0,0,119}, {0,0,119}, {0,0,119}, {0,0,119}, {0,0,119}, {0,0,119}, {0,0,119}, {0,0,119}, {0,0,119}, {0,0,119}, {0,0,119}, {0,0,119}, {0,0,119}, {0,0,119}, {0,0,119}, {0,0,119}, {0,0,119}, {0,0,119}, {0,0,119}, {0,0,119}, {0,0,119}, {0,0,119}, {0,0,119}, {0,0,119}, {0,0,119}, {0,0,119}, {0,0,119}, {0,0,119}, {0,0,119}, {0,0,119}, {0,0,119}, {0,0,119}, {0,0,119}, {0,0,119}, {0,0,119}, {0,0,119}, {0,0,119}, {0,0,119}, {0,0,119}, {0,0,119}, {0,0,119}, {0,0,119}, {0,0,119}, {0,0,119}, {0,0,119}, {0,0,119}, {0,0,119}, {0,0,119}, {0,0,119}, {0,0,119}, {0,0,119}, {0,0,119}, {0,0,119}, {0,0,119} },

    [GAME] = { {146,174,197}, {146,174,197}, {146,174,197}, {146,174,197}, {146,174,197}, {146,174,197}, {146,174,197}, {146,174,197}, {146,174,197}, {146,174,197}, {146,174,197}, {146,174,197}, {146,174,197}, {146,174,197}, {146,174,197}, {146,174,197}, {146,174,197}, {146,174,197}, {146,174,197}, {146,174,197}, {146,174,197}, {146,174,197}, {146,174,197}, {146,174,197}, {146,174,197}, {146,174,197}, {146,174,197}, {146,174,197}, {146,174,197}, {146,174,197}, {146,174,197}, {146,174,197}, {146,174,197}, {146,174,197}, {146,174,197}, {146,174,197}, {146,174,197}, {146,174,197}, {146,174,197}, {146,174,197}, {146,174,197}, {146,174,197}, {146,174,197}, {146,174,197}, {146,174,197}, {146,174,197}, {146,174,197}, {146,174,197}, {146,174,197}, {146,174,197}, {146,174,197}, {146,174,197}, {146,174,197}, {146,174,197}, {146,174,197}, {146,174,197}, {146,174,197}, {146,174,197}, {146,174,197}, {146,174,197}, {146,174,197}, {146,174,197}, {146,174,197}, {146,174,197}, {146,174,197}, {146,174,197}, {146,174,197}, {146,174,197}, {146,174,197}, {146,174,197}, {146,174,197}, {146,174,197} },

    [SYM_NUM] = { {0,0,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {169,120,255}, {169,120,255}, {169,120,255}, {10,225,255}, {0,0,0}, {169,120,255}, {169,120,255}, {169,120,255}, {10,225,255}, {0,0,0}, {169,120,255}, {169,120,255}, {169,120,255}, {0,0,0}, {0,0,0}, {169,120,255}, {169,120,255}, {169,120,255}, {0,0,0}, {0,0,0}, {0,0,0}, {169,120,255}, {169,120,255}, {146,174,197}, {146,174,197}, {146,174,197}, {146,224,255}, {105,255,255}, {146,224,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {169,120,255}, {169,120,255}, {169,120,255}, {0,0,0}, {0,0,0}, {169,120,255}, {146,224,255}, {146,224,255}, {146,224,255}, {169,120,255}, {169,120,255}, {146,224,255}, {146,224,255}, {146,224,255}, {169,120,255}, {32,176,255}, {146,224,255}, {146,224,255}, {146,224,255}, {146,224,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {146,174,197}, {146,174,197}, {146,174,197}, {146,224,255}, {105,255,255}, {105,255,255}, {0,0,0} },

    [MOU_NAV] = { {0,0,255}, {0,0,0}, {32,176,255}, {0,0,0}, {0,0,0}, {105,255,255}, {85,203,158}, {105,255,255}, {85,203,158}, {10,225,255}, {105,255,255}, {85,203,158}, {105,255,255}, {85,203,158}, {10,225,255}, {105,255,255}, {85,203,158}, {105,255,255}, {85,203,158}, {0,0,0}, {0,0,0}, {85,203,158}, {105,255,255}, {85,203,158}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {85,203,158}, {146,174,197}, {146,174,197}, {146,174,197}, {146,224,255}, {105,255,255}, {105,255,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {32,176,255}, {0,0,0}, {134,255,213}, {134,255,213}, {0,0,0}, {134,255,213}, {0,0,0}, {134,255,213}, {134,255,213}, {0,0,0}, {134,255,213}, {0,0,0}, {134,255,213}, {134,255,213}, {0,0,0}, {134,255,213}, {0,0,0}, {134,255,213}, {134,255,213}, {146,174,197}, {146,174,197}, {146,174,197}, {146,224,255}, {105,255,255}, {146,224,255}, {0,0,0} },

    [NUMPAD] = { {0,0,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {169,120,255}, {169,120,255}, {169,120,255}, {0,0,0}, {0,0,0}, {169,120,255}, {146,224,255}, {146,224,255}, {146,224,255}, {169,120,255}, {169,120,255}, {146,224,255}, {146,224,255}, {146,224,255}, {169,120,255}, {32,176,255}, {146,224,255}, {146,224,255}, {146,224,255}, {146,224,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0} },

    [BOARD_CTRL] = { {0,0,255}, {0,0,0}, {134,255,213}, {134,255,213}, {0,0,0}, {146,174,197}, {0,0,0}, {134,255,213}, {134,255,213}, {0,0,0}, {169,120,255}, {0,0,0}, {134,255,213}, {134,255,213}, {0,0,0}, {105,255,255}, {0,0,0}, {134,255,213}, {134,255,213}, {0,0,0}, {32,176,255}, {0,0,0}, {134,255,213}, {134,255,213}, {0,0,0}, {0,0,0}, {0,0,0}, {134,255,213}, {134,255,213}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,255,255}, {10,225,255}, {85,203,158}, {0,255,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {85,203,158}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,255,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,255,255}, {0,0,0}, {134,255,213}, {134,255,213}, {0,0,0}, {32,176,255}, {0,0,0}, {134,255,213}, {134,255,213}, {0,255,255}, {0,0,0}, {134,255,213}, {0,0,0}, {0,255,255}, {10,225,255}, {85,203,158} },

};

void set_layer_color(int layer) {
  for (int i = 0; i < DRIVER_LED_TOTAL; i++) {
    HSV hsv = {
      .h = pgm_read_byte(&ledmap[layer][i][0]),
      .s = pgm_read_byte(&ledmap[layer][i][1]),
      .v = pgm_read_byte(&ledmap[layer][i][2]),
    };
    if (!hsv.h && !hsv.s && !hsv.v) {
        rgb_matrix_set_color( i, 0, 0, 0 );
    } else {
        RGB rgb = hsv_to_rgb( hsv );
        float f = (float)rgb_matrix_config.hsv.v / UINT8_MAX;
        rgb_matrix_set_color( i, f * rgb.r, f * rgb.g, f * rgb.b );
    }
  }
}

void rgb_matrix_indicators_user(void) {
  if (g_suspend_state || keyboard_config.disable_layer_led) { return; }
  switch (biton32(layer_state)) {
    case 0:
      set_layer_color(0);
      break;
    case 1:
      set_layer_color(1);
      break;
    case 2:
      set_layer_color(2);
      break;
    case 3:
      set_layer_color(3);
      break;
    case 4:
      set_layer_color(4);
      break;
    case 5:
      set_layer_color(5);
      break;
   default:
    if (rgb_matrix_get_flags() == LED_FLAG_NONE)
      rgb_matrix_set_color_all(0, 0, 0);
    break;
  }
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case MC_KVM1:
      if (record->event.pressed) {
        SEND_STRING(SS_TAP(X_SCROLLLOCK) SS_DELAY(150) SS_TAP(X_SCROLLLOCK) SS_DELAY(150) SS_TAP(X_1));

      }
      break;
    case MC_KVM2:
      if (record->event.pressed) {
        SEND_STRING(SS_TAP(X_SCROLLLOCK) SS_DELAY(150) SS_TAP(X_SCROLLLOCK) SS_DELAY(150) SS_TAP(X_2));

      }
      break;
    case RGB_SLD:
      if (record->event.pressed) {
        rgblight_mode(1);
      }
      return false;
  }
  return true;
}