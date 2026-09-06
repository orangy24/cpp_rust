#include "kata.hpp"

#include <catch2/catch_test_macros.hpp>
#include <type_traits>
#include <utility>

TEST_CASE("SampleLoan is move-only") {
  STATIC_REQUIRE(!std::is_copy_constructible_v<SampleLoan>);
  STATIC_REQUIRE(std::is_move_constructible_v<SampleLoan>);
}

TEST_CASE("publish delivers payload") {
  SamplePool pool;
  {
    auto loan = pool.loan();
    REQUIRE(loan);
    loan.payload() = "scan";
    loan.publish();
    REQUIRE_FALSE(loan);
  }
  REQUIRE(pool.last_published() == "scan");
}

TEST_CASE("drop without publish frees the slot") {
  SamplePool pool;
  {
    auto loan = pool.loan();
    loan.payload() = "dropped";
  }
  REQUIRE_FALSE(pool.last_published().has_value());
  auto again = pool.loan();
  REQUIRE(again);
  again.payload() = "ok";
  again.publish();
  REQUIRE(pool.last_published() == "ok");
}

TEST_CASE("move transfers the loan") {
  SamplePool pool;
  auto a = pool.loan();
  a.payload() = "x";
  auto b = std::move(a);
  REQUIRE_FALSE(a);
  REQUIRE(b);
  b.publish();
  REQUIRE(pool.last_published() == "x");
}
