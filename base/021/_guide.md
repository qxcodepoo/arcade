***
layout: post
title: Matricula Guide
***

## Orientacoes

Temos algumas complicações aqui. Vamos fazer a matricula chamando
adicionar aluno em disciplina ou chamando adicionar disciplina na
class aluno?

Precisamos manter as informações em ambas as entidades. Uma possibilidade
é manter as listas públicas e implementar o método de inserir apenas
em uma das entidades. Assim o método pode fazer alterações em ambas
as listas.

Em c++, temos a funcionalidade do friend, que permite deixar as listas
privadas e dar acesso apenas à classe que queremos permitir modificar as
listas.

Uma outra forma mais trabalhosa, porém mais segura é permitir matrícula
vindo de qualquer uma das classes e colocar alguns controles para evitar
o loop. É assim que está apresentado à seguir, mas sinta-se livre para
usar o método que preferir para executar o exercício.

Obs: em java você pode atribuir visibilidade de pacote, o que garante que
fora do pacote, nenhuma classe terá acesso à variável. Você pode também
utilizar a notação do python com __ na frente da variável. Essa notação
significa dizer "olhar a variável/método é público, mas eu sugiro veementemente
que você não mexa nele".

``` python
class Discp:
    m_aluno #mapa<id, Aluno>
    idDiscp #nome da disciplina;

    def constructor(nome)
    # inicialize todos os atributos

    def matricular(aluno)
    # se ja tem o aluno em m_aluno
        # retorne
    # adicione o aluno em m_aluno
    # chame aluno.addDisc

    def desmatricular(idAluno)
    # tente pegar o aluno em m_aluno
    # se aluno nao existe
        # retorne
    # remova aluno de m_aluno
    # chame aluno.rmDisc
    
    def getAllAlu()
        # retorna o array de alunos da disciplina

    def toString()
        # o nome da disciplina

class Aluno:
    # a lista que guarda os alunos
    # sugiro que implemente como Map<string, Discp>
    m_discp 
    
    idAluno #nome do aluno

    def constructor(idAluno)
    # inicialize TODAS as variavies

    def matricular(discp)
    # aqui vai o MESMO codigo de insercao disciplina
    # so que utilizando as variaveis de Aluno

    def desmatricular(idDiscp)
    # o mesmo codigo de remover de disciplina refletido

    def toString()
    # retorna o nome do aluno
```

