#!/usr/bin/env python3
# generate_platform_detections.py
# Copyright (C) 2026 ACoderOrHacker. All rights reserved.

import datetime
import os

platforms = [
    {"macro": "OE_PLATFORM_ANDROID", "condition": "defined(__ANDROID__)"},
    {"macro": "OE_PLATFORM_AIX", "condition": "defined(_AIX) || defined(__TOS_AIX__)"},
    {"macro": "OE_PLATFORM_AMDHAL", "condition": "defined(UTS)"},
    {"macro": "OE_PLATFORM_AMIGA", "condition": "defined(AMIGA) || defined(__amigaos)"},
    {"macro": "OE_PLATFORM_AEGIS", "condition": "defined(aegis)"},
    {"macro": "OE_PLATFORM_APOLLO", "condition": "defined(apollo)"},
    {"macro": "OE_PLATFORM_BEOS", "condition": "defined(__BEOS__)"},
    {
        "macro": "OE_PLATFORM_BLUE_GENE",
        "condition": "defined(__bg__) || defined(__THW_BLUEGENE__)",
    },
    {
        "macro": "OE_PLATFORM_BLUE_GENE_Q",
        "condition": "defined(__bgq__) || defined(__TOS_BGQ__)",
    },
    {"macro": "OE_PLATFORM_CONVEX", "condition": "defined(__convex__)"},
    {"macro": "OE_PLATFORM_BSD_OS", "condition": "defined(__bsdi__)"},
    {"macro": "OE_PLATFORM_CYGWIN", "condition": "defined(__CYGWIN__)"},
    {
        "macro": "OE_PLATFORM_DGUX",
        "condition": "defined(DGUX) || defined(__DGUX__) || defined(__dgux__)",
    },
    {"macro": "OE_PLATFORM_DRAGONFLY", "condition": "defined(__DragonFly__)"},
    {
        "macro": "OE_PLATFORM_DYNIX_PTX",
        "condition": "defined(_SEQUENT_) || defined(__sequent__)",
    },
    {"macro": "OE_PLATFORM_ECOS", "condition": "defined(__ECOS)"},
    {"macro": "OE_PLATFORM_EMX", "condition": "defined(__EMX__)"},
    {"macro": "OE_PLATFORM_FREEBSD", "condition": "defined(__FreeBSD__)"},
    {
        "macro": "OE_PLATFORM_GNU",
        "condition": "defined(__GNU__) || defined(__gnu_hurd__)",
    },
    {
        "macro": "OE_PLATFORM_GNU_KFREEBSD",
        "condition": "defined(__FreeBSD_kernel__) && defined(__GLIBC__)",
    },
    {"macro": "OE_PLATFORM_GNU_LINUX", "condition": "defined(__gnu_linux__)"},
    {
        "macro": "OE_PLATFORM_HP_UX",
        "condition": "defined(hpux) || defined(_hpux) || defined(__hpux) || defined(__hiuxmpp)",
    },
    {"macro": "OE_PLATFORM_IBM_OS_400", "condition": "defined(__OS400__)"},
    {"macro": "OE_PLATFORM_INTEGRITY", "condition": "defined(__INTEGRITY)"},
    {"macro": "OE_PLATFORM_INTERIX", "condition": "defined(__INTERIX)"},
    {"macro": "OE_PLATFORM_IRIX", "condition": "defined(sgi) || defined(__sgi)"},
    {"macro": "OE_PLATFORM_LINUX", "condition": "defined(__linux__)"},
    {"macro": "OE_PLATFORM_LYNX", "condition": "defined(__Lynx__)"},
    {
        "macro": "OE_PLATFORM_MACOS",
        "condition": "defined(macintosh) || defined(Macintosh) || (defined(__APPLE__) && defined(__MACH__))",
    },
    {
        "macro": "OE_PLATFORM_MICROWARE_OS_9",
        "condition": "defined(__OS9000) || defined(_OSK)",
    },
    {"macro": "OE_PLATFORM_MINIX", "condition": "defined(__minix)"},
    {"macro": "OE_PLATFORM_MORPHOS", "condition": "defined(__MORPHOS__)"},
    {"macro": "OE_PLATFORM_MPE_IX", "condition": "defined(mpeix) || defined(__mpexl)"},
    {
        "macro": "OE_PLATFORM_MS_DOS",
        "condition": "defined(__MSDOS__) || defined(_MSDOS) || defined(MSDOS) || defined(__DOS__)",
    },
    {"macro": "OE_PLATFORM_NETBSD", "condition": "defined(__NetBSD__)"},
    {"macro": "OE_PLATFORM_NONSTOP", "condition": "defined(__TANDEM)"},
    {"macro": "OE_PLATFORM_NUCLEUS", "condition": "defined(__nucleus__)"},
    {"macro": "OE_PLATFORM_OPENBSD", "condition": "defined(__OpenBSD__)"},
    {
        "macro": "OE_PLATFORM_OS_2",
        "condition": "defined(_OS2) || defined(__OS2__) || defined(OS2) || defined(__TOS_OS2__)",
    },
    {"macro": "OE_PLATFORM_PALMOS", "condition": "defined(__palmos__)"},
    {"macro": "OE_PLATFORM_PLAN_9", "condition": "defined(EPLAN9)"},
    {"macro": "OE_PLATFORM_PYRAMID", "condition": "defined(pyr)"},
    {
        "macro": "OE_PLATFORM_QNX",
        "condition": "defined(__QNX__) || defined(__QNXNTO__)",
    },
    {"macro": "OE_PLATFORM_RELIANT_UNIX", "condition": "defined(sinux)"},
    {
        "macro": "OE_PLATFORM_SCO_OPEN_SERVER",
        "condition": "defined(_SCO_DS) || defined(M_I386) || defined(M_XENIX)",
    },
    {"macro": "OE_PLATFORM_SOLARIS", "condition": "defined(sun) || defined(__sun)"},
    {"macro": "OE_PLATFORM_STRATUS_VOS", "condition": "defined(__VOS__)"},
    {
        "macro": "OE_PLATFORM_SVR4",
        "condition": "defined(__sysv__) || defined(__SVR4) || defined(__svr4__) || defined(_SYSTYPE_SVR4)",
    },
    {"macro": "OE_PLATFORM_SYLLABLE", "condition": "defined(__SYLLABLE__)"},
    {"macro": "OE_PLATFORM_SYMBIAN", "condition": "defined(__SYMBIAN32__)"},
    {"macro": "OE_PLATFORM_OSF_1", "condition": "defined(__osf__) || defined(__osf)"},
    {
        "macro": "OE_PLATFORM_ULTRIX",
        "condition": "defined(ultrix) || defined(__ultrix) || defined(__ultrix__) || (defined(unix) && defined(vax))",
    },
    {"macro": "OE_PLATFORM_UNICOS", "condition": "defined(_UNICOS)"},
    {
        "macro": "OE_PLATFORM_UNICOS_MP",
        "condition": "defined(_CRAY) || defined(__crayx1)",
    },
    {"macro": "OE_PLATFORM_UNIX", "condition": "defined(__unix__) || defined(__unix)"},
    {
        "macro": "OE_PLATFORM_UNIX_WARE",
        "condition": "defined(sco) || defined(_UNIXWARE7)",
    },
    {"macro": "OE_PLATFORM_UWIN", "condition": "defined(_UWIN)"},
    {"macro": "OE_PLATFORM_VMS", "condition": "defined(VMS) || defined(__VMS)"},
    {"macro": "OE_PLATFORM_WIN16", "condition": "defined(_WIN16)"},
    {"macro": "OE_PLATFORM_WINDOWS", "condition": "defined(_WIN32) || defined(_WIN64)"},
    {"macro": "OE_PLATFORM_WINDOWS_CE", "condition": "defined(_WIN32_WCE)"},
    {"macro": "OE_PLATFORM_WIND_U", "condition": "defined(_WINDU_SOURCE)"},
    {
        "macro": "OE_PLATFORM_ZOS",
        "condition": "defined(__MVS__) || defined(__HOS_MVS__) || defined(__TOS_MVS__)",
    },
]

