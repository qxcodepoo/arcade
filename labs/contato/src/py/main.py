from dataclasses import dataclass
from typing import ClassVar


INVALID_NUMBER_MSG: str = "fail: invalid number"
INVALID_INDEX_MSG: str = "fail: invalid index"
INVALID_COMMAND_MSG: str = "fail: invalid command"


@dataclass
class Phone:
    label: str
    number: str

    VALID_CHARS: ClassVar[str] = "0123456789()-."

    def is_valid(self) -> bool:
        return (
            bool(self.number)
            and any(char.isdigit() for char in self.number)
            and all(char in Phone.VALID_CHARS for char in self.number)
        )

    def __str__(self) -> str:
        return f"{self.label}:{self.number}"


class Contact:
    def __init__(self, name: str) -> None:
        self._name: str = name
        self._favorite: bool = False
        self._phones: list[Phone] = []

    @property
    def name(self) -> str:
        return self._name

    @property
    def favorite(self) -> bool:
        return self._favorite

    def add_phone(self, label: str, number: str) -> bool:
        phone: Phone = Phone(label, number)
        if not phone.is_valid():
            return False
        self._phones.append(phone)
        return True

    def remove_phone(self, index: int) -> bool:
        if index < 0 or index >= len(self._phones):
            return False
        self._phones.pop(index)
        return True

    def toggle_favorite(self) -> None:
        self._favorite = not self._favorite

    def __str__(self) -> str:
        prefix: str = "@" if self._favorite else "-"
        phones: str = ", ".join(str(phone) for phone in self._phones)
        return f"{prefix} {self._name} [{phones}]"


def main() -> None:
    contact: Contact = Contact("")

    while True:
        line: str = input()
        print("$" + line)

        match line.split():
            case ["end"]:
                break
            case ["init", name]:
                contact = Contact(name)
            case ["addPhone", label, number]:
                if not contact.add_phone(label, number):
                    print(INVALID_NUMBER_MSG)
            case ["removePhone", index]:
                try:
                    parsed_index: int = int(index)
                except ValueError:
                    print(INVALID_INDEX_MSG)
                    continue
                if not contact.remove_phone(parsed_index):
                    print(INVALID_INDEX_MSG)
            case ["toggleFavorite"]:
                contact.toggle_favorite()
            case ["show"]:
                print(contact)
            case _:
                print(INVALID_COMMAND_MSG)


if __name__ == "__main__":
    main()
