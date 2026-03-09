#include "cxx-qt-lib/qt.h"
#include "cxx-qt-lib/qbytearray.h"
#include "cxx-qt-lib/qstring.h"
#include "cxx-qt-lib/qstringlist.h"
#include "cxx-qt-lib/common.h"
#include <array>
#include <cassert>
#include <cstddef>
#include <cstdint>
#include <iterator>
#include <new>
#include <stdexcept>
#include <string>
#include <type_traits>
#include <utility>
#if defined(_WIN32)
#include <basetsd.h>
#else
#include <sys/types.h>
#endif
#if __cplusplus >= 201703L
#include <string_view>
#endif
#if __cplusplus >= 202002L
#include <ranges>
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

#ifndef CXXBRIDGE1_PANIC
#define CXXBRIDGE1_PANIC
template <typename Exception>
void panic [[noreturn]] (const char *msg);
#endif // CXXBRIDGE1_PANIC

namespace {
template <typename T>
class impl;
} // namespace

class String;
class Opaque;

template <typename T>
::std::size_t size_of();
template <typename T>
::std::size_t align_of();

#ifndef CXXBRIDGE1_RUST_STR
#define CXXBRIDGE1_RUST_STR
class Str final {
public:
  Str() noexcept;
  Str(const String &) noexcept;
  Str(const std::string &);
  Str(const char *);
  Str(const char *, std::size_t);

  Str &operator=(const Str &) & noexcept = default;

  explicit operator std::string() const;
#if __cplusplus >= 201703L
  explicit operator std::string_view() const;
#endif

  const char *data() const noexcept;
  std::size_t size() const noexcept;
  std::size_t length() const noexcept;
  bool empty() const noexcept;

  Str(const Str &) noexcept = default;
  ~Str() noexcept = default;

  using iterator = const char *;
  using const_iterator = const char *;
  const_iterator begin() const noexcept;
  const_iterator end() const noexcept;
  const_iterator cbegin() const noexcept;
  const_iterator cend() const noexcept;

  bool operator==(const Str &) const noexcept;
  bool operator!=(const Str &) const noexcept;
  bool operator<(const Str &) const noexcept;
  bool operator<=(const Str &) const noexcept;
  bool operator>(const Str &) const noexcept;
  bool operator>=(const Str &) const noexcept;

  void swap(Str &) noexcept;

private:
  class uninit;
  Str(uninit) noexcept;
  friend impl<Str>;

  std::array<std::uintptr_t, 2> repr;
};
#endif // CXXBRIDGE1_RUST_STR

#ifndef CXXBRIDGE1_RUST_SLICE
#define CXXBRIDGE1_RUST_SLICE
namespace detail {
template <bool>
struct copy_assignable_if {};

template <>
struct copy_assignable_if<false> {
  copy_assignable_if() noexcept = default;
  copy_assignable_if(const copy_assignable_if &) noexcept = default;
  copy_assignable_if &operator=(const copy_assignable_if &) & noexcept = delete;
  copy_assignable_if &operator=(copy_assignable_if &&) & noexcept = default;
};
} // namespace detail

template <typename T>
class Slice final
    : private detail::copy_assignable_if<std::is_const<T>::value> {
public:
  using value_type = T;

  Slice() noexcept;
  Slice(T *, std::size_t count) noexcept;

  template <typename C>
  explicit Slice(C &c) : Slice(c.data(), c.size()) {}

  Slice &operator=(const Slice<T> &) & noexcept = default;
  Slice &operator=(Slice<T> &&) & noexcept = default;

  T *data() const noexcept;
  std::size_t size() const noexcept;
  std::size_t length() const noexcept;
  bool empty() const noexcept;

  T &operator[](std::size_t n) const noexcept;
  T &at(std::size_t n) const;
  T &front() const noexcept;
  T &back() const noexcept;

  Slice(const Slice<T> &) noexcept = default;
  ~Slice() noexcept = default;

  class iterator;
  iterator begin() const noexcept;
  iterator end() const noexcept;

  void swap(Slice &) noexcept;

private:
  class uninit;
  Slice(uninit) noexcept;
  friend impl<Slice>;
  friend void sliceInit(void *, const void *, std::size_t) noexcept;
  friend void *slicePtr(const void *) noexcept;
  friend std::size_t sliceLen(const void *) noexcept;

  std::array<std::uintptr_t, 2> repr;
};

