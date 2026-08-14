/**
 * @file platform_detections.h
 * @brief Platform detection macros - generated.
 * @copyright Copyright (C) 2026 ACoderOrHacker
 *
 * Defines OE_PLATFORM_* constants, OE_PLATFORM_SINGLE, and OE_HAS_*_PLATFORM_ID.
 */
#ifndef OE_DETECTIONS_PLATFORM_DETECTIONS_H
#define OE_DETECTIONS_PLATFORM_DETECTIONS_H

/* Platform ID constants (values assigned sequentially) */
#define OE_PLATFORM_ANDROID 1
#define OE_PLATFORM_AIX 2
#define OE_PLATFORM_AMDHAL 3
#define OE_PLATFORM_AMIGA 4
#define OE_PLATFORM_AEGIS 5
#define OE_PLATFORM_APOLLO 6
#define OE_PLATFORM_BEOS 7
#define OE_PLATFORM_BLUE_GENE 8
#define OE_PLATFORM_BLUE_GENE_Q 9
#define OE_PLATFORM_CONVEX 10
#define OE_PLATFORM_BSD_OS 11
#define OE_PLATFORM_CYGWIN 12
#define OE_PLATFORM_DGUX 13
#define OE_PLATFORM_DRAGONFLY 14
#define OE_PLATFORM_DYNIX_PTX 15
#define OE_PLATFORM_ECOS 16
#define OE_PLATFORM_EMX 17
#define OE_PLATFORM_FREEBSD 18
#define OE_PLATFORM_GNU 19
#define OE_PLATFORM_GNU_KFREEBSD 20
#define OE_PLATFORM_GNU_LINUX 21
#define OE_PLATFORM_HP_UX 22
#define OE_PLATFORM_IBM_OS_400 23
#define OE_PLATFORM_INTEGRITY 24
#define OE_PLATFORM_INTERIX 25
#define OE_PLATFORM_IRIX 26
#define OE_PLATFORM_LINUX 27
#define OE_PLATFORM_LYNX 28
#define OE_PLATFORM_MACOS 29
#define OE_PLATFORM_MICROWARE_OS_9 30
#define OE_PLATFORM_MINIX 31
#define OE_PLATFORM_MORPHOS 32
#define OE_PLATFORM_MPE_IX 33
#define OE_PLATFORM_MS_DOS 34
#define OE_PLATFORM_NETBSD 35
#define OE_PLATFORM_NONSTOP 36
#define OE_PLATFORM_NUCLEUS 37
#define OE_PLATFORM_OPENBSD 38
#define OE_PLATFORM_OS_2 39
#define OE_PLATFORM_PALMOS 40
#define OE_PLATFORM_PLAN_9 41
#define OE_PLATFORM_PYRAMID 42
#define OE_PLATFORM_QNX 43
#define OE_PLATFORM_RELIANT_UNIX 44
#define OE_PLATFORM_SCO_OPEN_SERVER 45
#define OE_PLATFORM_SOLARIS 46
#define OE_PLATFORM_STRATUS_VOS 47
#define OE_PLATFORM_SVR4 48
#define OE_PLATFORM_SYLLABLE 49
#define OE_PLATFORM_SYMBIAN 50
#define OE_PLATFORM_OSF_1 51
#define OE_PLATFORM_ULTRIX 52
#define OE_PLATFORM_UNICOS 53
#define OE_PLATFORM_UNICOS_MP 54
#define OE_PLATFORM_UNIX 55
#define OE_PLATFORM_UNIX_WARE 56
#define OE_PLATFORM_UWIN 57
#define OE_PLATFORM_VMS 58
#define OE_PLATFORM_WIN16 59
#define OE_PLATFORM_WINDOWS 60
#define OE_PLATFORM_WINDOWS_CE 61
#define OE_PLATFORM_WIND_U 62
#define OE_PLATFORM_ZOS 63

