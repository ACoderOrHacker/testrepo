/**
 * @file system.hpp
 * @brief Platform detection macros
 * OX_PLATFORM for platform's name
 * OX_PLATFORM_<NAME> for platform check
 * OX_PLATFORM_<NAME>_VERSION for platform version
 * See https://sourceforge.net/p/predef/wiki/OperatingSystems/ for OS detection
 */
#pragma once

#if defined(__ANDROID__)
#include <android/api-level.h> // for __ANDROID_API_
#define OX_PLATFORM "android"
#define OX_PLATFORM_ANDROID
#define OX_PLATFORM_ANDROID_API_LEVEL __ANDROID_API__
#elif defined(_AIX) || defined(__TOS_AIX__) // AIX OS
#define OX_PLATFORM "aix"
#define OX_PLATFORM_AIX
#ifdef _AIX43
#define OX_PLATFORM_AIX_VERSION "43" // 4.3
#elif defined(_AIX41)
#define OX_PLATFORM_AIX_VERSION "41" // 4.1
#elif defined(_AIX3) || defined(_AIX32)
#define OX_PLATFORM_AIX_VERSION "32" // 3.2.x
#endif
#elif defined(UTS) // Amdahl UTS
#define OX_PLATFORM "amdahl"
#define OX_PLATFORM_AMDHAL
#elif defined(AMIGA) || defined(__amigaos)
#define OX_PLATFORM "amiga"
#define OX_PLATFORM_AMIGA
#elif defined(aegis)
#define OX_PLATFORM "aegis"
#define OX_PLATFORM_AEGIS
#elif defined(apollo)
#define OX_PLATFORM "apollo"
#define OX_PLATFORM_APOLLO
#elif defined(__BEOS__)
#define OX_PLATFORM "beos"
#define OX_PLATFORM_BEOS
#elif defined(__bg__) || defined(__THW_BLUEGENE__)
#define OX_PLATFORM "BlueGene"
#define OX_PLATFORM_BLUE_GENE
#elif defined(__bgq__)
#define OX_PLATFORM "BlueGeneQ"
#define OX_PLATFORM_BLUE_GENE_Q
#define OX_PLATFORM_BLUE_GENE_Q_VERSION __bgq__
#elif defined(__TOS_BGQ__)
#define OX_PLATFORM "BlueGeneQ"
#define OX_PLATFORM_BLUE_GENE_Q
#define OX_PLATFORM_BLUE_GENE_Q_VERSION __TOS_BGQ__
#elif defined(__convex__)
#define OX_PLATFORM "convex"
#define OX_PLATFORM_CONVEX
#elif defined(__bsdi__)
#define OX_PLATFORM "bsdos"
#define OX_PLATFORM_BSD_OS
#elif defined(__CYGWIN__)
#define OX_PLATFORM "cygwin"
#define OX_PLATFORM_CYGWIN
#elif defined(DGUX) || defined(__DGUX__) || defined(__dgux__)
#define OX_PLATFORM "dgux"
#define OX_PLATFORM_DGUX
#elif defined(__DragonFly__)
#define OX_PLATFORM "dragonfly"
#define OX_PLATFORM_DRAGONFLY
#elif defined(_SEQUENT_) || defined(__sequent__)
#define OX_PLATFORM "dynix/ptx"
#define OX_PLATFORM_DYNIX_PTX
#elif defined(__ECOS)
#define OX_PLATFORM "ecos"
#define OX_PLATFORM_ECOS
#elif defined(__EMX__)
#define OX_PLATFORM "emx"
#define OX_PLATFORM_EMX
#elif defined(__FreeBSD__)
#include <osreldate.h>
#define OX_PLATFORM "freebsd"
#define OX_PLATFORM_FREEBSD
#define OX_PLATFORM_FREEBSD_VERSION __FreeBSD_version
#elif defined(__GNU__) || defined(__gnu_hurd__)
#define OX_PLATFORM "GNU"
#define OX_PLATFORM_GNU
#elif defined(__FreeBSD_kernel__) && defined(__GLIBC__)
#define OX_PLATFORM "GNU/kFreeBSD"
#define OX_PLATFORM_GNU_KFREEBSD
#elif defined(__gnu_linux__)
#define OX_PLATFORM "GNU/Linux"
#define OX_PLATFORM_GNU_LINUX
#elif defined(__hiuxmpp)
#define OX_PLATFORM "HP-UX"
#define OX_PLATFORM_HP_UX
#elif defined(hpux) || defined(_hpux) || defined(__hpux)
#define OX_PLATFORM "HP-UX"
#define OX_PLATFORM_HP_UX
#elif defined(__OS400__)
#define OX_PLATFORM "IBM OS/400"
#define OX_PLATFORM_IBM_OS_400
#define OX_PLATFORM_IBM_OS_400_VERSION __OS400_TGTVRM__
#elif defined(__INTEGRITY)
#define OX_PLATFORM "Integrity"
#define OX_PLATFORM_INTEGRITY
#elif defined(__INTERIX)
#define OX_PLATFORM "Interix"
#define OX_PLATFORM_INTERIX
#elif defined(sgi) || defined(__sgi)
#define OX_PLATFORM "IRIX"
#define OX_PLATFORM_IRIX
#elif defined(__linux__)
#define OX_PLATFORM "Linux"
#define OX_PLATFORM_LINUX
#elif defined(__Lynx__)
#define OX_PLATFORM "Lynx"
#define OX_PLATFORM_LYNX
#elif defined(macintosh) || defined(Macintosh) ||                              \
    (defined(__APPLE__) && defined(__MACH__))