#ifdef __cpp_deduction_guides
template <typename C>
explicit Slice(C &c)
    -> Slice<std::remove_reference_t<decltype(*std::declval<C>().data())>>;
#endif // __cpp_deduction_guides

template <typename T>
class Slice<T>::iterator final {
public:
#if __cplusplus >= 202002L
  using iterator_category = std::contiguous_iterator_tag;
#else
  using iterator_category = std::random_access_iterator_tag;
#endif
  using value_type = T;
  using difference_type = std::ptrdiff_t;
  using pointer = typename std::add_pointer<T>::type;
  using reference = typename std::add_lvalue_reference<T>::type;

  reference operator*() const noexcept;
  pointer operator->() const noexcept;
  reference operator[](difference_type) const noexcept;

  iterator &operator++() noexcept;
  iterator operator++(int) noexcept;
  iterator &operator--() noexcept;
  iterator operator--(int) noexcept;

  iterator &operator+=(difference_type) noexcept;
  iterator &operator-=(difference_type) noexcept;
  iterator operator+(difference_type) const noexcept;
  friend inline iterator operator+(difference_type lhs, iterator rhs) noexcept {
    return rhs + lhs;
  }
  iterator operator-(difference_type) const noexcept;
  difference_type operator-(const iterator &) const noexcept;

  bool operator==(const iterator &) const noexcept;
  bool operator!=(const iterator &) const noexcept;
  bool operator<(const iterator &) const noexcept;
  bool operator<=(const iterator &) const noexcept;
  bool operator>(const iterator &) const noexcept;
  bool operator>=(const iterator &) const noexcept;

private:
  friend class Slice;
  void *pos;
  std::size_t stride;
};

#if __cplusplus >= 202002L
static_assert(std::ranges::contiguous_range<rust::Slice<const uint8_t>>);
static_assert(std::contiguous_iterator<rust::Slice<const uint8_t>::iterator>);
#endif

template <typename T>
Slice<T>::Slice() noexcept {
  sliceInit(this, reinterpret_cast<void *>(align_of<T>()), 0);
}

template <typename T>
Slice<T>::Slice(T *s, std::size_t count) noexcept {
  assert(s != nullptr || count == 0);
  sliceInit(this,
            s == nullptr && count == 0
                ? reinterpret_cast<void *>(align_of<T>())
                : const_cast<typename std::remove_const<T>::type *>(s),
            count);
}

template <typename T>
T *Slice<T>::data() const noexcept {
  return reinterpret_cast<T *>(slicePtr(this));
}

template <typename T>
std::size_t Slice<T>::size() const noexcept {
  return sliceLen(this);
}

template <typename T>
std::size_t Slice<T>::length() const noexcept {
  return this->size();
}

template <typename T>
bool Slice<T>::empty() const noexcept {
  return this->size() == 0;
}

template <typename T>
T &Slice<T>::operator[](std::size_t n) const noexcept {
  assert(n < this->size());
  auto ptr = static_cast<char *>(slicePtr(this)) + size_of<T>() * n;
  return *reinterpret_cast<T *>(ptr);
}

template <typename T>
T &Slice<T>::at(std::size_t n) const {
  if (n >= this->size()) {
    panic<std::out_of_range>("rust::Slice index out of range");
  }
  return (*this)[n];
}

template <typename T>
T &Slice<T>::front() const noexcept {
  assert(!this->empty());
  return (*this)[0];
}

template <typename T>
T &Slice<T>::back() const noexcept {
  assert(!this->empty());
  return (*this)[this->size() - 1];
}

template <typename T>
typename Slice<T>::iterator::reference
Slice<T>::iterator::operator*() const noexcept {
  return *static_cast<T *>(this->pos);
}

