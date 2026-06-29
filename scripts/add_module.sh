#!/usr/bin/env bash

# Create a c++ module and header files
# Usage: add_module.sh <name>

touch ../modules/oe/$1.ixx
cat <<EOF > ../modules/oe/$1.ixx
module;

#define OE_${1^^}_USE_MODULES
#include <oe/$1.hpp>

export module oe:$1;

export namespace oe {
using namespace impl::$1;
}

EOF

touch ../include/oe/$1.hpp
mkdir ../include/oe/$1
touch ../include/oe/$1/$1.hpp

cat <<EOF > ../include/oe/$1.hpp
#pragma once

#include <oe/$1/$1.hpp>
EOF

cat <<EOF > ../include/oe/$1/$1.hpp
/**
 * @file $1.hpp
 * @brief
 */
#pragma once

#if defined(OE_USE_STD_MODULES) || defined(OE_${1^^}_USE_STD_MODULES)
// std module here
#else
// std header here
#endif

namespace oe {
namespace impl {
namespace $1 {

} // namespace $1
} // namespace impl
} // namespace oe

#ifndef OE_${1^^}_USE_MODULES
namespace oe {
using namespace impl::$1;
}
#endif

EOF

cat <<EOF >> ../include/oe/oe/configs.h.in
\${define OE_${1^^}_ENABLED}
EOF

cat <<EOF >> ../xmake/libs.lua
    .. "$1;"
EOF

cat <<EOF >> ../include/oe/oe.hpp
#include <oe/$1.hpp>
EOF

cat <<EOF >> ../source/oe/$1.d
module oe.$1;

public:

EOF
