from __future__ import annotations

from dataclasses import dataclass
from typing import TextIO


class ChatError(Exception):
    pass


class UserNotFoundError(ChatError):
    pass


class GroupNotFoundError(ChatError):
    pass


class NotMemberError(ChatError):
    pass


@dataclass(frozen=True)
class Message:
    sender: str
    text: str


class Group:
    def __init__(self, identifier: int, name: str) -> None:
        self.identifier: int = identifier
        self.name: str = name
        self.members: dict[str, User] = {}
        self._unread: dict[str, list[Message]] = {}

    def add(self, user: User) -> None:
        self.members[user.username] = user
        self._unread.setdefault(user.username, [])

    def remove(self, username: str) -> None:
        self.members.pop(username, None)
        self._unread.pop(username, None)

    def send(self, sender: User, text: str) -> None:
        if sender.username not in self.members:
            raise NotMemberError(f"fail: user {sender.username} nao esta no chat {self.name}")
        message = Message(sender.username, text)
        for username in self.members:
            if username != sender.username:
                self._unread[username].append(message)

    def read(self, username: str) -> list[Message]:
        if username not in self.members:
            raise NotMemberError(f"fail: user {username} nao esta no chat {self.name}")
        messages = self._unread[username].copy()
        self._unread[username].clear()
        return messages

    def unread_count(self, username: str) -> int:
        return len(self._unread.get(username, []))

    def __str__(self) -> str:
        return f"{self.identifier}:{self.name} [{', '.join(sorted(self.members))}]"


class User:
    def __init__(self, username: str) -> None:
        self.username: str = username
        self.groups: dict[int, Group] = {}


class WhatsApp:
    def __init__(self) -> None:
        self.users: dict[str, User] = {}
        self.groups: dict[int, Group] = {}
        self._next_group_id: int = 0

    def user(self, username: str) -> User:
        user = self.users.get(username)
        if user is None:
            raise UserNotFoundError(f"fail: key {username} not found")
        return user

    def group(self, identifier: int) -> Group:
        group = self.groups.get(identifier)
        if group is None:
            raise GroupNotFoundError(f"fail: key {identifier} not found")
        return group

    def group_by_name(self, name: str) -> Group:
        for group in self.groups.values():
            if group.name == name:
                return group
        raise GroupNotFoundError(f"fail: key {name} not found")

    def add_user(self, username: str) -> None:
        self.users.setdefault(username, User(username))

    def create(self, owner: str, name: str) -> Group:
        user = self.user(owner)
        group = Group(self._next_group_id, name)
        self._next_group_id += 1
        group.add(user)
        self.groups[group.identifier] = group
        user.groups[group.identifier] = group
        return group

    def invite(self, owner: str, invitee: str, identifier: int) -> None:
        group = self.group(identifier)
        if owner not in group.members:
            raise NotMemberError(f"fail: key {identifier} not found")
        user = self.user(invitee)
        group.add(user)
        user.groups[identifier] = group

    def leave(self, username: str, identifier: int) -> None:
        group = self.group(identifier)
        self.user(username)
        if username in group.members:
            group.remove(username)
            self.users[username].groups.pop(identifier, None)

    def send(self, username: str, identifier: int, text: str) -> None:
        self.group(identifier).send(self.user(username), text)

    def read(self, username: str, identifier: int) -> str:
        messages = self.group(identifier).read(username)
        return "\n".join(f"{message.sender}: {message.text}" for message in messages)

    def notify(self, username: str) -> str:
        user = self.user(username)
        return " ".join(
            f"{group.name}({group.unread_count(username)})"
            for group in sorted(user.groups.values(), key=lambda item: item.identifier)
        )


def main(input_stream: TextIO, output_stream: TextIO) -> None:
    app = WhatsApp()
    for line in input_stream:
        try:
            match line.split():
                case ["add", username]:
                    app.add_user(username)
                case ["users"]:
                    for user in app.users.values():
                        groups = ", ".join(f"{group.identifier}:{group.name}" for group in user.groups.values())
                        print(f"{user.username} [{groups}]", file=output_stream)
                case ["create", owner, name]:
                    app.create(owner, name)
                case ["invite", owner, invitee, identifier]:
                    app.invite(owner, invitee, int(identifier))
                case ["leave", username, identifier]:
                    app.leave(username, int(identifier))
                case ["zap", username, identifier, *text]:
                    app.send(username, int(identifier), " ".join(text))
                case ["ler", username, name]:
                    group = app.group_by_name(name)
                    print(app.read(username, group.identifier), file=output_stream)
                case ["notify", username]:
                    print(app.notify(username), file=output_stream)
                case ["end"]:
                    break
        except (ValueError, ChatError) as error:
            print(error, file=output_stream)


if __name__ == "__main__":
    import sys

    main(sys.stdin, sys.stdout)
