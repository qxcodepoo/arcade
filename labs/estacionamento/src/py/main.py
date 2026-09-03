from __future__ import annotations

from abc import ABC, abstractmethod
from dataclasses import dataclass
from typing import TextIO


class ParkingError(Exception):
    pass


class VehicleAlreadyParkedError(ParkingError):
    pass


class VehicleNotFoundError(ParkingError):
    pass


class InvalidTimeError(ParkingError):
    pass


class InvalidVehicleTypeError(ParkingError):
    pass


@dataclass
class Vehicle(ABC):
    identifier: str
    entry_time: int = 0

    @property
    @abstractmethod
    def kind(self) -> str:
        """Return the vehicle label used by the receipt."""

    @abstractmethod
    def price_for(self, minutes: int) -> float:
        """Calculate the price for the time spent in the parking lot."""

    def __str__(self) -> str:
        kind = f"{self.kind:>10}".replace(" ", "_")
        identifier = f"{self.identifier:>10}".replace(" ", "_")
        return f"{kind} : {identifier} : {self.entry_time}"


@dataclass
class Bike(Vehicle):
    @property
    def kind(self) -> str:
        return "Bike"

    def price_for(self, minutes: int) -> float:
        return 3.0


@dataclass
class Motorcycle(Vehicle):
    @property
    def kind(self) -> str:
        return "Moto"

    def price_for(self, minutes: int) -> float:
        return minutes / 20.0


@dataclass
class Car(Vehicle):
    @property
    def kind(self) -> str:
        return "Carro"

    def price_for(self, minutes: int) -> float:
        return max(5.0, minutes / 10.0)


class ParkingLot:
    def __init__(self) -> None:
        self.current_time: int = 0
        self._vehicles: dict[str, Vehicle] = {}

    def advance_time(self, minutes: int) -> None:
        if minutes < 0:
            raise InvalidTimeError
        self.current_time += minutes

    def park(self, vehicle: Vehicle) -> None:
        if vehicle.identifier in self._vehicles:
            raise VehicleAlreadyParkedError
        vehicle.entry_time = self.current_time
        self._vehicles[vehicle.identifier] = vehicle

    def pay(self, identifier: str) -> str:
        vehicle = self._vehicles.get(identifier)
        if vehicle is None:
            raise VehicleNotFoundError
        elapsed = self.current_time - vehicle.entry_time
        price = vehicle.price_for(elapsed)
        del self._vehicles[identifier]
        return (
            f"{vehicle.kind} chegou {vehicle.entry_time} "
            f"saiu {self.current_time}. Pagar R$ {price:.2f}"
        )

    def __str__(self) -> str:
        vehicles = [str(vehicle) for vehicle in self._vehicles.values()]
        vehicles.append(f"Hora atual: {self.current_time}")
        return "\n".join(vehicles)


def create_vehicle(kind: str, identifier: str) -> Vehicle:
    match kind:
        case "bike":
            return Bike(identifier)
        case "moto":
            return Motorcycle(identifier)
        case "carro":
            return Car(identifier)
        case _:
            raise InvalidVehicleTypeError


def main(input_stream: TextIO, output_stream: TextIO) -> None:
    parking = ParkingLot()
    for line in input_stream:
        match line.split():
            case ["show"]:
                print(parking, file=output_stream)
            case ["init"]:
                parking = ParkingLot()
            case ["tempo", minutes]:
                try:
                    parking.advance_time(int(minutes))
                except (ValueError, InvalidTimeError):
                    print("fail: invalid time", file=output_stream)
            case ["estacionar", kind, identifier]:
                try:
                    parking.park(create_vehicle(kind, identifier))
                except (InvalidVehicleTypeError, VehicleAlreadyParkedError):
                    print("fail: vehicle already parked or invalid type", file=output_stream)
            case ["pagar", identifier]:
                try:
                    print(parking.pay(identifier), file=output_stream)
                except VehicleNotFoundError:
                    print("fail: vehicle not found", file=output_stream)
            case ["end"]:
                break


if __name__ == "__main__":
    import sys

    main(sys.stdin, sys.stdout)
