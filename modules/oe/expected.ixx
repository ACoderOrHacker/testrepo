module;

#define OE_EXPECTED_USE_MODULES
#include <oe/expected.hpp>

export module oe:expected;

export namespace oe {
using namespace impl::expected;
}

