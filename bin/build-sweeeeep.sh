#!/bin/bash

make fingerpunch/sweeeeep/no_features:sadekbaroudi
make fingerpunch/sweeeeep/oled:sadekbaroudi
make fingerpunch/sweeeeep/rgblight:sadekbaroudi
make fingerpunch/sweeeeep/rgblight_oled:sadekbaroudi
cp .build/fingerpunch_sweeeeep_*_sadekbaroudi*.hex /mnt/g/My\ Drive/qmk-keyboards/sweeeeep/sadekbaroudi/

make fingerpunch/sweeeeep/no_features:default
make fingerpunch/sweeeeep/oled:default
make fingerpunch/sweeeeep/rgblight:default
make fingerpunch/sweeeeep/rgblight_oled:default
cp .build/fingerpunch_sweeeeep_*_default*.hex /mnt/g/My\ Drive/qmk-keyboards/sweeeeep/default/
