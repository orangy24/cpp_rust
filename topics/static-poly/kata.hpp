#pragma once

#include <string>
#include <string_view>
#include <vector>

template <typename Derived>
class PublisherBase {
 public:
  void publish(std::string_view bytes);
  int sent() const { return sent_; }

 protected:
  int sent_ = 0;
};

class LoopbackPublisher : public PublisherBase<LoopbackPublisher> {
 public:
  void send_bytes(std::string_view bytes);
  std::vector<std::string> const& inbox() const { return inbox_; }

 private:
  std::vector<std::string> inbox_;
};
