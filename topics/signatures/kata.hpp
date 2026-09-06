#pragma once

#include <cstdint>
#include <vector>

std::int64_t read_sum(std::vector<int> const& xs);
void append_copy(std::vector<int>& xs, int value);
std::int64_t take_and_sum(std::vector<int> xs);

template <typename T>
T first_or(std::vector<T> const& xs, T fallback) {
  (void)xs;
  // TODO: return xs.front() if !empty else fallback
  return fallback;
}
