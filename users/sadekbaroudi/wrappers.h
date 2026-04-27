#pragma once
#include "sadekbaroudi.h"
/*
Since our quirky block definitions are basically a list of comma separated
arguments, we need a wrapper in order for these definitions to be
expanded before being used as arguments to the LAYOUT_xxx macro.
*/

// Since Reviung39 uses the name LAYOUT_reviung39 instead of LAYOUT
#if (!defined(LAYOUT) && defined(LAYOUT_reviung39))
#    define LAYOUT LAYOUT_reviung39
#endif

// Since Reviung41 uses the name LAYOUT_reviung41 instead of LAYOUT
#if (!defined(LAYOUT) && defined(LAYOUT_reviung41))
#    define LAYOUT LAYOUT_reviung41
#endif

// Since Reviung39 uses the name LAYOUT_reviung39 instead of LAYOUT
#if (!defined(LAYOUT) && defined(LAYOUT_ortho_5x12))
#    define LAYOUT LAYOUT_ortho_5x12
#endif

// Since enigma36 uses the name LAYOUT_enigma36 instead of LAYOUT
#if (!defined(LAYOUT) && defined(LAYOUT_enigma36))
#    define LAYOUT LAYOUT_enigma36
#endif

// Since Euclid36 uses the name LAYOUT_euclid36 instead of LAYOUT
#if (!defined(LAYOUT) && defined(LAYOUT_euclid36))
#    define LAYOUT LAYOUT_euclid36
#endif

// Since euclid36proto uses the name LAYOUT_euclid36proto instead of LAYOUT
#if (!defined(LAYOUT) && defined(LAYOUT_euclid36proto))
#    define LAYOUT LAYOUT_euclid36proto
#endif

// Since pteron38 uses the name LAYOUT_pteron38 instead of LAYOUT
#if (!defined(LAYOUT) && defined(LAYOUT_pteron38))
#    define LAYOUT LAYOUT_pteron38
#endif

// Since barobordhw uses the name LAYOUT_barobordhw instead of LAYOUT
#if (!defined(LAYOUT) && defined(LAYOUT_barobordhw))
#    define LAYOUT LAYOUT_barobordhw
#endif

// Since barobord uses the name LAYOUT_barobord instead of LAYOUT
#if (!defined(LAYOUT) && defined(LAYOUT_barobord))
#    define LAYOUT LAYOUT_barobord
#endif

// Since barobord_byomcu uses the name LAYOUT_barobord_byomcu instead of LAYOUT
#if (!defined(LAYOUT) && defined(LAYOUT_barobord_byomcu))
#    define LAYOUT LAYOUT_barobord_byomcu
#endif

// Since barobord uses the name LAYOUT_barobord instead of LAYOUT
#if (!defined(LAYOUT) && defined(LAYOUT_ortho_4x12))
#    define LAYOUT LAYOUT_ortho_4x12
#endif

// Since halfdash uses the name LAYOUT_halfdash instead of LAYOUT
#if (!defined(LAYOUT) && defined(LAYOUT_halfdash))
#    define LAYOUT LAYOUT_halfdash
#endif

// Since ffkbhw uses the name LAYOUT_ffkbhw instead of LAYOUT
#if (!defined(LAYOUT) && defined(LAYOUT_ffkbhw))
#    define LAYOUT LAYOUT_ffkbhw
#endif

// Since ffkbhw uses the name LAYOUT_ffkb instead of LAYOUT
#if (!defined(LAYOUT) && defined(LAYOUT_ffkb))
#    define LAYOUT LAYOUT_ffkb
#endif

// Since bgkeeb uses the name LAYOUT_bgkeeb instead of LAYOUT
#if (!defined(LAYOUT) && defined(LAYOUT_bgkeeb))
#    define LAYOUT LAYOUT_bgkeeb
#endif

// Since absolem uses the name LAYOUT_absolem instead of LAYOUT
#if (!defined(LAYOUT) && defined(LAYOUT_absolem))
#    define LAYOUT LAYOUT_absolem
#endif

// Since pinkiesout uses the name LAYOUT_pinkiesout instead of LAYOUT
#if (!defined(LAYOUT) && defined(LAYOUT_pinkiesout))
#    define LAYOUT LAYOUT_pinkiesout
#endif

// Since rockon uses the name LAYOUT_rockon instead of LAYOUT
#if (!defined(LAYOUT) && defined(LAYOUT_rockon))
#    define LAYOUT LAYOUT_rockon
#endif

// Since rockon_bp uses the name LAYOUT_rockon_bp instead of LAYOUT
#if (!defined(LAYOUT) && defined(LAYOUT_rockon_bp))
#    define LAYOUT LAYOUT_rockon_bp
#endif

// Since luakeeb uses the name LAYOUT_luakeeb instead of LAYOUT
#if (!defined(LAYOUT) && defined(LAYOUT_luakeeb))
#    define LAYOUT LAYOUT_luakeeb
#endif

// Since sweeeeep uses the name LAYOUT_sweeeeep instead of LAYOUT
#if (!defined(LAYOUT) && defined(LAYOUT_sweeeeep))
#    define LAYOUT LAYOUT_sweeeeep
#endif

// Since bigbarobord uses the name LAYOUT_bigbarobord instead of LAYOUT
#if (!defined(LAYOUT) && defined(LAYOUT_bigbarobord))
#    define LAYOUT LAYOUT_bigbarobord
#endif

// Since arachnophobe uses the name LAYOUT_arachnophobe instead of LAYOUT
#if (!defined(LAYOUT) && defined(LAYOUT_arachnophobe))
#    define LAYOUT LAYOUT_arachnophobe
#endif

