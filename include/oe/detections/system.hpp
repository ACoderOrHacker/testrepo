/**
 * @file system.hpp
 * @brief Platform detection macros
 * OE_PLATFORM for platform's name
 * OE_PLATFORM_<NAME> for platform check
 * OE_PLATFORM_<NAME>_VERSION for platform version
 * See https://sourceforge.net/p/predef/wiki/OperatingSystems/ for OS detection
 */
#pragma once

#if defined(__ANDROID__)
#    include <android/api-level.h> // for __ANDROID_API_
#    define OE_PLATFORM "android"
#    define OE_PLATFORM_ANDROID
#    define OE_PLATFORM_ANDROID_API_LEVEL __ANDROID_API__
#elif defined(_AIX) || defined(__TOS_AIX__) // AIX OS
#    define OE_PLATFORM "aix"
#    define OE_PLATFORM_AIX
#    ifdef _AIX43
#        define OE_PLATFORM_AIX_VERSION "43" // 4.3
#    elif defined(_AIX41)
#        define OE_PLATFORM_AIX_VERSION "41" // 4.1
#    elif defined(_AIX3) || defined(_AIX32)
#        define OE_PLATFORM_AIX_VERSION "32" // 3.2.x
#    endif
#elif defined(UTS) // Amdahl UTS
#    define OE_PLATFORM "amdahl"
#    define OE_PLATFORM_AMDHAL
#elif defined(AMIGA) || defined(__amigaos)
#    define OE_PLATFORM "amiga"
#    define OE_PLATFORM_AMIGA
#elif defined(aegis)
#    define OE_PLATFORM "aegis"
#    define OE_PLATFORM_AEGIS
#elif defined(apollo)
#    define OE_PLATFORM "apollo"
#    define OE_PLATFORM_APOLLO
#elif defined(__BEOS__)
#    define OE_PLATFORM "beos"
#    define OE_PLATFORM_BEOS
#elif defined(__bg__) || defined(__THW_BLUEGENE__)
#    define OE_PLATFORM "BlueGene"
#    define OE_PLATFORM_BLUE_GENE
#elif defined(__bgq__)
#    define OE_PLATFORM "BlueGeneQ"
#    define OE_PLATFORM_BLUE_GENE_Q
#    define OE_PLATFORM_BLUE_GENE_Q_VERSION __bgq__
#elif defined(__TOS_BGQ__)
#    define OE_PLATFORM "BlueGeneQ"
#    define OE_PLATFORM_BLUE_GENE_Q
#    define OE_PLATFORM_BLUE_GENE_Q_VERSION __TOS_BGQ__
#elif defined(__convex__)
#    define OE_PLATFORM "convex"
#    define OE_PLATFORM_CONVEX
#elif defined(__bsdi__)
#    define OE_PLATFORM "bsdos"
#    define OE_PLATFORM_BSD_OS
#elif defined(__CYGWIN__)
#    define OE_PLATFORM "cygwin"
#    define OE_PLATFORM_CYGWIN
#elif defined(DGUX) || defined(__DGUX__) || defined(__dgux__)
#    define OE_PLATFORM "dgux"
#    define OE_PLATFORM_DGUX
#elif defined(__DragonFly__)
#    define OE_PLATFORM "dragonfly"
#    define OE_PLATFORM_DRAGONFLY
#elif defined(_SEQUENT_) || defined(__sequent__)
#    define OE_PLATFORM "dynix/ptx"
#    define OE_PLATFORM_DYNIX_PTX
#elif defined(__ECOS)
#    define OE_PLATFORM "ecos"
#    define OE_PLATFORM_ECOS
#elif defined(__EMX__)
#    define OE_PLATFORM "emx"
#    define OE_PLATFORM_EMX
#elif defined(__FreeBSD__)
#    include <osreldate.h>
#    define OE_PLATFORM "freebsd"
#    define OE_PLATFORM_FREEBSD
#    define OE_PLATFORM_FREEBSD_VERSION __FreeBSD_version
#elif defined(__GNU__) || defined(__gnu_hurd__)
#    define OE_PLATFORM "GNU"
#    define OE_PLATFORM_GNU
#elif defined(__FreeBSD_kernel__) && defined(__GLIBC__)
#    define OE_PLATFORM "GNU/kFreeBSD"
#    define OE_PLATFORM_GNU_KFREEBSD
#elif defined(__gnu_linux__)
#    define OE_PLATFORM "GNU/Linux"
#    define OE_PLATFORM_GNU_LINUX
#elif defined(__hiuxmpp)
#    define OE_PLATFORM "HP-UX"
#    define OE_PLATFORM_HP_UX
#elif defined(hpux) || defined(_hpux) || defined(__hpux)
#    define OE_PLATFORM "HP-UX"
#    define OE_PLATFORM_HP_UX
#elif defined(__OS400__)
#    define OE_PLATFORM "IBM OS/400"
#    define OE_PLATFORM_IBM_OS_400
#    define OE_PLATFORM_IBM_OS_400_VERSION __OS400_TGTVRM__
#elif defined(__INTEGRITY)
#    define OE_PLATFORM "Integrity"
#    define OE_PLATFORM_INTEGRITY
#elif defined(__INTERIX)
#    define OE_PLATFORM "Interix"
#    define OE_PLATFORM_INTERIX
#elif defined(sgi) || defined(__sgi)
#    define OE_PLATFORM "IRIX"
#    define OE_PLATFORM_IRIX
#elif defined(__linux__)
#    define OE_PLATFORM "Linux"
#    define OE_PLATFORM_LINUX
#elif defined(__Lynx__)
#    define OE_PLATFORM "Lynx"
#    define OE_PLATFORM_LYNX
#elif defined(macintosh) || defined(Macintosh) || (defined(__APPLE__) && defined(__MACH__))
#    define OE_PLATFORM "macOS"
#    define OE_PLATFORM_MACOS
#elif defined(__OS9000) || defined(_OSK)
#    define OE_PLATFORM "Microware OS-9"
#    define OE_PLATFORM_MICROWARE_OS_9
#elif defined(__minix)
#    define OE_PLATFORM "Minix"
#    define OE_PLATFORM_MINIX
#elif defined(__MORPHOS__)
#    define OE_PLATFORM "MorphOS"
#    define OE_PLATFORM_MORPHOS
#elif defined(mpeix) || defined(__mpexl)
#    define OE_PLATFORM "MPE/iX"
#    define OE_PLATFORM_MPE_IX
#elif defined(__MSDOS__) || defined(_MSDOS) || defined(MSDOS) || defined(__DOS__)
#    define OE_PLATFORM "MS-DOS"
#    define OE_PLATFORM_MS_DOS
#elif defined(__NetBSD__)
#    define OE_PLATFORM "NetBSD"
#    define OE_PLATFORM_NETBSD
#    define OE_PLATFORM_NETBSD_VERSION __NetBSD_Version__
#elif defined(__TANDEM)
#    define OE_PLATFORM "NonStop"
#    define OE_PLATFORM_NONSTOP
#elif defined(__nucleus__)
#    define OE_PLATFORM "Nucleus"
#    define OE_PLATFORM_NUCLEUS
#elif defined(__OpenBSD__)
#    define OE_PLATFORM "OpenBSD"
#    define OE_PLATFORM_OPENBSD
#elif defined(_OS2) || defined(__OS2__) || defined(OS2) || defined(__TOS_OS2__)
#    define OE_PLATFORM "OS/2"
#    define OE_PLATFORM_OS_2
#elif defined(__palmos__)
#    define OE_PLATFORM "PalmOS"
#    define OE_PLATFORM_PALMOS
#elif defined(EPLAN9)
#    define OE_PLATFORM "Plan9"
#    define OE_PLATFORM_PLAN_9
#elif defined(pyr)
#    define OE_PLATFORM "Pyramid"
#    define OE_PLATFORM_PYRAMID
#elif defined(__QNX__) || defined(__QNXNTO__)
#    define OE_PLATFORM "QNX"
#    define OE_PLATFORM_QNX
#    ifdef BBNDK_VERSION_CURRENT
#        define OE_PLATFORM_QNX_VERSION BBNDK_VERSION_CURRENT
#    elif defined(_NTO_VERSION)
#        define OE_PLATFORM_QNX_VERSION _NTO_VERSION
#    endif
#elif defined(sinux)
#    define OE_PLATFORM "Reliant UNIX"
#    define OE_PLATFORM_RELIANT_UNIX
#elif defined(_SCO_DS) || defined(M_I386) || defined(M_XENIX)
#    define OE_PLATFORM "SCO OpenServer"
#    define OE_PLATFORM_SCO_OPEN_SERVER
#elif defined(sun) || defined(__sun)
#    if defined(__SVR4) || defined(__svr4__)
#        define OE_PLATFORM "Solaris"
#        define OE_PLATFORM_SOLARIS
#    else
#        define OE_PLATFORM "SunOS"
#        define OE_PLATFORM_SUN_OS
#    endif
#elif defined(__VOS__)
#    define OE_PLATFORM "Stratus VOS"
#    define OE_PLATFORM_STRATUS_VOS
#    define OE_PLATFORM_STRATUS_VOS_VERSION __VOS__
#elif defined(__sysv__) || defined(__SVR4) || defined(__svr4__) || defined(_SYSTYPE_SVR4)
#    define OE_PLATFORM "SVR4"
#    define OE_PLATFORM_SVR4
#elif defined(__SYLLABLE__)
#    define OE_PLATFORM "Syllable"
#    define OE_PLATFORM_SYLLABLE
#elif defined(__SYMBIAN32__)
#    define OE_PLATFORM "Symbian"
#    define OE_PLATFORM_SYMBIAN
#elif defined(__osf__) || defined(__osf)
#    define OE_PLATFORM "OSF/1"
#    define OE_PLATFORM_OSF_1
#elif defined(ultrix) || defined(__ultrix) || defined(__ultrix__) || (defined(unix) && defined(vax))
#    define OE_PLATFORM "Ultrix"
#    define OE_PLATFORM_ULTRIX
#elif defined(_UNICOS)
#    define OE_PLATFORM "UNICOS"
#    define OE_PLATFORM_UNICOS
#    define OE_PLATFORM_UNICOS_VERSION _UNICOS
#elif defined(_CRAY) || defined(__crayx1)
#    define OE_PLATFORM "UNICOS/mp"
#    define OE_PLATFORM_UNICOS_MP
#elif defined(__unix__) || defined(__unix)
#    define OE_PLATFORM "UNIX"
#    define OE_PLATFORM_UNIX
#elif defined(sco) || defined(_UNIXWARE7)
#    define OE_PLATFORM "UNIXWare"
#    define OE_PLATFORM_UNIX_WARE
#elif defined(_UWIN)
#    define OE_PLATFORM "UWin"
#    define OE_PLATFORM_UWIN
#elif defined(VMS) || defined(__VMS)
#    define OE_PLATFORM "VMS"
#    define OE_PLATFORM_VMS
#    define OE_PLATFORM_VMS_VERSION __VMS_VER
#elif defined(_WIN16)
#    define OE_PLATFORM "Windows 16-bit"
#    define OE_PLATFORM_WIN16
#elif defined(_WIN32) || defined(_WIN64)
#    define OE_PLATFORM "Windows"
#    define OE_PLATFORM_WINDOWS
#elif defined(_WIN32_WCE)
#    define OE_PLATFORM "Windows CE"
#    define OE_PLATFORM_WINDOWS_CE
#    define OE_PLATFORM_WINDOWS_CE_VERSION _WIN32_WCE
#elif defined(_WINDU_SOURCE)
#    define OE_PLATFORM "Wind/U"
#    define OE_PLATFORM_WIND_U
#    define OE_PLATFORM_WIND_U_VERSION _WINDU_SOURCE
#elif defined(__MVS__) || defined(__HOS_MVS__) || defined(__TOS_MVS__)
#    define OE_PLATFORM "z/OS"
#    define OE_PLATFORM_ZOS
#else
#    error "Unknown platform"
#endif

#ifdef _POSIX_VERSION
#    define OE_PLATFORM_POSIX_SYSTEM
#endif
