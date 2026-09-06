#include "kata.hpp"

void Executor::add(std::function<void()> job) {
  (void)job;
}

void Executor::spin_once() {}

std::size_t Executor::size() const { return 0; }
