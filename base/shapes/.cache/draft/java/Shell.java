import java.util.*;

public class Shell {
    public static void main(String[] a) {
        Adapter adp = new Adapter();
        
        while (true) {
            var line = input();
            write("$" + line);
            var args = line.split(" ");

            if      (args[0].equals("show"))   { System.out.println(adp);                                                                                   }
            else if (args[0].equals("circle")) { adp.circle(number(args[1]), number(args[2]), number(args[3]));                           }
            else if (args[0].equals("rect"))   { adp.rectangle(number(args[1]), number(args[2]), number(args[3]), number(args[4])); }
            else if (args[0].equals("info"))   { System.out.println(adp.info());                                                                            }
            else if (args[0].equals("end"))    { break;                                                                                                     }
            else                                        { write("fail: comando invalido");                                                                     }
        }
    }

    private static Scanner scanner = new Scanner(System.in);
    private static String  input()              { return scanner.nextLine(); }
    private static double  number(String value) { return Double.parseDouble(value); }
    private static void    write(String value)  { System.out.println(value); }
}