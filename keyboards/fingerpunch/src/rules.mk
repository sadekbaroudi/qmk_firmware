DEFERRED_EXEC_ENABLE = yes
SRC +=  keyboards/fingerpunch/src/fp.c \
        keyboards/fingerpunch/src/fp_haptic.c \
        keyboards/fingerpunch/src/fp_audio.c \
        keyboards/fingerpunch/src/fp_keyhandler.c \
        keyboards/fingerpunch/src/fp_encoder.c \
        keyboards/fingerpunch/src/fp_pointing.c \
        keyboards/fingerpunch/src/fp_rgb_common.c \
        keyboards/fingerpunch/src/fp_rgblight.c \
        keyboards/fingerpunch/src/fp_rgb_matrix.c \
		keyboards/fingerpunch/src/fp_os_detection.c

ifeq ($(strip $(FP_CONVERT_TO)), svlinky_v01)
        VIK_ENABLE = yes
        OPT_DEFS += -DFP_CONVERT_TO_SVLINKY_V01
endif
ifeq ($(strip $(FP_CONVERT_TO)), svlinky_v02)
        VIK_ENABLE = yes
        OPT_DEFS += -DFP_CONVERT_TO_SVLINKY_V02
endif
ifeq ($(strip $(FP_CONVERT_TO)), xivik_v01)
        VIK_ENABLE = yes
        OPT_DEFS += -DFP_CONVERT_TO_XIVIK_V01
endif
ifeq ($(strip $(FP_CONVERT_TO)), xivik_v02)
        VIK_ENABLE = yes
        OPT_DEFS += -DFP_CONVERT_TO_XIVIK_V02
endif
ifeq ($(strip $(FP_CONVERT_TO)), xivik_v03)
        VIK_ENABLE = yes
        OPT_DEFS += -DFP_CONVERT_TO_XIVIK_V03
endif

ifeq ($(strip $(VIK_ENABLE)), yes)
	include keyboards/fingerpunch/src/vik/rules.mk
	OPT_DEFS += -DVIK_ENABLE
endif
