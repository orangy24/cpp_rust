#include "kata.hpp"

UniqueFunction::operator bool() const { return static_cast<bool>(impl_); }

void UniqueFunction::operator()() {
  // TODO: invoke if impl_
}
