## #00_init   Shell sub: Entendendo como funciona a main

![](figura.jpg)

O objetivo da atividade é treinar o modelo de comandos. Para isso você vai implementar uma calculadora simples que contém um único registrador.

***
## Funcionalidades
O modelo de comandos é um programa interativo com um contexto persistente.
- Você pode imaginar o terminal ou o prompt de comando.
- A primeira palavra é o comando e as outras são os parâmetros do comando.
- Um comando pode gerar ou não uma saída.

***


## SHELL

O modo shell mostra como funcionaria seu código rodando no modo interativo interpretando os comandos do usuário.

```bash
#__case inicio
# O acumulador inicia em 0.
# O comando "$show" mostra o valor acumulado com duas casas decimais.
# O comando "$add V" adiciona o um valor float ao acumulador.
$show
0.00
$add 3
$add 5
$show
8.00
$end
```

```bash
#__case multiplicacao
# o comando "$mult V" multiplica o acumulado pelo valor V float.
$show
0.00
$add 4 
$mult 2.5
$mult 1.5
$show
15.00
$end
```

```bash
#__case div
# o comando "$div V" divide pelo valor. Se V for zero, informe o erro e mantenha o acumulador.
$show
0.00
$add 4 
$mult 2.2
$div 2
$show
4.40
$div 0
fail: division by zero
$show
4.40
$end
```

```bash
#__case addm
# o comando "$addm V [V ...]" adiciona vários valores em linha.
$show
0.00
$addm -3 -10 2 3 4 1 20 2 9
$show
28.00
$addm -1 -1 -3.2 4.3
$show
27.10
$end
```

```bash
#__case all_together_p1
$show
0.00
$add 4
$mult 1.5
$show
6.00

#__case all_together_p2
$div 4
$show
1.50
$addm 1 3 -1
$show
4.50
$addm -3 -10 2 3 4 1 20 2 9
$show
32.50
$div 0
fail: division by zero
$show
32.50
$end
```

## Pontos de partida

Em java ou em c++, você pode começar desse código que fica num loop infinito enquanto o usuário não digitar `end`.

**Java**
```java
//Shell.java
import java.util.Scanner;
public class Shell{
    static Scanner scanner = new Scanner(System.in);
    public static void main(String[] args) {
        while(true){
            String line = scanner.nextLine();
            String[] ui = line.split(" ");
            if(ui[0].equals("end")){
                break;
            }else{
                System.out.println("fail: comando invalido");
            }
        }
    }
}
```

**C++**
```cpp
//shell.cpp
#include <iostream>
#include <sstream>
using namespace std;
int main(){
    string line;
    string cmd;
    while(true){
        getline(cin, line);
        stringstream ss(line);
        ss >> cmd;
        if(line == "end"){
            break;
        }else{
            puts("fail: command not found");
        }
    }
}
```


---

## Código base, respostas e VPL

- Respostas
    - [C++](solver.cpp)
    - [Java](Solver.java)
- Para rodar os teste offline
    - [TH](https://github.com/senapk/th)
