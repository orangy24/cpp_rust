# Week 03 — `constexpr` QoS

ROS 2 QoS is a bundle of enums (reliability, durability, history, depth). Illegal combos should be catchable early. iceoryx2 is stricter (often one policy: better not to look like DDS).

## Polymorphism this week

Configuration as **data**, not virtual `IQoS`. `constexpr` functions over enums.

## Read / watch

| Kind | Resource |
| --- | --- |
| ROS 2 | [QoS](https://docs.ros.org/en/rolling/Concepts/Intermediate/About-Quality-of-Service-Settings.html) |
| iceoryx2 | [QoS / service](https://iceoryx2.io/) — compare how little DDS they expose |
| Spec | [`constexpr`](https://en.cppreference.com/w/cpp/language/constexpr) |
| Talk | Ben Deane & Jason Turner, [constexpr ALL the Things](https://www.youtube.com/watch?v=PJwd4JLYJJY) (CppCon 2017) |

## Kata

`qos_ok(Reliability, History, depth)`: Keep-last requires depth ≥ 1. Keep-all ignores depth (treat any depth as ok). `depth_or_one` returns depth if keep-last else 1.

```bash
./run week03
```
