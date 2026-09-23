---
name: activity-readme
description: Create, review, or maintain a programming activity README with pedagogical progression, domain contracts, tests, diagrams, and reference implementations.
---

# Activity README

Use this skill when creating or revising an individual activity README and its directly associated code, tests, diagrams, or generated assets. It covers activities under `labs/` and similar task directories; use the separate `general-index-formatting` skill for the repository's general index README.

Reference formats when needed:

- `wiki/atividade_codigo/README.md` — activity code standard;
- `wiki/atividade_codigo/modelo.md` — Shell-based model;
- `wiki/atividade_codigo/modelo_orientada.md` — guided implementation model.

## Pedagogical scope

Assume students know variables, conditionals, loops, functions, and basic collections, but are still learning to decompose responsibilities, model state and invariants, separate domain from interface, test behavior, and justify design decisions.

Each activity should have one principal pedagogical objective and at most two directly related secondary objectives. Introduce only a manageable number of new ideas, and make their benefit visible through a concrete problem, an observable cost, a focused practice, incremental verification, and a small possible extension.

Progress through the relevant level:

1. local readability: expressive names, constants, simple flow, small cohesive operations, and removal of evident duplication;
2. state and invariants: valid state, validation by the class that owns the rule, state preservation after failure, encapsulation, and explicit commands/queries;
3. domain and interface: domain independent from terminal, files, or GUI, with a Shell that parses, invokes, and presents;
4. collaboration: cohesive classes, composition, ownership, multiplicity, lifecycle, delegation, and coordinators that orchestrate without absorbing component rules;
5. evolution and dependencies: real variation points, client-shaped interfaces, injected dependencies for tests, named failures, and test-guided refactoring.

Do not introduce a pattern, abstraction, or principle before the activity exposes the problem it solves. Do not create classes merely to increase the file count, add imagined extensibility, or move rules into the Shell to satisfy an incidental test.

## Activity contract

State the observable behavior before implementation details. Every activity should make explicit:

- behavior and output that can be observed;
- prior knowledge required;
- the principal learning objective;
- domain restrictions and invariants;
- completion and verification criteria;
- a plausible future change that can test the model's quality.

Keep the title and index name focused on the principal objective, with at most one directly related secondary objective. Do not present implementation details, class counts, return formats, or consequences as separate objectives. Preserve an existing `[GUIA]` marker when renaming an activity.

The executable contract is in English: identifiers, Shell commands, observable messages, enums, constants, and values used by code or tests. Pedagogical explanations, narrative rules, guides, reflections, and design justifications remain in Portuguese. Kotlin is the single reference language for activity descriptions and executable solutions. Use Kotlin identifiers, signatures, types, and collection names in READMEs and diagrams; do not mix in TypeScript or Python notation. Keep messages, formats, scores, and accents identical across rules, examples, tests, and code. Avoid implicit requirements.

## README structure

Use the activity's applicable sections in this order:

- title;
- `toc-table`;
- cover;
- `Intro`;
- `Regras`;
- `Diagrama`;
- `Guide`;
- `Shell` when the activity is evaluated through commands;
- `Draft` when a starter or skeleton is maintained by `tko`.

Describe observable behavior first, then implementation details. `eval=test` activities must include a Shell with `#TEST_CASE` blocks, commands beginning with `$`, and `$end`. `eval=self` activities need no Shell, but must describe methods, returns, limits, examples, and an objective verification route.

## Domain and interface

- Domain classes own state and domain rules; they do not read input or print output.
- The Shell parses commands, converts arguments, invokes the domain, and presents results.
- The class that knows a restriction guarantees it.
- Queries do not mutate state unless that is explicit in the model.
- Choose one coherent failure strategy per activity: values, result objects, booleans, exceptions, or enums. Do not scatter messages or mix strategies without a domain reason.
- Keep global state and hidden dependencies out of the model.

## Modeling decisions

Prefer KISS, DRY, and YAGNI as concrete decisions, not as decorative labels. Use SRP, OCP, LSP, ISP, or DIP only when the corresponding problem is observable and the activity demonstrates the decision.

When an activity divides classes, its Guide and diagram must explain:

- the problem before the division;
- each component's responsibility;
- the state, invariants, and behavior owned by each class;
- the relation and multiplicities between components;
- which objects have independent lifecycles;
- how the division improves maintenance, extension, or tests;
- the additional cost introduced by the division.

Avoid God Objects, public state that breaks invariants, automatic getters/setters without domain purpose, ambiguous booleans, magic values, inheritance used only for reuse, single-implementation abstractions without a real variation point, comments that translate code, premature optimization, and unrelated refactoring.

## Guide and implementation

The Guide must break implementation into small executable increments. Start with the minimum model that represents the domain, state what works at the end of each step, and connect each step to a responsibility or invariant. Include essential examples without mechanically giving the complete solution unless that is the activity format. End with verification and, when appropriate, a small extension.

