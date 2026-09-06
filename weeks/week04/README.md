# Week 04 — `Message` concept (static polymorphism)

rclcpp is heavily templated: `Publisher<T>`, `Subscription<T>`. The constraint is “T is a message,” not “T extends BaseMsg”.

## Polymorphism this week

**Concepts / templates** = static polymorphism. Each `T` gets its own code. No vtable. Cost: compile time, code size.

## Read / watch

| Kind | Resource |
| --- | --- |
| Spec | [Constraints](https://en.cppreference.com/w/cpp/language/constraints) |
| ROS 2 | [`Publisher<MessageT>`](https://docs.ros2.org/latest/api/rclcpp/classrclcpp_1_1Publisher.html) |
| Book | *C++ Templates* (Vandevoorde) ch. 1–3 |
| Talk | Klaus Iglberger, [Breaking Dependencies](https://www.youtube.com/watch?v=dXWRtuGl4MU) |

## Kata

`concept Message` requires `T::TYPE_NAME` convertible to `string_view` and `.payload()` → `string_view`. `topic_type(msg)` returns `TYPE_NAME`.

```bash
./run week04
```
