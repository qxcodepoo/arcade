# Repositório de POO

[](toc)

- [00. Introdução](#00-introdução)
- [01. Lógica](#01-lógica)
- [02. Uma classe](#02-uma-classe)
- [03. Modificadores de Acesso](#03-modificadores-de-acesso)
- [04. Agregação Simples](#04-agregação-simples)
- [05. ArrayList I - Arrays](#05-arraylist-i---arrays)
- [06. ArrayList II - Lista circular](#06-arraylist-ii---lista-circular)
- [07. ArrayList III - Array de tamanho fixo](#07-arraylist-iii---array-de-tamanho-fixo)
- [08. ArrayList IV - Organização](#08-arraylist-iv---organização)
- [09. Troca de Dados e Ordenação](#09-troca-de-dados-e-ordenação)
- [10. Excessões](#10-excessões)
- [11. Mapas Excessões](#11-mapas-excessões)
- [12. Herança I](#12-herança-i)
- [13. Lógica I](#13-lógica-i)
- [14. Herança II](#14-herança-ii)
- [15. Lógica II](#15-lógica-ii)
- [16. Herança III](#16-herança-iii)
[](toc)

---

## 00. Introdução
\________________ | \______________________ 
---------------- | ------------------------
![](.thumbs/038.jpg) | [@038 Introdução ao git](base/038/Readme.md)
![](---------------) | [Configuração C++]()
![](.thumbs/045.jpg) | [@045 Instalação Typescript](base/045/Readme.md)
![](.thumbs/044.jpg) | [@044 Relacionamentos](base/044/Readme.md)
![](---------------) | [Rodando os exercícios e os testes no Replit]()

## 01. Lógica
Exercícios de fup para aquecer o coração e o cérebro.

\________________ | \______________________ 
---------------- | ------------------------
![](.thumbs/000.jpg) | [@000 Estressados A: Busca](base/000/Readme.md)
![](.thumbs/040.jpg) | [@040 Estressados B: Contagem](base/040/Readme.md)
![](.thumbs/032.jpg) | [@032 Estressados C: Tranformações](base/032/Readme.md)
![](.thumbs/039.jpg) | [@039 Estressados D: Controles](base/039/Readme.md)


## 02. Uma classe
Nesse módulo, vamos aprender como criar uma classe e como se relacionam atributos e métodos.
- No **Carro**, você controla as pessoas que entram e saem, a gasolina e sai para passear.
- Na **Calculadora**, você pode realizar operações desde que haja bateria, o resultado pode ser consultado no visor.

\________________ | \______________________ 
---------------- | ------------------------
![](.thumbs/001.jpg) | [@001 Calculadora ](base/001/Readme.md)
![](.thumbs/002.jpg) | [@002 Carro ](base/002/Readme.md)

## 03. Modificadores de Acesso
A partir desse módulo, você deve estar atento aos modificadores de acesso `public` e `private`. Utilize os métodos `set` para controlar as alterações realizadas nos atributos. 
- No **Tamagotchi**, o setFome(valor) garante que a fome nunca seja maior que o máximo ou menor que 0 e muda o flag para morto caso chegue a 0.
- No **Relógio**, o setHora(valor) garante que a hora sempre será um valor entre 0 e 23.
- No **Porquinho**, o getValor() só deve retornar o valor se o porco estiver quebrado.

\________________ | \______________________ 
---------------- | ------------------------
![](.thumbs/036.jpg) | [@036 Relógio ](base/036/Readme.md)
![](.thumbs/006.jpg) | [@006 Tamagotchi ](base/006/Readme.md)
![](.thumbs/017.jpg) | [@017 Porquinho ](base/017/Readme.md)
![](.thumbs/042.jpg) | [@042 Carro Get e Set](base/042/Readme.md)

## 04. Agregação Simples
A partir desse módulo, você precisará estar atento às relações entre classes e objetos. Na agregação, a relação entre eles não define vínculos de tempo de vida. Caso o todo seja destruído, o objeto que está sendo agregado não é destruído.
- A **Lapiseria** recebe o objeto grafite, enquanto estiver escrevendo, ela vai gastando o grafite e quando o grafite for muito pequeno e não der mais para escrever ela remove o objeto grafite ficando com `null` na referência. A lapiseira não "cria" o grafite, ela apenas recebe o objeto. Também não o destroi, mas devolve sua referência.
- Na **Motoca**, a moto recebe e referencia a criança que está a utilizando para passear no parque.

\________________ | \______________________ 
---------------- | ------------------------
![](.thumbs/004.jpg) | [@004 Grafite ](base/004/Readme.md)
![](.thumbs/003.jpg) | [@003 Motoca ](base/003/Readme.md)

## 05. ArrayList I - Arrays
Aqui, começaremos o uso de estruturas de dados como arrays e listas ligadas. Lidaremos com estruturas de tamanho fixo e tamanho variável. 
- Na **Budega** temos uma fila de espera e um vetor de caixas atendendo. A fila de espera começa vazia e cresce em tamanho conforme os clientes entram e decrementa conforme os clientes são chamados ao caixa. Os caixas entretanto são um vetor de tamanho fixo. Se existem 4 caixas, você modela como um vetor de tamanho 4, onde todos os valores iniciais são `null`. Para saber se um caixa está livre, você deve verificar se o valor do vetor nesse índice é `null`.

\________________ | \______________________ 
---------------- | ------------------------
![](.thumbs/037.jpg) | [@037 Budega ](base/037/Readme.md)
![](.thumbs/020.jpg) | [@020 Lapiseira ](base/020/Readme.md)

## 06. ArrayList II - Lista circular

\________________ | \______________________ 
---------------- | ------------------------
![](.thumbs/041.jpg) | [@041 Tabuleiro](base/041/Readme.md)
![](.thumbs/009.jpg) | [@009 Pula pula ](base/009/Readme.md)

## 07. ArrayList III - Array de tamanho fixo

\________________ | \______________________ 
---------------- | ------------------------
![](.thumbs/010.jpg) | [@010 Cinema ](base/010/Readme.md)
![](.thumbs/012.jpg) | [@012 Topic ](base/012/Readme.md)
![](.thumbs/011.jpg) | [@011 JunkFood ](base/011/Readme.md)

## 08. ArrayList IV - Organização

\________________ | \______________________ 
---------------- | ------------------------
![](.thumbs/014.jpg) | [@014 Contato ](base/014/Readme.md)
![](.thumbs/007.jpg) | [@007 Tarifas ](base/007/Readme.md)


## 09. Troca de Dados e Ordenação

\________________ | \______________________ 
---------------- | ------------------------
![](.thumbs/024.jpg) | [@024 Mensagens](base/024/Readme.md)
![](.thumbs/015.jpg) | [@015 Busca ](base/015/Readme.md)

## 10. Excessões

\________________ | \______________________ 
---------------- | ------------------------
![](.thumbs/008.jpg) | [@008 Agiota](base/008/Readme.md)
![](.thumbs/028.jpg) | [@028 Bilheteria](base/028/Readme.md)

## 11. Mapas Excessões

\________________ | \______________________ 
---------------- | ------------------------
![](.thumbs/029.jpg) | [@029 Anotações](base/029/Readme.md)
![](.thumbs/031.jpg) | [@031 Clinica Veterinária](base/031/Readme.md)

## 12. Herança I

\________________ | \______________________ 
---------------- | ------------------------
![](.thumbs/013.jpg) | [@013 Cadastro ](base/013/Readme.md)
![](.thumbs/030.jpg) | [@030 ContatoStar ](base/030/Readme.md)
![](.thumbs/043.jpg) | [@043 Cofre ](base/043/Readme.md)

## 13. Lógica I

\________________ | \______________________ 
---------------- | ------------------------
![](.thumbs/021.jpg) | [@021 Matrícula ](base/021/Readme.md)
![](.thumbs/025.jpg) | [@025 Twitter ](base/025/Readme.md)

## 14. Herança II

\________________ | \______________________ 
---------------- | ------------------------
![](.thumbs/023.jpg) | [@023 Salário ](base/023/Readme.md)
![](.thumbs/022.jpg) | [@022 Hospital I](base/022/Readme.md)

## 15. Lógica II

\________________ | \______________________ 
---------------- | ------------------------
![](.thumbs/026.jpg) | [@026 Whatsapp I ](base/026/Readme.md)
![](.thumbs/033.jpg) | [@033 Trem 1 ](base/033/Readme.md)

## 16. Herança III

\________________ | \______________________ 
---------------- | ------------------------
![](.thumbs/034.jpg) | [@034 Trem 2 ](base/034/Readme.md)
![](.thumbs/027.jpg) | [@027 Whatsapp II - Chat Pessoa](base/027/Readme.md)



