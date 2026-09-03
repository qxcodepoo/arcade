from __future__ import annotations

from abc import ABC, abstractmethod
from dataclasses import dataclass
from typing import TextIO


class PayrollError(Exception):
    pass


class DailyLimitError(PayrollError):
    pass


class DailyNotAllowedError(PayrollError):
    pass


class Employee(ABC):
    def __init__(self, name: str) -> None:
        self.name: str = name
        self.daily_count: int = 0

    @abstractmethod
    def base_salary(self) -> float:
        pass

    @abstractmethod
    def type_code(self) -> str:
        pass

    @abstractmethod
    def daily_limit(self) -> int:
        pass

    def add_daily(self) -> None:
        limit = self.daily_limit()
        if limit == 0:
            raise DailyNotAllowedError("fail: terc nao pode receber diaria")
        if self.daily_count >= limit:
            raise DailyLimitError("fail: limite de diarias atingido")
        self.daily_count += 1

    def salary(self, bonus: float, total_employees: int) -> float:
        shared_bonus = bonus / total_employees if total_employees else 0.0
        return self.base_salary() + self.daily_count * 100.0 + shared_bonus

    @abstractmethod
    def details(self) -> str:
        pass


class Professor(Employee):
    SALARIES: dict[str, float] = {"A": 3000.0, "B": 5000.0, "C": 7000.0, "D": 9000.0, "E": 11000.0}

    def __init__(self, name: str, level: str) -> None:
        super().__init__(name)
        self.level: str = level

    def base_salary(self) -> float:
        return self.SALARIES[self.level]

    def type_code(self) -> str:
        return "prof"

    def daily_limit(self) -> int:
        return 2

    def details(self) -> str:
        return f"prof:{self.name}:{self.level}"


class Staff(Employee):
    def __init__(self, name: str, level: int) -> None:
        super().__init__(name)
        self.level: int = level

    def base_salary(self) -> float:
        return 3000.0 + 300.0 * self.level

    def type_code(self) -> str:
        return "sta"

    def daily_limit(self) -> int:
        return 1

    def details(self) -> str:
        return f"sta:{self.name}:{self.level}"


class Contractor(Employee):
    def __init__(self, name: str, hours: int, unhealthy: bool) -> None:
        super().__init__(name)
        self.hours: int = hours
        self.unhealthy: bool = unhealthy

    def base_salary(self) -> float:
        return self.hours * 4.0 + (500.0 if self.unhealthy else 0.0)

    def type_code(self) -> str:
        return "ter"

    def daily_limit(self) -> int:
        return 0

    def details(self) -> str:
        status = "sim" if self.unhealthy else "nao"
        return f"ter:{self.name}:{self.hours}:{status}"


class Payroll:
    def __init__(self) -> None:
        self.employees: dict[str, Employee] = {}
        self.bonus: float = 0.0

    def add(self, employee: Employee) -> None:
        self.employees.setdefault(employee.name, employee)

    def remove(self, name: str) -> None:
        self.employees.pop(name, None)

    def add_daily(self, name: str) -> None:
        self.employees[name].add_daily()

    def set_bonus(self, value: float) -> None:
        self.bonus = value

    def show(self, name: str | None = None) -> str:
        employees = [self.employees[name]] if name is not None else list(self.employees.values())
        return "\n".join(f"{employee.details()}:{employee.salary(self.bonus, len(self.employees)):.0f}" for employee in employees)


def main(input_stream: TextIO, output_stream: TextIO) -> None:
    payroll = Payroll()
    for line in input_stream:
        try:
            match line.split():
                case ["addProf", name, level]:
                    payroll.add(Professor(name, level))
                case ["addSta", name, level]:
                    payroll.add(Staff(name, int(level)))
                case ["addTer", name, hours, unhealthy]:
                    payroll.add(Contractor(name, int(hours), unhealthy == "sim"))
                case ["rm", name]:
                    payroll.remove(name)
                case ["addDiaria", name]:
                    payroll.add_daily(name)
                case ["setBonus", value]:
                    payroll.set_bonus(float(value))
                case ["show", name]:
                    print(payroll.show(name), file=output_stream)
                case ["showAll"]:
                    print(payroll.show(), file=output_stream)
                case ["end"]:
                    break
        except (KeyError, ValueError, PayrollError) as error:
            print(str(error) or "fail: funcionario nao encontrado", file=output_stream)


if __name__ == "__main__":
    import sys

    main(sys.stdin, sys.stdout)
