# Week 13 — Subscriber history queue

Keep-last QoS is a **bounded queue** of samples. Mutex now; lock-free later if you ever touch iceoryx internals.

## Polymorphism this week

The queue is **monomorphic** (`int` here). Heterogeneous messages belong *outside* (type erasure at subscribe). Do not make `queue<BaseMsg*>`.

## Read / watch

| Kind | Resource |
| --- | --- |
| ROS 2 | History KeepLast / KeepAll |
| Book | Williams *C++ Concurrency in Action* ch. 3–4, 6 |
| Spec | [`mutex`](https://en.cppreference.com/w/cpp/thread/mutex), [`condition_variable`](https://en.cppreference.com/w/cpp/thread/condition_variable) |

## Kata

`BlockingQueue`: `push`, `pop` (waits), `try_pop`. Two threads in tests.

```bash
./run week13
```
