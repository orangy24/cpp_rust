#pragma once

#include <string>
#include <string_view>
#include <vector>

struct Reliable {
  static constexpr bool kReliable = true;
};

struct RawFormat {
  static std::string render(std::string_view bytes);
};
struct FramedFormat {
  static std::string render(std::string_view bytes);
};

template <typename Rel, typename Fmt>
class Publisher {
 public:
  void publish(std::string_view bytes);
  std::vector<std::string> const& history() const { return history_; }

 private:
  std::vector<std::string> history_;
};
