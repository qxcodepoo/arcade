## @049 Criando a Main

![_](https://raw.githubusercontent.com/qxcodepoo/arcade/master/base/049/cover.jpg)

- Em c++:
  - Código: [main.cpp](https://raw.githubusercontent.com/qxcodepoo/arcade/master/base/049/main.cpp)
  - Vídeo explicando as funções auxiliares funções lambda, template e funções auxiliares [vídeo](https://youtu.be/u4FwmKEwGBo)

- Em java:
  - Código: [Main.java](https://raw.githubusercontent.com/qxcodepoo/arcade/master/base/049/Main.java)

- Em typescript:
  - Código: [main.ts](https://raw.githubusercontent.com/qxcodepoo/arcade/master/base/049/main.ts)

## Guide

O modelo básico da main é:

```cpp
function main() {
    //aqui cria o objeto que você vai gerenciar
    var objeto = new Objeto();
    while (true) {
        var line = input();
        write("$" + line);
        var args = split(line);

        if (args[0] == "end") {
            break;
        }
        else if (args[0] == "nome do comando") {
            //aqui voce repassa os parametros para o objeto
            //convertendo os que precisam ser números ou inteiros
            objeto.funcaoTal(args[1], number(args[2]), (int) number(args[3]));
        }
        else if (args[0] == "outro comando") {
            //outra invocacao
        }
        else {
            write("fail: invalid command");
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
2.33

$end
```