// Since arachnophobe uses the name LAYOUT_arachnophobe instead of LAYOUT
#if (!defined(LAYOUT) && defined(LAYOUT_stenographobe))
#    define LAYOUT LAYOUT_stenographobe
#endif

// Since ximi uses the name LAYOUT_ximi instead of LAYOUT
#if (!defined(LAYOUT) && defined(LAYOUT_ximi))
#    define LAYOUT LAYOUT_ximi
#endif

// Since ximega uses the name LAYOUT_ximega instead of LAYOUT
#if (!defined(LAYOUT) && defined(LAYOUT_ximega))
#    define LAYOUT LAYOUT_ximega
#endif

// Since badwings uses the name LAYOUT_badwings instead of LAYOUT
#if (!defined(LAYOUT) && defined(LAYOUT_badwings))
#    define LAYOUT LAYOUT_badwings
#endif

// Since fflx uses the name LAYOUT_fflx instead of LAYOUT
#if (!defined(LAYOUT) && defined(LAYOUT_fflx))
#    define LAYOUT LAYOUT_fflx
#endif

// Since KLOR uses the name LAYOUT_saegewerk instead of LAYOUT
#if (!defined(LAYOUT) && defined(LAYOUT_saegewerk))
#    define LAYOUT LAYOUT_saegewerk
#endif

// Since fpm101 uses the name LAYOUT_fpm101 instead of LAYOUT
#if (!defined(LAYOUT) && defined(LAYOUT_fpm101))
#    define LAYOUT LAYOUT_fpm101
#endif

// Since zazu uses the name LAYOUT_zazu instead of LAYOUT
#if (!defined(LAYOUT) && defined(LAYOUT_zazu))
#    define LAYOUT LAYOUT_zazu
#endif

// Since barghoot uses the name LAYOUT_barghoot instead of LAYOUT
#if (!defined(LAYOUT) && defined(LAYOUT_barghoot))
#    define LAYOUT LAYOUT_barghoot
#endif

// Since kong uses the name LAYOUT_kong instead of LAYOUT
#if (!defined(LAYOUT) && defined(LAYOUT_kong))
#    define LAYOUT LAYOUT_kong
#endif

// Since LAYOUT_vulpes_minora uses the name LAYOUT_vulpes_minora instead of LAYOUT
#if (!defined(LAYOUT) && defined(LAYOUT_vulpes_minora))
#    define LAYOUT LAYOUT_vulpes_minora
#endif

// Since LAYOUT_vulpes_majora uses the name LAYOUT_vulpes_majora instead of LAYOUT
#if (!defined(LAYOUT) && defined(LAYOUT_vulpes_majora))
#    define LAYOUT LAYOUT_vulpes_majora
#endif

// Since LAYOUT_testamatta uses the name LAYOUT_testamatta instead of LAYOUT
#if (!defined(LAYOUT) && defined(LAYOUT_testamatta))
#    define LAYOUT LAYOUT_testamatta
#endif

// Since LAYOUT_svlinky uses the name LAYOUT_svlinky instead of LAYOUT
#if (!defined(LAYOUT) && defined(LAYOUT_svlinky))
#    define LAYOUT LAYOUT_svlinky
#endif

// Since LAYOUT_xivik uses the name LAYOUT_xivik instead of LAYOUT
#if (!defined(LAYOUT) && defined(LAYOUT_xivik))
#    define LAYOUT LAYOUT_xivik
#endif

// Since LAYOUT_baboon38 uses the name LAYOUT_baboon38 instead of LAYOUT
#if (!defined(LAYOUT) && defined(LAYOUT_baboon38))
#    define LAYOUT LAYOUT_baboon38
#endif

// Since LAYOUT_kucheza uses the name LAYOUT_kucheza instead of LAYOUT
#if (!defined(LAYOUT) && defined(LAYOUT_kucheza))
#    define LAYOUT LAYOUT_kucheza
#endif

// Since LAYOUT_le_chiffre_democratique uses the name LAYOUT_le_chiffre_democratique instead of LAYOUT
#if (!defined(LAYOUT) && defined(LAYOUT_le_chiffre_democratique))
#    define LAYOUT LAYOUT_le_chiffre_democratique
#endif

// Since LAYOUT_le_chiffre_democratique uses the name LAYOUT_le_chiffre_democratique instead of LAYOUT
#if (!defined(LAYOUT) && defined(LAYOUT_smallcat))
#    define LAYOUT LAYOUT_smallcat
#endif

// clang-format off
#define LAYOUT_ergodox_wrapper(...)          LAYOUT_ergodox(__VA_ARGS__)
#define LAYOUT_ergodox_pretty_wrapper(...)   LAYOUT_ergodox_pretty(__VA_ARGS__)
#define KEYMAP_wrapper(...)                  LAYOUT(__VA_ARGS__)
#define LAYOUT_wrapper(...)                  LAYOUT(__VA_ARGS__)
#define LAYOUT_ortho_4x12_wrapper(...)       LAYOUT_ortho_4x12(__VA_ARGS__)
#define LAYOUT_ortho_5x12_wrapper(...)       LAYOUT_ortho_5x12(__VA_ARGS__)
#define LAYOUT_gergo_wrapper(...)            LAYOUT_gergo(__VA_ARGS__)
#define LAYOUT_split_3x6_3_wrapper(...)      LAYOUT_split_3x6_3(__VA_ARGS__)
#define LAYOUT_reviung39_wrapper(...)        LAYOUT_reviung39(__VA_ARGS__)
#define LAYOUT_pteron38_wrapper(...)         LAYOUT_pteron38(__VA_ARGS__)
#define LAYOUT_ffkbhw_wrapper(...)           LAYOUT_ffkbhw(__VA_ARGS__)

