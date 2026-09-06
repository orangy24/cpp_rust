#include "kata.hpp"

#include <catch2/catch_test_macros.hpp>
#include <memory>
#include <utility>

TEST_CASE("empty is false") {
  UniqueFunction f;
  REQUIRE_FALSE(f);
}

TEST_CASE("lambda runs") {
  int n = 0;
  UniqueFunction f([&] { n = 7; });
  REQUIRE(f);
  f();
  REQUIRE(n == 7);
}

TEST_CASE("move-only callable") {
  auto p = std::make_unique<int>(3);
  UniqueFunction f([p = std::move(p)] { /* owns p */ });
  UniqueFunction g = std::move(f);
  REQUIRE(g);
  REQUIRE_FALSE(f);
  g();
}
