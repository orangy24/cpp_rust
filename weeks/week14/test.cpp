#include "kata.hpp"

#include <catch2/catch_test_macros.hpp>

TEST_CASE("spin_once runs jobs") {
  Executor ex;
  int a = 0, b = 0;
  ex.add([&] { a = 1; });
  ex.add([&] { b = 2; });
  REQUIRE(ex.size() == 2);
  ex.spin_once();
  REQUIRE(a == 1);
  REQUIRE(b == 2);
}
