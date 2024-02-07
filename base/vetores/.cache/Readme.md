# @vetores @vetores

Veja a versão online: [aqui.](https://github.com/qxcodepoo/arcade/blob/master/base/vetores/Readme.md)

<!-- toch -->
[Requisitos](#requisitos) | [Shell](#shell) | [Dica](#dica) | [Esqueleto](#esqueleto)
-- | -- | -- | --
<!-- toch -->

![cover](https://raw.githubusercontent.com/qxcodepoo/arcade/master/base/vetores/cover.jpg)

O objetivo da atividade é treinar estrutura de dados.

***

## Requisitos

Requisito:
- Utilize uma estrutura de armazenamento linear que permita elementos duplicados e mantenha a ordem de inserção.
- Sugestão:
    - C: array
    - C++: vector
    - Java: ArrayList


## Shell

```bash
#__case inicio
# O comando "$show" mostra os valores do vetor.
# O comando "$add V [V ...]" adiciona os valores no final da estrutura.
$show
[ ]
$add 1 2 3 4
$show
[ 1 2 3 4 ]
$end
```

***

```bash
#__case inicio
# O comando "$get ind" mostra o valor do vetor na posicao `ind`
# O comando "$set ind value" muda o valor da posicao `ind` para o valor `value`.
$show
[ ]
$add 1 2 3 4
$get 0
1
$get 3
4
$set 0 9
$show
[ 9 2 3 4 ]
$end
```

***

```bash
#__case rshow
# O comando "$rshow" mostra os valores da estrutura do último para o primeiro.
$rshow
[ ]
$add 1
$rshow
[ 1 ]
$add 2 3 5
$rshow
[ 5 3 2 1 ]
$end
```

***

```bash
#__case add_mais_elementos
$add 4 5 6 8 1 2 2 9
$add 2 2 2 8 9 0 1 4
$add 3 3 2 1
$show
[ 4 5 6 8 1 2 2 9 2 2 2 8 9 0 1 4 3 3 2 1 ]

#__case find_elemento
# O comando "$find V [V ...]" retorna o índice da primeira ocorrência dos valores procurado ou -1 se ele não existir.
$find 7
[ -1 ]
$find 6 8 9
[ 2 3 7 ]
$find 2 0 1 7 10
[ 5 13 4 -1 -1 ]
$end
```
```bash
#__case insert_indice
# O comando "$ins ind V" insere esse valor V na posição ind da estrutura.
# Se o ind for menor que 0, não faça a inserção.
# Se ind for maior que último índice válido, insira na última posição.
# Se ind for um índice válido, desloque todos os elementos a partir dessa posição, uma posição à frente.
$add 3 7
$show
[ 3 7 ]
$ins 0 2
$show
[ 2 3 7 ]
$ins 3 1
$show
[ 2 3 7 1 ]
$ins -2 5
$show
[ 2 3 7 1 ]
$ins 9 5
$show
[ 2 3 7 1 5 ]
$ins 2 6
$show
[ 2 3 6 7 1 5 ]
$end
```

***

```bash
#__case remover_por_indice
# o comando "$rmi ind" remove o elemento dado o índice. 
# Se o índice não existir, informe a falha.
$add 4 5 6 8 1 2 2 9
$rmi 0
$show
[ 5 6 8 1 2 2 9 ]
$rmi 5
$show
[ 5 6 8 1 2 9 ]
$rmi 5
$show
[ 5 6 8 1 2 ]
$rmi 2
$show
[ 5 6 1 2 ]
$rmi -1
fail
$rmi 4
fail
$show
[ 5 6 1 2 ]
$end
```

***

```bash
#__case remove_all
# o comando "$rma V" remove todos os elemento que contém esse valor. 
$add 2 2 2 2
$rma 2
$show
[ ]
$add 4 4 4 4 2 2 2 4 4 4 1 2 3 4
$rma 7
$show
[ 4 4 4 4 2 2 2 4 4 4 1 2 3 4 ]
$rma 2
$show
[ 4 4 4 4 4 4 4 1 3 4 ]
$rma 4
$show
[ 1 3 ]
$end
```

***

## Dica
- **boolean add(Object element)**: Adiciona o elemento especificado no final da lista.
- **void add(int index, Object element)**: Insere o elemento especificado na posição indicada da lista.
- **void clear()**: Remove todos os elementos da lista.
- **boolean contains(Object element)**: Retorna verdadeiro se a lista contém o elemento especificado e falso caso contrário.
- **Object get(int index)**: Retorna o i-ésimo elemento da lista.
- **int indexOf(Object element)**: Retorna a posição da primeira ocorrência do elemento especificado na lista.
- **boolean isEmpty()**: Retorna verdadeiro se a lista estiver vazia e falso caso contrário.
- **int lastIndexOf(Object element)**: Retorna a posição da última ocorrência do elemento especificado na lista.
- **Object remove(int index)**: Remove o i-ésimo elemento da lista.
- **Object set(int index, Object element)**: Substitui o i-ésimo elemento da lista pelo elemento especificado.
- int size(): Retorna o número de elementos da lista.
***

## Esqueleto
<!--FILTER Solver.java java-->
```java
public class Solver{	
    
    public static void main(String[] args) {
        ArrayList<Integer> vet = new ArrayList<Integer>();
        Scanner scan = new Scanner(System.in);

        while(true) {
            String line = scan.nextLine();
            System.out.println("$" + line);
            String ui[] = line.split(" ");
            String cmd = ui[0];

            if(line.equals("end")) {
                break;
            } else if(cmd.equals("show")) {
                System.out.print("[ ");
                for(Integer value : vet)
                    System.out.print(value + " ");
                System.out.print("]\n");
            } else if(cmd.equals("rshow")) {
            } else if(cmd.equals("add")) {
                for(int i = 1; i < ui.length; i++)
                    vet.add(Integer.parseInt(ui[i]));
            } else if(cmd.equals("find")) {
            } else if(cmd.equals("get")) {
            } else if(cmd.equals("set")) {
            } else if(cmd.equals("ins")) {
            } else if(cmd.equals("rmi")) {
            } else if(cmd.equals("rma")) {
            } else {
                System.out.print("fail: command not found\n");
            }
        }
        scan.close();
    }
}
```
<!--FILTER_END-->