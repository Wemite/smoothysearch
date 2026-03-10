#include "cxx-qt-lib/qstring.h"
#include "cxx-qt-lib/qstringlist.h"
#include <QtCore/QObject>
#include "cxx-qt/connection.h"
#include "smoothysearch/src/backend.cxxqt.h"
#include <QtQml/QQmlEngine>
#include <cstddef>
#include <cstdint>
#include <new>
#include <type_traits>
#include <utility>

#ifdef __GNUC__
#pragma GCC diagnostic ignored "-Wmissing-declarations"
#pragma GCC diagnostic ignored "-Wshadow"
#ifdef __clang__
#pragma clang diagnostic ignored "-Wdollar-in-identifier-extension"
#endif // __clang__
#endif // __GNUC__

namespace rust {
inline namespace cxxbridge1 {
// #include "rust/cxx.h"

#ifndef CXXBRIDGE1_RUST_BOX
#define CXXBRIDGE1_RUST_BOX
template <typename T>
class Box final {
public:
  using element_type = T;
  using const_pointer =
      typename std::add_pointer<typename std::add_const<T>::type>::type;
  using pointer = typename std::add_pointer<T>::type;

  Box() = delete;
  Box(Box &&) noexcept;
  ~Box() noexcept;

  explicit Box(const T &);
  explicit Box(T &&);

  Box &operator=(Box &&) & noexcept;

  const T *operator->() const noexcept;
  const T &operator*() const noexcept;
  T *operator->() noexcept;
  T &operator*() noexcept;

  template <typename... Fields>
  static Box in_place(Fields &&...);

  void swap(Box &) noexcept;

  static Box from_raw(T *) noexcept;

  T *into_raw() noexcept;

  /* Deprecated */ using value_type = element_type;

private:
  class uninit;
  class allocation;
  Box(uninit) noexcept;
  void drop() noexcept;

  friend void swap(Box &lhs, Box &rhs) noexcept { lhs.swap(rhs); }

  T *ptr;
};

template <typename T>
class Box<T>::uninit {};

template <typename T>
class Box<T>::allocation {
  static T *alloc() noexcept;
  static void dealloc(T *) noexcept;

public:
  allocation() noexcept : ptr(alloc()) {}
  ~allocation() noexcept {
    if (this->ptr) {
      dealloc(this->ptr);
    }
  }
  T *ptr;
};

template <typename T>
Box<T>::Box(Box &&other) noexcept : ptr(other.ptr) {
  other.ptr = nullptr;
}

template <typename T>
Box<T>::Box(const T &val) {
  allocation alloc;
  ::new (alloc.ptr) T(val);
  this->ptr = alloc.ptr;
  alloc.ptr = nullptr;
}

template <typename T>
Box<T>::Box(T &&val) {
  allocation alloc;
  ::new (alloc.ptr) T(std::move(val));
  this->ptr = alloc.ptr;
  alloc.ptr = nullptr;
}

template <typename T>
Box<T>::~Box() noexcept {
  if (this->ptr) {
    this->drop();
  }
}

template <typename T>
Box<T> &Box<T>::operator=(Box &&other) & noexcept {
  if (this->ptr) {
    this->drop();
  }
  this->ptr = other.ptr;
  other.ptr = nullptr;
  return *this;
}

template <typename T>
const T *Box<T>::operator->() const noexcept {
  return this->ptr;
}

template <typename T>
const T &Box<T>::operator*() const noexcept {
  return *this->ptr;
}

template <typename T>
T *Box<T>::operator->() noexcept {
  return this->ptr;
}

template <typename T>
T &Box<T>::operator*() noexcept {
  return *this->ptr;
}

template <typename T>
template <typename... Fields>
Box<T> Box<T>::in_place(Fields &&...fields) {
  allocation alloc;
  auto ptr = alloc.ptr;
  ::new (ptr) T{std::forward<Fields>(fields)...};
  alloc.ptr = nullptr;
  return from_raw(ptr);
}

template <typename T>
void Box<T>::swap(Box &rhs) noexcept {
  using std::swap;
  swap(this->ptr, rhs.ptr);
}

template <typename T>
Box<T> Box<T>::from_raw(T *raw) noexcept {
  Box box = uninit{};
  box.ptr = raw;
  return box;
}

template <typename T>
T *Box<T>::into_raw() noexcept {
  T *raw = this->ptr;
  this->ptr = nullptr;
  return raw;
}

template <typename T>
Box<T>::Box(uninit) noexcept {}
#endif // CXXBRIDGE1_RUST_BOX

#ifndef CXXBRIDGE1_RUST_OPAQUE
#define CXXBRIDGE1_RUST_OPAQUE
class Opaque {
public:
  Opaque() = delete;
  Opaque(const Opaque &) = delete;
  ~Opaque() = delete;
};
#endif // CXXBRIDGE1_RUST_OPAQUE

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

namespace detail {
template <typename T, typename = void *>
struct operator_new {
  void *operator()(::std::size_t sz) { return ::operator new(sz); }
};

template <typename T>
struct operator_new<T, decltype(T::operator new(sizeof(T)))> {
  void *operator()(::std::size_t sz) { return T::operator new(sz); }
};
} // namespace detail

template <typename T>
union ManuallyDrop {
  T value;
  ManuallyDrop(T &&value) : value(::std::move(value)) {}
  ~ManuallyDrop() {}
};

template <typename T>
union MaybeUninit {
  T value;
  void *operator new(::std::size_t sz) { return detail::operator_new<T>{}(sz); }
  MaybeUninit() {}
  ~MaybeUninit() {}
};
} // namespace cxxbridge1
} // namespace rust

