from dataclasses import dataclass


INVALID_COMMAND_MSG: str = "fail: invalid command"


@dataclass
class Person:
    name: str
    age: int

    def __str__(self) -> str:
        return f"{self.name}:{self.age}"


def format_people(people: list[Person]) -> str:
    return "[" + ", ".join(str(person) for person in people) + "]"


def main() -> None:
    people: list[Person] = []

    while True:
        line: str = input()
        print("$" + line)

        match line.split():
            case ["end"]:
                break
            case ["pushBack", name, age]:
                people.append(Person(name, int(age)))
            case ["pushFront", name, age]:
                people.insert(0, Person(name, int(age)))
            case ["popBack"]:
                if people:
                    people.pop()
            case ["popFront"]:
                if people:
                    people.pop(0)
            case ["removeName", name]:
                for index, person in enumerate(people):
                    if person.name == name:
                        people.pop(index)
                        break
            case ["removeBelowAge", age]:
                minimum_age: int = int(age)
                people = [person for person in people if person.age >= minimum_age]
            case ["show"]:
                print(format_people(people))
            case _:
                print(INVALID_COMMAND_MSG)


if __name__ == "__main__":
    main()
