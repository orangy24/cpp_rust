#include "kata.hpp"

#include <catch2/catch_test_macros.hpp>

TEST_CASE("RawFormat") {
  Publisher<Reliable, RawFormat> pub;
  pub.publish("scan");
  REQUIRE(pub.history() == std::vector<std::string>{"scan"});
}

TEST_CASE("FramedFormat") {
  Publisher<Reliable, FramedFormat> pub;
  pub.publish("scan");
  REQUIRE(pub.history() == std::vector<std::string>{"[scan]"});
}
