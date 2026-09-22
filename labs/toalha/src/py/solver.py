class Towel:
    def __init__(self, color: str, size: str) -> None:
        self.color: str = color
        self.size: str = size
        self.wetness: int = 0
    
    def max_wetness(self) -> int:
        if self.size == "P":
            return 10
        if self.size == "M":
            return 20
        if self.size == "G":
            return 30
        return 0

    def absorb(self, water_amount: int) -> bool:
        if water_amount < 0:
            return False

        self.wetness += water_amount
        if self.wetness > self.max_wetness():
            self.wetness = self.max_wetness()
            return False # não conseguiu enxugar tudo
        return True
    
    def wring_out(self) -> None:
        self.wetness = 0
    
    def is_dry(self) -> bool:
        return self.wetness == 0


    def __str__(self) -> str:
        return f"{self.color} {self.size} {self.wetness}"

if __name__ == "__main__":
    towel = Towel("Azul", "P")
    print(towel)
    towel.absorb(5)
    print(towel)
    print(towel.is_dry())
    towel.wring_out()
    print(towel)
