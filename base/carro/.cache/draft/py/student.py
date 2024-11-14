# --
class Car:
    def __init__(self):
        self.pass_qtd = 0  # Passageiros
        self.pass_max = 2  # Limite de Passageiros
        self.gas = 0  # Tanque
        self.gas_max = 100  # Limite do tanque
        self.km = 0  # Quilometragem

    def enter(self):
        if self.pass_qtd < self.pass_max:
            self.pass_qtd += 1
        else:
            print("fail: limite de pessoas atingido")

    def leave(self):
        if self.pass_qtd > 0:
            self.pass_qtd -= 1
        else:
            print("fail: nao ha ninguem no carro")

    def fuel(self, gas):
        self.gas += gas
        if self.gas > self.gas_max:
            self.gas = self.gas_max

    def drive(self, km):
        if self.pass_qtd == 0:
            print("fail: nao ha ninguem no carro")
            return
        if self.gas == 0:
            print("fail: tanque vazio")
            return
        if self.gas < km:
            print(f"fail: tanque vazio apos andar {self.gas} km")
            self.km += self.gas
            self.gas = 0
        else:
            self.gas -= km
            self.km += km

    def __str__(self):
        return f"pass: {self.pass_qtd}, gas: {self.gas}, km: {self.km}"

# ==
class CarAdp:
    def __init__(self):
        # &&
        self.car = Car()
        # $$
        # pass
    def enter(self) -> None:
        # &&
        self.car.enter()
        # $$
        # pass
    def leave(self) -> None:
        # &&
        self.car.leave()
        # $$
        # pass
    def fuel(self, gas: int) -> None:
        # &&
        self.car.fuel(gas)
        # $$
        # pass
    def drive(self, km: int) -> None:
        # &&
        self.car.drive(km)
        # $$
        # pass
    def show(self) -> str:
        # &&
        return str(self.car)
        # $$
        # return ""
