#pragma once

#include <cstdint>
#include <string_view>
#include <utility>
#include <vector>

enum class ParseErr { Empty, Invalid };

template <typename T>
class Expected {
 public:
  static Expected ok(T value) { return Expected(std::move(value)); }
  static Expected err(ParseErr e) { return Expected(e); }

  bool has_value() const { return ok_; }
  T const& value() const { return value_; }
  ParseErr error() const { return err_; }

 private:
  explicit Expected(T v) : ok_(true), value_(std::move(v)), err_{} {}
  explicit Expected(ParseErr e) : ok_(false), value_{}, err_(e) {}
  bool ok_{};
  T value_{};
  ParseErr err_{};
};

Expected<std::int32_t> parse_stamp(std::string_view text);
std::vector<std::string_view> split_fields(std::string_view input);
