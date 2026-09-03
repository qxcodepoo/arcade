INVALID_COMMAND_MSG: str = "fail: invalid command"
KID_NOT_IN_TRAMPOLINE_MSG: str = "fail: {name} nao esta no pula-pula"


class Kid:
    def __init__(self, name: str, age: int) -> None:
        self.__name: str = name
        self.__age: int = age

    def getName(self) -> str:
        return self.__name

    def getAge(self) -> int:
        return self.__age

    def __str__(self) -> str:
        return f"{self.__name}:{self.__age}"


class Trampoline:
    def __init__(self) -> None:
        self.__waiting: list[Kid] = []
        self.__playing: list[Kid] = []

    @staticmethod
    def __remove_from_list(name: str, kids: list[Kid]) -> Kid | None:
        for index, kid in enumerate(kids):
            if kid.getName() == name:
                return kids.pop(index)
        return None

    def arrive(self, kid: Kid) -> None:
        self.__waiting.insert(0, kid)

    def enter(self) -> None:
        if self.__waiting:
            self.__playing.insert(0, self.__waiting.pop())

    def leave(self) -> None:
        if self.__playing:
            self.__waiting.insert(0, self.__playing.pop())

    def removeKid(self, name: str) -> Kid | None:
        kid: Kid | None = self.__remove_from_list(name, self.__waiting)
        if kid is not None:
            return kid
        return self.__remove_from_list(name, self.__playing)

    def __str__(self) -> str:
        waiting: str = ", ".join(str(kid) for kid in self.__waiting)
        playing: str = ", ".join(str(kid) for kid in self.__playing)
        return f"[{waiting}] => [{playing}]"


def main() -> None:
    trampoline: Trampoline = Trampoline()

    while True:
        line: str = input()
        print("$" + line)

        match line.split():
            case ["end"]:
                break
            case ["show"]:
                print(trampoline)
            case ["arrive", name, age]:
                trampoline.arrive(Kid(name, int(age)))
            case ["enter"]:
                trampoline.enter()
            case ["leave"]:
                trampoline.leave()
            case ["remove", name]:
                if trampoline.removeKid(name) is None:
                    print(KID_NOT_IN_TRAMPOLINE_MSG.format(name=name))
            case _:
                print(INVALID_COMMAND_MSG)


if __name__ == "__main__":
    main()
