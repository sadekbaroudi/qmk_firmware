# sweeeeep

An ergonomic 30% keyboard

* Keyboard Maintainer: [sadekbaroudi](https://github.com/sadekbaroudi)

why the name sweeeeep? because an elite-c is required to support the extra features, and an elite-c has 5 additional pins... so 5 Es for the 5 extra pins. Yes, it's dumb, I know.

# Descripiton

This is a reversible sweep pcb with support for 36 keys, per key leds, oled, and choc switches (no hotswap). In order to continue to support a no diode setup, I added support for the elite-c, and this is now required for the build.

# Firmware

To build the firmware for this keyboard (after setting up your build environment), select from one of the following, depending on what features you have on your board:

    make fingerpunch/sweeeeep/no-features:default
    make fingerpunch/sweeeeep/oled:default
    make fingerpunch/sweeeeep/rgblight:default
    make fingerpunch/sweeeeep/rgblight_oled:default


If using the vial repository, use these:
    make fingerpunch/sweeeeep/no-features:vial
    make fingerpunch/sweeeeep/oled:vial
    make fingerpunch/sweeeeep/rgblight:vial
    make fingerpunch/sweeeeep/rgblight_oled:vial

Example of flashing this keyboard:

    make fingerpunch/sweeeeep/no-features:default:flash

See the [build environment setup](https://docs.qmk.fm/#/getting_started_build_tools) and the [make instructions](https://docs.qmk.fm/#/getting_started_make_guide) for more information. Brand new to QMK? Start with our [Complete Newbs Guide](https://docs.qmk.fm/#/newbs).
