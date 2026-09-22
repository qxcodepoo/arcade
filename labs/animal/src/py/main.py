DEAD_ANIMAL_MSG: str = "warning: animal is dead"
INVALID_COMMAND_MSG: str = "fail: invalid command"


class Animal:
    DEAD_STAGE: int = 4

    def __init__(self, species: str, noise: str) -> None:
        self.species: str = species
        self.noise: str = noise
        self.life_stage: int = 0

    def make_sound(self) -> str:
        if self.life_stage == 0:
            return "---"

        if self.life_stage == Animal.DEAD_STAGE:
            return "RIP"

        return self.noise

    def grow(self, stages: int) -> bool:
        if self.life_stage == Animal.DEAD_STAGE:
            return False

        self.life_stage += stages

        if self.life_stage >= Animal.DEAD_STAGE:
            self.life_stage = Animal.DEAD_STAGE
            return False

        return True

    def __str__(self) -> str:
        return f"{self.species}:{self.life_stage}:{self.noise}"


def main() -> None:
    current_animal: Animal = Animal("", "")

    while True:
        line: str = input()
        print("$" + line)

        match line.split():
            case ["end"]:
                break
            case ["init", species, noise]:
                current_animal = Animal(species, noise)
            case ["show"]:
                print(current_animal)
            case ["noise"]:
                print(current_animal.make_sound())
            case ["grow", stages]:
                if not current_animal.grow(int(stages)):
                    print(DEAD_ANIMAL_MSG)
            case _:
                print(INVALID_COMMAND_MSG)


if __name__ == "__main__":
    main()