/*
Blocks for each of the four major keyboard layouts
Organized so we can quickly adapt and modify all of them
at once, rather than for each keyboard, one at a time.
And this allows for much cleaner blocks in the keymaps.
For instance Tap/Hold for Control on all of the layouts

NOTE: These are all the same length.  If you do a search/replace
  then you need to add/remove underscores to keep the
  lengths consistent.
*/


#define __ALPHA_THUMB_L1__ KC_DEL
#define __ALPHA_THUMB_L2__ KC_ENT
#define __ALPHA_THUMB_L3__ KC_TAB
#define __ALPHA_THUMB_R1__ KC_BSPC
#define __ALPHA_THUMB_R2__ KC_SPACE
#define __ALPHA_THUMB_R3__ KC_QUOT

#define __ALPHA_THUMBS_LEFT_2_TUCKY__                             __ALPHA_THUMB_L1__, __ALPHA_THUMB_L2__
#define __ALPHA_THUMBS_RIGHT_2_TUCKY__                            __ALPHA_THUMB_R2__, __ALPHA_THUMB_R3__

#define __ALPHA_THUMBS_LEFT_2_REACHY__                             __ALPHA_THUMB_L2__, __ALPHA_THUMB_L3__
#define __ALPHA_THUMBS_RIGHT_2_REACHY__                            __ALPHA_THUMB_R1__, __ALPHA_THUMB_R2__

#define __ALPHA_THUMBS_LEFT_3__                             __ALPHA_THUMB_L1__, __ALPHA_THUMB_L2__, __ALPHA_THUMB_L3__
#define __ALPHA_THUMBS_RIGHT_3__                            __ALPHA_THUMB_R1__, __ALPHA_THUMB_R2__, __ALPHA_THUMB_R3__

#define __ALPHA_THUMBS_4__                                  __ALPHA_THUMBS_LEFT_2_REACHY__, __ALPHA_THUMBS_RIGHT_2_REACHY__
#define __ALPHA_THUMBS_5__                                  __ALPHA_THUMB_L1__, __ALPHA_THUMB_L2__, __ALPHA_THUMB_R1__, __ALPHA_THUMB_R2__, __ALPHA_THUMB_R3__
#define __ALPHA_THUMBS_6__                                  __ALPHA_THUMBS_LEFT_3__, __ALPHA_THUMBS_RIGHT_3__

#define __ALPHA_ALT_THUMB_L1__ __ALPHA_THUMB_L1__
#define __ALPHA_ALT_THUMB_L2__ KC_O
#define __ALPHA_ALT_THUMB_L3__ __ALPHA_THUMB_L3__
#define __ALPHA_ALT_THUMB_R1__ __ALPHA_THUMB_R1__
#define __ALPHA_ALT_THUMB_R2__ __ALPHA_THUMB_R2__
#define __ALPHA_ALT_THUMB_R3__ __ALPHA_THUMB_R3__

#define __ALPHA_ALT_THUMBS_LEFT_2_TUCKY__                         __ALPHA_ALT_THUMB_L1__, __ALPHA_ALT_THUMB_L2__
#define __ALPHA_ALT_THUMBS_RIGHT_2_TUCKY__                        __ALPHA_ALT_THUMB_R2__, __ALPHA_ALT_THUMB_R3__

#define __ALPHA_ALT_THUMBS_LEFT_2_REACHY__                         __ALPHA_ALT_THUMB_L2__, __ALPHA_ALT_THUMB_L3__
#define __ALPHA_ALT_THUMBS_RIGHT_2_REACHY__                        __ALPHA_ALT_THUMB_R1__, __ALPHA_ALT_THUMB_R2__

#define __ALPHA_ALT_THUMBS_LEFT_3__                         __ALPHA_ALT_THUMB_L1__, __ALPHA_ALT_THUMB_L2__, __ALPHA_ALT_THUMB_L3__
#define __ALPHA_ALT_THUMBS_RIGHT_3__                        __ALPHA_ALT_THUMB_R1__, __ALPHA_ALT_THUMB_R2__, __ALPHA_ALT_THUMB_R3__

#define __ALPHA_ALT_THUMBS_4__                              __ALPHA_ALT_THUMBS_LEFT_2_REACHY__, __ALPHA_ALT_THUMBS_RIGHT_2_REACHY__
#define __ALPHA_ALT_THUMBS_5__                              __ALPHA_ALT_THUMB_L1__, __ALPHA_ALT_THUMB_L2__, __ALPHA_ALT_THUMB_R1__, __ALPHA_ALT_THUMB_R2__, __ALPHA_ALT_THUMB_R3__
#define __ALPHA_ALT_THUMBS_6__                              __ALPHA_ALT_THUMBS_LEFT_3__, __ALPHA_ALT_THUMBS_RIGHT_3__

#define __ALPHA_ALT_L1_K1__ KC_Q
#define __ALPHA_ALT_L1_K2__ KC_W
#define __ALPHA_ALT_L1_K3__ KC_F
#define __ALPHA_ALT_L1_K4__ KC_P
#define __ALPHA_ALT_L1_K5__ KC_B

#define __ALPHA_ALT_L2_K1__ KC_A
#define __ALPHA_ALT_L2_K2__ KC_R
#define __ALPHA_ALT_L2_K3__ KC_S
#define __ALPHA_ALT_L2_K4__ KC_T
#define __ALPHA_ALT_L2_K5__ KC_G

