from student import CarAdp

def teste_entrando():
    car = CarAdp()
    print("$Carro criado")
    car.show()
    print("$Entrando no carro")
    car.enter()
    car.show()
    print("$Entrando no carro")
    car.enter()
    car.show()
    print("$Entrando no carro")
    car.enter()
    car.show()

def teste_saindo():
    car = CarAdp()
    print("$Carro criado")
    car.show()
    print("$Entrando 2 pessoas no carro")
    car.enter()
    car.enter()
    car.show()
    print("$Saindo do carro")
    car.leave()
    car.show()
    print("$Saindo do carro")
    car.leave()
    car.show()
    print("$Saindo do carro")
    car.leave()
    car.show()

def teste_abastecendo():
    car = CarAdp()
    print("$Carro criado")
    car.show()
    print("$Abastecendo 10 litros")
    car.fuel(10)
    car.show()
    print("$Abastecendo 30 litros")
    car.fuel(30)
    car.show()
    print("$Abastecendo 100 litros")
    car.fuel(100)
    car.show()

def teste_dirigindo():
    car = CarAdp()
    print("$Carro criado")
    car.show()
    print("$Tentando dirigir com carro vazio")
    car.drive(10)
    car.show()
    print("$Entrando no carro")
    car.enter()
    car.show()
    print("$Testando dirigir sem gasolina")
    car.drive(10)
    car.show()
    print("$Abastecendo 30 litros")
    car.fuel(30)
    car.show()
    print("$Testando dirigir com gasolina")
    car.drive(10)
    car.show()
    print("$Testando dirigir só parte do caminho")
    car.drive(50)
    car.show()



def main():
    cmd = input()
    if cmd == "entrando":
        teste_entrando()
    elif cmd == "saindo":
        teste_saindo()
    elif cmd == "abastecendo":
        teste_abastecendo()
    elif cmd == "dirigindo":
        teste_dirigindo()

main()