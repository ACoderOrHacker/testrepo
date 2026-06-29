/**
 * @file compiler.hpp
 * @brief Compiler detection and configuration macros.
 * OE_COMPILER for the compiler name.
 * OE_COMPILER_<COMPILER> for the compiler definition.
 * OE_COMPILER_<COMPILER>_VERSION for the compiler version.
 * Actually, some of the compilers splits C and C++ into separate macros.
 * So, the compiler name definition adds the _C and _CPP suffixes.
 * Include this header after all other headers because some of the compilers
 * defines them in standard libraries.
 * See https://sourceforge.net/p/predef/wiki/Compilers/ for compiler detection.
 */
#pragma once

#ifdef __ACC__
#define OE_COMPILER "ACC"
#define OE_COMPILER_ACC
#elif defined(__CMB__)
#define OE_COMPILER "Altium MicroBlaze C"
#define OE_COMPILER_ALTIUM_MICROBLAZE
#define OE_COMPILER_ALTIUM_MICROBLAZE_VERSION __VERSION__
#elif defined(__CHC__)
#define OE_COMPILER "Altium C-to-Hardware"
#define OE_COMPILER_ALTIUM_C_TO_HARDWARE
#define OE_COMPILER_ALTIUM_C_TO_HARDWARE_VERSION __VERSION__
#elif defined(__ACK__)
#define OE_COMPILER "Amsterdam Compiler Kit"
#define OE_COMPILER_AMSTERDAM_COMPILER_KIT
#elif defined(__CC_ARM)
#define OE_COMPILER "ARM Compiler"
#define OE_COMPILER_ARM_COMPILER
#define OE_COMPILER_ARM_COMPILER_VERSION __ARMCC_VERSION
#elif defined(AZTEC_C) || defined(__AZTEC_C__)
#define OE_COMPILER "Aztec C"
#define OE_COMPILER_AZTEC_C
#define OE_COMPILER_AZTEC_C_VERSION __VERSION
#elif defined(__BORLANDC__) || defined(__CODEGEARC__)
#define OE_COMPILER "Borland C++"
#define OE_COMPILER_BORLAND_CPP
#ifdef __BORLANDC__
#define OE_COMPILER_BORLAND_CPP_VERSION __BORLANDC__
#else
#define OE_COMPILER_BORLAND_CPP_VERSION __CODEGEARC__
#endif
#elif defined(CC65)
#define OE_COMPILER "CC65"
#define OE_COMPILER_CC65
#define OE_COMPILER_CC65_VERSION __CC65__
#elif defined(__ibmxl__) // defined first because it is also defined __clang__
#define OE_COMPILER "IBM XL C/C++"
#define OE_COMPILER_IBM_XL_C_CPP
#define OE_COMPILER_IBM_XL_C_CPP_VERSION __ibmxl_vrm__
#elif defined(__xlC__)
#define OE_COMPILER "IBM XL C/C++ (legacy)"
#define OE_COMPILER_IBM_XL_C_CPP
#define OE_COMPILER_IBM_XL_C_CPP_VERSION __xlC__
#elif defined(__IBMC__)
#define OE_COMPILER "IBM z/OS XL C"
#define OE_COMPILER_IBM_Z_OS_XL_C
#define OE_COMPILER_IBM_Z_OS_XL_C_VERSION __IBMC__
#elif defined(__IBMCPP__)
#define OE_COMPILER "IBM z/OS XL C++"
#define OE_COMPILER_IBM_Z_OS_XL_CPP
#define OE_COMPILER_IBM_Z_OS_XL_CPP_VERSION __IBMCPP__
#elif defined(__clang__)
#define OE_COMPILER "Clang"
#define OE_COMPILER_CLANG
#define OE_COMPILER_CLANG_VERSION __clang_version__
#elif defined(__llvm__) // llvm compiler, clang defines it so it after clang
#define OE_COMPILER "LLVM"
#define OE_COMPILER_LLVM
#elif defined(__COMO__)
#define OE_COMPILER "Comeau C++"
#define OE_COMPILER_COMEAU_CPP
#define OE_COMPILER_COMEAU_CPP_VERSION __COMO_VERSION__
#elif defined(__DECC) || defined(__VAXC) ||                                    \
    defined(VAXC) // we treat __VAXC and VAXC as the C compiler