#define __ALPHA_ALT_L3_K1__ KC_Z
#define __ALPHA_ALT_L3_K2__ KC_X
#define __ALPHA_ALT_L3_K3__ KC_C
#define __ALPHA_ALT_L3_K4__ KC_D
#define __ALPHA_ALT_L3_K5__ KC_V

#define __ALPHA_ALT_R1_K1__ KC_J
#define __ALPHA_ALT_R1_K2__ KC_L
#define __ALPHA_ALT_R1_K3__ KC_U
#define __ALPHA_ALT_R1_K4__ KC_Y
#define __ALPHA_ALT_R1_K5__ KC_SCLN

#define __ALPHA_ALT_R2_K1__ KC_M
#define __ALPHA_ALT_R2_K2__ KC_N
#define __ALPHA_ALT_R2_K3__ KC_E
#define __ALPHA_ALT_R2_K4__ KC_I
#define __ALPHA_ALT_R2_K5__ KC_H

#define __ALPHA_ALT_R3_K1__ KC_K
#define __ALPHA_ALT_R3_K2__ KC_NO
#define __ALPHA_ALT_R3_K3__ KC_COMM
#define __ALPHA_ALT_R3_K4__ KC_DOT
#define __ALPHA_ALT_R3_K5__ KC_SLASH

#define _________________ALPHA_ALT_L1_________________			__ALPHA_ALT_L1_K1__,    __ALPHA_ALT_L1_K2__,    __ALPHA_ALT_L1_K3__,    __ALPHA_ALT_L1_K4__,    __ALPHA_ALT_L1_K5__
#define _________________ALPHA_ALT_L2_________________			__ALPHA_ALT_L2_K1__,    __ALPHA_ALT_L2_K2__,    __ALPHA_ALT_L2_K3__,    __ALPHA_ALT_L2_K4__,    __ALPHA_ALT_L2_K5__
#define _________________ALPHA_ALT_L3_________________			__ALPHA_ALT_L3_K1__,    __ALPHA_ALT_L3_K2__,    __ALPHA_ALT_L3_K3__,    __ALPHA_ALT_L3_K4__,    __ALPHA_ALT_L3_K5__

#define _________________ALPHA_ALT_R1_________________			__ALPHA_ALT_R1_K1__,    __ALPHA_ALT_R1_K2__,    __ALPHA_ALT_R1_K3__,    __ALPHA_ALT_R1_K4__,    __ALPHA_ALT_R1_K5__
#define _________________ALPHA_ALT_R2_________________			__ALPHA_ALT_R2_K1__,    __ALPHA_ALT_R2_K2__,    __ALPHA_ALT_R2_K3__,    __ALPHA_ALT_R2_K4__,    __ALPHA_ALT_R2_K5__
#define _________________ALPHA_ALT_R3_________________			__ALPHA_ALT_R3_K1__,    __ALPHA_ALT_R3_K2__,    __ALPHA_ALT_R3_K3__,    __ALPHA_ALT_R3_K4__,    __ALPHA_ALT_R3_K5__

/* This is the target
#define _________________ALPHA_ALT_L1_________________			KC_ENT,  KC_Q,    KC_W,    KC_P,    KC_B
#define _________________ALPHA_ALT_L2_________________			KC_A,    KC_R,    KC_S,    KC_T,    KC_G
#define _________________ALPHA_ALT_L3_________________			KC_Z,    KC_X,    KC_C,    KC_D,    KC_V

#define _________________ALPHA_ALT_R1_________________			KC_J,    KC_L,    KC_U,    KC_Y,    KC_SCLN
#define _________________ALPHA_ALT_R2_________________			KC_F,    KC_N,    KC_E,    KC_I,    KC_H
#define _________________ALPHA_ALT_R3_________________			KC_K,    KC_M,    KC_COMM, KC_DOT,  KC_SLASH
*/

#define __ALPHA_L1_K1__ KC_Q
#define __ALPHA_L1_K2__ KC_W
#define __ALPHA_L1_K3__ KC_F
#define __ALPHA_L1_K4__ KC_P
#define __ALPHA_L1_K5__ KC_B

#define __ALPHA_L2_K1__ KC_A
#define __ALPHA_L2_K2__ KC_R
#define __ALPHA_L2_K3__ KC_S
#define __ALPHA_L2_K4__ KC_T
#define __ALPHA_L2_K5__ KC_G

#define __ALPHA_L3_K1__ KC_Z
#define __ALPHA_L3_K2__ KC_X
#define __ALPHA_L3_K3__ KC_C
#define __ALPHA_L3_K4__ KC_D
#define __ALPHA_L3_K5__ KC_V

#define __ALPHA_R1_K1__ KC_J
#define __ALPHA_R1_K2__ KC_L
#define __ALPHA_R1_K3__ KC_U
#define __ALPHA_R1_K4__ KC_Y
#define __ALPHA_R1_K5__ KC_SCLN

#define __ALPHA_R2_K1__ KC_M
#define __ALPHA_R2_K2__ KC_N
#define __ALPHA_R2_K3__ KC_E
#define __ALPHA_R2_K4__ KC_I
#define __ALPHA_R2_K5__ KC_O

#define __ALPHA_R3_K1__ KC_K
#define __ALPHA_R3_K2__ KC_H
#define __ALPHA_R3_K3__ KC_COMM
#define __ALPHA_R3_K4__ KC_DOT
#define __ALPHA_R3_K5__ KC_SLASH

