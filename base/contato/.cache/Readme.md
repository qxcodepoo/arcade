# Gerenciando telefones de um contato

<!-- toch -->
[Intro](#intro) | [Guide](#guide) | [Shell](#shell)
-- | -- | --
<!-- toch -->

![cover](https://raw.githubusercontent.com/qxcodepoo/arcade/master/base/contato/cover.jpg)

O objetivo dessa atividade é implementar uma classe responsável por guardar um **único** contato da agenda telefônica do seu celular. Cada contato pode ter vários telefones.

Essa classe Contact será reutilizada nas atividades @agenda.

## Intro

Seu programa deve:

- **Definir nome**
  - Poder inicializar o contato passando o nome.
    - Se já houver contato, inicie um novo contato.
    - Se não houver nome, o nome default é "".
- **Inserir telefones no contato**
  - Um telefone tem um label e um fone.
  - Labels serão nomes como: casa, fixo, oi.
  - Labels podem ser duplicados.

```sh
# Exemplo de saída
- ana [tim:3434, casa:4567, oi:8754, casa:4567, oi:8754]
```

- **Remover telefones do contato.**
  - Remove os telefones pelo índice.
- **Validando os números de telefone.**
  - Processe os telefones para apenas permitir nos telefones os seguintes caracteres "0123456789()."
  - Se o usuário tentar inserir individualmente um telefone invalido, avise e não insira o telefone.
- **Favoritar e desfavoritar contato**
- **Mostrar contato**
  - Mostrar o contato com todos os telefones.
  - Se ele for favoritado, mostre um @ no começo do nome.

***

## Guide

![diagrama](https://raw.githubusercontent.com/qxcodepoo/arcade/master/base/contato/diagrama.png)

<!-- links .cache/draft -->
- cpp
  - [shell.cpp](https://github.com/qxcodepoo/arcade/blob/master/base/contato/.cache/draft/cpp/shell.cpp)
- java
  - [Shell.java](https://github.com/qxcodepoo/arcade/blob/master/base/contato/.cache/draft/java/Shell.java)
- ts
  - [shell.ts](https://github.com/qxcodepoo/arcade/blob/master/base/contato/.cache/draft/ts/shell.ts)
<!-- links -->

***

## Shell

```bash
#TEST_CASE definindo nome
$init david
$show
- david []

#TEST_CASE inserindo telefones
$add oi 88
$add tim 99
$add tim 98
$add vivo 83
$show
- david [oi:88, tim:99, tim:98, vivo:83]

#TEST_CASE removendo telefone por indice
$rm 2
$show
- david [oi:88, tim:99, vivo:83]
$rm 0
$show
- david [tim:99, vivo:83]

#TEST_CASE validando numero de fone
$add tim 9a9
fail: invalid number
$add tim (85)99.99
$show
- david [tim:99, vivo:83, tim:(85)99.99]

#TEST_CASE favoritos
$tfav
$show
@ david [tim:99, vivo:83, tim:(85)99.99]

$tfav
$show
- david [tim:99, vivo:83, tim:(85)99.99]


$end
#__end__
```
