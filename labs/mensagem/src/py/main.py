from __future__ import annotations

from dataclasses import dataclass, field
from typing import TextIO


class MessagingError(Exception):
    pass


@dataclass(frozen=True)
class Message:
    sender: str
    text: str


@dataclass
class User:
    username: str
    inbox: list[Message] = field(default_factory=list)

    def receive(self, message: Message) -> None:
        self.inbox.append(message)

    def read_inbox(self) -> list[Message]:
        messages = self.inbox.copy()
        self.inbox.clear()
        return messages


class Messaging:
    def __init__(self) -> None:
        self.users: dict[str, User] = {}

    def user(self, username: str) -> User:
        user = self.users.get(username)
        if user is None:
            raise MessagingError("fail: usuario nao encontrado")
        return user

    def add_user(self, username: str) -> None:
        self.users.setdefault(username, User(username))

    def send(self, sender: str, recipient: str, text: str) -> None:
        self.user(sender)
        self.user(recipient).receive(Message(sender, text))

    def inbox(self, username: str) -> str:
        messages = self.user(username).read_inbox()
        return "\n".join(f"{message.sender}:{message.text}" for message in messages) or "- empty -"


def main(input_stream: TextIO, output_stream: TextIO) -> None:
    messaging = Messaging()
    for line in input_stream:
        try:
            match line.split():
                case ["addUser", username]:
                    messaging.add_user(username)
                case ["sendMsg", sender, recipient, *text]:
                    messaging.send(sender, recipient, " ".join(text))
                case ["inbox", username]:
                    print(messaging.inbox(username), file=output_stream)
                case ["end"]:
                    break
        except MessagingError as error:
            print(error, file=output_stream)


if __name__ == "__main__":
    import sys

    main(sys.stdin, sys.stdout)
