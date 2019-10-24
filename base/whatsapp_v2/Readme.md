## 41 Whatsapp II
### Chats pessoa a pessoa e Grupos.
![](figura.jpg)

- Usuários podem ser adicionados ao sistema e devem ter id único.
- Os usuários podem criar grupos e convidar outros usuários do sistema.
    - O id de um grupo deve ser único entre grupos e usuários.
- Usuários podem abrir talks, que são chats entre dois usuário.
    - O id de um talk é formado pelo id dos dois usuários que participam, separados por -.
    - Se maria e abel abrem o chat, o id do chat é abel-maria, ordenando os nomes.

```
addUser goku
  done
addUser sara
  done
addUser tina
  done
newGroup goku familia
  done
invite goku sara familia
  done
newTalk goku tina
  done
notify goku
  [familia goku-tina]
notify sara
  [familia]
notify tina
  [goku-tina]
```
- Todos os comandos para enviar zap e receber, ver notificações e etc devem funcionar para Talks e Grupos.
- Se o usuário tentar sair de um Talk ou Convidar alguém, exiba uma mensagem de erro.

```
zap goku familia to levando pizza
  done
notify sara
  [familia(1)]
ler sara familia
  [goku: to levando pizza]
zap sara familia a tina ta aqui te esperando
  done
zap goku goku-tina passa la em casa
  done
notify tina
  [goku-tina(1)]
ler tina goku-tina
  [goku: passa la em casa]
zap tina goku-tina ja to aqui com a sara esperando
  done
ler goku goku-tina
  [tina: ja to aqui com a sara esperando]
ler goku familia
  [sara: a tina ta aqui te esperando]

invite goku sara goku-tina
  fail: operacao de acionar usuarios nao suportada
leave goku goku-tina
  fail: operacao de sair do chat nao suportada
```

## Guia de Atividade

![](diagrama.png)


## Créditos

Fica o agradecimento para turma de POO DD 2017.2 que fez nascer essa atividade comigo.
