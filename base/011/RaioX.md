## Raio X

````java
class Espiral
+ nome: String
+ qtd: int
+ preco: float
--
+ toString(): String

class Maquina
- espirais: List<Espiral>
- saldoCliente: float
- lucro: float
--
+ inserirDinheiro(value: number): boolean
+ pedirTroco(): float
+ vender(indice: int): boolean
+ alterarEspiral(indice: int, nome: String, qtd : int, preco :float) : boolean
+ getSaldo(): float
+ toString() String
````
