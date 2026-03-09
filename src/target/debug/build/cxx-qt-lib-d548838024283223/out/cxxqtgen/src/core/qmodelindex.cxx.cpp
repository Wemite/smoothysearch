#include "cxx-qt-lib/qmodelindex.h"
#include "cxx-qt-lib/qstring.h"
#include "cxx-qt-lib/common.h"
#include <cstdint>
#include <new>
#include <type_traits>

#ifdef __GNUC__
#pragma GCC diagnostic ignored "-Wmissing-declarations"
#ifdef __clang__
#pragma clang diagnostic ignored "-Wdollar-in-identifier-extension"
#endif // __clang__
#endif // __GNUC__

namespace rust {
inline namespace cxxbridge1 {
// #include "rust/cxx.h"

#ifndef CXXBRIDGE1_RELOCATABLE
#define CXXBRIDGE1_RELOCATABLE
namespace detail {
template <typename... Ts>
struct make_void {
  using type = void;
};

template <typename... Ts>
using void_t = typename make_void<Ts...>::type;

template <typename Void, template <typename...> class, typename...>
struct detect : std::false_type {};
template <template <typename...> class T, typename... A>
struct detect<void_t<T<A...>>, T, A...> : std::true_type {};

template <template <typename...> class T, typename... A>
using is_detected = detect<void, T, A...>;

template <typename T>
using detect_IsRelocatable = typename T::IsRelocatable;

template <typename T>
struct get_IsRelocatable
    : std::is_same<typename T::IsRelocatable, std::true_type> {};
} // namespace detail

template <typename T>
struct IsRelocatable
    : std::conditional<
          detail::is_detected<detail::detect_IsRelocatable, T>::value,
          detail::get_IsRelocatable<T>,
          std::integral_constant<
              bool, std::is_trivially_move_constructible<T>::value &&
                        std::is_trivially_destructible<T>::value>>::type {};
#endif // CXXBRIDGE1_RELOCATABLE
} // namespace cxxbridge1
} // namespace rust

static_assert(
    ::rust::IsRelocatable<::QModelIndex>::value,
    "type QModelIndex should be trivially move constructible and trivially destructible in C++ to be used as a return value of `parent`, `sibling`, `sibling_at_column` in Rust");
static_assert(
    ::rust::IsRelocatable<::QString>::value,
    "type QString should be trivially move constructible and trivially destructible in C++ to be used as a return value of `qmodelindex_to_debug_qstring` in Rust");
static_assert(
    ::rust::IsRelocatable<::quintptr>::value,
    "type quintptr should be trivially move constructible and trivially destructible in C++ to be used as a return value of `internal_id_quintptr` in Rust");

extern "C" {
::std::int32_t cxxbridge1$194$QModelIndex$column(::QModelIndex const &self) noexcept {
  ::std::int32_t (::QModelIndex::*column$)() const = &::QModelIndex::column;
  return (self.*column$)();
}

bool cxxbridge1$194$QModelIndex$is_valid(::QModelIndex const &self) noexcept {
  bool (::QModelIndex::*is_valid$)() const = &::QModelIndex::isValid;
  return (self.*is_valid$)();
}

void cxxbridge1$194$QModelIndex$parent(::QModelIndex const &self, ::QModelIndex *return$) noexcept {
  ::QModelIndex (::QModelIndex::*parent$)() const = &::QModelIndex::parent;
  new (return$) ::QModelIndex((self.*parent$)());
}

::std::int32_t cxxbridge1$194$QModelIndex$row(::QModelIndex const &self) noexcept {
  ::std::int32_t (::QModelIndex::*row$)() const = &::QModelIndex::row;
  return (self.*row$)();
}

void cxxbridge1$194$QModelIndex$sibling(::QModelIndex const &self, ::std::int32_t row, ::std::int32_t column, ::QModelIndex *return$) noexcept {
  ::QModelIndex (::QModelIndex::*sibling$)(::std::int32_t, ::std::int32_t) const = &::QModelIndex::sibling;
  new (return$) ::QModelIndex((self.*sibling$)(row, column));
}

void cxxbridge1$194$QModelIndex$sibling_at_column(::QModelIndex const &self, ::std::int32_t column, ::QModelIndex *return$) noexcept {
  ::QModelIndex (::QModelIndex::*sibling_at_column$)(::std::int32_t) const = &::QModelIndex::siblingAtColumn;
  new (return$) ::QModelIndex((self.*sibling_at_column$)(column));
}

void cxxbridge1$194$QModelIndex$sibling_at_row(::QModelIndex const &self, ::std::int32_t row, ::QModelIndex *return$) noexcept {
  ::QModelIndex (::QModelIndex::*sibling_at_row$)(::std::int32_t) const = &::QModelIndex::siblingAtRow;
  new (return$) ::QModelIndex((self.*sibling_at_row$)(row));
}

void cxxbridge1$194$QModelIndex$internal_id_quintptr(::QModelIndex const &self, ::quintptr *return$) noexcept {
  ::quintptr (::QModelIndex::*internal_id_quintptr$)() const = &::QModelIndex::internalId;
  new (return$) ::quintptr((self.*internal_id_quintptr$)());
}

::rust::cxxqtlib1::c_void *cxxbridge1$194$QModelIndex$internal_pointer_mut(::QModelIndex const &self) noexcept {
  ::rust::cxxqtlib1::c_void *(::QModelIndex::*internal_pointer_mut$)() const = &::QModelIndex::internalPointer;
  return (self.*internal_pointer_mut$)();
}
} // extern "C"

namespace rust {
namespace cxxqtlib1 {
extern "C" {
void rust$cxxqtlib1$cxxbridge1$194$qmodelindex_init_default(::QModelIndex *return$) noexcept {
  ::QModelIndex (*qmodelindex_init_default$)() = ::rust::cxxqtlib1::construct;
  new (return$) ::QModelIndex(qmodelindex_init_default$());
}

bool rust$cxxqtlib1$cxxbridge1$194$qmodelindex_eq(::QModelIndex const &a, ::QModelIndex const &b) noexcept {
  bool (*qmodelindex_eq$)(::QModelIndex const &, ::QModelIndex const &) = ::rust::cxxqtlib1::operatorEq;
  return qmodelindex_eq$(a, b);
}

void rust$cxxqtlib1$cxxbridge1$194$qmodelindex_to_debug_qstring(::QModelIndex const &value, ::QString *return$) noexcept {
  ::QString (*qmodelindex_to_debug_qstring$)(::QModelIndex const &) = ::rust::cxxqtlib1::toDebugQString;
  new (return$) ::QString(qmodelindex_to_debug_qstring$(value));
}
} // extern "C"
} // namespace cxxqtlib1
} // namespace rust
