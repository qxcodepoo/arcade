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

    def get_name(self) -> str:
        return self.__name

    def get_money(self) -> int:
        return self.__money

    def pay(self, amount: int) -> int:
        paid: int = min(self.__money, amount)
        self.__money -= paid
        return paid

    def add_money(self, amount: int) -> None:
        self.__money += amount

    def __str__(self) -> str:
        return f"{self.__name}:{self.__money}"


class Uber:
    def __init__(self) -> None:
        self.__driver: Person | None = None
        self.__passenger: Person | None = None
        self.__trip_cost: int = 0

    def set_driver(self, driver: Person) -> bool:
        if self.__driver is not None:
            return False
        self.__driver = driver
        return True

    def set_passenger(self, passenger: Person) -> SetPassengerResult:
        if self.__driver is None:
            return SetPassengerResult.DRIVER_NOT_SET
        if self.__passenger is not None:
            return SetPassengerResult.ALREADY_SET
        self.__passenger = passenger
        self.__trip_cost = 0
        return SetPassengerResult.OK

    def drive(self, distance: int) -> bool:
        if self.__driver is None:
            return False
        if self.__passenger is not None:
            self.__trip_cost += distance
        return True

    def leave(self) -> tuple[Person | None, LeaveResult]:
        if self.__driver is None:
            return (None, LeaveResult.DRIVER_NOT_SET)
        if self.__passenger is None:
            return (None, LeaveResult.PASSENGER_NOT_SET)

        passenger: Person = self.__passenger
        trip_cost: int = self.__trip_cost
        paid: int = passenger.pay(trip_cost)
        self.__driver.add_money(trip_cost)
        self.__passenger = None
        self.__trip_cost = 0
        result: LeaveResult = LeaveResult.OK
        if paid < trip_cost:
            result = LeaveResult.INSUFFICIENT_MONEY
        return (passenger, result)

    def __str__(self) -> str:
        driver_text: str = "None"
        if self.__driver is not None:
            driver_text = str(self.__driver)
        passenger_text: str = "None"
        if self.__passenger is not None:
            passenger_text = str(self.__passenger)
        return f"Cost: {self.__trip_cost}, Driver: {driver_text}, Passenger: {passenger_text}"


def print_set_driver_result(result: bool) -> None:
    if not result:
        print(DRIVER_ALREADY_SET_MSG)


def print_set_passenger_result(result: SetPassengerResult) -> None:
    if result == SetPassengerResult.DRIVER_NOT_SET:
        print(DRIVER_NOT_SET_MSG)
    elif result == SetPassengerResult.ALREADY_SET:
        print(PASSENGER_ALREADY_SET_MSG)

def print_drive_result(result: bool) -> None:
    if not result:
        print(DRIVER_NOT_SET_MSG)


def print_leave_result(result: tuple[Person | None, LeaveResult]) -> None:
    passenger: Person | None = result[0]
    leave_result: LeaveResult = result[1]
    if leave_result == LeaveResult.DRIVER_NOT_SET:
        print(DRIVER_NOT_SET_MSG)
    elif leave_result == LeaveResult.PASSENGER_NOT_SET:
        print(PASSENGER_NOT_SET_MSG)
    elif leave_result == LeaveResult.INSUFFICIENT_MONEY:
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
                driver_result: bool = uber.set_driver(Person(name, int(money)))
                print_set_driver_result(driver_result)
            case ["setPass", name, money]:
                passenger_result: SetPassengerResult = uber.set_passenger(Person(name, int(money)))
                print_set_passenger_result(passenger_result)
            case ["drive", distance]:
                drive_result: bool = uber.drive(int(distance))
                print_drive_result(drive_result)
            case ["leavePass"]:
                print_leave_result(uber.leave())
            case _:
                print(INVALID_COMMAND_MSG)


if __name__ == "__main__":
    main()
