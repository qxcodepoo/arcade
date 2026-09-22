from enum import Enum


ALREADY_HAS_LEAD_MSG: str = "fail: already has lead"
WRONG_THICKNESS_MSG: str = "fail: wrong thickness"
NO_LEAD_MSG: str = "fail: no lead"
INSUFFICIENT_SIZE_MSG: str = "fail: insufficient size"
INCOMPLETE_PAGE_MSG: str = "fail: incomplete page"
INVALID_COMMAND_MSG: str = "fail: invalid command"


class InsertResult(Enum):
    OK = 0
    ALREADY_HAS_LEAD = 1
    WRONG_THICKNESS = 2


class WriteResult(Enum):
    OK = 0
    NO_LEAD = 1
    INSUFFICIENT = 2
    INCOMPLETE = 3


class Lead:
    MIN_SIZE: int = 10

    def __init__(self, thickness: float, hardness: str, size: int) -> None:
        self.__thickness: float = thickness
        self.__hardness: str = hardness
        self.__size: int = size

    def get_thickness(self) -> float:
        return self.__thickness

    def get_hardness(self) -> str:
        return self.__hardness

    def get_size(self) -> int:
        return self.__size

    def get_wear_per_page(self) -> int:
        if self.__hardness == "HB":
            return 1
        if self.__hardness == "2B":
            return 2
        if self.__hardness == "4B":
            return 4
        return 6

    def consume(self, amount: int) -> bool:
        final_size: int = self.__size - amount
        if final_size < Lead.MIN_SIZE:
            self.__size = Lead.MIN_SIZE
            return False

        self.__size = final_size
        return True

    def __str__(self) -> str:
        return f"{self.__thickness:.1f}:{self.__hardness}:{self.__size}"


class Pencil:
    def __init__(self, thickness: float) -> None:
        self.__thickness: float = thickness
        self.__lead: Lead | None = None

    def get_thickness(self) -> float:
        return self.__thickness

    def has_lead(self) -> bool:
        return self.__lead is not None

    def insert(self, lead: Lead) -> InsertResult:
        if self.has_lead():
            return InsertResult.ALREADY_HAS_LEAD
        if self.__thickness != lead.get_thickness():
            return InsertResult.WRONG_THICKNESS

        self.__lead = lead
        return InsertResult.OK

    def remove(self) -> Lead | None:
        lead: Lead | None = self.__lead
        self.__lead = None
        return lead

    def write_page(self) -> WriteResult:
        if self.__lead is None:
            return WriteResult.NO_LEAD
        if self.__lead.get_size() == Lead.MIN_SIZE:
            return WriteResult.INSUFFICIENT
        if not self.__lead.consume(self.__lead.get_wear_per_page()):
            return WriteResult.INCOMPLETE

        return WriteResult.OK

    def __str__(self) -> str:
        lead_text: str = "null"
        if self.__lead is not None:
            lead_text = f"[{self.__lead}]"
        return f"thickness: {self.__thickness:.1f}, lead: {lead_text}"


def print_insert_result(result: InsertResult) -> None:
    if result == InsertResult.ALREADY_HAS_LEAD:
        print(ALREADY_HAS_LEAD_MSG)
    elif result == InsertResult.WRONG_THICKNESS:
        print(WRONG_THICKNESS_MSG)


def print_write_result(result: WriteResult) -> None:
    if result == WriteResult.NO_LEAD:
        print(NO_LEAD_MSG)
    elif result == WriteResult.INSUFFICIENT:
        print(INSUFFICIENT_SIZE_MSG)
    elif result == WriteResult.INCOMPLETE:
        print(INCOMPLETE_PAGE_MSG)


def main() -> None:
    pencil: Pencil = Pencil(0.5)

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
                lead: Lead = Lead(float(thickness), hardness, int(size))
                print_insert_result(pencil.insert(lead))
            case ["remove"]:
                if pencil.remove() is None:
                    print(NO_LEAD_MSG)
            case ["write"]:
                print_write_result(pencil.write_page())
            case _:
                print(INVALID_COMMAND_MSG)


if __name__ == "__main__":
    main()
