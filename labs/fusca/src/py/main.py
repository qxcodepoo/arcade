from __future__ import annotations

from dataclasses import dataclass
import sys


class OccupiedSeatError(Exception):
    pass


class PersonTooYoungError(Exception):
    pass


class DriverNotSetError(Exception):
    pass


class InvalidDistanceError(Exception):
    pass


@dataclass
class Person:
    name: str
    age: int

    def __str__(self) -> str:
        return f"{self.name}:{self.age}"


class Fusca:
    SEAT_COUNT: int = 4

    def __init__(self) -> None:
        self._seats: list[Person | None] = [None] * self.SEAT_COUNT
        self._km: int = 0

    def _check_seat_index(self, index: int) -> None:
        if not 0 <= index < self.SEAT_COUNT:
            raise IndexError("invalid seat index")

    def enter(self, person: Person, index: int) -> None:
        self._check_seat_index(index)
        if self._seats[index] is not None:
            raise OccupiedSeatError("occupied seat")
        if index == 0 and person.age < 18:
            raise PersonTooYoungError("person is too young for this seat")
        if index == 1 and person.age < 10:
            raise PersonTooYoungError("person is too young for this seat")
        self._seats[index] = person

    def leave(self, index: int) -> Person | None:
        self._check_seat_index(index)
        person: Person | None = self._seats[index]
        self._seats[index] = None
        return person

    def drive(self, distance: int) -> None:
        if self._seats[0] is None:
            raise DriverNotSetError("driver is not set")
        if distance <= 0:
            raise InvalidDistanceError("distance must be positive")
        self._km += distance

    def __str__(self) -> str:
        seat_text: list[str] = []
        for index, person in enumerate(self._seats):
            value: str = "(empty)" if person is None else str(person)
            seat_text.append(f"{index}:{value}")
        return f"seats: [{', '.join(seat_text)}], km: {self._km}"


def main() -> None:
    fusca: Fusca = Fusca()
    for line in sys.stdin:
        parts: list[str] = line.split()
        print(f"${line.rstrip()}")
        try:
            match parts:
                case ["end"]:
                    return
                case ["show"]:
                    print(fusca)
                case ["enter", name, age, index]:
                    fusca.enter(Person(name, int(age)), int(index))
                case ["leave", index]:
                    person: Person | None = fusca.leave(int(index))
                    if person is not None:
                        print(person)
                case ["drive", distance]:
                    fusca.drive(int(distance))
                case _:
                    print("fail: invalid command")
        except IndexError:
            print("fail: invalid seat")
        except OccupiedSeatError:
            print("fail: occupied seat")
        except PersonTooYoungError:
            print("fail: person is too young for this seat")
        except DriverNotSetError:
            print("fail: driver is not set")
        except InvalidDistanceError:
            print("fail: distance must be positive")
        except ValueError:
            print("fail: invalid command")


if __name__ == "__main__":
    main()
