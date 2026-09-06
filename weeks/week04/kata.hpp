#pragma once

#include <concepts>
#include <string>
#include <string_view>

template <typename T>
concept Message = requires(T const& t) {
  { T::TYPE_NAME } -> std::convertible_to<std::string_view>;
  { t.payload() } -> std::convertible_to<std::string_view>;
};

inline std::string_view topic_type(Message auto const& msg) {
  (void)msg;
  // TODO: return T::TYPE_NAME
  return {};
}
