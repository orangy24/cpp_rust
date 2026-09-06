# Week 09 — In-process topic hub

A toy **ROS graph** in one process: publishers and subscribers meet by **topic name**. Types are isolated (int vs string) like two message types.

## Polymorphism this week

Hub is **not** a template. Internally: `type_index` + type-erased handlers. Typed `subscribe<T>` / `publish<T>` at the edge.

## Read / watch

| Kind | Resource |
| --- | --- |
| ROS 2 | [Topics](https://docs.ros.org/en/rolling/Concepts/Basic/About-Topics.html) |
| iceoryx2 | Service name + event/publish-subscribe ports |
| Spec | [`type_index`](https://en.cppreference.com/w/cpp/types/type_index), [`any`](https://en.cppreference.com/w/cpp/utility/any) |

## Kata

Ignore topic string for matching in v1 if you want — tests use type isolation. Optional: also key by topic name; tests publish `int`/`string` only.

```bash
./run week09
```
