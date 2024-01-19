#pragma once
#include "quantum.h"

#define LAYOUT_xivik( \
  K01, K02, K03, K04, K05, K06, K07, \
  K11, K12, K13, K14, K15, K16, K17, \
  K21, K22, K23, K24, K25, K26, K27, \
  K31, K32, K33, K34, K35, K36, K37 \
  ) \
  { \
    { K01, K02, K03, K04, K05, K06, K07 }, \
    { K11, K12, K13, K14, K15, K16, K17 }, \
    { K21, K22, K23, K24, K25, K26, K27 }, \
    { K31, K32, K33, K34, K35, K36, K37 } \
  }

// General fingerpunch firmware include
#include "keyboards/fingerpunch/src/fp.h"
