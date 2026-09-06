# Week 06 — QoS as policies (not virtual IQoS)

ROS 2 QoS is a struct. Policy-based design makes **invalid combinations a type error** (or at least a template choice): `Publisher<Reliable, KeepLast>`.

## Polymorphism this week

**Policies** = static polymorphism of *behavior dimensions*. Contrast: a virtual `set_reliability()` on a base publisher.

## Read / watch

| Kind | Resource |
| --- | --- |
| ROS 2 | [QoS](https://docs.ros.org/en/rolling/Concepts/Intermediate/About-Quality-of-Service-Settings.html) |
| Book | Alexandrescu *Modern C++ Design* ch. 1 |
| Book | Iglberger *C++ Software Design* — strategy vs policy |
| iceoryx2 | Far fewer knobs — notice the design trade |

## Kata

`Reliable` / `BestEffort` expose `static constexpr bool kReliable`. `KeepLast<N>` exposes `kDepth`. `Publisher<Rel, Hist>::qos_reliable()` / `qos_depth()` read those. `log` analogue: `publish` appends to a vector (history not enforced yet).

```bash
./run week06
```
