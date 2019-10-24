---
layout: post
title: "Whatsapp Guide"
---

# Responsabilidades e Atribuições

---
### WhatsappService

        - rep_user: Repository<User>

É da classe de serviço a responsabilidade criar e armazenar os usuários do sistema.

        - rep_chat: Repository<Chat>

É da classe de serviço a responsabilidade de criar e armazenar os chats.

        + executeQuery(line: string): string

Esse método tem a responsabilidade de processar as solicitações realizadas no formato de comandos e parâmetros realizando ou encaminhando as solicitações. Deve retornar uma mensagem de resposta à solicitação.

        + createChat(userId: String, chatId: string)

Cria o chat apenas se não houver outro chat de mesmo nome. Solicita ao chat
 através do método Chat.addUser(user: User) a inclusão do usuário que o criou.

        + addByInvite(guessUserId: String, invitedUserId: String, chatId: String): void

Encaminha ao grupo a solicitação de incluir o usuário **invited** apenas se o usuário **guess** já fizer parte do grupo.

### User

        - id: String

User possui um id único entre todos os usuários.

        # chats: Chat[0..*]

User possui uma referência a todos os chats com que se comunica. A variável aparece com visibilidade de pacote. Cabe à classe Chat acessar a variável fazer a inserção cruzada adicionando o objeto chat no usuário e o objeto user no chat.

        + getChats(): String[]

Retorna a lista dos identificadores dos chats que participa.

        + getNotify(): Notify[]

O método solicita a cada chat que o user participa a informação
de quantas mensagens não lidas neste chat o user possui através do método 
Chat.unreadCount(userId).
Então retorna uma lista de notificacoes, uma tupla(chatId, qtd),
para informar quantas mensagens não lidas há em cada chat.

        +sendMsg(idChat: String, text: String)

Cabe a classe user iniciar a transmissão de uma mensagem. O objeto
chat é localidado na lista de chats a partir do chatId. O objeto Msg é
criado a partir do id de user e do texto da mensagem e encaminhado
para o médodo Chat.deliverMsg(msg). Cabe ao chat a responsabilidade
de colocar a mensagem do emissor no inbox de todos os outros usuários
do chat.


---
## Chat

        - id: String

Cada chat possui um identificador único entre todos os chats.

        # inboxes: Inbox[0..*]

Cada chat precisa possuir as referências ao usuários que dele fazem parte. Associado a cada usuário existe um inbox que guarda as mensagens destinadas a este usuário. Um Inbox é uma Tupla(User, Msg[]) que guarda a referência ao
objeto user e a lista de mensagens deste usuário.

        + getMsgs(userId): Msg[]

Procura o usuário em this.inboxes, obtem sua lista de mensagens. Ao retornar
a lista de mensagens, a lista que fica no inbox deve ser zerada para evitar 
que o usuário obtenha duas vezes a mesma mensagem.

        + deliverZap(msg: Msg)

A class user inicia a comunicação criando o objeto Msg e encaminhando ao chat. Cabe ao chat verificar se essa msg pertence a um usuário que faça parte do grupo e colocar a referência à mensagem nas caixas de entrada de todos os **outros** usuários do chat.

        + unreadCount(userId): int

Retorna quantas mensagens este usuário possui no chat.
    
        + addUserChat(user: User)

Adiciona um usuário na lista de usuários do chat criando um inbox para
ele na lista de inboxes. Também adiciona o próprio chat na lista de chats
do usuário.

        + rmUserChat(user: User)

Remove o usuário **user** do chat removendo sua respectiva Inbox, e remove o objeto chat da lista de chats de **user**.

---
### Classes Adicionais

Crie o Contrutor e o método toString mais apropriado para cada classe.

```
*Notify*
--
+ chatId: String
+ unreadCount: int
--

###################

*Msg*
--
+ userId: String
+ text: String
--

###################

*Inbox*
--
+ user: User
+ msgs: Msg[]
--

```
