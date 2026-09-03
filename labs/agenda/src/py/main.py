from collections.abc import Iterable
from dataclasses import dataclass
from typing import ClassVar


CONTACT_EXISTS_MSG: str = "fail: contact already exists"
CONTACT_NOT_FOUND_MSG: str = "fail: contact not found"
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

    def matches(self, pattern: str) -> bool:
        return pattern in self.label or pattern in self.number

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

    def matches(self, pattern: str) -> bool:
        return pattern in self._name or any(
            phone.matches(pattern) for phone in self._phones
        )

    def __str__(self) -> str:
        prefix: str = "@" if self._favorite else "-"
        phones: str = ", ".join(str(phone) for phone in self._phones)
        return f"{prefix} {self._name} [{phones}]"


class Agenda:
    def __init__(self) -> None:
        self._contacts: dict[str, Contact] = {}

    def add_contact(self, name: str) -> bool:
        if name in self._contacts:
            return False
        self._contacts[name] = Contact(name)
        return True

    def get_contact(self, name: str) -> Contact | None:
        return self._contacts.get(name)

    def remove_contact(self, name: str) -> bool:
        if name not in self._contacts:
            return False
        del self._contacts[name]
        return True

    def search(self, pattern: str) -> list[Contact]:
        return self._sorted_contacts(
            contact for contact in self._contacts.values() if contact.matches(pattern)
        )

    def get_favorites(self) -> list[Contact]:
        return self._sorted_contacts(
            contact for contact in self._contacts.values() if contact.favorite
        )

    def _sorted_contacts(self, contacts: Iterable[Contact]) -> list[Contact]:
        return sorted(contacts, key=lambda contact: contact.name)

    def __str__(self) -> str:
        contacts: list[Contact] = self._sorted_contacts(self._contacts.values())
        return "\n".join(str(contact) for contact in contacts)


def print_contacts(contacts: list[Contact]) -> None:
    for contact in contacts:
        print(contact)


def main() -> None:
    agenda: Agenda = Agenda()

    while True:
        line: str = input()
        print("$" + line)

        match line.split():
            case ["end"]:
                break
            case ["addContact", name]:
                if not agenda.add_contact(name):
                    print(CONTACT_EXISTS_MSG)
            case ["addPhone", name, label, number]:
                contact: Contact | None = agenda.get_contact(name)
                if contact is None:
                    print(CONTACT_NOT_FOUND_MSG)
                elif not contact.add_phone(label, number):
                    print(INVALID_NUMBER_MSG)
            case ["removePhone", name, index]:
                contact = agenda.get_contact(name)
                if contact is None:
                    print(CONTACT_NOT_FOUND_MSG)
                    continue
                try:
                    parsed_index: int = int(index)
                except ValueError:
                    print(INVALID_INDEX_MSG)
                    continue
                if not contact.remove_phone(parsed_index):
                    print(INVALID_INDEX_MSG)
            case ["removeContact", name]:
                if not agenda.remove_contact(name):
                    print(CONTACT_NOT_FOUND_MSG)
            case ["toggleFavorite", name]:
                contact = agenda.get_contact(name)
                if contact is None:
                    print(CONTACT_NOT_FOUND_MSG)
                else:
                    contact.toggle_favorite()
            case ["favorites"]:
                print_contacts(agenda.get_favorites())
            case ["search", pattern]:
                print_contacts(agenda.search(pattern))
            case ["show"]:
                output: str = str(agenda)
                if output:
                    print(output)
            case _:
                print(INVALID_COMMAND_MSG)


if __name__ == "__main__":
    main()