// ALPHA
#define __________________ALPHA_L1____________________			__ALPHA_L1_K1__,    __ALPHA_L1_K2__,    __ALPHA_L1_K3__,    __ALPHA_L1_K4__,    __ALPHA_L1_K5__
#define __________________ALPHA_L2____________________			__ALPHA_L2_K1__,    __ALPHA_L2_K2__,    __ALPHA_L2_K3__,    __ALPHA_L2_K4__,    __ALPHA_L2_K5__
#define __________________ALPHA_L3____________________			__ALPHA_L3_K1__,    __ALPHA_L3_K2__,    __ALPHA_L3_K3__,    __ALPHA_L3_K4__,    __ALPHA_L3_K5__

#define __________________ALPHA_R1____________________			__ALPHA_R1_K1__,    __ALPHA_R1_K2__,    __ALPHA_R1_K3__,    __ALPHA_R1_K4__,    __ALPHA_R1_K5__
#define __________________ALPHA_R2____________________			__ALPHA_R2_K1__,    __ALPHA_R2_K2__,    __ALPHA_R2_K3__,    __ALPHA_R2_K4__,    __ALPHA_R2_K5__
#define __________________ALPHA_R3____________________			__ALPHA_R3_K1__,    __ALPHA_R3_K2__,    __ALPHA_R3_K3__,    __ALPHA_R3_K4__,    __ALPHA_R3_K5__

// BLANK FULL LINE
#define ___________________BLANK___________________			_______, _______, _______, _______, _______

// NAVIGATION

#define __NAV_1_K1__ KC_ESC
#define __NAV_1_K2__ KC_PGUP
#define __NAV_1_K3__ KC_UP
#define __NAV_1_K4__ KC_PGDN
#define __NAV_1_K5__ _______

#define __NAV_2_K1__ KC_HOME
#define __NAV_2_K2__ KC_LEFT
#define __NAV_2_K3__ KC_DOWN
#define __NAV_2_K4__ KC_RGHT
#define __NAV_2_K5__ KC_END

#define __NAV_3_K1__ KC_ESC
#define __NAV_3_K2__ KC_PGUP
#define __NAV_3_K3__ KC_PGDN
#define __NAV_3_K4__ LCTL(LGUI(KC_LEFT))
#define __NAV_3_K5__ LCTL(LGUI(KC_RIGHT))

#define ________________NAVIGATION_1_______________			__NAV_1_K1__, __NAV_1_K2__, __NAV_1_K3__, __NAV_1_K4__, __NAV_1_K5__
#define ________________NAVIGATION_2_______________			__NAV_2_K1__, __NAV_2_K2__, __NAV_2_K3__, __NAV_2_K4__, __NAV_2_K5__
#define ________________NAVIGATION_3_______________			__NAV_3_K1__, __NAV_3_K2__, __NAV_3_K3__, __NAV_3_K4__, __NAV_3_K5__

#define __NUMPAD_1_K1__ KC_ASTR
#define __NUMPAD_1_K2__ KC_7
#define __NUMPAD_1_K3__ KC_8
#define __NUMPAD_1_K4__ KC_9
#define __NUMPAD_1_K5__ KC_MINS

#define __NUMPAD_2_K1__ KC_SLSH
#define __NUMPAD_2_K2__ KC_4
#define __NUMPAD_2_K3__ KC_5
#define __NUMPAD_2_K4__ KC_6
#define __NUMPAD_2_K5__ KC_PLUS

#define __NUMPAD_3_K1__ KC_EQL
#define __NUMPAD_3_K2__ KC_1
#define __NUMPAD_3_K3__ KC_2
#define __NUMPAD_3_K4__ KC_3
#define __NUMPAD_3_K5__ KC_0

#define _________________NUMPAD_1__________________			__NUMPAD_1_K1__, __NUMPAD_1_K2__, __NUMPAD_1_K3__, __NUMPAD_1_K4__, __NUMPAD_1_K5__
#define _________________NUMPAD_2__________________			__NUMPAD_2_K1__, __NUMPAD_2_K2__, __NUMPAD_2_K3__, __NUMPAD_2_K4__, __NUMPAD_2_K5__
#define _________________NUMPAD_3__________________			__NUMPAD_3_K1__, __NUMPAD_3_K2__, __NUMPAD_3_K3__, __NUMPAD_3_K4__, __NUMPAD_3_K5__

// SYMBOLS

#define __SYMBOLS_L1_K1__ KC_EXLM
#define __SYMBOLS_L1_K2__ KC_AT
#define __SYMBOLS_L1_K3__ KC_HASH
#define __SYMBOLS_L1_K4__ KC_DLR
#define __SYMBOLS_L1_K5__ KC_PERC

#define __SYMBOLS_L2_K1__ KC_MINS
#define __SYMBOLS_L2_K2__ KC_LBRC
#define __SYMBOLS_L2_K3__ KC_LCBR
#define __SYMBOLS_L2_K4__ KC_LPRN
#define __SYMBOLS_L2_K5__ KC_LT

#define __META_NAV_L1_K1__ KC_CAPS
#define __META_NAV_L1_K2__ KC_GRV
#define __META_NAV_L1_K3__ LCTL(LSFT(KC_TAB))
#define __META_NAV_L1_K4__ LCTL(LGUI(KC_LEFT))
#define __META_NAV_L1_K5__ C_CAPSWORD

#define __SYMBOLS_R1_K1__ KC_CIRC
#define __SYMBOLS_R1_K2__ KC_AMPR
#define __SYMBOLS_R1_K3__ KC_ASTR
#define __SYMBOLS_R1_K4__ KC_UNDS
#define __SYMBOLS_R1_K5__ KC_EQL

