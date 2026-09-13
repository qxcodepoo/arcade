#!/usr/bin/env python3
"""Synchronize index entry content with linked README YAML front matter."""

from __future__ import annotations

import argparse
import re
from pathlib import Path
from typing import Any

import yaml  # type: ignore[import-untyped]


ROOT: Path = Path(__file__).resolve().parent
INDEX: Path = ROOT / "README.md"
ENTRY_RE: re.Pattern[str] = re.compile(r"^(\s*)- \[ \].*\(([^)]+/README\.md)\)")
KEY_ALIASES: dict[str, tuple[str, ...]] = {
    "description": ("description", "Descrição"),
    "domain": ("domain", "Domínio"),
    "objectives": ("objectives", "Objetivos", "Objetivo"),
}
INDEX_LABELS: dict[str, str] = {
    "description": "Descrição",
    "domain": "Domínio",
    "objectives": "Objetivos",
}


class LiteralString(str):
    """A string represented with YAML's literal block style."""


def represent_literal_string(dumper: yaml.SafeDumper, value: LiteralString) -> yaml.Node:
    """Keep Markdown readable in the front matter."""
    return dumper.represent_scalar("tag:yaml.org,2002:str", value, style="|")


yaml.SafeDumper.add_representer(LiteralString, represent_literal_string)


def entry_starts(lines: list[str]) -> list[tuple[int, int, Path]]:
    """Return each linked README entry with its indentation level."""
    entries: list[tuple[int, int, Path]] = []
    for line_number, line in enumerate(lines):
        match: re.Match[str] | None = ENTRY_RE.match(line.rstrip("\n"))
        if match is None:
            continue
        indent: int = len(match.group(1))
        entries.append((line_number, indent, ROOT / match.group(2)))
    return entries


def child_end(lines: list[str], start: int, entry_indent: int) -> int:
    """Return the first line that does not belong to an entry's child block."""
    position: int = start + 1
    last_content: int = position
    while position < len(lines):
        line: str = lines[position]
        if not line.strip():
            position += 1
            continue
        indentation: int = len(line) - len(line.lstrip(" "))
        if indentation <= entry_indent:
            break
        last_content = position + 1
        position += 1
    return last_content


def front_matter(text: str) -> tuple[dict[str, Any], str]:
    """Return front matter data and the document body."""
    lines: list[str] = text.splitlines(keepends=True)
    if not lines or lines[0].strip() != "---":
        return {}, text
    closing: int | None = next(
        (index for index, line in enumerate(lines[1:], start=1) if line.strip() == "---"),
        None,
    )
    if closing is None:
        return {}, text
    raw: str = "".join(lines[1:closing])
    loaded: Any = yaml.safe_load(raw) if raw.strip() else {}
    data: dict[str, Any] = loaded if isinstance(loaded, dict) else {}
    body: str = "".join(lines[closing + 1 :])
    return data, body


def legacy_metadata_from_yaml(data: dict[str, Any]) -> dict[str, str]:
    """Read the metadata format used before index_content."""
    result: dict[str, str] = {}
    for canonical, aliases in KEY_ALIASES.items():
        for alias in aliases:
            value: Any = data.get(alias)
            if isinstance(value, str):
                result[canonical] = value
                break
    return result


def write_front_matter(path: Path, data: dict[str, Any]) -> None:
    """Write front matter data while preserving the README body."""
    text: str = path.read_text(encoding="utf-8")
    _existing, body = front_matter(text)
    header: str = yaml.safe_dump(
        data,
        allow_unicode=True,
        default_flow_style=False,
        sort_keys=False,
    )
    path.write_text(f"---\n{header}---\n{body}", encoding="utf-8")


def save(index_text: str) -> tuple[str, int]:
    """Store each linked entry's complete child Markdown as index_content."""
    lines: list[str] = index_text.splitlines(keepends=True)
    changed: int = 0
    for start, indent, path in reversed(entry_starts(lines)):
        end: int = child_end(lines, start, indent)
        content: str = "".join(lines[start + 1 : end])
        if not content or not path.is_file():
            continue

        data: dict[str, Any]
        _body: str
        data, _body = front_matter(path.read_text(encoding="utf-8"))
        for aliases in KEY_ALIASES.values():
            for key in aliases:
                data.pop(key, None)
        data["index_content"] = LiteralString(content)
        write_front_matter(path, data)
        lines[start + 1 : end] = []
        changed += 1
    return "".join(lines), changed


def legacy_content(data: dict[str, Any]) -> str | None:
    """Build the old three-field block for READMEs not yet migrated."""
    fields: dict[str, str] = legacy_metadata_from_yaml(data)
    if len(fields) != len(INDEX_LABELS):
        return None
    return "".join(f"  - {INDEX_LABELS[key]}: {fields[key]}\n" for key in INDEX_LABELS)


def load(index_text: str) -> tuple[str, int]:
    """Restore each linked entry's child Markdown from YAML front matter."""
    lines: list[str] = index_text.splitlines(keepends=True)
    changed: int = 0
    for start, indent, path in reversed(entry_starts(lines)):
        if not path.is_file():
            continue
        data: dict[str, Any]
        _body: str
        data, _body = front_matter(path.read_text(encoding="utf-8"))
        stored: Any = data.get("index_content")
        content: str | None = stored if isinstance(stored, str) else legacy_content(data)
        if content is None:
            continue
        end: int = child_end(lines, start, indent)
        lines[start + 1 : end] = content.splitlines(keepends=True)
        changed += 1
    return "".join(lines), changed


def parse_args() -> argparse.Namespace:
    parser: argparse.ArgumentParser = argparse.ArgumentParser(
        description="Synchronize index entry content with README YAML front matter."
    )
    mode: argparse._MutuallyExclusiveGroup = parser.add_mutually_exclusive_group(required=True)
    mode.add_argument("--save", action="store_true", help="copy child Markdown to READMEs and remove it from the index")
    mode.add_argument("--load", action="store_true", help="restore child Markdown from README YAML")
    return parser.parse_args()


def main() -> None:
    args: argparse.Namespace = parse_args()
    index_text: str = INDEX.read_text(encoding="utf-8")
    updated_index: str
    count: int
    if args.save:
        updated_index, count = save(index_text)
        INDEX.write_text(updated_index, encoding="utf-8")
        print(f"saved {count} entries")
        return
    updated_index, count = load(index_text)
    INDEX.write_text(updated_index, encoding="utf-8")
    print(f"loaded {count} entries")


if __name__ == "__main__":
    main()
