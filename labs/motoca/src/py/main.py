from enum import Enum, auto

class EnterResult(Enum):
    OK = auto()
    TOO_OLD = auto()
    BUSY = auto()


class DriveResult(Enum):
    OK = auto()
    BUY_TIME_FIRST = auto()
    EMPTY_MOTORCYCLE = auto()
    TIME_FINISHED = auto()

class Person:
    def __init__(self, name: str, age: int) -> None:
        self.__name: str = name
        self.__age: int = age

    def get_name(self) -> str:
        return self.__name

    def get_age(self) -> int:
        return self.__age

    def can_drive(self, max_age: int) -> bool:
        return self.__age <= max_age

    def __str__(self) -> str:
        return f"{self.__name}:{self.__age}"


class Motorcycle:
    def __init__(self, size: int) -> None:
        self.__person: Person | None = None
        self.__size: int = size
        self.__remaining_minutes: int = 0

    def get_size(self) -> int:
        return self.__size

    def get_time(self) -> int:
        return self.__remaining_minutes

    def get_person(self) -> Person | None:
        return self.__person

    def enter(self, person: Person) -> EnterResult:
        if self.__person is not None:
            return EnterResult.BUSY
        if not person.can_drive(self.__size):
            return EnterResult.TOO_OLD
        self.__person = person
        return EnterResult.OK

    def leave(self) -> Person | None:
        if self.__person is None:
            return None

        person: Person = self.__person
        self.__person = None
        return person

    def buy(self, minutes: int) -> None:
        self.__remaining_minutes += minutes

    def drive(self, minutes: int) -> DriveResult:
        if self.__remaining_minutes == 0:
            return DriveResult.BUY_TIME_FIRST
        if self.__person is None:
            return DriveResult.EMPTY_MOTORCYCLE
        if self.__remaining_minutes < minutes:
            self.__remaining_minutes = 0
            return DriveResult.TIME_FINISHED

        self.__remaining_minutes -= minutes
        return DriveResult.OK

    def __str__(self) -> str:
        EMPTY_PERSON_TEXT: str = "empty"
        person_text: str = EMPTY_PERSON_TEXT
        if self.__person is not None:
            person_text = str(self.__person)

        return f"size:{self.__size}, time:{self.__remaining_minutes}, person:({person_text})"

#################################################################

def main() -> None:
    motorcycle: Motorcycle = Motorcycle(10)

    drive_map: dict[DriveResult, str] = {
        DriveResult.BUY_TIME_FIRST: "fail: buy time first",
        DriveResult.EMPTY_MOTORCYCLE: "fail: empty motorcycle",
        DriveResult.TIME_FINISHED: "fail: time finished",
        DriveResult.OK: "success: drive completed"
    }
    enter_map: dict[EnterResult, str] = {
        EnterResult.TOO_OLD: "fail: too old to drive",
        EnterResult.BUSY: "fail: busy motorcycle", 
        EnterResult.OK: "success: person entered"
    }

    while True:
        line: str = input()
        print("$" + line)

        match line.split():
            case ["end"]:
                break
            case ["init", size]:
                motorcycle = Motorcycle(int(size))
            case ["show"]:
                print(motorcycle)
            case ["enter", name, age]:
                enter_result = motorcycle.enter(Person(name, int(age)))
                if enter_result != EnterResult.OK:
                    print(enter_map[enter_result])
            case ["leave"]:
                person: Person | None = motorcycle.leave()
                if person is None:
                    print("fail: empty motorcycle")
                else:
                    print(person)
            case ["buy", time]:
                motorcycle.buy(int(time))
            case ["drive", time]:
                result: DriveResult = motorcycle.drive(int(time))
                if result != DriveResult.OK:
                    print(drive_map[result])
            case _:
                print("arg inválido")


if __name__ == "__main__":
    main()
