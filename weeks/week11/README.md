# Week 11 — rmw-style C ABI

ROS 2’s language boundary is **C** (`rmw`). iceoryx2 can FFI, but C is the stable joint. Hide the C++ node behind `NodeHandle*`.

## Polymorphism this week

**No C++ polymorphism across ABI.** Virtual tables are not portable. Type erasure / templates stop at `extern "C"`.

## Read / watch

| Kind | Resource |
| --- | --- |
| ROS 2 | [rmw](https://github.com/ros2/rmw) (skim README) |
| Spec | [`extern "C"`](https://en.cppreference.com/w/cpp/language/language_linkage), [pimpl](https://en.cppreference.com/w/cpp/language/pimpl) |
| Guidelines | C.129 Pimpl |

## Kata

`node_new` / `node_free` / `node_publish` (counts messages) / `node_count`. Tests use only C functions.

```bash
./run week11
```
