#include "kata.hpp"

Arena::Arena(std::size_t capacity) : buf_(capacity) {}

void* Arena::allocate(std::size_t bytes, std::size_t alignment) {
  (void)bytes;
  (void)alignment;
  // TODO: bump offset_ to satisfy alignment, then reserve `bytes`.
  return nullptr;
}

void Arena::reset() {
  // TODO
}

std::size_t Arena::used() const { return offset_; }
