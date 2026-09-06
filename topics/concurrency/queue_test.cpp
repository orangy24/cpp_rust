#include "queue.hpp"

#include <catch2/catch_test_macros.hpp>
#include <thread>
#include <vector>

TEST_CASE("try_pop empty") {
  BlockingQueue q;
  REQUIRE_FALSE(q.try_pop().has_value());
}

TEST_CASE("push then try_pop") {
  BlockingQueue q;
  q.push(9);
  auto v = q.try_pop();
  REQUIRE(v.has_value());
  REQUIRE(*v == 9);
  REQUIRE_FALSE(q.try_pop().has_value());
}

TEST_CASE("pop waits for producer") {
  BlockingQueue q;
  int got = -1;
  std::thread consumer([&] { got = q.pop(); });
  q.push(42);
  consumer.join();
  REQUIRE(got == 42);
}

TEST_CASE("fifo across threads") {
  BlockingQueue q;
  std::vector<int> out;
  std::thread c([&] {
    for (int i = 0; i < 5; ++i) out.push_back(q.pop());
  });
  for (int i = 0; i < 5; ++i) q.push(i);
  c.join();
  REQUIRE(out == std::vector<int>{0, 1, 2, 3, 4});
}
