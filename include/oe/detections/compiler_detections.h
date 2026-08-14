/**
 * @file compiler_detections.h
 * @brief Compiler detection macros - generated.
 * Defines OE_COMPILER_* constants, OE_COMPILER_SINGLE, and OE_HAS_*_COMPILER_ID.
 * @copyright Copyright (C) 2026 ACoderOrHacker. All rights reserved.
 */
#ifndef OE_DETECTIONS_COMPILER_DETECTIONS_H
#define OE_DETECTIONS_COMPILER_DETECTIONS_H

/* Compiler ID constants (values assigned sequentially) */
#define OE_COMPILER_ACC 1
#define OE_COMPILER_ALTIUM_MICROBLAZE 2
#define OE_COMPILER_ALTIUM_C_TO_HARDWARE 3
#define OE_COMPILER_AMSTERDAM_COMPILER_KIT 4
#define OE_COMPILER_ARM_COMPILER 5
#define OE_COMPILER_AZTEC_C 6
#define OE_COMPILER_BORLAND_CPP 7
#define OE_COMPILER_CC65 8
#define OE_COMPILER_IBM_XL_C_CPP 9
#define OE_COMPILER_IBM_Z_OS_XL_C 10
#define OE_COMPILER_IBM_Z_OS_XL_CPP 11
#define OE_COMPILER_CLANG 12
#define OE_COMPILER_LLVM 13
#define OE_COMPILER_COMEAU_CPP 14
#define OE_COMPILER_COMPAQ_C 15
#define OE_COMPILER_COMPAQ_CPP 16
#define OE_COMPILER_CONVEXC 17
#define OE_COMPILER_COMPCERT 18
#define OE_COMPILER_COVERITY 19
#define OE_COMPILER_CRAY_C 20
#define OE_COMPILER_DIAB_C_CPP 21
#define OE_COMPILER_DICE_C 22
#define OE_COMPILER_DIGITAL_MARS_C 23
#define OE_COMPILER_DIGNUS_SYSTEMS_CPP 24
#define OE_COMPILER_DJGPP 25
#define OE_COMPILER_EDG 26
#define OE_COMPILER_PATHSCALE_CPP 27
#define OE_COMPILER_FUJITSU_CPP 28
#define OE_COMPILER_GCC 29
#define OE_COMPILER_GREEN_HILLS_CPP 30
#define OE_COMPILER_HP_ANSI_C 31
#define OE_COMPILER_HP_ACPP 32
#define OE_COMPILER_IAR_C_CPP 33
#define OE_COMPILER_IMAGE_CRAFT_C 34
#define OE_COMPILER_INTEL_C_CPP 35
#define OE_COMPILER_KAI_CPP 36
#define OE_COMPILER_KEIL_CARM 37
#define OE_COMPILER_KEIL_C166 38
#define OE_COMPILER_KEIL_C51 39
#define OE_COMPILER_LCC 40
#define OE_COMPILER_METAWARE_HIGH_C_CPP 41
#define OE_COMPILER_METROWERKS_CODEWARRIOR 42
#define OE_COMPILER_MSVC 43
#define OE_COMPILER_MICROTEC_C_CPP 44
#define OE_COMPILER_MICROWAY_NDP_C 45
#define OE_COMPILER_MINGW64 46
#define OE_COMPILER_MINGW32 47
#define OE_COMPILER_SGI_MIPSPRO 48
#define OE_COMPILER_MIRACLE_C 49
#define OE_COMPILER_MPW_CPP 50
#define OE_COMPILER_NORCROFT_C 51
#define OE_COMPILER_NWCC 52
#define OE_COMPILER_OPEN64 53
#define OE_COMPILER_ORACLE_PROC 54
#define OE_COMPILER_ORACLE_SOLARIS_STUDIO_C 55
#define OE_COMPILER_ORACLE_SOLARIS_STUDIO_CPP 56
#define OE_COMPILER_PACIFIC_C 57
#define OE_COMPILER_PALM_C_CPP 58
#define OE_COMPILER_PELLES_C 59
#define OE_COMPILER_PORTLAND_GROUP_C_CPP 60
#define OE_COMPILER_RENESAS 61
#define OE_COMPILER_SAS_C 62
#define OE_COMPILER_SCO_OPENSERVER 63
#define OE_COMPILER_SDCC 64
#define OE_COMPILER_SN 65
#define OE_COMPILER_STRATUS_VOSC 66
#define OE_COMPILER_SYMANTEC_CPP 67
#define OE_COMPILER_TENDRA 68
#define OE_COMPILER_TEXAS_INSTRUMENTS_C_CPP 69
#define OE_COMPILER_THINKC 70
#define OE_COMPILER_TINYC 71
#define OE_COMPILER_TURBO_C 72
#define OE_COMPILER_ULTIMATE_C_CPP 73
#define OE_COMPILER_USLC 74
#define OE_COMPILER_VBCC 75
#define OE_COMPILER_WATCOM_C_CPP 76
#define OE_COMPILER_ZORTECH_CPP 77

