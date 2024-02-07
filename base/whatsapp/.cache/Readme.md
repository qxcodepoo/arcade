# @whatsapp @whatsapp

Veja a versão online: [aqui.](https://github.com/qxcodepoo/arcade/blob/master/base/whatsapp/Readme.md)

<!-- toch -->
[Intro](#intro) | [Shell](#shell) | [Guia de Resolução](#guia-de-resolução) | [Main não interativa](#main-não-interativa) | [Créditos](#créditos)
-- | -- | -- | -- | --
<!-- toch -->

![cover](https://raw.githubusercontent.com/qxcodepoo/arcade/master/base/whatsapp/cover.jpg)

## Intro

- **$add**: adicionanar usuários.
  - `$add _username_`
    - Cria um usuário com esse username.
    - Adiciona o objeto usuário à lista de usuários do sistema.
  - `$users`
    - Mostra os usuários cadastrados.
  - Restrições:
    - O username deve ser único no sistema.
- **$create**: criar grupos de conversação.
  - `$create _username_ _groupName_`
    - Cria um grupo com um id inteiro único no sistema.
    - O grupo criado deve ser armazenado na lista de grupos do sistema.
    - O grupo criado deve ser adicionado na lista de grupos do usuário.
    - O usuário deve ser adicionado na lista de usuários do grupo.
    - O username deve corresponder a um usuário cadastrado.
  - `$users`:
    - Atualize para mostrar:
    - Todos os usernames e o id e nome dos grupos que ele participa.
    - Todos os grupos do sistema e os usernames dos usuários que participam dele.
  - Restrições:
    - O usuário deve ser um usuário cadastrado.
- **$invite**: convidando outros usuários para um grupo que você participa.
  - `$invite _owner_ _invitee_ _groupId_`
    - Adicione o grupo na lista de grupos de `_invitee_`
    - Adicione esse usuário no grupo com esse `_groupId_`
  - Restrições:
    - Ambos os usernames devem ser de distintos usuários cadastrados.
    - O grupo com esse `_groupId_` deve ser um dos grupos do `_owner_`.
- **$send** : envio de mensagens para o grupo.
  - `$send _username_ _groupId_ _message_`
    - A pessoa que manda as mensagens, tem que estar no grupo.
    - Apenas quem está no grupo, poderá ler as mensagens.
- Sair de um chat.
- Ler as mensagens de um grupo.
  - Um usuário pode ser as mensagens do grupo se ele está no grupo.
  - Ao pedir as mensagens, o usuário receberá as mensagens não lidas que ele tem no grupo.
  - Ao pedir as mensagens, o usuário não recebe as mensagens que ele mesmo enviou.
- Ao pedir a lista de notificações, o usuário vê ao lado de cada grupo se ele possui mensagens não lidas.

---

## Shell

```sh
#__case adicionar e mostrar usuários 
# O comando "$add nomeUsuario" cria um novo usuário.
# O comando "$allUsers" mostra todos usuários.
$add goku
$add sara
$add tina

$users
goku []
sara []
tina []

#__case novo Chat, mostrar chats do usuário
# O comando "$create nomeUser nomeChat" cria um novo chat.
# O comando "$chats nomeUser" mostra os chats usuário.

$create goku familia
$create sara familia
$create goku guerreiros

$create kuririm casa
fail: key kuririm not found

$users
goku [0:familia, 2:guerreiros]
sara [1:familia]
tina []

#__case invite
#- Adicionar pessoas a um grupo.
#    - A pessoa que adiciona deve já estar no grupo.
#- Ver quem está em um grupo.
#- Sair de um grupo.

$invite goku sara 2
$invite sara tina 2
$invite tina goku 1
fail: key 1 not found

$users
goku [0:familia, 2:guerreiros]
sara [1:familia, 2:guerreiros]
tina [2:guerreiros]

$chats
0:familia [goku]
1:familia [sara]
2:guerreiros [goku, sara, tina]

#__case leaving
$leave sara 2

$users
goku [0:familia, 2:guerreiros]
sara [1:familia]
tina [2:guerreiros]



#- Mandar mensagens para um grupo.
#    - A pessoa que manda as mensagens, tem que estar no grupo.
#    - Apenas quem está no grupo, poderá ler as mensagens.
#- Ler as mensagens de um grupo.    
#    - Um usuário pode ser as mensagens do grupo se ele está no grupo.
#    - Ao pedir as mensagens, o usuário receberá as mensagens não lidas que ele tem no grupo.
#    - Ao pedir as mensagens, o usuário não recebe as mensagens que ele mesmo enviou.
#- Ao pedir a lista de notificações, o usuário vê ao lado de cada grupo se ele possui mensagens não lidas.

#__case mensagens
$zap goku 2 oi, eu sou o goku
$zap tina 2 oi goku

$notify goku
[guerreiros(1) homens]
$notify tina
[guerreiros(1)]

$ler goku guerreiros
[tina: oi goku]
$ler tina guerreiros
[goku: oi, eu sou o goku]

$ler sara guerreiros
fail: user sara nao esta no chat guerreiros

$zap goku guerreiros vamos sair tina?
$zap tina guerreiros voce ta com fome goku?
$zap goku guerreiros to com saudade de voce.

$notify tina
[guerreiros(2)]
$notify goku
[guerreiros(1) homens]

$ler goku guerreiros
[tina: voce ta com fome goku?]
$ler tina guerreiros
[goku: vamos sair tina?]
[goku: to com saudade de voce.]
$end
```

- Opcionais:
  - Enviar uma mensagem do sistema avisando quando um usuário entra ou sai de um Chat.

---

## Guia de Resolução

[GUIA](https://github.com/qxcodepoo/arcade/blob/master/base/whatsapp/_guide.md)

![diagrama](https://raw.githubusercontent.com/qxcodepoo/arcade/master/base/whatsapp/diagrama.png)

---

## Main não interativa

```java
//case init
WhatsappService whatsapp = new WhatsappService();
whatsapp.createUser("goku");
whatsapp.createUser("sara");
whatsapp.createUser("tina");
System.out.println(whatsapp.allUsers());
//[goku sara tina]
whatsapp.createChat("goku", "guerreiros");
whatsapp.createChat("goku", "homens");
whatsapp.createChat("sara", "familia");

whatsapp.createChat("sara", "guerreiros");
//fail: chat guerreiros ja existe

System.out.println(whatsapp.getChatsUser("goku"));
//[guerreiros homens]
System.out.println(whatsapp.getChatsUser("sara"));
//[familia]
System.out.println(whatsapp.getChatsUser("tina"));
//[]

//case invite
whatsapp.addByInvite("goku", "sara", "guerreiros");
whatsapp.addByInvite("sara", "tina", "guerreiros");
whatsapp.addByInvite("tina", "goku", "familia");
//fail: user tina nao esta em chat familia
System.out.println(whatsapp.getChatsUser("sara"));
//[guerreiros familia]
System.out.println(whatsapp.getChatsUser("tina"));
//[guerreiros]
System.out.println(whatsapp.getChatsUser("goku"));
//[guerreiros homens]
System.out.println(whatsapp.getUsersChat("guerreiros"));
//[goku sara tina]
System.out.println(whatsapp.getUsersChat("familia"));
//[sara]

//case leaving
whatsapp.removerUserChat("sara", "guerreiros");
System.out.println(whatsapp.getUsersChat("guerreiros"));
//[goku tina]
System.out.println(whatsapp.getChatsUser("sara"));
//[familia]

//case mensagens
whatsapp.sendMessage("goku", "guerreiros", "oi, eu sou o goku");
whatsapp.sendMessage("tina", "guerreiros", "oi goku");

System.out.println(whatsapp.getNotifyUser("goku"));
//[guerreiros(1) homens]
System.out.println(whatsapp.getNotifyUser("tina"));
//[guerreiros(1)]

System.out.println(whatsapp.readMessageUserChat("goku", "guerreiros"));
//[tina: oi goku]

System.out.println(whatsapp.readMessageUserChat("tina", "guerreiros"));
//[goku: oi, eu sou o goku]

System.out.println(whatsapp.readMessageUserChat("sara", "guerreiros"));
//fail: user sara nao esta no chat guerreiros


whatsapp.sendMessage("goku", "guerreiros", "vamos sair tina?");
whatsapp.sendMessage("tina", "guerreiros", "voce ta com fome goku?");
whatsapp.sendMessage("goku", "guerreiros", "to com saudade de voce.");

System.out.println(whatsapp.getNotifyUser("tina"));
//[guerreiros(2)]
System.out.println(whatsapp.getNotifyUser("goku"));
//[guerreiros(1) homens]

System.out.println(whatsapp.readMessageUserChat("goku", "guerreiros"));
//[tina: voce ta com fome goku?]
System.out.println(whatsapp.readMessageUserChat("tina", "guerreiros"));
//[goku: vamos sair tina?]
//[goku: to com saudade de voce.]
```

---

## Créditos

Fica o agradecimento para turma de POO DD 2017.2 que fez nascer essa atividade comigo.
