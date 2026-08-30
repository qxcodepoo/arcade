import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.Scanner;
import java.util.stream.Collectors;

class Fone {
    private String id;
    private String number;
    public Fone(String id, String number) {
        this.id = id;
        this.number = number;
    }

    //verifica se o número é um número de telefone válido
    public static boolean validate(String number) {
        String validos = "()-.0123456789";
        for(int i = 0; i < number.length(); i++)
            if(!validos.contains("" + number.charAt(i)))
                return false;
        return true;
    }

    //O resultado deve ficar assim
    //oi:1234
    @Override
    public String toString() {
        return getId()+ ":" + getNumber();
    }

    //GETS e SETS
    String getId() {
        return this.id;
    }
    void setId(String id) {
        this.id = id;
    }
    String getNumber() {
        return this.number;
    }
    void setNumber(String number) {
        this.number = number;
    }
}

class Contact {
    private String name;
    private List<Fone> fones;
    protected String prefix = "-"; //utilizado no toString
    private boolean star;
    //Crie um ArrayList para o ATRIBUTO fones
    //Se a variável fones não for null, adicione todos os fones usando o método addFone
    //Inicie star como false
    public Contact(String name, List<Fone> fones) {
        this.star = false;
        this.name = name;
        this.fones = new ArrayList<>();
        if(fones != null)
            fones.stream().forEach((fone) -> {this.addFone(fone);});
    }

    //Se fone for válido, insira no atributo fones
    //Se não, informe o erro
    public void addFone(Fone fone) {
        if(Fone.validate(fone.getNumber()))
            this.fones.add(fone);
        else
            System.out.println("fail: invalid number");
    }

    //Se o índice existir no ArrayList, remova o telefone com esse índice
    public void rmFone(int index) {
        if(index < 0 || index >= (int) fones.size())
            return;
        fones.remove(index);
    }

    //Use um contador para mostrar o índice do telefone
    //Use o toString do fone para adicioná-lo à saída
    //O resultado dever ficar assim:
    //- david [0:oi:123] [1:tim:9081] [2:claro:5431]
    @Override
    public String toString() {
        StringBuilder sb = new StringBuilder();
        sb.append(this.prefix + " " + this.getName());
        for(int i = 0; i < fones.size(); i++)
            sb.append( " [" + i + ":" + fones.get(i) + "]");
        return sb.toString();
    }

    //GETS e SETS
    String getName() {
        return this.name;
    }
    void setName(String name) {
        this.name = name;
    }
    List<Fone> getFones() {
        return this.fones;
    }
    //muda o prefixo e o valor de star
    void setStar(boolean value) {
        this.star = value;
        prefix = value ? "@" : "-";
    }
    boolean getStar() { 
        return this.star;
    }
}

class Agenda {
    private List<Contact> contacts;

    public Agenda() {
        this.contacts = new ArrayList<>();
    }

    //retorna a posição do contato com esse nome no vetor ou -1 se não existir.
    private int findPos(String name) {
        for(int i = 0; i < this.contacts.size(); i++)
            if(contacts.get(i).getName().equals(name))
                return i;
        return -1;
    }

    //retorna o objeto contato com esse nome ou null se não existir
    //utilize o método findPos
    public Contact getContact(String name) {
        int pos = this.findPos(name);
        if(pos == -1)
            return null;
        return contacts.get(pos);
    }

    //se nenhum contato existir com esse nome, adicione
    //se ja existir, faça o merge adicionando os telefones
    public void addContact(Contact contact) {
        if(contact == null)
            return;
        Contact old = getContact(contact.getName());
        if(old == null) {
            this.contacts.add(contact);
        } else {
            contact.getFones().stream().forEach(fone -> old.addFone(fone));
        }
        this.contacts.sort((Contact c1, Contact c2) -> (c1.getName().compareTo(c2.getName())));
        // this.contacts.sort(new Comparator<Contact>() {
        //     @Override
        //     public int compare(Contact arg0, Contact arg1) {
        //         return ((Contact) arg0).getName().compareTo(((Contact)arg1).getName());
        //     }
        // });
    }

    //Utilize o método findPos
    public void rmContact(String name) {
        int pos = findPos(name);
        if(pos == -1) {
            System.out.println("fail: contact not found");
            return;
        }
        this.contacts.remove(pos);
    }

    //Monte uma lista auxiliar procurando no .toString() de cada contato
    //se ele possui a substring procurada.
    public List<Contact> search(String pattern) {
        return this.contacts
            .stream()
            .filter(contact -> contact.toString().contains(pattern))
            .collect(Collectors.toList());
    }



    @Override
    public String toString() {
        return this.contacts.stream().map(contact -> "" + contact).collect(Collectors.joining("\n"));
    }

    //se o contato existir, altere o atributo star dele
    public void star(String name, boolean value) { 
        Contact contact = getContact(name);
        if(contact == null)
            return;
        contact.setStar(value);
    }

    //filtre em uma nova lista apenas os contatos que estão favoritados
    public List<Contact> getStarred() {
        return this.contacts.stream().filter(c -> c.getStar()).collect(Collectors.toList());
    }

    List<Contact> getContacts() {
        return this.contacts;
    }
}

//!KEEP
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
            }
            else {
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
//!OFF
    