/* Define OE_COMPILER_SINGLE based on detection */
#if defined(__ACC__)
#define OE_COMPILER_SINGLE OE_COMPILER_ACC
#elif defined(__CMB__)
#define OE_COMPILER_SINGLE OE_COMPILER_ALTIUM_MICROBLAZE
#elif defined(__CHC__)
#define OE_COMPILER_SINGLE OE_COMPILER_ALTIUM_C_TO_HARDWARE
#elif defined(__ACK__)
#define OE_COMPILER_SINGLE OE_COMPILER_AMSTERDAM_COMPILER_KIT
#elif defined(__CC_ARM)
#define OE_COMPILER_SINGLE OE_COMPILER_ARM_COMPILER
#elif defined(AZTEC_C) || defined(__AZTEC_C__)
#define OE_COMPILER_SINGLE OE_COMPILER_AZTEC_C
#elif defined(__BORLANDC__) || defined(__CODEGEARC__)
#define OE_COMPILER_SINGLE OE_COMPILER_BORLAND_CPP
#elif defined(CC65)
#define OE_COMPILER_SINGLE OE_COMPILER_CC65
#elif defined(__ibmxl__) || defined(__xlC__)
#define OE_COMPILER_SINGLE OE_COMPILER_IBM_XL_C_CPP
#elif defined(__IBMC__)
#define OE_COMPILER_SINGLE OE_COMPILER_IBM_Z_OS_XL_C
#elif defined(__IBMCPP__)
#define OE_COMPILER_SINGLE OE_COMPILER_IBM_Z_OS_XL_CPP
#elif defined(__clang__)
#define OE_COMPILER_SINGLE OE_COMPILER_CLANG
#elif defined(__llvm__)
#define OE_COMPILER_SINGLE OE_COMPILER_LLVM
#elif defined(__COMO__)
#define OE_COMPILER_SINGLE OE_COMPILER_COMEAU_CPP
#elif defined(__DECC) || defined(__VAXC) || defined(VAXC)
#define OE_COMPILER_SINGLE OE_COMPILER_COMPAQ_C
#elif defined(__DECCXX)
#define OE_COMPILER_SINGLE OE_COMPILER_COMPAQ_CPP
#elif defined(__convexc__)
#define OE_COMPILER_SINGLE OE_COMPILER_CONVEXC
#elif defined(__COMPCERT)
#define OE_COMPILER_SINGLE OE_COMPILER_COMPCERT
#elif defined(__COVERITY__)
#define OE_COMPILER_SINGLE OE_COMPILER_COVERITY
#elif defined(_CRAYC)
#define OE_COMPILER_SINGLE OE_COMPILER_CRAY_C
#elif defined(__DCC__)
#define OE_COMPILER_SINGLE OE_COMPILER_DIAB_C_CPP
#elif defined(_DICE)
#define OE_COMPILER_SINGLE OE_COMPILER_DICE_C
#elif defined(__DMC__)
#define OE_COMPILER_SINGLE OE_COMPILER_DIGITAL_MARS_C
#elif defined(__SYSC__)
#define OE_COMPILER_SINGLE OE_COMPILER_DIGNUS_SYSTEMS_CPP
#elif defined(__DJGPP__) || defined(__GO32__)
#define OE_COMPILER_SINGLE OE_COMPILER_DJGPP
#elif defined(__EDG__)
#define OE_COMPILER_SINGLE OE_COMPILER_EDG
#elif defined(__PATHCC__)
#define OE_COMPILER_SINGLE OE_COMPILER_PATHSCALE_CPP
#elif defined(__FCC_VERSION)
#define OE_COMPILER_SINGLE OE_COMPILER_FUJITSU_CPP
#elif defined(__GNUC__)
#define OE_COMPILER_SINGLE OE_COMPILER_GCC
#elif defined(__ghs__)
#define OE_COMPILER_SINGLE OE_COMPILER_GREEN_HILLS_CPP
#elif defined(__HP_cc)
#define OE_COMPILER_SINGLE OE_COMPILER_HP_ANSI_C
#elif defined(__HP_aCC)
#define OE_COMPILER_SINGLE OE_COMPILER_HP_ACPP
#elif defined(__IAR_SYSTEMS_ICC__)
#define OE_COMPILER_SINGLE OE_COMPILER_IAR_C_CPP
#elif defined(__IMAGECRAFT__)
#define OE_COMPILER_SINGLE OE_COMPILER_IMAGE_CRAFT_C
#elif defined(__INTEL_COMPILER)
#define OE_COMPILER_SINGLE OE_COMPILER_INTEL_C_CPP
#elif defined(__KCC__)
#define OE_COMPILER_SINGLE OE_COMPILER_KAI_CPP
#elif defined(__CA__) || defined(__KEIL__)
#define OE_COMPILER_SINGLE OE_COMPILER_KEIL_CARM
#elif defined(__C166__)
#define OE_COMPILER_SINGLE OE_COMPILER_KEIL_C166
#elif defined(__C51__) || defined(__CX51__)
#define OE_COMPILER_SINGLE OE_COMPILER_KEIL_C51
#elif defined(__LCC__)
#define OE_COMPILER_SINGLE OE_COMPILER_LCC
#elif defined(__HIGHC__)
#define OE_COMPILER_SINGLE OE_COMPILER_METAWARE_HIGH_C_CPP
#elif defined(__MWERKS__) || defined(__CWCC__)
#define OE_COMPILER_SINGLE OE_COMPILER_METROWERKS_CODEWARRIOR
#elif defined(_MSC_VER)
#define OE_COMPILER_SINGLE OE_COMPILER_MSVC
#elif defined(__MRI)
#define OE_COMPILER_SINGLE OE_COMPILER_MICROTEC_C_CPP
#elif defined(__NDPC__) || defined(__NDPX__)
#define OE_COMPILER_SINGLE OE_COMPILER_MICROWAY_NDP_C
#elif defined(__MINGW64__)
#define OE_COMPILER_SINGLE OE_COMPILER_MINGW64
#elif defined(__MINGW32__)
#define OE_COMPILER_SINGLE OE_COMPILER_MINGW32
#elif defined(__sgi) || defined(sgi)
#define OE_COMPILER_SINGLE OE_COMPILER_SGI_MIPSPRO
#elif defined(MIRACLE)
#define OE_COMPILER_SINGLE OE_COMPILER_MIRACLE_C
#elif defined(__MRC__) || defined(MPW_C) || defined(MPW_CPLUS)
#define OE_COMPILER_SINGLE OE_COMPILER_MPW_CPP
#elif defined(__CC_NORCROFT)
#define OE_COMPILER_SINGLE OE_COMPILER_NORCROFT_C
#elif defined(NWCC)
#define OE_COMPILER_SINGLE OE_COMPILER_NWCC
#elif defined(__OPEN64__) || defined(__OPENCC__)
#define OE_COMPILER_SINGLE OE_COMPILER_OPEN64
#elif defined(ORA_PROC)
#define OE_COMPILER_SINGLE OE_COMPILER_ORACLE_PROC
#elif defined(__SUNPRO_C)
#define OE_COMPILER_SINGLE OE_COMPILER_ORACLE_SOLARIS_STUDIO_C
#elif defined(__SUBPRO_CC)
#define OE_COMPILER_SINGLE OE_COMPILER_ORACLE_SOLARIS_STUDIO_CPP
#elif defined(__PACIFIC__)
#define OE_COMPILER_SINGLE OE_COMPILER_PACIFIC_C
#elif defined(_PACC_VER)
#define OE_COMPILER_SINGLE OE_COMPILER_PALM_C_CPP
#elif defined(__POCC__)
#define OE_COMPILER_SINGLE OE_COMPILER_PELLES_C
#elif defined(__PGI)
#define OE_COMPILER_SINGLE OE_COMPILER_PORTLAND_GROUP_C_CPP
#elif defined(__RENESAS__) && defined(__HITACHI__)
#define OE_COMPILER_SINGLE OE_COMPILER_RENESAS
#elif defined(SASC) || defined(__SASC) || defined(__SASC__)
#define OE_COMPILER_SINGLE OE_COMPILER_SAS_C
#elif defined(__SCO_DS)
#define OE_COMPILER_SINGLE OE_COMPILER_SCO_OPENSERVER
#elif defined(SDCC)
#define OE_COMPILER_SINGLE OE_COMPILER_SDCC
#elif defined(__SNC__)
#define OE_COMPILER_SINGLE OE_COMPILER_SN
#elif defined(__VOSC__)
#define OE_COMPILER_SINGLE OE_COMPILER_STRATUS_VOSC
#elif defined(__SC__)
#define OE_COMPILER_SINGLE OE_COMPILER_SYMANTEC_CPP
#elif defined(__TenDRA__)
#define OE_COMPILER_SINGLE OE_COMPILER_TENDRA
#elif defined(_TMS320C6X) || defined(__TI_COMPILER_VERSION__)
#define OE_COMPILER_SINGLE OE_COMPILER_TEXAS_INSTRUMENTS_C_CPP
#elif defined(THINKC3) || defined(THINKC4)
#define OE_COMPILER_SINGLE OE_COMPILER_THINKC
#elif defined(__TINYC__)
#define OE_COMPILER_SINGLE OE_COMPILER_TINYC
#elif defined(__TURBOC__)
#define OE_COMPILER_SINGLE OE_COMPILER_TURBO_C
#elif defined(_UCC)
#define OE_COMPILER_SINGLE OE_COMPILER_ULTIMATE_C_CPP
#elif defined(__USLC__)
#define OE_COMPILER_SINGLE OE_COMPILER_USLC
#elif defined(VBCC)
#define OE_COMPILER_SINGLE OE_COMPILER_VBCC
#elif defined(__WATCOMC__)
#define OE_COMPILER_SINGLE OE_COMPILER_WATCOM_C_CPP
#elif defined(__ZTC__)
#define OE_COMPILER_SINGLE OE_COMPILER_ZORTECH_CPP
#else
#error "Unknown compiler"
#endif

