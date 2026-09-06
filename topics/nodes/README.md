# Week 10 — Node: virtual subscriptions (runtime poly)

A node must hold **LaserScan and Imu** subscribers together. Templates cannot be the container element. Options: virtual `ISubscription`, or type erasure (week 08). This week uses a **vtable**.

## Polymorphism this week

**Runtime polymorphism** for a heterogeneous list. Cost: extra call, object layout, harder inlining. This is closer to “plugin” than to iceoryx2’s typed port.

## Read / watch

| Kind | Resource |
| --- | --- |
| Talk | Sean Parent, [Better Code: Runtime Polymorphism](https://www.youtube.com/watch?v=QGcVXgEVMJg) |
| ROS 2 | Multiple subscriptions on `Node` |
| iceoryx2 | Prefer **separate typed ports**, not one `ISubscriber*` |
| Guidelines | [C.120](https://isocpp.github.io/CppCoreGuidelines/CppCoreGuidelines#Rh-virtual) |

## Kata

`ISubscription::on_bytes` + `topic()`. `Node::add` takes `unique_ptr<ISubscription>`. `Node::inject(topic, bytes)` delivers only to matching topics.

```bash
./run week10
```
