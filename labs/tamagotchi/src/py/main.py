from enum import Enum


NOT_SLEEPY_MSG: str = "fail: not sleepy"
INVALID_COMMAND_MSG: str = "fail: invalid command"


class DeathCause(Enum):
    NONE = "none"
    WEAKNESS = "weakness"
    DIRT = "dirt"


class Pet:
    def __init__(self, energyMax: int, cleanMax: int) -> None:
        self.__energyMax: int = energyMax
        self.__cleanMax: int = cleanMax
        self.__energy: int = energyMax
        self.__clean: int = cleanMax
        self.__age: int = 0
        self.__alive: bool = True
        self.__deathCause: DeathCause = DeathCause.NONE

    def isAlive(self) -> bool:
        return self.__alive

    def getEnergy(self) -> int:
        return self.__energy

    def getEnergyMax(self) -> int:
        return self.__energyMax

    def getClean(self) -> int:
        return self.__clean

    def getCleanMax(self) -> int:
        return self.__cleanMax

    def getAge(self) -> int:
        return self.__age

    def loseEnergy(self, amount: int) -> None:
        self.__energy = max(0, self.__energy - amount)
        if self.__energy == 0:
            self.__die(DeathCause.WEAKNESS)

    def loseClean(self, amount: int) -> None:
        self.__clean = max(0, self.__clean - amount)
        if self.__clean == 0:
            self.__die(DeathCause.DIRT)

    def advanceAge(self, amount: int) -> None:
        if self.__alive:
            self.__age += amount

    def restoreEnergy(self) -> None:
        if self.__alive:
            self.__energy = self.__energyMax

    def restoreClean(self) -> None:
        if self.__alive:
            self.__clean = self.__cleanMax

    def __die(self, cause: DeathCause) -> None:
        if self.__alive:
            self.__alive = False
            self.__deathCause = cause

    def __str__(self) -> str:
        text: str = (
            f"energy:{self.__energy}/{self.__energyMax}, "
            f"clean:{self.__clean}/{self.__cleanMax}, age:{self.__age}"
        )
        if not self.__alive:
            text += f", death:{self.__deathCause.value}"
        return text


class Game:
    def __init__(self, pet: Pet) -> None:
        self.__pet: Pet = pet

    def isAlive(self) -> bool:
        return self.__pet.isAlive()

    def isSleepy(self) -> bool:
        return self.__pet.getEnergyMax() - self.__pet.getEnergy() >= 5

    def play(self) -> bool:
        if not self.__pet.isAlive():
            return False
        self.__pet.advanceAge(1)
        self.__pet.loseEnergy(2)
        self.__pet.loseClean(3)
        return True

    def shower(self) -> bool:
        if not self.__pet.isAlive():
            return False
        self.__pet.advanceAge(2)
        self.__pet.loseEnergy(3)
        self.__pet.restoreClean()
        return True

    def sleep(self) -> bool:
        if not self.__pet.isAlive():
            return True
        if not self.isSleepy():
            return False
        lostEnergy: int = self.__pet.getEnergyMax() - self.__pet.getEnergy()
        self.__pet.advanceAge(lostEnergy)
        self.__pet.restoreEnergy()
        return True

    def __str__(self) -> str:
        return str(self.__pet)


def main() -> None:
    game: Game = Game(Pet(0, 0))

    while True:
        line: str = input()
        print("$" + line)

        match line.split():
            case ["end"]:
                break
            case ["init", energyMax, cleanMax]:
                game = Game(Pet(int(energyMax), int(cleanMax)))
            case ["show"]:
                print(game)
            case ["play"]:
                game.play()
            case ["shower"]:
                game.shower()
            case ["sleep"]:
                if not game.sleep():
                    print(NOT_SLEEPY_MSG)
            case _:
                print(INVALID_COMMAND_MSG)


if __name__ == "__main__":
    main()
