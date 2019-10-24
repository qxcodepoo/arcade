## 40 Whatsapp I
### Só 5% do que tem no zap presta. Nestes 5% pode haver uma história de amor.
![](figura.jpg)

## Funcionalidades

- Adicionar usuário passando username.
- Mostrar os usuários cadastrados.

```
addUser goku
  done
addUser sara
  done
addUser tina
  done
allUsers
  [goku sara tina]
```

- Criar chat(grupo) para mandar mensagens
    - O nome do Chat deve ser único no sistema.
    - Quando um usuário cria um Chat, o Chat começa com o usuário que criou.
- Ver os Chats de um usuario.

```
newChat goku guerreiros
  done
newChat goku homens
  done
newChat sara familia
  done

# testando chats duplicados
newChat sara guerreiros
  fail: chat guerreiros ja existe

chats goku
 [guerreiros homens]
chats sara
  [familia]
chats tina
  []
```

- Adicionar pessoas a um grupo.
    - A pessoa que adiciona deve já estar no grupo.
- Ver quem está em um grupo.
- Sair de um grupo.

```
invite goku sara guerreiros
  done
invite sara tina guerreiros
  done
invite tina goku familia
  fail: user tina nao esta em chat familia

chats sara
  [familia guerreiros]
chats tina
  [guerreiros]
chats goku
  [guerreiros homens]

users guerreiros
  [goku sara tina]
users familia
  [sara tina]

leave sara guerreiros
  done
users guerreiros
  [goku tina]
chats sara
  [familia]
```

- Mandar mensagens para um grupo.
    - A pessoa que manda as mensagens, tem que estar no grupo.
    - Apenas quem está no grupo, poderá ler as mensagens.
- Ler as mensagens de um grupo.    
    - Um usuário pode ser as mensagens do grupo se ele está no grupo.
    - Ao pedir as mensagens, o usuário receberá as mensagens não lidas que ele tem no grupo.
    - Ao pedir as mensagens, o usuário não recebe as mensagens que ele mesmo enviou.
- Ao pedir a lista de notificações, o usuário vê ao lado de cada grupo se ele possui mensagens não lidas.

```
zap goku guerreiros sou goku galera
  done
zap tina guerreiros oi goku
  done

notify goku
  [guerreiros(1) homens]
notify tina
  [guerreiros(1)]

ler goku guerreiros
  [tina: oi goku]
ler tina guerreiros
  [goku: sou goku galera]

ler sara guerreiros
  fail: user sara nao esta no chat guerreiros

zap goku guerreiros vamos sair tina?
  done
zap tina guerreiros voce ta com fome goku?
  done
zap goku guerreiros to com saudade de voce.
  done

notify tina
  [guerreiros(2)]
notify goku
  [guerreiros(1) homens]

ler goku guerreiros
  [tina: voce ta com fome goku?]
ler tina guerreiros
  [goku: vamos sair tina?]
  [goku: to com saudade de voce.]
```

- Opcionais:
    - Enviar uma mensagem do sistema avisando quando um usuário entra ou sai de um Chat.

---

## Guia de Resolução
[GUIA](/assets/whatsapp/guide)

[](## Diagrama de Classes /assets/whatsapp/diagrama.png)

---
## Créditos

Fica o agradecimento para turma de POO DD 2017.2 que fez nascer essa atividade comigo.
