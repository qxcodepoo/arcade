from enum import Enum


DRIVER_ALREADY_SET_MSG: str = "fail: driver is already set"
DRIVER_NOT_SET_MSG: str = "fail: driver is not set"
PASSENGER_ALREADY_SET_MSG: str = "fail: passenger is already set"
PASSENGER_NOT_SET_MSG: str = "fail: passenger is not set"
PASSENGER_CANNOT_PAY_MSG: str = "fail: passenger does not have enough money"
INVALID_COMMAND_MSG: str = "fail: invalid command"


class SetPassengerResult(Enum):
    OK = 0
    DRIVER_NOT_SET = 1
    ALREADY_SET = 2


class LeaveResult(Enum):
    OK = 0
    DRIVER_NOT_SET = 1
    PASSENGER_NOT_SET = 2
    INSUFFICIENT_MONEY = 3


class Person:
    def __init__(self, name: str, money: int) -> None:
        self.__name: str = name
        self.__money: int = money

    def getName(self) -> str:
        return self.__name

    def getMoney(self) -> int:
        return self.__money

    def pay(self, amount: int) -> int:
        paid: int = min(self.__money, amount)
        self.__money -= paid
        return paid

    def addMoney(self, amount: int) -> None:
        self.__money += amount

    def __str__(self) -> str:
        return f"{self.__name}:{self.__money}"


class Uber:
    def __init__(self) -> None:
        self.__driver: Person | None = None
        self.__passenger: Person | None = None
        self.__runCost: int = 0

    def setDriver(self, driver: Person) -> bool:
        if self.__driver is not None:
            return False
        self.__driver = driver
        return True

    def setPassenger(self, passenger: Person) -> SetPassengerResult:
        if self.__driver is None:
            return SetPassengerResult.DRIVER_NOT_SET
        if self.__passenger is not None:
            return SetPassengerResult.ALREADY_SET
        self.__passenger = passenger
        self.__runCost = 0
        return SetPassengerResult.OK

    def drive(self, distance: int) -> bool:
        if self.__driver is None:
            return False
        if self.__passenger is not None:
            self.__runCost += distance
        return True

    def leave(self) -> tuple[Person | None, LeaveResult]:
        if self.__driver is None:
            return (None, LeaveResult.DRIVER_NOT_SET)
        if self.__passenger is None:
            return (None, LeaveResult.PASSENGER_NOT_SET)

        passenger: Person = self.__passenger
        runCost: int = self.__runCost
        paid: int = passenger.pay(runCost)
        self.__driver.addMoney(runCost)
        self.__passenger = None
        self.__runCost = 0
        result: LeaveResult = LeaveResult.OK
        if paid < runCost:
            result = LeaveResult.INSUFFICIENT_MONEY
        return (passenger, result)

    def __str__(self) -> str:
        driverText: str = "None"
        if self.__driver is not None:
            driverText = str(self.__driver)
        passengerText: str = "None"
        if self.__passenger is not None:
            passengerText = str(self.__passenger)
        return f"Cost: {self.__runCost}, Driver: {driverText}, Passenger: {passengerText}"


def printSetDriverResult(result: bool) -> None:
    if not result:
        print(DRIVER_ALREADY_SET_MSG)


def printSetPassengerResult(result: SetPassengerResult) -> None:
    if result == SetPassengerResult.DRIVER_NOT_SET:
        print(DRIVER_NOT_SET_MSG)
    elif result == SetPassengerResult.ALREADY_SET:
        print(PASSENGER_ALREADY_SET_MSG)

def printDriveResult(result: bool) -> None:
    if not result:
        print(DRIVER_NOT_SET_MSG)


def printLeaveResult(result: tuple[Person | None, LeaveResult]) -> None:
    passenger: Person | None = result[0]
    leaveResult: LeaveResult = result[1]
    if leaveResult == LeaveResult.DRIVER_NOT_SET:
        print(DRIVER_NOT_SET_MSG)
    elif leaveResult == LeaveResult.PASSENGER_NOT_SET:
        print(PASSENGER_NOT_SET_MSG)
    elif leaveResult == LeaveResult.INSUFFICIENT_MONEY:
        print(PASSENGER_CANNOT_PAY_MSG)

    if passenger is not None:
        print(f"{passenger} left")


def main() -> None:
    uber: Uber = Uber()

    while True:
        line: str = input()
        print("$" + line)

        match line.split():
            case ["end"]:
                break
            case ["show"]:
                print(uber)
            case ["setDriver", name, money]:
                driverResult: bool = uber.setDriver(Person(name, int(money)))
                printSetDriverResult(driverResult)
            case ["setPass", name, money]:
                passengerResult: SetPassengerResult = uber.setPassenger(Person(name, int(money)))
                printSetPassengerResult(passengerResult)
            case ["drive", distance]:
                driveResult: bool = uber.drive(int(distance))
                printDriveResult(driveResult)
            case ["leavePass"]:
                printLeaveResult(uber.leave())
            case _:
                print(INVALID_COMMAND_MSG)


if __name__ == "__main__":
    main()