#define OE_COMPILER "Compaq C"
#define OE_COMPILER_COMPAQ_C
#define OE_COMPILER_COMPAQ_C_VERSION __DECC_VER
#elif defined(__DECCXX)
#define OE_COMPILER "Compaq C++"
#define OE_COMPILER_COMPAQ_CPP
#define OE_COMPILER_COMPAQ_CPP_VERSION __DECCXX_VER
#elif defined(__convexc__)
#define OE_COMPILER "Convex C"
#define OE_COMPILER_CONVEXC
#elif defined(__COMPCERT)
#define OE_COMPILER "CompCert"
#define OE_COMPILER_COMPCERT
#elif defined(__COVERITY__)
#define OE_COMPILER "Coverity"
#define OE_COMPILER_COVERITY
#elif defined(_CRAYC)
#define OE_COMPILER "Cray C"
#define OE_COMPILER_CRAY_C
#define OE_COMPILER_CRAY_C_VERSION _RELEASE
#elif defined(__DCC__)
#define OE_COMPILER "Diab C/C++"
#define OE_COMPILER_DIAB_C_CPP
#define OE_COMPILER_DIAB_C_CPP_VERSION __VERSION_NUMBER__
#elif defined(_DICE)
#define OE_COMPILER "DICE C"
#define OE_COMPILER_DICE_C
#elif defined(__DMC__)
#define OE_COMPILER "Digital Mars C"
#define OE_COMPILER_DIGITAL_MARS_C
#define OE_COMPILER_DIGITAL_MARS_C_VERSION __DMC__
#elif defined(__SYSC__)
#define OE_COMPILER "Dignus Systems/C++"
#define OE_COMPILER_DIGNUS_SYSTEMS_CPP
#define OE_COMPILER_DIGNUS_SYSTEMS_CPP_VERSION __SYSC_VER__
#elif defined(__DJGPP__) || defined(__GO32__)
#define OE_COMPILER "DJGPP"
#define OE_COMPILER_DJGPP
#ifdef __DJGPP__
#define OE_COMPILER_DJGPP_VERSION __DJGPP__
#endif
#elif defined(__EDG__)
#define OE_COMPILER "EDG"
#define OE_COMPILER_EDG
#define OE_COMPILER_EDG_VERSION __EDG_VERSION__
#elif defined(__PATHCC__)
#define OE_COMPILER "PathScale C++"
#define OE_COMPILER_PATHSCALE_CPP
#define OE_COMPILER_PATHSCALE_CPP_VERSION __PATHCC__
#elif defined(__FCC_VERSION)
#define OE_COMPILER "Fujitsu C++"
#define OE_COMPILER_FUJITSU_CPP
#define OE_COMPILER_FUJITSU_CPP_VERSION __FCC_VERSION
#elif defined(__GNUC__)
#define OE_COMPILER "GCC"
#define OE_COMPILER_GCC
#define OE_COMPILER_GCC_VERSION __GNUC__
#elif defined(__ghs__)
#define OE_COMPILER "Green Hills C++"
#define OE_COMPILER_GREEN_HILLS_CPP
#define OE_COMPILER_GREEN_HILLS_CPP_VERSION __GHS_VERSION_NUMBER__
#elif defined(__HP_cc)
#define OE_COMPILER "HP ANSI C"
#define OE_COMPILER_HP_ANSI_C
#elif defined(__HP_aCC)
#define OE_COMPILER "HP aC++"
#define OE_COMPILER_HP_ACPP
#define OE_COMPILER_HP_ACPP_VERSION __HP_aCC
#elif defined(__IAR_SYSTEMS_ICC__)
#define OE_COMPILER "IAR C/C++"
#define OE_COMPILER_IAR_C_CPP
#define OE_COMPILER_IAR_C_CPP_VERSION __VER__
#elif defined(__IMAGECRAFT__)
#define OE_COMPILER "ImageCraft C"
#define OE_COMPILER_IMAGE_CRAFT_C
#elif defined(__INTEL_COMPILER)
#define OE_COMPILER "Intel C/C++"
#define OE_COMPILER_INTEL_C_CPP
#define OE_COMPILER_INTEL_C_CPP_VERSION __INTEL_COMPILER
#elif defined(__KCC__)
#define OE_COMPILER "KAI C++"
#define OE_COMPILER_KAI_CPP
#define OE_COMPILER_KAI_CPP_VERSION __KCC_VERSION
#elif defined(__CA__) || defined(__KEIL__)
#define OE_COMPILER "Keil CARM"
#define OE_COMPILER_KEIL_CARM
#ifdef __CA__
#define OE_COMPILER_KEIL_CARM_VERSION __CA__
#endif
#elif defined(__C166__)
#define OE_COMPILER "Keil C166"
#define OE_COMPILER_KEIL_C166
#define OE_COMPILER_KEIL_C166_VERSION __C166__
#elif defined(__C51__) || defined(__CX51__)
#define OE_COMPILER "Keil C51"
#define OE_COMPILER_KEIL_C51
#define OE_COMPILER_KEIL_C51_VERSION __C51__
#elif defined(__LCC__)
#define OE_COMPILER "LCC"
#define OE_COMPILER_LCC
#elif defined(__HIGHC__)
#define OE_COMPILER "MetaWare High C/C++"
#define OE_COMPILER_METAWARE_HIGH_C_CPP
#elif defined(__MWERKS__)
#define OE_COMPILER "Metrowerks CodeWarrior"
#define OE_COMPILER_METROWERKS_CODEWARRIOR
#define OE_COMPILER_METROWERKS_CODEWARRIOR_VERSION __MWERKS__
#elif defined(__CWCC__) // ditto
#define OE_COMPILER "Metrowerks CodeWarrior"
#define OE_COMPILER_METROWERKS_CODEWARRIOR
#define OE_COMPILER_METROWERKS_CODEWARRIOR_VERSION __CWCC__
#elif defined(_MSC_VER)
#define OE_COMPILER "Microsoft Visual C++"
#define OE_COMPILER_MICROSOFT_VISUAL_CPP
#define OE_COMPILER_MICROSOFT_VISUAL_CPP_VERSION _MSC_VER
#elif defined(__MRI)
#define OE_COMPILER "Microtec C/C++"
#define OE_COMPILER_MICROTEC_C_CPP
#elif defined(__NDPC__) || defined(__NDPX__)
#define OE_COMPILER "Microway NDP C"
#define OE_COMPILER_MICROWAY_NDP_C
#elif defined(__MINGW64__)
#define OE_COMPILER "MinGW64"
#define OE_COMPILER_MINGW64
#define OE_COMPILER_MINGW64_VERSION_MAJOR __MINGW64_MAJOR_VERSION
#define OE_COMPILER_MINGW64_VERSION_MINOR __MINGW64_MINOR_VERSION
#define OE_COMPILER_MINGW64_VERSION                                            \
    OE_COMPILER_MINGW64_VERSION_MAJOR * 100 + OE_COMPILER_MINGW64_VERSION_MINOR
