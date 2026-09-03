from __future__ import annotations

from abc import ABC, abstractmethod
from typing import TextIO


class AccountError(Exception):
    pass


class AccountNotFoundError(AccountError):
    pass


class InsufficientBalanceError(AccountError):
    pass


class Account(ABC):
    def __init__(self, identifier: int, client_id: str) -> None:
        self.identifier: int = identifier
        self.client_id: str = client_id
        self.balance: float = 0.0

    @property
    @abstractmethod
    def type_code(self) -> str:
        pass

    @abstractmethod
    def monthly_update(self) -> None:
        pass

    def deposit(self, value: float) -> None:
        self.balance += value

    def withdraw(self, value: float) -> None:
        if self.balance < value:
            raise InsufficientBalanceError("fail: saldo insuficiente")
        self.balance -= value

    def transfer_to(self, other: Account, value: float) -> None:
        self.withdraw(value)
        other.deposit(value)

    def __str__(self) -> str:
        return f"{self.identifier}:{self.client_id}:{self.balance:.2f}:{self.type_code}"


class CheckingAccount(Account):
    @property
    def type_code(self) -> str:
        return "CC"

    def monthly_update(self) -> None:
        self.balance -= 20.0


class SavingsAccount(Account):
    @property
    def type_code(self) -> str:
        return "CP"

    def monthly_update(self) -> None:
        self.balance *= 1.01


class Client:
    def __init__(self, identifier: str) -> None:
        self.identifier: str = identifier
        self.accounts: list[Account] = []

    def add_account(self, account: Account) -> None:
        if all(existing.identifier != account.identifier for existing in self.accounts):
            self.accounts.append(account)

    def __str__(self) -> str:
        account_ids = ", ".join(str(account.identifier) for account in self.accounts)
        return f"{self.identifier} [{account_ids}]"


class BankAgency:
    def __init__(self) -> None:
        self.clients: dict[str, Client] = {}
        self.accounts: dict[int, Account] = {}
        self._next_account_id: int = 0

    def add_client(self, client_id: str) -> None:
        if client_id in self.clients:
            return
        client = Client(client_id)
        checking = CheckingAccount(self._next_account_id, client_id)
        savings = SavingsAccount(self._next_account_id + 1, client_id)
        self._next_account_id += 2
        self.clients[client_id] = client
        self.accounts[checking.identifier] = checking
        self.accounts[savings.identifier] = savings
        client.add_account(checking)
        client.add_account(savings)

    def _get_account(self, identifier: int) -> Account:
        account = self.accounts.get(identifier)
        if account is None:
            raise AccountNotFoundError("fail: conta nao encontrada")
        return account

    def deposit(self, identifier: int, value: float) -> None:
        self._get_account(identifier).deposit(value)

    def withdraw(self, identifier: int, value: float) -> None:
        self._get_account(identifier).withdraw(value)

    def transfer(self, source: int, target: int, value: float) -> None:
        source_account = self._get_account(source)
        target_account = self._get_account(target)
        source_account.transfer_to(target_account, value)

    def monthly_update(self) -> None:
        for account in self.accounts.values():
            account.monthly_update()

    def __str__(self) -> str:
        clients = "\n".join(str(client) for client in self.clients.values())
        accounts = "\n".join(str(account) for account in self.accounts.values())
        return f"- Clients\n{clients}\n- Accounts\n{accounts}"


def main(input_stream: TextIO, output_stream: TextIO) -> None:
    agency = BankAgency()
    for line in input_stream:
        try:
            match line.split():
                case ["addCli", client_id]:
                    agency.add_client(client_id)
                case ["show"]:
                    print(agency, file=output_stream)
                case ["saque", identifier, value]:
                    agency.withdraw(int(identifier), float(value))
                case ["deposito", identifier, value]:
                    agency.deposit(int(identifier), float(value))
                case ["transf", source, target, value]:
                    agency.transfer(int(source), int(target), float(value))
                case ["update"]:
                    agency.monthly_update()
                case ["end"]:
                    break
        except (ValueError, AccountError) as error:
            print(str(error) or "fail: argumento invalido", file=output_stream)


if __name__ == "__main__":
    import sys

    main(sys.stdin, sys.stdout)
