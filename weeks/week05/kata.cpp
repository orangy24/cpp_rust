#include "kata.hpp"

template <typename Derived>
void PublisherBase<Derived>::publish(std::string_view bytes) {
  (void)bytes;
  // TODO: ++sent_; static_cast<Derived*>(this)->send_bytes(bytes);
}

void LoopbackPublisher::send_bytes(std::string_view bytes) {
  (void)bytes;
  // TODO: inbox_.emplace_back(bytes)
}

template class PublisherBase<LoopbackPublisher>;
