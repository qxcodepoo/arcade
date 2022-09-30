# Anotações

![](cover.jpg)

[](toc)

- [Funcionalidades](#funcionalidades)
- [Shell](#shell)
- [Diagrama](#diagrama)
- [Ajuda](#ajuda)
[](toc)

O objetivo dessa atividade é criar um pequeno serviço de anotações. O sistema terá vários usuários que vão logar utilizando login e senha. Cada usuário pode armazenar notas de texto contendo título e texto.

## Funcionalidades

- Criar usuário passando username e password.
    - Usernames devem ser únicos no sistema.
- Mostrar os usernames cadastrados no sistema.
- Logar e deslogar na conta de um usuário.
- Adicionar uma nota com título e texto.
    - A primeira palavra é o título, o resto é o texto.
- Mostrar notas

## Shell

```python
#__case add
#addUser _username _pass
#fail: usuario ja existe

$addUser david 123
$addUser luana 541

# Mostra os usuários cadastrados
#showUsers
$users
[ david luana ]

#__case login
#login _username _pass

$login david 144
fail: senha invalida
$login davi 123
fail: usuario nao encontrado

$login david 123
$show
user: david

#__case logout
#logout
#fail: ninguem logado
$logout

$logout
fail: ninguem logado

#__case notes

#addNote _titulo _texto
#fail: ninguem logado
$login david 123
$addNote compras comprar banana ovo xilito mexirica e melancia
$addNote farmacia comprar tilenol, omeprazol, doril e soro

$show
user: david
[0:compras:comprar banana ovo xilito mexirica e melancia]
[1:farmacia:comprar tilenol, omeprazol, doril e soro]

$logout
$login luana 541
$addNote beleza fazer as unhas, limpeza de pele, massagem linfatica
$addNote filmes_favoritos moana, ariel, bela adormecida
$addNote cores azul, vermelho, verde, anil

$show
user: luana
[0:beleza:fazer as unhas, limpeza de pele, massagem linfatica]
[1:filmes_favoritos:moana, ariel, bela adormecida]
[2:cores:azul, vermelho, verde, anil]

$logout
$login david 123
$show
user: david
[0:compras:comprar banana ovo xilito mexirica e melancia]
[1:farmacia:comprar tilenol, omeprazol, doril e soro]
$end

```

## Diagrama
![](diagrama.png)

## Ajuda
- O objetivo é dividir as responsabilidades entre o Sistema e o Gerenciador de Login.
- Ambos compartilham a mesma estrutura de dados que contém os usuários `users: map<string, User>`.
- O Sistema é responsável por adicionar e remover Usuários e Notas.
- O Gerenciador de Login é responsável por efetuar as operações de `login`, `logout` e `getCurrentUser`.
- O getCurrentUser pode ser utilizado para obter o usuário corrente ou disparar uma exceção caso ninguém esteja logado.