#if __cplusplus >= 201402L
#define CXX_DEFAULT_VALUE(value) = value
#else
#define CXX_DEFAULT_VALUE(value)
#endif

using Backend = ::Backend;
struct BackendRust;
namespace cxx_qt_Backend {
  struct CxxQtConstructorArguments0;
  struct CxxQtConstructorBaseArguments0;
  struct CxxQtConstructorNewArguments0;
  struct CxxQtConstructorInitializeArguments0;
}

#ifndef CXXBRIDGE1_STRUCT_BackendRust
#define CXXBRIDGE1_STRUCT_BackendRust
struct BackendRust final : public ::rust::Opaque {
  ~BackendRust() = delete;

private:
  friend ::rust::layout;
  struct layout {
    static ::std::size_t size() noexcept;
    static ::std::size_t align() noexcept;
  };
};
#endif // CXXBRIDGE1_STRUCT_BackendRust

namespace cxx_qt_Backend {
#ifndef CXXBRIDGE1_STRUCT_cxx_qt_Backend$CxxQtConstructorBaseArguments0
#define CXXBRIDGE1_STRUCT_cxx_qt_Backend$CxxQtConstructorBaseArguments0
struct CxxQtConstructorBaseArguments0 final {
  ::std::int8_t not_empty CXX_DEFAULT_VALUE(0);

  using IsRelocatable = ::std::true_type;
};
#endif // CXXBRIDGE1_STRUCT_cxx_qt_Backend$CxxQtConstructorBaseArguments0

#ifndef CXXBRIDGE1_STRUCT_cxx_qt_Backend$CxxQtConstructorNewArguments0
#define CXXBRIDGE1_STRUCT_cxx_qt_Backend$CxxQtConstructorNewArguments0
struct CxxQtConstructorNewArguments0 final {
  ::std::int8_t not_empty CXX_DEFAULT_VALUE(0);

  using IsRelocatable = ::std::true_type;
};
#endif // CXXBRIDGE1_STRUCT_cxx_qt_Backend$CxxQtConstructorNewArguments0

#ifndef CXXBRIDGE1_STRUCT_cxx_qt_Backend$CxxQtConstructorInitializeArguments0
#define CXXBRIDGE1_STRUCT_cxx_qt_Backend$CxxQtConstructorInitializeArguments0
struct CxxQtConstructorInitializeArguments0 final {
  ::std::int8_t not_empty CXX_DEFAULT_VALUE(0);

  using IsRelocatable = ::std::true_type;
};
#endif // CXXBRIDGE1_STRUCT_cxx_qt_Backend$CxxQtConstructorInitializeArguments0

#ifndef CXXBRIDGE1_STRUCT_cxx_qt_Backend$CxxQtConstructorArguments0
#define CXXBRIDGE1_STRUCT_cxx_qt_Backend$CxxQtConstructorArguments0
struct CxxQtConstructorArguments0 final {
  ::cxx_qt_Backend::CxxQtConstructorBaseArguments0 base;
  ::cxx_qt_Backend::CxxQtConstructorNewArguments0 new_;
  ::cxx_qt_Backend::CxxQtConstructorInitializeArguments0 initialize;

  using IsRelocatable = ::std::true_type;
};
#endif // CXXBRIDGE1_STRUCT_cxx_qt_Backend$CxxQtConstructorArguments0
} // namespace cxx_qt_Backend

static_assert(
    ::rust::IsRelocatable<::QString>::value,
    "type QString should be trivially move constructible and trivially destructible in C++ to be used as an argument of `set_current_text`, `set_command_preview`, `set_query` in Rust");
static_assert(
    ::rust::IsRelocatable<::QStringList>::value,
    "type QStringList should be trivially move constructible and trivially destructible in C++ to be used as an argument of `set_items`, `set_icon_paths` in Rust");