#define OX_PLATFORM "macOS"
#define OX_PLATFORM_MACOS
#elif defined(__OS9000) || defined(_OSK)
#define OX_PLATFORM "Microware OS-9"
#define OX_PLATFORM_MICROWARE_OS_9
#elif defined(__minix)
#define OX_PLATFORM "Minix"
#define OX_PLATFORM_MINIX
#elif defined(__MORPHOS__)
#define OX_PLATFORM "MorphOS"
#define OX_PLATFORM_MORPHOS
#elif defined(mpeix) || defined(__mpexl)
#define OX_PLATFORM "MPE/iX"
#define OX_PLATFORM_MPE_IX
#elif defined(__MSDOS__) || defined(_MSDOS) || defined(MSDOS) ||               \
    defined(__DOS__)
#define OX_PLATFORM "MS-DOS"
#define OX_PLATFORM_MS_DOS
#elif defined(__NetBSD__)
#define OX_PLATFORM "NetBSD"
#define OX_PLATFORM_NETBSD
#define OX_PLATFORM_NETBSD_VERSION __NetBSD_Version__
#elif defined(__TANDEM)
#define OX_PLATFORM "NonStop"
#define OX_PLATFORM_NONSTOP
#elif defined(__nucleus__)
#define OX_PLATFORM "Nucleus"
#define OX_PLATFORM_NUCLEUS
#elif defined(__OpenBSD__)
#define OX_PLATFORM "OpenBSD"
#define OX_PLATFORM_OPENBSD
#elif defined(_OS2) || defined(__OS2__) || defined(OS2) || defined(__TOS_OS2__)
#define OX_PLATFORM "OS/2"
#define OX_PLATFORM_OS_2
#elif defined(__palmos__)
#define OX_PLATFORM "PalmOS"
#define OX_PLATFORM_PALMOS
#elif defined(EPLAN9)
#define OX_PLATFORM "Plan9"
#define OX_PLATFORM_PLAN_9
#elif defined(pyr)
#define OX_PLATFORM "Pyramid"
#define OX_PLATFORM_PYRAMID
#elif defined(__QNX__) || defined(__QNXNTO__)
#define OX_PLATFORM "QNX"
#define OX_PLATFORM_QNX
#ifdef BBNDK_VERSION_CURRENT
#define OX_PLATFORM_QNX_VERSION BBNDK_VERSION_CURRENT
#elif defined(_NTO_VERSION)
#define OX_PLATFORM_QNX_VERSION _NTO_VERSION
#endif
#elif defined(sinux)
#define OX_PLATFORM "Reliant UNIX"
#define OX_PLATFORM_RELIANT_UNIX
#elif defined(_SCO_DS) || defined(M_I386) || defined(M_XENIX)
#define OX_PLATFORM "SCO OpenServer"
#define OX_PLATFORM_SCO_OPEN_SERVER
#elif defined(sun) || defined(__sun)
#if defined(__SVR4) || defined(__svr4__)
#define OX_PLATFORM "Solaris"
#define OX_PLATFORM_SOLARIS
#else
#define OX_PLATFORM "SunOS"
#define OX_PLATFORM_SUN_OS
#endif
#elif defined(__VOS__)
#define OX_PLATFORM "Stratus VOS"
#define OX_PLATFORM_STRATUS_VOS
#define OX_PLATFORM_STRATUS_VOS_VERSION __VOS__
#elif defined(__sysv__) || defined(__SVR4) || defined(__svr4__) ||             \
    defined(_SYSTYPE_SVR4)
