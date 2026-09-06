#pragma once

#include <memory>
#include <utility>

class UniqueFunction {
 public:
  UniqueFunction() = default;

  template <typename F>
  UniqueFunction(F f);

  UniqueFunction(UniqueFunction&&) noexcept = default;
  UniqueFunction& operator=(UniqueFunction&&) noexcept = default;
  UniqueFunction(UniqueFunction const&) = delete;
  UniqueFunction& operator=(UniqueFunction const&) = delete;

  explicit operator bool() const;
  void operator()();

 private:
  struct Concept {
    virtual ~Concept() = default;
    virtual void invoke() = 0;
  };
  template <typename F>
  struct Model : Concept {
    explicit Model(F f) : f_(std::move(f)) {}
    void invoke() override { f_(); }
    F f_;
  };
  std::unique_ptr<Concept> impl_;
};

template <typename F>
UniqueFunction::UniqueFunction(F f) {
  (void)f;
  // TODO: impl_ = std::make_unique<Model<F>>(std::move(f));
}
