#include "keyboards/fingerpunch/src/fp_os_detection.h"

#ifdef OS_DETECTION_ENABLE
bool is_mac = false;
void fp_set_macos(bool macos) {
    is_mac = macos;
}
#elif FP_MAC_PREFERRED
const bool is_mac = true;
#else
const bool is_mac = false;
#endif
