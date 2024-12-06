# Roupa com testes

## Descrição

- Vamos implementar uma classe que controla os possíveis valores de tamanho para uma roupa.
- Os tamanhos serão identificados como uma variável tipo texto, e os valores válidos são "PP", "P", "M" e "G", "GG" e "XG".
- Faça o objeto roupa iniciar o tamanho como uma string vazia, para expressar que nenhum tamanho foi atribuído.
- Crie um construtor que não recebe parâmetros e inicializa o tamanho como uma string vazia.
- Crie o método setTamanho que apenas aceita os valores válidos de tamanho.
  - Caso o valor seja inválido, avise e dê uma mensagem de erro informando quais os valores permitidos.
- Coloque o atributo tamanho como privado e crie um método getTamanho para acessá-lo e setTamanho para alterá-lo.

## Testes

```bash
#TEST_CASE
$show
size: ()

$size F
fail: Valor inválido, tente PP, P, M, G, GG ou XG

$show
size: ()

$size PP
$show
size: (PP)

$end

```
