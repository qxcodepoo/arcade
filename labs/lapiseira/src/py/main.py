from enum import Enum


INVALID_COMMAND_MSG: str = "fail: comando invalido"
WRONG_THICKNESS_MSG: str = "fail: calibre incompatível"
TIP_OCCUPIED_MSG: str = "fail: ja existe grafite no bico"
BARREL_EMPTY_MSG: str = "fail: nao existe grafite no barril"
NO_LEAD_MSG: str = "fail: nao existe grafite no bico"
INSUFFICIENT_SIZE_MSG: str = "fail: tamanho insuficiente"
INCOMPLETE_PAGE_MSG: str = "fail: folha incompleta"


class InsertResult(Enum):
    OK = 0
    WRONG_THICKNESS = 1


class PullResult(Enum):
    OK = 0
    TIP_OCCUPIED = 1
    BARREL_EMPTY = 2


class WriteResult(Enum):
    OK = 0
    NO_LEAD = 1
    INSUFFICIENT = 2
    INCOMPLETE = 3


class Lead:
    def __init__(self, thickness: float, hardness: str, size: int) -> None:
        self.__thickness: float = thickness
        self.__hardness: str = hardness
        self.__size: int = size

    def getWearPerPage(self) -> int:
        if self.__hardness == "HB":
            return 1
        if self.__hardness == "2B":
            return 2
        if self.__hardness == "4B":
            return 4
        return 6

    def getSize(self) -> int:
        return self.__size

    def getThickness(self) -> float:
        return self.__thickness

    def consume(self, amount: int) -> bool:
        final_size: int = self.__size - amount
        if final_size < 10:
            self.__size = 10
            return False
        self.__size = final_size
        return True

    def __str__(self) -> str:
        return f"{self.__thickness:.1f}:{self.__hardness}:{self.__size}"


class Pencil:
    def __init__(self, thickness: float) -> None:
        self.__thickness: float = thickness
        self.__tip: Lead | None = None
        self.__barrel: list[Lead] = []

    def insert(self, lead: Lead) -> InsertResult:
        if self.__thickness != lead.getThickness():
            return InsertResult.WRONG_THICKNESS
        self.__barrel.append(lead)
        return InsertResult.OK

    def remove(self) -> Lead | None:
        lead: Lead | None = self.__tip
        self.__tip = None
        return lead

    def pull(self) -> PullResult:
        if self.__tip is not None:
            return PullResult.TIP_OCCUPIED
        if not self.__barrel:
            return PullResult.BARREL_EMPTY
        self.__tip = self.__barrel.pop(0)
        return PullResult.OK

    def writePage(self) -> WriteResult:
        if self.__tip is None:
            return WriteResult.NO_LEAD
        if self.__tip.getSize() == 10:
            return WriteResult.INSUFFICIENT
        if not self.__tip.consume(self.__tip.getWearPerPage()):
            return WriteResult.INCOMPLETE
        return WriteResult.OK

    def __str__(self) -> str:
        tip: str = "[]" if self.__tip is None else f"[{self.__tip}]"
        barrel: str = "".join(f"[{lead}]" for lead in self.__barrel)
        return f"calibre: {self.__thickness:.1f}, bico: {tip}, tambor: <{barrel}>"


def print_insert_result(result: InsertResult) -> None:
    if result == InsertResult.WRONG_THICKNESS:
        print(WRONG_THICKNESS_MSG)


def print_pull_result(result: PullResult) -> None:
    if result == PullResult.TIP_OCCUPIED:
        print(TIP_OCCUPIED_MSG)
    elif result == PullResult.BARREL_EMPTY:
        print(BARREL_EMPTY_MSG)


def print_write_result(result: WriteResult) -> None:
    if result == WriteResult.NO_LEAD:
        print(NO_LEAD_MSG)
    elif result == WriteResult.INSUFFICIENT:
        print(INSUFFICIENT_SIZE_MSG)
    elif result == WriteResult.INCOMPLETE:
        print(INCOMPLETE_PAGE_MSG)


def main() -> None:
    pencil: Pencil = Pencil(0.0)

    while True:
        line: str = input()
        print("$" + line)

        match line.split():
            case ["end"]:
                break
            case ["init", thickness]:
                pencil = Pencil(float(thickness))
            case ["show"]:
                print(pencil)
            case ["insert", thickness, hardness, size]:
                result: InsertResult = pencil.insert(
                    Lead(float(thickness), hardness, int(size))
                )
                print_insert_result(result)
            case ["pull"]:
                print_pull_result(pencil.pull())
            case ["remove"]:
                if pencil.remove() is None:
                    print(NO_LEAD_MSG)
            case ["write"]:
                print_write_result(pencil.writePage())
            case _:
                print(INVALID_COMMAND_MSG)


if __name__ == "__main__":
    main()
