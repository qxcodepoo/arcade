# Como fazer os códigos e relatórios

- Veja a versão online: [aqui.](https://github.com/qxcodepoo/arcade/blob/master/base/relatorio/Readme.md)
- Para programar na sua máquina (local/virtual) use:
  - `tko down poo relatorio`
- Se não tem o `tko`, instale pelo [LINK](https://github.com/senapk/tko).

---

<!-- toc -->
- [Como fazer seu código orientado a testes](#como-fazer-seu-código-orientado-a-testes)
- [Relatório de Código](#relatório-de-código)
  - [Exemplo 1](#exemplo-1)
  - [Exemplo 2](#exemplo-2)
  - [Exemplo 3](#exemplo-3)
<!-- toc -->

![_](https://raw.githubusercontent.com/qxcodepoo/arcade/master/base/relatorio/cover.jpg)

## Como fazer seu código orientado a testes

1. Se é um conteúdo novo, faça alguns códigos de exemplo simples para entender os conceitos e a sintaxe.
2. Crie uma estrutura mínima de classes e métodos que lhe permita passar no primeiro teste.
3. Vá incrementando as classes e métodos até que todos os testes passem.
4. Um código completo, mas que não passa em todos os testes, não é um código completo.
5. Se vocês fez todas as classes, mas não fez a main e por isso não consegue rodar os testes, não vale nada.

## Relatório de Código

![_](https://raw.githubusercontent.com/qxcodepoo/arcade/master/base/relatorio/relatorio.jpg)

O relatório para ser colocado no início do arquivo principal do código de cada projeto e  deve responder às seguintes perguntas:

- O que fez?
  - Se fez tudo, passando em todos os testes, ou se fez parcial (qual parte fez).
- Com quem fez?
  - Se fez sozinho ou se fez com alguém(quem) e como foi a divisão do trabalho.
- O que aprendeu?
  - Se aprendeu não aprendeu o que a tarefa propõe ou tem partes que você não é capaz de refazer.
- Quanto tempo levou?
  - Juntando estudo e codificação.

### Exemplo 1

```cpp
// 1. Fiz tudo e passou em todos os testes.
// 2. Fiz sozinho.
// 3. Aprendi a usar herança e melhorei a manipulação de vetores.
// 4. Levei 4 horas distribuídas em 2 dias.

#include <iostream>
int main() {
    std::cout << "Hello World!" << std::endl;
    return 0;
}
```

### Exemplo 2

```ts
// 1. Fiz até a parte dos favoritos, e passou nos testes de cadastro e inclusão apenas.
// 2. Fiz com o João via google meet o trabalho, mas eu peguei todos os conceitos.
// 3. A parte de cadastro e inclusão eu aprendi, mas eu não entendi como funcionam os favoritos.
// 4. Levei 3 horas no meet mais 2 horas sozinho.
```

### Exemplo 3

```java
// 1. Fiz tudo, mas em NENHUM teste.
// 2. Fiz com o João e o Pedro, o João não fez nada, mas eu aprendi tudo menos a main.
// 3. Aprendi tudo, mas não passou em nenhum teste.
// 4. Levei 5 horas com os meninos e mais 3 horas sozinho.

import java.util.Scanner;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.println("Hello World!");
    }
}
```
