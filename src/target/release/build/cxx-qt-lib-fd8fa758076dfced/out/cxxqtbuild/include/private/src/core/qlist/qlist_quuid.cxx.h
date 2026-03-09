#pragma once
#include "cxx-qt-lib/quuid.h"
#include "cxx-qt-lib/core/qlist/qlist_QUuid.h"
#include "cxx-qt-lib/common.h"
#if defined(_WIN32)
#include <basetsd.h>
#else
#include <sys/types.h>
#endif

namespace rust {
inline namespace cxxbridge1 {
// #include "rust/cxx.h"

#ifndef CXXBRIDGE1_RUST_ISIZE
#define CXXBRIDGE1_RUST_ISIZE
#if defined(_WIN32)
using isize = SSIZE_T;
#else
using isize = ssize_t;
#endif
#endif // CXXBRIDGE1_RUST_ISIZE
} // namespace cxxbridge1
} // namespace rust
