#include "cxx-qt-lib/qt.h"
#include "cxx-qt-lib/qstring.h"
#include "cxx-qt-lib/core/qlist/qlist_QString.h"
#include "cxx-qt-lib/qstringlist.h"
#include "cxx-qt/casting.h"
#include "cxx-qt-lib/common.h"
#include <new>
#include <type_traits>
#include <utility>
#if defined(_WIN32)
#include <basetsd.h>
#else
#include <sys/types.h>
#endif

#ifdef __GNUC__
#pragma GCC diagnostic ignored "-Wmissing-declarations"
#ifdef __clang__
#pragma clang diagnostic ignored "-Wdollar-in-identifier-extension"
#endif // __clang__
#endif // __GNUC__

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
    ::rust::IsRelocatable<::Qt::CaseSensitivity>::value,
    "type Qt::CaseSensitivity should be trivially move constructible and trivially destructible in C++ to be used as an argument of `contains`, `filter`, `sort` in Rust");
static_assert(
    ::rust::IsRelocatable<::QString>::value,
    "type QString should be trivially move constructible and trivially destructible in C++ to be used as a return value of `join`, `qstringlist_to_debug_qstring` in Rust");
static_assert(
    ::rust::IsRelocatable<::QList_QString>::value,
    "type QList_QString should be trivially move constructible and trivially destructible in C++ to be used as a return value of `qstringlist_as_qlist_qstring` in Rust");
static_assert(
    ::rust::IsRelocatable<::QStringList>::value,
    "type QStringList should be trivially move constructible and trivially destructible in C++ to be used as a return value of `filter`, `qstringlist_clone`, `qstringlist_default` in Rust");

extern "C" {
bool cxxbridge1$194$QStringList$contains(::QStringList const &self, ::QString const &str, ::Qt::CaseSensitivity *cs) noexcept {
  bool (::QStringList::*contains$)(::QString const &, ::Qt::CaseSensitivity) const = &::QStringList::contains;
  return (self.*contains$)(str, ::std::move(*cs));
}

void cxxbridge1$194$QStringList$filter(::QStringList const &self, ::QString const &str, ::Qt::CaseSensitivity *cs, ::QStringList *return$) noexcept {
  ::QStringList (::QStringList::*filter$)(::QString const &, ::Qt::CaseSensitivity) const = &::QStringList::filter;
  new (return$) ::QStringList((self.*filter$)(str, ::std::move(*cs)));
}

void cxxbridge1$194$QStringList$join(::QStringList const &self, ::QString const &separator, ::QString *return$) noexcept {
  ::QString (::QStringList::*join$)(::QString const &) const = &::QStringList::join;
  new (return$) ::QString((self.*join$)(separator));
}

void cxxbridge1$194$QStringList$sort(::QStringList &self, ::Qt::CaseSensitivity *cs) noexcept {
  void (::QStringList::*sort$)(::Qt::CaseSensitivity) = &::QStringList::sort;
  (self.*sort$)(::std::move(*cs));
}

void cxxbridge1$194$QStringList$replace_in_strings(::QStringList &self, ::QString const &before, ::QString const &after, ::Qt::CaseSensitivity *cs, ::QStringList **return$) noexcept {
  ::QStringList &(::QStringList::*replace_in_strings$)(::QString const &, ::QString const &, ::Qt::CaseSensitivity) = &::QStringList::replaceInStrings;
  new (return$) ::QStringList *(&(self.*replace_in_strings$)(before, after, ::std::move(*cs)));
}
} // extern "C"

namespace rust {
namespace cxxqt1 {
extern "C" {
::QList_QString const *rust$cxxqt1$cxxbridge1$194$upcast_qstringlist(::QStringList const *thiz) noexcept {
  ::QList_QString const *(*upcast_qstringlist$)(::QStringList const *) = ::rust::cxxqt1::upcastPtr;
  return upcast_qstringlist$(thiz);
}

::QStringList const *rust$cxxqt1$cxxbridge1$194$downcast_qlist_qstring(::QList_QString const *base) noexcept {
  ::QStringList const *(*downcast_qlist_qstring$)(::QList_QString const *) = ::rust::cxxqt1::downcastPtrStatic;
  return downcast_qlist_qstring$(base);
}
} // extern "C"
} // namespace cxxqt1

namespace cxxqtlib1 {
extern "C" {
void rust$cxxqtlib1$cxxbridge1$194$qstringlist_clone(::QStringList const &list, ::QStringList *return$) noexcept {
  ::QStringList (*qstringlist_clone$)(::QStringList const &) = ::rust::cxxqtlib1::construct;
  new (return$) ::QStringList(qstringlist_clone$(list));
}

void rust$cxxqtlib1$cxxbridge1$194$qstringlist_drop(::QStringList &url) noexcept {
  void (*qstringlist_drop$)(::QStringList &) = ::rust::cxxqtlib1::drop;
  qstringlist_drop$(url);
}

void rust$cxxqtlib1$cxxbridge1$194$qstringlist_default(::QStringList *return$) noexcept {
  ::QStringList (*qstringlist_default$)() = ::rust::cxxqtlib1::construct;
  new (return$) ::QStringList(qstringlist_default$());
}

void rust$cxxqtlib1$cxxbridge1$194$qstringlist_from_qstring(::QString const &string, ::QStringList *return$) noexcept {
  ::QStringList (*qstringlist_from_qstring$)(::QString const &) = ::rust::cxxqtlib1::construct;
  new (return$) ::QStringList(qstringlist_from_qstring$(string));
}

bool rust$cxxqtlib1$cxxbridge1$194$qstringlist_eq(::QStringList const &a, ::QStringList const &b) noexcept {
  bool (*qstringlist_eq$)(::QStringList const &, ::QStringList const &) = ::rust::cxxqtlib1::operatorEq;
  return qstringlist_eq$(a, b);
}

void rust$cxxqtlib1$cxxbridge1$194$qstringlist_to_debug_qstring(::QStringList const &value, ::QString *return$) noexcept {
  ::QString (*qstringlist_to_debug_qstring$)(::QStringList const &) = ::rust::cxxqtlib1::toDebugQString;
  new (return$) ::QString(qstringlist_to_debug_qstring$(value));
}

void rust$cxxqtlib1$cxxbridge1$194$qstringlist_from_qlist_qstring(::QList_QString const &list, ::QStringList *return$) noexcept {
  ::QStringList (*qstringlist_from_qlist_qstring$)(::QList_QString const &) = ::rust::cxxqtlib1::qstringlistFromQListQString;
  new (return$) ::QStringList(qstringlist_from_qlist_qstring$(list));
}

void rust$cxxqtlib1$cxxbridge1$194$qstringlist_as_qlist_qstring(::QStringList const &list, ::QList_QString *return$) noexcept {
  ::QList_QString (*qstringlist_as_qlist_qstring$)(::QStringList const &) = ::rust::cxxqtlib1::qstringlistAsQListQString;
  new (return$) ::QList_QString(qstringlist_as_qlist_qstring$(list));
}

::rust::isize rust$cxxqtlib1$cxxbridge1$194$qstringlist_remove_duplicates(::QStringList &list) noexcept {
  ::rust::isize (*qstringlist_remove_duplicates$)(::QStringList &) = ::rust::cxxqtlib1::qstringlistRemoveDuplicates;
  return qstringlist_remove_duplicates$(list);
}
} // extern "C"
} // namespace cxxqtlib1
} // namespace rust