#define __SYMBOLS_R2_K1__ KC_GT
#define __SYMBOLS_R2_K2__ KC_RPRN
#define __SYMBOLS_R2_K3__ KC_RCBR
#define __SYMBOLS_R2_K4__ KC_RBRC
#define __SYMBOLS_R2_K5__ KC_PLUS

#define __META_NAV_L2_K1__ C_UNDERSCORECASE
#define __META_NAV_L2_K2__ LCTL(LGUI(KC_RIGHT))
#define __META_NAV_L2_K3__ LCTL(KC_TAB)
#define __META_NAV_L2_K4__ C_ANYCASE
#define __META_NAV_L2_K5__ KC_BSLS


#define _________________META_NAV_L1_______________     __META_NAV_L1_K1__, __META_NAV_L1_K2__, __META_NAV_L1_K3__, __META_NAV_L1_K4__, __META_NAV_L1_K5__
#define _________________META_NAV_R1_______________     __META_NAV_L2_K1__, __META_NAV_L2_K2__, __META_NAV_L2_K3__, __META_NAV_L2_K4__, __META_NAV_L2_K5__

#define ________________SYMBOLS_L1_________________			__SYMBOLS_L1_K1__, __SYMBOLS_L1_K2__, __SYMBOLS_L1_K3__, __SYMBOLS_L1_K4__, __SYMBOLS_L1_K5__
#define ________________SYMBOLS_L2_________________			__SYMBOLS_L2_K1__, __SYMBOLS_L2_K2__, __SYMBOLS_L2_K3__, __SYMBOLS_L2_K4__, __SYMBOLS_L2_K5__
#define ________________SYMBOLS_L3_________________			_________________META_NAV_L1_______________

#define ________________SYMBOLS_R1_________________			__SYMBOLS_R1_K1__, __SYMBOLS_R1_K2__, __SYMBOLS_R1_K3__, __SYMBOLS_R1_K4__, __SYMBOLS_R1_K5__
#define ________________SYMBOLS_R2_________________			__SYMBOLS_R2_K1__, __SYMBOLS_R2_K2__, __SYMBOLS_R2_K3__, __SYMBOLS_R2_K4__, __SYMBOLS_R2_K5__
#define ________________SYMBOLS_R3_________________			_________________META_NAV_R1_______________

// SHIFT NAVIGATION LAYER

#define __SHIFTNAV_1_K1__ QK_BOOT
#define __SHIFTNAV_1_K2__ LSFT(KC_PGUP)
#define __SHIFTNAV_1_K3__ LSFT(KC_UP)
#define __SHIFTNAV_1_K4__ LSFT(KC_PGDN)
#define __SHIFTNAV_1_K5__ EE_CLR

#define __SHIFTNAV_2_K1__ LSFT(KC_HOME)
#define __SHIFTNAV_2_K2__ LSFT(KC_LEFT)
#define __SHIFTNAV_2_K3__ LSFT(KC_DOWN)
#define __SHIFTNAV_2_K4__ LSFT(KC_RGHT)
#define __SHIFTNAV_2_K5__ LSFT(KC_END)

#define __SHIFTNAV_3_K1__ QK_REBOOT
#define __SHIFTNAV_3_K2__ LSFT(KC_PGUP)
#define __SHIFTNAV_3_K3__ LSFT(KC_PGDN)
#define __SHIFTNAV_3_K4__ _______
#define __SHIFTNAV_3_K5__ U_KVM_SWITCH

#define ________________SHIFTNAV_1_________________			__SHIFTNAV_1_K1__, __SHIFTNAV_1_K2__, __SHIFTNAV_1_K3__, __SHIFTNAV_1_K4__, __SHIFTNAV_1_K5__
#define ________________SHIFTNAV_2_________________			__SHIFTNAV_2_K1__, __SHIFTNAV_2_K2__, __SHIFTNAV_2_K3__, __SHIFTNAV_2_K4__, __SHIFTNAV_2_K5__
#define ________________SHIFTNAV_3_________________			__SHIFTNAV_3_K1__, __SHIFTNAV_3_K2__, __SHIFTNAV_3_K3__, __SHIFTNAV_3_K4__, __SHIFTNAV_3_K5__

#define __FUNCTION_1_K1__ KC_MPLY
#define __FUNCTION_1_K2__ KC_F7
#define __FUNCTION_1_K3__ KC_F8
#define __FUNCTION_1_K4__ KC_F9
#define __FUNCTION_1_K5__ KC_F10

#define __FUNCTION_2_K1__ KC_VOLU
#define __FUNCTION_2_K2__ KC_F4
#define __FUNCTION_2_K3__ KC_F5
#define __FUNCTION_2_K4__ KC_F6
#define __FUNCTION_2_K5__ KC_F11

#define __FUNCTION_3_K1__ KC_VOLD
#define __FUNCTION_3_K2__ KC_F1
#define __FUNCTION_3_K3__ KC_F2
#define __FUNCTION_3_K4__ KC_F3
#define __FUNCTION_3_K5__ KC_F12

#define ________________FUNCTION_1_________________			__FUNCTION_1_K1__, __FUNCTION_1_K2__, __FUNCTION_1_K3__, __FUNCTION_1_K4__, __FUNCTION_1_K5__
#define ________________FUNCTION_2_________________			__FUNCTION_2_K1__, __FUNCTION_2_K2__, __FUNCTION_2_K3__, __FUNCTION_2_K4__, __FUNCTION_2_K5__
#define ________________FUNCTION_3_________________			__FUNCTION_3_K1__, __FUNCTION_3_K2__, __FUNCTION_3_K3__, __FUNCTION_3_K4__, __FUNCTION_3_K5__

// MEDIA LAYER