#elif defined(__MINGW32__)
#define OE_COMPILER "MinGW32"
#define OE_COMPILER_MINGW32
#define OE_COMPILER_MINGW32_VERSION_MAJOR __MINGW32_MAJOR_VERSION
#define OE_COMPILER_MINGW32_VERSION_MINOR __MINGW32_MINOR_VERSION
#define OE_COMPILER_MINGW32_VERSION                                            \
    OE_COMPILER_MINGW32_VERSION_MAJOR * 100 + OE_COMPILER_MINGW32_VERSION_MINOR
#elif defined(__sgi) || defined(sgi)
#define OE_COMPILER "SGI MIPSpro"
#define OE_COMPILER_SGI_MIPSPRO
#ifdef _COMPILER_VERSION
#define OE_COMPILER_SGI_MIPSPRO_VERSION _COMPILER_VERSION
#elif defined(_SGI_COMPILER_VERSION)
#define OE_COMPILER_SGI_MIPSPRO_VERSION _SGI_COMPILER_VERSION
#endif
#elif defined(MIRACLE)
#define OE_COMPILER "Miracle C"
#define OE_COMPILER_MIRACLE_C
#elif defined(__MRC__) || defined(MPW_C) || defined(MPW_CPLUS)
#define OE_COMPILER "MPW C++"
#define OE_COMPILER_MPW_CPP
#ifdef __MRC__
#define OE_COMPILER_MPW_CPP_VERSION __MRC__
#endif
#elif defined(__CC_NORCROFT)
#define OE_COMPILER "Norcroft C"
#define OE_COMPILER_NORCROFT_C
#define OE_COMPILER_NORCROFT_C_VERSION __ARMCC_VERSION
#elif defined(NWCC)
#define OE_COMPILER "NWCC"
#define OE_COMPILER_NWCC
#elif defined(__OPEN64__) || defined(__OPENCC__)
#define OE_COMPILER "Open64"
#define OE_COMPILER_OPEN64
#define OE_COMPILER_OPEN64_VERSION_MAJOR __OPENCC__
#define OE_COMPILER_OPEN64_VERSION_MINOR __OPENCC_MINOR__
#define OE_COMPILER_OPEN64_VERSION                                             \
    OE_COMPILER_OPEN64_VERSION_MAJOR * 100 + OE_COMPILER_OPEN64_VERSION_MINOR
