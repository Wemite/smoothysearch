#include "cxx-qt-lib/qbytearray.h"
#include "cxx-qt-lib/common.h"
#include <algorithm>
#include <array>
#include <cassert>
#include <cstddef>
#include <cstdint>
#include <initializer_list>
#include <iterator>
#include <new>
#include <stdexcept>
#include <type_traits>
#include <utility>
#if defined(_WIN32)
#include <basetsd.h>
#else
#include <sys/types.h>
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

class Opaque;

template <typename T>
::std::size_t size_of();
template <typename T>
::std::size_t align_of();

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

#ifndef CXXBRIDGE1_RUST_BITCOPY_T
#define CXXBRIDGE1_RUST_BITCOPY_T
struct unsafe_bitcopy_t final {
  explicit unsafe_bitcopy_t() = default;
};
#endif // CXXBRIDGE1_RUST_BITCOPY_T

#ifndef CXXBRIDGE1_RUST_VEC
#define CXXBRIDGE1_RUST_VEC
template <typename T>
class Vec final {
public:
  using value_type = T;

  Vec() noexcept;
  Vec(std::initializer_list<T>);
  Vec(const Vec &);
  Vec(Vec &&) noexcept;
  ~Vec() noexcept;

  Vec &operator=(Vec &&) & noexcept;
  Vec &operator=(const Vec &) &;

  std::size_t size() const noexcept;
  bool empty() const noexcept;
  const T *data() const noexcept;
  T *data() noexcept;
  std::size_t capacity() const noexcept;

  const T &operator[](std::size_t n) const noexcept;
  const T &at(std::size_t n) const;
  const T &front() const noexcept;
  const T &back() const noexcept;

  T &operator[](std::size_t n) noexcept;
  T &at(std::size_t n);
  T &front() noexcept;
  T &back() noexcept;

  void reserve(std::size_t new_cap);
  void push_back(const T &value);
  void push_back(T &&value);
  template <typename... Args>
  void emplace_back(Args &&...args);
  void truncate(std::size_t len);
  void clear();

  using iterator = typename Slice<T>::iterator;
  iterator begin() noexcept;
  iterator end() noexcept;

  using const_iterator = typename Slice<const T>::iterator;
  const_iterator begin() const noexcept;
  const_iterator end() const noexcept;
  const_iterator cbegin() const noexcept;
  const_iterator cend() const noexcept;

  void swap(Vec &) noexcept;

  Vec(unsafe_bitcopy_t, const Vec &) noexcept;

private:
  void reserve_total(std::size_t new_cap) noexcept;
  void set_len(std::size_t len) noexcept;
  void drop() noexcept;

  friend void swap(Vec &lhs, Vec &rhs) noexcept { lhs.swap(rhs); }

  std::array<std::uintptr_t, 3> repr;
};

template <typename T>
Vec<T>::Vec(std::initializer_list<T> init) : Vec{} {
  this->reserve_total(init.size());
  std::move(init.begin(), init.end(), std::back_inserter(*this));
}

template <typename T>
Vec<T>::Vec(const Vec &other) : Vec() {
  this->reserve_total(other.size());
  std::copy(other.begin(), other.end(), std::back_inserter(*this));
}

template <typename T>
Vec<T>::Vec(Vec &&other) noexcept : repr(other.repr) {
  new (&other) Vec();
}

template <typename T>
Vec<T>::~Vec() noexcept {
  this->drop();
}

template <typename T>
Vec<T> &Vec<T>::operator=(Vec &&other) & noexcept {
  this->drop();
  this->repr = other.repr;
  new (&other) Vec();
  return *this;
}

template <typename T>
Vec<T> &Vec<T>::operator=(const Vec &other) & {
  if (this != &other) {
    this->drop();
    new (this) Vec(other);
  }
  return *this;
}

template <typename T>
bool Vec<T>::empty() const noexcept {
  return this->size() == 0;
}

template <typename T>
T *Vec<T>::data() noexcept {
  return const_cast<T *>(const_cast<const Vec<T> *>(this)->data());
}

template <typename T>
const T &Vec<T>::operator[](std::size_t n) const noexcept {
  assert(n < this->size());
  auto data = reinterpret_cast<const char *>(this->data());
  return *reinterpret_cast<const T *>(data + n * size_of<T>());
}

