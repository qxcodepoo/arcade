# Título da atividade

<!-- toc-table -->
[Intro](#intro) | [Regras](#regras) | [Diagrama](#diagrama) | [Guide](#guide)
-- | -- | -- | --
<!-- toc-table -->

![cover](assets/cover.webp)

## Intro

Descreva em poucas linhas o projeto que o aluno vai implementar.

- O objetivo dessa atividade é implementar `...`.
- A classe `NomeEmIngles` representa `conceito em português`.
- Essa atividade não possui Shell obrigatório.
- O aluno deve implementar os requisitos e criar um código de teste ou demonstração para validar o comportamento.

## Regras

### Modelo

- Classe `NomeEmIngles`
  - Atributo `attribute`: descreva o valor guardado.
  - Atributo `limit`: descreva o limite, se existir.
  - Construtor
    - Recebe `...`.
    - Inicializa `...`.

### Métodos

- Método `methodName(arg)`
  - Recebe `...`.
  - Deve executar `...`.
  - Deve retornar `...`, se houver retorno.
  - Deve alterar `...`, se houver alteração de estado.

- Método `anotherMethod()`
  - Deve executar `...`.
  - Deve retornar `...`.

### Limites

- Defina os valores máximos, mínimos ou casos especiais.
- Informe o que acontece quando uma operação ultrapassa o limite.
- Informe se a operação deve retornar `true`, `false`, `null`, lançar erro ou apenas ajustar o estado.

### Representação

- Defina o formato textual do objeto, se houver.
- Formato literal:
  - `campo outro valor`

### Verificação

O aluno deve criar um código de teste ou demonstração cobrindo:

- Criação do objeto.
- Estado inicial.
- Operação principal em caso normal.
- Operação no limite.
- Método de consulta ou representação textual.

## Diagrama

Use uma convenção de tipos baseada em TypeScript dentro da notação UML. A convenção é didática e deve ser traduzida para a linguagem da turma durante a implementação.

- `number`: números inteiros ou decimais.
- `boolean`: valores verdadeiro ou falso.
- `string`: textos e caracteres.
- `void`: método sem valor de retorno.
- `Array<T>`: coleção indexada de tamanho variável.
- `Map<K, V>`: estrutura de dados chave-valor.
- `T | null`: valor que pode estar ausente.
- Use multiplicidades UML nas associações, como `0..1` para uma referência opcional e `0..*` para uma coleção.
- Não use `None`, `Optional`, `undefined`, ponteiros ou tipos de coleções específicos de uma linguagem.
- Não use tuplas como padrão. Quando os valores tiverem significado próprio, modele uma classe de resultado com atributos nomeados.

O arquivo fonte deve ser `assets/diagrama.puml`. Gere a imagem na pasta `assets` com `plantuml diagrama.puml`.

## Guide

![diagrama](assets/diagrama.png)

Implemente a atividade em partes.

- Parte 1: estado e construtor
  - Crie a classe principal.
  - Inicialize todos os atributos.
  - Confira o estado inicial.
- Parte 2: métodos de consulta
  - Implemente métodos que retornam informações sem alterar o estado.
  - Implemente a representação textual, se existir.
- Parte 3: métodos de alteração
  - Implemente operações que modificam o objeto.
  - Confira os limites definidos em `Regras`.
- Parte 4: código de teste
  - Crie objetos com valores diferentes.
  - Chame os métodos principais.
  - Confira visualmente ou por asserts se o comportamento bate com o enunciado.
