#include "kata.hpp"

#include <catch2/catch_test_macros.hpp>
#include <string>

TEST_CASE("typed delivery") {
  TopicHub hub;
  int sum = 0;
  hub.subscribe<int>([&](int const& x) { sum += x; });
  hub.publish(3);
  hub.publish(4);
  REQUIRE(sum == 7);
}

TEST_CASE("types do not mix") {
  TopicHub hub;
  int n_int = 0, n_str = 0;
  hub.subscribe<int>([&](int const&) { ++n_int; });
  hub.subscribe<std::string>([&](std::string const&) { ++n_str; });
  hub.publish(1);
  hub.publish(std::string{"imu"});
  REQUIRE(n_int == 1);
  REQUIRE(n_str == 1);
}
