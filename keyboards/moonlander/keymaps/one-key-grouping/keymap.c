#include QMK_KEYBOARD_H
#include "version.h"
#include "keymap_german.h"
#include "keymap_nordic.h"
#include "keymap_french.h"
#include "keymap_spanish.h"
#include "keymap_hungarian.h"
#include "keymap_swedish.h"
#include "keymap_br_abnt2.h"
#include "keymap_canadian_multilingual.h"
#include "keymap_german_ch.h"
#include "keymap_jp.h"
#include "keymap_bepo.h"
#include "keymap_italian.h"
#include "keymap_slovenian.h"
#include "keymap_danish.h"
#include "keymap_norwegian.h"
#include "keymap_portuguese.h"

#define KC_MAC_UNDO LGUI(KC_Z)
#define KC_MAC_CUT LGUI(KC_X)
#define KC_MAC_COPY LGUI(KC_C)
#define KC_MAC_PASTE LGUI(KC_V)
#define KC_PC_UNDO LCTL(KC_Z)
#define KC_PC_CUT LCTL(KC_X)
#define KC_PC_COPY LCTL(KC_C)
#define KC_PC_PASTE LCTL(KC_V)
#define ES_LESS_MAC KC_GRAVE
#define ES_GRTR_MAC LSFT(KC_GRAVE)
#define ES_BSLS_MAC ALGR(KC_6)
#define NO_PIPE_ALT KC_GRAVE
#define NO_BSLS_ALT KC_EQUAL
#define LSA_T(kc) MT(MOD_LSFT | MOD_LALT, kc)
#define BP_NDSH_MAC ALGR(KC_8)

/*
 * Hardware notes:
 * The Moonlander is powered by a Cortex-M4, in the [STM32F303](https://www.st.com/en/microcontrollers-microprocessors/stm32f303.html) family.
 * - TODO: Which one specifically? ZSA probably published that information; the Moonlander is based heavily on the open source Ergodox design.
 * Its RGB matrix uses an [IS31FL3731](http://www.issi.com/WW/pdf/31FL3731.pdf) Audio Modulated Matrix LED Driver.
 * - QMK docs on the matter: https://docs.qmk.fm/#/feature_rgb_matrix - mentions this driver directly!
 */
enum layer_names {
  LAYER_BASE = 0,
  LAYER_LOWER,
  LAYER_RAISE,
  LAYER_ADJUST
};

enum custom_keycodes {
  RGB_SLD = ML_SAFE_RANGE, // RGB Toggle button - turns on/off the entire RGB matrix.
  MC_ARW1, // "Thin" arrow: ->
  MC_ARW2, // "Thick" arrow: =>
  MC_KVM1, // KVM switch 1: Double tap scroll lock, then tap 1.
  MC_KVM2, // KVM switch 1: Double tap scroll lock, then tap 2.
};

/*
 * Things to change (officially beyond Oryx support):
 * - Create layers 4+ for a left-side-only mode. Call DF(4) to activate it and DF(0) to deactivate it.
 *   - Investigate calling DF(4) when the right side is disconnected and DF(0) when it's reconnected.
 * - Investigate two-way OS communication, for things like notifications (with go-to macros) on-keyboard.
 *   - If this is possible, it's also possible to emulate AuraSync for games that can use it.
 * - Use the six status LEDs to indicate layers.
 * - Consider binding more complex macros behind tap dances and chords.
 */