template <typename T>
const T &Vec<T>::at(std::size_t n) const {
  if (n >= this->size()) {
    panic<std::out_of_range>("rust::Vec index out of range");
  }
  return (*this)[n];
}

template <typename T>
const T &Vec<T>::front() const noexcept {
  assert(!this->empty());
  return (*this)[0];
}

template <typename T>
const T &Vec<T>::back() const noexcept {
  assert(!this->empty());
  return (*this)[this->size() - 1];
}

template <typename T>
T &Vec<T>::operator[](std::size_t n) noexcept {
  assert(n < this->size());
  auto data = reinterpret_cast<char *>(this->data());
  return *reinterpret_cast<T *>(data + n * size_of<T>());
}

template <typename T>
T &Vec<T>::at(std::size_t n) {
  if (n >= this->size()) {
    panic<std::out_of_range>("rust::Vec index out of range");
  }
  return (*this)[n];
}

template <typename T>
T &Vec<T>::front() noexcept {
  assert(!this->empty());
  return (*this)[0];
}

template <typename T>
T &Vec<T>::back() noexcept {
  assert(!this->empty());
  return (*this)[this->size() - 1];
}

template <typename T>
void Vec<T>::reserve(std::size_t new_cap) {
  this->reserve_total(new_cap);
}

template <typename T>
void Vec<T>::push_back(const T &value) {
  this->emplace_back(value);
}

template <typename T>
void Vec<T>::push_back(T &&value) {
  this->emplace_back(std::move(value));
}

template <typename T>
template <typename... Args>
void Vec<T>::emplace_back(Args &&...args) {
  auto size = this->size();
  this->reserve_total(size + 1);
  ::new (reinterpret_cast<T *>(reinterpret_cast<char *>(this->data()) +
                               size * size_of<T>()))
      T(std::forward<Args>(args)...);
  this->set_len(size + 1);
}

template <typename T>
void Vec<T>::clear() {
  this->truncate(0);
}

template <typename T>
typename Vec<T>::iterator Vec<T>::begin() noexcept {
  return Slice<T>(this->data(), this->size()).begin();
}

template <typename T>
typename Vec<T>::iterator Vec<T>::end() noexcept {
  return Slice<T>(this->data(), this->size()).end();
}

template <typename T>
typename Vec<T>::const_iterator Vec<T>::begin() const noexcept {
  return this->cbegin();
}

template <typename T>
typename Vec<T>::const_iterator Vec<T>::end() const noexcept {
  return this->cend();
}

template <typename T>
typename Vec<T>::const_iterator Vec<T>::cbegin() const noexcept {
  return Slice<const T>(this->data(), this->size()).begin();
}

template <typename T>
typename Vec<T>::const_iterator Vec<T>::cend() const noexcept {
  return Slice<const T>(this->data(), this->size()).end();
}

template <typename T>
void Vec<T>::swap(Vec &rhs) noexcept {
  using std::swap;
  swap(this->repr, rhs.repr);
}

template <typename T>
Vec<T>::Vec(unsafe_bitcopy_t, const Vec &bits) noexcept : repr(bits.repr) {}
#endif // CXXBRIDGE1_RUST_VEC

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

namespace rust {
  namespace cxxqtlib1 {
    using QByteArrayBase64DecodingStatus = ::rust::cxxqtlib1::QByteArrayBase64DecodingStatus;
    using QByteArrayBase64Option = ::rust::cxxqtlib1::QByteArrayBase64Option;
  }
}