static_assert(
    ::rust::IsRelocatable<::Qt::ConnectionType>::value,
    "type Qt::ConnectionType should be trivially move constructible and trivially destructible in C++ to be used as an argument of `Backend_connect_current_text_changed`, `Backend_connect_items_changed`, `Backend_connect_icon_paths_changed` in Rust");
static_assert(
    ::rust::IsRelocatable<::rust::cxxqt1::QMetaObjectConnection>::value,
    "type rust::cxxqt1::QMetaObjectConnection should be trivially move constructible and trivially destructible in C++ to be used as a return value of `Backend_connect_current_text_changed`, `Backend_connect_items_changed`, `Backend_connect_icon_paths_changed` in Rust");
static_assert(
    ::rust::IsRelocatable<::rust::cxxqtgen1::BackendCxxQtSignalHandlercurrent_textChanged>::value,
    "type rust::cxxqtgen1::BackendCxxQtSignalHandlercurrent_textChanged should be trivially move constructible and trivially destructible in C++ to be used as an argument of `Backend_connect_current_text_changed`, `drop_Backend_signal_handler_current_textChanged` in Rust");
static_assert(
    ::rust::IsRelocatable<::rust::cxxqtgen1::BackendCxxQtSignalHandleritemsChanged>::value,
    "type rust::cxxqtgen1::BackendCxxQtSignalHandleritemsChanged should be trivially move constructible and trivially destructible in C++ to be used as an argument of `Backend_connect_items_changed`, `drop_Backend_signal_handler_itemsChanged` in Rust");
static_assert(
    ::rust::IsRelocatable<::rust::cxxqtgen1::BackendCxxQtSignalHandlericon_pathsChanged>::value,
    "type rust::cxxqtgen1::BackendCxxQtSignalHandlericon_pathsChanged should be trivially move constructible and trivially destructible in C++ to be used as an argument of `Backend_connect_icon_paths_changed`, `drop_Backend_signal_handler_icon_pathsChanged` in Rust");
static_assert(
    ::rust::IsRelocatable<::rust::cxxqtgen1::BackendCxxQtSignalHandlercurrent_indexChanged>::value,
    "type rust::cxxqtgen1::BackendCxxQtSignalHandlercurrent_indexChanged should be trivially move constructible and trivially destructible in C++ to be used as an argument of `Backend_connect_current_index_changed`, `drop_Backend_signal_handler_current_indexChanged` in Rust");
static_assert(
    ::rust::IsRelocatable<::rust::cxxqtgen1::BackendCxxQtSignalHandlershow_command_hintChanged>::value,
    "type rust::cxxqtgen1::BackendCxxQtSignalHandlershow_command_hintChanged should be trivially move constructible and trivially destructible in C++ to be used as an argument of `Backend_connect_show_command_hint_changed`, `drop_Backend_signal_handler_show_command_hintChanged` in Rust");
static_assert(
    ::rust::IsRelocatable<::rust::cxxqtgen1::BackendCxxQtSignalHandlercommand_previewChanged>::value,
    "type rust::cxxqtgen1::BackendCxxQtSignalHandlercommand_previewChanged should be trivially move constructible and trivially destructible in C++ to be used as an argument of `Backend_connect_command_preview_changed`, `drop_Backend_signal_handler_command_previewChanged` in Rust");

extern "C" {
::std::size_t cxxbridge1$194$BackendRust$operator$sizeof() noexcept;
::std::size_t cxxbridge1$194$BackendRust$operator$alignof() noexcept;

::QString const *cxxbridge1$194$Backend$current_text(::Backend const &self) noexcept;

void cxxbridge1$194$Backend$set_current_text(::Backend &self, ::QString *value) noexcept;

::QStringList const *cxxbridge1$194$Backend$items(::Backend const &self) noexcept;

void cxxbridge1$194$Backend$set_items(::Backend &self, ::QStringList *value) noexcept;

::QStringList const *cxxbridge1$194$Backend$icon_paths(::Backend const &self) noexcept;

void cxxbridge1$194$Backend$set_icon_paths(::Backend &self, ::QStringList *value) noexcept;

::std::int32_t const *cxxbridge1$194$Backend$current_index(::Backend const &self) noexcept;

void cxxbridge1$194$Backend$set_current_index(::Backend &self, ::std::int32_t value) noexcept;

bool const *cxxbridge1$194$Backend$show_command_hint(::Backend const &self) noexcept;

void cxxbridge1$194$Backend$set_show_command_hint(::Backend &self, bool value) noexcept;

::QString const *cxxbridge1$194$Backend$command_preview(::Backend const &self) noexcept;

void cxxbridge1$194$Backend$set_command_preview(::Backend &self, ::QString *value) noexcept;

void cxxbridge1$194$Backend$current_text_changed(::Backend &self) noexcept {
  void (::Backend::*current_text_changed$)() = &::Backend::current_textChanged;
  (self.*current_text_changed$)();
}
} // extern "C"

