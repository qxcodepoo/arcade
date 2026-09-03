from enum import Enum


INVALID_COMMAND_MSG: str = "fail: comando invalido"
INVALID_INDEX_MSG: str = "fail: cadeira nao existe"
OCCUPIED_SEAT_MSG: str = "fail: cadeira ja esta ocupada"
DUPLICATE_CLIENT_MSG: str = "fail: cliente ja esta no cinema"
CLIENT_NOT_FOUND_MSG: str = "fail: cliente nao esta no cinema"


class ReserveResult(Enum):
    OK = 0
    INVALID_INDEX = 1
    OCCUPIED = 2
    DUPLICATE_CLIENT = 3


class CancelResult(Enum):
    OK = 0
    CLIENT_NOT_FOUND = 1


class Client:
    def __init__(self, client_id: str, phone: str) -> None:
        self.__id: str = client_id
        self.__phone: str = phone

    def getId(self) -> str:
        return self.__id

    def setId(self, client_id: str) -> None:
        self.__id = client_id

    def getPhone(self) -> str:
        return self.__phone

    def setPhone(self, phone: str) -> None:
        self.__phone = phone

    def __str__(self) -> str:
        return f"{self.__id}:{self.__phone}"


class Theater:
    def __init__(self, capacity: int) -> None:
        self.__seats: list[Client | None] = [None] * capacity

    def __verify_index(self, index: int) -> bool:
        return 0 <= index < len(self.__seats)

    def __search(self, client_id: str) -> int:
        for index, client in enumerate(self.__seats):
            if client is not None and client.getId() == client_id:
                return index
        return -1

    def reserve(self, client_id: str, phone: str, index: int) -> ReserveResult:
        if not self.__verify_index(index):
            return ReserveResult.INVALID_INDEX
        if self.__seats[index] is not None:
            return ReserveResult.OCCUPIED
        if self.__search(client_id) != -1:
            return ReserveResult.DUPLICATE_CLIENT
        self.__seats[index] = Client(client_id, phone)
        return ReserveResult.OK

    def cancel(self, client_id: str) -> CancelResult:
        index: int = self.__search(client_id)
        if index == -1:
            return CancelResult.CLIENT_NOT_FOUND
        self.__seats[index] = None
        return CancelResult.OK

    def getSeats(self) -> list[Client | None]:
        return self.__seats.copy()

    def __str__(self) -> str:
        seats: str = " ".join("-" if client is None else str(client) for client in self.__seats)
        return f"[{seats}]"


def print_reserve_result(result: ReserveResult) -> None:
    if result == ReserveResult.INVALID_INDEX:
        print(INVALID_INDEX_MSG)
    elif result == ReserveResult.OCCUPIED:
        print(OCCUPIED_SEAT_MSG)
    elif result == ReserveResult.DUPLICATE_CLIENT:
        print(DUPLICATE_CLIENT_MSG)


def print_cancel_result(result: CancelResult) -> None:
    if result == CancelResult.CLIENT_NOT_FOUND:
        print(CLIENT_NOT_FOUND_MSG)


def main() -> None:
    theater: Theater = Theater(0)

    while True:
        line: str = input()
        print("$" + line)

        match line.split():
            case ["end"]:
                break
            case ["show"]:
                print(theater)
            case ["init", capacity]:
                theater = Theater(int(capacity))
            case ["reserve", client_id, phone, index]:
                result: ReserveResult = theater.reserve(client_id, phone, int(index))
                print_reserve_result(result)
            case ["cancel", client_id]:
                print_cancel_result(theater.cancel(client_id))
            case _:
                print(INVALID_COMMAND_MSG)


if __name__ == "__main__":
    main()