output_lines = [
    "/**",
    " * @file platform_detections.h",
    " * @brief Platform detection macros - generated.",
    f" * @copyright Copyright (C) {datetime.datetime.now(datetime.timezone.utc).year} ACoderOrHacker",
    " *",
    " * Defines OE_PLATFORM_* constants, OE_PLATFORM_SINGLE, and OE_HAS_*_PLATFORM_ID.",
    " */",
    "#ifndef OE_DETECTIONS_PLATFORM_DETECTIONS_H",
    "#define OE_DETECTIONS_PLATFORM_DETECTIONS_H",
    "",
    "/* Platform ID constants (values assigned sequentially) */",
]

for idx, p in enumerate(platforms, start=1):
    output_lines.append(f"#define {p['macro']} {idx}")

output_lines.append("")
output_lines.append("/* Define OE_PLATFORM_SINGLE based on detection */")
output_lines.append("#if " + platforms[0]["condition"])
output_lines.append(f"#define OE_PLATFORM_SINGLE {platforms[0]['macro']}")
for p in platforms[1:]:
    output_lines.append(f"#elif {p['condition']}")
    output_lines.append(f"#define OE_PLATFORM_SINGLE {p['macro']}")
output_lines.append("#else")
output_lines.append('#error "Unknown platform"')
output_lines.append("#endif")

output_lines.append("")
output_lines.append(
    "/* Define OE_HAS_*_PLATFORM_ID for each platform (mutually independent) */"
)
for p in platforms:
    base = p["macro"].replace("OE_PLATFORM_", "")
    output_lines.append(f"#if {p['condition']}")
    output_lines.append(f"#define OE_HAS_{base}_PLATFORM_ID 1")
    output_lines.append("#endif")

output_lines.append("")
output_lines.append("#endif /* OE_DETECTIONS_PLATFORM_DETECTIONS_H */")

output_text = "\n".join(output_lines)

script_dir = os.path.dirname(os.path.abspath(__file__))
project_root = os.path.dirname(os.path.dirname(script_dir))
target_dir = os.path.join(project_root, "include", "oe", "detections")
os.makedirs(target_dir, exist_ok=True)

target_file = os.path.join(target_dir, "platform_detections.h")
with open(target_file, "w", encoding="utf-8") as f:
    f.write(output_text)

print(f"Successfully generated `{target_file}`")
