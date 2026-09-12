---
name: general-index-formatting
description: Format or revise a repository's general activity index README, including module summaries and activity entries. Use for index-specific layout and metadata; not for individual activity READMEs.
---

# General Index Formatting

Use this skill only for the repository's general activity index, normally the root `README.md`. Do not apply these layout rules to individual activity READMEs unless explicitly requested.

## Activity entries

- Keep every module entry in a continuous list, with no blank lines between consecutive activities.
- Write each activity as a checkbox item followed by exactly these indented fields:
  - `Descrição:` explains the observable problem or behavior.
  - `Domínio:` states the restrictions, invariants or essential business rules.
  - `Objetivos:` states the learning outcome, not an implementation checklist.
- Do not add `Conceitos`, `Técnicas` or `Pré-requisito` to individual entries; these belong in the module introduction when relevant.
- Preserve any existing `[GUIA]` marker when an activity title is renamed.

## Module layout

- Start an instructional module with `- Introdução` and keep its nested lists in this order when they are relevant:
  1. `Objetivos de aprendizagem:`
  2. `Conceitos:`
  3. `Técnicas de programação:`
  4. `Princípio relacionado, quando necessário:`
- List the activities immediately after the introduction, without a horizontal separator or blank line between the introduction and the first activity.
- Keep activity entries consecutive, without horizontal separators between them.
- When a comparison helps expose the progression, add one Markdown table after the last activity. Its rows must represent observable competencies or techniques and its columns the activities in the block.
- A horizontal separator may mark the end of a completed module before the next module. Preserve the existing local convention rather than adding one only for decoration.

## Verification

After changing the general index, run `tko util mdpp README.md` and `git diff --check`. Review the generated formatting to ensure the activity lists remain continuous and the separators still follow these rules.
