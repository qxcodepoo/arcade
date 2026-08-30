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


    def show(self) -> None:
        print(self)

    def __str__(self) -> str:
        return f"{self.color} {self.size} {self.wetness}"

# Testes
towel = Towel("Azul", "P")
towel.show()  # Azul P 0
towel.dry(5)
towel.show()  # Azul P 5
print(towel.isDry()) # False
towel.dry(5)
towel.show()  # Azul P 10
if not towel.dry(5): # msg: toalha encharcada
    print("toalha encharcada")
towel.show()  # Azul P 10

towel.wringOut()
towel.show()  # Azul P 0

towel = Towel("Verde", "G")
print(towel.isDry()) # True
towel.dry(30)
towel.show()  # Verde G 30
print(towel.isDry()) # False
if not towel.dry(1):  # msg: toalha encharcada
    print("toalha encharcada")