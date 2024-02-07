# Criando a Main

Veja a versão online: [aqui.](https://github.com/qxcodepoo/arcade/blob/master/base/main/Readme.md)

![_](https://raw.githubusercontent.com/qxcodepoo/arcade/master/base/main/cover.jpg)

- Em c++:
  - Código: [main.cpp](https://github.com/qxcodepoo/arcade/blob/master/base/main/main.cpp)

- Em java:
  - Código: [Main.java](https://github.com/qxcodepoo/arcade/blob/master/base/main/Main.java)

- Em typescript:
  - Código: [main.ts](https://github.com/qxcodepoo/arcade/blob/master/base/main/main.ts)

## Guide

O modelo básico da main é:

```cpp
function main() {
    
    var coisa = new Coisa(); //Coisa a ser manipulada

    while (true) {
        var line = input();         //lê a linha
        var args = line.split(" "); // quebra em array de palavras
        write("$" + line);          //mostra '$' na frente

        if (args[0] == "nome do comando") {
            //aqui voce repassa os parametros para o objeto
            //convertendo os que precisam ser números ou inteiros
            coisa.funcaoTal(args[1], number(args[2]), (int) number(args[3]));
        }
        else if (args[0] == "outro comando") {
            //outra invocacao
        }
        else if (args[0] == "end") {
            break;
        }
        else {
            write("fail: comando invalido");
        }
    }
}
```

## Shell

```s
#__case teste simples
$show
[]

#__case inserindo vários números em lote
$push 1 4 3 2
$show
[1, 4, 3, 2]

#__case apagando por índice
$erase 1
$show
[1, 3, 2]

#__case calculando a media
$media
2.00

$end
```
