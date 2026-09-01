from enum import Enum


class DriveResult(Enum):
    OK = "ok"
    NO_PASSENGERS = "no_passengers"
    INCOMPLETE = "incomplete"
    NO_GAS = "no_gas"


CAR_FULL_MSG = "fail: limite de pessoas atingido"
CAR_EMPTY_MSG = "fail: nao ha ninguem no carro"
NO_GAS_MSG = "fail: tanque vazio"
INCOMPLETE_TRIP_MSG = "fail: viagem incompleta"
INVALID_COMMAND_MSG = "fail: comando invalido"


class Car:
    def __init__(self) -> None:
        self.pass_: int = 0
        self.pass_max: int = 2
        self.gas: int = 0
        self.gas_max: int = 100
        self.km: int = 0

    def enter(self) -> bool:
        if self.pass_ < self.pass_max:
            self.pass_ += 1
            return True

        return False

    def leave(self) -> bool:
        if self.pass_ > 0:
            self.pass_ -= 1
            return True

        return False

    def fuel(self, gas: int) -> None:
        self.gas += gas

        if self.gas > self.gas_max:
            self.gas = self.gas_max

    def drive(self, km: int) -> DriveResult:
        if self.pass_ == 0:
            return DriveResult.NO_PASSENGERS

        if self.gas == 0:
            return DriveResult.NO_GAS

        if self.gas < km:
            self.km += self.gas
            self.gas = 0
            return DriveResult.INCOMPLETE

        self.gas -= km
        self.km += km

        return DriveResult.OK

    def __str__(self) -> str:
        return f"pass: {self.pass_}, gas: {self.gas}, km: {self.km}"


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
            case ["fuel", increment]:
                car.fuel(int(increment))
            case ["drive", distance]:
                match car.drive(int(distance)):
                    case DriveResult.NO_PASSENGERS:
                        print(CAR_EMPTY_MSG)
                    case DriveResult.NO_GAS:
                        print(NO_GAS_MSG)
                    case DriveResult.INCOMPLETE:
                        print(INCOMPLETE_TRIP_MSG)
                    case DriveResult.OK:
                        pass
            case _:
                print(INVALID_COMMAND_MSG)


if __name__ == "__main__":
    main()
