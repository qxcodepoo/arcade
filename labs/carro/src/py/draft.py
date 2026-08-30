from enum import Enum


class Result(Enum):
    OK = "ok"
    CAR_FULL = "car_full"
    CAR_EMPTY = "car_empty"
    INCOMPLETE = "incomplete"
    NO_GAS = "no_gas"


class Car:
    def __init__(self) -> None:
        self.pass_: int = 0
        self.pass_max: int = 2
        self.gas: int = 0
        self.gas_max: int = 100
        self.km: int = 0

    def enter(self) -> Result:
        if self.pass_ < self.pass_max:
            self.pass_ += 1
            return Result.OK

        return Result.CAR_FULL

    def leave(self) -> Result:
        if self.pass_ > 0:
            self.pass_ -= 1
            return Result.OK

        return Result.CAR_EMPTY

    def fuel(self, gas: int) -> None:
        self.gas += gas

        if self.gas > self.gas_max:
            self.gas = self.gas_max

    def drive(self, km: int) -> Result:
        if self.pass_ == 0:
            return Result.CAR_EMPTY

        if self.gas == 0:
            return Result.NO_GAS

        if self.gas < km:
            self.km += self.gas
            self.gas = 0
            return Result.INCOMPLETE

        self.gas -= km
        self.km += km

        return Result.OK

    def __str__(self) -> str:
        return f"pass: {self.pass_}, gas: {self.gas}, km: {self.km}"


def print_result(result: Result) -> None:
    if result == Result.OK:
        return
    if result == Result.CAR_FULL:
        print("fail: limite de pessoas atingido")
    elif result == Result.CAR_EMPTY:
        print("fail: nao ha ninguem no carro")
    elif result == Result.NO_GAS:
        print("fail: tanque vazio")
    elif result == Result.INCOMPLETE:
        print("fail: viagem incompleta")


def main() -> None:
    car: Car = Car()

    while True:
        line: str = input()
        print("$" + line)

        par: list[str] = line.split()
        cmd: str = par[0]

        if cmd == "end":
            break

        elif cmd == "show":
            print(car)

        elif cmd == "enter":
            print_result(car.enter())

        elif cmd == "leave":
            print_result(car.leave())

        elif cmd == "fuel":
            increment: int = int(par[1])
            car.fuel(increment)

        elif cmd == "drive":
            distance: int = int(par[1])
            print_result(car.drive(distance))

        else:
            print("fail: comando invalido")


if __name__ == "__main__":
    main()