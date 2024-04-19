import java.util.*;
import java.util.stream.Collectors;

class Client {
    private String id;
    private String fone;
    public Client(String id, String fone) {
        this.id = id;
        this.fone = fone;
    }

    @Override
    public String toString() {
        return id + ":" + fone;
    }

    public String getId() {
        return this.id;
    }

    public void setId(String id) {
        this.id = id;
    }

    public String getFone() {
        return this.fone;
    }

    public void setFone(String fone) {
        this.fone = fone;
    }
}


class Sala{
    private List<Client> cadeiras;


    public Sala(int capacidade) {
    }

    public List<Client> getCadeiras() {
    }
    
    public boolean reservar(String id, String fone, int ind) {

    }

    public void cancelar(String id) {
    }

    @Override
    public String toString() {
        return "[" + this.cadeiras.stream().map(c -> (c == null) ? "-" : c.toString()).collect(Collectors.joining(" ")) + "]";
    }
}

public class Solver {
    public static void main(String[] _args) {
        Sala sala = new Sala(0);
        while (true) {
            var line = input();
            var args = line.split(" ");
            write('$' + line);

            if (args[0].equals("end")) { break; }
            else if (args[0].equals("init"))     { sala = new Sala(Integer.parseInt(args[1])); }
            else if (args[0].equals("show"))     { write(sala.toString()); }
            else if (args[0].equals("reservar")) { sala.reservar(args[1], args[2], (int) number(args[3])); }
            else if (args[0].equals("cancelar")) { sala.cancelar(args[1]); }
            else                                 { write("fail: comando invalido"); }
        }
    }

    private static Scanner scanner = new Scanner(System.in);
    private static String input() { return scanner.nextLine(); }
    private static double number(String value) { return Double.parseDouble(value); }
    private static void write(String value) { System.out.println(value); }
}
