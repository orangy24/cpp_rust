#include "kata.hpp"

#include <catch2/catch_test_macros.hpp>
#include <memory>

TEST_CASE("inject matches topic") {
  Node n;
  auto scan = std::make_unique<CountingSub>("/scan");
  auto imu = std::make_unique<CountingSub>("/imu");
  CountingSub* ps = scan.get();
  CountingSub* pi = imu.get();
  n.add(std::move(scan));
  n.add(std::move(imu));
  n.inject("/scan", "data");
  REQUIRE(ps->hits() == 1);
  REQUIRE(pi->hits() == 0);
  n.inject("/imu", "data");
  REQUIRE(pi->hits() == 1);
}