#define __RGB_1_K1__ UG_TOGG
#define __RGB_1_K2__ UG_PREV
#define __RGB_1_K3__ UG_NEXT
#define __RGB_1_K4__ _______
#define __RGB_1_K5__ TG(_ALPHA_ALT)

#define __RGB_2_K1__ KC_RGB_BLT
#define __RGB_2_K2__ UG_HUEU
#define __RGB_2_K3__ UG_SATU
#define __RGB_2_K4__ UG_VALU
#define __RGB_2_K5__ TG(_ALPHA)

#define __RGB_3_K1__ KC_RGB_T
#define __RGB_3_K2__ UG_HUED
#define __RGB_3_K3__ UG_SATD
#define __RGB_3_K4__ UG_VALD
#define __RGB_3_K5__ _______

#define ___________________RGB_1___________________			__RGB_1_K1__, __RGB_1_K2__, __RGB_1_K3__, __RGB_1_K4__, __RGB_1_K5__
#define ___________________RGB_2___________________			__RGB_2_K1__, __RGB_2_K2__, __RGB_2_K3__, __RGB_2_K4__, __RGB_2_K5__
#define ___________________RGB_3___________________			__RGB_3_K1__, __RGB_3_K2__, __RGB_3_K3__, __RGB_3_K4__, __RGB_3_K5__

#define __MACROS_1_K1__ UG_SPDU
#define __MACROS_1_K2__ FP_POINT_DPI_RESET
#define __MACROS_1_K3__ FP_SCROLL_DPI_RESET
#define __MACROS_1_K4__ FP_SNIPE_DPI_RESET
#define __MACROS_1_K5__ E_ROBOT

#define __MACROS_2_K1__ P_ANGBRKT
#define __MACROS_2_K2__ FP_POINT_DPI_UP
#define __MACROS_2_K3__ FP_SCROLL_DPI_UP
#define __MACROS_2_K4__ FP_SNIPE_DPI_UP
#define __MACROS_2_K5__ P_ARROW

#define __MACROS_3_K1__ UG_SPDD
#define __MACROS_3_K2__ FP_POINT_DPI_DN
#define __MACROS_3_K3__ FP_SCROLL_DPI_DN
#define __MACROS_3_K4__ FP_SNIPE_DPI_DN
#define __MACROS_3_K5__ E_CAT

// // UNCOMMENT TO DISABLE MACROS
// #define _________________MACROS_1__________________			___________________BLANK___________________
// #define _________________MACROS_2__________________			___________________BLANK___________________
// #define _________________MACROS_3__________________			___________________BLANK___________________

// COMMENT TO DISABLE MACROS
#define _________________MACROS_1__________________			__MACROS_1_K1__, __MACROS_1_K2__, __MACROS_1_K3__, __MACROS_1_K4__, __MACROS_1_K5__
#define _________________MACROS_2__________________			__MACROS_2_K1__, __MACROS_2_K2__, __MACROS_2_K3__, __MACROS_2_K4__, __MACROS_2_K5__
#define _________________MACROS_3__________________			__MACROS_3_K1__, __MACROS_3_K2__, __MACROS_3_K3__, __MACROS_3_K4__, __MACROS_3_K5__

// MOUSE LAYER

#define __MOUSE_1_K1__ _______
#define __MOUSE_1_K2__ MS_WHLU
#define __MOUSE_1_K3__ MS_UP
#define __MOUSE_1_K4__ MS_WHLD
#define __MOUSE_1_K5__ _______

#define __MOUSE_2_K1__ MS_WHLL
#define __MOUSE_2_K2__ MS_LEFT
#define __MOUSE_2_K3__ MS_DOWN
#define __MOUSE_2_K4__ MS_RGHT
#define __MOUSE_2_K5__ MS_WHLR

#define __MOUSE_3_K1__ _______
#define __MOUSE_3_K2__ MS_WHLU
#define __MOUSE_3_K3__ MS_WHLD
#define __MOUSE_3_K4__ MS_ACL1
#define __MOUSE_3_K5__ MS_ACL2

#define __________________MOUSE_1__________________     __MOUSE_1_K1__, __MOUSE_1_K2__, __MOUSE_1_K3__, __MOUSE_1_K4__, __MOUSE_1_K5__
#define __________________MOUSE_2__________________     __MOUSE_2_K1__, __MOUSE_2_K2__, __MOUSE_2_K3__, __MOUSE_2_K4__, __MOUSE_2_K5__
#define __________________MOUSE_3__________________     __MOUSE_3_K1__, __MOUSE_3_K2__, __MOUSE_3_K3__, __MOUSE_3_K4__, __MOUSE_3_K5__

#define __AMOUSE_1_K1_ _______
#define __AMOUSE_1_K2_ MS_WHLU
#define __AMOUSE_1_K3_ MS_UP
#define __AMOUSE_1_K4_ MS_WHLD
#define __AMOUSE_1_K5_ _______

#define __AMOUSE_2_K1_ MS_WHLL
#define __AMOUSE_2_K2_ MS_BTN3
#define __AMOUSE_2_K3_ MS_BTN2
#define __AMOUSE_2_K4_ MS_BTN1
#define __AMOUSE_2_K5_ MS_WHLR

#define __AMOUSE_3_K1_ EE_CLR
#define __AMOUSE_3_K2_ MS_WHLU
#define __AMOUSE_3_K3_ MS_WHLD
#define __AMOUSE_3_K4_ MS_ACL1
#define __AMOUSE_3_K5_ MS_ACL2

