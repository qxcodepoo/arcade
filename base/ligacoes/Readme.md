## Serviço de Ligações #agregação #repositório #observer
### Você digita o número de Maria no celular e aparece que você está ligando pra João. Hum, alguma coisa errada não está certa.
![](figura.jpg)

Vamos criar o módulo que gerencia ligações da nossa agenda telefônica. Ele vai ser capaz de encontrar o número da agenda que corresponde à aquele número, montar nossa lista de contatos mais ligados e histórico de ligações.

## Funcionalidades

- Adicionar contatos passando idCont e uma lista de telefones.
    - 
    - idCont deve ser único no sistema, idFone único para o contato e número deve obedecer as regras do trabalho anterior.
    - Caso haja qualquer erro no contato, não faça inserção do contato.
    - Retorne os contatos ordenados pelo nome

```
# addCont _idCont _idFone;_number _idFone;_number ...
addCont silva oi;8832 tim;9934 casa;3232
  done
addCont gomes casa;3235
  done
addCont joao
  done
addCont maria oi;8831 tim;9931 claro;r43
  fail: numero invalido
getAllCont
  - gomes [casa 3235]
  - joao
  - silva [oi 8832][tim 9934][casa 3232]
```

- Atualizar contato informando os dados novamente.
- Remover contato pelo id.

```
updateCont gomes vivo;8635 casa;1212 oi;123
  done
getAllCont
  - gomes [casa 3235]
  - joao
  - silva [oi 8832][tim 9934][casa 3232]
delCont joao
  done
getAllCont
  - gomes [vivo 8635][casa 1212][oi 123]
  - silva [oi 8832][tim 9934][casa 3232]
```

- Favoritar, desfavoritar e ver favoritos pelo idCont
- Contatos favoritados começam com @ ao invés de -
- Buscar contato por padrão.

```
addCont alves oi;123
  done
fav alves
  done
fav silva
  done
getAllCont
  @ alves [oi 123]
  - gomes [vivo 8635][casa 1212][oi 123]
  @ silva [oi 8832][tim 9934][casa 3232]
getFav
  @ alves [oi 123]
  @ silva [oi 8832][tim 9934][casa 3232]
desfav silva
  done
getFav
  @ alves [oi 123]
getAllCont
  @ alves [oi 123]
  - gomes [vivo 8635][casa 1212][oi 123]
  - silva [oi 8832][tim 9934][casa 3232]
search casa
  - gomes [vivo 8635][casa 1212][oi 123]
  - silva [oi 8832][tim 9934][casa 3232]
```

- Ligar pra um número, incrementando no contato a quantidade de vezes que ele recebeu uma ligação.
- Mostrar a sppedList, uma lista cos contatos ordenandos pela quantidade de ligações recebidas, começando pelos que receberam mais ligações primeiro.
- Se o número ligado pertencer a vários contatos, quando ligar mostre apenas o primeiro que encontrar na ordem alfabética.
- Se o número ligado pertencer a vários contatos, incremente o contador de ligações em todos eles.
- Se não encontrar contato, mostre apenas o número.
- Atualize o toString do contato para apresentar o contador de ligações.

```
ligar 8832
  ligando silva
ligar 123
  ligando alves
ligar 9934
  ligando silva
ligar 555
  ligando 555
speedList
  - silva {2 lig}[oi 8832][tim 9934][casa 3232]
  @ alves {1 lig}[oi 123]
  - gomes {1 lig}[vivo 8635][casa 1212][oi 123]
```

- Mostrar histórico de ligações. Informe o número ligado e todos os contatos que batem com o número ligado.
- Caso o contato não exista. Crie um contato temporário com o telefone como nome e telefone apenas para mostrar.
- Caso algum contato seja removido ou alterado, mantenha a integridade do histórico e do speedList

```
historico
  call 8832
  - silva {2 lig}[oi 8832][tim 9934][casa 3232]
  call 123
  @ alves {1 lig}[oi 123]
  - gomes {1 lig}[vivo 8635][casa 1212][oi 123]
  call 9934
  - silva {2 lig}[oi 8832][tim 9934][casa 3232]
  call 555
  - 555 {1 lig}[fone 555]
rm alves
  done
updateCont silva oi;8832 casa;3232
  done
speedList
  - silva {2 lig}[oi 8832][casa 3232]
  - gomes {1 lig}[vivo 8635][casa 1212][oi 123]
historico
  call 8832
  - silva {2 lig}[oi 8832][casa 3232]
  call 123
  - gomes {1 lig}[vivo 8635][casa 1212][oi 123]
  call 9934
  - 9934 {1 lig}[fone 9934]
  call 555
  - 555 {1 lig}[fone 555]
```

## Diagrama de Classes

- Métodos Get e Set de atributos básicos omitidos.

![](/assets/ligacoes/diagrama.png)
