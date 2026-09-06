# Polymorphism + robotics middleware

C++-first, then Rust. The spine is **which polymorphism to use**, in the setting of **ROS 2 / iceoryx2-style** nodes, topics, QoS, and loaned (zero-copy) samples — not HTTP pipelines.

| Week | Polymorphism lens | Robotics object | Run |
| --- | --- | --- | --- |
| 01 | Ownership / RAII (so later loans are safe) | Loaned sample: publish vs drop-release | `./run week01` |
| 02 | Values, views, error types | Message header + payload parse | `./run week02` |
| 03 | `constexpr` configuration | QoS validity | `./run week03` |
| 04 | Concepts (static interface) | `Message` concept | `./run week04` |
| 05 | CRTP (static poly) | `PublisherBase<Derived>` | `./run week05` |
| 06 | Policy-based design | Reliability + history as policies | `./run week06` |
| 07 | Orthogonal policies | Serialization policy + QoS | `./run week07` |
| 08 | Type erasure (dynamic, no vtable in *your* API) | Subscription callback | `./run week08` |
| 09 | Type-erased + typed topics | In-process topic hub | `./run week09` |
| 10 | Virtual vs erasure vs templates | Node with mixed subscriber types | `./run week10` |
| 11 | C ABI / rmw boundary | Opaque node handle | `./run week11` |
| 12 | Layout / allocators | Sample arena (shm mock) | `./run week12` |
| 13 | Shared-state poly | Subscriber history queue | `./run week13` |
| 14 | Executor design | `spin()` dispatching erased callbacks | `./run week14` |
| 15 | Rust ownership | Loan / publish | `cargo test --manifest-path rust/Cargo.toml week15` |
| 16 | Traits (static) | `Message` trait | `… week16` |
| 17 | `dyn Trait` (dynamic) | Type-erased subscriber | `… week17` |
| 18 | FFI | Bind the week-11 C ABI | `… week18` |
| 19 | Threads | Waitset / executor pool | `… week19` |
| 20 | API comparison | When ROS 2 vs iceoryx2 | `… week20` |

Read the week's `README.md` first. Fill TODOs until tests pass. ASan/UBSan are on for C++ Debug.

```bash
cmake --preset debug   # first time
./run week01
```
