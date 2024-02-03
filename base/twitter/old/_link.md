---
layout: post
title:  "Twitter"
category: 'Adept'
introduction: Twitte para seus seguidores e dê like quando gostar daquilo que alguém disse.
description: 
image: '/assets/twitter/cover.jpg'
tags:
- agregação
- excessões
---

Vamos implementar o modelo do twitter. Os usuários se cadastram e podem follow outros usuários do sistema. Ao twittar, a mensagem vai para timeline de todas as pessoas que a seguem.

---
## Habilidades

- Nessa atividade o mesmo objeto User estará armazenado no repositório de usuários, como também nas listas de seguidores e seguidos do próprio usuário. 
- Também o objeto Tweet estará tanto na lista de meusTweets do usuário que postou como na timeline de seus seguidores. Dado que é o mesmo objeto tweet, quando uma usuário dá like e altera o objeto, todos vêem quem deu o like. 
- Tweets são gerados através de uma Classe Geradora de Tweets.
- Também User utiliza um contador de mensagem não lidas para mostrar apenas as novas mensagens.

---
## Funcionalidades
- **[2.0 P] Repositório de Usuários**
    - Adicionar usuário passando username.
    - Mostrar os usuários cadastrados.

- **[2.0 P] Seguir e ser seguido**
    - Seguir um outro usuário cadastrado.
    - Mostrar a lista de seguidores.
    - Mostrar a lista de seguidos.

- **[4.0 P] Voa passaarinho**
    - twittar um tweet com várias palavras.
        - o id de um tweet é único globalmente.
        - o tweet de um usuário vai para o início da timeline de seus seguidores.
        - o mesmo tweet vai também para sua própria lista de minhas mensagens.
    - mostrar as mensagens que você enviou.

- **[1.0 P] Quais as novidades?**
  - Mostrar apenas as mensagens não lidas.

- **[1.0 P] Gostei dei like**
    - Dar like num tweet da sua timeline.

---
## Comandos e Exemplos

```bash
##################################
# Repositório de Usuários
##################################
#__case cadastrar
$addUser goku
$addUser sara
$addUser tina
$show
goku
  seguidos   [ ]
  seguidores [ ]
sara
  seguidos   [ ]
  seguidores [ ]
tina
  seguidos   [ ]
  seguidores [ ]

##################################
# Seguir e ser seguido
##################################
#__case seguir

$follow goku sara
$follow goku tina
$follow sara tina
$show
goku
  seguidos   [ sara tina ]
  seguidores [ ]
sara
  seguidos   [ tina ]
  seguidores [ goku ]
tina
  seguidos   [ ]
  seguidores [ goku sara ]

##################################
# Voa passarinho
##################################
#__case twittar
#twittar _userId _msg

$twittar sara hoje estou triste
$twittar tina ganhei chocolate
$twittar sara partiu ru
$twittar tina chocolate ruim
$twittar goku internet maldita

$timeline goku
0:sara( hoje estou triste )
1:tina( ganhei chocolate )
2:sara( partiu ru )
3:tina( chocolate ruim )
4:goku( internet maldita )

$timeline tina 
1:tina( ganhei chocolate )
3:tina( chocolate ruim )

$timeline sara
0:sara( hoje estou triste )
1:tina( ganhei chocolate )
2:sara( partiu ru )
3:tina( chocolate ruim )

##################################
# Gostei dei like
##################################
#__case like
#like _username _idTw

$like sara 1
$like goku 1
$like sara 3

$timeline sara
0:sara( hoje estou triste )
1:tina( ganhei chocolate )[ sara goku ]
2:sara( partiu ru )
3:tina( chocolate ruim )[ sara ]

$timeline goku
0:sara( hoje estou triste )
1:tina( ganhei chocolate )[ sara goku ]
2:sara( partiu ru )
3:tina( chocolate ruim )[ sara ]
4:goku( internet maldita )


##################################
# Errinhos
##################################
#__case erros

# lembre de tratar erros como
$timeline bruno
fail: usuario nao encontrado
$follow goku kuririm
fail: usuario nao encontrado
$like sara 8
fail: tweet nao existe
$end
##################################
# FIM FIM FIM FIM FIM FIM FIM FIM#
##################################
```

---
## Orientações

```python

class Tweet:
    # nao esqueca de nenhum atributo
    def constructor(idTw, username, msg):
        # inicialize tudo direitinho

    def darLike(username):
        # adicione username na lista se ja nao existir

    def toString():
        # saida = _idTw _username: _msg {likes}

class User:
    # adicione o resto dos atributos

    # utilize alguma estrutura de dados de lista ligada
    # que permita inserção no começo da lista

    naoLidos: int

    timeline: Tweet[]
    myTweets: Tweet[]

    seguidores: User[]
    seguidos: User[]

    def constructor(username):
        # nao esqueca de inicializar nenhum atributo

    def follow(other: User):
        # other entra na minha lista de seguidos
        # this  entra na lista de seguidores de other

    def twittar(tweet):
        # adiciono o tweet na minha lista de myTweets
        # para cada um dos meus seguidores
            # incremente a contagem de nao lidas
            # adicione o tweet na timeline deles

    def darLike(idTw):
        # procure o tweet na sua timeline
        # se existir, chame o tweet.darLike(this.username)

    def get unread():
        # verifica contador de naoLidos
        # pega as mensagens da timeline até a quantidade necessária
        # lembre de zerar a contagem de nao lidos

    def get timeline():
        # retorna a timeline
        # lembre de zerar a contagem de nao lidos

    def toString():
        # retorne username

# Tem como responsabilidade gerar um tweet com 
# id unico, guardando o tweet gerado no repositorio
# de tweets. 
class TweetGenerator:
    # referencia para o repositorio de tweet
    r_tw: Repository<Tweet>*
    nextId: int

    def construtor(r_tw):
        # o controller vai criar o gerador
        # passando como referencia o repositorio
        # de tweets. Assim o gerador sabe como 
        # guardar os tweets armazenados.

    def create(username, msg): Tweet*
        # cria um tweet para esse usuario
        # adiciona no repositorio
        # incrementa o nextId
        # retorna a referencia ao tweet criado
```
