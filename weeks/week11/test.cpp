#include "kata.hpp"

#include <catch2/catch_test_macros.hpp>

TEST_CASE("C node counts publishes") {
  NodeHandle* n = node_new();
  REQUIRE(n != nullptr);
  node_publish(n, "a");
  node_publish(n, "b");
  REQUIRE(node_count(n) == 2);
  node_free(n);
}