#define OX_PLATFORM "SVR4"
#define OX_PLATFORM_SVR4
#elif defined(__SYLLABLE__)
#define OX_PLATFORM "Syllable"
#define OX_PLATFORM_SYLLABLE
#elif defined(__SYMBIAN32__)
#define OX_PLATFORM "Symbian"
#define OX_PLATFORM_SYMBIAN
#elif defined(__osf__) || defined(__osf)
#define OX_PLATFORM "OSF/1"
#define OX_PLATFORM_OSF_1
#elif defined(ultrix) || defined(__ultrix) || defined(__ultrix__) ||           \
    (defined(unix) && defined(vax))
#define OX_PLATFORM "Ultrix"
#define OX_PLATFORM_ULTRIX
#elif defined(_UNICOS)
#define OX_PLATFORM "UNICOS"
#define OX_PLATFORM_UNICOS
#define OX_PLATFORM_UNICOS_VERSION _UNICOS
#elif defined(_CRAY) || defined(__crayx1)
#define OX_PLATFORM "UNICOS/mp"
#define OX_PLATFORM_UNICOS_MP
#elif defined(__unix__) || defined(__unix)
#define OX_PLATFORM "UNIX"
#define OX_PLATFORM_UNIX
#elif defined(sco) || defined(_UNIXWARE7)
#define OX_PLATFORM "UNIXWare"
#define OX_PLATFORM_UNIX_WARE
#elif defined(_UWIN)
#define OX_PLATFORM "UWin"
#define OX_PLATFORM_UWIN
#elif defined(VMS) || defined(__VMS)
#define OX_PLATFORM "VMS"
#define OX_PLATFORM_VMS
#define OX_PLATFORM_VMS_VERSION __VMS_VER
#elif defined(_WIN16)
#define OX_PLATFORM "Windows 16-bit"
#define OX_PLATFORM_WIN16
#elif defined(_WIN32) || defined(_WIN64)
#define OX_PLATFORM "Windows"
#define OX_PLATFORM_WINDOWS
#elif defined(_WIN32_WCE)
#define OX_PLATFORM "Windows CE"
#define OX_PLATFORM_WINDOWS_CE
#define OX_PLATFORM_WINDOWS_CE_VERSION _WIN32_WCE
#elif defined(_WINDU_SOURCE)
#define OX_PLATFORM "Wind/U"
#define OX_PLATFORM_WIND_U
#define OX_PLATFORM_WIND_U_VERSION _WINDU_SOURCE
#elif defined(__MVS__) || defined(__HOS_MVS__) || defined(__TOS_MVS__)
#define OX_PLATFORM "z/OS"
#define OX_PLATFORM_ZOS
#else
#error "Unknown platform"
#endif

#ifdef _POSIX_VERSION
#define OX_PLATFORM_POSIX_SYSTEM
#endif
