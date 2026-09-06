#pragma once

#include <optional>
#include <string>
#include <string_view>

class SampleLoan;

class SamplePool {
 public:
  SampleLoan loan();
  std::optional<std::string> const& last_published() const { return last_; }

 private:
  friend class SampleLoan;
  bool in_use_ = false;
  std::string slot_;
  std::optional<std::string> last_;
  void release();
  void publish_from(std::string_view payload);
};

class SampleLoan {
 public:
  SampleLoan() = default;
  ~SampleLoan();
  SampleLoan(SampleLoan const&) = delete;
  SampleLoan& operator=(SampleLoan const&) = delete;
  SampleLoan(SampleLoan&& other) noexcept;
  SampleLoan& operator=(SampleLoan&& other) noexcept;

  explicit operator bool() const;
  std::string& payload();
  void publish();

 private:
  friend class SamplePool;
  explicit SampleLoan(SamplePool* pool);
  SamplePool* pool_ = nullptr;
};
