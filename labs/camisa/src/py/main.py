INVALID_SIZE_MSG: str = "fail: invalid size"


class Shirt:
    DEFAULT_SIZE: str = "P"

    def __init__(self, size: str) -> None:
        self.__size: str = Shirt.DEFAULT_SIZE
        self.setSize(size)

    def getSize(self) -> str:
        return self.__size

    @staticmethod
    def getAllowedSizes() -> list[str]:
        return ["PP", "P", "M", "G", "GG", "XG"]

    def setSize(self, size: str) -> bool:
        if size not in Shirt.getAllowedSizes():
            return False

        self.__size = size
        return True


def main() -> None:
    shirt: Shirt = Shirt(Shirt.DEFAULT_SIZE)

    while True:
        print("Enter shirt size")
        size: str = input()
        if shirt.setSize(size):
            break
        print(INVALID_SIZE_MSG)

    print("Congratulations, you bought a shirt size", shirt.getSize())


if __name__ == "__main__":
    main()
