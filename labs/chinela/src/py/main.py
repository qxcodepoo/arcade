INVALID_SIZE_MSG: str = "fail: invalid size"


class Slipper:
    MIN_SIZE: int = 20
    MAX_SIZE: int = 50

    def __init__(self) -> None:
        self.__size: int = Slipper.MIN_SIZE

    def get_size(self) -> int:
        return self.__size

    def set_size(self, size: int) -> bool:
        if size < Slipper.MIN_SIZE:
            return False
        if size > Slipper.MAX_SIZE:
            return False
        if size % 2 != 0:
            return False

        self.__size = size
        return True


def main() -> None:
    slipper: Slipper = Slipper()

    while True:
        print("Enter slipper size")
        size: int = int(input())
        if slipper.set_size(size):
            break
        print(INVALID_SIZE_MSG)

    print("Congratulations, you bought a slipper size", slipper.get_size())


if __name__ == "__main__":
    main()
