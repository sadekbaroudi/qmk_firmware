#!/bin/bash

make fingerpunch/ffkb_byomcu/rgblight_evq:sadekbaroudi STMC=yes
make fingerpunch/ffkb_byomcu/ec11:sadekbaroudi STMC=yes
make fingerpunch/ffkb_byomcu/rgbmatrix_evq:sadekbaroudi STMC=yes
make fingerpunch/ffkb_byomcu/pimoroni_evq:sadekbaroudi STMC=yes
make fingerpunch/ffkb_byomcu/rgbmatrix_pimoroni_evq:sadekbaroudi STMC=yes
make fingerpunch/ffkb_byomcu/rgbmatrix_pimoroni_ec10:sadekbaroudi STMC=yes
make fingerpunch/ffkb_byomcu/rgbmatrix_oled:sadekbaroudi STMC=yes
make fingerpunch/ffkb_byomcu/oled:sadekbaroudi STMC=yes
make fingerpunch/ffkb_byomcu/rgbmatrix:sadekbaroudi STMC=yes
make fingerpunch/ffkb_byomcu/rgbmatrix_ec11:sadekbaroudi STMC=yes
make fingerpunch/ffkb_byomcu/rgbmatrix_oled_ec11:sadekbaroudi STMC=yes
make fingerpunch/ffkb_byomcu/rgblight_pimoroni_evq:sadekbaroudi STMC=yes
make fingerpunch/ffkb_byomcu/rgbmatrix_pimoroni:sadekbaroudi STMC=yes
make fingerpunch/ffkb_byomcu/rgblight_oled_evq:sadekbaroudi STMC=yes
make fingerpunch/ffkb_byomcu/pimoroni:sadekbaroudi STMC=yes
make fingerpunch/ffkb_byomcu/evq:sadekbaroudi STMC=yes
make fingerpunch/ffkb_byomcu/rgblight_ec11:sadekbaroudi STMC=yes
make fingerpunch/ffkb_byomcu/rgblight_pimoroni_ec11:sadekbaroudi STMC=yes
make fingerpunch/ffkb_byomcu/rgblight_oled:sadekbaroudi STMC=yes
make fingerpunch/ffkb_byomcu/oled_ec10:sadekbaroudi STMC=yes
make fingerpunch/ffkb_byomcu/rgbmatrix_ec11_evq:sadekbaroudi STMC=yes
make fingerpunch/ffkb_byomcu/rgblight:sadekbaroudi STMC=yes
make fingerpunch/ffkb_byomcu/no_features:sadekbaroudi STMC=yes
make fingerpunch/ffkb_byomcu/pimoroni_ec11:sadekbaroudi STMC=yes
make fingerpunch/ffkb_byomcu/rgblight_pimoroni:sadekbaroudi STMC=yes
make fingerpunch/ffkb_byomcu/rgblight_ec11_evq:sadekbaroudi STMC=yes
make fingerpunch/ffkb_byomcu/rgbmatrix_oled_evq:sadekbaroudi STMC=yes
make fingerpunch/ffkb_byomcu/oled_evq:sadekbaroudi STMC=yes
make fingerpunch/ffkb_byomcu/ec11_evq:sadekbaroudi STMC=yes
make fingerpunch/ffkb_byomcu/rgblight_oled_ec11:sadekbaroudi STMC=yes

cp fingerpunch_ffkb_byomcu_*_sadekbaroudi.uf2 /mnt/g/My\ Drive/qmk-keyboards/ffkb_stemcell/sadekbaroudi/
