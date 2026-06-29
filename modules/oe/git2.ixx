module;

#define OE_GIT2_USE_MODULES
#include <oe/git2.hpp>

export module oe:git2;

export namespace oe {
using namespace impl::git2;
}

