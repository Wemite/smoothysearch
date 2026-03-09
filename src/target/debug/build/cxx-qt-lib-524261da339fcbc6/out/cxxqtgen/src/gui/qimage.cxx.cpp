#include "cxx-qt-lib/qt.h"
#include "cxx-qt-lib/qimage.h"
#include "cxx-qt-lib/qsize.h"
#include "cxx-qt-lib/qstring.h"
#include "cxx-qt-lib/qrect.h"
#include "cxx-qt-lib/qcolor.h"
#include "cxx-qt-lib/qpoint.h"
#include "cxx-qt-lib/qsizef.h"
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

using uchar = ::uchar;
namespace rust {
  namespace cxxqtlib1 {
    using QImageFormat = ::rust::cxxqtlib1::QImageFormat;
    using QImageInvertMode = ::rust::cxxqtlib1::QImageInvertMode;
  }
}

namespace rust {
namespace cxxqtlib1 {
static_assert(::std::is_enum<QImageInvertMode>::value, "expected enum");
static_assert(sizeof(QImageInvertMode) == sizeof(::std::int32_t), "incorrect size");
static_assert(static_cast<::std::int32_t>(QImageInvertMode::InvertRgb) == 0, "disagrees with the value in #[cxx::bridge]");
static_assert(static_cast<::std::int32_t>(QImageInvertMode::InvertRgba) == 1, "disagrees with the value in #[cxx::bridge]");

static_assert(::std::is_enum<QImageFormat>::value, "expected enum");
static_assert(sizeof(QImageFormat) == sizeof(::std::int32_t), "incorrect size");
static_assert(static_cast<::std::int32_t>(QImageFormat::Format_Invalid) == 0, "disagrees with the value in #[cxx::bridge]");
static_assert(static_cast<::std::int32_t>(QImageFormat::Format_Mono) == 1, "disagrees with the value in #[cxx::bridge]");
static_assert(static_cast<::std::int32_t>(QImageFormat::Format_MonoLSB) == 2, "disagrees with the value in #[cxx::bridge]");
static_assert(static_cast<::std::int32_t>(QImageFormat::Format_Indexed8) == 3, "disagrees with the value in #[cxx::bridge]");
static_assert(static_cast<::std::int32_t>(QImageFormat::Format_RGB32) == 4, "disagrees with the value in #[cxx::bridge]");
static_assert(static_cast<::std::int32_t>(QImageFormat::Format_ARGB32) == 5, "disagrees with the value in #[cxx::bridge]");
static_assert(static_cast<::std::int32_t>(QImageFormat::Format_ARGB32_Premultiplied) == 6, "disagrees with the value in #[cxx::bridge]");
static_assert(static_cast<::std::int32_t>(QImageFormat::Format_RGB16) == 7, "disagrees with the value in #[cxx::bridge]");
static_assert(static_cast<::std::int32_t>(QImageFormat::Format_ARGB8565_Premultiplied) == 8, "disagrees with the value in #[cxx::bridge]");
static_assert(static_cast<::std::int32_t>(QImageFormat::Format_RGB666) == 9, "disagrees with the value in #[cxx::bridge]");
static_assert(static_cast<::std::int32_t>(QImageFormat::Format_ARGB6666_Premultiplied) == 10, "disagrees with the value in #[cxx::bridge]");
static_assert(static_cast<::std::int32_t>(QImageFormat::Format_RGB555) == 11, "disagrees with the value in #[cxx::bridge]");
static_assert(static_cast<::std::int32_t>(QImageFormat::Format_ARGB8555_Premultiplied) == 12, "disagrees with the value in #[cxx::bridge]");
static_assert(static_cast<::std::int32_t>(QImageFormat::Format_RGB888) == 13, "disagrees with the value in #[cxx::bridge]");
static_assert(static_cast<::std::int32_t>(QImageFormat::Format_RGB444) == 14, "disagrees with the value in #[cxx::bridge]");
static_assert(static_cast<::std::int32_t>(QImageFormat::Format_ARGB4444_Premultiplied) == 15, "disagrees with the value in #[cxx::bridge]");
static_assert(static_cast<::std::int32_t>(QImageFormat::Format_RGBX8888) == 16, "disagrees with the value in #[cxx::bridge]");
static_assert(static_cast<::std::int32_t>(QImageFormat::Format_RGBA8888) == 17, "disagrees with the value in #[cxx::bridge]");
static_assert(static_cast<::std::int32_t>(QImageFormat::Format_RGBA8888_Premultiplied) == 18, "disagrees with the value in #[cxx::bridge]");
static_assert(static_cast<::std::int32_t>(QImageFormat::Format_BGR30) == 19, "disagrees with the value in #[cxx::bridge]");
static_assert(static_cast<::std::int32_t>(QImageFormat::Format_A2BGR30_Premultiplied) == 20, "disagrees with the value in #[cxx::bridge]");
static_assert(static_cast<::std::int32_t>(QImageFormat::Format_RGB30) == 21, "disagrees with the value in #[cxx::bridge]");
static_assert(static_cast<::std::int32_t>(QImageFormat::Format_A2RGB30_Premultiplied) == 22, "disagrees with the value in #[cxx::bridge]");
static_assert(static_cast<::std::int32_t>(QImageFormat::Format_Alpha8) == 23, "disagrees with the value in #[cxx::bridge]");
static_assert(static_cast<::std::int32_t>(QImageFormat::Format_Grayscale8) == 24, "disagrees with the value in #[cxx::bridge]");
static_assert(static_cast<::std::int32_t>(QImageFormat::Format_RGBX64) == 25, "disagrees with the value in #[cxx::bridge]");
static_assert(static_cast<::std::int32_t>(QImageFormat::Format_RGBA64) == 26, "disagrees with the value in #[cxx::bridge]");
static_assert(static_cast<::std::int32_t>(QImageFormat::Format_RGBA64_Premultiplied) == 27, "disagrees with the value in #[cxx::bridge]");
static_assert(static_cast<::std::int32_t>(QImageFormat::Format_Grayscale16) == 28, "disagrees with the value in #[cxx::bridge]");
static_assert(static_cast<::std::int32_t>(QImageFormat::Format_BGR888) == 29, "disagrees with the value in #[cxx::bridge]");
} // namespace cxxqtlib1
} // namespace rust