template <typename T>
typename Slice<T>::iterator::pointer
Slice<T>::iterator::operator->() const noexcept {
  return static_cast<T *>(this->pos);
}

template <typename T>
typename Slice<T>::iterator::reference Slice<T>::iterator::operator[](
    typename Slice<T>::iterator::difference_type n) const noexcept {
  auto ptr = static_cast<char *>(this->pos) + this->stride * n;
  return *reinterpret_cast<T *>(ptr);
}

template <typename T>
typename Slice<T>::iterator &Slice<T>::iterator::operator++() noexcept {
  this->pos = static_cast<char *>(this->pos) + this->stride;
  return *this;
}

template <typename T>
typename Slice<T>::iterator Slice<T>::iterator::operator++(int) noexcept {
  auto ret = iterator(*this);
  this->pos = static_cast<char *>(this->pos) + this->stride;
  return ret;
}

template <typename T>
typename Slice<T>::iterator &Slice<T>::iterator::operator--() noexcept {
  this->pos = static_cast<char *>(this->pos) - this->stride;
  return *this;
}

template <typename T>
typename Slice<T>::iterator Slice<T>::iterator::operator--(int) noexcept {
  auto ret = iterator(*this);
  this->pos = static_cast<char *>(this->pos) - this->stride;
  return ret;
}

template <typename T>
typename Slice<T>::iterator &Slice<T>::iterator::operator+=(
    typename Slice<T>::iterator::difference_type n) noexcept {
  this->pos = static_cast<char *>(this->pos) + this->stride * n;
  return *this;
}

template <typename T>
typename Slice<T>::iterator &Slice<T>::iterator::operator-=(
    typename Slice<T>::iterator::difference_type n) noexcept {
  this->pos = static_cast<char *>(this->pos) - this->stride * n;
  return *this;
}

template <typename T>
typename Slice<T>::iterator Slice<T>::iterator::operator+(
    typename Slice<T>::iterator::difference_type n) const noexcept {
  auto ret = iterator(*this);
  ret.pos = static_cast<char *>(this->pos) + this->stride * n;
  return ret;
}

template <typename T>
typename Slice<T>::iterator Slice<T>::iterator::operator-(
    typename Slice<T>::iterator::difference_type n) const noexcept {
  auto ret = iterator(*this);
  ret.pos = static_cast<char *>(this->pos) - this->stride * n;
  return ret;
}

template <typename T>
typename Slice<T>::iterator::difference_type
Slice<T>::iterator::operator-(const iterator &other) const noexcept {
  auto diff = std::distance(static_cast<char *>(other.pos),
                            static_cast<char *>(this->pos));
  return diff / static_cast<typename Slice<T>::iterator::difference_type>(
                    this->stride);
}

template <typename T>
bool Slice<T>::iterator::operator==(const iterator &other) const noexcept {
  return this->pos == other.pos;
}

template <typename T>
bool Slice<T>::iterator::operator!=(const iterator &other) const noexcept {
  return this->pos != other.pos;
}

template <typename T>
bool Slice<T>::iterator::operator<(const iterator &other) const noexcept {
  return this->pos < other.pos;
}

template <typename T>
bool Slice<T>::iterator::operator<=(const iterator &other) const noexcept {
  return this->pos <= other.pos;
}

template <typename T>
bool Slice<T>::iterator::operator>(const iterator &other) const noexcept {
  return this->pos > other.pos;
}

template <typename T>
bool Slice<T>::iterator::operator>=(const iterator &other) const noexcept {
  return this->pos >= other.pos;
}

template <typename T>
typename Slice<T>::iterator Slice<T>::begin() const noexcept {
  iterator it;
  it.pos = slicePtr(this);
  it.stride = size_of<T>();
  return it;
}

template <typename T>
typename Slice<T>::iterator Slice<T>::end() const noexcept {
  iterator it = this->begin();
  it.pos = static_cast<char *>(it.pos) + it.stride * this->size();
  return it;
}

