# Week 12 — Sample arena (shared-memory mock)

iceoryx2 places samples in a **segment**. You bump-allocate aligned payloads; you do not `new` per message on the hot path.

## Polymorphism this week

Allocator is a **policy of layout**, not a virtual `Message` heap. ROS 2 loaned messages sit on top of rmw loans.

## Read / watch

| Kind | Resource |
| --- | --- |
| iceoryx2 | Shared memory / zero-copy overview at [iceoryx2.io](https://iceoryx2.io/) |
| ROS 2 | [Loaned messages](https://docs.ros.org/en/rolling/How-To-Guides/Using-loaned-messages.html) |
| Paper | [Drepper — memory](https://people.freebsd.org/~lstewart/articles/cpumemory.pdf) §3–4 |
| Spec | [`std::align`](https://en.cppreference.com/w/cpp/memory/align) |

## Kata

`Arena(cap)`, `allocate(n, align)` or nullptr, `reset()`, `used()`.

```bash
./run week12
```
