INVALID_SIZE_MSG: str = "fail: invalid size"


class Shirt:
    DEFAULT_SIZE: str = "P"

    def __init__(self, size: str) -> None:
        self.__size: str = Shirt.DEFAULT_SIZE
        self.set_size(size)

    def get_size(self) -> str:
        return self.__size

    @staticmethod
    def get_allowed_sizes() -> list[str]:
        return ["PP", "P", "M", "G", "GG", "XG"]

    def set_size(self, size: str) -> bool:
        if size not in Shirt.get_allowed_sizes():
            return False

        self.__size = size
        return True


def main() -> None:
    shirt: Shirt = Shirt(Shirt.DEFAULT_SIZE)

    while True:
        print("Enter shirt size")
        size: str = input()
        if shirt.set_size(size):
            break
        print(INVALID_SIZE_MSG)
        print("Allowed sizes are:", ", ".join(Shirt.get_allowed_sizes()))

    print("Congratulations, you bought a shirt size", shirt.get_size())


if __name__ == "__main__":
    main()
