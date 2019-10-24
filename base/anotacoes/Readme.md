## 52 Serviço de Anotações #composição #login #ordenação
### Sinto saudades do meu finado palmtop, onde escrevia de canetinha todos os meus insights. Com essa parada de smathphone e trocentos aplicativos de anotações, perdeu foi a graça.
![](figura.jpg)


O objetivo dessa atividade é criar um pequeno serviço de anotações. O sistema
terá vários usuários que vão logar utilizando login e senha. Cada usuário pode
armazenar notas de texto contendo título e texto.

## Vídeo Explicativo

<iframe width="640" height="360" src="https://www.youtube.com/embed/ggOdp0Eh7fc" frameborder="0" allowfullscreen></iframe>

## Funcionalidades

- **[1.0 P]** Criar usuário passando username e password.
    - Usernames devem ser únicos no sistema.

- **[1.0 P]** Mostrar os usernames cadastrados no sistema.

- **[2.0 P]** Logar e deslogar na conta de um usuário.

- **[1.0 P]** Mudar password.

- **[1.0 P]** Adicionar uma nota com título e texto.
    - **[2.0 E]** Título deve ter uma palavra, mas o texto pode conter várias palavras.
        - Não deve ser possível inserir duas notas com o mesmo título para o mesmo usuário.

- **[1.0 E]** Apagar uma nota dado o título.

- **[1.0 P]** Mostrar notas

- **[1.0 P]** Inicialize seu sistema com alguns usuários e algumas notas.

## Exemplos

```python
#######################################
# Criar usuário
#######################################
addUser _username _password
  ok | usuario criado
  fail: username já existe

#######################################
# Mostrar usernames cadastrados
#######################################
showUsers
  _username1
  _username2
  ...

#######################################
# Logar e deslogar
#######################################
login _username _senha
  done
  fail: username não existe
  fail: senha inválida

logout
  ok
  fail: nenhum usuário logado

#######################################
# Mudar o password
#######################################
changePass _oldpass _newpass
  done
  fail: password errado
  fail: ninguém logado

#######################################
# Adicionar nota
#######################################
addNote _titulo _texto
  done
  fail: ninguem logado
  fail: titulo ja existe

#######################################
# Apagar uma nota
#######################################
rmNote _titulo
  done
  fail: nota não encontrada
  fail: ninguém logado


#######################################
# Mostrar notas
#######################################
showNotes
  _titulo1 _texto1
  _titulo2 _texto2
...

```

## Pontuação

```
[ ][1.0 P] addUser
[ ][1.0 P] showUsers
[ ][1.0 P] login
[ ][1.0 P] logout
[ ][1.0 P] changePass
[ ][1.0 P] addNote
[ ][1.0 P] showNotes
[ ][1.0 P] inicialização do sistema
[ ]     Total pontos

[ ][2.0 E] título deve ter uma palavra e o texto várias
[ ][1.0 E] apagar nota por título
[ ]        Total Extras
```

---
## Raio X

````java
class Nota
+ titulo: String
+ texto: String
--
+ toString(): String

class Usuario
- username: String
- password: String
- notas: List<Nota>
--
+ addNote(note: Nota): boolean
+ rmNote(titulo: String): boolean
+ changePass(oldPass: String, newPass: String): boolean
+ toString(): String

class Sistema
- usuarios: List<Usuario>
--
+ addUser(userName: String, password: String): boolean


````
