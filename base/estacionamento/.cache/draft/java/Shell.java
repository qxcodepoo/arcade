import java.util.*;

public class Shell {
    public static void main(String[] a) {
        Adapter adp = new Adapter();
        
        while (true) {
            var line = input();
            write("$" + line);
            var args = line.split(" ");

            if      (args[0].equals("show"))  { adp.show();                }
            else if (args[0].equals("estacionar")) { adp.estacionar(args[1], args[2]);  }
            else if (args[0].equals("tempo")) { adp.passarTempo((int) number(args[1])); }
            else if (args[0].equals("pagar")) { adp.pagar(args[1]); adp.sair(args[1]);  }
            else if (args[0].equals("end"))   { break;                                  }
            else                                       { write("fail: comando invalido");  }
        }
    }

    private static Scanner scanner = new Scanner(System.in);
    private static String  input()              { return scanner.nextLine(); }
    private static double  number(String value) { return Double.parseDouble(value); }
    private static void    write(String value)  { System.out.println(value); }
}