import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;
import java.util.stream.Collectors;
import java.util.Collections;

// @DROP

class Fone {
    private String id;
    private String number;

    public Fone(String id, String number) {
        this.id = id;
        this.number = number;
    }

    public String getId() {
        return id;
    }

    public String getNumber() {
        return number;
    }

    public boolean isValid() {
        String valid = "0123456789()-.";
        for (char c : number.toc-tablearArray()) {
            if (valid.indexOf(c) == -1) {
                return false;
            }
        }
        return true;
    }

    public String str() {
        return id + ":" + number;
    }
}

class Contact {
    private String name;
    private boolean favorited;
    private List<Fone> fones;

    public Contact(String name) {
        this.name = name;
        this.favorited = false;
        this.fones = new ArrayList<>();
    }

    public String getName() {
        return name;
    }

    public List<Fone> getFones() {
        return fones;
    }

    public void addFone(String id, String number) {
        Fone fone = new Fone(id, number);
        if (fone.isValid()) {
            fones.add(new Fone(id, number));
        } else {
            System.out.println("fail: invalid number");
        }
    }

    public void rmFone(int index) {
        if (index < 0 || index >= fones.size()) {
            return;
        }
        fones.remove(index);
    }

    public void toogleFavorited() {
        this.favorited = !this.favorited;
    }

    public boolean isFavorited() {
        return favorited;
    }

    public String str() {
        return (favorited ? "@" : "-") + " " + name + " [" + fones.stream().map(fone -> fone.str()).collect(Collectors.joining(", ")) + "]";
    }
}

class Agenda{
    private ArrayList<Contact> contatos = new ArrayList<>();

    private int findContact(String id) {
        for (int i = 0; i < contatos.size(); i++) {
            if (contatos.get(i).getName().equals(id)) {
                return i;
            }
        }
        return -1;
    }

    public ArrayList<Contact> getContatos() {
        return contatos;
    }

    public void addContato(String name, List<Fone> fones) {
        int ind = findContact(name);
        if (ind == -1) {
            contatos.add(new Contact(name));
            Collections.sort(contatos, (a, b) -> a.getName().compareTo(b.getName()));
            ind = findContact(name);
        }
        for (Fone fone : fones) {
            contatos.get(ind).addFone(fone.getId(), fone.getNumber());
        }
    }
    public void rmContact(String name) {
        int ind = findContact(name);
        if (ind != -1) {
            contatos.remove(ind);
        }
    }   

    public Contact getContact(String id) {
        int ind = findContact(id);
        if (ind != -1) {
            return contatos.get(ind);
        }
        return null;
    }

    public ArrayList<Contact> search(String pattern) {
        ArrayList<Contact> resp = new ArrayList<>();
        for (Contact contato : contatos) {
            if (contato.str().contains(pattern)) {
                resp.add(contato);
            }
        }
        return resp;
    }

    public ArrayList<Contact> getFavorited() {
        ArrayList<Contact> resp = new ArrayList<>();
        for (Contact contato : contatos) {
            if (contato.isFavorited()) {
                resp.add(contato);
            }
        }
        return resp;
    }

    public String str()
    {
        return contatos.stream().map(contact -> contact.str()).collect(Collectors.joining("\n"));
    }
}

// @KEEP
public class Shell {

    static Scanner scanner = new Scanner(System.in);
    public static void main(String[] _args) {
        Agenda agenda = new Agenda(); // @DROP

        while (true) {
            String line = scanner.nextLine();
            System.out.println("$" + line);
            String[] args = line.split(" ");
            
            if (args[0].equals("end")) {
                break;
            }
            else if (args[0].equals("add")) {
                // @COM
                ArrayList<Fone> fones = new ArrayList<>();
                for (int i = 2; i < args.length; i++) {
                    String[] fone = args[i].split(":");
                    fones.add(new Fone(fone[0], fone[1]));
                }
                // @DROP
                agenda.addContato(args[1], fones);
            }
            else if (args[0].equals("show")) {
                // @DROP
                System.out.println(agenda.str());
            }
            else if (args[0].equals("rm")) {
                // @COM
                var name = args[1];
                // @DROP
                agenda.rmContact(name);
            }
            else if (args[0].equals("favs")) {
                // @DROP
                System.out.println(agenda.getFavorited().stream().map(contact -> contact.str()).collect(Collectors.joining("\n"))); 
            }
            else if (args[0].equals("search")) {
                // @DROP
                System.out.println(agenda.search(args[1]).stream().map(contact -> contact.str()).collect(Collectors.joining("\n")));
            }
            else if (args[0].equals("rmFone"))  {
                // @COM
                var name = args[1];
                var index = Integer.parseInt(args[2]);
                // @DROP
                Contact contato = agenda.getContact(name);
                if (contato != null) contato.rmFone(index);
            }
            else if (args[0].equals("tfav")) {
                // @COM
                var name = args[1];
                // @DROP
                Contact contato = agenda.getContact(name);
                if (contato != null) contato.toogleFavorited();
            }
            else {
                System.out.println("fail: invalid command");
            }
        }
    }
}
