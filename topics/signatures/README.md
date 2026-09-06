# Signatures — `const`, refs, `vector`, templates

This is the C++ you actually write every day: **what the parameter type promises**. Robotics APIs fail here first (`publish` copies a 2 MB scan because someone took `LaserScan` by value).

## In this topic

- `T` vs `T const&` vs `T&&` vs `std::unique_ptr<T>`
- `std::vector<T>` by value (steal / transfer) vs `const&` (read) vs `&` (mutate)
- `std::string_view` for read-only text (see also `topics/views`)
- Function templates that do not copy unless they must

## CppCon

| Talk | Why |
| --- | --- |
| Kate Gregory, [10 Core Guidelines You Need to Start Using Now](https://www.youtube.com/watch?v=XkD4zMCpHYA) (CppCon 2017) | `const`, ownership in signatures |
| Arthur O'Dwyer, [Back to Basics: Value Semantics](https://www.youtube.com/watch?v=WRLTlx2rAW0) (CppCon 2022, if you prefer 2018: search “Value Semantics O’Dwyer”) | Values vs identities |
| Klaus Iglberger, [Back to Basics: Move Semantics](https://www.youtube.com/watch?v=pIzaZbKUw2s) (CppCon 2019) | When `T&&` is a contract |
| Scott Meyers, [Type Deduction and Why You Care](https://www.youtube.com/watch?v=wQxj20X-tIU) (CppCon 2014) | Why `template <class T> void f(T&&)` is not “an rvalue ref” |

## Kata

Implement `read_sum`, `append_copy`, `take_and_sum` (by-value so the caller can `std::move`), and `first_or` (function template).

```bash
./run signatures
```
