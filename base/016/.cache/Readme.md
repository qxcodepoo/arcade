## @016 Favoritos & Agenda 3: cache e redundância

![cover](https://github.com/qxcodepoo/arcade/blob/master/base/016/cover.jpg)

<!-- toc -->
- [Requisitos Novos](#requisitos-novos)
- [Shell](#shell)
- [Diagrama UML](#diagrama-uml)
- [Esqueleto](#esqueleto)
<!-- toc -->

Ampliando a atividade de agenda 2, vamos criar uma agenda que gerencia os nossos contatos.


## Requisitos Novos

O sistema deverá:
- Partida
    - Você deve utilizar o código construído na atividade busca.
    - Você deverá modificar o contato e a classe agenda para permitir a operação de favoritar contatos.
    - Para isso, o contato ganhará um atributo "star" que marca se ele está favoritado.
    - A agenda ganhará os métodos star e getStarred para favoritar e pegar os favoritos.
- Mostrando
    - Ordenar os contatos pelo idContato.
    - Se o contato não for favorito (starred) use - antes do idContato.
    - Marque os contatos que são favoritados com um @ antes do idContato. 
- Favoritando
    - Favoritar contatos. (star)
    - Desfavoritar contatos. (unstar)
    - Mostrar apenas os favoritos. (starred)

## Shell

```bash
#__case iniciando agenda
$add eva oi:8585 claro:9999
$add ana tim:3434 
$add ana casa:4567 oi:8754
$add bia vivo:5454
$add rui casa:3233
$add zac fixo:3131

$show
- ana [0:tim:3434] [1:casa:4567] [2:oi:8754]
- bia [0:vivo:5454]
- eva [0:oi:8585] [1:claro:9999]
- rui [0:casa:3233]
- zac [0:fixo:3131]

#__case favoritando
$star eva
$star ana
$star ana
$star zac

$show
@ ana [0:tim:3434] [1:casa:4567] [2:oi:8754]
- bia [0:vivo:5454]
@ eva [0:oi:8585] [1:claro:9999]
- rui [0:casa:3233]
@ zac [0:fixo:3131]

#__case lista de favoritos
$starred
@ ana [0:tim:3434] [1:casa:4567] [2:oi:8754]
@ eva [0:oi:8585] [1:claro:9999]
@ zac [0:fixo:3131]

#__case removendo contato
$rm zac

$show
@ ana [0:tim:3434] [1:casa:4567] [2:oi:8754]
- bia [0:vivo:5454]
@ eva [0:oi:8585] [1:claro:9999]
- rui [0:casa:3233]

$starred
@ ana [0:tim:3434] [1:casa:4567] [2:oi:8754]
@ eva [0:oi:8585] [1:claro:9999]

#__case desfavoritando
$unstar ana

$starred
@ eva [0:oi:8585] [1:claro:9999]

$show
- ana [0:tim:3434] [1:casa:4567] [2:oi:8754]
- bia [0:vivo:5454]
@ eva [0:oi:8585] [1:claro:9999]
- rui [0:casa:3233]
$end
```

***

## Diagrama UML
![diagrama](https://github.com/qxcodepoo/arcade/blob/master/base/016/diagrama.png)

## Esqueleto
<!--FILTER Solver.java java-->
```java
class Fone {
    private String id;
    private String number;
    public Fone(String id, String number);
    //verifica se o número é um número de telefone válido
    public static boolean validate(String number);
    //O resultado deve ficar assim
    //oi:1234
    public String toString();
    //GETS e SETS
    String getId();
    void setId(String id);
    String getNumber();
    void setNumber(String number);
}
class Contact {
    private String name;
    private List<Fone> fones;
    protected String prefix = "-"; //utilizado no toString
    private boolean star;
    //Crie um ArrayList para o ATRIBUTO fones
    //Se a variável fones não for null, adicione todos os fones usando o método addFone
    //Inicie star como false
    public Contact(String name, List<Fone> fones);
    //Se fone for válido, insira no atributo fones
    //Se não, informe o erro
    public void addFone(Fone fone);
    //Se o índice existir no ArrayList, remova o telefone com esse índice
    public void rmFone(int index);
    //Use um contador para mostrar o índice do telefone
    //Use o toString do fone para adicioná-lo à saída
    //O resultado dever ficar assim:
    //- david [0:oi:123] [1:tim:9081] [2:claro:5431]
    public String toString();
    //GETS e SETS
    String getName();
    void setName(String name);
    List<Fone> getFones();
    //muda o prefixo e o valor de star
    void setStar(boolean value);
    boolean getStar(); 
}
class Agenda {
    private List<Contact> contacts;
    public Agenda();
    //retorna a posição do contato com esse nome no vetor ou -1 se não existir.
    private int findPos(String name);
    //retorna o objeto contato com esse nome ou null se não existir
    //utilize o método findPos
    public Contact getContact(String name);
    //se nenhum contato existir com esse nome, adicione
    //se ja existir, faça o merge adicionando os telefones
    public void addContact(Contact contact);
    //Utilize o método findPos
    public void rmContact(String name);
    //Monte uma lista auxiliar procurando no .toString() de cada contato
    //se ele possui a substring procurada.
    public List<Contact> search(String pattern);
    public String toString();
    //se o contato existir, altere o atributo star dele
    public void star(String name, boolean value); 
    //filtre em uma nova lista apenas os contatos que estão favoritados
    public List<Contact> getStarred();
    List<Contact> getContacts();
}
class Solver {
    //cria um contato a partir do vetor de entrada tal como
    //add joao oi:123 tim:432 claro:09123
    static Contact parseContact(String[] ui) {
        return new Contact(ui[1], Arrays.asList(ui).stream()
            .skip(2).map(token -> new Fone(token.split(":")[0], token.split(":")[1]))
            .collect(Collectors.toList()));
    }
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        Agenda agenda = new Agenda();
        while(true) {
            String line = scanner.nextLine();
            System.out.println("$" + line);
            String ui[] = line.split(" ");
            
            if(ui[0].equals("end")) {
                break;
            } else if(ui[0].equals("init")) {
                agenda = new Agenda();
            } else if(ui[0].equals("add")) { //name label:fone label:fone label:fone
                agenda.addContact(Solver.parseContact(ui));
            } else if(ui[0].equals("rm")) { //name
                agenda.rmContact(ui[1]);;
            } else if(ui[0].equals("rmFone")) { //name index
                agenda.getContact(ui[1]).rmFone(Integer.parseInt(ui[2]));
            } else if(ui[0].equals("show")) {
                System.out.println(agenda);
            } else if(ui[0].equals("star")) {
                agenda.star(ui[1], true);
            } else if(ui[0].equals("unstar")) {
                agenda.star(ui[1], false);
            } else if(ui[0].equals("starred")) {
                System.out.println(agenda.getStarred().stream().map(c -> "" + c).collect(Collectors.joining("\n")));
            } else if(ui[0].equals("search")) {
                System.out.println(agenda.search(ui[1]).stream().map(c -> "" + c).collect(Collectors.joining("\n")));
            } else {
                System.out.println("fail: invalid command");
            }
        }
        scanner.close();
    }
}

class Manual {
    public static void main(String[] args) {
        Agenda agenda = new Agenda();
        agenda.addContact(new Contact("eva", Arrays.asList(new Fone("oio", "8585"), new Fone("cla", "9999"))));
        agenda.addContact(new Contact("ana", Arrays.asList(new Fone("Tim", "3434"))));
        agenda.addContact(new Contact("bia", Arrays.asList(new Fone("viv", "5454"))));
        agenda.addContact(new Contact("ana", Arrays.asList(new Fone("cas", "4567"), new Fone("oio", "8754"))));
        System.out.println(agenda);
        /*
        - ana [0:casa:4567][1:oi:8754]
        - bia [0:vivo:5454]
        - eva [0:oi:8585][1:claro:9999]
        - rui [0:casa:3233]
        - zac [0:fixo:3131]
        */

        //case favoritando
        agenda.star("eva", true);
        agenda.star("ana", true);
        agenda.star("ana", true);
        agenda.star("zac", true);
        agenda.star("rex", true);
        //fail: contato rex nao existe
        System.out.println(agenda);
        /*
        @ ana [0:casa:4567][1:oi:8754]
        - bia [0:vivo:5454]
        @ eva [0:oi:8585][1:claro:9999]
        - rui [0:casa:3233]
        @ zac [0:fixo:3131]
        */

        //case lista de favoritos
        for(Contact fav : agenda.getStarred())
            System.out.println(fav);
        /*
        @ ana [0:casa:4567][1:oi:8754]
        @ eva [0:oi:8585][1:claro:9999]
        @ zac [0:fixo:3131]
        */

        //case removendo contato
        agenda.rmContact("zac");
        System.out.println(agenda);
        /*
        @ ana [0:casa:4567][1:oi:8754]
        - bia [0:vivo:5454]
        @ eva [0:oi:8585][1:claro:9999]
        - rui [0:casa:3233]
        */
        for(Contact fav : agenda.getStarred())
            System.out.println(fav);
        /*
        @ ana [0:casa:4567][1:oi:8754]
        @ eva [0:oi:8585][1:claro:9999]
        */

        //case desfavoritando
        agenda.star("ana", false);
        for(Contact fav : agenda.getStarred())
            System.out.println(fav);
        //@ eva [0:oi:8585][1:claro:9999]
        System.out.println(agenda);
        /*
        - ana [0:casa:4567][1:oi:8754]
        - bia [0:vivo:5454]
        @ eva [0:oi:8585][1:claro:9999]
        - rui [0:casa:3233]
        */
    }
}
```
<!--FILTER_END-->
