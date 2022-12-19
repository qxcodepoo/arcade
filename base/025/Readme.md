# Twitter

![cover](cover.jpg)

[](toc)

- [Vídeo com a explicação do projeto](#vídeo-com-a-explicação-do-projeto)
- [Módulos](#módulos)
- [Comandos e Exemplos](#comandos-e-exemplos)
- [Diagrama](#diagrama)
- [Métodos](#métodos)
- [Esqueleto C++](#esqueleto-c)
[](toc)

Vamos implementar o modelo do twitter. Os usuários se cadastram e podem follow outros usuários do sistema. Ao twittar, a mensagem vai para timeline de todas as pessoas que a seguem. Ao dar like, todos os usuários em suas timelines vêem os likes.

***

## Vídeo com a explicação do projeto

[![_](player.png)](https://www.youtube.com/watch?v=75-YyuNrOsc)

***

## Módulos

- cadastrar
  - Adicionar usuário passando username.
  - Mostrar os usuários cadastrados.
- follow
  - Seguir um outro usuário cadastrado.
  - Mostrar a lista de seguidores.
  - Mostrar a lista de seguidos.
- twittar
  - Twittar um tweet com várias palavras.
    - O id de um tweet é único globalmente.
    - O tweet de um usuário vai para o início da timeline de seus seguidores.
    - O mesmo tweet vai também para sua própria timeline.
  - Mostrar a timeline de um usuário.
- like
  - Dar like num tweet da sua timeline.
- unfollow
  - Deixar de seguir um usuário.
  - Remover todos os tweets desse usuario da sua timeline.
- retweet
  - Retweetar um tweet da sua timeline.
  - Um novo tweet é criado e ele contém uma referência ao tweet original.
- remover
  - Remover um usuário do sistema.
  - Desfazer todos os vínculos de seguidores e seguidos dele.
  - Marcar todos os tweets dele no sistema como deletados.
  - Tweets deletados não aparecem nas timelines
  - Se um tweet é deletado, nos rt deve aparecer "esse tweet foi removido".

***

## Comandos e Exemplos

```bash
##################################
#__case cadastrar
##################################
$add goku
$add sara
$add tina
$show
goku
  seguidos   []
  seguidores []
sara
  seguidos   []
  seguidores []
tina
  seguidos   []
  seguidores []

##################################
#__case follow
##################################

$follow goku sara
$follow goku tina
$follow sara tina
$show
goku
  seguidos   [sara, tina]
  seguidores []
sara
  seguidos   [tina]
  seguidores [goku]
tina
  seguidos   []
  seguidores [goku, sara]

##################################
#__case twittar
##################################
#twittar _userId _msg

$twittar sara hoje estou triste
$twittar tina ganhei chocolate
$twittar sara partiu ru
$twittar tina chocolate ruim
$twittar goku internet maldita

$timeline goku
4:goku (internet maldita)
3:tina (chocolate ruim)
2:sara (partiu ru)
1:tina (ganhei chocolate)
0:sara (hoje estou triste)

$timeline tina 
3:tina (chocolate ruim)
1:tina (ganhei chocolate)

$timeline sara
3:tina (chocolate ruim)
2:sara (partiu ru)
1:tina (ganhei chocolate)
0:sara (hoje estou triste)

##################################
#__case like
##################################
#like _username _idTw

$like sara 1
$like goku 1
$like sara 3

$timeline sara
3:tina (chocolate ruim) [sara]
2:sara (partiu ru)
1:tina (ganhei chocolate) [goku, sara]
0:sara (hoje estou triste)

$timeline goku
4:goku (internet maldita)
3:tina (chocolate ruim) [sara]
2:sara (partiu ru)
1:tina (ganhei chocolate) [goku, sara]
0:sara (hoje estou triste)


##################################
#__case unfollow
##################################

$unfollow goku tina
$show
goku
  seguidos   [sara]
  seguidores []
sara
  seguidos   [tina]
  seguidores [goku]
tina
  seguidos   []
  seguidores [sara]

$timeline goku
4:goku (internet maldita)
2:sara (partiu ru)
0:sara (hoje estou triste)

##################################
#__case retweet
##################################

$timeline sara
3:tina (chocolate ruim) [sara]
2:sara (partiu ru)
1:tina (ganhei chocolate) [goku, sara]
0:sara (hoje estou triste)

$rt sara 3 olha goku, ela nao gostou do seu chocolate
$timeline sara
5:sara (olha goku, ela nao gostou do seu chocolate)
    3:tina (chocolate ruim) [sara]
3:tina (chocolate ruim) [sara]
2:sara (partiu ru)
1:tina (ganhei chocolate) [goku, sara]
0:sara (hoje estou triste)

$timeline goku
5:sara (olha goku, ela nao gostou do seu chocolate)
    3:tina (chocolate ruim) [sara]
4:goku (internet maldita)
2:sara (partiu ru)
0:sara (hoje estou triste)

##################################
#__case erros
##################################

# lembre de tratar erros como
$timeline bruno
fail: usuario nao encontrado
$follow goku kuririm
fail: usuario nao encontrado
$like sara 4
fail: tweet nao existe

##################################
#__case remover
##################################
$follow tina sara
$show
goku
  seguidos   [sara]
  seguidores []
sara
  seguidos   [tina]
  seguidores [goku, tina]
tina
  seguidos   [sara]
  seguidores [sara]

$rm tina
$show
goku
  seguidos   [sara]
  seguidores []
sara
  seguidos   []
  seguidores [goku]

$timeline goku
5:sara (olha goku, ela nao gostou do seu chocolate)
    3: (esse tweet foi deletado)
4:goku (internet maldita)
2:sara (partiu ru)
0:sara (hoje estou triste)

$timeline sara
5:sara (olha goku, ela nao gostou do seu chocolate)
    3: (esse tweet foi deletado)
2:sara (partiu ru)
0:sara (hoje estou triste)

$end

##################################
# FIM FIM FIM FIM FIM FIM FIM FIM#
##################################
```

***

## Diagrama

![diagrama](diagrama.png)

***

## Métodos

[](load)[](diagrama.puml)[](filter:fenced:plantuml)

```plantuml

class Tweet {
    
    - id: int
    
    - username: str
    
    - msg: str
    
    ' guarda os username dos usuarios que deram like
    - likes: set<str>
    
    ' guarda o tweet original que foi retweetado
    - rt: Tweet
    
    __
    
    + Tweet(id: int, username: str, msg: str)
    
    + getId(): int
    
    + getSender(): str
    
    + getMsg(): str
    
    ' retorna as informacoes do tweet
    ' no modulo de likes e retweet
    ' esse método deve ser alterado conforme requisitos
    + toString() : str
    
    __like__
    
    ' adiciona o nome do usuario na lista de likes
    + like(username : str)
    
    ' retorna o nome dos usuarios que deram like
    + getLikes() : set<str>
    '
    __retweet__
    
    ' define que tw é o tweet original que está sendo retuitado
    ' o metodo toString deve mostrar o tweet original
    + setRt(tw : Tweet)
    
    __remover__
    
    ' marca se o tweet foi deletado
    - deleted: boolean
    
    ' marca o tweet como deletado
    ' substitui o texto da mensagem por "esse tweet foi deletado"
    ' apaga o username
    ' limpa a lista de likes
    + setDeleted()
    
    ' retorna true se o tweet foi deletado
    + isDeleted() : boolean
    '
}

class Inbox {
    
    - timeline: map<int, Tweet>
    
    - myTweets: map<int, Tweet>
    '
    __
    
    + Inbox()
    
    __twittar__
    
    ' adiciona um tweet na timeline
    + storeInTimeline(tweet : Tweet)
    
    ' retornam todos os tweets da timeline que não estiverem deletados
    ' os tweets mais recentes devem ficar primeiro na lista
    + getTimeline() : List<Tweet>
    
    ' retorna a timeline do usuario
    + toString(): str
    
    __like__
    
    ' obtem e retorna o tweet com o id passado da timeline
    ' ou dispara uma exceção se ele não existir
    + getTweet(id : int) : Tweet
    
    __unfollow__
    
    ' remove todos os tweets emitidos por esse usuario da sua timeline
    ' quando alguem deixa de seguir um usario, apaga todos os tweets 
    ' dele na sua timeline
    + rmMsgsFrom(username : str)
    
    __remover__
    
    ' adiciona um tweet no myTweets do usuario
    + storeInMyTweets(tweet : Tweet)
    
    ' retorna todos os tweets emitidos pelo usuario
    + getMyTweets() : List<Tweet>
    '
}

class User {
    
    - username: str
    
    - inbox: Inbox
    
    - followers: map<str, User>
    
    - following: map<str, User>
    
    __
    
    + User(username : str)
    
    ' mostra o nome dos seguidos e o nome dos seguires
    + toString(): str
    
    __follow__
    
    ' voce não pode seguir a voce mesmo
    ' se ainda nao estiver seguindo o usuario other
    '   adiciona other na lista de seguidos
    '   adiciona voce na lista de seguidores de other
    + follow(other : User)
    
    __twittar__
    
    + getInbox() : Inbox
    '
    ' coloca o tw no myTweets do usuario
    ' coloca o tw na timeline do usuario
    ' coloca o tw na timeline de todos os seguidores do usuario
    + sendTweet(tw : Tweet)
    
    __unfollow__
    
    ' se estiver seguindo esse username
    '   obtenha o objeto User correspondente na sua lista de seguidos
    '   remova ele da sua lista de seguidos
    '   remova todas as mensagens dele da sua timeline utilizando o metodo inbox.rmMsgsFrom(username)
    '   se remova da lista de seguidores dele
    + unfollow(other : str)
    
    __like__
    
    ' recupera o tweet com esse id da timeline do usuario
    ' invoca o método like do tweet
    + like(idTw : int)
    
    __remover__
    
    ' remove todos os seus seguidos
    ' se removendo também da lista de seguidores deles
    + unfollowAll()
    
    ' remove todos os seus seguidores
    ' se removendo também da lista de seguidos deles
    + rejectAll()
    '
}

class Controller {
    
    ' armazena o id para o proximo tweet a ser criado
    - nextTweetId: int
    
    ' armazena todos os usuarios do sistema
    - users: map<str, User>
    
    ' armazena todos os tweets do sistema
    - tweets: map<int, Tweet>
    
    __
    
    + Controller()
    
    ' se nao existe um usuario com esse username
    ' cria o usuario e armazena no mapa de usuarios
    + addUser(username : str)
    
    ' imprime todos os objetos usuarios do sistema
    + toString(): str
    
    __twittar__
    
    ' cria um novo objeto tweet com os dados passado
    ' utiliza o atributo nextTwId para gerar o id do tweet
    ' incrementa o atributo nextTwId
    ' armazena esse tweet no mapa de tweets
    ' retorna a referencia para o tweet criado
    - createTweet(sender: str, msg: str): Tweet
    
    ' retorna uma referencia para o objeto do usuario com esse username
    ' dispara uma excecao se o usuario nao existir
    + getUser(username : str) : User

    ' utiliza this.getUser para recuperar o objeto do usuario
    ' cria o tweet utilizando o this.createTweet e chama
    ' user.sendTweet(tweet) para entrega dos tweets nas timelines
    + sendTweet(username : str, msg : str)
    
    __retweet__
    
    ' recupera o user utilizando o this.getUser
    ' recupera o tweet original utilizando o user.getTweet
    ' cria um novo tweet com o tweet original e os outros parametros
    ' invoca user.sendTweet(tweet) para entrega dos tweets nas timelines
    + sendRt(username : str, twId : int, rtMsg : str)
    
    __remover__
    
    ' recupera o user utilizando o this.getUser
    ' remove todos os vínculos de seguidos e seguidores
    ' utilizando o user.unfollowAll() e user.rejectAll()
    ' marca todos os tweets de user.myTweets como deletados
    ' remove o user do mapa de usuarios
    + rmUser(username : str)
    
}

Controller "1" -* "0..*" Tweet
User "0..*" *- "1" Controller
User "1..*" o-- "0..*" User
User "1" --*  "1" Inbox
Inbox "1" --o "0..*" Tweet
@enduml

```

[](load)

***

## Esqueleto C++

[](load)[](solver.cpp)[](fenced:cpp:filter)

```cpp
#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <memory>
#include <sstream>
#include <algorithm>

namespace aux {
    double number(std::string text) {
        std::stringstream ss(text);
        double value {};
        if (ss >> value) {
            return value;
        }
        std::cout << "fail: (" << text << ") is not a number\n";
        return 0.0;
    }

    double operator+(std::string text) {
        return number(text);
    }

    std::vector<std::string> split(std::string line, char delimiter = ' ') {
        std::stringstream ss(line);
        std::vector<std::string> result;
        std::string token;
        while (std::getline(ss, token, delimiter)) {
            result.push_back(token);
        }
        return result;
    }

    template <class T, class FN> std::string join(T container, std::string sep, FN fn) { 
        std::stringstream ss;
        for (auto it = container.begin(); it != container.end(); ++it) {
            ss << (it == container.begin() ? "" : sep) << fn(*it);
        }
        return ss.str();
    }

    template <class T> std::string join(T container, std::string sep = ", ") {
        return join(container, sep, [](auto item) { return item; });
    }

    std::string input() {
        std::string line;
        std::getline(std::cin, line);
        return line;
    }

    template <class T> void write(T data, std::string end = "\n") {
        std::cout << data << end;
    }

    template <class DATA>
    std::string format(std::string format, DATA data) {
        char buffer[100];
        sprintf(buffer, format.c_str(), data);
        return buffer;
    }

    template<typename CONTAINER, typename FUNCTION>
    auto map(CONTAINER container, FUNCTION fn) {
        std::vector<decltype(fn(*container.begin()))> aux;
        std::transform(container.begin(), container.end(), std::back_inserter(aux), fn);
        return aux;
    }

    template<typename DATA>
    std::vector<DATA> slice(std::vector<DATA> container, int start, int end) {
        int size = container.size();
        if (start < 0) start = size + start;
        if (end < 0) end = size + end;
        std::vector<DATA> aux;
        for (int i = start; i < end; i++) {
            aux.push_back(container[i]);
        }
        return aux;
    }

    template<typename DATA>
    std::vector<DATA> slice(std::vector<DATA> container, int start = 0) {
        return slice(container, start, container.size());
    }

}


class TweetException : public std::exception {
    std::string message;
public:
    TweetException(const std::string& message) : 
        message(message) {
    }
    const char* what() const noexcept override {
        return message.c_str(); 
    }
};

class Tweet {
    int id;
    std::string username;
    std::string msg;
    std::set<std::string> likes;
    
    // ' guarda o tweet original que foi retweetado
    Tweet *rt {nullptr};

public:

    Tweet(int id, const std::string& username, const std::string& msg) { //todo 
    }

    int getId() const {
        return {}; // todo 
    }

    std::string getSender() const {
        return {}; // todo
    }

    std::string getMsg() const {
        return {}; // todo
    }

    std::string str() const {
        return {}; // todo
    }

    // __like__

    void like(const std::string& username) { 
    }

    std::set<std::string> getLikes() const {
        return {}; // todo
    }
    
    // __retweet__

    void setRt(Tweet *rt) {
    }
    
    // __remover__

    bool deleted {false};
    
    void setDeleted() {
    }

    bool isDeleted() const {
        return {}; // todo
    }
};

std::ostream& operator<<(std::ostream& os, const Tweet& msg) {
    return os << msg.str();
}

std::ostream& operator<<(std::ostream& os, Tweet* msg) {
    return os << msg->str();
}
//++

class Inbox {

    std::map<int, Tweet*> timeline;

    std::map<int, Tweet*> myTweets;
    
public:
    Inbox() {
    }

    void storeInTimeline(Tweet* tweet) {
        timeline[tweet->getId()] = tweet;
    }

    std::vector<Tweet*> getTimeline() const {
        std::vector<Tweet*> messages;
        for (auto it = timeline.rbegin(); it != timeline.rend(); ++it) {
            if (it->second->isDeleted() == false)
                messages.push_back(it->second);
        }
        return messages;
    }

    friend std::ostream& operator<<(std::ostream& os, const Inbox& inbox) {
        return os << aux::join(inbox.getTimeline(), "\n");
    }

    // __like__
    Tweet* getTweet(int id) {
        if(auto it = timeline.find(id); it != timeline.end())
            return timeline[id];
        throw TweetException("fail: tweet nao existe");
    }

    // __unfollow__

    void rmMsgsFrom(const std::string& username) {
        auto keysToRemove = std::vector<int>();
        for (auto& [key, tweet] : timeline)
            if (tweet->getSender() == username)
                keysToRemove.push_back(key);
        for (auto key : keysToRemove)
            timeline.erase(key);
    }

    // __remover__

    void storeInMyTweets(Tweet* tweet) {
        myTweets[tweet->getId()] = tweet;
    }

    std::vector<Tweet*> getMyTweets() const {
        std::vector<Tweet*> messages;
        for (auto it = myTweets.rbegin(); it != myTweets.rend(); ++it)
            messages.push_back(it->second);
        return messages;
    }
};

class User {

    std::string username;
    Inbox inbox;
    std::map<std::string, User*> followers;
    std::map<std::string, User*> following;

    // __
public:

    User(const std::string& username) : 
        username(username) {
    }

    // ' mostra o nome dos seguidos e o nome dos seguires
    // + toString(): str
    std::string str() {
        std::stringstream ss;
        ss << username << "\n" 
            << "  seguidos   [" << aux::join(aux::map(following, [](auto p) {return p.first;})) << "]\n"
            << "  seguidores [" << aux::join(aux::map(followers, [](auto p) {return p.first;})) << "]";
        return ss.str();
    }

    // __follow__
    void follow(User * other) {
        if(other == this)
            throw TweetException("You cannot follow yourself");
        if(following.count(other->username) == 1)
            throw TweetException("You are already following this user");
        following[other->username] = other;
        other->followers[username] = this;
    }

    // __twittar__

    Inbox& getInbox() {
        return inbox;
    }

    void sendTweet(Tweet * msg) {
        inbox.storeInTimeline(msg);
        inbox.storeInMyTweets(msg);
        for(auto& follower : followers)
            follower.second->getInbox().storeInTimeline(msg);
    }

    // __unfollow__

    void unfollow(std::string username) {
        if(following.count(username) == 0)
            throw TweetException("You are not following this user");
        auto other = following[username];
        
        this->inbox.rmMsgsFrom(username);
        following.erase(username);

        other->followers.erase(this->username);
    }

    // __like__

    void like(int twId) {
        inbox.getTweet(twId)->like(username);
    }

    // __remover__
    void unfollowAll() {
        for(auto& [username, user] : following) {
            user->followers.erase(this->username);
        }
        following.clear();
    }

    void rejectAll() {
        for(auto& [username, user] : followers) {
            user->following.erase(this->username);
        }
        followers.clear();
    }
};


std::ostream& operator<<(std::ostream& os, User user)                  { return os << user.str(); }
std::ostream& operator<<(std::ostream& os, User* user)                 { return os << user->str(); }
std::ostream& operator<<(std::ostream& os, std::shared_ptr<User> user) { return os << user->str(); }


// class Controller {
class Controller {
    // ' armazena o id para o proximo tweet a ser criado
    // - nextTweetId: int
    int nextTweetId { 0 };

    // ' armazena todos os usuarios do sistema
    // - users: map<str, User>
    std::map<std::string, std::shared_ptr<User>> users;

    // ' armazena todos os tweets do sistema
    // - tweets: map<int, Tweet>
    std::map<int, std::shared_ptr<Tweet>> tweets;

    // __
public:

    Controller() {}

    void addUser(std::string username) {
    }

    friend std::ostream& operator<<(std::ostream& os, const Controller& ctrl);

    // __twittar__

private:
    Tweet* createTweet(std::string username, std::string msg) {
    }
public:

    User* getUser(std::string username) {
    }

    void sendTweet(std::string username, std::string msg) {
    }

    // __retweet__

    void sendRt(std::string username, int twId, std::string msg) {
    }

    // __remover__

    void rmUser(std::string username) {
    }
};


std::ostream& operator<<(std::ostream& os, const Controller& ctrl) {
    return os << aux::join(aux::map(ctrl.users, [](auto p) {return *p.second;}), "\n");
}


using namespace aux;

int main() {
    Controller sistema;

    while(true) {
        auto line = input();
        write("$" + line);
        auto args = split(line, ' ');
        
        try {
            if      (args[0] == "end"     ) { break;                                                                     } 
            else if (args[0] == "add"     ) { sistema.addUser(args[1]);                                                  } 
            else if (args[0] == "rm"      ) { sistema.rmUser(args[1]);                                                   }
            else if (args[0] == "show"    ) { write(sistema);                                                            }
            else if (args[0] == "follow"  ) { sistema.getUser(args[1])->follow(sistema.getUser(args[2]));                }
            else if (args[0] == "unfollow") { sistema.getUser(args[1])->unfollow(args[2]);                               }
            else if (args[0] == "twittar" ) { sistema.sendTweet(args[1], join(slice(args, 2), " "));                     }
            else if (args[0] == "like"    ) { sistema.getUser(args[1])->like((int) +(args[2]));                     }
            else if (args[0] == "timeline") { write(join(sistema.getUser(args[1])->getInbox().getTimeline(), "\n"));     } 
            else if (args[0] == "rt"      ) { sistema.sendRt(args[1], (int) +(args[2]), join(slice(args, 3), " ")); } 
            else                            { write("fail: comando invalido");                                           }
        } catch (TweetException &e) {
            std::cout << e.what() << '\n';
        }
    }
    return 0;
}


```

[](load)