#include "kata.hpp"

#include <utility>

void SamplePool::release() {
  // TODO: mark slot free (in_use_ = false)
}

void SamplePool::publish_from(std::string_view payload) {
  (void)payload;
  // TODO: last_ = std::string(payload); then release()
}

SampleLoan SamplePool::loan() {
  // TODO: if in_use_, return empty loan; else take slot, return SampleLoan(this)
  return {};
}

SampleLoan::SampleLoan(SamplePool* pool) : pool_(pool) {}

SampleLoan::~SampleLoan() {
  // TODO: if still holding a pool, release() without publishing
}

SampleLoan::SampleLoan(SampleLoan&& other) noexcept {
  (void)other;
}

SampleLoan& SampleLoan::operator=(SampleLoan&& other) noexcept {
  (void)other;
  return *this;
}

SampleLoan::operator bool() const { return pool_ != nullptr; }

std::string& SampleLoan::payload() {
  static std::string empty;
  if (!pool_) return empty;
  return pool_->slot_;
}

void SampleLoan::publish() {
  // TODO: publish_from(slot_), then pool_ = nullptr
}
