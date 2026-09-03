from dataclasses import dataclass
from enum import Enum


INVALID_COMMAND_MSG: str = "fail: comando invalido"
INVALID_INDEX_MSG: str = "fail: indice nao existe"
INVALID_QUANTITY_MSG: str = "fail: quantidade invalida"
INVALID_VALUE_MSG: str = "fail: valor invalido"
INSUFFICIENT_BALANCE_MSG: str = "fail: saldo insuficiente"
EMPTY_SLOT_MSG: str = "fail: espiral sem produtos"


class SlotResult(Enum):
    OK = 0
    INVALID_INDEX = 1
    INVALID_QUANTITY = 2


class CashResult(Enum):
    OK = 0
    INVALID_VALUE = 1


class BuyResult(Enum):
    OK = 0
    INVALID_INDEX = 1
    INSUFFICIENT_BALANCE = 2
    EMPTY_SLOT = 3


@dataclass
class Slot:
    name: str = "empty"
    quantity: int = 0
    price: float = 0.0

    def __str__(self) -> str:
        return f"[{self.name:>8} :{self.quantity:2d} U : {self.price:.2f} RS]"


class Machine:
    def __init__(self, capacity: int) -> None:
        self.__slots: list[Slot] = [Slot() for _ in range(capacity)]
        self.__cash: float = 0.0
        self.__revenue: float = 0.0

    def __valid_index(self, index: int) -> bool:
        return 0 <= index < len(self.__slots)

    def get_slot(self, index: int) -> Slot | None:
        if not self.__valid_index(index):
            return None
        return self.__slots[index]

    def set_slot(self, index: int, name: str, quantity: int, price: float) -> SlotResult:
        if not self.__valid_index(index):
            return SlotResult.INVALID_INDEX
        if quantity < 0:
            return SlotResult.INVALID_QUANTITY
        self.__slots[index] = Slot(name, quantity, price)
        return SlotResult.OK

    def clear_slot(self, index: int) -> bool:
        if not self.__valid_index(index):
            return False
        self.__slots[index] = Slot()
        return True

    def insert_cash(self, value: float) -> CashResult:
        if value <= 0:
            return CashResult.INVALID_VALUE
        self.__cash += value
        return CashResult.OK

    def withdraw_cash(self) -> float:
        cash: float = self.__cash
        self.__cash = 0.0
        return cash

    def get_cash(self) -> float:
        return self.__cash

    def get_revenue(self) -> float:
        return self.__revenue

    def buy_item(self, index: int) -> tuple[BuyResult, str | None]:
        if not self.__valid_index(index):
            return (BuyResult.INVALID_INDEX, None)
        slot: Slot = self.__slots[index]
        if self.__cash < slot.price:
            return (BuyResult.INSUFFICIENT_BALANCE, None)
        if slot.quantity == 0:
            return (BuyResult.EMPTY_SLOT, None)
        slot.quantity -= 1
        self.__cash -= slot.price
        self.__revenue += slot.price
        return (BuyResult.OK, slot.name)

    def __str__(self) -> str:
        lines: list[str] = [f"saldo: {self.__cash:.2f}"]
        lines.extend(f"{index} {slot}" for index, slot in enumerate(self.__slots))
        return "\n".join(lines)


def print_slot_result(result: SlotResult) -> None:
    if result == SlotResult.INVALID_INDEX:
        print(INVALID_INDEX_MSG)
    elif result == SlotResult.INVALID_QUANTITY:
        print(INVALID_QUANTITY_MSG)


def print_cash_result(result: CashResult) -> None:
    if result == CashResult.INVALID_VALUE:
        print(INVALID_VALUE_MSG)


def print_buy_result(result: tuple[BuyResult, str | None]) -> None:
    buy_result: BuyResult = result[0]
    product_name: str | None = result[1]
    if buy_result == BuyResult.INVALID_INDEX:
        print(INVALID_INDEX_MSG)
    elif buy_result == BuyResult.INSUFFICIENT_BALANCE:
        print(INSUFFICIENT_BALANCE_MSG)
    elif buy_result == BuyResult.EMPTY_SLOT:
        print(EMPTY_SLOT_MSG)
    elif product_name is not None:
        print(f"voce comprou um {product_name}")


def main() -> None:
    machine: Machine = Machine(0)

    while True:
        line: str = input()
        print("$" + line)

        match line.split():
            case ["end"]:
                break
            case ["init", capacity]:
                machine = Machine(int(capacity))
            case ["show"]:
                print(machine)
            case ["set", index, name, quantity, price]:
                result: SlotResult = machine.set_slot(
                    int(index), name, int(quantity), float(price)
                )
                print_slot_result(result)
            case ["limpar", index]:
                if not machine.clear_slot(int(index)):
                    print(INVALID_INDEX_MSG)
            case ["dinheiro", value]:
                print_cash_result(machine.insert_cash(float(value)))
            case ["troco"]:
                print(f"voce recebeu {machine.withdraw_cash():.2f} RS")
            case ["comprar", index]:
                print_buy_result(machine.buy_item(int(index)))
            case ["revenue"]:
                print(f"arrecadacao: {machine.get_revenue():.2f}")
            case _:
                print(INVALID_COMMAND_MSG)


if __name__ == "__main__":
    main()
