#include "kata.hpp"

#include <catch2/catch_test_macros.hpp>

TEST_CASE("Reliable KeepLast<10>") {
  Publisher<Reliable, KeepLast<10>> pub;
  REQUIRE(pub.qos_reliable());
  REQUIRE(pub.qos_depth() == 10);
  pub.publish("a");
  REQUIRE(pub.history() == std::vector<std::string>{"a"});
}

TEST_CASE("BestEffort KeepLast<1>") {
  Publisher<BestEffort, KeepLast<1>> pub;
  REQUIRE_FALSE(pub.qos_reliable());
  REQUIRE(pub.qos_depth() == 1);
}
