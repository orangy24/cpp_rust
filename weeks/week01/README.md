# Week 01 — RAII loan (iceoryx-style)

iceoryx2 loans you a sample in shared memory. You either **publish** it or **drop** it (release). Copying a loan would double-free. That is move-only RAII, not a file wrapper.

## Polymorphism this week

None yet. You are locking down ownership so later publishers can return `LoanedSample<T>` instead of copying payloads.

## Read / watch

| Kind | Resource |
| --- | --- |
| iceoryx2 | [LoanedSample](https://docs.rs/iceoryx2/latest/iceoryx2/) — skim publisher loan docs |
| iceoryx2 book | [iceoryx2 documentation](https://iceoryx2.io/) |
| ROS 2 | [Loaned messages](https://docs.ros.org/en/rolling/How-To-Guides/Using-loaned-messages.html) |
| C++ | [Value categories](https://en.cppreference.com/w/cpp/language/value_category), [move ctor](https://en.cppreference.com/w/cpp/language/move_constructor) |
| Guidelines | [R.1 / R.3 / C.21](https://isocpp.github.io/CppCoreGuidelines/CppCoreGuidelines#S-resource) |
| Talk | Klaus Iglberger, [Back to Basics: Move Semantics](https://www.youtube.com/watch?v=pIzaZbKUw2s) |

## Kata

`SamplePool` holds one reusable `std::string` slot. `loan()` returns a move-only `SampleLoan`. `payload()` writes the slot. `publish()` sends a copy into `Pool::last_published` and returns the slot. Destructor without publish must return the slot (pool can loan again). After move, the source is empty (`operator bool` false).

```bash
./run week01
```
