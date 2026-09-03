from collections.abc import Iterable
from dataclasses import dataclass


CONTACT_NOT_FOUND_MSG: str = "fail: contact not found"
PHONE_NOT_FOUND_MSG: str = "fail: phone not found"
NO_PHONE_MSG: str = "fail: contact has no phone"
INVALID_COMMAND_MSG: str = "fail: invalid command"


@dataclass
class Phone:
    label: str
    number: str

    def __str__(self) -> str:
        return f"{self.label}:{self.number}"


class Contact:
    def __init__(self, name: str, phones: list[Phone] | None = None) -> None:
        self.__name: str = name
        self.__phones: list[Phone] = [] if phones is None else phones.copy()

    @property
    def name(self) -> str:
        return self.__name

    def add_phone(self, phone: Phone) -> None:
        self.__phones.append(phone)

    def remove_phone(self, label: str) -> bool:
        for index, phone in enumerate(self.__phones):
            if phone.label == label:
                self.__phones.pop(index)
                return True
        return False

    def get_phones(self) -> list[Phone]:
        return self.__phones.copy()

    def first_phone(self) -> Phone | None:
        return self.__phones[0] if self.__phones else None

    def has_number(self, number: str) -> bool:
        return any(phone.number == number for phone in self.__phones)

    def __str__(self) -> str:
        phones: str = ", ".join(str(phone) for phone in self.__phones)
        return f"- {self.__name} [{phones}]"


class CallRegistry:
    def __init__(self) -> None:
        self.__calls_by_number: dict[str, int] = {}
        self.__history: list[str] = []

    def register(self, number: str) -> None:
        self.__calls_by_number[number] = self.__calls_by_number.get(number, 0) + 1
        self.__history.append(number)

    def count(self, number: str) -> int:
        return self.__calls_by_number.get(number, 0)

    def history(self) -> list[str]:
        return self.__history.copy()


class Agenda:
    def __init__(self) -> None:
        self.__contacts: dict[str, Contact] = {}
        self.__registry: CallRegistry = CallRegistry()

    def add_contact(self, contact: Contact) -> None:
        current: Contact | None = self.__contacts.get(contact.name)
        if current is None:
            self.__contacts[contact.name] = contact
            return
        for phone in contact.get_phones():
            current.add_phone(phone)

    def remove_contact(self, name: str) -> bool:
        if name not in self.__contacts:
            return False
        del self.__contacts[name]
        return True

    def remove_phone(self, name: str, label: str) -> bool:
        contact: Contact | None = self.__contacts.get(name)
        return contact is not None and contact.remove_phone(label)

    def call(self, target: str) -> str | None:
        contact: Contact | None = self.__contacts.get(target)
        if contact is not None:
            phone: Phone | None = contact.first_phone()
            if phone is None:
                return None
            number: str = phone.number
        else:
            number = target
        self.__registry.register(number)
        return number

    def call_count(self, contact: Contact) -> int:
        return sum(self.__registry.count(phone.number) for phone in contact.get_phones())

    def contact_for_number(self, number: str) -> Contact | None:
        contacts: list[Contact] = [
            contact
            for contact in self.__contacts.values()
            if contact.has_number(number)
        ]
        return min(contacts, key=lambda contact: contact.name) if contacts else None

    def speed_list(self) -> list[Contact]:
        contacts: list[Contact] = [
            contact for contact in self.__contacts.values() if self.call_count(contact) > 0
        ]
        return sorted(
            contacts,
            key=lambda contact: (-self.call_count(contact), contact.name),
        )

    def history_lines(self) -> list[str]:
        lines: list[str] = []
        for number in self.__registry.history():
            contact: Contact | None = self.contact_for_number(number)
            destination: str = number if contact is None else contact.name
            count: int = self.__registry.count(number)
            lines.append(f":call {number} - {destination} {{{count} call}}")
        return lines

    def all_contacts(self) -> list[Contact]:
        return sorted(self.__contacts.values(), key=lambda contact: contact.name)


def parse_contact(arguments: list[str]) -> Contact:
    name: str = arguments[0]
    phones: list[Phone] = []
    for token in arguments[1:]:
        label, number = token.split(":", 1)
        phones.append(Phone(label, number))
    return Contact(name, phones)


def print_contact_with_count(contacts: Iterable[Contact], agenda: Agenda) -> None:
    for contact in contacts:
        phones: str = str(contact)[len(contact.name) + 2 :].lstrip()
        print(f"- {contact.name} {{{agenda.call_count(contact)} call}}{phones}")


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
                agenda.add_contact(parse_contact(parts[1:]))
            case ["rm", name]:
                if not agenda.remove_contact(name):
                    print(CONTACT_NOT_FOUND_MSG)
            case ["rmFone", name, label]:
                if not agenda.remove_phone(name, label):
                    print(PHONE_NOT_FOUND_MSG)
            case ["call", target]:
                number: str | None = agenda.call(target)
                if number is None:
                    print(NO_PHONE_MSG)
                else:
                    contact: Contact | None = agenda.contact_for_number(number)
                    destination: str = number if contact is None else contact.name
                    print(f"ligando {destination} {number}")
            case ["agenda"]:
                for contact in agenda.all_contacts():
                    print(contact)
            case ["speedList"]:
                print_contact_with_count(agenda.speed_list(), agenda)
            case ["history"]:
                for history_line in agenda.history_lines():
                    print(history_line)
            case _:
                print(INVALID_COMMAND_MSG)


if __name__ == "__main__":
    main()
