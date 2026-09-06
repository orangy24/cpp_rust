#pragma once

#include <cstdint>

enum class Reliability { BestEffort, Reliable };
enum class History { KeepLast, KeepAll };

constexpr bool qos_ok(Reliability r, History h, std::uint32_t depth) {
  (void)r;
  (void)h;
  (void)depth;
  // TODO
  return false;
}

constexpr std::uint32_t depth_or_one(History h, std::uint32_t depth) {
  (void)h;
  (void)depth;
  return 0;
}
