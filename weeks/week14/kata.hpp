#pragma once

#include <functional>
#include <vector>

class Executor {
 public:
  void add(std::function<void()> job);
  void spin_once();
  std::size_t size() const;

 private:
  std::vector<std::function<void()>> jobs_;
};
