from dataclasses import dataclass
from enum import Enum


INVALID_COMMAND_MSG: str = "fail: comando invalido"
INVALID_COUNTER_MSG: str = "fail: caixa inexistente"
BUSY_COUNTER_MSG: str = "fail: caixa ocupado"
EMPTY_WAITING_MSG: str = "fail: sem clientes"
EMPTY_COUNTER_MSG: str = "fail: caixa vazio"
PERSON_NOT_WAITING_MSG: str = "fail: pessoa nao esta na fila"


class CallResult(Enum):
    OK = 0
    INVALID_COUNTER = 1
    BUSY_COUNTER = 2
    EMPTY_WAITING = 3


class FinishResult(Enum):
    OK = 0
    INVALID_COUNTER = 1
    EMPTY_COUNTER = 2


@dataclass
class Person:
    name: str

    def __str__(self) -> str:
        return self.name


class Market:
    def __init__(self, counter_count: int) -> None:
        self.__counters: list[Person | None] = [None] * counter_count
        self.__waiting: list[Person] = []

    def __validate_counter(self, index: int) -> bool:
        return 0 <= index < len(self.__counters)

    def arrive(self, person: Person) -> None:
        self.__waiting.append(person)

    def call(self, index: int) -> CallResult:
        if not self.__validate_counter(index):
            return CallResult.INVALID_COUNTER
        if self.__counters[index] is not None:
            return CallResult.BUSY_COUNTER
        if not self.__waiting:
            return CallResult.EMPTY_WAITING
        self.__counters[index] = self.__waiting.pop(0)
        return CallResult.OK

    def finish(self, index: int) -> tuple[Person | None, FinishResult]:
        if not self.__validate_counter(index):
            return (None, FinishResult.INVALID_COUNTER)
        person: Person | None = self.__counters[index]
        if person is None:
            return (None, FinishResult.EMPTY_COUNTER)
        self.__counters[index] = None
        return (person, FinishResult.OK)

    def cut_in_line(self, sneaky: Person, fool: str) -> bool:
        for index, person in enumerate(self.__waiting):
            if person.name == fool:
                self.__waiting.insert(index, sneaky)
                return True
        return False

    def give_up(self, name: str) -> Person | None:
        for index, person in enumerate(self.__waiting):
            if person.name == name:
                return self.__waiting.pop(index)
        return None

    def __str__(self) -> str:
        counters: str = ", ".join(
            "-----" if person is None else str(person)
            for person in self.__counters
        )
        waiting: str = ", ".join(str(person) for person in self.__waiting)
        return f"Caixas: [{counters}]\nEspera: [{waiting}]"


def print_call_result(result: CallResult) -> None:
    if result == CallResult.INVALID_COUNTER:
        print(INVALID_COUNTER_MSG)
    elif result == CallResult.BUSY_COUNTER:
        print(BUSY_COUNTER_MSG)
    elif result == CallResult.EMPTY_WAITING:
        print(EMPTY_WAITING_MSG)


def print_finish_result(result: FinishResult) -> None:
    if result == FinishResult.INVALID_COUNTER:
        print(INVALID_COUNTER_MSG)
    elif result == FinishResult.EMPTY_COUNTER:
        print(EMPTY_COUNTER_MSG)


def main() -> None:
    market: Market = Market(0)

    while True:
        line: str = input()
        print("$" + line)

        match line.split():
            case ["end"]:
                break
            case ["show"]:
                print(market)
            case ["init", counter_count]:
                market = Market(int(counter_count))
            case ["arrive", name]:
                market.arrive(Person(name))
            case ["call", index]:
                print_call_result(market.call(int(index)))
            case ["finish", index]:
                _, result = market.finish(int(index))
                print_finish_result(result)
            case ["cutInLine", sneaky, fool]:
                if not market.cut_in_line(Person(sneaky), fool):
                    print(PERSON_NOT_WAITING_MSG)
            case ["giveUp", name]:
                if market.give_up(name) is None:
                    print(PERSON_NOT_WAITING_MSG)
            case _:
                print(INVALID_COMMAND_MSG)


if __name__ == "__main__":
    main()
