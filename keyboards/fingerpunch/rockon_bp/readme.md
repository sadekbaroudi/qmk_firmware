# rockon (black pill)

An ergonomic 50% keyboard

* Keyboard Maintainer: [sadekbaroudi](https://github.com/sadekbaroudi)

(unimplemented for black pill as of now) Rock On supports vial! If you want to use Vial, go to https://github.com/sadekbaroudi/vial-qmk/keyboards/fingerpunch/rockon_bp/

To build the firmware for this keyboard (after setting up your build environment), select from one of the following, depending on what features you have on your board:

    make fingerpunch/rockon_bp/no-features:default
    make fingerpunch/rockon_bp/oled:default
    make fingerpunch/rockon_bp/rgblight:default
    make fingerpunch/rockon_bp/rgblight-oled:default
    make fingerpunch/rockon_bp/rgbmatrix:default
    make fingerpunch/rockon_bp/rgbmatrix-oled:default
    make fingerpunch/rockon_bp/ec11:default
    make fingerpunch/rockon_bp/oled_ec11:default
    make fingerpunch/rockon_bp/rgblight_ec11:default
    make fingerpunch/rockon_bp/rgblight_oled_ec11:default
    make fingerpunch/rockon_bp/rgbmatrix_ec11:default
    make fingerpunch/rockon_bp/rgbmatrix_oled_ec11:default

(As of April 2022, Vial not supported for this board yet) If using the vial repository, use these:
    make fingerpunch/rockon_bp/no-features:vial
    make fingerpunch/rockon_bp/oled:vial
    make fingerpunch/rockon_bp/rgblight:vial
    make fingerpunch/rockon_bp/rgblight-oled:vial
    make fingerpunch/rockon_bp/rgbmatrix:vial
    make fingerpunch/rockon_bp/rgbmatrix-oled:vial
    make fingerpunch/rockon_bp/ec11:vial
    make fingerpunch/rockon_bp/oled_ec11:vial
    make fingerpunch/rockon_bp/rgblight_ec11:vial
    make fingerpunch/rockon_bp/rgblight_oled_ec11:vial
    make fingerpunch/rockon_bp/rgbmatrix_ec11:vial
    make fingerpunch/rockon_bp/rgbmatrix_oled_ec11:vial

Example of flashing this keyboard:

    make fingerpunch/rockon_bp/no-features:default:flash

Or in the vial repository:

    make fingerpunch/rockon_bp/no-features:vial:flash

See the [build environment setup](https://docs.qmk.fm/#/getting_started_build_tools) and the [make instructions](https://docs.qmk.fm/#/getting_started_make_guide) for more information. Brand new to QMK? Start with our [Complete Newbs Guide](https://docs.qmk.fm/#/newbs).
