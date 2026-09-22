import enum

## Domínio

class DriveResult(enum.Enum):
    OK = enum.auto()
    NO_PASSENGERS = enum.auto()
    INCOMPLETE = enum.auto()
    NO_GAS = enum.auto()

class Car:
    def __init__(self) -> None:
        self.passenger_count: int = 0
        self.max_passengers: int = 2
        self.fuel_amount: int = 0
        self.max_fuel: int = 100
        self.distance_traveled: int = 0

    def enter(self) -> bool:
        if self.passenger_count < self.max_passengers:
            self.passenger_count += 1
            return True

        return False

    def leave(self) -> bool:
        if self.passenger_count > 0:
            self.passenger_count -= 1
            return True

        return False

    def refuel(self, liters: int) -> None:
        self.fuel_amount += liters

        if self.fuel_amount > self.max_fuel:
            self.fuel_amount = self.max_fuel

    def drive(self, distance: int) -> DriveResult:
        if self.passenger_count == 0:
            return DriveResult.NO_PASSENGERS

        if self.fuel_amount == 0:
            return DriveResult.NO_GAS

        if self.fuel_amount < distance:
            self.distance_traveled += self.fuel_amount
            self.fuel_amount = 0
            return DriveResult.INCOMPLETE

        self.fuel_amount -= distance
        self.distance_traveled += distance
        return DriveResult.OK

    def __str__(self) -> str:
        return f"pass: {self.passenger_count}, gas: {self.fuel_amount}, km: {self.distance_traveled}"


# INTERFACE

CAR_FULL_MSG: str = "fail: car is full"
CAR_EMPTY_MSG: str = "fail: car is empty"
INVALID_COMMAND_MSG: str = "fail: invalid command"

def drive_result_to_message(result: DriveResult) -> str:
    return {
        DriveResult.OK: "ok: drove successfully",
        DriveResult.NO_PASSENGERS: "fail: car is empty",
        DriveResult.INCOMPLETE: "fail: incomplete trip",
        DriveResult.NO_GAS: "fail: empty tank",
    }[result]

def main() -> None:
    car: Car = Car()

    while True:
        line: str = input()
        print("$" + line)

        match line.split():
            case ["end"]:
                break
            case ["show"]:
                print(car)
            case ["enter"]:
                if not car.enter():
                    print(CAR_FULL_MSG)
            case ["leave"]:
                if not car.leave():
                    print(CAR_EMPTY_MSG)
            case ["refuel", liters]:
                car.refuel(int(liters))
            case ["drive", distance]:
                result = car.drive(int(distance))
                if result != DriveResult.OK:
                    print(drive_result_to_message(result))
            case _:
                print(INVALID_COMMAND_MSG)


if __name__ == "__main__":
    main()