Explain decisions before naming patterns. Ask reflection questions about alternatives, consequences, costs, and what future change would become easier. Do not give steps such as “create three classes” without explaining the responsibility or lifecycle that justifies the division.

## Tests as a learning instrument

Tests should reinforce the contract and model rather than accidental internals. Include, as appropriate:

- main path and boundaries;
- invalid operations;
- state preserved after failure;
- sequences of operations;
- collaboration between components;
- domain independence from the Shell.

Do not depend on private attributes, internal execution order, or an unrequired decomposition. If structure itself is being taught, state explicitly what is inspected and why.

When reviewing a refactoring, record the smell or risk, the change, unchanged behavior, the new change made easier, and remaining costs. Distinguish a functional solution from one appropriate to the current context and one prepared for a stated future requirement.

## Diagrams

Every activity with a diagram includes an inline Mermaid `classDiagram` in its README. Use `labs/motoca/README.md` as the formatting model: initialize the diagram with a monospace font, set its direction explicitly, and use Kotlin types and notation:

- `Int`, `Double`, `Boolean`, `String`, and `Unit` for common types;
- `List~T~`, `MutableList~T~`, and `Map~K, V~` for collections in Mermaid source;
- `T?` for nullable values;
- UML multiplicities such as `0..1` and `0..*`;
- UML visibility modifiers `+`, `-`, and `#`, with `val` or `var` when mutability is relevant.
- A static member ends with `$`, for example `+DEAD_STAGE : Int$`.

Format properties and parameters as `name : Type`, with spaces around the colon. Format methods without a colon after the closing parenthesis, for example `+drive(minutes : Int) DriveResult`; show the return type after the signature. Use Mermaid's `~` generic delimiters for collection types. Represent the entry point as `main() Unit`, without incidental language arguments or parsing helpers. The diagram communicates relevant responsibilities and relationships, not every implementation detail.

When updating an activity that still has the legacy `assets/diagrama.png` or `assets/diagrama.puml`, remove those obsolete artifacts after migrating the diagram to Mermaid. Do not create new PNG, PUML, or PlantUML diagram artifacts for activity READMEs.

Before finalizing an activity, propose improvements to the names of methods, attributes, variables, and classes. Prefer names that reveal domain intent, distinguish state from operation parameters, avoid unexplained abbreviations, and follow the target language's conventions; apply the improvements only when they preserve or deliberately update the documented contract.

## Reference implementations

Each activity's canonical executable solution is Kotlin, stored under `src/kt` and run with `tko run . -l kt`. Keep the solution and any code examples in the README in Kotlin. Use Kotlin's nullability, collection, visibility, and mutability features directly instead of translating another language's model mechanically. Keep Shell parsing and output in the entry point; domain classes should not read input or print messages.

Preserve the activity's command contract and exit behavior when implementing or reviewing its Kotlin solution. Prefer clear, idiomatic Kotlin and explicit types on public APIs and state whose type is not obvious; local types may be inferred when that improves readability.

When changing `eval=test`, preserve the Shell contract and change tests only when the domain rule changes. When changing `eval=self`, keep examples and verification aligned with the conceptual model without turning the tutorial into a rigid output contract.

## Review checklist

Before completing an activity README, verify:

1. the principal pedagogical objective matches the prerequisites and level;
2. the problem makes the value of the practice visible;
3. observable behavior is separate from implementation detail;
4. classes own the right rules, state, invariants, and lifecycles;
5. the Shell contains no domain logic;
6. the division improves cohesion, coupling, maintenance, extension, or tests;
7. names reveal domain intent and methods have one conceptual operation; naming improvements were considered and proposed where useful;
8. dependencies are explicit and necessary;
9. tests cover behavior, boundaries, failures, state after failures, and collaboration as relevant;
10. the diagram matches the taught model;
11. the Guide explains decisions and consequences accessibly;
12. technical terms appear only when demonstrated by a decision, comparison, test, or refactoring;
13. the solution stays simple for the intended level;
14. a small future change can exercise the structure.

## Verification before delivery

- Read the README, code, tests, and diagram before changing an existing activity.
- Check consistency among rules, examples, diagram, tests, and implementations.
- Validate the inline Mermaid diagram and confirm that obsolete PNG/PUML artifacts were removed when the activity was updated.
- Compile and run the Kotlin solution with `tko run . -l kt`.
- For `eval=test`, run success, failure, boundary, sequence, and state-preservation scenarios.
- For `eval=self`, validate examples and the verification route.
- Run `tko tool mdpp README.md` when the README changes.
- Do not run `tko index` against an activity README; build the general index only from the repository root using its central `README.md`.
- Run `git diff --check`.
- Use `make all` only when index or generated artifacts need updating, then review the complete diff.
- Run `tko run <codigo> README.md` when checking consistency between code and README tests.

Preserve pre-existing worktree changes and inspect generated files before including them. If a change would redefine the contract, pedagogical progression, or expected student level, present alternatives instead of assuming a choice.
