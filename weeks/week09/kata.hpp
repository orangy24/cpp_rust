#pragma once

#include <any>
#include <functional>
#include <typeindex>
#include <unordered_map>
#include <vector>

class TopicHub {
 public:
  template <typename T>
  void subscribe(std::function<void(T const&)> handler) {
    (void)handler;
    // TODO: handlers_[typeid(T)].push_back erased wrapper
  }

  template <typename T>
  void publish(T const& sample) {
    (void)sample;
    // TODO: invoke handlers for typeid(T)
  }

 private:
  std::unordered_map<std::type_index, std::vector<std::function<void(std::any const&)>>>
      handlers_;
};
