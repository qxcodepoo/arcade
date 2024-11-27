# Verificando o tamanho de uma Roupa

## Descrição

- Vamos implementar uma classe que controla os possíveis valores de tamanho para uma roupa.
- Os tamanhos serão identificados como uma variável tipo texto, e os valores válidos são "PP", "P", "M" e "G", "GG" e "XG".
- Faça o objeto roupa iniciar o tamanho como uma string vazia, para expressar que nenhum tamanho foi atribuído.
- Crie o método setTamanho que apenas aceita os valores válidos de tamanho.
- Caso o valor seja inválido, avise e dê uma mensagem de erro informando quais os valores permitidos.
- Faça um código de teste iniciando uma roupa com tamanho vazio e pedindo para o usuário informar o tamanho da roupa.
- Mantenha o usuário preso no loop até que ele insira um valor válido.

## Exemplo em python

```py

class Roupa:
    def __init__(self): # isso é o construtor em python
        self.tamanho: str = ""

    def getTamanho(self) -> str: # métodos em python tem self como primeiro atributo
        return self.tamanho

    def setTamanho(self, valor: str):
        # implementar os testes de valor e disparar os avisos caso necessário

# loop principal
roupa = Roupa() # criando roupa com valor tamanho padrão

while roupa.getTamanho() == "": # mantendo usuário no loop
    print("Digite seu tamanho de roupa")
    tamanho = input() # lendo a resposta
    roupa.setTamanho(tamanho) # tentando atribuir e disparando erros

print("Parabens, você comprou uma roupa tamanho", roupa.getTamanho())
```
