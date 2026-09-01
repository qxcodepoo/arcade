from enum import Enum


EMPTY_PERSON_TEXT: str = "empty"
BUSY_MOTORCYCLE_MSG: str = "fail: busy motorcycle"
EMPTY_MOTORCYCLE_MSG: str = "fail: empty motorcycle"
BUY_TIME_FIRST_MSG: str = "fail: buy time first"
TOO_OLD_TO_DRIVE_MSG: str = "fail: too old to drive"
TIME_FINISHED_MSG: str = "fail: time finished"
INVALID_COMMAND_MSG: str = "fail: invalid command"


class DriveResult(Enum):
    OK = 0
    BUY_TIME_FIRST = 1
    EMPTY_MOTORCYCLE = 2
    TOO_OLD_TO_DRIVE = 3
    TIME_FINISHED = 4


class Person:
    def __init__(self, name: str, age: int) -> None:
        self.__name: str = name
        self.__age: int = age

    def getName(self) -> str:
        return self.__name

    def getAge(self) -> int:
        return self.__age

    def canDrive(self, maxAge: int) -> bool:
        return self.__age <= maxAge

    def __str__(self) -> str:
        return f"{self.__name}:{self.__age}"


class Motorcycle:
    def __init__(self, size: int) -> None:
        self.__person: Person | None = None
        self.__size: int = size
        self.__time: int = 0

    def getSize(self) -> int:
        return self.__size

    def getTime(self) -> int:
        return self.__time

    def getPerson(self) -> Person | None:
        return self.__person

    def enter(self, person: Person) -> bool:
        if self.__person is not None:
            return False

        self.__person = person
        return True

    def leave(self) -> Person | None:
        if self.__person is None:
            return None

        person: Person = self.__person
        self.__person = None
        return person

    def buy(self, time: int) -> None:
        self.__time += time

    def drive(self, time: int) -> DriveResult:
        if self.__time == 0:
            return DriveResult.BUY_TIME_FIRST
        if self.__person is None:
            return DriveResult.EMPTY_MOTORCYCLE
        if not self.__person.canDrive(self.__size):
            return DriveResult.TOO_OLD_TO_DRIVE
        if self.__time < time:
            self.__time = 0
            return DriveResult.TIME_FINISHED

        self.__time -= time
        return DriveResult.OK

    def __str__(self) -> str:
        person_text: str = EMPTY_PERSON_TEXT
        if self.__person is not None:
            person_text = str(self.__person)

        return f"size:{self.__size}, time:{self.__time}, person:({person_text})"


def main() -> None:
    motorcycle: Motorcycle = Motorcycle(10)

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
                if not motorcycle.enter(Person(name, int(age))):
                    print(BUSY_MOTORCYCLE_MSG)
            case ["leave"]:
                person: Person | None = motorcycle.leave()
                if person is None:
                    print(EMPTY_MOTORCYCLE_MSG)
                else:
                    print(person)
            case ["buy", time]:
                motorcycle.buy(int(time))
            case ["drive", time]:
                result: DriveResult = motorcycle.drive(int(time))
                if result == DriveResult.BUY_TIME_FIRST:
                    print(BUY_TIME_FIRST_MSG)
                elif result == DriveResult.EMPTY_MOTORCYCLE:
                    print(EMPTY_MOTORCYCLE_MSG)
                elif result == DriveResult.TOO_OLD_TO_DRIVE:
                    print(TOO_OLD_TO_DRIVE_MSG)
                elif result == DriveResult.TIME_FINISHED:
                    print(TIME_FINISHED_MSG)
            case _:
                print(INVALID_COMMAND_MSG)


if __name__ == "__main__":
    main()
