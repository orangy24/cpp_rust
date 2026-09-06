# Study track = [roadmap.sh/cpp](https://roadmap.sh/cpp)

Source: official C++ Developer Roadmap (2026). We follow their groups, not weeks and not a robotics-only path.

| Roadmap group | Official nodes | Kata in this repo |
| --- | --- | --- |
| Setup | What is C++, Why, C vs C++, install, IDE, first program | none — do on your machine |
| Basic operations | arithmetic / logical / bitwise | none |
| Control flow | for/while, if/switch | none |
| Functions | functions | `./run signatures` |
| Data types | static typing | none |
| Pointers & references | references, raw pointers | `./run signatures` |
| Memory | lifetime, new/delete, leaks, `unique_ptr` / `shared_ptr` / `weak_ptr` | `./run raii-loans` |
| Structure | scope, namespaces, headers | `./run abi` (C ABI / pimpl-shaped) |
| Classes / OOP | rule of 0/3/5, inheritance, virtual, vtable, dynamic poly | `./run nodes` |
| Exceptions | exceptions, exit codes | none |
| Language concepts | `auto`, casts, UB, ADL | `./run views` (views / no extra copies) |
| Static polymorphism | overload, operators, lambdas | `./run static-poly` |
| STL | iterators, iostream, algorithms, containers, date/time | `./run views` |
| Multithreading | threads | `./run concurrency-queue` / `concurrency-executor` |
| Templates | specialization, SFINAE, type traits, variadic | `./run templates` `./run policies` |
| Idioms | RAII, Pimpl, CRTP, copy-swap, erase-remove | `./run raii-loans` `./run type-erasure` |
| Standards | C++11/14/17/20/23 | `./run qos` (constexpr) |
| Tools (later) | GDB, compilers, CMake, vcpkg/Conan, Catch2 | this repo already uses CMake + Catch2 |
| Optional libraries | Boost, gtest, Qt, … | skip until you need them |

Interactive: [`study/track.html`](study/track.html) or the Cursor canvas after `./scripts/link-canvas.sh`.

Open the graph anytime: https://roadmap.sh/cpp