template <typename T>
void Slice<T>::swap(Slice &rhs) noexcept {
  std::swap(*this, rhs);
}
#endif // CXXBRIDGE1_RUST_SLICE

#ifndef CXXBRIDGE1_RUST_ISIZE
#define CXXBRIDGE1_RUST_ISIZE
#if defined(_WIN32)
using isize = SSIZE_T;
#else
using isize = ssize_t;
#endif
#endif // CXXBRIDGE1_RUST_ISIZE

#ifndef CXXBRIDGE1_IS_COMPLETE
#define CXXBRIDGE1_IS_COMPLETE
namespace detail {
namespace {
template <typename T, typename = std::size_t>
struct is_complete : std::false_type {};
template <typename T>
struct is_complete<T, decltype(sizeof(T))> : std::true_type {};
} // namespace
} // namespace detail
#endif // CXXBRIDGE1_IS_COMPLETE

#ifndef CXXBRIDGE1_LAYOUT
#define CXXBRIDGE1_LAYOUT
class layout {
  template <typename T>
  friend std::size_t size_of();
  template <typename T>
  friend std::size_t align_of();
  template <typename T>
  static typename std::enable_if<std::is_base_of<Opaque, T>::value,
                                 std::size_t>::type
  do_size_of() {
    return T::layout::size();
  }
  template <typename T>
  static typename std::enable_if<!std::is_base_of<Opaque, T>::value,
                                 std::size_t>::type
  do_size_of() {
    return sizeof(T);
  }
  template <typename T>
  static
      typename std::enable_if<detail::is_complete<T>::value, std::size_t>::type
      size_of() {
    return do_size_of<T>();
  }
  template <typename T>
  static typename std::enable_if<std::is_base_of<Opaque, T>::value,
                                 std::size_t>::type
  do_align_of() {
    return T::layout::align();
  }
  template <typename T>
  static typename std::enable_if<!std::is_base_of<Opaque, T>::value,
                                 std::size_t>::type
  do_align_of() {
    return alignof(T);
  }
  template <typename T>
  static
      typename std::enable_if<detail::is_complete<T>::value, std::size_t>::type
      align_of() {
    return do_align_of<T>();
  }
};

template <typename T>
std::size_t size_of() {
  return layout::size_of<T>();
}

template <typename T>
std::size_t align_of() {
  return layout::align_of<T>();
}
#endif // CXXBRIDGE1_LAYOUT

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
    "type Qt::CaseSensitivity should be trivially move constructible and trivially destructible in C++ to be used as an argument of `compare_i32`, `contains`, `ends_with` in Rust");
static_assert(
    ::rust::IsRelocatable<::Qt::SplitBehaviorFlags>::value,
    "type Qt::SplitBehaviorFlags should be trivially move constructible and trivially destructible in C++ to be used as an argument of `qstring_split` in Rust");
static_assert(
    ::rust::IsRelocatable<::QByteArray>::value,
    "type QByteArray should be trivially move constructible and trivially destructible in C++ to be used as a return value of `qstring_to_latin1`, `qstring_to_local8bit`, `qstring_to_utf8` in Rust");
static_assert(
    ::rust::IsRelocatable<::QString>::value,
    "type QString should be trivially move constructible and trivially destructible in C++ to be used as a return value of `to_html_escaped`, `qstring_init_default`, `qstring_init_from_rust_string` in Rust");
static_assert(
    ::rust::IsRelocatable<::QStringList>::value,
    "type QStringList should be trivially move constructible and trivially destructible in C++ to be used as a return value of `qstring_split` in Rust");