static_assert(
    ::rust::IsRelocatable<::Qt::TransformationMode>::value,
    "type Qt::TransformationMode should be trivially move constructible and trivially destructible in C++ to be used as an argument of `scaled`, `scaled_to_height`, `scaled_to_width` in Rust");
static_assert(
    ::rust::IsRelocatable<::Qt::AspectRatioMode>::value,
    "type Qt::AspectRatioMode should be trivially move constructible and trivially destructible in C++ to be used as an argument of `scaled` in Rust");
static_assert(
    ::rust::IsRelocatable<::Qt::Orientations>::value,
    "type Qt::Orientations should be trivially move constructible and trivially destructible in C++ to be used as an argument of `flip` in Rust");
static_assert(
    ::rust::IsRelocatable<::QImage>::value,
    "type QImage should be trivially move constructible and trivially destructible in C++ to be used as a return value of `copy`, `create_heuristic_mask`, `scaled` in Rust");
static_assert(
    ::rust::IsRelocatable<::QSize>::value,
    "type QSize should be trivially move constructible and trivially destructible in C++ to be used as a return value of `size` in Rust");
static_assert(
    ::rust::IsRelocatable<::QString>::value,
    "type QString should be trivially move constructible and trivially destructible in C++ to be used as a return value of `qimage_to_debug_qstring` in Rust");
static_assert(
    ::rust::IsRelocatable<::QRect>::value,
    "type QRect should be trivially move constructible and trivially destructible in C++ to be used as a return value of `rect` in Rust");
