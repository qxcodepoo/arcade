DEAD_ANIMAL: str = "warning: animal is dead"
INVALID_COMMAND_MSG: str = "fail: invalid command"


class Animal:
    DEAD_AGE: int = 4

    def __init__(self, species: str, noise: str) -> None:
        self.species: str = species
        self.noise: str = noise
        self.age: int = 0

    def make_sound(self) -> str:
        if self.age == 0:
            return "---"

        if self.age == Animal.DEAD_AGE:
            return "RIP"

        return self.noise

    def age_by(self, increment: int) -> bool:
        if self.age == Animal.DEAD_AGE:
            return False

        self.age += increment

        if self.age >= Animal.DEAD_AGE:
            self.age = Animal.DEAD_AGE
            return False

        return True

    def __str__(self) -> str:
        return f"{self.species}:{self.age}:{self.noise}"


def main() -> None:
    animal: Animal = Animal("", "")

    while True:
        line: str = input()
        print("$" + line)

        match line.split():
            case ["end"]:
                break
            case ["init", species, noise]:
                animal = Animal(species, noise)
            case ["show"]:
                print(animal)
            case ["noise"]:
                print(animal.make_sound())
            case ["grow", increment]:
                if not animal.age_by(int(increment)):
                    print(DEAD_ANIMAL)
            case _:
                print(INVALID_COMMAND_MSG)


if __name__ == "__main__":
    main()
