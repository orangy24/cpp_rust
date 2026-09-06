# Week 07 — Orthogonal policies: serialize + QoS

iceoryx2 payload is a type you pick; ROS 2 usually codegen. A **Serialize** policy is independent of **Reliability**.

## Polymorphism this week

Two template parameters that do not share a base class. Virtual would force a diamond or a fat interface.

## Read / watch

| Kind | Resource |
| --- | --- |
| ROS 2 | [IDL / typesupport](https://docs.ros.org/en/rolling/Concepts/Basic/About-Interfaces.html) |
| Guidelines | [T.120 headers](https://isocpp.github.io/CppCoreGuidelines/CppCoreGuidelines#Rt-header) |
| iceoryx2 | Zero-copy: often **no** serialize step on the hot path |

## Kata

`RawFormat::render(msg)` identity. `FramedFormat::render` wraps `[msg]`. `Publisher<Rel, Fmt>::publish` stores `Fmt::render(bytes)`.

```bash
./run week07
```