extern "C" {
::QString *cxxbridge1$194$QString$append(::QString &self, ::QString const &str) noexcept {
  ::QString &(::QString::*append$)(::QString const &) = &::QString::append;
  return &(self.*append$)(str);
}

void cxxbridge1$194$QString$clear(::QString &self) noexcept {
  void (::QString::*clear$)() = &::QString::clear;
  (self.*clear$)();
}

::std::int32_t cxxbridge1$194$QString$compare_i32(::QString const &self, ::QString const &other, ::Qt::CaseSensitivity *cs) noexcept {
  ::std::int32_t (::QString::*compare_i32$)(::QString const &, ::Qt::CaseSensitivity) const = &::QString::compare;
  return (self.*compare_i32$)(other, ::std::move(*cs));
}

bool cxxbridge1$194$QString$contains(::QString const &self, ::QString const &str, ::Qt::CaseSensitivity *cs) noexcept {
  bool (::QString::*contains$)(::QString const &, ::Qt::CaseSensitivity) const = &::QString::contains;
  return (self.*contains$)(str, ::std::move(*cs));
}

bool cxxbridge1$194$QString$ends_with(::QString const &self, ::QString const &s, ::Qt::CaseSensitivity *cs) noexcept {
  bool (::QString::*ends_with$)(::QString const &, ::Qt::CaseSensitivity) const = &::QString::endsWith;
  return (self.*ends_with$)(s, ::std::move(*cs));
}

bool cxxbridge1$194$QString$is_empty(::QString const &self) noexcept {
  bool (::QString::*is_empty$)() const = &::QString::isEmpty;
  return (self.*is_empty$)();
}

bool cxxbridge1$194$QString$is_lower(::QString const &self) noexcept {
  bool (::QString::*is_lower$)() const = &::QString::isLower;
  return (self.*is_lower$)();
}

bool cxxbridge1$194$QString$is_null(::QString const &self) noexcept {
  bool (::QString::*is_null$)() const = &::QString::isNull;
  return (self.*is_null$)();
}

bool cxxbridge1$194$QString$is_right_to_left(::QString const &self) noexcept {
  bool (::QString::*is_right_to_left$)() const = &::QString::isRightToLeft;
  return (self.*is_right_to_left$)();
}

bool cxxbridge1$194$QString$is_upper(::QString const &self) noexcept {
  bool (::QString::*is_upper$)() const = &::QString::isUpper;
  return (self.*is_upper$)();
}

bool cxxbridge1$194$QString$is_valid_utf16(::QString const &self) noexcept {
  bool (::QString::*is_valid_utf16$)() const = &::QString::isValidUtf16;
  return (self.*is_valid_utf16$)();
}

::QString *cxxbridge1$194$QString$prepend(::QString &self, ::QString const &str) noexcept {
  ::QString &(::QString::*prepend$)(::QString const &) = &::QString::prepend;
  return &(self.*prepend$)(str);
}

::QString *cxxbridge1$194$QString$remove(::QString &self, ::QString const &str, ::Qt::CaseSensitivity *cs) noexcept {
  ::QString &(::QString::*remove$)(::QString const &, ::Qt::CaseSensitivity) = &::QString::remove;
  return &(self.*remove$)(str, ::std::move(*cs));
}

void cxxbridge1$194$QString$remove_first(::QString &self, ::QString **return$) noexcept {
  ::QString &(::QString::*remove_first$)() = &::QString::removeFirst;
  new (return$) ::QString *(&(self.*remove_first$)());
}

void cxxbridge1$194$QString$remove_last(::QString &self, ::QString **return$) noexcept {
  ::QString &(::QString::*remove_last$)() = &::QString::removeLast;
  new (return$) ::QString *(&(self.*remove_last$)());
}

::QString *cxxbridge1$194$QString$replace(::QString &self, ::QString const &before, ::QString const &after, ::Qt::CaseSensitivity *cs) noexcept {
  ::QString &(::QString::*replace$)(::QString const &, ::QString const &, ::Qt::CaseSensitivity) = &::QString::replace;
  return &(self.*replace$)(before, after, ::std::move(*cs));
}

bool cxxbridge1$194$QString$starts_with(::QString const &self, ::QString const &s, ::Qt::CaseSensitivity *cs) noexcept {
  bool (::QString::*starts_with$)(::QString const &, ::Qt::CaseSensitivity) const = &::QString::startsWith;
  return (self.*starts_with$)(s, ::std::move(*cs));
}

void cxxbridge1$194$QString$to_html_escaped(::QString const &self, ::QString *return$) noexcept {
  ::QString (::QString::*to_html_escaped$)() const = &::QString::toHtmlEscaped;
  new (return$) ::QString((self.*to_html_escaped$)());
}
} // extern "C"

