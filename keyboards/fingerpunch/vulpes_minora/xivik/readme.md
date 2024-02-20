# vulpes minora

* Keyboard Maintainer: sadekbaroudi
* Hardware Supported: vulpes minora (xivik)

Make example for this keyboard (after setting up your build environment):
```
    make fingerpunch/vulpes_minora/xivik:default RGBLIGHT_ENABLE=yes ENCODER_ENABLE=yes
```

Options are:
```
    RGBLIGHT_ENABLE=yes
    HAPTIC_FEEDBACK=yes
    ENCODER_ENABLE=yes
    CIRQUE_ENABLE=yes
    FP_TRACKBALL_ENABLE=yes
```

See [build environment setup](https://docs.qmk.fm/#/getting_started_build_tools) then the [make instructions](https://docs.qmk.fm/#/getting_started_make_guide) for more information.

## Build Guide

See:
https://github.com/sadekbaroudi/vulpes-minora/


## Sadek's personal peacock trackpad build

`bin/fp_build.sh -k vulpes_minora/xivik -m sadekbaroudi -i -r -e "RGB_MATRIX_ENABLE=yes FP_XIVIK_V01=yes"`

Select `VIK_PEACOCK` for vik option