namespace rust {
namespace cxxqtgen1 {
extern "C" {
void rust$cxxqtgen1$cxxbridge1$194$Backend_connect_current_text_changed(::Backend &self_value, ::rust::cxxqtgen1::BackendCxxQtSignalHandlercurrent_textChanged *signal_handler, ::Qt::ConnectionType *conn_type, ::rust::cxxqt1::QMetaObjectConnection *return$) noexcept {
  ::rust::cxxqt1::QMetaObjectConnection (*Backend_connect_current_text_changed$)(::Backend &, ::rust::cxxqtgen1::BackendCxxQtSignalHandlercurrent_textChanged, ::Qt::ConnectionType) = ::rust::cxxqtgen1::Backend_current_textChangedConnect;
  new (return$) ::rust::cxxqt1::QMetaObjectConnection(Backend_connect_current_text_changed$(self_value, ::std::move(*signal_handler), ::std::move(*conn_type)));
}

void rust$cxxqtgen1$cxxbridge1$194$drop_Backend_signal_handler_current_textChanged(::rust::cxxqtgen1::BackendCxxQtSignalHandlercurrent_textChanged *handler) noexcept;

void rust$cxxqtgen1$cxxbridge1$194$call_Backend_signal_handler_current_textChanged(::rust::cxxqtgen1::BackendCxxQtSignalHandlercurrent_textChanged &handler, ::Backend &self_value) noexcept;
} // extern "C"
} // namespace cxxqtgen1
} // namespace rust

extern "C" {
void cxxbridge1$194$Backend$items_changed(::Backend &self) noexcept {
  void (::Backend::*items_changed$)() = &::Backend::itemsChanged;
  (self.*items_changed$)();
}
} // extern "C"

namespace rust {
namespace cxxqtgen1 {
extern "C" {
void rust$cxxqtgen1$cxxbridge1$194$Backend_connect_items_changed(::Backend &self_value, ::rust::cxxqtgen1::BackendCxxQtSignalHandleritemsChanged *signal_handler, ::Qt::ConnectionType *conn_type, ::rust::cxxqt1::QMetaObjectConnection *return$) noexcept {
  ::rust::cxxqt1::QMetaObjectConnection (*Backend_connect_items_changed$)(::Backend &, ::rust::cxxqtgen1::BackendCxxQtSignalHandleritemsChanged, ::Qt::ConnectionType) = ::rust::cxxqtgen1::Backend_itemsChangedConnect;
  new (return$) ::rust::cxxqt1::QMetaObjectConnection(Backend_connect_items_changed$(self_value, ::std::move(*signal_handler), ::std::move(*conn_type)));
}

void rust$cxxqtgen1$cxxbridge1$194$drop_Backend_signal_handler_itemsChanged(::rust::cxxqtgen1::BackendCxxQtSignalHandleritemsChanged *handler) noexcept;

void rust$cxxqtgen1$cxxbridge1$194$call_Backend_signal_handler_itemsChanged(::rust::cxxqtgen1::BackendCxxQtSignalHandleritemsChanged &handler, ::Backend &self_value) noexcept;
} // extern "C"
} // namespace cxxqtgen1
} // namespace rust

extern "C" {
void cxxbridge1$194$Backend$icon_paths_changed(::Backend &self) noexcept {
  void (::Backend::*icon_paths_changed$)() = &::Backend::icon_pathsChanged;
  (self.*icon_paths_changed$)();
}
} // extern "C"

namespace rust {
namespace cxxqtgen1 {
extern "C" {
void rust$cxxqtgen1$cxxbridge1$194$Backend_connect_icon_paths_changed(::Backend &self_value, ::rust::cxxqtgen1::BackendCxxQtSignalHandlericon_pathsChanged *signal_handler, ::Qt::ConnectionType *conn_type, ::rust::cxxqt1::QMetaObjectConnection *return$) noexcept {
  ::rust::cxxqt1::QMetaObjectConnection (*Backend_connect_icon_paths_changed$)(::Backend &, ::rust::cxxqtgen1::BackendCxxQtSignalHandlericon_pathsChanged, ::Qt::ConnectionType) = ::rust::cxxqtgen1::Backend_icon_pathsChangedConnect;
  new (return$) ::rust::cxxqt1::QMetaObjectConnection(Backend_connect_icon_paths_changed$(self_value, ::std::move(*signal_handler), ::std::move(*conn_type)));
}

void rust$cxxqtgen1$cxxbridge1$194$drop_Backend_signal_handler_icon_pathsChanged(::rust::cxxqtgen1::BackendCxxQtSignalHandlericon_pathsChanged *handler) noexcept;

void rust$cxxqtgen1$cxxbridge1$194$call_Backend_signal_handler_icon_pathsChanged(::rust::cxxqtgen1::BackendCxxQtSignalHandlericon_pathsChanged &handler, ::Backend &self_value) noexcept;
} // extern "C"
} // namespace cxxqtgen1
} // namespace rust

