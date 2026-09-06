#include "kata.hpp"

CountingSub::CountingSub(std::string topic) : topic_(std::move(topic)) {}

std::string_view CountingSub::topic() const { return topic_; }

void CountingSub::on_bytes(std::string_view bytes) {
  (void)bytes;
  // TODO: ++hits_
}

int CountingSub::hits() const { return hits_; }

void Node::add(std::unique_ptr<ISubscription> sub) {
  (void)sub;
  // TODO
}

void Node::inject(std::string_view topic, std::string_view bytes) {
  (void)topic;
  (void)bytes;
  // TODO: call on_bytes on subs whose topic() == topic
}
