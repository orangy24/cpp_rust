# Week 08 — Type-erased subscription callback

rclcpp stores subscriptions of **different message types** on one node. The node cannot be `Node<LaserScan>` only. Type erasure (or a virtual `ISubscription`) is the dynamic half.

## Polymorphism this week

**Type erasure**: user API is `void(std::string_view)` or any move-only callable. No copy (`std::function` copies). Same pattern as Sean Parent's `task`.

## Read / watch

| Kind | Resource |
| --- | --- |
| Talk | Sean Parent, [Inheritance Is The Base Class of Evil](https://www.youtube.com/watch?v=bIhUE5uUFOA) |
| Talk | Klaus Iglberger, [Type Erasure](https://www.youtube.com/watch?v=4eeESJQk-mw) |
| ROS 2 | Node holds a list of subscriptions — inspect `rclcpp::Node` mentally |
| Book | *C++ Software Design* — type erasure |

## Kata

`UniqueFunction` stores any `void()` invocable, move-only. (Message bytes can be captured in the lambda.)

```bash
./run week08
```