extern "C" {
void cxxbridge1$194$Backend$current_index_changed(::Backend &self) noexcept {
  void (::Backend::*current_index_changed$)() = &::Backend::current_indexChanged;
  (self.*current_index_changed$)();
}
} // extern "C"

namespace rust {
namespace cxxqtgen1 {
extern "C" {
void rust$cxxqtgen1$cxxbridge1$194$Backend_connect_current_index_changed(::Backend &self_value, ::rust::cxxqtgen1::BackendCxxQtSignalHandlercurrent_indexChanged *signal_handler, ::Qt::ConnectionType *conn_type, ::rust::cxxqt1::QMetaObjectConnection *return$) noexcept {
  ::rust::cxxqt1::QMetaObjectConnection (*Backend_connect_current_index_changed$)(::Backend &, ::rust::cxxqtgen1::BackendCxxQtSignalHandlercurrent_indexChanged, ::Qt::ConnectionType) = ::rust::cxxqtgen1::Backend_current_indexChangedConnect;
  new (return$) ::rust::cxxqt1::QMetaObjectConnection(Backend_connect_current_index_changed$(self_value, ::std::move(*signal_handler), ::std::move(*conn_type)));
}

void rust$cxxqtgen1$cxxbridge1$194$drop_Backend_signal_handler_current_indexChanged(::rust::cxxqtgen1::BackendCxxQtSignalHandlercurrent_indexChanged *handler) noexcept;

void rust$cxxqtgen1$cxxbridge1$194$call_Backend_signal_handler_current_indexChanged(::rust::cxxqtgen1::BackendCxxQtSignalHandlercurrent_indexChanged &handler, ::Backend &self_value) noexcept;
} // extern "C"
} // namespace cxxqtgen1
} // namespace rust

extern "C" {
void cxxbridge1$194$Backend$show_command_hint_changed(::Backend &self) noexcept {
  void (::Backend::*show_command_hint_changed$)() = &::Backend::show_command_hintChanged;
  (self.*show_command_hint_changed$)();
}
} // extern "C"

namespace rust {
namespace cxxqtgen1 {
extern "C" {
void rust$cxxqtgen1$cxxbridge1$194$Backend_connect_show_command_hint_changed(::Backend &self_value, ::rust::cxxqtgen1::BackendCxxQtSignalHandlershow_command_hintChanged *signal_handler, ::Qt::ConnectionType *conn_type, ::rust::cxxqt1::QMetaObjectConnection *return$) noexcept {
  ::rust::cxxqt1::QMetaObjectConnection (*Backend_connect_show_command_hint_changed$)(::Backend &, ::rust::cxxqtgen1::BackendCxxQtSignalHandlershow_command_hintChanged, ::Qt::ConnectionType) = ::rust::cxxqtgen1::Backend_show_command_hintChangedConnect;
  new (return$) ::rust::cxxqt1::QMetaObjectConnection(Backend_connect_show_command_hint_changed$(self_value, ::std::move(*signal_handler), ::std::move(*conn_type)));
}

void rust$cxxqtgen1$cxxbridge1$194$drop_Backend_signal_handler_show_command_hintChanged(::rust::cxxqtgen1::BackendCxxQtSignalHandlershow_command_hintChanged *handler) noexcept;

void rust$cxxqtgen1$cxxbridge1$194$call_Backend_signal_handler_show_command_hintChanged(::rust::cxxqtgen1::BackendCxxQtSignalHandlershow_command_hintChanged &handler, ::Backend &self_value) noexcept;
} // extern "C"
} // namespace cxxqtgen1
} // namespace rust

extern "C" {
void cxxbridge1$194$Backend$command_preview_changed(::Backend &self) noexcept {
  void (::Backend::*command_preview_changed$)() = &::Backend::command_previewChanged;
  (self.*command_preview_changed$)();
}
} // extern "C"

