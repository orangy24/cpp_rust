import {
  Callout,
  Checkbox,
  H1,
  H2,
  Link,
  Select,
  Stack,
  Stat,
  Table,
  Text,
  useCanvasState,
} from "cursor/canvas";

type Section = {
  id: string;
  title: string;
  nodes: string;
  run: string | null;
  idea: string;
};

// Groups and node names from https://roadmap.sh/cpp (official API, 2026).
const SECTIONS: Section[] = [
  {
    id: "setup",
    title: "1. Setup",
    nodes: "What is C++, Why use C++, C vs C++, Installing C++, IDEs, first program",
    run: null,
    idea: "Install a compiler and run hello world. No kata.",
  },
  {
    id: "ops",
    title: "2. Basic operations",
    nodes: "Arithmetic, logical, bitwise operators",
    run: null,
    idea: "Write a tiny file and print results. No kata yet.",
  },
  {
    id: "flow",
    title: "3. Control flow",
    nodes: "for / while / do while, if else / switch",
    run: null,
    idea: "Loops and branches. No kata yet.",
  },
  {
    id: "functions",
    title: "4. Functions",
    nodes: "Functions, how arguments are passed",
    run: "./run signatures",
    idea: "const, refs, vector by value vs view, templates as functions.",
  },
  {
    id: "types",
    title: "5. Data types",
    nodes: "Static typing",
    run: null,
    idea: "Prefer the standard types; avoid C arrays until you need them.",
  },
  {
    id: "ptrs",
    title: "6. Pointers and references",
    nodes: "References, raw pointers",
    run: "./run signatures",
    idea: "Same kata: signatures encode pointer vs ref vs value.",
  },
  {
    id: "memory",
    title: "7. Memory model",
    nodes: "Lifetime, new/delete, leaks, unique_ptr, shared_ptr, weak_ptr",
    run: "./run raii-loans",
    idea: "RAII loan: publish or drop. Rule of Zero.",
  },
  {
    id: "structure",
    title: "8. Structuring codebase",
    nodes: "Scope, namespaces, headers / .cpp",
    run: "./run abi",
    idea: "Headers vs ABI: C boundary, opaque handle.",
  },
  {
    id: "oop",
    title: "9. Classes and OOP",
    nodes: "Rule of 0/3/5, inheritance, virtual methods, vtables, dynamic polymorphism",
    run: "./run nodes",
    idea: "ISubscription* on one node.",
  },
  {
    id: "exceptions",
    title: "10. Exception handling",
    nodes: "Exceptions, exit codes",
    run: null,
    idea: "Read cppreference exceptions. No kata yet.",
  },
  {
    id: "concepts-lang",
    title: "11. Language concepts",
    nodes: "auto, static/dynamic/const/reinterpret_cast, UB, ADL",
    run: "./run views",
    idea: "string_view and parse without copies; watch for dangling views (UB).",
  },
  {
    id: "static-poly",
    title: "12. Static polymorphism",
    nodes: "Function overloading, operator overloading, lambdas",
    run: "./run static-poly",
    idea: "CRTP publisher — compile-time poly.",
  },
  {
    id: "stl",
    title: "13. Standard library + STL",
    nodes: "Iterators, iostream, algorithms, containers, date/time",
    run: "./run views",
    idea: "Prefer STL algorithms over hand-rolled loops.",
  },
  {
    id: "threads",
    title: "14. Multithreading",
    nodes: "Multithreading",
    run: "./run concurrency-queue",
    idea: "Also ./run concurrency-executor.",
  },
  {
    id: "templates",
    title: "15. Templates",
    nodes: "Variadic, specialization, type traits, SFINAE",
    run: "./run templates",
    idea: "Also ./run policies and ./run policies-serialize.",
  },
  {
    id: "idioms",
    title: "16. Idioms",
    nodes: "RAII, Pimpl, CRTP, copy-swap, erase-remove, non-copyable",
    run: "./run type-erasure",
    idea: "Type erasure + earlier RAII/CRTP katas.",
  },
  {
    id: "standards",
    title: "17. Standards",
    nodes: "C++11/14, 17, 20, 23",
    run: "./run qos",
    idea: "constexpr QoS. Stay on C++20 in this repo.",
  },
  {
    id: "tools",
    title: "18. Tools (later)",
    nodes: "GDB, compilers, CMake, vcpkg/Conan, Catch2",
    run: null,
    idea: "You already use CMake + Catch2 + sanitizers here.",
  },
];

export default function StudyTrack() {
  const [current, setCurrent] = useCanvasState("rm-section", "functions");
  const [done, setDone] = useCanvasState<Record<string, boolean>>("rm-done", {});
  const section = SECTIONS.find((s) => s.id === current) ?? SECTIONS[0];
  const nDone = SECTIONS.filter((s) => done[s.id]).length;

  return (
    <Stack gap={24}>
      <Stack gap={8}>
        <H1>C++ track — roadmap.sh</H1>
        <Text tone="secondary">
          Same groups as the official graph. Open{" "}
          <Link href="https://roadmap.sh/cpp">roadmap.sh/cpp</Link> for the
          picture. Check a row when you finished that group (read + kata if
          listed).
        </Text>
      </Stack>

      <Stat
        value={`${nDone} / ${SECTIONS.length}`}
        label="Groups marked done"
      />

      <Callout tone="info">
        Beginner Topics / Start here on the site: setup through functions. Then
        Intermediate. Tools and libraries are Optional / Learn if you want.
      </Callout>

      <H2>Groups</H2>
      <Table
        headers={["#", "Group", "Kata", "Done"]}
        rows={SECTIONS.map((s) => [
          s.title.split(".")[0],
          s.title.replace(/^\d+\.\s/, ""),
          s.run ?? "—",
          done[s.id] ? "yes" : "",
        ])}
        rowTone={SECTIONS.map((s) => (done[s.id] ? "success" : "neutral"))}
        striped
      />

      <H2>This group</H2>
      <Select
        value={current}
        onChange={setCurrent}
        options={SECTIONS.map((s) => ({ value: s.id, label: s.title }))}
      />
      <Text>
        <Text weight="semibold">{section.title}.</Text> {section.idea}
      </Text>
      <Text size="small" tone="secondary">
        Official nodes: {section.nodes}
      </Text>
      {section.run ? (
        <Text>
          Run <Text weight="semibold">{section.run}</Text>
        </Text>
      ) : (
        <Text tone="secondary">No kata in this repo yet — use the site node.</Text>
      )}
      <Checkbox
        checked={Boolean(done[section.id])}
        onChange={(v) => setDone((prev) => ({ ...prev, [section.id]: v }))}
        label="Group done"
      />
    </Stack>
  );
}
