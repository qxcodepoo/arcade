---
layout: post
title: "Whatsapp Guide"
---

## Classes

```python


# classe sem mistérios, serve para conduzir informações
class Zap:
    # faca construtor e inicizalizações
    def toString():
        return "[" + userId + ": " + msg + "]";



class User:
    #guarde um mapa de nome do chat para sua referencia ao chat
    map<string, Chat> lista_chat
    userId


    def constructor(chatId ):
        # inicialize tudo

    def getChats():
    # retorne uma lista com os identificadores dos chats

    def getOverview():
    # monte uma string com o nome de cada chat e se existir, 
    # a quantidade de mensagens não lidas no chat

    def assertChat(chatId):
    # sugito criar esse método que testa se esse user tem
    # um chat com esse nome. Se não existir, lance uma excessão.
    # você pode usar esse métodos em todos os outros abaixo
    # para garantir estar trabalhando com dados válidos 

    def invite(chatId, user):
    # teste se o chat existe
    # obtenha o objeto chat
    # se o usuario ja esta no chat, retorne
    # abra um registro para esse usuario no chat
    # adicione esse chat na lista dos usuarios
    # se as mensagens de InOut estiverem habilitadas
        # envie uma mensagem avisando que o novo usuario chegou


    def leave(chatId):
    # teste se voce tem esse chat
    # se retire da lista do chat
    # retire o chat da sua lista
    # se habilitado, mande mensagem avisando que voce saiu

    def sendZap(msg, chatId):
    # teste se voce tem esse chat
    # obtenha o objeto chat
    # delegue para o chat entregar o objeto Zap que voce criou

    def toString():
    # retorne o userId
    


class Registro:
    user #referencia para usuario
    unreadCount # contagem de mensagens nao lidas

    def constructor(user):
    # inicie todas as variaveis



class Chat:

    # onde voce guarda o mapeamento entre nomes de usuario,
    # as referencias para o usuario e a contagem de mensagens
    # nao lidas
    lista_reg

    lista_zap # a lista de mensagens do grupo    

    # para saber se deve notificar entradas e saidas do grupo
    # static define que ela pertence à classe Chat
    static bool enableInOutMsgs; 

    # crie essa variavel static e const para definir
    # que o username system é reservado para notificacoes do sistema 
    static const string systemUsername = "system"
    
    #id do chat
    string chatId;

    def constructr(chatId):
    # inicialize TUDO

    # antes de fazer os convites, o primeiro usuário precisar ser
    # adicionado ao grupo. Utilize esse método após criar o grupo.
    def addFirstUser(user):
    # teste se a lista de usuarios esta vazio
    # adicione o usuario
    # se adicione a lista de grupos do usuario

    def getUsers():
    # retorne uma lista com as chaves dos usuarios

    def assertUser(user):
    # mesma logica do assertChat

    def deliverZap(zap):
    # se nao for um zap do sistema, teste se o usuario esta no chat
    # adicione o zap na lista do grupo
    # para cada usuario do grupo
        # se ele nao for o emissor
            # incremente o contador de nao lidos

    def getUnreadCount(userId):
    # retorne a quantidade de mensagens nao lidas desse user

    def getUnread(userId):
    # teste se usuario existe no grupo
    # crie lista de retorno
    # veja quantas sao as mensagens nao lidas desse usuario
    # já coletando mensagens do grupo que nao forem emitidas
    # por esse usuario ate atingir a quantidade de nao lidas.
    # zere a quantidade de mensagens nao lidas
    # se nao houver mensagens, retorne que nao ha mensagens

    def hasUser(userId):
    # retorne se o usuario esta nesse grupo
    
    def toString():
    # retorne chatId
```



