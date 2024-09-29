#pragma once
#ifdef OS_DETECTION_ENABLE
extern bool is_mac;
void fp_set_macos(bool macos);
#else
extern const bool is_mac;
#endif
