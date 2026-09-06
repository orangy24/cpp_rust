# Topic katas — polymorphism + robotics middleware

No week numbers. Pick a **section**, watch the CppCon talks in its README, implement until Catch2 is green.

```bash
cmake --preset debug    # first time
./run signatures
./run rust
```

## Sections (suggested order)

| Topic | What you practice | Run |
| --- | --- | --- |
| [signatures](topics/signatures/README.md) | `const`, refs, `vector`, function templates | `./run signatures` |
| [raii-loans](topics/raii-loans/README.md) | Move-only loaned sample (iceoryx2 / ROS 2 loans) | `./run raii-loans` |
| [views](topics/views/README.md) | `string_view`, parse, no needless copies | `./run views` |
| [qos](topics/qos/README.md) | `constexpr` QoS validity | `./run qos` |
| [templates](topics/templates/README.md) | `Message` concept — static interface | `./run templates` |
| [static-poly](topics/static-poly/README.md) | CRTP publisher | `./run static-poly` |
| [policies](topics/policies/README.md) | QoS as types (+ [serialize](topics/policies/SERIALIZE.md)) | `./run policies` / `policies-serialize` |
| [type-erasure](topics/type-erasure/README.md) | Move-only subscription callback | `./run type-erasure` |
| [pubsub](topics/pubsub/README.md) | In-process topic hub | `./run pubsub` |
| [nodes](topics/nodes/README.md) | Virtual `ISubscription` on one node | `./run nodes` |
| [abi](topics/abi/README.md) | rmw-shaped C API | `./run abi` |
| [memory](topics/memory/README.md) | Sample arena (shm mock) | `./run memory` |
| [concurrency](topics/concurrency/README.md) | History queue + executor `spin_once` | `./run concurrency-queue` / `concurrency-executor` |

Rust lives under `rust/src/` (`week15`… still mapped in `rust/README.md`). Same ideas: loans, `Message` trait, `dyn Subscription`, FFI, threads.

## Why these sections (not “weeks”)

1. **Signatures** — every robotics API is an ownership sentence.
2. **RAII / loans** — zero-copy publish vs drop.
3. **Views** — payloads without copies.
4. **QoS** — configuration as data.
5. **Templates / static poly / policies** — `Publisher<T>` and orthogonal knobs.
6. **Type erasure / pubsub / nodes** — one process, many message types.
7. **ABI** — languages meet in C, not in vtables.
8. **Memory / concurrency** — segments, history, executors.

CppCon talks are in each topic README. Open the topic-map canvas beside chat for the catalog.
