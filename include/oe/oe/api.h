#pragma once

#include <oe/platforms/compiler.hpp>
#ifdef OE_SHARED
#ifdef OE_COMPILER_MICROSOFT_VISUAL_CPP
#define OE_API __declspec(dllexport)
#endif
#else
#define OE_API
#endif
