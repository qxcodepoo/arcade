# @grupo

- Veja a versão online: [aqui.](https://github.com/qxcodepoo/arcade/blob/master/base/grupo/Readme.md)
- Para programar na sua máquina (local/virtual) use:
  - `tko down poo grupo`
- Se não tem o `tko`, instale pelo [LINK](https://github.com/senapk/tko).

---

<!-- toch -->
[Guia de Atividade](#guia-de-atividade) | [Créditos](#créditos)
-- | --
<!-- toch -->

![cover](https://raw.githubusercontent.com/qxcodepoo/arcade/master/base/grupo/cover.jpg)

- Usuários podem ser adicionados ao sistema e devem ter id único.
- Os usuários podem criar grupos e convidar outros usuários do sistema.
    - O id de um grupo deve ser único entre grupos e usuários.
- Usuários podem abrir talks, que são chats entre dois usuário.
    - O id de um talk é formado pelo id dos dois usuários que participam, separados por -.
    - Se maria e abel abrem o chat, o id do chat é abel-maria, ordenando os nomes.

```sh
#__case init
$addUser goku
$addUser sara
$addUser tina
$newGroup goku familia
$invite goku sara familia
$newTalk goku tina
$notify goku
[familia goku-tina]
$notify sara
[familia]
$notify tina
[goku-tina]
```

- Todos os comandos para enviar zap e receber, ver notificações e etc devem funcionar para Talks e Grupos.
- Se o usuário tentar sair de um Talk ou Convidar alguém, exiba uma mensagem de erro.

```sh
#__case zap
$zap goku familia to levando pizza
$notify sara
[familia(1)]
$ler sara familia
[goku: to levando pizza]
$zap sara familia a tina ta aqui te esperando
$zap goku goku-tina passa la em casa
$notify tina
[goku-tina(1)]
$ler tina goku-tina
[goku: passa la em casa]
$zap tina goku-tina ja to aqui com a sara esperando
$ler goku goku-tina
[tina: ja to aqui com a sara esperando]
$ler goku familia
[sara: a tina ta aqui te esperando]
$invite goku sara goku-tina
fail: operacao de acionar usuarios nao suportada
$leave goku goku-tina
fail: operacao de sair do chat nao suportada
$end
```

## Guia de Atividade

![diagrama](https://raw.githubusercontent.com/qxcodepoo/arcade/master/base/grupo/diagrama.png)


## Créditos

Fica o agradecimento para turma de POO DD 2017.2 que fez nascer essa atividade comigo.
