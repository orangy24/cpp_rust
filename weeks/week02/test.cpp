#include "kata.hpp"

#include <catch2/catch_test_macros.hpp>

TEST_CASE("parse_stamp") {
  auto v = parse_stamp("42");
  REQUIRE(v.has_value());
  REQUIRE(v.value() == 42);
  REQUIRE_FALSE(parse_stamp("").has_value());
  REQUIRE(parse_stamp("").error() == ParseErr::Empty);
  REQUIRE(parse_stamp("12x").error() == ParseErr::Invalid);
}

TEST_CASE("split_fields aliases input") {
  std::string owned = "stamp|base_link|scan";
  auto parts = split_fields(owned);
  REQUIRE(parts.size() == 3);
  REQUIRE(parts[0] == "stamp");
  REQUIRE(parts[1] == "base_link");
  REQUIRE(parts[2] == "scan");
  REQUIRE(parts[0].data() == owned.data());
}

TEST_CASE("split_fields empty") { REQUIRE(split_fields("").empty()); }
