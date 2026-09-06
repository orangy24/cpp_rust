# Week 02 — Message values (`string_view`, parse)

ROS 2 messages are generated structs. Here you parse a tiny wire format: `stamp|frame|payload` without copying until you store.

## Polymorphism this week

Prefer **values + views** over a class hierarchy of messages. Inheritance is the wrong default for CDR-like blobs.

## Read / watch

| Kind | Resource |
| --- | --- |
| ROS 2 | [Interfaces](https://docs.ros.org/en/rolling/Concepts/Basic/About-Interfaces.html) |
| Spec | [`string_view`](https://en.cppreference.com/w/cpp/string/basic_string_view), [`from_chars`](https://en.cppreference.com/w/cpp/utility/from_chars) |
| iceoryx2 | Payload is a **type you choose**, not a base `Message*` |

## Kata

`parse_stamp` / `split_fields` on `'|'` (same rules as before: empty → Empty; leftover digits → Invalid; split aliases the input).

```bash
./run week02
```
