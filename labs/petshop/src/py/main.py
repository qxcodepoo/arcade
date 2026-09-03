from __future__ import annotations

from dataclasses import dataclass
import sys


class ClinicError(Exception):
    """Falha em uma regra do domínio da clínica."""


@dataclass(frozen=True)
class Pet:
    id: int
    name: str
    species: str

    def __str__(self) -> str:
        return f"{self.id}:{self.name}:{self.species}"


class Client:
    def __init__(self, client_id: str, name: str) -> None:
        self._id: str = client_id
        self._name: str = name
        self._pets: dict[str, Pet] = {}

    @property
    def id(self) -> str:
        return self._id

    @property
    def name(self) -> str:
        return self._name

    def add_pet(self, pet: Pet) -> None:
        if pet.name in self._pets:
            raise ClinicError(f"animal {pet.name} ja existe")
        self._pets[pet.name] = pet

    def get_pet(self, name: str) -> Pet:
        pet: Pet | None = self._pets.get(name)
        if pet is None:
            raise ClinicError(f"animal {name} nao existe")
        return pet

    def pets(self) -> tuple[Pet, ...]:
        return tuple(self._pets.values())

    def __str__(self) -> str:
        pets: str = "".join(f"[{pet}]" for pet in self.pets())
        return f"{self.id}:{self.name}{pets}"


@dataclass(frozen=True)
class Service:
    id: str
    price: float

    def __str__(self) -> str:
        return f"{self.id}:{self.price:.1f}"


@dataclass(frozen=True)
class Sale:
    id: int
    client_id: str
    pet_name: str
    service_id: str
    price: float

    def __str__(self) -> str:
        return f"{self.id}:{self.client_id}:{self.pet_name}:{self.service_id}"


class Clinic:
    def __init__(self) -> None:
        self._clients: dict[str, Client] = {}
        self._services: dict[str, Service] = {}
        self._sales: list[Sale] = []
        self._next_pet_id: int = 1
        self._next_sale_id: int = 0

    def _get_client(self, client_id: str) -> Client:
        client: Client | None = self._clients.get(client_id)
        if client is None:
            raise ClinicError(f"cliente {client_id} nao existe")
        return client

    def _get_service(self, service_id: str) -> Service:
        service: Service | None = self._services.get(service_id)
        if service is None:
            raise ClinicError(f"servico {service_id} nao existe")
        return service

    def add_client(self, client_id: str, name: str) -> None:
        if client_id in self._clients:
            raise ClinicError(f"cliente {client_id} ja cadastrado.")
        self._clients[client_id] = Client(client_id, name)

    def get_client(self, client_id: str) -> Client:
        return self._get_client(client_id)

    def delete_client(self, client_id: str) -> None:
        self._get_client(client_id)
        del self._clients[client_id]

    def add_pet(self, client_id: str, name: str, species: str) -> None:
        client: Client = self._get_client(client_id)
        pet: Pet = Pet(self._next_pet_id, name, species)
        client.add_pet(pet)
        self._next_pet_id += 1

    def add_service(self, service_id: str, price: float) -> None:
        if service_id in self._services:
            raise ClinicError(f"servico {service_id} ja cadastrado.")
        self._services[service_id] = Service(service_id, price)

    def sell(self, client_id: str, pet_name: str, service_id: str) -> None:
        client: Client = self._get_client(client_id)
        client.get_pet(pet_name)
        service: Service = self._get_service(service_id)
        self._sales.append(
            Sale(self._next_sale_id, client_id, pet_name, service_id, service.price)
        )
        self._next_sale_id += 1

    def clients_text(self) -> str:
        return "\n".join(str(client) for client in self._clients.values())

    def services_text(self) -> str:
        return "\n".join(str(service) for service in self._services.values())

    def sales_text(self) -> str:
        return "\n".join(str(sale) for sale in self._sales)

    def balance(self) -> float:
        return sum(sale.price for sale in self._sales)


def main() -> None:
    clinic: Clinic = Clinic()
    for line in sys.stdin:
        parts: list[str] = line.split()
        print(f"${line.rstrip()}")
        try:
            match parts:
                case ["end"]:
                    return
                case ["show"]:
                    print(clinic.clients_text())
                case ["getcli", client_id]:
                    print(clinic.get_client(client_id))
                case ["addcli", client_id, *name_parts] if name_parts:
                    clinic.add_client(client_id, " ".join(name_parts))
                case ["delcli", client_id]:
                    clinic.delete_client(client_id)
                case ["addpet", client_id, pet_name, species]:
                    clinic.add_pet(client_id, pet_name, species)
                case ["addser", service_id, price]:
                    clinic.add_service(service_id, float(price))
                case ["listser"]:
                    print(clinic.services_text())
                case ["sell", client_id, pet_name, service_id]:
                    clinic.sell(client_id, pet_name, service_id)
                case ["listsell"]:
                    print(clinic.sales_text())
                case ["balance"]:
                    print(f"{clinic.balance():.1f}")
                case _:
                    print("fail: comando invalido")
        except (ClinicError, ValueError) as error:
            if isinstance(error, ClinicError):
                print(f"fail: {error}")
            else:
                print("fail: comando invalido")


if __name__ == "__main__":
    main()
