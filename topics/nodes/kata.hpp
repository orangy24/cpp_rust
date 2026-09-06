#pragma once

#include <memory>
#include <string>
#include <string_view>
#include <vector>

class ISubscription {
 public:
  virtual ~ISubscription() = default;
  virtual std::string_view topic() const = 0;
  virtual void on_bytes(std::string_view bytes) = 0;
};

class CountingSub : public ISubscription {
 public:
  explicit CountingSub(std::string topic);
  std::string_view topic() const override;
  void on_bytes(std::string_view bytes) override;
  int hits() const;

 private:
  std::string topic_;
  int hits_ = 0;
};

class Node {
 public:
  void add(std::unique_ptr<ISubscription> sub);
  void inject(std::string_view topic, std::string_view bytes);

 private:
  std::vector<std::unique_ptr<ISubscription>> subs_;
};
