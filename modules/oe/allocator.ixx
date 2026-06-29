module;

#define OE_ALLOCATOR_USE_MODULES
#include <oe/allocator.hpp>

export module oe:allocator;

export namespace oe {
using namespace impl::allocator;
}

