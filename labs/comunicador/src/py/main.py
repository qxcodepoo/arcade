from __future__ import annotations

from dataclasses import dataclass, field


class CommunicationError(Exception):
    pass


@dataclass(frozen=True)
class Message:
    sender: str
    text: str


@dataclass
class Communicator:
    identifier: str
    receivers: dict[str, Communicator] = field(default_factory=dict)
    inbox: list[Message] = field(default_factory=list)

    def receive(self, message: Message) -> None:
        self.inbox.append(message)

    def send(self, receiver: str, text: str) -> None:
        target = self.receivers.get(receiver)
        if target is None:
            raise CommunicationError(f"fail:{self.identifier} nao conhece {receiver}")
        target.receive(Message(self.identifier, text))

    def read(self) -> list[Message]:
        messages = self.inbox.copy()
        self.inbox.clear()
        return messages
