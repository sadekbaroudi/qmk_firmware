#!/bin/bash

# TODO: consolidate all the build files into one

cp keyboards/handwired/enigma36/config-v1.h keyboards/handwired/enigma36/config.h
cp keyboards/handwired/enigma36/rules-v1.mk keyboards/handwired/enigma36/rules.mk
make handwired/enigma36:sadekbaroudi ; cp .build/handwired_enigma36_sadekbaroudi* /mnt/c/Users/sadek/Google\ Drive/qmk-keyboards/enigma36-v1/ ;
rm keyboards/handwired/enigma36/config.h
rm keyboards/handwired/enigma36/rules.mk
