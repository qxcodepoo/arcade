#!/usr/bin/env python3
"""Synchronize activity metadata between the root index and activity READMEs."""

from __future__ import annotations

import argparse
import re
from pathlib import Path
from typing import Any

import yaml


ROOT: Path = Path(__file__).resolve().parent
INDEX: Path = ROOT / "README.md"
ENTRY_RE: re.Pattern[str] = re.compile(r"^- \[ \].*\(([^)]+/README\.md)\)")
FIELD_RE: re.Pattern[str] = re.compile(
    r"^(\s*)-\s+(Descrição|Domínio|Objetivos?|description|domain|objectives):\s*(.*)$",
    re.IGNORECASE,
)
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
FIELD_KEYS: dict[str, str] = {
    "description": "description",
    "descrição": "description",
    "domain": "domain",
    "domínio": "domain",
    "objectives": "objectives",
    "objetivos": "objectives",
    "objetivo": "objectives",
}


def activity_entries(lines: list[str]) -> list[tuple[int, int, Path]]:
    """Return index ranges and linked README paths for activity entries."""
    entries: list[tuple[int, int, Path]] = []
    starts: list[tuple[int, Path]] = []
    for line_number, line in enumerate(lines):
        match: re.Match[str] | None = ENTRY_RE.match(line.rstrip("\n"))
        if match is not None:
            starts.append((line_number, ROOT / match.group(1)))

    for position, (start, path) in enumerate(starts):
        end: int = starts[position + 1][0] if position + 1 < len(starts) else len(lines)
        entries.append((start, end, path))
    return entries


def read_index_fields(lines: list[str], start: int, end: int) -> dict[str, str]:
    """Read the three metadata fields from one index entry."""
    fields: dict[str, str] = {}
    for line in lines[start + 1 : end]:
        match: re.Match[str] | None = FIELD_RE.match(line.rstrip("\n"))
        if match is None:
            continue
        label: str = match.group(2).lower()
        key: str = FIELD_KEYS.get(label, "")
        if key in ("description", "domain", "objectives"):
            fields[key] = match.group(3).strip()
    return fields


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


def metadata_from_yaml(data: dict[str, Any]) -> dict[str, str]:
    """Read canonical metadata, accepting Portuguese key aliases too."""
    result: dict[str, str] = {}
    for canonical, aliases in KEY_ALIASES.items():
        for alias in aliases:
            value: Any = data.get(alias)
            if isinstance(value, str):
                result[canonical] = value
                break
    return result


def write_front_matter(path: Path, fields: dict[str, str]) -> None:
    """Merge metadata into a README front matter and preserve its body."""
    text: str = path.read_text(encoding="utf-8")
    data: dict[str, Any]
    body: str
    data, body = front_matter(text)
    for key in ("description", "domain", "objectives"):
        if key in fields:
            data[key] = fields[key]
    header: str = yaml.safe_dump(
        data,
        allow_unicode=True,
        default_flow_style=False,
        sort_keys=False,
    )
    path.write_text(f"---\n{header}---\n{body}", encoding="utf-8")


def save(index_text: str) -> tuple[str, int]:
    """Copy metadata to activity READMEs and remove it from the index."""
    lines: list[str] = index_text.splitlines(keepends=True)
    changed: int = 0
    for start, end, path in reversed(activity_entries(lines)):
        fields: dict[str, str] = read_index_fields(lines, start, end)
        if len(fields) != 3 or not path.is_file():
            continue
        write_front_matter(path, fields)
        retained: list[str] = []
        for line in lines[start + 1 : end]:
            match: re.Match[str] | None = FIELD_RE.match(line.rstrip("\n"))
            if match is not None and FIELD_KEYS.get(match.group(2).lower(), "") in fields:
                continue
            retained.append(line)
        lines[start + 1 : end] = retained
        changed += 1
    return "".join(lines), changed


def load(index_text: str) -> tuple[str, int]:
    """Copy metadata from linked activity READMEs to the index."""
    lines: list[str] = index_text.splitlines(keepends=True)
    changed: int = 0
    for start, end, path in reversed(activity_entries(lines)):
        if not path.is_file():
            continue
        data: dict[str, Any]
        _body: str
        data, _body = front_matter(path.read_text(encoding="utf-8"))
        fields: dict[str, str] = metadata_from_yaml(data)
        if len(fields) != 3:
            continue

        existing: dict[str, int] = {}
        for line_number in range(start + 1, end):
            match: re.Match[str] | None = FIELD_RE.match(lines[line_number].rstrip("\n"))
            if match is None:
                continue
            label: str = match.group(2).lower()
            key: str = FIELD_KEYS.get(label, "")
            if key in fields and key not in existing:
                existing[key] = line_number

        if len(existing) == 3:
            for key, line_number in existing.items():
                lines[line_number] = f"  - {INDEX_LABELS[key]}: {fields[key]}\n"
        else:
            insert_at: int = start + 1
            new_lines: list[str] = [
                f"  - {INDEX_LABELS['description']}: {fields['description']}\n",
                f"  - {INDEX_LABELS['domain']}: {fields['domain']}\n",
                f"  - {INDEX_LABELS['objectives']}: {fields['objectives']}\n",
            ]
            lines[insert_at:insert_at] = new_lines
        changed += 1
    return "".join(lines), changed


def parse_args() -> argparse.Namespace:
    parser: argparse.ArgumentParser = argparse.ArgumentParser(
        description="Synchronize activity metadata with README YAML front matter."
    )
    mode: argparse._MutuallyExclusiveGroup = parser.add_mutually_exclusive_group(required=True)
    mode.add_argument("--save", action="store_true", help="copy metadata to activities and remove it from the index")
    mode.add_argument("--load", action="store_true", help="copy metadata to the index without changing activity YAML")
    return parser.parse_args()


def main() -> None:
    args: argparse.Namespace = parse_args()
    index_text: str = INDEX.read_text(encoding="utf-8")
    if args.save:
        updated_index: str
        count: int
        updated_index, count = save(index_text)
        INDEX.write_text(updated_index, encoding="utf-8")
        print(f"saved {count} activities")
        return
    updated_index: str
    count = 0
    updated_index, count = load(index_text)
    INDEX.write_text(updated_index, encoding="utf-8")
    print(f"loaded {count} activities")


if __name__ == "__main__":
    main()
