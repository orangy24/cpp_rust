#include "kata.hpp"

template <typename Rel, typename Hist>
void Publisher<Rel, Hist>::publish(std::string_view bytes) {
  (void)bytes;
  // TODO: append to history_
}

template <typename Rel, typename Hist>
bool Publisher<Rel, Hist>::qos_reliable() const {
  return false;
}

template <typename Rel, typename Hist>
std::size_t Publisher<Rel, Hist>::qos_depth() const {
  return 0;
}

template class Publisher<Reliable, KeepLast<10>>;
template class Publisher<BestEffort, KeepLast<1>>;
