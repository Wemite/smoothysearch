#include "cxx-qt-lib/qstring.h"
#include "cxx-qt-lib/qtlogging.h"
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

using QtMsgType = ::QtMsgType;

static_assert(::std::is_enum<QtMsgType>::value, "expected enum");
static_assert(sizeof(QtMsgType) == sizeof(::std::int32_t), "incorrect size");
static_assert(static_cast<::std::int32_t>(QtMsgType::QtDebugMsg) == 0, "disagrees with the value in #[cxx::bridge]");
static_assert(static_cast<::std::int32_t>(QtMsgType::QtInfoMsg) == 4, "disagrees with the value in #[cxx::bridge]");
static_assert(static_cast<::std::int32_t>(QtMsgType::QtWarningMsg) == 1, "disagrees with the value in #[cxx::bridge]");
static_assert(static_cast<::std::int32_t>(QtMsgType::QtFatalMsg) == 3, "disagrees with the value in #[cxx::bridge]");
static_assert(static_cast<::std::int32_t>(QtMsgType::QtCriticalMsg) == 2, "disagrees with the value in #[cxx::bridge]");

static_assert(
    ::rust::IsRelocatable<::QString>::value,
    "type QString should be trivially move constructible and trivially destructible in C++ to be used as a return value of `q_format_log_message` in Rust");
static_assert(
    ::rust::IsRelocatable<::QMessageLogContext>::value,
    "type QMessageLogContext should be trivially move constructible and trivially destructible in C++ to be used as a return value of `construct_qmessagelogcontext` in Rust");

extern "C" {
void cxxbridge1$194$qt_message_output(::QtMsgType msg_type, ::QMessageLogContext const &context, ::QString const &string) noexcept {
  void (*qt_message_output$)(::QtMsgType, ::QMessageLogContext const &, ::QString const &) = ::qt_message_output;
  qt_message_output$(msg_type, context, string);
}

void cxxbridge1$194$q_format_log_message(::QtMsgType msg_type, ::QMessageLogContext const &context, ::QString const &str, ::QString *return$) noexcept {
  ::QString (*q_format_log_message$)(::QtMsgType, ::QMessageLogContext const &, ::QString const &) = ::qFormatLogMessage;
  new (return$) ::QString(q_format_log_message$(msg_type, context, str));
}

void cxxbridge1$194$q_set_message_pattern(::QString const &pattern) noexcept {
  void (*q_set_message_pattern$)(::QString const &) = ::qSetMessagePattern;
  q_set_message_pattern$(pattern);
}

::std::int32_t cxxbridge1$194$line(::QMessageLogContext const &context) noexcept {
  ::std::int32_t (*line$)(::QMessageLogContext const &) = ::qmessagelogcontext_line;
  return line$(context);
}

char const *cxxbridge1$194$file(::QMessageLogContext const &context) noexcept {
  char const *(*file$)(::QMessageLogContext const &) = ::qmessagelogcontext_file;
  return file$(context);
}

char const *cxxbridge1$194$function(::QMessageLogContext const &context) noexcept {
  char const *(*function$)(::QMessageLogContext const &) = ::qmessagelogcontext_function;
  return function$(context);
}

char const *cxxbridge1$194$category(::QMessageLogContext const &context) noexcept {
  char const *(*category$)(::QMessageLogContext const &) = ::qmessagelogcontext_category;
  return category$(context);
}
} // extern "C"

namespace rust {
namespace cxxqtlib1 {
extern "C" {
void rust$cxxqtlib1$cxxbridge1$194$construct_qmessagelogcontext(char const *file_name, ::std::int32_t line_number, char const *function_name, char const *category_name, ::QMessageLogContext *return$) noexcept {
  ::QMessageLogContext (*construct_qmessagelogcontext$)(char const *, ::std::int32_t, char const *, char const *) = ::rust::cxxqtlib1::construct;
  new (return$) ::QMessageLogContext(construct_qmessagelogcontext$(file_name, line_number, function_name, category_name));
}
} // extern "C"
} // namespace cxxqtlib1
} // namespace rust
