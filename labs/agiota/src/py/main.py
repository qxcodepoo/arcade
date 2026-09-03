from __future__ import annotations

from dataclasses import dataclass
from enum import Enum
import math
import sys


class Label(Enum):
    GIVE = "give"
    TAKE = "take"
    PLUS = "plus"

    def __str__(self) -> str:
        return self.value


class AgiotaError(Exception):
    """Falha de uma regra do domínio do agiota."""


@dataclass(frozen=True)
class Operation:
    id: int
    name: str
    label: Label
    value: int

    def __str__(self) -> str:
        return f"id:{self.id} {self.label}:{self.name} {self.value}"


class Client:
    def __init__(self, name: str, limit: int) -> None:
        self._name: str = name
        self._limit: int = limit
        self._operations: list[Operation] = []

    @property
    def name(self) -> str:
        return self._name

    @property
    def limit(self) -> int:
        return self._limit

    @property
    def operations(self) -> tuple[Operation, ...]:
        return tuple(self._operations)

    def add_operation(self, operation: Operation) -> None:
        self._operations.append(operation)

    def balance(self) -> int:
        balance: int = 0
        for operation in self._operations:
            if operation.label is Label.TAKE:
                balance -= operation.value
            else:
                balance += operation.value
        return balance

    def __str__(self) -> str:
        return f"{self.name} {self.balance()}/{self.limit}"


class Agiota:
    def __init__(self) -> None:
        self._clients: dict[str, Client] = {}
        self._dead_clients: list[Client] = []
        self._operations: list[Operation] = []
        self._dead_operations: list[Operation] = []
        self._next_operation_id: int = 0

    def _client(self, name: str) -> Client:
        client: Client | None = self._clients.get(name)
        if client is None:
            raise AgiotaError("cliente nao existe")
        return client

    def _add_operation(self, client: Client, label: Label, value: int) -> None:
        operation: Operation = Operation(
            self._next_operation_id, client.name, label, value
        )
        self._next_operation_id += 1
        self._operations.append(operation)
        client.add_operation(operation)

    def add_client(self, name: str, limit: int) -> None:
        if name in self._clients:
            raise AgiotaError("cliente ja existe")
        self._clients[name] = Client(name, limit)

    def give(self, name: str, value: int) -> None:
        client: Client = self._client(name)
        if client.balance() + value > client.limit:
            raise AgiotaError("limite excedido")
        self._add_operation(client, Label.GIVE, value)

    def take(self, name: str, value: int) -> None:
        client: Client = self._client(name)
        if value > client.balance():
            raise AgiotaError("pagamento excede divida")
        self._add_operation(client, Label.TAKE, value)

    def plus(self) -> None:
        for name in sorted(self._clients):
            client: Client = self._clients[name]
            interest: int = math.ceil(client.balance() * 0.1)
            if interest > 0:
                self._add_operation(client, Label.PLUS, interest)
            if client.balance() > client.limit:
                self.kill(client.name)

    def kill(self, name: str) -> None:
        client: Client = self._client(name)
        del self._clients[name]
        self._dead_clients.append(client)

        remaining: list[Operation] = []
        for operation in self._operations:
            if operation.name == name:
                self._dead_operations.append(operation)
            else:
                remaining.append(operation)
        self._operations = remaining

    def client_text(self, name: str) -> str:
        client: Client = self._client(name)
        return "\n".join([str(client), *(str(op) for op in client.operations)])

    def __str__(self) -> str:
        lines: list[str] = []
        for name in sorted(self._clients):
            lines.append(f":) {self._clients[name]}")
        lines.extend(f"+ {operation}" for operation in self._operations)
        lines.extend(f":( {client}" for client in self._dead_clients)
        lines.extend(f"- {operation}" for operation in self._dead_operations)
        return "\n".join(lines)


def main() -> None:
    agiota: Agiota = Agiota()
    for line in sys.stdin:
        parts: list[str] = line.split()
        print(f"${line.rstrip()}")
        try:
            match parts:
                case ["end"]:
                    return
                case ["show"]:
                    print(agiota)
                case ["showCli", name]:
                    print(agiota.client_text(name))
                case ["addCli", name, limit]:
                    agiota.add_client(name, int(limit))
                case ["give", name, value]:
                    agiota.give(name, int(value))
                case ["take", name, value]:
                    agiota.take(name, int(value))
                case ["plus"]:
                    agiota.plus()
                case ["kill", name]:
                    agiota.kill(name)
                case _:
                    print("fail: comando invalido")
        except (AgiotaError, ValueError) as error:
            if isinstance(error, AgiotaError):
                print(f"fail: {error}")
            else:
                print("fail: comando invalido")


if __name__ == "__main__":
    main()
