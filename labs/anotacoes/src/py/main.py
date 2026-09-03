from __future__ import annotations
from dataclasses import dataclass
from typing import TextIO

@dataclass(frozen=True)
class Note:
    title: str
    text: str

class NotesApp:
    def __init__(self) -> None:
        self.users: dict[str, str] = {}
        self.notes: dict[str, list[Note]] = {}
        self.current: str | None = None
    def add_user(self, name: str, password: str) -> None:
        self.users.setdefault(name, password); self.notes.setdefault(name, [])
    def login(self, name: str, password: str) -> None:
        if name not in self.users: raise ValueError("fail: usuario nao encontrado")
        if self.users[name] != password: raise ValueError("fail: senha invalida")
        self.current = name
    def logout(self) -> None:
        if self.current is None: raise ValueError("fail: ninguem logado")
        self.current = None
    def add_note(self, title: str, text: str) -> None:
        if self.current is None: raise ValueError("fail: ninguem logado")
        self.notes[self.current].append(Note(title, text))
    def show(self) -> str:
        if self.current is None: raise ValueError("fail: ninguem logado")
        return "user: " + self.current + "\n" + "\n".join(f"[{i}:{n.title}:{n.text}]" for i, n in enumerate(self.notes[self.current]))

def main(inp: TextIO, out: TextIO) -> None:
    app = NotesApp()
    for line in inp:
        try:
            match line.split():
                case ["addUser", name, password]: app.add_user(name, password)
                case ["users"]: print("[ " + " ".join(app.users) + " ]", file=out)
                case ["login", name, password]: app.login(name, password)
                case ["logout"]: app.logout()
                case ["addNote", title, *text]: app.add_note(title, " ".join(text))
                case ["show"]: print(app.show(), file=out)
                case ["end"]: break
        except ValueError as error: print(error, file=out)

if __name__ == "__main__":
    import sys
    main(sys.stdin, sys.stdout)
