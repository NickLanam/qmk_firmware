#include QMK_KEYBOARD_H
#include "version.h"
#include "keymap_korean.h"

#define MOON_LED_LEVEL LED_LEVEL
#define TG_LC TOGGLE_LAYER_COLOR

enum custom_keycodes {
  RGB_SLD = ML_SAFE_RANGE,
  MC_KVM1,
  MC_KVM2,
};

enum layer_names {
  LAYER_BASE = 0,
  LAYER_GAME,
  LAYER_SYM_NUM,
  LAYER_MOU_NAV,
  LAYER_NUMPAD,
  LAYER_BOARD_CTRL,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  /*
   * Base layer: typing normally
   * TODO: Leverage https://docs.qmk.fm/#/feature_rawhid?id=raw-hid somehow. Could switch game layer on when WoW gains focus and off when it drops for instance.
   */
  [LAYER_BASE] = LAYOUT_moonlander(
    KC_ESC,         KC_F1,          KC_F2,          KC_F3,          KC_F4,          KC_F5,          KC_LCBR,                        KC_RCBR,        KC_F6,          KC_F7,          KC_F8,          KC_F9,          KC_F10,         KC_MINUS,          
    KC_TAB,         KC_Q,           KC_W,           KC_E,           KC_R,           KC_T,           KC_LBRACKET,                    KC_RBRACKET,    KC_Y,           KC_U,           KC_I,           KC_O,           KC_P,           KC_EQUAL,       
    KC_BSPACE,      KC_A,           LSFT_T(KC_S),   LGUI_T(KC_D),   KC_F,           KC_G,           KC_LPRN,                        KC_RPRN,        KC_H,           KC_J,           RGUI_T(KC_K),   RSFT_T(KC_L),   KC_SCOLON,      KC_DELETE,      
    KC_LSHIFT,      LCTL_T(KC_Z),   KC_X,           KC_C,           KC_V,           KC_B,                                                           KC_N,           KC_M,           KC_COMMA,       KC_DOT,         RCTL_T(KC_SLASH),KC_RSHIFT,      
    KC_LCTRL,       KC_LGUI,        KC_LALT,        KC_F11,         LALT_T(KC_QUOTE),               TO(5),                          TO(4),                          LALT_T(KC_GRAVE),KC_F12,        KC_RALT,        KC_RGUI,        KC_RCTRL,       
                                                                    LT(2,KC_SPACE), LT(3,KC_ENTER), TT(2),                          TT(3),          LT(3,KC_ENTER), LT(2,KC_SPACE)
  ),
  /*
   * Game layer: disables all dual-function behaviors, unmaps meta, enables one-shot hand swapping.
   */
  [LAYER_GAME] = LAYOUT_moonlander(
    _______,        _______,        _______,        _______,        _______,        _______,        TO(0),                          TG(4),          _______,        _______,        _______,        _______,        _______,        _______,        
    _______,        _______,        _______,        _______,        _______,        _______,        SH_OFF,                         SH_OFF,         _______,        _______,        _______,        _______,        _______,        _______,        
    _______,        _______,        KC_S,           KC_D,           KC_F,           _______,        SH_OS,                          SH_OS,          _______,        KC_J,           KC_K,           KC_L,           _______,        _______,        
    _______,        KC_Z,           _______,        _______,        _______,        _______,                                                        _______,        _______,        _______,        _______,        KC_SLASH,       _______,        
    _______,        XXXXXXX,        _______,        _______,        KC_LALT,                        TO(0),                          TO(0),                          KC_LALT,        _______,        _______,        XXXXXXX,        _______,        
                                                                    KC_SPACE,       KC_ENTER,       MO(2),                          MO(3),          KC_ENTER,       KC_SPACE
  ),
  /*
   * Symbols on left hand, numbers on right hand
   */
  [LAYER_SYM_NUM] = LAYOUT_moonlander(
    TO(0),          XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,        KC_MUTE,                        KC_MNXT,        KC_CAPSLOCK,    KC_NUMLOCK,     KC_SLASH,       KC_ASTERISK,    KC_MINUS,       _______,        
    _______,        KC_EXLM,        KC_AT,          KC_HASH,        KC_DLR,         XXXXXXX,        KC_VOLU,                        KC_MPRV,        XXXXXXX,        KC_7,           KC_8,           KC_9,           KC_PLUS,        _______,        
    _______,        KC_PERC,        KC_CIRC,        KC_AMPR,        KC_ASTR,        KC_PIPE,        KC_VOLD,                        KC_MPLY,        XXXXXXX,        KC_4,           KC_5,           KC_6,           KC_EQUAL,       _______,        
    _______,        KC_MINUS,       KC_UNDS,        KC_EQUAL,       KC_PLUS,        KC_BSLASH,                                                      XXXXXXX,        KC_1,           KC_2,           KC_3,           XXXXXXX,        _______,        
    _______,        MC_KVM1,        MC_KVM2,        XXXXXXX,        XXXXXXX,                        _______,                        _______,                        KC_0,           KC_DOT,         KC_ENTER,       XXXXXXX,        _______,        
                                                                    _______,        _______,        _______,                        _______,        _______,        _______
  ),
  /*
   * Mouse on left hand, text navigation on right hand
   */
  [LAYER_MOU_NAV] = LAYOUT_moonlander(
    TO(0),          KC_ACL0,        KC_ACL1,        KC_ACL2,        XXXXXXX,        XXXXXXX,        KC_MUTE,                        KC_MPRV,        KC_PAUSE,       KC_PSCREEN,     KC_INSERT,      KC_SCROLLLOCK,  _______,        _______,        
    _______,        KC_WH_L,        KC_WH_D,        KC_WH_U,        KC_WH_R,        XXXXXXX,        KC_VOLU,                        KC_MNXT,        XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,        _______,        _______,        
    _______,        KC_MS_L,        KC_MS_D,        KC_MS_U,        KC_MS_R,        XXXXXXX,        KC_VOLD,                        KC_MPLY,        KC_LEFT,        KC_DOWN,        KC_UP,          KC_RIGHT,       _______,        _______,        
    _______,        KC_BTN1,        KC_BTN2,        KC_BTN3,        KC_BTN4,        KC_BTN5,                                                        KC_HOME,        KC_PGDOWN,      KC_PGUP,        KC_END,         _______,        _______,        
    _______,        MC_KVM1,        MC_KVM2,        XXXXXXX,        XXXXXXX,                        _______,                        _______,                        XXXXXXX,        XXXXXXX,        XXXXXXX,        _______,        _______,        
                                                                    _______,        _______,        _______,                        _______,        _______,        _______
  ),
  /*
   * Right-hand numpad that uses the actual numpad keycodes
   */
  [LAYER_NUMPAD] = LAYOUT_moonlander(
    TO(0),          _______,        _______,        _______,        _______,        _______,        _______,                        _______,        _______,        KC_NUMLOCK,     KC_KP_SLASH,    KC_KP_ASTERISK, KC_KP_MINUS,    _______,        
    _______,        _______,        _______,        _______,        _______,        _______,        _______,                        _______,        _______,        KC_KP_7,        KC_KP_8,        KC_KP_9,        KC_KP_PLUS,     _______,        
    _______,        _______,        _______,        _______,        _______,        _______,        _______,                        _______,        _______,        KC_KP_4,        KC_KP_5,        KC_KP_6,        KC_KP_EQUAL,    _______,        
    _______,        _______,        _______,        _______,        _______,        _______,                                                        _______,        KC_KP_1,        KC_KP_2,        KC_KP_3,        XXXXXXX,        _______,        
    _______,        _______,        _______,        _______,        _______,                        _______,                        _______,                        KC_KP_0,        KC_KP_DOT,      KC_KP_ENTER,    XXXXXXX,        _______,        
                                                                    _______,        _______,        _______,                        _______,        _______,        _______
  ),
  /*
   * Board / system controls: direct layer switch, Moonlander color+audio, bootloader, Oryx, APCI
   */
  [LAYER_BOARD_CTRL] = LAYOUT_moonlander(
    TO(0),          TO(1),          TO(2),          TO(3),          TO(4),          XXXXXXX,        XXXXXXX,                        WEBUSB_PAIR,    MOON_LED_LEVEL, KC_PWR,         KC_SLEP,        XXXXXXX,        KC_WAKE,        RESET,          
    XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,                        XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,        
    RGB_HUI,        RGB_VAI,        RGB_MOD,        RGB_SPI,        TG_LC,          RGB_SAI,        XXXXXXX,                        MU_MOD,         MU_ON,          AU_ON,          XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,        
    RGB_HUD,        RGB_VAD,        RGB_SLD,        RGB_SPD,        RGB_TOG,        RGB_SAD,                                                        MU_OFF,         AU_OFF,         XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,        
    XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,                        DM_PLY1,                        DM_PLY2,                        XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,        
                                                                    XXXXXXX,        DM_REC1,        DM_RSTP,                        DM_RSTP,        DM_REC2,        XXXXXXX
  ),
};

