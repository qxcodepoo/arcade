from __future__ import annotations

from typing import TextIO


class Vector:
    def __init__(self) -> None:
        self.values: list[int] = []

    def add(self, values: list[int]) -> None:
        self.values.extend(values)

    def get(self, index: int) -> int:
        return self.values[index]

    def set(self, index: int, value: int) -> None:
        self.values[index] = value

    def insert(self, index: int, value: int) -> None:
        if index < 0:
            return
        self.values.insert(min(index, len(self.values)), value)

    def find(self, values: list[int]) -> list[int]:
        return [self.values.index(value) if value in self.values else -1 for value in values]

    def __str__(self) -> str:
        return "[ " + " ".join(map(str, self.values)) + " ]"


def main(input_stream: TextIO, output_stream: TextIO) -> None:
    vector = Vector()
    for line in input_stream:
        try:
            match line.split():
                case ["add", *values]:
                    vector.add([int(value) for value in values])
                case ["show"]:
                    print(vector, file=output_stream)
                case ["rshow"]:
                    print("[ " + " ".join(map(str, reversed(vector.values))) + " ]", file=output_stream)
                case ["get", index]:
                    print(vector.get(int(index)), file=output_stream)
                case ["set", index, value]:
                    vector.set(int(index), int(value))
                case ["ins", index, value]:
                    vector.insert(int(index), int(value))
                case ["find", *values]:
                    print("[ " + " ".join(map(str, vector.find([int(value) for value in values])) ) + " ]", file=output_stream)
                case ["end"]:
                    break
        except (ValueError, IndexError):
            print("fail: invalid index or value", file=output_stream)


if __name__ == "__main__":
    import sys

    main(sys.stdin, sys.stdout)