#define _______________AUTO_MOUSE_1________________     __AMOUSE_1_K1_, __AMOUSE_1_K2_, __AMOUSE_1_K3_, __AMOUSE_1_K4_, __AMOUSE_1_K5_
#define _______________AUTO_MOUSE_2________________     __AMOUSE_2_K1_, __AMOUSE_2_K2_, __AMOUSE_2_K3_, __AMOUSE_2_K4_, __AMOUSE_2_K5_
#define _______________AUTO_MOUSE_3________________     __AMOUSE_3_K1_, __AMOUSE_3_K2_, __AMOUSE_3_K3_, __AMOUSE_3_K4_, __AMOUSE_3_K5_

#define _MCRAFT_DROP_        KC_Q
#define _MCRAFT_FWD_         KC_W
#define _MCRAFT_SWAP_HAND_   KC_F

#define _MCRAFT_SPRINT_      KC_LCTL
#define _MCRAFT_LEFT_        KC_A
#define _MCRAFT_BACK_        KC_S
#define _MCRAFT_RIGHT_       KC_D
#define _MCRAFT_INVENTORY_   KC_E

#define _MCRAFT_SNEAK_       KC_LSFT

#define _MCRAFT_NONE_        KC_NO

#define _MCRAFT_JUMP_   KC_SPACE
#define _MCRAFT_ENTER_  KC_ENTER

#define _______________MINECRAFT_1_________________     _MCRAFT_DROP_,   _MCRAFT_NONE_, _MCRAFT_FWD_,  _MCRAFT_NONE_,  _MCRAFT_SWAP_HAND_
#define _______________MINECRAFT_2_________________     _MCRAFT_SPRINT_, _MCRAFT_LEFT_, _MCRAFT_BACK_, _MCRAFT_RIGHT_, _MCRAFT_INVENTORY_
#define _______________MINECRAFT_3_________________     _MCRAFT_SNEAK_,  _MCRAFT_NONE_, _MCRAFT_NONE_, _MCRAFT_NONE_,  _MCRAFT_NONE_

//                                                      Zoom Home           Add Line            Add Arc            Add Polygon         Add Circle
#define ___________________KICAD_0_________________     KC_HOME,            LCTL(LSFT(KC_L)),   LCTL(LSFT(KC_A)),  LCTL(LSFT(KC_P)),   LCTL(LSFT(KC_C))
//                                                      Drag 45 degree      Move Dialog         Flip               Pos Relative        Select Net
#define ___________________KICAD_1_________________     KC_D,               LSFT(KC_M),         KC_F,              LSFT(KC_P),         KC_GRV
//                                                      Create Track        End Track           Edit Property      Move                Fill Zones
#define ___________________KICAD_2_________________     LCTL_T(KC_X),       LGUI_T(KC_END),     LALT_T(KC_E),      LSFT_T(KC_M),       KC_B
//                                                      Undo                Redo                Rotate             Add Via             Front<->Back
#define ___________________KICAD_3_________________     LCTL(KC_X),         LCTL(KC_Y),         KC_R,              LCTL(LSFT(KC_V)),   KC_V

// Shortcuts for general kicad aliases
#define M_KI_SEL_TR KC_U
#define M_KI_MV     KC_M
#define M_KI_MVREL  LSFT(KC_P)

#define __KICAD_R0_L__ KC_ESC
#define __KICAD_R1_L__ KC_TAB            // Drag free angl
#define __KICAD_R2_L__ LCTL(KC_C)        // Copy
#define __KICAD_R3_L__ LCTL(KC_V)        // Paste
#define __KICAD_R0_R__ LCTL(LSFT(KC_T))  // Add Text
#define __KICAD_R1_R__ LSFT(KC_GRV)      // Stop SelctNet
#define __KICAD_R2_R__ LCTL(KC_B)        // Unfill Zones
#define __KICAD_R3_R__ LCTL(LSFT(KC_M))  // Measure
#define __KICAD_TH_L__ KC_DEL            // Delete
#define __KICAD_TH_C__ KC_ENT            // Enter
#define __KICAD_TH_R__ LSFT(KC_DEL)      // Delete track, note that this only deletes the current copper line up to pads or vias
#define __KICAD_R4_1__ __KICAD_R3_R__
#define __KICAD_R4_2__ LALT(KC_3)        // 3D Viewer
#define __KICAD_R4_3__ M_KI_SEL_TR       // Select track, double press for all connected... // used to be this --> LCTL(KC_E)        // Edit Footprint


#define ___________________GAMES_0_________________     KC_F1,   KC_F2,   KC_C,    KC_V,    KC_G
#define ___________________GAMES_1_________________     KC_Q,    KC_W,    KC_E,    KC_R,    KC_D
#define ___________________GAMES_2_________________     KC_A,    KC_F,    KC_TAB,  KC_L,    KC_H
#define ___________________GAMES_3_________________     KC_T,    KC_COMM, KC_K,    KC_SCLN, KC_DOT
#define __GAMES_R0_L__ KC_F4
#define __GAMES_R1_L__ KC_Z
#define __GAMES_R2_L__ KC_P
#define __GAMES_R3_L__ KC_LSFT
#define __GAMES_R0_R__ KC_N
#define __GAMES_R1_R__ KC_Y
#define __GAMES_R2_R__ KC_F7
#define __GAMES_R3_R__ KC_ESC
#define __GAMES_TH_L__ KC_LALT
#define __GAMES_TH_C__ KC_X
#define __GAMES_TH_R__ KC_B
#define __GAMES_R4_1__ KC_J
#define __GAMES_R4_2__ __GAMES_R3_R__
#define __GAMES_R4_3__ KC_LCTL


// clang-format on
