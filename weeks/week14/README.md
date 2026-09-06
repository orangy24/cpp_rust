# Week 14 — Executor `spin`

rclcpp `spin(node)` runs waitsets and **dispatches** callbacks. iceoryx2 often: you wait on a listener, then take. The executor holds **erased** work items (week 08).

## Polymorphism this week

Compose weeks 08 + 10: a list of `void()` tasks. Design talk: why not `virtual execute()` on Node?

## Read / watch

| Kind | Resource |
| --- | --- |
| ROS 2 | [Executors](https://docs.ros.org/en/rolling/Concepts/Intermediate/About-Executors.html) |
| iceoryx2 | Wait / listener APIs |
| Prompts | Out loud: typed publisher vs erased subscription vs C rmw |

## Kata

`Executor::add(std::function<void()>)`, `spin_once()` runs all current tasks once (not forever).

```bash
./run week14
```
