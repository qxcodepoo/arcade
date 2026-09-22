from enum import Enum


class DivisionResult(Enum):
    OK = "ok"
    NO_BATTERY = "no_battery"
    DIVISION_BY_ZERO = "division_by_zero"


NO_BATTERY_MSG: str = "fail: insufficient battery"
DIVISION_BY_ZERO_MSG: str = "fail: division by zero"
INVALID_COMMAND_MSG: str = "fail: invalid command"


class Calculator:
    def __init__(self, max_battery: int) -> None:
        self.max_battery: int = max_battery
        self.battery: int = 0
        self.display: float = 0.0

    def charge(self, amount: int) -> None:
        if amount < 0:
            return

        self.battery += amount

        if self.battery > self.max_battery:
            self.battery = self.max_battery

    def add(self, left: int, right: int) -> bool:
        if self.battery == 0:
            return False

        self.battery -= 1
        self.display = float(left + right)
        return True

    def divide(self, numerator: int, denominator: int) -> DivisionResult:
        if self.battery == 0:
            return DivisionResult.NO_BATTERY

        self.battery -= 1

        if denominator == 0:
            return DivisionResult.DIVISION_BY_ZERO

        self.display = numerator / denominator
        return DivisionResult.OK

    def __str__(self) -> str:
        return f"display = {self.display:.2f}, battery = {self.battery}"


def main() -> None:
    calculator: Calculator = Calculator(0)

    while True:
        line: str = input()
        print("$" + line)

        match line.split():
            case ["end"]:
                break
            case ["init", max_battery]:
                calculator = Calculator(int(max_battery))
            case ["show"]:
                print(calculator)
            case ["charge", amount]:
                calculator.charge(int(amount))
            case ["sum", left, right]:
                if not calculator.add(int(left), int(right)):
                    print(NO_BATTERY_MSG)
            case ["div", numerator, denominator]:
                match calculator.divide(int(numerator), int(denominator)):
                    case DivisionResult.NO_BATTERY:
                        print(NO_BATTERY_MSG)
                    case DivisionResult.DIVISION_BY_ZERO:
                        print(DIVISION_BY_ZERO_MSG)
                    case DivisionResult.OK:
                        pass
            case _:
                print(INVALID_COMMAND_MSG)


if __name__ == "__main__":
    main()
