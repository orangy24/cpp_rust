# Concurrency — subscriber history + executor

Keep-last QoS is a **queue**. `spin` is a list of erased callbacks. Heterogeneous messages stay *outside* the queue (do not `queue<BaseMsg*>`).

## Run

```bash
./run concurrency-queue
./run concurrency-executor
```

## CppCon

| Talk | Why |
| --- | --- |
| Fedor Pikus, [C++ atomics, from basic to advanced](https://www.youtube.com/watch?v=ZQFzMfHIxng) (CppCon 2017) | What `memory_order` actually is |
| Fedor Pikus, [The speed of concurrency](https://www.youtube.com/watch?v=9hJkWwHDDxs) (CppCon 2016) | Locks vs lock-free (do mutex first) |
| Herb Sutter, [atomic<> Weapons](https://www.youtube.com/watch?v=A8eCGOqgvH4) (C++ and Beyond / CppCon era) | Happens-before |
| Tony Van Eerd, [Thread Sanitizer is not a Toy](https://www.youtube.com/watch?v=k-Aiyx95ULQ) (search if ID drifts) | How you’ll debug this |

## Also

ROS 2 [Executors](https://docs.ros.org/en/rolling/Concepts/Intermediate/About-Executors.html). Williams *C++ Concurrency in Action* ch. 3–4, 6.
