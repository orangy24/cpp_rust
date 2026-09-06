#pragma once

#include <cstddef>
#include <string>
#include <string_view>
#include <vector>

struct Reliable {
  static constexpr bool kReliable = true;
};
struct BestEffort {
  static constexpr bool kReliable = false;
};

template <std::size_t N>
struct KeepLast {
  static constexpr std::size_t kDepth = N;
};

template <typename Rel, typename Hist>
class Publisher {
 public:
  void publish(std::string_view bytes);
  bool qos_reliable() const;
  std::size_t qos_depth() const;
  std::vector<std::string> const& history() const { return history_; }

 private:
  std::vector<std::string> history_;
};
