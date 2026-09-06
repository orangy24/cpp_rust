// Your Catch2 cases. Run: ./run practice
#include <catch2/catch_test_macros.hpp>
#include <vector>

// Replace this with a real question from QUESTIONS.md.
int sum(std::vector<int> const& xs) {
  int n = 0;
  for (int x : xs) n += x;
  return n;
}

TEST_CASE("sandbox: sum") {
  REQUIRE(sum({1, 2, 3}) == 6);
}
