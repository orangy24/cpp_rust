#include "kata.hpp"

#include <catch2/catch_test_macros.hpp>
#include <cstdint>

TEST_CASE("allocate then used grows") {
  Arena a(64);
  void* p = a.allocate(8, 8);
  REQUIRE(p != nullptr);
  REQUIRE(a.used() >= 8);
}

TEST_CASE("alignment") {
  Arena a(64);
  (void)a.allocate(1, 1);
  void* p = a.allocate(8, 8);
  REQUIRE(p != nullptr);
  REQUIRE(reinterpret_cast<std::uintptr_t>(p) % 8 == 0);
}

TEST_CASE("oom returns nullptr") {
  Arena a(16);
  REQUIRE(a.allocate(32, 1) == nullptr);
}

TEST_CASE("reset rewinds") {
  Arena a(32);
  REQUIRE(a.allocate(16, 1) != nullptr);
  a.reset();
  REQUIRE(a.used() == 0);
  REQUIRE(a.allocate(16, 1) != nullptr);
}
