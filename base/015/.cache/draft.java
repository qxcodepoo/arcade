import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.Scanner;
import java.util.stream.Collectors;


//!DEL
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

    //utiliza o static validate para retornar se essa instancia do fone é valida
    public boolean isValid() {
        return validate(number);
    }

    //O resultado deve ficar assim
    //oi:1234
    @Override
    public String toString() {
        return getId()+ ":" + getNumber();
    }

    //GETS e SETS
    public String getId() {
        return this.id;
    }
    public void setId(String id) {
        this.id = id;
    }
    public String getNumber() {
        return this.number;
    }
    public void setNumber(String number) {
        this.number = number;
    }


}

class Contact {
    private String name;
    private List<Fone> fones;
    protected String prefix = "-"; //utilizado no toString
    //Crie um ArrayList para o ATRIBUTO fones
    //Adicione todos os fones usando o método setFones
    public Contact(String name, List<Fone> fones) {
        this.fones = new ArrayList<>();
        this.setName(name);
        this.setFones(fones);
    }

    //Se fone for válido, insira no atributo fones
    //Se não, informe o erro
    public void addFone(Fone fone) {
        if(fone.isValid())
            this.fones.add(fone);
        else
            System.out.println("fail: invalid number");
    }

    //Se o índice existir no ArrayList, remova o telefone com esse índice
    public void rmFone(int index){
        if(index < 0 || index >= (int) fones.size())
            return;
        fones.remove(index);
    }

    //Use um contador para mostrar o índice do telefone
    //Use o toString do fone para adicioná-lo à saída
    //O resultado dever ficar assim:
    //- david [0:oi:123] [1:tim:9081] [2:claro:5431]
    @Override
    public String toString(){
        StringBuilder sb = new StringBuilder();
        sb.append(this.prefix + " " + this.getName());
        for(int i = 0; i < fones.size(); i++)
            sb.append( " [" + i + ":" + fones.get(i) + "]");
        return sb.toString();
    }

    //GETS e SETS
    public String getName() {
        return this.name;
    }
    public void setName(String name) {
        this.name = name;
    }
    public List<Fone> getFones() {
        return this.fones;
    }
    //limpe a lista de fones
    //se fones não for null, utilize o addFone para adicionar todos os fones
    public void setFones(List<Fone> fones) {
        this.fones.clear();
        fones.stream().forEach((fone) -> {this.addFone(fone);});
    }
}
//!INS


class Agenda {
    private List<Contact> contacts;

    public Agenda() {
        this.contacts = new ArrayList<>();
    }

    //retorna a posição do contato com esse nome no vetor ou -1 se não existir.
    private int findPosByName(String name) {
        for(int i = 0; i < this.contacts.size(); i++)
            if(contacts.get(i).getName().equals(name))
                return i;
        return -1;
    }

    //retorna o objeto contato com esse nome ou null se não existir
    //utilize o método findPos
    public Contact findContact(String name) {
        int pos = this.findPosByName(name);
        if(pos == -1)
            return null;
        return contacts.get(pos);
    }

    //se nenhum contato existir com esse nome, adicione
    //se ja existir, faça o merge adicionando os telefones
    //se tiver adicionado um novo contato, ordene a lista para ficar em ordem alfabética
    public void addContact(Contact contact) {
        if(contact == null)
            return;
        Contact old = findContact(contact.getName());
        if(old == null) {
            this.contacts.add(contact);
        } else {
            contact.getFones().stream().forEach(fone -> old.addFone(fone));
        }
        this.contacts.sort((Contact c1, Contact c2) -> (c1.getName().compareTo(c2.getName())));
        // this.contacts.sort(new Comparator<Contact>(){
        //     @Override
        //     public int compare(Contact arg0, Contact arg1) {
        //         return ((Contact) arg0).getName().compareTo(((Contact)arg1).getName());
        //     }
        // });
    }

    //Utilize o método findPos
    public void rmContact(String name) {
        int pos = findPosByName(name);
        if(pos == -1){
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

    public List<Contact> getContacts() {
        return this.contacts;
    }

    @Override
    public String toString() {
        return this.contacts.stream().map(contact -> "" + contact).collect(Collectors.joining("\n"));
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
            while(true){
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
                    agenda.findContact(ui[1]).rmFone(Integer.parseInt(ui[2]));
                } else if(ui[0].equals("show")) {
                    System.out.println(agenda);
                } else if(ui[0].equals("search")) {
                    System.out.println(agenda.search(ui[1]).stream().map(c -> "" + c).collect(Collectors.joining("\n")));
                } else {
                    System.out.println("fail: invalid command");
                }
            }
            scanner.close();
        }
    }
    //!OFF