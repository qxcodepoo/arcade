from __future__ import annotations

from abc import ABC, abstractmethod
from dataclasses import dataclass


@dataclass
class Animal(ABC):
    name: str

    @abstractmethod
    def make_sound(self) -> str:
        """Return the sound characteristic of this animal."""

    @abstractmethod
    def move(self) -> str:
        """Return the movement characteristic of this animal."""


class Lion(Animal):
    def make_sound(self) -> str:
        return "roar"

    def move(self) -> str:
        return "run"


class Elephant(Animal):
    def make_sound(self) -> str:
        return "trumpet"

    def move(self) -> str:
        return "walk"


class Snake(Animal):
    def make_sound(self) -> str:
        return "hiss"

    def move(self) -> str:
        return "slither"


def present(animal: Animal) -> str:
    return f"{animal.name}: {animal.make_sound()}, {animal.move()}"
