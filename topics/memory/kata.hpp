#pragma once

#include <cstddef>
#include <cstdint>
#include <vector>

class Arena {
 public:
  explicit Arena(std::size_t capacity);
  void* allocate(std::size_t bytes, std::size_t alignment);
  void reset();
  std::size_t used() const;

 private:
  std::vector<std::uint8_t> buf_;
  std::size_t offset_ = 0;
};
