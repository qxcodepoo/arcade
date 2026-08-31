class Towel:
    def __init__(self, color: str, size: str):
        self.color: str = color
        self.size: str = size
        self.wetness: int = 0
    
    def getMaxWetness(self) -> int:
        if self.size == "P":
            return 10
        if self.size == "M":
            return 20
        if self.size == "G":
            return 30
        return 0

    def dry(self, amount: int) -> bool:
        self.wetness += amount
        if self.wetness > self.getMaxWetness():
            self.wetness = self.getMaxWetness()
            return False # não conseguiu enxugar tudo
        return True
    
    def wringOut(self) -> None:
        self.wetness = 0
    
    def isDry(self) -> bool:
        return self.wetness == 0


    def __str__(self) -> str:
        return f"{self.color} {self.size} {self.wetness}"

if __name__ == "__main__":
    towel = Towel("Azul", "P")
    print(towel)
    towel.dry(5)
    print(towel)
    print(towel.isDry())
    towel.wringOut()
    print(towel)
