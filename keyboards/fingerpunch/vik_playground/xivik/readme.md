# xivik

* Keyboard Maintainer: sadekbaroudi
* Hardware Supported: xivik controller

## Description

This is a controller, **not** a keyboard. This firmware is intended to serve two purposes:
1) To test your controller
2) A template for copying over the firmware to any keyboard that you use it on.

## Building

Make example for this keyboard (after setting up your build environment):
```
    make fingerpunch/xivik:default RGBLIGHT_ENABLE=yes
```

Options are:
```
    RGBLIGHT_ENABLE=yes
    HAPTIC_FEEDBACK=yes
    // for the options below, select only one, or none, used for testing [VIK modules](https://github.com/sadekbaroudi/vik#known-list-of-vik-certifications)
    VIK_PER56_CIRQUE_LEDS=yes
    VIK_PER56_PMW3360_LEDS=yes
    VIK_PMW3360=yes
    VIK_WEACT_ST7735=yes
    VIK_GC9A01=yes
    VIK_WAVESHARE_22224=yes
    VIK_HAPTIC=yes
```

See [build environment setup](https://docs.qmk.fm/#/getting_started_build_tools) then the [make instructions](https://docs.qmk.fm/#/getting_started_make_guide) for more information.

## Hardware

See:
https://fingerpunch.xyz/products/xivik/
