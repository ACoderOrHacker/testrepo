// Generate the include/oe/detections/compiler_detection.h
// Copyright (C) 2026 ACoderOrHacker

const fs = require('fs');
const path = require('path');

const compilers = [
    {macro: 'OE_COMPILER_ACC', condition: 'defined(__ACC__)'},
    {macro: 'OE_COMPILER_ALTIUM_MICROBLAZE', condition: 'defined(__CMB__)'},
    {macro: 'OE_COMPILER_ALTIUM_C_TO_HARDWARE', condition: 'defined(__CHC__)'},
    {macro: 'OE_COMPILER_AMSTERDAM_COMPILER_KIT', condition: 'defined(__ACK__)'},
    {macro: 'OE_COMPILER_ARM_COMPILER', condition: 'defined(__CC_ARM)'},
    {macro: 'OE_COMPILER_AZTEC_C', condition: 'defined(AZTEC_C) || defined(__AZTEC_C__)'},
    {macro: 'OE_COMPILER_BORLAND_CPP', condition: 'defined(__BORLANDC__) || defined(__CODEGEARC__)'},
    {macro: 'OE_COMPILER_CC65', condition: 'defined(CC65)'},
    {macro: 'OE_COMPILER_IBM_XL_C_CPP', condition: 'defined(__ibmxl__) || defined(__xlC__)'},
    {macro: 'OE_COMPILER_IBM_Z_OS_XL_C', condition: 'defined(__IBMC__)'},
    {macro: 'OE_COMPILER_IBM_Z_OS_XL_CPP', condition: 'defined(__IBMCPP__)'},
    {macro: 'OE_COMPILER_CLANG', condition: 'defined(__clang__)'},
    {macro: 'OE_COMPILER_LLVM', condition: 'defined(__llvm__)'},
    {macro: 'OE_COMPILER_COMEAU_CPP', condition: 'defined(__COMO__)'},
    {macro: 'OE_COMPILER_COMPAQ_C', condition: 'defined(__DECC) || defined(__VAXC) || defined(VAXC)'},
    {macro: 'OE_COMPILER_COMPAQ_CPP', condition: 'defined(__DECCXX)'},
    {macro: 'OE_COMPILER_CONVEXC', condition: 'defined(__convexc__)'},
    {macro: 'OE_COMPILER_COMPCERT', condition: 'defined(__COMPCERT)'},
    {macro: 'OE_COMPILER_COVERITY', condition: 'defined(__COVERITY__)'},
    {macro: 'OE_COMPILER_CRAY_C', condition: 'defined(_CRAYC)'},
    {macro: 'OE_COMPILER_DIAB_C_CPP', condition: 'defined(__DCC__)'},
    {macro: 'OE_COMPILER_DICE_C', condition: 'defined(_DICE)'},
    {macro: 'OE_COMPILER_DIGITAL_MARS_C', condition: 'defined(__DMC__)'},
    {macro: 'OE_COMPILER_DIGNUS_SYSTEMS_CPP', condition: 'defined(__SYSC__)'},
    {macro: 'OE_COMPILER_DJGPP', condition: 'defined(__DJGPP__) || defined(__GO32__)'},
    {macro: 'OE_COMPILER_EDG', condition: 'defined(__EDG__)'},
    {macro: 'OE_COMPILER_PATHSCALE_CPP', condition: 'defined(__PATHCC__)'},
    {macro: 'OE_COMPILER_FUJITSU_CPP', condition: 'defined(__FCC_VERSION)'},
    {macro: 'OE_COMPILER_GCC', condition: 'defined(__GNUC__)'},
    {macro: 'OE_COMPILER_GREEN_HILLS_CPP', condition: 'defined(__ghs__)'},
    {macro: 'OE_COMPILER_HP_ANSI_C', condition: 'defined(__HP_cc)'},
    {macro: 'OE_COMPILER_HP_ACPP', condition: 'defined(__HP_aCC)'},
    {macro: 'OE_COMPILER_IAR_C_CPP', condition: 'defined(__IAR_SYSTEMS_ICC__)'},
    {macro: 'OE_COMPILER_IMAGE_CRAFT_C', condition: 'defined(__IMAGECRAFT__)'},
    {macro: 'OE_COMPILER_INTEL_C_CPP', condition: 'defined(__INTEL_COMPILER)'},
    {macro: 'OE_COMPILER_KAI_CPP', condition: 'defined(__KCC__)'},
    {macro: 'OE_COMPILER_KEIL_CARM', condition: 'defined(__CA__) || defined(__KEIL__)'},
    {macro: 'OE_COMPILER_KEIL_C166', condition: 'defined(__C166__)'},
    {macro: 'OE_COMPILER_KEIL_C51', condition: 'defined(__C51__) || defined(__CX51__)'},
    {macro: 'OE_COMPILER_LCC', condition: 'defined(__LCC__)'},
    {macro: 'OE_COMPILER_METAWARE_HIGH_C_CPP', condition: 'defined(__HIGHC__)'},
    {macro: 'OE_COMPILER_METROWERKS_CODEWARRIOR', condition: 'defined(__MWERKS__) || defined(__CWCC__)'},
    {macro: 'OE_COMPILER_MSVC', condition: 'defined(_MSC_VER)'},
    {macro: 'OE_COMPILER_MICROTEC_C_CPP', condition: 'defined(__MRI)'},
    {macro: 'OE_COMPILER_MICROWAY_NDP_C', condition: 'defined(__NDPC__) || defined(__NDPX__)'},
    {macro: 'OE_COMPILER_MINGW64', condition: 'defined(__MINGW64__)'},
    {macro: 'OE_COMPILER_MINGW32', condition: 'defined(__MINGW32__)'},
    {macro: 'OE_COMPILER_SGI_MIPSPRO', condition: 'defined(__sgi) || defined(sgi)'},
    {macro: 'OE_COMPILER_MIRACLE_C', condition: 'defined(MIRACLE)'},
    {macro: 'OE_COMPILER_MPW_CPP', condition: 'defined(__MRC__) || defined(MPW_C) || defined(MPW_CPLUS)'},
    {macro: 'OE_COMPILER_NORCROFT_C', condition: 'defined(__CC_NORCROFT)'},
    {macro: 'OE_COMPILER_NWCC', condition: 'defined(NWCC)'},
    {macro: 'OE_COMPILER_OPEN64', condition: 'defined(__OPEN64__) || defined(__OPENCC__)'},
    {macro: 'OE_COMPILER_ORACLE_PROC', condition: 'defined(ORA_PROC)'},
    {macro: 'OE_COMPILER_ORACLE_SOLARIS_STUDIO_C', condition: 'defined(__SUNPRO_C)'},
    {macro: 'OE_COMPILER_ORACLE_SOLARIS_STUDIO_CPP', condition: 'defined(__SUBPRO_CC)'},
    {macro: 'OE_COMPILER_PACIFIC_C', condition: 'defined(__PACIFIC__)'},
    {macro: 'OE_COMPILER_PALM_C_CPP', condition: 'defined(_PACC_VER)'},
    {macro: 'OE_COMPILER_PELLES_C', condition: 'defined(__POCC__)'},
    {macro: 'OE_COMPILER_PORTLAND_GROUP_C_CPP', condition: 'defined(__PGI)'},
    {macro: 'OE_COMPILER_RENESAS', condition: 'defined(__RENESAS__) && defined(__HITACHI__)'},
    {macro: 'OE_COMPILER_SAS_C', condition: 'defined(SASC) || defined(__SASC) || defined(__SASC__)'},
    {macro: 'OE_COMPILER_SCO_OPENSERVER', condition: 'defined(__SCO_DS)'},
    {macro: 'OE_COMPILER_SDCC', condition: 'defined(SDCC)'},
    {macro: 'OE_COMPILER_SN', condition: 'defined(__SNC__)'},
    {macro: 'OE_COMPILER_STRATUS_VOSC', condition: 'defined(__VOSC__)'},
    {macro: 'OE_COMPILER_SYMANTEC_CPP', condition: 'defined(__SC__)'},
    {macro: 'OE_COMPILER_TENDRA', condition: 'defined(__TenDRA__)'},
    {
        macro: 'OE_COMPILER_TEXAS_INSTRUMENTS_C_CPP',
        condition: 'defined(_TMS320C6X) || defined(__TI_COMPILER_VERSION__)'
    },
    {macro: 'OE_COMPILER_THINKC', condition: 'defined(THINKC3) || defined(THINKC4)'},
    {macro: 'OE_COMPILER_TINYC', condition: 'defined(__TINYC__)'},
    {macro: 'OE_COMPILER_TURBO_C', condition: 'defined(__TURBOC__)'},
    {macro: 'OE_COMPILER_ULTIMATE_C_CPP', condition: 'defined(_UCC)'},
    {macro: 'OE_COMPILER_USLC', condition: 'defined(__USLC__)'},
    {macro: 'OE_COMPILER_VBCC', condition: 'defined(VBCC)'},
    {macro: 'OE_COMPILER_WATCOM_C_CPP', condition: 'defined(__WATCOMC__)'},
    {macro: 'OE_COMPILER_ZORTECH_CPP', condition: 'defined(__ZTC__)'}
];

