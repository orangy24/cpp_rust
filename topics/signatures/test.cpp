#include "kata.hpp"

#include <catch2/catch_test_macros.hpp>
#include <utility>
#include <vector>

TEST_CASE("read_sum does not need a copy") {
  std::vector<int> const xs{1, 2, 3};
  REQUIRE(read_sum(xs) == 6);
}

TEST_CASE("append_copy mutates") {
  std::vector<int> xs{1};
  append_copy(xs, 9);
  REQUIRE(xs == std::vector<int>{1, 9});
}

TEST_CASE("take_and_sum accepts moved vector") {
  std::vector<int> xs{4, 5};
  REQUIRE(take_and_sum(std::move(xs)) == 9);
}

TEST_CASE("first_or template") {
  REQUIRE(first_or(std::vector<int>{7, 8}, 0) == 7);
  REQUIRE(first_or(std::vector<int>{}, 3) == 3);
}