/* Define OE_PLATFORM_SINGLE based on detection */
#if defined(__ANDROID__)
#define OE_PLATFORM_SINGLE OE_PLATFORM_ANDROID
#elif defined(_AIX) || defined(__TOS_AIX__)
#define OE_PLATFORM_SINGLE OE_PLATFORM_AIX
#elif defined(UTS)
#define OE_PLATFORM_SINGLE OE_PLATFORM_AMDHAL
#elif defined(AMIGA) || defined(__amigaos)
#define OE_PLATFORM_SINGLE OE_PLATFORM_AMIGA
#elif defined(aegis)
#define OE_PLATFORM_SINGLE OE_PLATFORM_AEGIS
#elif defined(apollo)
#define OE_PLATFORM_SINGLE OE_PLATFORM_APOLLO
#elif defined(__BEOS__)
#define OE_PLATFORM_SINGLE OE_PLATFORM_BEOS
#elif defined(__bg__) || defined(__THW_BLUEGENE__)
#define OE_PLATFORM_SINGLE OE_PLATFORM_BLUE_GENE
#elif defined(__bgq__) || defined(__TOS_BGQ__)
#define OE_PLATFORM_SINGLE OE_PLATFORM_BLUE_GENE_Q
#elif defined(__convex__)
#define OE_PLATFORM_SINGLE OE_PLATFORM_CONVEX
#elif defined(__bsdi__)
#define OE_PLATFORM_SINGLE OE_PLATFORM_BSD_OS
#elif defined(__CYGWIN__)
#define OE_PLATFORM_SINGLE OE_PLATFORM_CYGWIN
#elif defined(DGUX) || defined(__DGUX__) || defined(__dgux__)
#define OE_PLATFORM_SINGLE OE_PLATFORM_DGUX
#elif defined(__DragonFly__)
#define OE_PLATFORM_SINGLE OE_PLATFORM_DRAGONFLY
#elif defined(_SEQUENT_) || defined(__sequent__)
#define OE_PLATFORM_SINGLE OE_PLATFORM_DYNIX_PTX
#elif defined(__ECOS)
#define OE_PLATFORM_SINGLE OE_PLATFORM_ECOS
#elif defined(__EMX__)
#define OE_PLATFORM_SINGLE OE_PLATFORM_EMX
#elif defined(__FreeBSD__)
#define OE_PLATFORM_SINGLE OE_PLATFORM_FREEBSD
#elif defined(__GNU__) || defined(__gnu_hurd__)
#define OE_PLATFORM_SINGLE OE_PLATFORM_GNU
#elif defined(__FreeBSD_kernel__) && defined(__GLIBC__)
#define OE_PLATFORM_SINGLE OE_PLATFORM_GNU_KFREEBSD
#elif defined(__gnu_linux__)
#define OE_PLATFORM_SINGLE OE_PLATFORM_GNU_LINUX
#elif defined(hpux) || defined(_hpux) || defined(__hpux) || defined(__hiuxmpp)
#define OE_PLATFORM_SINGLE OE_PLATFORM_HP_UX
#elif defined(__OS400__)
#define OE_PLATFORM_SINGLE OE_PLATFORM_IBM_OS_400
#elif defined(__INTEGRITY)
#define OE_PLATFORM_SINGLE OE_PLATFORM_INTEGRITY
#elif defined(__INTERIX)
#define OE_PLATFORM_SINGLE OE_PLATFORM_INTERIX
#elif defined(sgi) || defined(__sgi)
#define OE_PLATFORM_SINGLE OE_PLATFORM_IRIX
#elif defined(__linux__)
#define OE_PLATFORM_SINGLE OE_PLATFORM_LINUX
#elif defined(__Lynx__)
#define OE_PLATFORM_SINGLE OE_PLATFORM_LYNX
#elif defined(macintosh) || defined(Macintosh) || (defined(__APPLE__) && defined(__MACH__))
#define OE_PLATFORM_SINGLE OE_PLATFORM_MACOS
#elif defined(__OS9000) || defined(_OSK)
#define OE_PLATFORM_SINGLE OE_PLATFORM_MICROWARE_OS_9
#elif defined(__minix)
#define OE_PLATFORM_SINGLE OE_PLATFORM_MINIX
#elif defined(__MORPHOS__)
#define OE_PLATFORM_SINGLE OE_PLATFORM_MORPHOS
#elif defined(mpeix) || defined(__mpexl)
#define OE_PLATFORM_SINGLE OE_PLATFORM_MPE_IX
#elif defined(__MSDOS__) || defined(_MSDOS) || defined(MSDOS) || defined(__DOS__)
#define OE_PLATFORM_SINGLE OE_PLATFORM_MS_DOS
#elif defined(__NetBSD__)
#define OE_PLATFORM_SINGLE OE_PLATFORM_NETBSD
#elif defined(__TANDEM)
#define OE_PLATFORM_SINGLE OE_PLATFORM_NONSTOP
#elif defined(__nucleus__)
#define OE_PLATFORM_SINGLE OE_PLATFORM_NUCLEUS
#elif defined(__OpenBSD__)
#define OE_PLATFORM_SINGLE OE_PLATFORM_OPENBSD
#elif defined(_OS2) || defined(__OS2__) || defined(OS2) || defined(__TOS_OS2__)
#define OE_PLATFORM_SINGLE OE_PLATFORM_OS_2
#elif defined(__palmos__)
#define OE_PLATFORM_SINGLE OE_PLATFORM_PALMOS
#elif defined(EPLAN9)
#define OE_PLATFORM_SINGLE OE_PLATFORM_PLAN_9
#elif defined(pyr)
#define OE_PLATFORM_SINGLE OE_PLATFORM_PYRAMID
#elif defined(__QNX__) || defined(__QNXNTO__)
#define OE_PLATFORM_SINGLE OE_PLATFORM_QNX
#elif defined(sinux)
#define OE_PLATFORM_SINGLE OE_PLATFORM_RELIANT_UNIX
#elif defined(_SCO_DS) || defined(M_I386) || defined(M_XENIX)
#define OE_PLATFORM_SINGLE OE_PLATFORM_SCO_OPEN_SERVER
#elif defined(sun) || defined(__sun)
#define OE_PLATFORM_SINGLE OE_PLATFORM_SOLARIS
#elif defined(__VOS__)
#define OE_PLATFORM_SINGLE OE_PLATFORM_STRATUS_VOS
#elif defined(__sysv__) || defined(__SVR4) || defined(__svr4__) || defined(_SYSTYPE_SVR4)
#define OE_PLATFORM_SINGLE OE_PLATFORM_SVR4
#elif defined(__SYLLABLE__)
#define OE_PLATFORM_SINGLE OE_PLATFORM_SYLLABLE
#elif defined(__SYMBIAN32__)
#define OE_PLATFORM_SINGLE OE_PLATFORM_SYMBIAN
#elif defined(__osf__) || defined(__osf)
#define OE_PLATFORM_SINGLE OE_PLATFORM_OSF_1
#elif defined(ultrix) || defined(__ultrix) || defined(__ultrix__) || (defined(unix) && defined(vax))
#define OE_PLATFORM_SINGLE OE_PLATFORM_ULTRIX
#elif defined(_UNICOS)
#define OE_PLATFORM_SINGLE OE_PLATFORM_UNICOS
#elif defined(_CRAY) || defined(__crayx1)
#define OE_PLATFORM_SINGLE OE_PLATFORM_UNICOS_MP
#elif defined(__unix__) || defined(__unix)
#define OE_PLATFORM_SINGLE OE_PLATFORM_UNIX
#elif defined(sco) || defined(_UNIXWARE7)
#define OE_PLATFORM_SINGLE OE_PLATFORM_UNIX_WARE
#elif defined(_UWIN)
#define OE_PLATFORM_SINGLE OE_PLATFORM_UWIN
#elif defined(VMS) || defined(__VMS)
#define OE_PLATFORM_SINGLE OE_PLATFORM_VMS
#elif defined(_WIN16)
#define OE_PLATFORM_SINGLE OE_PLATFORM_WIN16
#elif defined(_WIN32) || defined(_WIN64)
#define OE_PLATFORM_SINGLE OE_PLATFORM_WINDOWS
#elif defined(_WIN32_WCE)
#define OE_PLATFORM_SINGLE OE_PLATFORM_WINDOWS_CE
#elif defined(_WINDU_SOURCE)
#define OE_PLATFORM_SINGLE OE_PLATFORM_WIND_U
#elif defined(__MVS__) || defined(__HOS_MVS__) || defined(__TOS_MVS__)
#define OE_PLATFORM_SINGLE OE_PLATFORM_ZOS
#else
#error "Unknown platform"
#endif