namespace rust {
namespace cxxqtgen1 {
extern "C" {
void rust$cxxqtgen1$cxxbridge1$194$Backend_connect_command_preview_changed(::Backend &self_value, ::rust::cxxqtgen1::BackendCxxQtSignalHandlercommand_previewChanged *signal_handler, ::Qt::ConnectionType *conn_type, ::rust::cxxqt1::QMetaObjectConnection *return$) noexcept {
  ::rust::cxxqt1::QMetaObjectConnection (*Backend_connect_command_preview_changed$)(::Backend &, ::rust::cxxqtgen1::BackendCxxQtSignalHandlercommand_previewChanged, ::Qt::ConnectionType) = ::rust::cxxqtgen1::Backend_command_previewChangedConnect;
  new (return$) ::rust::cxxqt1::QMetaObjectConnection(Backend_connect_command_preview_changed$(self_value, ::std::move(*signal_handler), ::std::move(*conn_type)));
}

void rust$cxxqtgen1$cxxbridge1$194$drop_Backend_signal_handler_command_previewChanged(::rust::cxxqtgen1::BackendCxxQtSignalHandlercommand_previewChanged *handler) noexcept;

void rust$cxxqtgen1$cxxbridge1$194$call_Backend_signal_handler_command_previewChanged(::rust::cxxqtgen1::BackendCxxQtSignalHandlercommand_previewChanged &handler, ::Backend &self_value) noexcept;
} // extern "C"
} // namespace cxxqtgen1
} // namespace rust

extern "C" {
void cxxbridge1$194$Backend$set_query(::Backend &self, ::QString *value) noexcept;

void cxxbridge1$194$Backend$move_down(::Backend &self) noexcept;

void cxxbridge1$194$Backend$move_up(::Backend &self) noexcept;

void cxxbridge1$194$Backend$select_index(::Backend &self, ::std::int32_t index) noexcept;

void cxxbridge1$194$Backend$launch_current(::Backend &self) noexcept;
} // extern "C"

namespace rust {
namespace cxxqt1 {
extern "C" {
::QObject const *rust$cxxqt1$cxxbridge1$194$cxx_qt_ffi_Backend_upcastPtr(::Backend const *thiz) noexcept {
  ::QObject const *(*cxx_qt_ffi_Backend_upcastPtr$)(::Backend const *) = ::rust::cxxqt1::upcastPtr;
  return cxx_qt_ffi_Backend_upcastPtr$(thiz);
}

::Backend const *rust$cxxqt1$cxxbridge1$194$cxx_qt_ffi_Backend_downcastPtr(::QObject const *base) noexcept {
  ::Backend const *(*cxx_qt_ffi_Backend_downcastPtr$)(::QObject const *) = ::rust::cxxqt1::downcastPtr;
  return cxx_qt_ffi_Backend_downcastPtr$(base);
}
} // extern "C"
} // namespace cxxqt1
} // namespace rust

namespace cxx_qt_Backend {
extern "C" {
void cxx_qt_Backend$cxxbridge1$194$route_arguments_Backend_0(::cxx_qt_Backend::CxxQtConstructorArguments0 *return$) noexcept;

::BackendRust *cxx_qt_Backend$cxxbridge1$194$new_rs_Backend_0(::cxx_qt_Backend::CxxQtConstructorNewArguments0 *args) noexcept;

void cxx_qt_Backend$cxxbridge1$194$initialize_Backend_0(::Backend &qobject, ::cxx_qt_Backend::CxxQtConstructorInitializeArguments0 *args) noexcept;
} // extern "C"
} // namespace cxx_qt_Backend

namespace rust {
namespace cxxqt1 {
extern "C" {
void rust$cxxqt1$cxxbridge1$194$cxx_qt_ffi_Backend_unsafeRust(::Backend const &outer, ::BackendRust const **return$) noexcept {
  ::BackendRust const &(*cxx_qt_ffi_Backend_unsafeRust$)(::Backend const &) = ::rust::cxxqt1::unsafeRust;
  new (return$) ::BackendRust const *(&cxx_qt_ffi_Backend_unsafeRust$(outer));
}

void rust$cxxqt1$cxxbridge1$194$cxx_qt_ffi_Backend_unsafeRustMut(::Backend &outer, ::BackendRust **return$) noexcept {
  ::BackendRust &(*cxx_qt_ffi_Backend_unsafeRustMut$)(::Backend &) = ::rust::cxxqt1::unsafeRustMut;
  new (return$) ::BackendRust *(&cxx_qt_ffi_Backend_unsafeRustMut$(outer));
}
} // extern "C"
} // namespace cxxqt1
} // namespace rust

::std::size_t BackendRust::layout::size() noexcept {
  return cxxbridge1$194$BackendRust$operator$sizeof();
}

::std::size_t BackendRust::layout::align() noexcept {
  return cxxbridge1$194$BackendRust$operator$alignof();
}

::QString const &Backend::getCurrent_text() const noexcept {
  return *cxxbridge1$194$Backend$current_text(*this);
}

