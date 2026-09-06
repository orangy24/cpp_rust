#include "kata.hpp"

#include <catch2/catch_test_macros.hpp>

TEST_CASE("CRTP publish hits derived send_bytes") {
  LoopbackPublisher pub;
  pub.publish("scan");
  pub.publish("imu");
  REQUIRE(pub.sent() == 2);
  REQUIRE(pub.inbox() == std::vector<std::string>{"scan", "imu"});
}
