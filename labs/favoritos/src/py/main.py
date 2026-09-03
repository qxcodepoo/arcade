from collections.abc import Iterable
from dataclasses import dataclass
from typing import ClassVar


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
            and all(char in self.VALID_CHARS for char in self.number)
        )

    def __str__(self) -> str:
        return f"{self.label}:{self.number}"


class Contact:
    def __init__(self, name: str, phones: list[Phone] | None = None) -> None:
        self.__name: str = name
        self.__phones: list[Phone] = []
        self.__starred: bool = False
        if phones is not None:
            for phone in phones:
                self.add_phone(phone)

    @property
    def name(self) -> str:
        return self.__name

    @property
    def starred(self) -> bool:
        return self.__starred

    def add_phone(self, phone: Phone) -> bool:
        if not phone.is_valid():
            return False
        self.__phones.append(phone)
        return True

    def remove_phone(self, index: int) -> bool:
        if index < 0 or index >= len(self.__phones):
            return False
        self.__phones.pop(index)
        return True

    def get_phones(self) -> list[Phone]:
        return self.__phones.copy()

    def set_starred(self, value: bool) -> None:
        self.__starred = value

    def matches(self, pattern: str) -> bool:
        return pattern in self.__name or any(
            pattern in phone.label or pattern in phone.number for phone in self.__phones
        )

    def __str__(self) -> str:
        prefix: str = "@" if self.__starred else "-"
        phones: str = " ".join(
            f"[{index}:{phone}]" for index, phone in enumerate(self.__phones)
        )
        return f"{prefix} {self.__name} {phones if phones else '[]'}"


class Agenda:
    def __init__(self) -> None:
        self.__contacts: dict[str, Contact] = {}
        self.__favorite_ids: set[str] = set()

    def add_contact(self, contact: Contact) -> None:
        current: Contact | None = self.__contacts.get(contact.name)
        if current is None:
            self.__contacts[contact.name] = contact
            return
        for phone in contact.get_phones():
            current.add_phone(phone)

    def get_contact(self, name: str) -> Contact | None:
        return self.__contacts.get(name)

    def remove_contact(self, name: str) -> bool:
        if name not in self.__contacts:
            return False
        del self.__contacts[name]
        self.__favorite_ids.discard(name)
        return True

    def star(self, name: str) -> bool:
        contact: Contact | None = self.__contacts.get(name)
        if contact is None:
            return False
        contact.set_starred(True)
        self.__favorite_ids.add(name)
        return True

    def unstar(self, name: str) -> bool:
        contact: Contact | None = self.__contacts.get(name)
        if contact is None:
            return False
        contact.set_starred(False)
        self.__favorite_ids.discard(name)
        return True

    def search(self, pattern: str) -> list[Contact]:
        return self.__sorted_contacts(
            contact for contact in self.__contacts.values() if contact.matches(pattern)
        )

    def get_starred(self) -> list[Contact]:
        contacts: list[Contact] = [
            self.__contacts[name]
            for name in self.__favorite_ids
            if name in self.__contacts
        ]
        return self.__sorted_contacts(contacts)

    def get_all(self) -> list[Contact]:
        return self.__sorted_contacts(self.__contacts.values())

    @staticmethod
    def __sorted_contacts(contacts: Iterable[Contact]) -> list[Contact]:
        return sorted(contacts, key=lambda contact: contact.name)

    def __str__(self) -> str:
        return "\n".join(str(contact) for contact in self.get_all())


def print_contacts(contacts: list[Contact]) -> None:
    for contact in contacts:
        print(contact)


def parse_contact(arguments: list[str]) -> tuple[Contact, bool]:
    name: str = arguments[0]
    phones: list[Phone] = []
    all_valid: bool = True
    for token in arguments[1:]:
        label, number = token.split(":", 1)
        phone: Phone = Phone(label, number)
        if phone.is_valid():
            phones.append(phone)
        else:
            all_valid = False
    return (Contact(name, phones), all_valid)


def main() -> None:
    agenda: Agenda = Agenda()

    while True:
        line: str = input()
        print("$" + line)

        parts: list[str] = line.split()
        match parts:
            case ["end"]:
                break
            case ["init"]:
                agenda = Agenda()
            case ["add", *_] if len(parts) >= 2:
                contact, all_valid = parse_contact(parts[1:])
                agenda.add_contact(contact)
                if not all_valid:
                    print(INVALID_NUMBER_MSG)
            case ["rm", name]:
                if not agenda.remove_contact(name):
                    print(CONTACT_NOT_FOUND_MSG)
            case ["star", name]:
                if not agenda.star(name):
                    print(CONTACT_NOT_FOUND_MSG)
            case ["unstar", name]:
                if not agenda.unstar(name):
                    print(CONTACT_NOT_FOUND_MSG)
            case ["starred"]:
                print_contacts(agenda.get_starred())
            case ["search", pattern]:
                print_contacts(agenda.search(pattern))
            case ["show"]:
                print_contacts(agenda.get_all())
            case _:
                print(INVALID_COMMAND_MSG)


if __name__ == "__main__":
    main()
