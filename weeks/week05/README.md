# Week 05 — CRTP publisher (static polymorphism)

A derived `ShmPublisher` injects `send_bytes` without a virtual call on the hot path. Same idea as iceoryx2's typed publisher wrapping a port.

## Polymorphism this week

**CRTP**: `PublisherBase<Derived>` calls `static_cast<Derived*>(this)->send_bytes(...)`. Contrast with virtual `ITransport::send`.

## Read / watch

| Kind | Resource |
| --- | --- |
| Spec | [CRTP](https://en.cppreference.com/w/cpp/language/crtp) |
| Article | [Fluent C++ CRTP](https://www.fluentcpp.com/2017/05/12/curiously-recurring-template-pattern/) |
| ROS 2 | Publisher is a template; transport is behind rmw (dynamic at the boundary) |

## Kata

`PublisherBase<D>::publish(string_view)` increments `sent` and calls `derived().send_bytes`. `LoopbackPublisher` appends to `inbox`. Separate CRTP counters if you reuse week-05 counting — here just loopback.

```bash
./run week05
```
