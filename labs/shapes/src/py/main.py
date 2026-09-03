from __future__ import annotations

from dataclasses import dataclass
import math
import sys
from typing import Protocol


class Shape(Protocol):
    def name(self) -> str:
        ...

    def area(self) -> float:
        ...

    def perimeter(self) -> float:
        ...


@dataclass(frozen=True)
class Point2D:
    x: float
    y: float

    def __str__(self) -> str:
        return f"({self.x:.2f}, {self.y:.2f})"


@dataclass(frozen=True)
class Circle:
    center: Point2D
    radius: float

    def name(self) -> str:
        return "Circ"

    def area(self) -> float:
        return math.pi * self.radius**2

    def perimeter(self) -> float:
        return 2 * math.pi * self.radius

    def __str__(self) -> str:
        return f"{self.name()}: C={self.center}, R={self.radius:.2f}"


@dataclass(frozen=True)
class Rectangle:
    p1: Point2D
    p2: Point2D

    def name(self) -> str:
        return "Rect"

    def _width(self) -> float:
        return abs(self.p1.x - self.p2.x)

    def _height(self) -> float:
        return abs(self.p1.y - self.p2.y)

    def area(self) -> float:
        return self._width() * self._height()

    def perimeter(self) -> float:
        return 2 * (self._width() + self._height())

    def __str__(self) -> str:
        return f"{self.name()}: P1={self.p1} P2={self.p2}"


def info(shape: Shape) -> str:
    return f"{shape.name()}: A={shape.area():.2f} P={shape.perimeter():.2f}"


def main() -> None:
    shapes: list[Shape] = []
    for line in sys.stdin:
        parts: list[str] = line.split()
        print(f"${line.rstrip()}")
        try:
            match parts:
                case ["end"]:
                    return
                case ["show"]:
                    print("\n".join(str(shape) for shape in shapes))
                case ["info"]:
                    print("\n".join(info(shape) for shape in shapes))
                case ["circle", x, y, radius]:
                    shapes.append(Circle(Point2D(float(x), float(y)), float(radius)))
                case ["rect", x1, y1, x2, y2]:
                    shapes.append(
                        Rectangle(
                            Point2D(float(x1), float(y1)),
                            Point2D(float(x2), float(y2)),
                        )
                    )
                case _:
                    print("fail: invalid command")
        except ValueError:
            print("fail: invalid command")


if __name__ == "__main__":
    main()
