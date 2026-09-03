from __future__ import annotations
from dataclasses import dataclass

@dataclass
class Passenger:
    identifier: str

class Train:
    def __init__(self, max_cars: int) -> None:
        self.max_cars=max_cars; self.cars: list[list[str|None]]=[]; self.registered:set[str]=set(); self.history:list[str]=[]
    def add_car(self, seats: int) -> None:
        if len(self.cars)>=self.max_cars: raise ValueError("fail: limite de vagões atingido")
        self.cars.append([None]*seats)
    def board(self, passenger: Passenger) -> None:
        self.registered.add(passenger.identifier)
        if any(passenger.identifier in car for car in self.cars): raise ValueError(f"fail: {passenger.identifier} já está no trem")
        for car in self.cars:
            for i, seat in enumerate(car):
                if seat is None: car[i]=passenger.identifier; self.history.append(passenger.identifier+" in"); return
        raise ValueError("fail: trem lotado")
    def leave(self, identifier: str) -> None:
        for car in self.cars:
            for i, seat in enumerate(car):
                if seat==identifier: car[i]=None; self.history.append(identifier+" out"); return
        raise ValueError(f"fail: {identifier} nao esta no trem")
    def __str__(self) -> str:
        return "Trem " + "".join("[ " + " ".join(x or "-" for x in car) + " ]" for car in self.cars)
