from __future__ import annotations

from abc import ABC, abstractmethod
from dataclasses import dataclass


class PaymentError(Exception):
    """Base class for payment domain failures."""


class InvalidAmountError(PaymentError):
    pass


class InsufficientLimitError(PaymentError):
    pass


class PaymentMethod(ABC):
    @abstractmethod
    def process(self, amount: float) -> str:
        """Process an amount and return an observable result."""


@dataclass
class CreditCard(PaymentMethod):
    holder: str
    limit: float

    def process(self, amount: float) -> str:
        if amount > self.limit:
            raise InsufficientLimitError("insufficient credit limit")
        self.limit -= amount
        return f"Payment approved for {self.holder}. Remaining limit: {self.limit:.2f}"


@dataclass(frozen=True)
class Pix(PaymentMethod):
    key: str
    bank: str

    def process(self, amount: float) -> str:
        return f"PIX sent through {self.bank} using key {self.key}"


@dataclass(frozen=True)
class Boleto(PaymentMethod):
    barcode: str
    due_date: str

    def process(self, amount: float) -> str:
        return "Boleto generated. Waiting for payment..."


@dataclass
class Payment:
    amount: float
    description: str
    method: PaymentMethod

    def process(self) -> str:
        if self.amount <= 0:
            raise InvalidAmountError("invalid amount")
        result: str = self.method.process(self.amount)
        return f"Payment of R$ {self.amount:.2f}: {self.description}\n{result}"


def process_payments(payments: list[Payment]) -> list[str]:
    results: list[str] = []
    for payment in payments:
        try:
            results.append(payment.process())
        except PaymentError as error:
            results.append(f"Error: {error}")
    return results
