# Título da atividade

<!-- toc-table -->
[Intro](#intro) | [Regras](#regras) | [Diagrama](#diagrama) | [Guide](#guide) | [Shell](#shell) | [Draft](#draft)
-- | -- | -- | -- | -- | --
<!-- toc-table -->

![cover](assets/cover.webp)

## Intro

Descreva em poucas linhas o projeto que o aluno vai implementar.

- O objetivo dessa atividade é implementar `...`.
- A classe `NomeEmIngles` representa `conceito em português`.
- A classe `Shell` representa a interface de linha de comando.
- A classe de domínio não deve ler entrada nem imprimir saída.
- O Shell deve interpretar comandos, chamar os métodos e imprimir os resultados.

## Regras

### Modelo

- Classe `NomeEmIngles`
  - Atributo `attribute`: descreva o valor guardado.
  - Atributo `limit`: descreva o limite, se existir.
  - Construtor
    - Recebe `...`.
    - Inicializa `...`.

### Mostrar

- Comando: `$show`
- Deve imprimir a chamada do `toString` ou representação principal do objeto.
- Formato literal:
  - `campo:{valor}, outro:{valor}`

### Inicializar

- Comando: `$init arg1 arg2`
- Deve criar ou reiniciar o objeto principal.
- Estado inicial:
  - `campo`: `valor inicial`.
  - `limite`: `valor máximo`.

### Operação principal

- Comando: `$command arg`
- Deve executar `...`.
- Em caso de sucesso:
  - Atualiza `...`.
  - Retorna ou imprime `...`, se houver saída.
- Em caso de falha:
  - Não altera `...`, se a regra exigir.
  - Mensagem literal: `fail: mensagem de erro`.

### Outra operação

- Comando: `$other arg1 arg2`
- Deve executar `...`.
- Limites:
  - `...`
- Falhas:
  - `fail: primeira falha`
  - `fail: segunda falha`

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
  - Implemente a representação textual.
- Parte 2: operações básicas
  - Implemente os comandos sem casos de erro.
  - Confira os primeiros testes.
- Parte 3: limites e falhas
  - Implemente as validações.
  - Garanta que mensagens e estado final batem com o Shell.
- Parte 4: integração com Shell
  - Leia cada linha.
  - Separe comando e argumentos.
  - Chame os métodos do domínio.
  - Imprima somente o que o contrato pedir.

## Shell

```bash
#TEST_CASE inicializar
$init 10
$show
campo:0, limite:10
$end
```

```bash
#TEST_CASE operacao basica
$init 10
$command 3
$show
campo:3, limite:10
$end
```

```bash
#TEST_CASE limite
$init 10
$command 11
fail: mensagem de erro
$show
campo:0, limite:10
$end
```

## Draft

<!-- links .cache/starter -->
<!-- links -->
