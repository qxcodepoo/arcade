# Criando a Main

![_](cover.jpg)

- Em c++:
  - Código: [main.cpp](main.cpp)

- Em java:
  - Código: [Main.java](Main.java)

- Em typescript:
  - Código: [main.ts](main.ts)

## Guide

O modelo básico da main é:

```py
def main():
    
    coisa = Coisa(); // Elemento a ser manipulado

    while True:
        line = input();         // lê a linha
        args = line.split(" "); // quebra em array de palavras
        cmd = args[0]           // o comando é a primeira palavra
        print("$" + line);      // mostra a linha lida

        if cmd == "end":
            break;
        elif cmd == "nome do comando":
            valor = int(args[1])
            nome = args[2]
            coisa.funcaoTal(valor, nome)

        elif cmd == "outro comando":
            //outra invocacao
        else:
            write("fail: comando invalido");
```

## Shell

```s
#TEST_CASE teste simples
$show
[]

#TEST_CASE inserindo vários números em lote
$push 1 4 3 2
$show
[1, 4, 3, 2]

#TEST_CASE apagando por índice
$erase 1
$show
[1, 3, 2]

#TEST_CASE calculando a media
$media
2.00

$end
```