namespace rust {
namespace cxxqtlib1 {
static_assert(::std::is_enum<QByteArrayBase64Option>::value, "expected enum");
static_assert(sizeof(QByteArrayBase64Option) == sizeof(::std::uint32_t), "incorrect size");
static_assert(static_cast<::std::uint32_t>(QByteArrayBase64Option::Base64UrlEncoding) == 1, "disagrees with the value in #[cxx::bridge]");
static_assert(static_cast<::std::uint32_t>(QByteArrayBase64Option::OmitTrailingEquals) == 2, "disagrees with the value in #[cxx::bridge]");

static_assert(::std::is_enum<QByteArrayBase64DecodingStatus>::value, "expected enum");
static_assert(sizeof(QByteArrayBase64DecodingStatus) == sizeof(::std::int32_t), "incorrect size");
static_assert(static_cast<::std::int32_t>(QByteArrayBase64DecodingStatus::Ok) == 0, "disagrees with the value in #[cxx::bridge]");
static_assert(static_cast<::std::int32_t>(QByteArrayBase64DecodingStatus::IllegalInputLength) == 1, "disagrees with the value in #[cxx::bridge]");
static_assert(static_cast<::std::int32_t>(QByteArrayBase64DecodingStatus::IllegalCharacter) == 2, "disagrees with the value in #[cxx::bridge]");
static_assert(static_cast<::std::int32_t>(QByteArrayBase64DecodingStatus::IllegalPadding) == 3, "disagrees with the value in #[cxx::bridge]");
} // namespace cxxqtlib1
} // namespace rust

static_assert(
    ::rust::IsRelocatable<::rust::cxxqtlib1::QByteArrayFromBase64Result>::value,
    "type rust::cxxqtlib1::QByteArrayFromBase64Result should be trivially move constructible and trivially destructible in C++ to be used as a return value of `qbytearrray_from_base64_encoding` in Rust");
static_assert(
    ::rust::IsRelocatable<::rust::cxxqtlib1::QByteArrayBase64Options>::value,
    "type rust::cxxqtlib1::QByteArrayBase64Options should be trivially move constructible and trivially destructible in C++ to be used as an argument of `to_base64`, `qbytearrray_from_base64_encoding` in Rust");
static_assert(
    ::rust::IsRelocatable<::QByteArray>::value,
    "type QByteArray should be trivially move constructible and trivially destructible in C++ to be used as a return value of `to_base64`, `qbytearray_default`, `qbytearray_clone` in Rust");

extern "C" {
void cxxbridge1$194$QByteArray$clear(::QByteArray &self) noexcept {
  void (::QByteArray::*clear$)() = &::QByteArray::clear;
  (self.*clear$)();
}

bool cxxbridge1$194$QByteArray$is_empty(::QByteArray const &self) noexcept {
  bool (::QByteArray::*is_empty$)() const = &::QByteArray::isEmpty;
  return (self.*is_empty$)();
}

bool cxxbridge1$194$QByteArray$is_lower(::QByteArray const &self) noexcept {
  bool (::QByteArray::*is_lower$)() const = &::QByteArray::isLower;
  return (self.*is_lower$)();
}

bool cxxbridge1$194$QByteArray$is_null(::QByteArray const &self) noexcept {
  bool (::QByteArray::*is_null$)() const = &::QByteArray::isNull;
  return (self.*is_null$)();
}

bool cxxbridge1$194$QByteArray$is_upper(::QByteArray const &self) noexcept {
  bool (::QByteArray::*is_upper$)() const = &::QByteArray::isUpper;
  return (self.*is_upper$)();
}

void cxxbridge1$194$QByteArray$squeeze(::QByteArray &self) noexcept {
  void (::QByteArray::*squeeze$)() = &::QByteArray::squeeze;
  (self.*squeeze$)();
}

void cxxbridge1$194$QByteArray$to_base64(::QByteArray const &self, ::rust::cxxqtlib1::QByteArrayBase64Options *options, ::QByteArray *return$) noexcept {
  ::QByteArray (::QByteArray::*to_base64$)(::rust::cxxqtlib1::QByteArrayBase64Options) const = &::QByteArray::toBase64;
  new (return$) ::QByteArray((self.*to_base64$)(::std::move(*options)));
}
} // extern "C"

