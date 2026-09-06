#include "kata.hpp"

#include <catch2/catch_test_macros.hpp>
#include <string_view>

struct LaserScan {
  static constexpr std::string_view TYPE_NAME = "sensor_msgs/LaserScan";
  std::string bytes{"range"};
  std::string_view payload() const { return bytes; }
};

struct NotAMessage {
  int x{};
};

TEST_CASE("concept") {
  STATIC_REQUIRE(Message<LaserScan>);
  STATIC_REQUIRE(!Message<NotAMessage>);
}

TEST_CASE("topic_type") {
  LaserScan m;
  REQUIRE(topic_type(m) == "sensor_msgs/LaserScan");
}
