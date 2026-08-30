class Towel:
    def __init__(self, color: str = "", size: str = "P") -> None:
        self.__color: str = color
        self.__size: str = size
        self.__wetness: int = 0

    def dry(self, amount: int) -> bool:
        max_wetness: int = self.get_max_wetness()

        if self.__wetness + amount > max_wetness:
            self.__wetness = max_wetness
            return False

        self.__wetness += amount
        return True

    def wring_out(self) -> None:
        self.__wetness = 0

    def get_max_wetness(self) -> int:
        match self.__size:
            case "P":
                return 10
            case "M":
                return 20
            case "G":
                return 30
            case _:
                return 0

    def is_dry(self) -> bool:
        return self.__wetness == 0

    def __str__(self) -> str:
        return (
            f"Cor: {self.__color}, "
            f"Tamanho: {self.__size}, "
            f"Umidade: {self.__wetness}"
        )


def main() -> None:
    towel: Towel = Towel()

    while True:
        line: str = input()
        print("$" + line)

        par: list[str] = line.split()
        cmd: str = par[0]

        if cmd == "end":
            break

        elif cmd == "criar":
            color: str = par[1]
            size: str = par[2]

            towel = Towel(color, size)

        elif cmd == "mostrar":
            print(towel)

        elif cmd == "enxugar":
            amount: int = int(par[1])

            if not towel.dry(amount):
                print("fail: toalha nao conseguiu enxugar tudo")

        elif cmd == "seca":
            if towel.is_dry():
                print("sim")
            else:
                print("nao")

        elif cmd == "torcer":
            towel.wring_out()

        else:
            print("comando invalido")


if __name__ == "__main__":
    main()