/* Define OE_HAS_*_COMPILER_ID for each compiler (mutually independent) */
#if defined(__ACC__)
#define OE_HAS_ACC_COMPILER_ID 1
#endif
#if defined(__CMB__)
#define OE_HAS_ALTIUM_MICROBLAZE_COMPILER_ID 1
#endif
#if defined(__CHC__)
#define OE_HAS_ALTIUM_C_TO_HARDWARE_COMPILER_ID 1
#endif
#if defined(__ACK__)
#define OE_HAS_AMSTERDAM_COMPILER_KIT_COMPILER_ID 1
#endif
#if defined(__CC_ARM)
#define OE_HAS_ARM_COMPILER_COMPILER_ID 1
#endif
#if defined(AZTEC_C) || defined(__AZTEC_C__)
#define OE_HAS_AZTEC_C_COMPILER_ID 1
#endif
#if defined(__BORLANDC__) || defined(__CODEGEARC__)
#define OE_HAS_BORLAND_CPP_COMPILER_ID 1
#endif
#if defined(CC65)
#define OE_HAS_CC65_COMPILER_ID 1
#endif
#if defined(__ibmxl__) || defined(__xlC__)
#define OE_HAS_IBM_XL_C_CPP_COMPILER_ID 1
#endif
#if defined(__IBMC__)
#define OE_HAS_IBM_Z_OS_XL_C_COMPILER_ID 1
#endif
#if defined(__IBMCPP__)
#define OE_HAS_IBM_Z_OS_XL_CPP_COMPILER_ID 1
#endif
#if defined(__clang__)
#define OE_HAS_CLANG_COMPILER_ID 1
#endif
#if defined(__llvm__)
#define OE_HAS_LLVM_COMPILER_ID 1
#endif
#if defined(__COMO__)
#define OE_HAS_COMEAU_CPP_COMPILER_ID 1
#endif
#if defined(__DECC) || defined(__VAXC) || defined(VAXC)
#define OE_HAS_COMPAQ_C_COMPILER_ID 1
#endif
#if defined(__DECCXX)
#define OE_HAS_COMPAQ_CPP_COMPILER_ID 1
#endif
#if defined(__convexc__)
#define OE_HAS_CONVEXC_COMPILER_ID 1
#endif
#if defined(__COMPCERT)
#define OE_HAS_COMPCERT_COMPILER_ID 1
#endif
#if defined(__COVERITY__)
#define OE_HAS_COVERITY_COMPILER_ID 1
#endif
#if defined(_CRAYC)
#define OE_HAS_CRAY_C_COMPILER_ID 1
#endif
#if defined(__DCC__)
#define OE_HAS_DIAB_C_CPP_COMPILER_ID 1
#endif
#if defined(_DICE)
#define OE_HAS_DICE_C_COMPILER_ID 1
#endif
#if defined(__DMC__)
#define OE_HAS_DIGITAL_MARS_C_COMPILER_ID 1
#endif
#if defined(__SYSC__)
#define OE_HAS_DIGNUS_SYSTEMS_CPP_COMPILER_ID 1
#endif
#if defined(__DJGPP__) || defined(__GO32__)
#define OE_HAS_DJGPP_COMPILER_ID 1
#endif
#if defined(__EDG__)
#define OE_HAS_EDG_COMPILER_ID 1
#endif
#if defined(__PATHCC__)
#define OE_HAS_PATHSCALE_CPP_COMPILER_ID 1
#endif
#if defined(__FCC_VERSION)
#define OE_HAS_FUJITSU_CPP_COMPILER_ID 1
#endif
#if defined(__GNUC__)
#define OE_HAS_GCC_COMPILER_ID 1
#endif
#if defined(__ghs__)
#define OE_HAS_GREEN_HILLS_CPP_COMPILER_ID 1
#endif
#if defined(__HP_cc)
#define OE_HAS_HP_ANSI_C_COMPILER_ID 1
#endif
#if defined(__HP_aCC)
#define OE_HAS_HP_ACPP_COMPILER_ID 1
#endif
#if defined(__IAR_SYSTEMS_ICC__)
#define OE_HAS_IAR_C_CPP_COMPILER_ID 1
#endif
#if defined(__IMAGECRAFT__)
#define OE_HAS_IMAGE_CRAFT_C_COMPILER_ID 1
#endif
#if defined(__INTEL_COMPILER)
#define OE_HAS_INTEL_C_CPP_COMPILER_ID 1
#endif
#if defined(__KCC__)
#define OE_HAS_KAI_CPP_COMPILER_ID 1
#endif
#if defined(__CA__) || defined(__KEIL__)
#define OE_HAS_KEIL_CARM_COMPILER_ID 1
#endif
#if defined(__C166__)
#define OE_HAS_KEIL_C166_COMPILER_ID 1
#endif
#if defined(__C51__) || defined(__CX51__)
#define OE_HAS_KEIL_C51_COMPILER_ID 1
#endif
#if defined(__LCC__)
#define OE_HAS_LCC_COMPILER_ID 1
#endif
#if defined(__HIGHC__)
#define OE_HAS_METAWARE_HIGH_C_CPP_COMPILER_ID 1
#endif
#if defined(__MWERKS__) || defined(__CWCC__)
#define OE_HAS_METROWERKS_CODEWARRIOR_COMPILER_ID 1
#endif
#if defined(_MSC_VER)
#define OE_HAS_MSVC_COMPILER_ID 1
#endif
#if defined(__MRI)
#define OE_HAS_MICROTEC_C_CPP_COMPILER_ID 1
#endif
#if defined(__NDPC__) || defined(__NDPX__)
#define OE_HAS_MICROWAY_NDP_C_COMPILER_ID 1
#endif
#if defined(__MINGW64__)
#define OE_HAS_MINGW64_COMPILER_ID 1
#endif
#if defined(__MINGW32__)
#define OE_HAS_MINGW32_COMPILER_ID 1
#endif
#if defined(__sgi) || defined(sgi)
#define OE_HAS_SGI_MIPSPRO_COMPILER_ID 1
#endif
#if defined(MIRACLE)
#define OE_HAS_MIRACLE_C_COMPILER_ID 1
#endif
#if defined(__MRC__) || defined(MPW_C) || defined(MPW_CPLUS)
#define OE_HAS_MPW_CPP_COMPILER_ID 1
#endif
#if defined(__CC_NORCROFT)
#define OE_HAS_NORCROFT_C_COMPILER_ID 1
#endif
#if defined(NWCC)
#define OE_HAS_NWCC_COMPILER_ID 1
#endif
#if defined(__OPEN64__) || defined(__OPENCC__)
#define OE_HAS_OPEN64_COMPILER_ID 1
#endif
#if defined(ORA_PROC)
#define OE_HAS_ORACLE_PROC_COMPILER_ID 1
#endif
#if defined(__SUNPRO_C)
#define OE_HAS_ORACLE_SOLARIS_STUDIO_C_COMPILER_ID 1
#endif
#if defined(__SUBPRO_CC)
#define OE_HAS_ORACLE_SOLARIS_STUDIO_CPP_COMPILER_ID 1
#endif
#if defined(__PACIFIC__)
#define OE_HAS_PACIFIC_C_COMPILER_ID 1
#endif
#if defined(_PACC_VER)
#define OE_HAS_PALM_C_CPP_COMPILER_ID 1
#endif
#if defined(__POCC__)
#define OE_HAS_PELLES_C_COMPILER_ID 1
#endif
#if defined(__PGI)
#define OE_HAS_PORTLAND_GROUP_C_CPP_COMPILER_ID 1
#endif
#if defined(__RENESAS__) && defined(__HITACHI__)
#define OE_HAS_RENESAS_COMPILER_ID 1
#endif
#if defined(SASC) || defined(__SASC) || defined(__SASC__)
#define OE_HAS_SAS_C_COMPILER_ID 1
#endif
#if defined(__SCO_DS)
#define OE_HAS_SCO_OPENSERVER_COMPILER_ID 1
#endif
#if defined(SDCC)
#define OE_HAS_SDCC_COMPILER_ID 1
#endif
#if defined(__SNC__)
#define OE_HAS_SN_COMPILER_ID 1
#endif
#if defined(__VOSC__)
#define OE_HAS_STRATUS_VOSC_COMPILER_ID 1
#endif
#if defined(__SC__)
#define OE_HAS_SYMANTEC_CPP_COMPILER_ID 1
#endif
#if defined(__TenDRA__)
#define OE_HAS_TENDRA_COMPILER_ID 1
#endif
#if defined(_TMS320C6X) || defined(__TI_COMPILER_VERSION__)
#define OE_HAS_TEXAS_INSTRUMENTS_C_CPP_COMPILER_ID 1
#endif
#if defined(THINKC3) || defined(THINKC4)
#define OE_HAS_THINKC_COMPILER_ID 1
#endif
#if defined(__TINYC__)
#define OE_HAS_TINYC_COMPILER_ID 1
#endif
#if defined(__TURBOC__)
#define OE_HAS_TURBO_C_COMPILER_ID 1
#endif
#if defined(_UCC)
#define OE_HAS_ULTIMATE_C_CPP_COMPILER_ID 1
#endif
#if defined(__USLC__)
#define OE_HAS_USLC_COMPILER_ID 1
#endif
#if defined(VBCC)
#define OE_HAS_VBCC_COMPILER_ID 1
#endif
#if defined(__WATCOMC__)
#define OE_HAS_WATCOM_C_CPP_COMPILER_ID 1
#endif
#if defined(__ZTC__)
#define OE_HAS_ZORTECH_CPP_COMPILER_ID 1
#endif

#endif /* OE_DETECTIONS_COMPILER_DETECTIONS_H */
