from enum import Enum


class DivisionResult(Enum):
    OK = "ok"
    NO_BATTERY = "no_battery"
    DIVISION_BY_ZERO = "division_by_zero"


NO_BATTERY_MSG: str = "fail: insufficient battery"
DIVISION_BY_ZERO_MSG: str = "fail: division by zero"
INVALID_COMMAND_MSG: str = "fail: invalid command"


class Calculator:
    def __init__(self, battery_max: int) -> None:
        self.battery_max: int = battery_max
        self.battery: int = 0
        self.display: float = 0.0

    def charge_battery(self, increment: int) -> None:
        if increment < 0:
            return

        self.battery += increment

        if self.battery > self.battery_max:
            self.battery = self.battery_max

    def sum(self, a: int, b: int) -> bool:
        if self.battery == 0:
            return False

        self.battery -= 1
        self.display = float(a + b)
        return True

    def division(self, num: int, den: int) -> DivisionResult:
        if self.battery == 0:
            return DivisionResult.NO_BATTERY

        self.battery -= 1

        if den == 0:
            return DivisionResult.DIVISION_BY_ZERO

        self.display = num / den
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
            case ["init", battery_max]:
                calculator = Calculator(int(battery_max))
            case ["show"]:
                print(calculator)
            case ["charge", increment]:
                calculator.charge_battery(int(increment))
            case ["sum", a, b]:
                if not calculator.sum(int(a), int(b)):
                    print(NO_BATTERY_MSG)
            case ["div", num, den]:
                match calculator.division(int(num), int(den)):
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
