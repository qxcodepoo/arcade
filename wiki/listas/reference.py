from dataclasses import dataclass


@dataclass
class Person:
    name: str
    age: int

    def __str__(self) -> str:
        return f"{self.name}:{self.age}"


def format_people(people: list[Person]) -> str:
    return "[" + ", ".join(str(person) for person in people) + "]"


def find_by_name(people: list[Person], name: str) -> Person | None:
    return next((person for person in people if person.name == name), None)


def remove_first_by_name(people: list[Person], name: str) -> bool:
    for index, person in enumerate(people):
        if person.name == name:
            people.pop(index)
            return True
    return False


def main() -> None:
    people: list[Person] = []

    # Inserção no final, no início e de vários elementos.
    people.append(Person("ana", 20))
    people.append(Person("bia", 17))
    people.insert(0, Person("caio", 31))
    people.extend(
        [Person("dora", 25), Person("eva", 19), Person("fabi", 22)]
    )
    print(format_people(people))

    # Consultas por posição e tamanho.
    size: int = len(people)
    first: Person = people[0]
    last: Person = people[-1]
    print(f"size={size} first={first} last={last}")

    # Percurso com o elemento e com sua posição.
    for person in people:
        print(person.name)
    for index, person in enumerate(people):
        print(index, person)

    # Busca e teste de uma condição.
    found: Person | None = find_by_name(people, "bia")
    has_adult: bool = any(person.age >= 18 for person in people)
    print(f"found={found} has_adult={has_adult}")

    # Remoção pelo nome e pelas extremidades.
    removed: bool = remove_first_by_name(people, "ana")
    print(f"removed={removed}")
    if people:
        people.pop()
    if people:
        people.pop(0)

    # Filtro: mantém somente pessoas adultas.
    adults: list[Person] = [person for person in people if person.age >= 18]

    # Transformação, cópia e ordenação.
    names: list[str] = [person.name for person in adults]
    copied_people: list[Person] = adults.copy()
    by_age: list[Person] = sorted(adults, key=lambda person: person.age)
    by_name: list[Person] = sorted(adults, key=lambda person: person.name)
    copied_people.clear()
    print(f"adults={format_people(adults)}")
    print(f"names={names}")
    print(f"cleared_copy={format_people(copied_people)}")
    print(f"by_age={format_people(by_age)}")
    print(f"by_name={format_people(by_name)}")


if __name__ == "__main__":
    main()
