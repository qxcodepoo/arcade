# Toalha, o item mais útil do universo

- Crie uma classe `Toalha` com os atributos `cor`, `tamanho` e `humidade`.
- Crie um construtor que inicialize todos os atributos `cor` e `tamanho` com valores recebidos como parâmetro e `humidade` com 0.
- Crie um método `enxugar` que recebe um valor inteiro `humidade` e aumenta o atributo `humidade` da toalha.
- Crie um método `torcer` que zera o atributo `humidade` da toalha.
- O máximo de humidade que uma toalha pode ter é de acordo com o tamanho dela:
  - `P` -> 10
  - `M` -> 20
  - `G` -> 30
- Crie um método `estaSeca` que retorna `true` se a humidade da toalha for 0 e `false` caso contrário.
- Faça um código de teste para validar o comportamento da classe `Toalha`.

## Exemplo

```py

toalha = Toalha("Azul", "P")
toalha.mostrar()  # Azul P 0
toalha.enxugar(5)
toalha.mostrar()  # Azul P 5
toalha.estaSeca() # False
toalha.enxugar(5)
toalha.mostrar()  # Azul P 10
toalha.enxugar(5) # msg: toalha encharcada
toalha.mostrar()  # Azul P 10

toalha.torcer()
toalha.mostrar()  # Azul P 0

toalha = Toalha("Verde", "G")
toalha.estaSeca() # True
toalha.enxugar(30)
toalha.mostrar()  # Verde G 30
toalha.estaSeca() # False
toalha.enxugar(1)  # msg: toalha encharcada
```
