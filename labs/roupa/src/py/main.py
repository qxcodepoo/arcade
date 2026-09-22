INVALID_SIZE_MSG: str = "fail: invalid size"
INVALID_COMMAND_MSG: str = "fail: invalid command"


class Garment:
    DEFAULT_SIZE: str = "P"

    def __init__(self, size: str) -> None:
        self.__size: str = Garment.DEFAULT_SIZE
        self.set_size(size)

    def get_size(self) -> str:
        return self.__size

    @staticmethod
    def get_allowed_sizes() -> list[str]:
        return ["PP", "P", "M", "G", "GG", "XG"]

    def set_size(self, size: str) -> bool:
        if size not in Garment.get_allowed_sizes():
            return False

        self.__size = size
        return True

    def __str__(self) -> str:
        return f"size: ({self.__size})"


def main() -> None:
    garment: Garment = Garment(Garment.DEFAULT_SIZE)

    while True:
        line: str = input()
        print("$" + line)

        match line.split():
            case ["end"]:
                break
            case ["show"]:
                print(garment)
            case ["size", size]:
                if not garment.set_size(size):
                    print(INVALID_SIZE_MSG)
            case _:
                print(INVALID_COMMAND_MSG)


if __name__ == "__main__":
    main()
