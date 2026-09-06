# cpp-rust-kata

Practice repo aligned with the official **[C++ Developer Roadmap](https://roadmap.sh/cpp)** (roadmap.sh, 2026).

How to walk it: open that graph, then this table in [`ROADMAP.md`](ROADMAP.md). Interactive checklist: [`study/track.html`](study/track.html).

```bash
cmake --preset debug          # first time (Catch2 + ASan)
./run signatures              # first kata = Functions / pointers
```

Each `./run <topic>` builds a Catch2 binary. Stubs compile; tests fail until you fill TODOs in `topics/<name>/`.

## Roadmap order → commands

1. Setup, operators, control flow — no kata (do on the site).
2. **Functions / pointers** — `./run signatures`
3. **Memory / RAII** — `./run raii-loans`
4. **Headers / ABI** — `./run abi`
5. **OOP / virtual** — `./run nodes`
6. **Language / views** — `./run views`
7. **Static poly** — `./run static-poly`
8. **STL** — `./run views`
9. **Threads** — `./run concurrency-queue` then `concurrency-executor`
10. **Templates** — `./run templates` then `policies` / `policies-serialize`
11. **Idioms** — `./run type-erasure`
12. **Standards (C++20)** — `./run qos`
13. Tools — already CMake + Catch2 here. Libraries on the roadmap are optional.

Your own questions and scratch code live in [`practice/`](practice/) (`QUESTIONS.md`, `tests.cpp`, `sandbox.cpp`). Course katas stay in `topics/`.

```bash
./run practice
./run practice-sandbox
./run rust
```

Cursor canvas (after `./scripts/link-canvas.sh`): [study-track](/home/david/.cursor/projects/home-david-cpp-rust-kata/canvases/study-track.canvas.tsx).