#elif defined(ORA_PROC)
#define OE_COMPILER "Oracle Pro*C" // wtf, what is pro*c???
#define OE_COMPILER_ORACLE_PROC
#elif defined(__SUNPRO_C)
#define OE_COMPILER "Oracle Solaris Studio C"
#define OE_COMPILER_ORACLE_SOLARIS_STUDIO_C
#define OE_COMPILER_ORACLE_SOLARIS_STUDIO_C_VERSION __SUNPRO_C
#elif defined(__SUBPRO_CC)
#define OE_COMPILER "Oracle Solaris Studio C++"
#define OE_COMPILER_ORACLE_SOLARIS_STUDIO_CPP
#define OE_COMPILER_ORACLE_SOLARIS_STUDIO_CPP_VERSION __SUBPRO_CC
#elif defined(__PACIFIC__)
#define OE_COMPILER "Pacific C"
#define OE_COMPILER_PACIFIC_C
#elif defined(_PACC_VER)
#define OE_COMPILER "Palm C/C++"
#define OE_COMPILER_PALM_C_CPP
#define OE_COMPILER_PALM_C_CPP_VERSION _PACC_VER
#elif defined(__POCC__)
#define OE_COMPILER "Pelles C"
#define OE_COMPILER_PELLES_C
#define OE_COMPILER_PELLES_C_VERSION __POCC__
#elif defined(__PGI)
#define OE_COMPILER "Portland Group C/C++"
#define OE_COMPILER_PORTLAND_GROUP_C_CPP
#define OE_COMPILER_PORTLAND_GROUP_C_CPP_VERSION __PGIC__
#elif defined(__RENESAS__) defined(__HITACHI__)
#define OE_COMPILER "Renesas"
#define OE_COMPILER_RENESAS
#ifdef __RENESAS_VERSION__
#define OE_COMPILER_RENESAS_VERSION __RENESAS_VERSION__
#else
#define OE_COMPILER_RENESAS_VERSION __HITACHI_VERSION__
#endif
#elif defined(SASC) || defined(__SASC) || defined(__SASC__)
#define OE_COMPILER "SAS/C"
#define OE_COMPILER_SAS_C
#ifdef __VERSION__
#define OE_COMPILER_SAS_C_VERSION __VERSION__
#else
#ifdef __SASC__
#define OE_COMPILER_SAS_C_VERSION __SASC__
#endif
#endif
#elif defined(__SCO_DS)
#define OE_COMPILER "SCO OpenServer"
#define OE_COMPILER_SCO_OPENSERVER
#elif defined(SDCC)
#define OE_COMPILER "Small Device C Compiler"
#define OE_COMPILER_SDCC
#define OE_COMPILER_SDCC_VERSION SDCC
#elif defined(__SNC__)
#define OE_COMPILER "SN Compiler"
#define OE_COMPILER_SN
#elif defined(__VOSC__)
#define OE_COMPILER "Stratus VOS C"
#define OE_COMPILER_STRATUS_VOSC
#define OE_COMPILER_STRATUS_VOSC_VERSION __VOSC__
#elif defined(__SC__)
#define OE_COMPILER "Symantec C++"
#define OE_COMPILER_SYMANTEC_CPP
#define OE_COMPILER_SYMANTEC_CPP_VERSION __SC__
#elif defined(__TenDRA__)
#define OE_COMPILER "TenDRA"
#define OE_COMPILER_TENDRA
#define OE_COMPILER_TENDRA_VERSION __TenDRA__
#elif defined(_TMS320C6X) || defined(__TI_COMPILER_VERSION__)
#define OE_COMPILER "Texas Instruments C/C++ Compiler"
#define OE_COMPILER_TEXAS_INSTRUMENTS_C_CPP
#define OE_COMPILER_TEXAS_INSTRUMENTS_C_CPP_VERSION __TI_COMPILER_VERSION__
#elif defined(THINKC3) || defined(THINKC4)
#define OE_COMPILER "ThinkC"
#define OE_COMPILER_THINKC
#ifdef THINKC3
#define OE_COMPILER_THINKC_VERSION 3
#else
#define OE_COMPILER_THINKC_VERSION 4
#endif
#elif defined(__TINYC__)
#define OE_COMPILER "TinyC"
#define OE_COMPILER_TINYC
#elif defined(__TURBOC__)
#define OE_COMPILER "Turbo C"
#define OE_COMPILER_TURBO_C
#define OE_COMPILER_TURBO_C_VERSION __TURBOC__
#elif defined(_UCC)
#define OE_COMPILER "Ultimate C/C++"
#define OE_COMPILER_ULTIMATE_C_CPP
#define OE_COMPILER_ULTIMATE_C_CPP_VERSION_MAJOR _MAJOR_REV
#define OE_COMPILER_ULTIMATE_C_CPP_VERSION_MINOR _MINOR_REV
#define OE_COMPILER_ULTIMATE_C_CPP_VERSION                                     \
    OE_COMPILER_ULTIMATE_C_CPP_VERSION_MAJOR * 100 +                           \
        OE_COMPILER_ULTIMATE_C_CPP_VERSION_MINOR
#elif defined(__USLC__)
#define OE_COMPILER "USL C"
#define OE_COMPILER_USLC
#define OE_COMPILER_USLC_VERSION __SCO_VERSION__
#elif defined(VBCC)
#define OE_COMPILER "VBCC"
#define OE_COMPILER_VBCC
#elif defined(__WATCOMC__)
#define OE_COMPILER "Watcom C/C++"
#define OE_COMPILER_WATCOM_C_CPP
#define OE_COMPILER_WATCOM_C_CPP_VERSION __WATCOMC__
#elif defined(__ZTC__)
#define OE_COMPILER "Zortech C++"
#define OE_COMPILER_ZORTECH_CPP
#define OE_COMPILER_ZORTECH_CPP_VERSION __ZTC__
#else
#error "Unknown compiler"
#endif