let output = `/**
 * @file compiler_detections.h
 * @brief Compiler detection macros - generated.
 * Defines OE_COMPILER_* constants, OE_COMPILER_SINGLE, and OE_HAS_*_COMPILER_ID.
 * @copyright Copyright (C) ${new Date().getFullYear()} ACoderOrHacker. All rights reserved.
 */
#ifndef OE_DETECTIONS_COMPILER_DETECTIONS_H
#define OE_DETECTIONS_COMPILER_DETECTIONS_H

/* Compiler ID constants (values assigned sequentially) */
`;

compilers.forEach((comp, index) => {
    const id = index + 1;
    output += `#define ${comp.macro} ${id}\n`;
});

output += `
/* Define OE_COMPILER_SINGLE based on detection */
#if `;
for (let i = 0; i < compilers.length; i++) {
    if (i > 0) {
        output += `#elif ${compilers[i].condition}\n`;
    } else {
        output += `${compilers[i].condition}\n`;
    }
    output += `#define OE_COMPILER_SINGLE ${compilers[i].macro}\n`;
}
output += `#else\n#error "Unknown compiler"\n#endif\n`;

output += `
/* Define OE_HAS_*_COMPILER_ID for each compiler (mutually independent) */
`;
compilers.forEach(comp => {
    const base = comp.macro.replace('OE_COMPILER_', '');
    output += `#if ${comp.condition}\n#define OE_HAS_${base}_COMPILER_ID 1\n#endif\n`;
});

output += `
#endif /* OE_DETECTIONS_COMPILER_DETECTIONS_H */
`;

const filePath = path.join(path.dirname(__dirname), "include", "oe", "detections", "compiler_detections.h");

fs.writeFile(filePath, output, 'utf8', (err) => {
    if (err) throw err;
    console.log('Successfully generate `compiler_detections.h`');
});