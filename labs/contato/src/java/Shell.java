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
        for (char c : number.toCharArray()) {
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

    public String toString() {
        return (favorited ? "@" : "-") + " " + name + " [" + fones.stream().map(fone -> fone.str()).collect(Collectors.joining(", ")) + "]";
    }
}

// @KEEP
public class Shell{

    public static void main(String[] Args) {
        // @DROP
        Contact contact = new Contact("");
        // @KEEP
        while (true) {
            String line = scanner.nextLine();
            System.out.println("$" + line);
            String[] args = line.split(" ");
            
            if (args[0].equals("end")) {
                break;
            }
            else if (args[0].equals("init")) {
                // @COM
                var name = args[1];
                // @DROP
                contact = new Contact(name);
            }
            else if (args[0].equals("show")) {
                // @DROP
                System.out.println(contact.toString());
            }
            else if (args[0].equals("add")) {
                // @COM
                var id = args[1];
                var number = args[2];
                // @DROP
                contact.addFone(id, number);
            }
            else if (args[0].equals("rm")) {
                // @COM
                var index = Integer.parseInt(args[1]);
                // @DROP
                contact.rmFone(index);
            }
            else if (args[0].equals("tfav")) {
                // @DROP
                contact.toogleFavorited();
            }
            else {
                System.out.println("fail: invalid command");
            }
        }
    }
    static Scanner scanner = new Scanner(System.in);
}
