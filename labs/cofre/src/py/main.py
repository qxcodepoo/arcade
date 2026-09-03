from __future__ import annotations

from dataclasses import dataclass
from enum import Enum
from typing import Protocol, TextIO


class Valuable(Protocol):
    def get_label(self) -> str: ...

    def get_value(self) -> float: ...

    def get_volume(self) -> int: ...


class PigError(Exception):
    pass


class PigBrokenError(PigError):
    pass


class PigFullError(PigError):
    pass


class PigAlreadyBrokenError(PigError):
    pass


class Coin(Enum):
    M10 = (0.10, 1)
    M25 = (0.25, 2)
    M50 = (0.50, 3)
    M100 = (1.00, 4)

    @property
    def label(self) -> str:
        return self.name

    def get_value(self) -> float:
        return self.value_data[0]

    def get_volume(self) -> int:
        return self.value_data[1]

    def get_label(self) -> str:
        return self.label

    @property
    def value_data(self) -> tuple[float, int]:
        return self._value_

    def __str__(self) -> str:
        return f"{self.label}:{self.get_value():.2f}:{self.get_volume()}"


@dataclass(frozen=True)
class Item:
    label: str
    value: float
    volume: int

    def __str__(self) -> str:
        return f"{self.label}:{self.value:.2f}:{self.volume}"

    def get_label(self) -> str:
        return self.label

    def get_value(self) -> float:
        return self.value

    def get_volume(self) -> int:
        return self.volume


class Pig:
    def __init__(self, max_volume: int) -> None:
        self.max_volume: int = max_volume
        self.broken: bool = False
        self._valuables: list[Valuable] = []

    @property
    def volume(self) -> int:
        if self.broken:
            return 0
        return sum(item.get_volume() for item in self._valuables)

    @property
    def value(self) -> float:
        return sum(item.get_value() for item in self._valuables)

    def add(self, valuable: Valuable) -> None:
        if self.broken:
            raise PigBrokenError("fail: the pig is broken")
        if self.volume + valuable.get_volume() > self.max_volume:
            raise PigFullError("fail: the pig is full")
        self._valuables.append(valuable)

    def break_pig(self) -> None:
        if self.broken:
            raise PigAlreadyBrokenError("fail: the pig is already broken")
        self.broken = True

    def extract_coins(self) -> list[Coin]:
        self._ensure_broken()
        coins = [item for item in self._valuables if isinstance(item, Coin)]
        self._valuables = [item for item in self._valuables if not isinstance(item, Coin)]
        return coins

    def extract_items(self) -> list[Item]:
        self._ensure_broken()
        items = [item for item in self._valuables if isinstance(item, Item)]
        self._valuables = [item for item in self._valuables if not isinstance(item, Item)]
        return items

    def _ensure_broken(self) -> None:
        if not self.broken:
            raise PigBrokenError("fail: you must break the pig first")

    def __str__(self) -> str:
        values = ", ".join(str(item) for item in self._valuables)
        status = "broken" if self.broken else "intact"
        return f"[{values}] : {self.value:.2f}$ : {self.volume}/{self.max_volume} : {status}"


def main(input_stream: TextIO, output_stream: TextIO) -> None:
    pig = Pig(0)
    for line in input_stream:
        match line.split():
            case ["init", volume]:
                pig = Pig(int(volume))
            case ["show"]:
                print(pig, file=output_stream)
            case ["addCoin", amount]:
                try:
                    pig.add(Coin[f"M{amount}"])
                except (KeyError, PigError) as error:
                    print(str(error) or "fail: invalid coin", file=output_stream)
            case ["addItem", label, value, volume]:
                try:
                    pig.add(Item(label, float(value), int(volume)))
                except (ValueError, PigError) as error:
                    print(str(error) or "fail: invalid item", file=output_stream)
            case ["break"]:
                try:
                    pig.break_pig()
                except PigError as error:
                    print(error, file=output_stream)
            case ["extractCoins"]:
                try:
                    print("[" + ", ".join(map(str, pig.extract_coins())) + "]", file=output_stream)
                except PigError as error:
                    print(error, file=output_stream)
            case ["extractItems"]:
                try:
                    print("[" + ", ".join(map(str, pig.extract_items())) + "]", file=output_stream)
                except PigError as error:
                    print(error, file=output_stream)
            case ["end"]:
                break


if __name__ == "__main__":
    import sys

    main(sys.stdin, sys.stdout)