void Backend::setCurrent_text(::QString value) noexcept {
  ::rust::ManuallyDrop<::QString> value$(::std::move(value));
  cxxbridge1$194$Backend$set_current_text(*this, &value$.value);
}

::QStringList const &Backend::getItems() const noexcept {
  return *cxxbridge1$194$Backend$items(*this);
}

void Backend::setItems(::QStringList value) noexcept {
  ::rust::ManuallyDrop<::QStringList> value$(::std::move(value));
  cxxbridge1$194$Backend$set_items(*this, &value$.value);
}

::QStringList const &Backend::getIcon_paths() const noexcept {
  return *cxxbridge1$194$Backend$icon_paths(*this);
}

void Backend::setIcon_paths(::QStringList value) noexcept {
  ::rust::ManuallyDrop<::QStringList> value$(::std::move(value));
  cxxbridge1$194$Backend$set_icon_paths(*this, &value$.value);
}

::std::int32_t const &Backend::getCurrent_index() const noexcept {
  return *cxxbridge1$194$Backend$current_index(*this);
}

void Backend::setCurrent_index(::std::int32_t value) noexcept {
  cxxbridge1$194$Backend$set_current_index(*this, value);
}

bool const &Backend::getShow_command_hint() const noexcept {
  return *cxxbridge1$194$Backend$show_command_hint(*this);
}

void Backend::setShow_command_hint(bool value) noexcept {
  cxxbridge1$194$Backend$set_show_command_hint(*this, value);
}

::QString const &Backend::getCommand_preview() const noexcept {
  return *cxxbridge1$194$Backend$command_preview(*this);
}

void Backend::setCommand_preview(::QString value) noexcept {
  ::rust::ManuallyDrop<::QString> value$(::std::move(value));
  cxxbridge1$194$Backend$set_command_preview(*this, &value$.value);
}

namespace rust {
namespace cxxqtgen1 {
void drop_Backend_signal_handler_current_textChanged(::rust::cxxqtgen1::BackendCxxQtSignalHandlercurrent_textChanged handler) noexcept {
  ::rust::ManuallyDrop<::rust::cxxqtgen1::BackendCxxQtSignalHandlercurrent_textChanged> handler$(::std::move(handler));
  rust$cxxqtgen1$cxxbridge1$194$drop_Backend_signal_handler_current_textChanged(&handler$.value);
}

void call_Backend_signal_handler_current_textChanged(::rust::cxxqtgen1::BackendCxxQtSignalHandlercurrent_textChanged &handler, ::Backend &self_value) noexcept {
  rust$cxxqtgen1$cxxbridge1$194$call_Backend_signal_handler_current_textChanged(handler, self_value);
}

void drop_Backend_signal_handler_itemsChanged(::rust::cxxqtgen1::BackendCxxQtSignalHandleritemsChanged handler) noexcept {
  ::rust::ManuallyDrop<::rust::cxxqtgen1::BackendCxxQtSignalHandleritemsChanged> handler$(::std::move(handler));
  rust$cxxqtgen1$cxxbridge1$194$drop_Backend_signal_handler_itemsChanged(&handler$.value);
}

void call_Backend_signal_handler_itemsChanged(::rust::cxxqtgen1::BackendCxxQtSignalHandleritemsChanged &handler, ::Backend &self_value) noexcept {
  rust$cxxqtgen1$cxxbridge1$194$call_Backend_signal_handler_itemsChanged(handler, self_value);
}

void drop_Backend_signal_handler_icon_pathsChanged(::rust::cxxqtgen1::BackendCxxQtSignalHandlericon_pathsChanged handler) noexcept {
  ::rust::ManuallyDrop<::rust::cxxqtgen1::BackendCxxQtSignalHandlericon_pathsChanged> handler$(::std::move(handler));
  rust$cxxqtgen1$cxxbridge1$194$drop_Backend_signal_handler_icon_pathsChanged(&handler$.value);
}

void call_Backend_signal_handler_icon_pathsChanged(::rust::cxxqtgen1::BackendCxxQtSignalHandlericon_pathsChanged &handler, ::Backend &self_value) noexcept {
  rust$cxxqtgen1$cxxbridge1$194$call_Backend_signal_handler_icon_pathsChanged(handler, self_value);
}

void drop_Backend_signal_handler_current_indexChanged(::rust::cxxqtgen1::BackendCxxQtSignalHandlercurrent_indexChanged handler) noexcept {
  ::rust::ManuallyDrop<::rust::cxxqtgen1::BackendCxxQtSignalHandlercurrent_indexChanged> handler$(::std::move(handler));
  rust$cxxqtgen1$cxxbridge1$194$drop_Backend_signal_handler_current_indexChanged(&handler$.value);
}

void call_Backend_signal_handler_current_indexChanged(::rust::cxxqtgen1::BackendCxxQtSignalHandlercurrent_indexChanged &handler, ::Backend &self_value) noexcept {
  rust$cxxqtgen1$cxxbridge1$194$call_Backend_signal_handler_current_indexChanged(handler, self_value);
}

void drop_Backend_signal_handler_show_command_hintChanged(::rust::cxxqtgen1::BackendCxxQtSignalHandlershow_command_hintChanged handler) noexcept {
  ::rust::ManuallyDrop<::rust::cxxqtgen1::BackendCxxQtSignalHandlershow_command_hintChanged> handler$(::std::move(handler));
  rust$cxxqtgen1$cxxbridge1$194$drop_Backend_signal_handler_show_command_hintChanged(&handler$.value);
}

void call_Backend_signal_handler_show_command_hintChanged(::rust::cxxqtgen1::BackendCxxQtSignalHandlershow_command_hintChanged &handler, ::Backend &self_value) noexcept {
  rust$cxxqtgen1$cxxbridge1$194$call_Backend_signal_handler_show_command_hintChanged(handler, self_value);
}

void drop_Backend_signal_handler_command_previewChanged(::rust::cxxqtgen1::BackendCxxQtSignalHandlercommand_previewChanged handler) noexcept {
  ::rust::ManuallyDrop<::rust::cxxqtgen1::BackendCxxQtSignalHandlercommand_previewChanged> handler$(::std::move(handler));
  rust$cxxqtgen1$cxxbridge1$194$drop_Backend_signal_handler_command_previewChanged(&handler$.value);
}

void call_Backend_signal_handler_command_previewChanged(::rust::cxxqtgen1::BackendCxxQtSignalHandlercommand_previewChanged &handler, ::Backend &self_value) noexcept {
  rust$cxxqtgen1$cxxbridge1$194$call_Backend_signal_handler_command_previewChanged(handler, self_value);
}
} // namespace cxxqtgen1
} // namespace rust