namespace rust {
namespace cxxqtlib1 {
extern "C" {
void rust$cxxqtlib1$cxxbridge1$194$qstring_drop(::QString &string) noexcept {
  void (*qstring_drop$)(::QString &) = ::rust::cxxqtlib1::drop;
  qstring_drop$(string);
}

void rust$cxxqtlib1$cxxbridge1$194$qstring_init_default(::QString *return$) noexcept {
  ::QString (*qstring_init_default$)() = ::rust::cxxqtlib1::construct;
  new (return$) ::QString(qstring_init_default$());
}

void rust$cxxqtlib1$cxxbridge1$194$qstring_init_from_rust_string(::rust::Str string, ::QString *return$) noexcept {
  ::QString (*qstring_init_from_rust_string$)(::rust::Str) = ::rust::cxxqtlib1::qstringInitFromRustString;
  new (return$) ::QString(qstring_init_from_rust_string$(string));
}

void rust$cxxqtlib1$cxxbridge1$194$qstring_init_from_qstring(::QString const &string, ::QString *return$) noexcept {
  ::QString (*qstring_init_from_qstring$)(::QString const &) = ::rust::cxxqtlib1::construct;
  new (return$) ::QString(qstring_init_from_qstring$(string));
}

bool rust$cxxqtlib1$cxxbridge1$194$qstring_eq(::QString const &a, ::QString const &b) noexcept {
  bool (*qstring_eq$)(::QString const &, ::QString const &) = ::rust::cxxqtlib1::operatorEq;
  return qstring_eq$(a, b);
}

::std::int8_t rust$cxxqtlib1$cxxbridge1$194$qstring_cmp(::QString const &a, ::QString const &b) noexcept {
  ::std::int8_t (*qstring_cmp$)(::QString const &, ::QString const &) = ::rust::cxxqtlib1::operatorCmp;
  return qstring_cmp$(a, b);
}

void rust$cxxqtlib1$cxxbridge1$194$qstring_as_slice(::QString const &string, ::rust::Slice<::std::uint16_t const> *return$) noexcept {
  ::rust::Slice<::std::uint16_t const> (*qstring_as_slice$)(::QString const &) = ::rust::cxxqtlib1::qstringAsSlice;
  new (return$) ::rust::Slice<::std::uint16_t const>(qstring_as_slice$(string));
}

void rust$cxxqtlib1$cxxbridge1$194$qstring_arg(::QString const &string, ::QString const &a, ::QString *return$) noexcept {
  ::QString (*qstring_arg$)(::QString const &, ::QString const &) = ::rust::cxxqtlib1::qstringArg;
  new (return$) ::QString(qstring_arg$(string, a));
}

::rust::isize rust$cxxqtlib1$cxxbridge1$194$qstring_index_of(::QString const &string, ::QString const &str, ::rust::isize from, ::Qt::CaseSensitivity *cs) noexcept {
  ::rust::isize (*qstring_index_of$)(::QString const &, ::QString const &, ::rust::isize, ::Qt::CaseSensitivity) = ::rust::cxxqtlib1::qstringIndexOf;
  return qstring_index_of$(string, str, from, ::std::move(*cs));
}

::QString *rust$cxxqtlib1$cxxbridge1$194$qstring_insert(::QString &string, ::rust::isize pos, ::QString const &str) noexcept {
  ::QString &(*qstring_insert$)(::QString &, ::rust::isize, ::QString const &) = ::rust::cxxqtlib1::qstringInsert;
  return &qstring_insert$(string, pos, str);
}

void rust$cxxqtlib1$cxxbridge1$194$qstring_left(::QString const &string, ::rust::isize n, ::QString *return$) noexcept {
  ::QString (*qstring_left$)(::QString const &, ::rust::isize) = ::rust::cxxqtlib1::qstringLeft;
  new (return$) ::QString(qstring_left$(string, n));
}

::rust::isize rust$cxxqtlib1$cxxbridge1$194$qstring_len(::QString const &string) noexcept {
  ::rust::isize (*qstring_len$)(::QString const &) = ::rust::cxxqtlib1::qstringLen;
  return qstring_len$(string);
}

void rust$cxxqtlib1$cxxbridge1$194$qstring_mid(::QString const &string, ::rust::isize position, ::rust::isize n, ::QString *return$) noexcept {
  ::QString (*qstring_mid$)(::QString const &, ::rust::isize, ::rust::isize) = ::rust::cxxqtlib1::qstringMid;
  new (return$) ::QString(qstring_mid$(string, position, n));
}

void rust$cxxqtlib1$cxxbridge1$194$qstring_right(::QString const &string, ::rust::isize n, ::QString *return$) noexcept {
  ::QString (*qstring_right$)(::QString const &, ::rust::isize) = ::rust::cxxqtlib1::qstringRight;
  new (return$) ::QString(qstring_right$(string, n));
}

void rust$cxxqtlib1$cxxbridge1$194$qstring_simplified(::QString const &string, ::QString *return$) noexcept {
  ::QString (*qstring_simplified$)(::QString const &) = ::rust::cxxqtlib1::qstringSimplified;
  new (return$) ::QString(qstring_simplified$(string));
}

void rust$cxxqtlib1$cxxbridge1$194$qstring_split(::QString const &string, ::QString const &sep, ::Qt::SplitBehaviorFlags *behavior, ::Qt::CaseSensitivity *cs, ::QStringList *return$) noexcept {
  ::QStringList (*qstring_split$)(::QString const &, ::QString const &, ::Qt::SplitBehaviorFlags, ::Qt::CaseSensitivity) = ::rust::cxxqtlib1::qstringSplit;
  new (return$) ::QStringList(qstring_split$(string, sep, ::std::move(*behavior), ::std::move(*cs)));
}

void rust$cxxqtlib1$cxxbridge1$194$qstring_to_latin1(::QString const &string, ::QByteArray *return$) noexcept {
  ::QByteArray (*qstring_to_latin1$)(::QString const &) = ::rust::cxxqtlib1::qstringToLatin1;
  new (return$) ::QByteArray(qstring_to_latin1$(string));
}

void rust$cxxqtlib1$cxxbridge1$194$qstring_to_local8bit(::QString const &string, ::QByteArray *return$) noexcept {
  ::QByteArray (*qstring_to_local8bit$)(::QString const &) = ::rust::cxxqtlib1::qstringToLocal8Bit;
  new (return$) ::QByteArray(qstring_to_local8bit$(string));
}

void rust$cxxqtlib1$cxxbridge1$194$qstring_to_lower(::QString const &string, ::QString *return$) noexcept {
  ::QString (*qstring_to_lower$)(::QString const &) = ::rust::cxxqtlib1::qstringToLower;
  new (return$) ::QString(qstring_to_lower$(string));
}

void rust$cxxqtlib1$cxxbridge1$194$qstring_to_upper(::QString const &string, ::QString *return$) noexcept {
  ::QString (*qstring_to_upper$)(::QString const &) = ::rust::cxxqtlib1::qstringToUpper;
  new (return$) ::QString(qstring_to_upper$(string));
}

void rust$cxxqtlib1$cxxbridge1$194$qstring_to_utf8(::QString const &string, ::QByteArray *return$) noexcept {
  ::QByteArray (*qstring_to_utf8$)(::QString const &) = ::rust::cxxqtlib1::qstringToUtf8;
  new (return$) ::QByteArray(qstring_to_utf8$(string));
}

void rust$cxxqtlib1$cxxbridge1$194$qstring_trimmed(::QString const &string, ::QString *return$) noexcept {
  ::QString (*qstring_trimmed$)(::QString const &) = ::rust::cxxqtlib1::qstringTrimmed;
  new (return$) ::QString(qstring_trimmed$(string));
}
} // extern "C"
} // namespace cxxqtlib1
} // namespace rust
