#include "serialize.hpp"

std::string RawFormat::render(std::string_view bytes) {
  (void)bytes;
  return {};
}
std::string FramedFormat::render(std::string_view bytes) {
  (void)bytes;
  return {};
}

template <typename Rel, typename Fmt>
void Publisher<Rel, Fmt>::publish(std::string_view bytes) {
  (void)bytes;
  // TODO: history_.push_back(Fmt::render(bytes));
}

template class Publisher<Reliable, RawFormat>;
template class Publisher<Reliable, FramedFormat>;