/* ===========================================================
 *  This layout was built in Oryx, then modified by hand here
 *  https://configure.ergodox-ez.com/moonlander/layouts/VYgB4
 * ===========================================================
 */

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  /*
   * Base 0
   *                      ┌──────┐                                                ┌──────┐
   *               ┌──────┤  F3  ├──────┐                                  ┌──────┤ F10  ├──────┐
   * ┌──────┬──────┤  F2  ├──────┤  F4  ├──────┬──────┐      ┌──────┬──────┤  F9  ├──────┤ F11  ├──────┬──────┐
   * │ Tab  │  F1  ├──────┤  E   ├──────┤  F5  │  F6  │      │  F7  │  F8  ├──────┤  I   ├──────┤ F12  │SysRq │
   * ├──────┼──────┤ W    ├──────┤  R   ├──────┼──────┤      ├──────┼──────┤  U   ├──────┤  O   ├──────┼──────┤
   * │ Tab  │  Q   ├──────┤  D   ├──────┤  T   │  `   │      │  '   │  Y   ├──────┤  K   ├──────┤  P   │  ⌫   │
   * ├──────┼──────┤ S    ├──────┤  F   ├──────┼──────┤      ├──────┼──────┤  J   ├──────┤  L   ├──────┼──────┤
   * │ Esc  │  A   ├──────┤  C   ├──────┤  G   │  ~   │      │  "   │  H   ├──────┤  ,   ├──────┤  ;   │  ⏎   │
   * ├──────┼──────┤ X    ├──────┤  V   ├──────┼──────┘      └──────┼──────┤  M   ├──────┤  .   ├──────┼──────┤
   * │ ( ⇧  │  Z   ├──────┤L-alt ├──────┤  B   │                    │  N   ├──────┤  ◀   ├──────┤  /   │ ) ⇧  │
   * ├──────┼──────┤L-Meta├──────┤[ LT→1├──────┘                    └──────┤] LT→2├──────┤  ▼   ├──────┼──────┤
   * │L-Ctrl│Layout├──────┘      └──────┘                                  └──────┘      └──────┤  ▲   │  ▶   │
   * └──────┴──────┘                      ┌───────┐              ┌───────┐                      └──────┴──────┘
   *                                      │M1Play │              │M2Play │
   *                                      ├───┬───┼───┐      ┌───┼───┬───┤
   *                                      │Spc│ { │ < │      │ > │ } │Spc│
   *                                      └───┴───┴───┘      └───┴───┴───┘
   */
  [LAYER_BASE] = LAYOUT_moonlander(
    KC_TAB,         KC_F1,          KC_F2,          KC_F3,          KC_F4,          KC_F5,          KC_F6,                          KC_F7,          KC_F8,          KC_F9,          KC_F10,         KC_F11,         KC_F12,         KC_PSCREEN,
    KC_TAB,         KC_Q,           KC_W,           KC_E,           KC_R,           KC_T,           KC_GRAVE,                       KC_QUOTE,       KC_Y,           KC_U,           KC_I,           KC_O,           KC_P,           KC_BSPACE,
    KC_ESCAPE,      KC_A,           KC_S,           KC_D,           KC_F,           KC_G,           KC_TILD,                        LSFT(KC_QUOTE), KC_H,           KC_J,           KC_K,           KC_L,           KC_SCOLON,      KC_ENTER,
    KC_LSPO,        KC_Z,           KC_X,           KC_C,           KC_V,           KC_B,                                                           KC_N,           KC_M,           KC_COMMA,       KC_DOT,         KC_SLASH,       KC_RSPC,
    KC_LCTRL,       LGUI(KC_SPACE), KC_LGUI,        KC_LALT,        LT(1,KC_LBRACKET),              DYN_MACRO_PLAY1,                DYN_MACRO_PLAY2,                LT(2,KC_RBRACKET),KC_LEFT,      KC_DOWN,        KC_UP,          KC_RIGHT,
                                                                    KC_SPACE,       KC_LCBR,        KC_LABK,                        KC_RABK,        KC_RCBR,        KC_SPACE
  ),
  /*
   * Lower 1
   *                      ┌──────┐                                                ┌──────┐
   *               ┌──────┤  3   ├──────┐                                  ┌──────┤  0   ├──────┐
   * ┌──────┬──────┤  2   ├──────┤  4   ├──────┬──────┐      ┌──────┬──────┤  9   ├──────┤  -   ├──────┬──────┐
   * │      │  1   ├──────┤      ├──────┤  5   │  6   │      │  7   │  8   ├──────┤ RCLK ├──────┤  =   │ Ins  │
   * ├──────┼──────┤ MS_U ├──────┤      ├──────┼──────┤      ├──────┼──────┤ MCLK ├──────┤  ->  ├──────┼──────┤
   * │      │      ├──────┤      ├──────┤ M_A0 │      │      │ TG→2 │ LCLK ├──────┤  ▲   ├──────┤  =>  │ Del  │
   * ├──────┼──────┤ MS_D ├──────┤      ├──────┼──────┤      ├──────┼──────┤  ▼   ├──────┤  ▶   ├──────┼──────┤
   * │ Caps │ MS_L ├──────┤ MS_R ├──────┤ M_A1 │      │      │      │  ◀   ├──────┤ PgDn ├──────┤      │      │
   * ├──────┼──────┤      ├──────┤      ├──────┼──────┘      └──────┼──────┤ PgUp ├──────┤ End  ├──────┼──────┤
   * │      │      ├──────┤      ├──────┤ M_A2 │                    │ Home ├──────┤R-Alt ├──────┤Emoji │Unicde│
   * ├──────┼──────┤ KVM2 ├──────┤//////├──────┘                    └──────┤] LT→3├──────┤R-Meta├──────┼──────┤
   * │      │ KVM1 ├──────┘      └──────┘                                  └──────┘      └──────┤ Menu │R-Ctrl│
   * └──────┴──────┘                      ┌───────┐              ┌───────┐                      └──────┴──────┘
   *                                      │       │              │       │
   *                                      ├───┬───┼───┐      ┌───┼───┬───┤
   *                                      │   │   │   │      │   │   │   │
   *                                      └───┴───┴───┘      └───┴───┴───┘
   */
  [LAYER_LOWER] = LAYOUT_moonlander(
    _______,        KC_1,           KC_2,           KC_3,           KC_4,           KC_5,           KC_6,                           KC_7,           KC_8,           KC_9,           KC_0,           KC_MINUS,       KC_EQUAL,       KC_INSERT,
    _______,        _______,        KC_MS_U,        _______,        _______,        KC_ACL0,        _______,                        TG(2),          KC_BTN1,        KC_BTN3,        KC_BTN2,        MC_ARW1,        MC_ARW2,        KC_DELETE,
    KC_CAPSLOCK,    KC_MS_L,        KC_MS_D,        KC_MS_R,        _______,        KC_ACL1,        _______,                        _______,        KC_LEFT,        KC_DOWN,        KC_UP,          KC_RIGHT,       _______,        _______,
    _______,        _______,        _______,        _______,        _______,        KC_ACL2,                                                        KC_HOME,        KC_PGDOWN,      KC_PGUP,        KC_END,         LCTL(LSFT(KC_E)),LCTL(LSFT(KC_U)),
    _______,        MC_KVM1,        MC_KVM2,        _______,        _______,                        _______,                        _______,                        LT(3,KC_RBRACKET),KC_RALT,      KC_RGUI,        KC_APPLICATION, KC_RCTRL,
                                                                    _______,        _______,        _______,                        _______,        _______,        _______
  ),
  /*
   * Raise 2
   *                      ┌──────┐                                                ┌──────┐
   *               ┌──────┤  #   ├──────┐                                  ┌──────┤ num/ ├──────┐
   * ┌──────┬──────┤  @   ├──────┤  $   ├──────┬──────┐      ┌──────┬──────┤      ├──────┤ num* ├──────┬──────┐
   * │      │  !   ├──────┤  &   ├──────┤VolDn │VolUp │      │      │      ├──────┤ num8 ├──────┤ num- │Pause │
   * ├──────┼──────┤  ^   ├──────┤  *   ├──────┼──────┤      ├──────┼──────┤ num7 ├──────┤ num9 ├──────┼──────┤
   * │      │  %   ├──────┤  =   ├──────┤ Prev │ Next │      │      │      ├──────┤ num5 ├──────┤ num+ │ Del  │
   * ├──────┼──────┤  _   ├──────┤  +   ├──────┼──────┤      ├──────┼──────┤ num4 ├──────┤ num6 ├──────┼──────┤
   * │      │  -   ├──────┤  \   ├──────┤ Mute │ Play │      │      │      ├──────┤ num2 ├──────┤numEnt│      │
   * ├──────┼──────┤  ~   ├──────┤  |   ├──────┼──────┘      └──────┼──────┤ num1 ├──────┤ num3 ├──────┼──────┤
   * │      │  `   ├──────┤      ├──────┤      │                    │      ├──────┤ num0 ├──────┤      │      │
   * ├──────┼──────┤ KVM2 ├──────┤[ LT→3├──────┘                    └──────┤//////├──────┤ num. ├──────┼──────┤
   * │      │ KVM1 ├──────┘      └──────┘                                  └──────┘      └──────┤      │      │
   * └──────┴──────┘                      ┌───────┐              ┌───────┐                      └──────┴──────┘
   *                                      │       │              │       │
   *                                      ├───┬───┼───┐      ┌───┼───┬───┤
   *                                      │   │   │   │      │   │   │   │
   *                                      └───┴───┴───┘      └───┴───┴───┘
   */
  [LAYER_RAISE] = LAYOUT_moonlander(
    _______,        KC_EXLM,        KC_AT,          KC_HASH,        KC_DLR,         KC_AUDIO_VOL_DOWN,KC_AUDIO_VOL_UP,              _______,        _______,        _______,        KC_KP_SLASH,    KC_KP_ASTERISK, KC_KP_MINUS,    KC_PAUSE,
    _______,        KC_PERC,        KC_CIRC,        KC_AMPR,        KC_ASTR,        KC_MEDIA_PREV_TRACK,KC_MEDIA_NEXT_TRACK,        _______,        _______,        KC_KP_7,        KC_KP_8,        KC_KP_9,        KC_KP_PLUS,     KC_DELETE,
    KC_CAPSLOCK,    KC_MINUS,       KC_UNDS,        KC_EQUAL,       KC_PLUS,        KC_AUDIO_MUTE,  KC_MEDIA_PLAY_PAUSE,            _______,        _______,        KC_KP_4,        KC_KP_5,        KC_KP_6,        KC_KP_ENTER,    _______,
    _______,        KC_GRAVE,       KC_TILD,        KC_BSLASH,      KC_PIPE,        _______,                                                        _______,        KC_KP_1,        KC_KP_2,        KC_KP_3,        _______,        _______,
    _______,        MC_KVM1,        MC_KVM2,        _______,        LT(3,KC_LBRACKET),              _______,                        _______,                        _______,        KC_KP_0,        KC_KP_DOT,      _______,        _______,
                                                                    _______,        _______,        _______,                        _______,        _______,        _______
  ),
  /*
   * Adjust 3
   *                      ┌──────┐                                                ┌──────┐
   *               ┌──────┤      ├──────┐                                  ┌──────┤      ├──────┐
   * ┌──────┬──────┤      ├──────┤      ├──────┬──────┐      ┌──────┬──────┤      ├──────┤      ├──────┬──────┐
   * │Reset │      ├──────┤      ├──────┤      │      │      │      │      ├──────┤      ├──────┤      │      │
   * ├──────┼──────┤      ├──────┤      ├──────┼──────┤      ├──────┼──────┤      ├──────┤      ├──────┼──────┤
   * │ Oryx │      ├──────┤SndOff├──────┤      │C-A-Bk│      │C-A-Dl│      ├──────┤RGBTgl├──────┤      │      │
   * ├──────┼──────┤SndOn ├──────┤SndTgl├──────┼──────┤      ├──────┼──────┤Lights├──────┤ Dark ├──────┼──────┤
   * │      │      ├──────┤♪ Off ├──────┤      │      │      │      │      ├──────┤StopAn├──────┤Bright│      │
   * ├──────┼──────┤ ♪ On ├──────┤♪ Tgl ├──────┼──────┘      └──────┼──────┤NxtAni├──────┤Slower├──────┼──────┤
   * │      │      ├──────┤      ├──────┤      │                    │      ├──────┤      ├──────┤Faster│      │
   * ├──────┼──────┤ KVM2 ├──────┤//////├──────┘                    └──────┤//////├──────┤      ├──────┼──────┤
   * │      │ KVM1 ├──────┘      └──────┘                                  └──────┘      └──────┤      │      │
   * └──────┴──────┘                      ┌───────┐              ┌───────┐                      └──────┴──────┘
   *                                      │M1Play │              │M2Play │
   *                                      ├───┬───┼───┐      ┌───┼───┬───┤
   *                                      │   │Rc1│Stp│      │Stp│Rc2│   │
   *                                      └───┴───┴───┘      └───┴───┴───┘
   */
  [LAYER_ADJUST] = LAYOUT_moonlander(
    RESET,          _______,        _______,        _______,        _______,         _______,       _______,                        _______,        _______,        _______,         _______,       _______,        _______,        _______,
    WEBUSB_PAIR,    _______,        _______,        _______,        _______,         _______,       LALT(LCTL(KC_BSPACE)),          LALT(LCTL(KC_DELETE)),_______,  _______,         _______,       _______,        _______,        _______,
    _______,        _______,        AU_ON,          AU_OFF,         AU_TOG,          _______,       _______,                        _______,        _______,        RGB_TOG,         TOGGLE_LAYER_COLOR,RGB_VAD,    RGB_VAI,        _______,
    _______,        _______,        MU_ON,          MU_OFF,         MU_TOG,          _______,                                                       _______,        RGB_MOD,         RGB_SLD,       RGB_HUD,        RGB_HUI,        _______,
    _______,        MC_KVM1,        MC_KVM2,        _______,        _______,                        DYN_MACRO_PLAY1,                DYN_MACRO_PLAY2,                _______,         _______,       _______,        _______,        _______,
                                                                    _______,         DYN_REC_START1,DYN_REC_STOP,                   DYN_REC_STOP,   DYN_REC_START2, _______
  ),
};
// clang-format on

