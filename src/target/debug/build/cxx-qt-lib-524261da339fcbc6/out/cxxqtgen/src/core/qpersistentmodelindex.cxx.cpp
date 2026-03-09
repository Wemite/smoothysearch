#include "cxx-qt-lib/qpersistentmodelindex.h"
#include "cxx-qt-lib/qstring.h"
#include "cxx-qt-lib/qmodelindex.h"
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
    ::rust::IsRelocatable<::QPersistentModelIndex>::value,
    "type QPersistentModelIndex should be trivially move constructible and trivially destructible in C++ to be used as a return value of `qpersistentmodelindex_from_qmodelindex`, `qpersistentmodelindex_clone` in Rust");
static_assert(
    ::rust::IsRelocatable<::QString>::value,
    "type QString should be trivially move constructible and trivially destructible in C++ to be used as a return value of `qpersistentmodelindex_to_debug_qstring` in Rust");
static_assert(
    ::rust::IsRelocatable<::QModelIndex>::value,
    "type QModelIndex should be trivially move constructible and trivially destructible in C++ to be used as a return value of `parent`, `sibling` in Rust");

extern "C" {
::std::int32_t cxxbridge1$194$QPersistentModelIndex$column(::QPersistentModelIndex const &self) noexcept {
  ::std::int32_t (::QPersistentModelIndex::*column$)() const = &::QPersistentModelIndex::column;
  return (self.*column$)();
}

bool cxxbridge1$194$QPersistentModelIndex$is_valid(::QPersistentModelIndex const &self) noexcept {
  bool (::QPersistentModelIndex::*is_valid$)() const = &::QPersistentModelIndex::isValid;
  return (self.*is_valid$)();
}

void cxxbridge1$194$QPersistentModelIndex$parent(::QPersistentModelIndex const &self, ::QModelIndex *return$) noexcept {
  ::QModelIndex (::QPersistentModelIndex::*parent$)() const = &::QPersistentModelIndex::parent;
  new (return$) ::QModelIndex((self.*parent$)());
}

::std::int32_t cxxbridge1$194$QPersistentModelIndex$row(::QPersistentModelIndex const &self) noexcept {
  ::std::int32_t (::QPersistentModelIndex::*row$)() const = &::QPersistentModelIndex::row;
  return (self.*row$)();
}

void cxxbridge1$194$QPersistentModelIndex$sibling(::QPersistentModelIndex const &self, ::std::int32_t row, ::std::int32_t column, ::QModelIndex *return$) noexcept {
  ::QModelIndex (::QPersistentModelIndex::*sibling$)(::std::int32_t, ::std::int32_t) const = &::QPersistentModelIndex::sibling;
  new (return$) ::QModelIndex((self.*sibling$)(row, column));
}

void cxxbridge1$194$QPersistentModelIndex$swap(::QPersistentModelIndex &self, ::QPersistentModelIndex &other) noexcept {
  void (::QPersistentModelIndex::*swap$)(::QPersistentModelIndex &) = &::QPersistentModelIndex::swap;
  (self.*swap$)(other);
}
} // extern "C"

namespace rust {
namespace cxxqtlib1 {
extern "C" {
void rust$cxxqtlib1$cxxbridge1$194$qpersistentmodelindex_drop(::QPersistentModelIndex &string) noexcept {
  void (*qpersistentmodelindex_drop$)(::QPersistentModelIndex &) = ::rust::cxxqtlib1::drop;
  qpersistentmodelindex_drop$(string);
}

void rust$cxxqtlib1$cxxbridge1$194$qpersistentmodelindex_from_qmodelindex(::QModelIndex const &index, ::QPersistentModelIndex *return$) noexcept {
  ::QPersistentModelIndex (*qpersistentmodelindex_from_qmodelindex$)(::QModelIndex const &) = ::rust::cxxqtlib1::construct;
  new (return$) ::QPersistentModelIndex(qpersistentmodelindex_from_qmodelindex$(index));
}

void rust$cxxqtlib1$cxxbridge1$194$qpersistentmodelindex_clone(::QPersistentModelIndex const &other, ::QPersistentModelIndex *return$) noexcept {
  ::QPersistentModelIndex (*qpersistentmodelindex_clone$)(::QPersistentModelIndex const &) = ::rust::cxxqtlib1::construct;
  new (return$) ::QPersistentModelIndex(qpersistentmodelindex_clone$(other));
}

bool rust$cxxqtlib1$cxxbridge1$194$qpersistentmodelindex_eq(::QPersistentModelIndex const &a, ::QPersistentModelIndex const &b) noexcept {
  bool (*qpersistentmodelindex_eq$)(::QPersistentModelIndex const &, ::QPersistentModelIndex const &) = ::rust::cxxqtlib1::operatorEq;
  return qpersistentmodelindex_eq$(a, b);
}

void rust$cxxqtlib1$cxxbridge1$194$qpersistentmodelindex_to_debug_qstring(::QPersistentModelIndex const &value, ::QString *return$) noexcept {
  ::QString (*qpersistentmodelindex_to_debug_qstring$)(::QPersistentModelIndex const &) = ::rust::cxxqtlib1::toDebugQString;
  new (return$) ::QString(qpersistentmodelindex_to_debug_qstring$(value));
}
} // extern "C"
} // namespace cxxqtlib1
} // namespace rust
