#pragma once

#include <condition_variable>
#include <mutex>
#include <optional>
#include <queue>

class BlockingQueue {
 public:
  void push(int value);
  int pop();  // waits until an item exists
  std::optional<int> try_pop();

 private:
  std::mutex m_;
  std::condition_variable cv_;
  std::queue<int> q_;
};
