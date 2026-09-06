#include "kata.hpp"

#include <catch2/catch_test_macros.hpp>

TEST_CASE("keep last needs depth") {
  REQUIRE_FALSE(qos_ok(Reliability::Reliable, History::KeepLast, 0));
  REQUIRE(qos_ok(Reliability::Reliable, History::KeepLast, 1));
  REQUIRE(qos_ok(Reliability::BestEffort, History::KeepAll, 0));
}

TEST_CASE("depth_or_one") {
  REQUIRE(depth_or_one(History::KeepLast, 10) == 10);
  REQUIRE(depth_or_one(History::KeepAll, 99) == 1);
}