extern bool g_suspend_state;
extern rgb_config_t rgb_matrix_config;

void keyboard_post_init_user(void) {
  rgb_matrix_enable();
}

// clang-format off

// Reminder: These are HSV colors, not RGB.
#define GRAY   {  0,   0, 119}
#define BLACK  {  0,   0,   0}
#define BLUE   {146, 224, 255}
#define CYAN   {134, 255, 213}
#define GREEN  {105, 255, 255}
#define YELLOW { 32, 255, 234}
#define PINK   {243, 222, 234}
#define ORANGE { 12, 225, 241}
#define PURPLE {169, 120, 255}
#define FOREST { 85, 203, 158}
#define RED    {  0, 204, 255}
#define MAROON {  0, 200, 220}
#define OLIVE  { 48, 255, 153}
#define PINK2  {237, 189, 211}
#define BLUE2  {146, 208, 210}
#define VIOLET {169, 114, 196}

const uint8_t PROGMEM ledmap[][DRIVER_LED_TOTAL][3] = {
    [LAYER_BASE] = LEDMAP_moonlander(
          GRAY,   GRAY,   GRAY,   GRAY,   GRAY,   GRAY,   GRAY,        GRAY,   GRAY,   GRAY,   GRAY,   GRAY,   GRAY,   GRAY,
          GRAY,   GRAY,   GRAY,   GRAY,   GRAY,   GRAY,   GRAY,        GRAY,   GRAY,   GRAY,   GRAY,   GRAY,   GRAY,   GRAY,
          GRAY,   GRAY,   GRAY,   GRAY,   GRAY,   GRAY,   GRAY,        GRAY,   GRAY,   GRAY,   GRAY,   GRAY,   GRAY,   GRAY,
          GRAY,   GRAY,   GRAY,   GRAY,   GRAY,   GRAY,                        GRAY,   GRAY,   GRAY,   GRAY,   GRAY,   GRAY,
          GRAY,   GRAY,   GRAY,   GRAY,   GRAY,           GRAY,        GRAY,           GRAY,   GRAY,   GRAY,   GRAY,   GRAY,
                                          GRAY,   GRAY,   GRAY,        GRAY,   GRAY,   GRAY
    ),

    [LAYER_LOWER] = LEDMAP_moonlander(
         BLACK,   BLUE,   BLUE,   BLUE,   BLUE,   BLUE,   BLUE,        BLUE,   BLUE,   BLUE,   BLUE,   BLUE,   BLUE,   CYAN,
         BLACK,  BLACK,  GREEN,  BLACK,  BLACK,  GREEN,  BLACK,      YELLOW,  GREEN,  GREEN,  GREEN,   PINK,   PINK,   CYAN,
        YELLOW,  GREEN,  GREEN,  GREEN,  BLACK,  GREEN,  BLACK,       BLACK,   CYAN,   CYAN,   CYAN,   CYAN,  BLACK,  BLACK,
         BLACK,  BLACK,  BLACK,  BLACK,  BLACK,  GREEN,                        CYAN,   CYAN,   CYAN,   CYAN, YELLOW, YELLOW,
         BLACK, YELLOW, YELLOW,  BLACK,   BLUE,          BLACK,       BLACK,         ORANGE,   GRAY,   GRAY,   GRAY,   GRAY,
                                         BLACK,  BLACK,  BLACK,       BLACK,  BLACK,  BLACK
    ),

    [LAYER_RAISE] = LEDMAP_moonlander(
         BLACK, PURPLE, PURPLE, PURPLE, PURPLE, FOREST, FOREST,       BLACK,  BLACK,  BLACK, PURPLE, PURPLE, PURPLE,   CYAN,
         BLACK, PURPLE, PURPLE, PURPLE, PURPLE, FOREST, FOREST,       BLACK,  BLACK,   BLUE,   BLUE,   BLUE, PURPLE,   CYAN,
        YELLOW, PURPLE, PURPLE, PURPLE, PURPLE, FOREST, FOREST,       BLACK,  BLACK,   BLUE,   BLUE,   BLUE,   GRAY,  BLACK,
         BLACK, PURPLE, PURPLE, PURPLE, PURPLE,  BLACK,                       BLACK,   BLUE,   BLUE,   BLUE,  BLACK,  BLACK,
         BLACK, YELLOW, YELLOW,  BLACK, ORANGE,          BLACK,       BLACK,         PURPLE,   BLUE, PURPLE,  BLACK,  BLACK,
                                         BLACK,  BLACK,  BLACK,       BLACK,  BLACK,  BLACK
    ),

    [LAYER_ADJUST] = LEDMAP_moonlander(
           RED,  BLACK,  BLACK,  BLACK,  BLACK,  BLACK,  BLACK,       BLACK,  BLACK,  BLACK,  BLACK,  BLACK,  BLACK,  BLACK,
           RED,  BLACK,  BLACK,  BLACK,  BLACK,  BLACK, MAROON,      MAROON,  BLACK,  BLACK,  BLACK,  BLACK,  BLACK,  BLACK,
         BLACK,  BLACK,  OLIVE,  PINK2,  BLUE2,  BLACK,  BLACK,       BLACK,  BLACK,  BLUE2,  BLUE2,  OLIVE,  OLIVE,  BLACK,
         BLACK,  BLACK,  OLIVE,  PINK2,  BLUE2,  BLACK,                       BLACK,  PINK2,  PINK2, VIOLET, VIOLET,  BLACK,
         BLACK, YELLOW, YELLOW,  BLACK, ORANGE,           BLUE,        BLUE,         ORANGE,  BLACK,  BLACK,  BLACK,  BLACK,
                                         BLACK,    RED, ORANGE,      ORANGE,    RED,  BLACK
    ),
};
// clang-format on

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
   default:
    if (rgb_matrix_get_flags() == LED_FLAG_NONE)
      rgb_matrix_set_color_all(0, 0, 0);
    break;
  }
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case MC_ARW1:
      if (record->event.pressed) {
        SEND_STRING(SS_TAP(X_MINUS) SS_DELAY(100) SS_LSFT(SS_TAP(X_DOT)));

      }
      break;
    case MC_ARW2:
      if (record->event.pressed) {
        SEND_STRING(SS_TAP(X_EQUAL) SS_DELAY(100) SS_LSFT(SS_TAP(X_COMMA)));
      }
      break;
    case MC_KVM1:
      if (record->event.pressed) {
        SEND_STRING(SS_TAP(X_SCROLLLOCK) SS_DELAY(100) SS_TAP(X_SCROLLLOCK) SS_DELAY(100) SS_TAP(X_1));
      }
      break;
    case MC_KVM2:
      if (record->event.pressed) {
        SEND_STRING(SS_TAP(X_SCROLLLOCK) SS_DELAY(100) SS_TAP(X_SCROLLLOCK) SS_DELAY(100) SS_TAP(X_1));
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
