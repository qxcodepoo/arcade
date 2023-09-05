# Animal

<!-- toch -->
[Intro](#intro) | [Shell](#shell) | [Guide](#guide) | [Draft](#draft)
-- | -- | -- | --
<!-- toch -->

![_](cover.jpg)

O objetivo dessa atividade é implementar um animal que passa pelas diversas fases de crescimento até a morte.

***

## Intro

- Criar um animal passando por parâmetro a espécie e o barulho que ele faz.
- Invocar o método para que o animal faça barulho.
- Envelhecer o animal que vai passar por 4 estágios:
  - 0: bebe. Muito pequeno, não faz barulho `---`.
  - 1: criança. Faz barulho normal.
  - 2: adulto. Faz barulho normal.
  - 3: idoso. Faz barulho normal.
  - 4: morto. Não faz mais barulho `RIP`.

***

## Shell

```bash
#__case iniciando
# O comando "$init _especie _barulho" cria uma animal bebe dessa especie
# O comando "$show" mostra, sem manipulação, os atributos especie:estagio:barulho
$init gato miau
$show
gato:0:miau

$init cachorro auau
$show
cachorro:0:auau

$init galinha cocorico
$show
galinha:0:cocorico

$end
```

```bash
# O comando grow _valor envelhece o animal em _valor etapas
#__case envelhecendo
$init vaca muu
$show
vaca:0:muu

$grow 2
$show
vaca:2:muu

$grow 2
warning: vaca morreu

$show
vaca:4:muu

$grow 3
warning: vaca morreu

$show
vaca:4:muu

$end
```

```bash
# O comando noise faz o animal fazer barulho, se ele estiver vivo e não for bebe
#__case fazer barulho
$init cabra beeh

$noise
---

$grow 1
$noise
beeh
$grow 3
warning: cabra morreu

$noise
RIP

$end
```

```bash
#__case extra
$init passaro piupiu

$show
passaro:0:piupiu

$noise
---

$grow 1
$noise
piupiu

$grow 2
$noise
piupiu

$grow 1
warning: passaro morreu

$noise
RIP

$end
```

## Guide

### Diagrama

![_](diagrama.png)

### O que é o Shell

O [Shell](#shell) que você encontra em cada atividade serve tanto para que você entenda o funcionamento do código quanto ele gera o teste que será usado na correção.

Cada `$alguma coisa` representa comando que será enviado para o seu programa.

Depois é verificado se a saída gerada pelo seu programa é igual ao que era esperado.

Esse é o modelo do arquivo de testes gerado para cada atividade.

- [cases.tio](cases.tio)

![image](https://user-images.githubusercontent.com/4747652/263118401-36183946-8e20-4ecb-b0cc-75a5cef3610a.png)

### Como fazer a leitura dos dados

Criando a função main

- Você cria o elemento a ser manipulado fora do laço principal.
- Cria um loop infinito.
- Lê a linha que é o comando.
- Quebra a linha em palavras.
- Mostra o comando digitado precedido de '$'.
- Faz um if aninhado para cada comando repassando os parâmetros para o objeto.
- Se o comando for 'end' sai do loop.
- Se o comando for inválido mostra uma mensagem de erro.

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

## Draft

Para padronizar, em cada linguagem são criadas algumas funções auxiliares para simplificar a criação da main. Você pode utilizar essas resoluções como modelos para fazer as funções `main` dos outros projetos.

- [Solver.java](.cache/draft.java)
- [solver.cpp](.cache/draft.cpp )
- [solver.ts](.cache/draft.ts )