static_assert(
    ::rust::IsRelocatable<::QColor>::value,
    "type QColor should be trivially move constructible and trivially destructible in C++ to be used as a return value of `pixel_color` in Rust");
static_assert(
    ::rust::IsRelocatable<::QPoint>::value,
    "type QPoint should be trivially move constructible and trivially destructible in C++ to be used as a return value of `offset` in Rust");
static_assert(
    ::rust::IsRelocatable<::QSizeF>::value,
    "type QSizeF should be trivially move constructible and trivially destructible in C++ to be used as a return value of `device_independent_size` in Rust");
static_assert(
    ::rust::IsRelocatable<::QImageCleanupFunction>::value,
    "type QImageCleanupFunction should be trivially move constructible and trivially destructible in C++ to be used as an argument of `qimage_init_from_raw_parts_mut`, `qimage_init_from_raw_parts` in Rust");

extern "C" {
bool cxxbridge1$194$QImage$all_gray(::QImage const &self) noexcept {
  bool (::QImage::*all_gray$)() const = &::QImage::allGray;
  return (self.*all_gray$)();
}

::std::int32_t cxxbridge1$194$QImage$bit_plane_count(::QImage const &self) noexcept {
  ::std::int32_t (::QImage::*bit_plane_count$)() const = &::QImage::bitPlaneCount;
  return (self.*bit_plane_count$)();
}

void cxxbridge1$194$QImage$copy(::QImage const &self, ::QRect const &rectangle, ::QImage *return$) noexcept {
  ::QImage (::QImage::*copy$)(::QRect const &) const = &::QImage::copy;
  new (return$) ::QImage((self.*copy$)(rectangle));
}

void cxxbridge1$194$QImage$create_heuristic_mask(::QImage const &self, bool clip_tight, ::QImage *return$) noexcept {
  ::QImage (::QImage::*create_heuristic_mask$)(bool) const = &::QImage::createHeuristicMask;
  new (return$) ::QImage((self.*create_heuristic_mask$)(clip_tight));
}

::std::int32_t cxxbridge1$194$QImage$color_count(::QImage const &self) noexcept {
  ::std::int32_t (::QImage::*color_count$)() const = &::QImage::colorCount;
  return (self.*color_count$)();
}

::std::int32_t cxxbridge1$194$QImage$depth(::QImage const &self) noexcept {
  ::std::int32_t (::QImage::*depth$)() const = &::QImage::depth;
  return (self.*depth$)();
}

void cxxbridge1$194$QImage$device_independent_size(::QImage const &self, ::QSizeF *return$) noexcept {
  ::QSizeF (::QImage::*device_independent_size$)() const = &::QImage::deviceIndependentSize;
  new (return$) ::QSizeF((self.*device_independent_size$)());
}

::std::int32_t cxxbridge1$194$QImage$dots_per_meter_x(::QImage const &self) noexcept {
  ::std::int32_t (::QImage::*dots_per_meter_x$)() const = &::QImage::dotsPerMeterX;
  return (self.*dots_per_meter_x$)();
}

::std::int32_t cxxbridge1$194$QImage$dots_per_meter_y(::QImage const &self) noexcept {
  ::std::int32_t (::QImage::*dots_per_meter_y$)() const = &::QImage::dotsPerMeterY;
  return (self.*dots_per_meter_y$)();
}

void cxxbridge1$194$QImage$fill(::QImage &self, ::QColor const &color) noexcept {
  void (::QImage::*fill$)(::QColor const &) = &::QImage::fill;
  (self.*fill$)(color);
}

void cxxbridge1$194$QImage$flip(::QImage &self, ::Qt::Orientations *orient) noexcept {
  void (::QImage::*flip$)(::Qt::Orientations) = &::QImage::flip;
  (self.*flip$)(::std::move(*orient));
}

::rust::cxxqtlib1::QImageFormat cxxbridge1$194$QImage$format(::QImage const &self) noexcept {
  ::rust::cxxqtlib1::QImageFormat (::QImage::*format$)() const = &::QImage::format;
  return (self.*format$)();
}

void cxxbridge1$194$QImage$invert_pixels(::QImage &self, ::rust::cxxqtlib1::QImageInvertMode mode) noexcept {
  void (::QImage::*invert_pixels$)(::rust::cxxqtlib1::QImageInvertMode) = &::QImage::invertPixels;
  (self.*invert_pixels$)(mode);
}

bool cxxbridge1$194$QImage$is_null(::QImage const &self) noexcept {
  bool (::QImage::*is_null$)() const = &::QImage::isNull;
  return (self.*is_null$)();
}

bool cxxbridge1$194$QImage$is_gray_scale(::QImage const &self) noexcept {
  bool (::QImage::*is_gray_scale$)() const = &::QImage::isGrayscale;
  return (self.*is_gray_scale$)();
}

bool cxxbridge1$194$QImage$has_alpha_channel(::QImage const &self) noexcept {
  bool (::QImage::*has_alpha_channel$)() const = &::QImage::hasAlphaChannel;
  return (self.*has_alpha_channel$)();
}

::std::int32_t cxxbridge1$194$QImage$height(::QImage const &self) noexcept {
  ::std::int32_t (::QImage::*height$)() const = &::QImage::height;
  return (self.*height$)();
}

void cxxbridge1$194$QImage$mirror(::QImage &self, bool horizontal, bool vertical) noexcept {
  void (::QImage::*mirror$)(bool, bool) = &::QImage::mirror;
  (self.*mirror$)(horizontal, vertical);
}

void cxxbridge1$194$QImage$rgb_swap(::QImage &self) noexcept {
  void (::QImage::*rgb_swap$)() = &::QImage::rgbSwap;
  (self.*rgb_swap$)();
}

void cxxbridge1$194$QImage$rect(::QImage const &self, ::QRect *return$) noexcept {
  ::QRect (::QImage::*rect$)() const = &::QImage::rect;
  new (return$) ::QRect((self.*rect$)());
}

void cxxbridge1$194$QImage$scaled(::QImage const &self, ::std::int32_t width, ::std::int32_t height, ::Qt::AspectRatioMode *aspect_ratio_mode, ::Qt::TransformationMode *transform_mode, ::QImage *return$) noexcept {
  ::QImage (::QImage::*scaled$)(::std::int32_t, ::std::int32_t, ::Qt::AspectRatioMode, ::Qt::TransformationMode) const = &::QImage::scaled;
  new (return$) ::QImage((self.*scaled$)(width, height, ::std::move(*aspect_ratio_mode), ::std::move(*transform_mode)));
}

void cxxbridge1$194$QImage$scaled_to_height(::QImage const &self, ::std::int32_t height, ::Qt::TransformationMode *mode, ::QImage *return$) noexcept {
  ::QImage (::QImage::*scaled_to_height$)(::std::int32_t, ::Qt::TransformationMode) const = &::QImage::scaledToHeight;
  new (return$) ::QImage((self.*scaled_to_height$)(height, ::std::move(*mode)));
}

void cxxbridge1$194$QImage$scaled_to_width(::QImage const &self, ::std::int32_t width, ::Qt::TransformationMode *mode, ::QImage *return$) noexcept {
  ::QImage (::QImage::*scaled_to_width$)(::std::int32_t, ::Qt::TransformationMode) const = &::QImage::scaledToWidth;
  new (return$) ::QImage((self.*scaled_to_width$)(width, ::std::move(*mode)));
}

void cxxbridge1$194$QImage$set_color_count(::QImage &self, ::std::int32_t color_count) noexcept {
  void (::QImage::*set_color_count$)(::std::int32_t) = &::QImage::setColorCount;
  (self.*set_color_count$)(color_count);
}

void cxxbridge1$194$QImage$set_alpha_channel(::QImage &self, ::QImage const &alpha_channel) noexcept {
  void (::QImage::*set_alpha_channel$)(::QImage const &) = &::QImage::setAlphaChannel;
  (self.*set_alpha_channel$)(alpha_channel);
}

void cxxbridge1$194$QImage$set_dots_per_meter_x(::QImage &self, ::std::int32_t x) noexcept {
  void (::QImage::*set_dots_per_meter_x$)(::std::int32_t) = &::QImage::setDotsPerMeterX;
  (self.*set_dots_per_meter_x$)(x);
}

void cxxbridge1$194$QImage$set_dots_per_meter_y(::QImage &self, ::std::int32_t y) noexcept {
  void (::QImage::*set_dots_per_meter_y$)(::std::int32_t) = &::QImage::setDotsPerMeterY;
  (self.*set_dots_per_meter_y$)(y);
}

void cxxbridge1$194$QImage$set_offset(::QImage &self, ::QPoint const &offset) noexcept {
  void (::QImage::*set_offset$)(::QPoint const &) = &::QImage::setOffset;
  (self.*set_offset$)(offset);
}

void cxxbridge1$194$QImage$set_pixel_color(::QImage &self, ::std::int32_t x, ::std::int32_t y, ::QColor const &color) noexcept {
  void (::QImage::*set_pixel_color$)(::std::int32_t, ::std::int32_t, ::QColor const &) = &::QImage::setPixelColor;
  (self.*set_pixel_color$)(x, y, color);
}

void cxxbridge1$194$QImage$size(::QImage const &self, ::QSize *return$) noexcept {
  ::QSize (::QImage::*size$)() const = &::QImage::size;
  new (return$) ::QSize((self.*size$)());
}

void cxxbridge1$194$QImage$swap(::QImage &self, ::QImage &other) noexcept {
  void (::QImage::*swap$)(::QImage &) = &::QImage::swap;
  (self.*swap$)(other);
}

bool cxxbridge1$194$QImage$reinterpret_as_format(::QImage &self, ::rust::cxxqtlib1::QImageFormat format) noexcept {
  bool (::QImage::*reinterpret_as_format$)(::rust::cxxqtlib1::QImageFormat) = &::QImage::reinterpretAsFormat;
  return (self.*reinterpret_as_format$)(format);
}

void cxxbridge1$194$QImage$offset(::QImage const &self, ::QPoint *return$) noexcept {
  ::QPoint (::QImage::*offset$)() const = &::QImage::offset;
  new (return$) ::QPoint((self.*offset$)());
}

void cxxbridge1$194$QImage$pixel_color(::QImage const &self, ::std::int32_t x, ::std::int32_t y, ::QColor *return$) noexcept {
  ::QColor (::QImage::*pixel_color$)(::std::int32_t, ::std::int32_t) const = &::QImage::pixelColor;
  new (return$) ::QColor((self.*pixel_color$)(x, y));
}

::std::int32_t cxxbridge1$194$QImage$pixel_index(::QImage const &self, ::std::int32_t x, ::std::int32_t y) noexcept {
  ::std::int32_t (::QImage::*pixel_index$)(::std::int32_t, ::std::int32_t) const = &::QImage::pixelIndex;
  return (self.*pixel_index$)(x, y);
}

bool cxxbridge1$194$QImage$valid(::QImage const &self, ::std::int32_t x, ::std::int32_t y) noexcept {
  bool (::QImage::*valid$)(::std::int32_t, ::std::int32_t) const = &::QImage::valid;
  return (self.*valid$)(x, y);
}

::std::int32_t cxxbridge1$194$QImage$width(::QImage const &self) noexcept {
  ::std::int32_t (::QImage::*width$)() const = &::QImage::width;
  return (self.*width$)();
}
} // extern "C"

