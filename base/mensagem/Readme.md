# @mensagem

- Veja a versão online: [aqui.](https://github.com/qxcodepoo/arcade/blob/master/base/mensagem/Readme.md)
- Para programar na sua máquina (local/virtual) use:
  - `tko down poo mensagem`
- Se não tem o `tko`, instale pelo [LINK](https://github.com/senapk/tko).

---

<!-- toch -->
[Intro](#intro) | [Guide](#guide) | [Shell](#shell)
-- | -- | --
<!-- toch -->

![cover](https://raw.githubusercontent.com/qxcodepoo/arcade/master/base/mensagem/cover.jpg)

Essa atividade é a base conceitual para simplificar a troca de mensagens entre dois usuários de um sistema. Cada usuário deve conter um _inbox_ que guarda as mensagens recebidas.

***

## Intro

- Adicionar usuários usando o nome como chave única.
- Enviar mensagens de texto entre usuários.
- Ler as mensagens não lidas de um usuário.

***

## Guide

![diagrama](https://raw.githubusercontent.com/qxcodepoo/arcade/master/base/mensagem/diagrama.png)

## Shell

```python
#__case unique
$addUser david
$addUser celia
$sendMsg david celia voce esta com fome?
$sendMsg david celia ganhei duas cortesias para comer no McLanches, bora?
$inbox david
- empty -
$sendMsg david celia me avisa se quiser ir!
$inbox celia
david:voce esta com fome?
david:ganhei duas cortesias para comer no McLanches, bora?
david:me avisa se quiser ir!
$sendMsg celia david na hora, te encontro la em 10 min
$inbox david
celia:na hora, te encontro la em 10 min
$sendMsg david celia ja to aqui
$inbox celia
david:ja to aqui
$end
```
