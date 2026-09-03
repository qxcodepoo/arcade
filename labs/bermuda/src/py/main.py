from __future__ import annotations

import sys


class Bermuda:
    DEFAULT_SIZE: str = "P"
    ALLOWED_SIZES: tuple[str, ...] = ("P", "M", "G", "GG")

    def __init__(self, size: str) -> None:
        self._validate_size(size)
        self._size: str = size

    @classmethod
    def _validate_size(cls, size: str) -> None:
        if size not in cls.ALLOWED_SIZES:
            raise ValueError("invalid size")

    def get_size(self) -> str:
        return self._size

    def set_size(self, size: str) -> None:
        self._validate_size(size)
        self._size = size

    @classmethod
    def get_allowed_sizes(cls) -> list[str]:
        return list(cls.ALLOWED_SIZES)

    def __str__(self) -> str:
        return f"size: ({self._size})"


def main() -> None:
    bermuda: Bermuda = Bermuda(Bermuda.DEFAULT_SIZE)
    for line in sys.stdin:
        parts: list[str] = line.split()
        print(f"${line.rstrip()}")
        try:
            match parts:
                case ["end"]:
                    return
                case ["show"]:
                    print(bermuda)
                case ["init", size]:
                    bermuda = Bermuda(size)
                case ["size", size]:
                    bermuda.set_size(size)
                case _:
                    print("fail: invalid command")
        except ValueError:
            print("fail: invalid size")


if __name__ == "__main__":
    main()
