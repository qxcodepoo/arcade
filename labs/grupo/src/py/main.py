from __future__ import annotations

from abc import ABC, abstractmethod
from dataclasses import dataclass
from typing import TextIO


class ChatError(Exception):
    pass


@dataclass(frozen=True)
class Message:
    sender: str
    text: str


class Chat(ABC):
    def __init__(self, identifier: str, members: set[str]) -> None:
        self.identifier: str = identifier
        self.members: set[str] = members
        self._unread: dict[str, list[Message]] = {member: [] for member in members}

    @abstractmethod
    def invite(self, owner: str, user: str) -> None:
        pass

    @abstractmethod
    def leave(self, user: str) -> None:
        pass

    def send(self, sender: str, text: str) -> None:
        if sender not in self.members:
            raise ChatError(f"fail: {sender} nao esta no chat")
        message = Message(sender, text)
        for member in self.members:
            if member != sender:
                self._unread[member].append(message)

    def read(self, user: str) -> list[Message]:
        if user not in self.members:
            raise ChatError(f"fail: {user} nao esta no chat")
        result = self._unread[user].copy()
        self._unread[user].clear()
        return result


class Group(Chat):
    def invite(self, owner: str, user: str) -> None:
        if owner not in self.members:
            raise ChatError("fail: usuario nao esta no grupo")
        self.members.add(user)
        self._unread.setdefault(user, [])

    def leave(self, user: str) -> None:
        self.members.discard(user)
        self._unread.pop(user, None)


class Talk(Chat):
    def invite(self, owner: str, user: str) -> None:
        raise ChatError("fail: operacao de acionar usuarios nao suportada")

    def leave(self, user: str) -> None:
        raise ChatError("fail: operacao de sair do chat nao suportada")


class Messenger:
    def __init__(self) -> None:
        self.users: set[str] = set()
        self.chats: dict[str, Chat] = {}

    def add_user(self, user: str) -> None:
        self.users.add(user)

    def create_group(self, owner: str, identifier: str) -> None:
        self._require_user(owner)
        self.chats[identifier] = Group(identifier, {owner})

    def create_talk(self, first: str, second: str) -> None:
        self._require_user(first)
        self._require_user(second)
        identifier = "-".join(sorted((first, second)))
        self.chats[identifier] = Talk(identifier, {first, second})

    def chat(self, identifier: str) -> Chat:
        chat = self.chats.get(identifier)
        if chat is None:
            raise ChatError("fail: chat nao encontrado")
        return chat

    def _require_user(self, user: str) -> None:
        if user not in self.users:
            raise ChatError("fail: usuario nao encontrado")


def main(input_stream: TextIO, output_stream: TextIO) -> None:
    app = Messenger()
    for line in input_stream:
        try:
            match line.split():
                case ["addUser", user]:
                    app.add_user(user)
                case ["newGroup", owner, name]:
                    app.create_group(owner, name)
                case ["newTalk", first, second]:
                    app.create_talk(first, second)
                case ["invite", owner, user, chat]:
                    app.chat(chat).invite(owner, user)
                case ["leave", user, chat]:
                    app.chat(chat).leave(user)
                case ["zap", user, chat, *text]:
                    app.chat(chat).send(user, " ".join(text))
                case ["ler", user, chat]:
                    messages = app.chat(chat).read(user)
                    print("\n".join(f"{m.sender}: {m.text}" for m in messages), file=output_stream)
                case ["end"]:
                    break
        except ChatError as error:
            print(error, file=output_stream)


if __name__ == "__main__":
    import sys

    main(sys.stdin, sys.stdout)