namespace rust {
namespace cxxqtlib1 {
extern "C" {
void rust$cxxqtlib1$cxxbridge1$194$qbytearray_drop(::QByteArray &bytearray) noexcept {
  void (*qbytearray_drop$)(::QByteArray &) = ::rust::cxxqtlib1::drop;
  qbytearray_drop$(bytearray);
}

void rust$cxxqtlib1$cxxbridge1$194$qbytearray_default(::QByteArray *return$) noexcept {
  ::QByteArray (*qbytearray_default$)() = ::rust::cxxqtlib1::construct;
  new (return$) ::QByteArray(qbytearray_default$());
}

void rust$cxxqtlib1$cxxbridge1$194$qbytearray_clone(::QByteArray const &bytearray, ::QByteArray *return$) noexcept {
  ::QByteArray (*qbytearray_clone$)(::QByteArray const &) = ::rust::cxxqtlib1::construct;
  new (return$) ::QByteArray(qbytearray_clone$(bytearray));
}

bool rust$cxxqtlib1$cxxbridge1$194$qbytearray_eq(::QByteArray const &a, ::QByteArray const &b) noexcept {
  bool (*qbytearray_eq$)(::QByteArray const &, ::QByteArray const &) = ::rust::cxxqtlib1::operatorEq;
  return qbytearray_eq$(a, b);
}

void rust$cxxqtlib1$cxxbridge1$194$qbytearray_from_slice_u8(::rust::Slice<::std::uint8_t const> slice, ::QByteArray *return$) noexcept {
  ::QByteArray (*qbytearray_from_slice_u8$)(::rust::Slice<::std::uint8_t const>) = ::rust::cxxqtlib1::qbytearrayFromSliceU8;
  new (return$) ::QByteArray(qbytearray_from_slice_u8$(slice));
}

void rust$cxxqtlib1$cxxbridge1$194$qbytearray_to_vec_u8(::QByteArray const &string, ::rust::Vec<::std::uint8_t> *return$) noexcept {
  ::rust::Vec<::std::uint8_t> (*qbytearray_to_vec_u8$)(::QByteArray const &) = ::rust::cxxqtlib1::qbytearrayToVecU8;
  new (return$) ::rust::Vec<::std::uint8_t>(qbytearray_to_vec_u8$(string));
}

void rust$cxxqtlib1$cxxbridge1$194$qbytearray_from_raw_data(::rust::Slice<::std::uint8_t const> slice, ::QByteArray *return$) noexcept {
  ::QByteArray (*qbytearray_from_raw_data$)(::rust::Slice<::std::uint8_t const>) = ::rust::cxxqtlib1::qbytearrayFromRawData;
  new (return$) ::QByteArray(qbytearray_from_raw_data$(slice));
}

void rust$cxxqtlib1$cxxbridge1$194$qbytearray_as_mut_slice(::QByteArray &bytearray, ::rust::Slice<::std::uint8_t > *return$) noexcept {
  ::rust::Slice<::std::uint8_t > (*qbytearray_as_mut_slice$)(::QByteArray &) = ::rust::cxxqtlib1::qbytearrayAsMutSlice;
  new (return$) ::rust::Slice<::std::uint8_t >(qbytearray_as_mut_slice$(bytearray));
}

void rust$cxxqtlib1$cxxbridge1$194$qbytearray_as_slice(::QByteArray const &bytearray, ::rust::Slice<::std::uint8_t const> *return$) noexcept {
  ::rust::Slice<::std::uint8_t const> (*qbytearray_as_slice$)(::QByteArray const &) = ::rust::cxxqtlib1::qbytearrayAsSlice;
  new (return$) ::rust::Slice<::std::uint8_t const>(qbytearray_as_slice$(bytearray));
}

void rust$cxxqtlib1$cxxbridge1$194$qbytearray_append(::QByteArray &bytearray, ::std::uint8_t ch) noexcept {
  void (*qbytearray_append$)(::QByteArray &, ::std::uint8_t) = ::rust::cxxqtlib1::qbytearrayAppend;
  qbytearray_append$(bytearray, ch);
}

void rust$cxxqtlib1$cxxbridge1$194$qbytearray_fill(::QByteArray &bytearray, ::std::uint8_t ch, ::rust::isize size) noexcept {
  void (*qbytearray_fill$)(::QByteArray &, ::std::uint8_t, ::rust::isize) = ::rust::cxxqtlib1::qbytearrayFill;
  qbytearray_fill$(bytearray, ch, size);
}

void rust$cxxqtlib1$cxxbridge1$194$qbytearrray_from_base64_encoding(::QByteArray const &base64, ::rust::cxxqtlib1::QByteArrayBase64Options *options, ::rust::cxxqtlib1::QByteArrayFromBase64Result *return$) noexcept {
  ::rust::cxxqtlib1::QByteArrayFromBase64Result (*qbytearrray_from_base64_encoding$)(::QByteArray const &, ::rust::cxxqtlib1::QByteArrayBase64Options) = ::rust::cxxqtlib1::qbytearrayFromBase64Encoding;
  new (return$) ::rust::cxxqtlib1::QByteArrayFromBase64Result(qbytearrray_from_base64_encoding$(base64, ::std::move(*options)));
}

void rust$cxxqtlib1$cxxbridge1$194$qbytearray_insert(::QByteArray &bytearray, ::rust::isize pos, ::std::uint8_t ch) noexcept {
  void (*qbytearray_insert$)(::QByteArray &, ::rust::isize, ::std::uint8_t) = ::rust::cxxqtlib1::qbytearrayInsert;
  qbytearray_insert$(bytearray, pos, ch);
}

::rust::isize rust$cxxqtlib1$cxxbridge1$194$qbytearray_len(::QByteArray const &bytearray) noexcept {
  ::rust::isize (*qbytearray_len$)(::QByteArray const &) = ::rust::cxxqtlib1::qbytearrayLen;
  return qbytearray_len$(bytearray);
}

void rust$cxxqtlib1$cxxbridge1$194$qbytearray_prepend(::QByteArray &bytearray, ::std::uint8_t ch) noexcept {
  void (*qbytearray_prepend$)(::QByteArray &, ::std::uint8_t) = ::rust::cxxqtlib1::qbytearrayPrepend;
  qbytearray_prepend$(bytearray, ch);
}

void rust$cxxqtlib1$cxxbridge1$194$qbytearray_remove(::QByteArray &bytearray, ::rust::isize pos, ::rust::isize len) noexcept {
  void (*qbytearray_remove$)(::QByteArray &, ::rust::isize, ::rust::isize) = ::rust::cxxqtlib1::qbytearrayRemove;
  qbytearray_remove$(bytearray, pos, len);
}

void rust$cxxqtlib1$cxxbridge1$194$qbytearray_reserve(::QByteArray &bytearray, ::rust::isize size) noexcept {
  void (*qbytearray_reserve$)(::QByteArray &, ::rust::isize) = ::rust::cxxqtlib1::qbytearrayReserve;
  qbytearray_reserve$(bytearray, size);
}

void rust$cxxqtlib1$cxxbridge1$194$qbytearray_resize(::QByteArray &bytearray, ::rust::isize size) noexcept {
  void (*qbytearray_resize$)(::QByteArray &, ::rust::isize) = ::rust::cxxqtlib1::qbytearrayResize;
  qbytearray_resize$(bytearray, size);
}

void rust$cxxqtlib1$cxxbridge1$194$qbytearray_simplified(::QByteArray const &bytearray, ::QByteArray *return$) noexcept {
  ::QByteArray (*qbytearray_simplified$)(::QByteArray const &) = ::rust::cxxqtlib1::qbytearraySimplified;
  new (return$) ::QByteArray(qbytearray_simplified$(bytearray));
}

void rust$cxxqtlib1$cxxbridge1$194$qbytearray_to_lower(::QByteArray const &bytearray, ::QByteArray *return$) noexcept {
  ::QByteArray (*qbytearray_to_lower$)(::QByteArray const &) = ::rust::cxxqtlib1::qbytearrayToLower;
  new (return$) ::QByteArray(qbytearray_to_lower$(bytearray));
}

void rust$cxxqtlib1$cxxbridge1$194$qbytearray_to_upper(::QByteArray const &bytearray, ::QByteArray *return$) noexcept {
  ::QByteArray (*qbytearray_to_upper$)(::QByteArray const &) = ::rust::cxxqtlib1::qbytearrayToUpper;
  new (return$) ::QByteArray(qbytearray_to_upper$(bytearray));
}

void rust$cxxqtlib1$cxxbridge1$194$qbytearray_trimmed(::QByteArray const &bytearray, ::QByteArray *return$) noexcept {
  ::QByteArray (*qbytearray_trimmed$)(::QByteArray const &) = ::rust::cxxqtlib1::qbytearrayTrimmed;
  new (return$) ::QByteArray(qbytearray_trimmed$(bytearray));
}
} // extern "C"
} // namespace cxxqtlib1
} // namespace rust
