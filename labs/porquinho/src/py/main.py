from __future__ import annotations

from dataclasses import dataclass
import sys


class PigError(Exception):
    """Falha em uma regra do porquinho."""


@dataclass(frozen=True)
class Coin:
    value: float
    volume: int
    label: str

    def __str__(self) -> str:
        return f"{self.value:.2f}:{self.volume}"


@dataclass(frozen=True)
class Item:
    label: str
    volume: int

    def __str__(self) -> str:
        return f"{self.label}:{self.volume}"


COINS: dict[str, Coin] = {
    "10": Coin(0.10, 1, "C10"),
    "25": Coin(0.25, 2, "C25"),
    "50": Coin(0.50, 3, "C50"),
    "100": Coin(1.00, 4, "C100"),
}


class Pig:
    def __init__(self, max_volume: int) -> None:
        self._max_volume: int = max_volume
        self._coins: list[Coin] = []
        self._items: list[Item] = []
        self._broken: bool = False

    def _check_can_add(self, volume: int) -> None:
        if self._broken:
            raise PigError("the pig is broken")
        if self.volume() + volume > self._max_volume:
            raise PigError("the pig is full")

    def add_coin(self, coin: Coin) -> None:
        self._check_can_add(coin.volume)
        self._coins.append(coin)

    def add_item(self, item: Item) -> None:
        self._check_can_add(item.volume)
        self._items.append(item)

    def break_pig(self) -> None:
        if self._broken:
            raise PigError("the pig is already broken")
        self._broken = True

    def extract_coins(self) -> list[Coin]:
        if not self._broken:
            raise PigError("you must break the pig first")
        coins: list[Coin] = self._coins.copy()
        self._coins.clear()
        return coins

    def extract_items(self) -> list[Item]:
        if not self._broken:
            raise PigError("you must break the pig first")
        items: list[Item] = self._items.copy()
        self._items.clear()
        return items

    def value(self) -> float:
        return sum(coin.value for coin in self._coins)

    def volume(self) -> int:
        if self._broken:
            return 0
        return sum(coin.volume for coin in self._coins) + sum(
            item.volume for item in self._items
        )

    def __str__(self) -> str:
        state: str = "broken" if self._broken else "intact"
        coins: str = ", ".join(str(coin) for coin in self._coins)
        items: str = ", ".join(str(item) for item in self._items)
        return (
            f"state={state} : coins=[{coins}] : items=[{items}] : "
            f"value={self.value():.2f} : volume={self.volume()}/{self._max_volume}"
        )


def list_text(objects: list[Coin] | list[Item]) -> str:
    return "[" + ", ".join(str(obj) for obj in objects) + "]"


def main() -> None:
    pig: Pig | None = None
    for line in sys.stdin:
        parts: list[str] = line.split()
        print(f"${line.rstrip()}")
        try:
            match parts:
                case ["end"]:
                    return
                case ["init", max_volume]:
                    pig = Pig(int(max_volume))
                case ["show"] if pig is not None:
                    print(pig)
                case ["addCoin", code] if pig is not None:
                    coin: Coin | None = COINS.get(code)
                    if coin is None:
                        print("fail: invalid coin")
                    else:
                        pig.add_coin(coin)
                case ["addItem", label, volume] if pig is not None:
                    pig.add_item(Item(label, int(volume)))
                case ["break"] if pig is not None:
                    pig.break_pig()
                case ["extractCoins"] if pig is not None:
                    print(list_text(pig.extract_coins()))
                case ["extractItems"] if pig is not None:
                    print(list_text(pig.extract_items()))
                case _:
                    print("fail: invalid command")
        except (PigError, ValueError) as error:
            if isinstance(error, PigError):
                print(f"fail: {error}")
            else:
                print("fail: invalid command")


if __name__ == "__main__":
    main()