namespace rust {
namespace cxxqtlib1 {
extern "C" {
void rust$cxxqtlib1$cxxbridge1$194$qimage_init_default(::QImage *return$) noexcept {
  ::QImage (*qimage_init_default$)() = ::rust::cxxqtlib1::construct;
  new (return$) ::QImage(qimage_init_default$());
}

void rust$cxxqtlib1$cxxbridge1$194$qimage_init_from_width_and_height_and_image_format(::std::int32_t width, ::std::int32_t height, ::rust::cxxqtlib1::QImageFormat format, ::QImage *return$) noexcept {
  ::QImage (*qimage_init_from_width_and_height_and_image_format$)(::std::int32_t, ::std::int32_t, ::rust::cxxqtlib1::QImageFormat) = ::rust::cxxqtlib1::construct;
  new (return$) ::QImage(qimage_init_from_width_and_height_and_image_format$(width, height, format));
}

void rust$cxxqtlib1$cxxbridge1$194$qimage_drop(::QImage &image) noexcept {
  void (*qimage_drop$)(::QImage &) = ::rust::cxxqtlib1::drop;
  qimage_drop$(image);
}

void rust$cxxqtlib1$cxxbridge1$194$qimage_init_from_data(::rust::Slice<::std::uint8_t const> data, ::rust::Str format, ::QImage *return$) noexcept {
  ::QImage (*qimage_init_from_data$)(::rust::Slice<::std::uint8_t const>, ::rust::Str) = ::rust::cxxqtlib1::qimageInitFromData;
  new (return$) ::QImage(qimage_init_from_data$(data, format));
}

::std::int64_t rust$cxxqtlib1$cxxbridge1$194$qimage_cache_key(::QImage const &image) noexcept {
  ::std::int64_t (*qimage_cache_key$)(::QImage const &) = ::rust::cxxqtlib1::qimageCacheKey;
  return qimage_cache_key$(image);
}

bool rust$cxxqtlib1$cxxbridge1$194$qimage_eq(::QImage const &a, ::QImage const &b) noexcept {
  bool (*qimage_eq$)(::QImage const &, ::QImage const &) = ::rust::cxxqtlib1::operatorEq;
  return qimage_eq$(a, b);
}

void rust$cxxqtlib1$cxxbridge1$194$qimage_to_debug_qstring(::QImage const &image, ::QString *return$) noexcept {
  ::QString (*qimage_to_debug_qstring$)(::QImage const &) = ::rust::cxxqtlib1::toDebugQString;
  new (return$) ::QString(qimage_to_debug_qstring$(image));
}

void rust$cxxqtlib1$cxxbridge1$194$qimage_init_from_raw_parts_mut(::uchar *data, ::std::int32_t width, ::std::int32_t height, ::rust::cxxqtlib1::QImageFormat format, ::QImageCleanupFunction *cleanup_function, ::rust::cxxqtlib1::c_void *cleanup_info, ::QImage *return$) noexcept {
  ::QImage (*qimage_init_from_raw_parts_mut$)(::uchar *, ::std::int32_t, ::std::int32_t, ::rust::cxxqtlib1::QImageFormat, ::QImageCleanupFunction, ::rust::cxxqtlib1::c_void *) = ::rust::cxxqtlib1::construct;
  new (return$) ::QImage(qimage_init_from_raw_parts_mut$(data, width, height, format, ::std::move(*cleanup_function), cleanup_info));
}

void rust$cxxqtlib1$cxxbridge1$194$qimage_init_from_raw_parts(::uchar const *data, ::std::int32_t width, ::std::int32_t height, ::rust::cxxqtlib1::QImageFormat format, ::QImageCleanupFunction *cleanup_function, ::rust::cxxqtlib1::c_void *cleanup_info, ::QImage *return$) noexcept {
  ::QImage (*qimage_init_from_raw_parts$)(::uchar const *, ::std::int32_t, ::std::int32_t, ::rust::cxxqtlib1::QImageFormat, ::QImageCleanupFunction, ::rust::cxxqtlib1::c_void *) = ::rust::cxxqtlib1::construct;
  new (return$) ::QImage(qimage_init_from_raw_parts$(data, width, height, format, ::std::move(*cleanup_function), cleanup_info));
}
} // extern "C"
} // namespace cxxqtlib1
} // namespace rust