/* Define OE_HAS_*_PLATFORM_ID for each platform (mutually independent) */
#if defined(__ANDROID__)
#define OE_HAS_ANDROID_PLATFORM_ID 1
#endif
#if defined(_AIX) || defined(__TOS_AIX__)
#define OE_HAS_AIX_PLATFORM_ID 1
#endif
#if defined(UTS)
#define OE_HAS_AMDHAL_PLATFORM_ID 1
#endif
#if defined(AMIGA) || defined(__amigaos)
#define OE_HAS_AMIGA_PLATFORM_ID 1
#endif
#if defined(aegis)
#define OE_HAS_AEGIS_PLATFORM_ID 1
#endif
#if defined(apollo)
#define OE_HAS_APOLLO_PLATFORM_ID 1
#endif
#if defined(__BEOS__)
#define OE_HAS_BEOS_PLATFORM_ID 1
#endif
#if defined(__bg__) || defined(__THW_BLUEGENE__)
#define OE_HAS_BLUE_GENE_PLATFORM_ID 1
#endif
#if defined(__bgq__) || defined(__TOS_BGQ__)
#define OE_HAS_BLUE_GENE_Q_PLATFORM_ID 1
#endif
#if defined(__convex__)
#define OE_HAS_CONVEX_PLATFORM_ID 1
#endif
#if defined(__bsdi__)
#define OE_HAS_BSD_OS_PLATFORM_ID 1
#endif
#if defined(__CYGWIN__)
#define OE_HAS_CYGWIN_PLATFORM_ID 1
#endif
#if defined(DGUX) || defined(__DGUX__) || defined(__dgux__)
#define OE_HAS_DGUX_PLATFORM_ID 1
#endif
#if defined(__DragonFly__)
#define OE_HAS_DRAGONFLY_PLATFORM_ID 1
#endif
#if defined(_SEQUENT_) || defined(__sequent__)
#define OE_HAS_DYNIX_PTX_PLATFORM_ID 1
#endif
#if defined(__ECOS)
#define OE_HAS_ECOS_PLATFORM_ID 1
#endif
#if defined(__EMX__)
#define OE_HAS_EMX_PLATFORM_ID 1
#endif
#if defined(__FreeBSD__)
#define OE_HAS_FREEBSD_PLATFORM_ID 1
#endif
#if defined(__GNU__) || defined(__gnu_hurd__)
#define OE_HAS_GNU_PLATFORM_ID 1
#endif
#if defined(__FreeBSD_kernel__) && defined(__GLIBC__)
#define OE_HAS_GNU_KFREEBSD_PLATFORM_ID 1
#endif
#if defined(__gnu_linux__)
#define OE_HAS_GNU_LINUX_PLATFORM_ID 1
#endif
#if defined(hpux) || defined(_hpux) || defined(__hpux) || defined(__hiuxmpp)
#define OE_HAS_HP_UX_PLATFORM_ID 1
#endif
#if defined(__OS400__)
#define OE_HAS_IBM_OS_400_PLATFORM_ID 1
#endif
#if defined(__INTEGRITY)
#define OE_HAS_INTEGRITY_PLATFORM_ID 1
#endif
#if defined(__INTERIX)
#define OE_HAS_INTERIX_PLATFORM_ID 1
#endif
#if defined(sgi) || defined(__sgi)
#define OE_HAS_IRIX_PLATFORM_ID 1
#endif
#if defined(__linux__)
#define OE_HAS_LINUX_PLATFORM_ID 1
#endif
#if defined(__Lynx__)
#define OE_HAS_LYNX_PLATFORM_ID 1
#endif
#if defined(macintosh) || defined(Macintosh) || (defined(__APPLE__) && defined(__MACH__))
#define OE_HAS_MACOS_PLATFORM_ID 1
#endif
#if defined(__OS9000) || defined(_OSK)
#define OE_HAS_MICROWARE_OS_9_PLATFORM_ID 1
#endif
#if defined(__minix)
#define OE_HAS_MINIX_PLATFORM_ID 1
#endif
#if defined(__MORPHOS__)
#define OE_HAS_MORPHOS_PLATFORM_ID 1
#endif
#if defined(mpeix) || defined(__mpexl)
#define OE_HAS_MPE_IX_PLATFORM_ID 1
#endif
#if defined(__MSDOS__) || defined(_MSDOS) || defined(MSDOS) || defined(__DOS__)
#define OE_HAS_MS_DOS_PLATFORM_ID 1
#endif
#if defined(__NetBSD__)
#define OE_HAS_NETBSD_PLATFORM_ID 1
#endif
#if defined(__TANDEM)
#define OE_HAS_NONSTOP_PLATFORM_ID 1
#endif
#if defined(__nucleus__)
#define OE_HAS_NUCLEUS_PLATFORM_ID 1
#endif
#if defined(__OpenBSD__)
#define OE_HAS_OPENBSD_PLATFORM_ID 1
#endif
#if defined(_OS2) || defined(__OS2__) || defined(OS2) || defined(__TOS_OS2__)
#define OE_HAS_OS_2_PLATFORM_ID 1
#endif
#if defined(__palmos__)
#define OE_HAS_PALMOS_PLATFORM_ID 1
#endif
#if defined(EPLAN9)
#define OE_HAS_PLAN_9_PLATFORM_ID 1
#endif
#if defined(pyr)
#define OE_HAS_PYRAMID_PLATFORM_ID 1
#endif
#if defined(__QNX__) || defined(__QNXNTO__)
#define OE_HAS_QNX_PLATFORM_ID 1
#endif
#if defined(sinux)
#define OE_HAS_RELIANT_UNIX_PLATFORM_ID 1
#endif
#if defined(_SCO_DS) || defined(M_I386) || defined(M_XENIX)
#define OE_HAS_SCO_OPEN_SERVER_PLATFORM_ID 1
#endif
#if defined(sun) || defined(__sun)
#define OE_HAS_SOLARIS_PLATFORM_ID 1
#endif
#if defined(__VOS__)
#define OE_HAS_STRATUS_VOS_PLATFORM_ID 1
#endif
#if defined(__sysv__) || defined(__SVR4) || defined(__svr4__) || defined(_SYSTYPE_SVR4)
#define OE_HAS_SVR4_PLATFORM_ID 1
#endif
#if defined(__SYLLABLE__)
#define OE_HAS_SYLLABLE_PLATFORM_ID 1
#endif
#if defined(__SYMBIAN32__)
#define OE_HAS_SYMBIAN_PLATFORM_ID 1
#endif
#if defined(__osf__) || defined(__osf)
#define OE_HAS_OSF_1_PLATFORM_ID 1
#endif
#if defined(ultrix) || defined(__ultrix) || defined(__ultrix__) || (defined(unix) && defined(vax))
#define OE_HAS_ULTRIX_PLATFORM_ID 1
#endif
#if defined(_UNICOS)
#define OE_HAS_UNICOS_PLATFORM_ID 1
#endif
#if defined(_CRAY) || defined(__crayx1)
#define OE_HAS_UNICOS_MP_PLATFORM_ID 1
#endif
#if defined(__unix__) || defined(__unix)
#define OE_HAS_UNIX_PLATFORM_ID 1
#endif
#if defined(sco) || defined(_UNIXWARE7)
#define OE_HAS_UNIX_WARE_PLATFORM_ID 1
#endif
#if defined(_UWIN)
#define OE_HAS_UWIN_PLATFORM_ID 1
#endif
#if defined(VMS) || defined(__VMS)
#define OE_HAS_VMS_PLATFORM_ID 1
#endif
#if defined(_WIN16)
#define OE_HAS_WIN16_PLATFORM_ID 1
#endif
#if defined(_WIN32) || defined(_WIN64)
#define OE_HAS_WINDOWS_PLATFORM_ID 1
#endif
#if defined(_WIN32_WCE)
#define OE_HAS_WINDOWS_CE_PLATFORM_ID 1
#endif
#if defined(_WINDU_SOURCE)
#define OE_HAS_WIND_U_PLATFORM_ID 1
#endif
#if defined(__MVS__) || defined(__HOS_MVS__) || defined(__TOS_MVS__)
#define OE_HAS_ZOS_PLATFORM_ID 1
#endif

#endif /* OE_DETECTIONS_PLATFORM_DETECTIONS_H */
