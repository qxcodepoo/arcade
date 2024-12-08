import java.util.Scanner;

class Adapter {
    public Adapter() {
    }

    public void criar(String cor, String tamanho) {
    }

    public void enxugar(int quantidade) {
    }

    public void seca() {
    }

    public void torcer() {
    }

    public void mostrar() {
    }
}

public class Shell {
    
    public static void main(String[] a) {
        Adapter adp = new Adapter();
        
        while (true) {
            System.out.print("$");
            var line = input();
            write(line); // comente para executar interativamente
            var args = line.split(" ");
            if (args[0].equals("criar")) {
                adp.criar(args[1], args[2]);
            } else if (args[0].equals("enxugar")) {
                adp.enxugar(Integer.parseInt(args[1]));
            } else if (args[0].equals("seca")) {
                adp.seca();
            } else if (args[0].equals("torcer")) {
                adp.torcer();
            } else if (args[0].equals("mostrar")) {
                adp.mostrar();
            } else if (args[0].equals("end")) {
                break;
            } else {
                System.out.println("comando invalido");
            }
        }
    }
    private static Scanner scanner = new Scanner(System.in);
    private static String  input()              { return scanner.nextLine(); }
    private static void    write(String value)  { System.out.println(value); }
}