extern bool g_suspend_state;
extern rgb_config_t rgb_matrix_config;

void keyboard_post_init_user(void) {
  rgb_matrix_enable();
}

// Reminder: these colors are in HSV
#define BLACK  {  0,   0,   0}
#define DIM    {  0,   0, 119}
#define WHITE  {  0,   0, 255}
#define RED    {  0, 255, 255}
#define ORANGE { 10, 225, 255}
#define PURPLE {169, 120, 255}
#define BLUE   {146, 224, 255}
#define NAVY   {146, 174, 197}
#define CYAN   {134, 255, 213}
#define YELLOW { 32, 176, 255}
#define LIME   {105, 255, 255}
#define GREEN  { 85, 203, 158}

const uint8_t PROGMEM ledmap[][DRIVER_LED_TOTAL][3] = {
  [LAYER_BASE] = LEDMAP_moonlander(
    DIM,    DIM,    DIM,    DIM,    DIM,    DIM,    DIM,         DIM,    DIM,    DIM,    DIM,    DIM,    DIM,    DIM,    
    DIM,    DIM,    DIM,    DIM,    DIM,    DIM,    DIM,         DIM,    DIM,    DIM,    DIM,    DIM,    DIM,    DIM,    
    DIM,    DIM,    DIM,    DIM,    DIM,    DIM,    DIM,         DIM,    DIM,    DIM,    DIM,    DIM,    DIM,    DIM,    
    DIM,    DIM,    DIM,    DIM,    DIM,    DIM,                         DIM,    DIM,    DIM,    DIM,    DIM,    DIM,    
    DIM,    DIM,    DIM,    DIM,    DIM,            DIM,         DIM,            DIM,    DIM,    DIM,    DIM,    DIM,    
                                    DIM,    DIM,    DIM,         DIM,    DIM,    DIM
  ),

  [LAYER_GAME] = LEDMAP_moonlander(
    NAVY,   NAVY,   NAVY,   NAVY,   NAVY,   NAVY,   NAVY,        NAVY,   NAVY,   NAVY,   NAVY,   NAVY,   NAVY,   NAVY,
    NAVY,   NAVY,   NAVY,   NAVY,   NAVY,   NAVY,   NAVY,        NAVY,   NAVY,   NAVY,   NAVY,   NAVY,   NAVY,   NAVY,
    NAVY,   NAVY,   NAVY,   NAVY,   NAVY,   NAVY,   NAVY,        NAVY,   NAVY,   NAVY,   NAVY,   NAVY,   NAVY,   NAVY,
    NAVY,   NAVY,   NAVY,   NAVY,   NAVY,   NAVY,                        NAVY,   NAVY,   NAVY,   NAVY,   NAVY,   NAVY,
    NAVY,   NAVY,   NAVY,   NAVY,   NAVY,           NAVY,        NAVY,           NAVY,   NAVY,   NAVY,   NAVY,   NAVY,
                                    NAVY,   NAVY,   NAVY,        NAVY,   NAVY,   NAVY
  ),

  [LAYER_SYM_NUM] = LEDMAP_moonlander(
    WHITE, BLACK,  BLACK,  BLACK,   BLACK,  BLACK,  NAVY,        NAVY,   YELLOW, YELLOW, PURPLE, PURPLE, PURPLE, BLACK,    
    BLACK, PURPLE, PURPLE, PURPLE,  PURPLE, BLACK,  NAVY,        NAVY,   BLACK,  BLUE,   BLUE,   BLUE,   PURPLE, BLACK,    
    BLACK, PURPLE, PURPLE, PURPLE,  PURPLE, PURPLE, NAVY,        NAVY,   BLACK,  BLUE,   BLUE,   BLUE,   PURPLE, BLACK,    
    BLACK, PURPLE, PURPLE, PURPLE,  PURPLE, PURPLE,                      BLACK,  BLUE,   BLUE,   BLUE,   BLACK,  BLACK,    
    BLACK, ORANGE, ORANGE, BLACK,   BLACK,          BLACK,       BLACK,          BLUE,   PURPLE, PURPLE, BLACK,  BLACK,    
                                    PURPLE, LIME,   PURPLE,      LIME,   LIME,   PURPLE
  ),

  [LAYER_MOU_NAV] = LEDMAP_moonlander(
    WHITE, LIME,   LIME,   LIME,    BLACK,  BLACK,  NAVY,        NAVY,   CYAN,   CYAN,   CYAN,   YELLOW, BLACK,  BLACK,
    BLACK, GREEN,  GREEN,  GREEN,   GREEN,  BLACK,  NAVY,        NAVY,   BLACK,  BLACK,  BLACK,  BLACK,  BLACK,  BLACK,
    BLACK, LIME,   LIME,   LIME,    LIME,   BLACK,  NAVY,        NAVY,   CYAN,   CYAN,   CYAN,   CYAN,   BLACK,  BLACK,
    BLACK, GREEN,  GREEN,  GREEN,   GREEN,  GREEN,                       CYAN,   CYAN,   CYAN,   CYAN,   BLACK,  BLACK,
    BLACK, ORANGE, ORANGE, BLACK,   BLACK,          BLACK,       BLACK,          BLACK,  BLACK,  BLACK,  BLACK,  BLACK,
                                    PURPLE, LIME,   PURPLE,      LIME,   LIME,   PURPLE
  ),

  [LAYER_NUMPAD] = LEDMAP_moonlander(
    WHITE, BLACK,  BLACK,  BLACK,   BLACK,  BLACK,  BLACK,       BLACK,  BLACK,  YELLOW, PURPLE, PURPLE, PURPLE, BLACK,
    BLACK, BLACK,  BLACK,  BLACK,   BLACK,  BLACK,  BLACK,       BLACK,  BLACK,  BLUE,   BLUE,   BLUE,   PURPLE, BLACK,
    BLACK, BLACK,  BLACK,  BLACK,   BLACK,  BLACK,  BLACK,       BLACK,  BLACK,  BLUE,   BLUE,   BLUE,   PURPLE, BLACK,
    BLACK, BLACK,  BLACK,  BLACK,   BLACK,  BLACK,                       BLACK,  BLUE,   BLUE,   BLUE,   BLACK,  BLACK,
    BLACK, BLACK,  BLACK,  BLACK,   BLACK,          BLACK,       BLACK,          BLUE,   PURPLE, PURPLE, BLACK,  BLACK,
                                    BLACK,  BLACK,  BLACK,       BLACK,  BLACK,  BLACK
  ),

  [LAYER_BOARD_CTRL] = LEDMAP_moonlander(
    WHITE, NAVY,   PURPLE, LIME,    YELLOW, BLACK,  BLACK,       RED,    YELLOW, RED,    RED,    BLACK,  GREEN,  RED,
    BLACK, BLACK,  BLACK,  BLACK,   BLACK,  BLACK,  BLACK,       BLACK,  BLACK,  BLACK,  BLACK,  BLACK,  BLACK,  BLACK,
    CYAN,  CYAN,   CYAN,   CYAN,    CYAN,   CYAN,   BLACK,       CYAN,   CYAN,   CYAN,   BLACK,  BLACK,  BLACK,  BLACK,
    CYAN,  CYAN,   CYAN,   CYAN,    CYAN,   CYAN,                        CYAN,   CYAN,   BLACK,  BLACK,  BLACK,  BLACK,
    BLACK, BLACK,  BLACK,  BLACK,   BLACK,          GREEN,       GREEN,          BLACK,  BLACK,  BLACK,  BLACK,  BLACK,
                                    BLACK,  RED,    ORANGE,      ORANGE, RED,    BLACK
  ),
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