void Backend::set_query(::QString value) noexcept {
  ::rust::ManuallyDrop<::QString> value$(::std::move(value));
  cxxbridge1$194$Backend$set_query(*this, &value$.value);
}

void Backend::move_down() noexcept {
  cxxbridge1$194$Backend$move_down(*this);
}

void Backend::move_up() noexcept {
  cxxbridge1$194$Backend$move_up(*this);
}

void Backend::select_index(::std::int32_t index) noexcept {
  cxxbridge1$194$Backend$select_index(*this, index);
}

void Backend::launch_current() noexcept {
  cxxbridge1$194$Backend$launch_current(*this);
}

namespace cxx_qt_Backend {
::cxx_qt_Backend::CxxQtConstructorArguments0 routeArguments0() noexcept {
  ::rust::MaybeUninit<::cxx_qt_Backend::CxxQtConstructorArguments0> return$;
  cxx_qt_Backend$cxxbridge1$194$route_arguments_Backend_0(&return$.value);
  return ::std::move(return$.value);
}

::rust::Box<::BackendRust> newRs0(::cxx_qt_Backend::CxxQtConstructorNewArguments0 args) noexcept {
  ::rust::ManuallyDrop<::cxx_qt_Backend::CxxQtConstructorNewArguments0> args$(::std::move(args));
  return ::rust::Box<::BackendRust>::from_raw(cxx_qt_Backend$cxxbridge1$194$new_rs_Backend_0(&args$.value));
}

void initialize0(::Backend &qobject, ::cxx_qt_Backend::CxxQtConstructorInitializeArguments0 args) noexcept {
  ::rust::ManuallyDrop<::cxx_qt_Backend::CxxQtConstructorInitializeArguments0> args$(::std::move(args));
  cxx_qt_Backend$cxxbridge1$194$initialize_Backend_0(qobject, &args$.value);
}
} // namespace cxx_qt_Backend

extern "C" {
::BackendRust *cxxbridge1$box$BackendRust$alloc() noexcept;
void cxxbridge1$box$BackendRust$dealloc(::BackendRust *) noexcept;
void cxxbridge1$box$BackendRust$drop(::rust::Box<::BackendRust> *ptr) noexcept;
} // extern "C"

namespace rust {
inline namespace cxxbridge1 {
template <>
::BackendRust *Box<::BackendRust>::allocation::alloc() noexcept {
  return cxxbridge1$box$BackendRust$alloc();
}
template <>
void Box<::BackendRust>::allocation::dealloc(::BackendRust *ptr) noexcept {
  cxxbridge1$box$BackendRust$dealloc(ptr);
}
template <>
void Box<::BackendRust>::drop() noexcept {
  cxxbridge1$box$BackendRust$drop(this);
}
} // namespace cxxbridge1
} // namespace rust
