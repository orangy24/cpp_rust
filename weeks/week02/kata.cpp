#include "kata.hpp"

Expected<std::int32_t> parse_stamp(std::string_view text) {
  (void)text;
  // TODO: empty → Empty; from_chars whole string → ok; else Invalid
  return Expected<std::int32_t>::err(ParseErr::Invalid);
}

std::vector<std::string_view> split_fields(std::string_view input) {
  (void)input;
  // TODO: split on '|'; "a||b" → three views; empty input → empty vector
  return {};
}
