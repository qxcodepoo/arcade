from __future__ import annotations
from dataclasses import dataclass
from typing import TextIO

@dataclass(frozen=True)
class Operation:
    kind: str
    amount: int
    balance: int

class Account:
    def __init__(self, identifier: int) -> None:
        self.identifier = identifier
        self.balance = 0
        self.operations: list[Operation] = [Operation("opening", 0, 0)]
    def _record(self, kind: str, amount: int) -> None:
        self.balance += amount; self.operations.append(Operation(kind, amount, self.balance))
    def deposit(self, amount: int) -> None:
        if amount <= 0: raise ValueError("fail: invalid value")
        self._record("deposit", amount)
    def withdraw(self, amount: int) -> None:
        if amount <= 0: raise ValueError("fail: invalid value")
        if amount > self.balance: raise ValueError("fail: insufficient balance")
        self._record("withdraw", -amount)
    def fee(self, amount: int) -> None:
        if amount <= 0: raise ValueError("fail: invalid value")
        self._record("fee", -amount)
    def reverse(self, indexes: list[int]) -> list[str]:
        errors: list[str] = []
        for index in indexes:
            if index < 0 or index >= len(self.operations):
                errors.append(f"fail: index {index} invalid")
                continue
            operation = self.operations[index]
            if operation.kind != "fee":
                errors.append(f"fail: index {index} is not a fee")
                continue
            self._record("reverse", -operation.amount)
        return errors
    def __str__(self) -> str:
        return f"account:{self.identifier} balance:{self.balance}"

def main(inp: TextIO, out: TextIO) -> None:
    account: Account | None = None
    def current() -> Account:
        if account is None: raise ValueError("fail: account not initialized")
        return account
    for line in inp:
        try:
            match line.split():
                case ["init", identifier]: account = Account(int(identifier))
                case ["show"]: print(current(), file=out)
                case ["deposit", amount]: current().deposit(int(amount))
                case ["withdraw", amount]: current().withdraw(int(amount))
                case ["fee", amount]: current().fee(int(amount))
                case ["extract"]: print("\n".join(f"{i}:{op.kind}:{op.amount}:{op.balance}" for i, op in enumerate(current().operations)), file=out)
                case ["extract", count]: print("\n".join(f"{i}:{op.kind}:{op.amount}:{op.balance}" for i, op in list(enumerate(current().operations))[-int(count):]), file=out)
                case ["reverse", *indexes]:
                    for error in current().reverse([int(i) for i in indexes]): print(error, file=out)
                case ["end"]: break
        except (AttributeError, ValueError) as error: print(error, file=out)

if __name__ == "__main__":
    import sys
    main(sys.stdin, sys.stdout)
