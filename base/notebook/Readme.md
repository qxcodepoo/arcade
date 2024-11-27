# Notebook com carregador e bateria

## Descrição

- Vamos criar um código para aprender a lidar com objetos que podem ou não existir.
- Vamos modelar um notebook que pode ter ou não tanto carregador quanto bateria.
- Terá que reagir às ações `usar <tempo>`, `ligar` e `desligar`.
- Só poderá `ligar` se tiver carga na bateria ou carregador.
- Enquanto em uso
  - se tiver apenas na bateria, a carga da bateria deve diminuir.
  - se estiver na bateria e no carregador, a carga deve aumentar.
- O carregador possui uma potência que implica na quantidade de carga carregada por unidade de tempo.
- A bateria possui uma carga e uma capacidade que representam a carga atual e o máximo possível de carga.
- Para simplificar, vamos utilizar minutos como a unidade de tempo e de carga.
- Uma bateria `15/50` significa que possui ainda 15 minutos de carga e suporta no máximo 50.
- Um carregador com 3 de potência consegue em um minuto de uso, adicionar 3 minutos de carga na bateria.

## Ação

- Projete o Diagrama de Classes das classes Notebook, Bateria e Carregador.
- Defina as relações, atributos, métodos e multiplicidade.
- Utilize o Plantuml para fazer o diagrama.

## Ações

- Para facilitar, você pode imaginar o notebook sendo utilizado da seguinte forma.
- Adapte a implementação para sua linguagem.

```python
# python
notebook = Notebook() # criando notebook
notebook.mostrar()    # msg: Status: Desligado, Bateria: Nenhuma, Carregador: Desconectado
notebook.ligar()      # msg: não foi possível ligar
notebook.usar(10)     # msg: notebook desligado

bateria = Bateria(50) # criando bateria que suporta 50 minutos e começa carregada
notebook.setBateria(bateria) # coloca a bateria no notebook

notebook.mostrar() # msg: Status: Desligado, Bateria: (50/50), Carregador: Desconectado
notebook.ligar()   # msg: notebook ligado
notebook.mostrar() # msg: Status: Ligado, Bateria: (50/50), Carregador: Desconectado
notebook.usar(30)  # msb: Usando por 30 minutos
notebook.mostrar() # msg: Status: Ligado, Bateria: (20/50), Carregador: Desconectado
notebook.usar(30)  # msb: Usando por 20 minutos, notebook descarregou
notebook.mostrar() # msg: Status: Desligado, Bateria: (0/50), Carregador: Desconectado

bateria = notebook.rmBateria() # msg: bateria removida
bateria.mostrar()  # (0/50)
notebook.mostrar() # msg: Status: Desligado, Bateria: Nenhuma, Carregador: Desconectado

carregador = Carregador(2) # criando carregador com 2 de potencia
notebook.setCarregador(carregador) # adicionando carregador no notebook
notebook.mostrar() # msg: Status: Desligado, Bateria: Nenhuma, Carregador: (Potência 2)
notebook.ligar()   # msg: notebook ligado
notebook.mostrar() # msg: Status: Ligado, Bateria: Nenhuma, Carregador: (Potência 2)

notebook.setBateria(bateria)
notebook.mostrar() # msg: Status: Ligado, Bateria: (0/50), Carregador: (Potência 2)
notebook.usar(10)  # msg: Notebook utilizado com sucesso
notebook.mostrar() # msg: Status: Ligado, Bateria: (20/50), Carregador: (Potência 2)
```
