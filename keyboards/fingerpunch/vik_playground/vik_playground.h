#pragma once
#include "quantum.h"

#define LAYOUT_vik_playground( \
  K01, K02, K03, \
  K04, K05, K06 \
  ) \
  { \
    { K01, K02, K03 }, \
    { K04, K05, K06 } \
  }

// General fingerpunch firmware include
#include "keyboards/fingerpunch/src/fp.h"
