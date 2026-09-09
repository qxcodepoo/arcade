from __future__ import annotations

import tempfile
import unittest
from pathlib import Path
from unittest.mock import patch

import yaml_store


class YamlStoreTest(unittest.TestCase):
    def setUp(self) -> None:
        self.temporary_directory = tempfile.TemporaryDirectory[str]()
        self.root = Path(self.temporary_directory.name)
        self.root_patch = patch.object(yaml_store, "ROOT", self.root)
        self.root_patch.start()

    def tearDown(self) -> None:
        self.root_patch.stop()
        self.temporary_directory.cleanup()

    def write_readme(self, relative_path: str, content: str) -> Path:
        path = self.root / relative_path
        path.parent.mkdir(parents=True, exist_ok=True)
        path.write_text(content, encoding="utf-8")
        return path

    def test_save_and_load_preserve_complete_child_markdown(self) -> None:
        path = self.write_readme(
            "labs/sample/README.md",
            "---\ndescription: old\ndomain: old\nobjectives: old\nkeep: value\n---\n# Sample\n",
        )
        original = (
            "## Topic\n\n"
            "- [ ] [Sample](labs/sample/README.md)\n"
            "  - Summary: preserves **Markdown**.\n"
            "    - Nested item.\n"
            "  - Paragraph: text.\n"
            "\n"
            "| Table |\n"
            "| --- |\n"
        )

        saved, count = yaml_store.save(original)

        self.assertEqual(1, count)
        self.assertEqual(
            "## Topic\n\n- [ ] [Sample](labs/sample/README.md)\n\n| Table |\n| --- |\n",
            saved,
        )
        data, _body = yaml_store.front_matter(path.read_text(encoding="utf-8"))
        self.assertEqual(
            "  - Summary: preserves **Markdown**.\n    - Nested item.\n  - Paragraph: text.\n",
            data["index_content"],
        )
        self.assertEqual("value", data["keep"])
        self.assertNotIn("description", data)
        self.assertNotIn("domain", data)
        self.assertNotIn("objectives", data)
        self.assertIn("index_content: |", path.read_text(encoding="utf-8"))

        loaded, count = yaml_store.load(saved)

        self.assertEqual(1, count)
        self.assertEqual(original, loaded)

    def test_save_supports_wiki_readmes(self) -> None:
        path = self.write_readme("wiki/topic/README.md", "# Topic\n")
        index = "- [ ] [Topic](wiki/topic/README.md)\n  - Learning goal.\n"

        saved, count = yaml_store.save(index)

        self.assertEqual(1, count)
        self.assertEqual("- [ ] [Topic](wiki/topic/README.md)\n", saved)
        data, _body = yaml_store.front_matter(path.read_text(encoding="utf-8"))
        self.assertEqual("  - Learning goal.\n", data["index_content"])

    def test_load_accepts_legacy_metadata(self) -> None:
        self.write_readme(
            "labs/legacy/README.md",
            "---\ndescription: description\ndomain: domain\nobjectives: objectives\n---\n# Legacy\n",
        )
        index = "- [ ] [Legacy](labs/legacy/README.md)\n"

        loaded, count = yaml_store.load(index)

        self.assertEqual(1, count)
        self.assertEqual(
            "- [ ] [Legacy](labs/legacy/README.md)\n"
            "  - Descrição: description\n"
            "  - Domínio: domain\n"
            "  - Objetivos: objectives\n",
            loaded,
        )


if __name__ == "__main__":
    unittest.main()
