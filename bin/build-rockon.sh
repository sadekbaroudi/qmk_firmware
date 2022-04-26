#!/bin/bash

# TODO: consolidate all the build files into one

make fingerpunch/rockon/v1/rgbmatrix_oled:sadekbaroudi
cp .build/fingerpunch_rockon_v1_rgbmatrix_oled_sadekbaroudi.hex /mnt/g/My\ Drive/qmk-keyboards/rock-on/v1/rgbmatrix/fingerpunch_rockon_v1_rgbmatrix_oled_sadekbaroudi.hex

make fingerpunch/rockon/v1/rgblight_oled:sadekbaroudi
cp .build/fingerpunch_rockon_v1_rgblight_oled_sadekbaroudi.hex /mnt/g/My\ Drive/qmk-keyboards/rock-on/v1/rgblight/fingerpunch_rockon_v1_rgblight_oled_sadekbaroudi.hex
